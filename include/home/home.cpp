#include "home.hpp"

home::home()
{
	pass = "";
	loop_flag = true;
};

void home::home_event()
{

	std::cout << "1 - Create pass | other - Exit" << std::flush;
	while (loop_flag)
	{
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			pass =
		}
		default:
		{
			std::cout << "Exit" << std::endl;
			break;
		}
		}
	}
}
