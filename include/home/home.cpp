#include "home.hpp"

Home::Home()
{
	pass = "";
	loop_flag = true;
};

void Home::home_event()
{
	Create create;
	Check_lockyou check_lockyou;
	std::cout << "1 - Create pass | 2 - Pass check | other - Exit" << std::endl;
	while (loop_flag)
	{
		std::cout << ">" << std::flush;
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			std::cout << "1 - number | 2 - number & alphabet | 3 - number,alphabet & mark | 4 - custom | other - exit" << std::endl;
			pass = create.pass_creator();
			break;
		}
		case 2:
		{
			int cmd_return = check_lockyou.check_script();
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
