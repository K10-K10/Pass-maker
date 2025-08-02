#include "home.hpp"

Home::Home()
{
	pass = "";
	loop_flag = true;
};

void Home::home_event()
{
	Create create;
	std::cout << "1 - Create pass | other - Exit:" << std::flush;
	while (loop_flag)
	{
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			pass = create.pass_creator();
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
