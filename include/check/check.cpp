#include "check.hpp"

Check::Check() {}
void Check::check_func()
{
	std::cout << "Checker>Password to be confirmed:" << std::flush;
	std::cin >> check_pass;

	std::cout << "lockyou: [  ]\n";
	std::cout << "repeat : [  ]\n";
	std::cout << "\033[2A\033[10C";
	int cmd_return = check_lockyou();
	std::cout << (cmd_return == 0 ? "\033[32mOK\033[0m" : "\033[31mNG\033[0m");

	std::cout << "\033[B\033[2D";
	int cmd_return2 = check_repeat();
	std::cout << (cmd_return2 == 0 ? "\033[32mOK\033[0m" : "\033[31mNG\033[0m");

	std::cout << std::endl;
}

int Check::check_lockyou()
{
	std::string cmd = "../script/main.sh " + check_pass;
	int script_return_value = system(cmd.c_str());
	if (script_return_value == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Check::check_repeat()
{
	double ans = 0;
	std::unordered_map<char, int> count_char;
	int word_count = check_pass.size();
	for (char c : check_pass)
	{
		count_char[c] += 1;
	}
	double num = 0;
	for (auto it = count_char.begin(); it != count_char.end(); ++it)
	{
		num = static_cast<double>(it->second) / word_count;
		ans += num * num;
	}
	if (ans >= 0.3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
