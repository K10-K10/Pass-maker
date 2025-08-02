#include "create/create.hpp"

Create::Create()
{
	pass = "";
}

int Create::input_length()
{
	std::cout << "length:";
	std::cin >> Create::pass_long;
	if (Create::pass_long == 0)
	{
		std::cout << "Above 0" << std::endl;
		return 1;
	}
	else if (Create::pass_long < 4)
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
	std::cout << "Please select mode\n1 - number | 2 - number & alphabet | 3 - number,alphabet & mark | 4 - custom | other - exit:";
	std::cin >> Create::cmd;
	Create::pass = "`";
	switch (Create::cmd)
	{
	case 1:
	{
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
	}
	case 2:
	{
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
	}
	case 3:
	{
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
	}
	case 4:
	{
		int map_count = 0;
		std::string input;
		std::cout << "Send input string to crate pass (end with input \"exit\")" << std::endl;
		bool loop_flag = true;
		while (loop_flag)
		{
			std::cout << "Input:";
			std::cin >> input;
			if (input == "exit")
				loop_flag = false;
			else
			{
				map_count += input.size();
				Create::custom_chars = Create::custom_chars + input;
				int iteriter = 0;
				while (iteriter < map_count)
				{
					if (Create::custom_chars[iteriter] == Create::custom_chars[iteriter - 1])
					{
						Create::custom_chars.erase(iteriter, 1);
						map_count -= 1;
					}
					else
					{
						iteriter++;
					}
				}
			}
		}
		if (map_count == 0)
		{
			return Create::pass;
			break;
		}
		if (!Create::input_length())
		{
			for (int i = 0; i < Create::pass_long; i++)
			{
				unsigned int result = Create::rng() % map_count;
				Create::pass += Create::custom_chars[result];
			}
			std::cout << "Pass: " << pass << std::endl;
		}
		return Create::pass;
		break;
	}
	default:
	{
		std::cout << "Exit" << std::endl;
		return Create::pass;
	};
		return 0;
	}
}
