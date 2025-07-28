#include "create/create.hpp"
#include "check/check.hpp"

Create::Create()
{
	pass = "";
}

int Create::input_length()
{
	std::cout << "length:";
	std::cin >> Create::pass_long;
	if (Create::pass_long < 4)
	{
		std::cout << "Password is to short.Do you create?(y,n):";
		char input = 'n';
		std::cin >> input;
		if (input != 'y' && input != 'Y')
		{
			std::cout << "Stop createing" << std::endl;
			return 1;
		}
	}
	return 0;
}

std::string Create::pass_creator()
{
	std::cout << "Please select mode\n1 - number | 2 - number & alphabet | 3 - number,alphabet & mark | 4 - custom :";
	std::cin >> Create::cmd;
	switch (Create::cmd)
	{
	case 1:
		if (!Create::input_length())
		{
			for (int i = 0; i < Create::pass_long; i++)
			{
				unsigned int result = Create::rng() % 10;
				Create::pass += Create::chars[result];
			}
			std::cout << "Pass: " << pass << std::endl;
		}
		return Create::pass;
		break;
	case 2:
		if (!Create::input_length())
		{
			for (int i = 0; i < Create::pass_long; i++)
			{
				unsigned int result = Create::rng() % 62;
				Create::pass += Create::chars[result];
			}
			std::cout << "Pass: " << pass << std::endl;
		}
		return Create::pass;
		break;
	case 3:
		if (!Create::input_length())
		{
			for (int i = 0; i < Create::pass_long; i++)
			{
				unsigned int result = Create::rng() % 71;
				Create::pass += Create::chars[result];
			}
			std::cout << "Pass: " << pass << std::endl;
		}
		return Create::pass;
		break;
	case 4:
		if (!Create::input_length())
		{
		}
		break;
	default:
		std::cout << "Chose cmd 1 ~ 4" << std::endl;
		return Create::pass;
		break;
	};
	return 0;
}
