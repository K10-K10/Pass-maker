#include "home.hpp"

Home::Home()
{
	pass = "";
	loop_flag = true;
};

void Home::home_event()
{
	Create create;
	Check check;
	std::cout << "1 - Create pass | 2 - Pass check | other - Exit" << std::endl;
	while (loop_flag)
	{
		std::cout << ">" << std::flush;
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			pass = create.pass_creator();
			break;
		}
		case 2:
		{ // TODO:CHECK
			check.check_func();
			break;
		}
		default:
		{
			std::cout << "Exit" << std::endl;
			loop_flag = false;
			break;
		}
		}
	}
}
