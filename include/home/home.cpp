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
	Check_repeat check_repeat;
	std::cout
			<< "1 - Create pass | 2 - Pass check | other - Exit" << std::endl;
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
			std::string check_pass;
			std::cout << "Checker>Password to be confirmed:" << std::flush;
			std::cin >> check_pass;

			std::cout << "lockyou: [  ]\n";
			std::cout << "repeat : [  ]\n";

			std::cout << "\033[2A\033[10C";
			int cmd_return = check_lockyou.check_script(check_pass);
			std::cout << (cmd_return == 0 ? "\033[32mOK\033[0m" : "\033[31mNG\033[0m");

			std::cout << "\033[B\033[2D";
			int cmd_return2 = check_repeat.check_repeat_fn(check_pass);
			std::cout << (cmd_return2 == 0 ? "\033[32mOK\033[0m" : "\033[31mNG\033[0m");

			std::cout << std::endl;
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
