#include "check.hpp"
#include <mutex>

Check::Check() {}
void Check::check_func()
{
	std::cout << "Checker>Password to be confirmed:" << std::flush;
	std::cin >> check_pass;

	std::cout << "lockyou: [  ]\n";
	std::cout << "repeat : [  ]\n";

	std::thread lockyou(&Check::check_lockyou, this);
	std::thread repeat(&Check::check_repeat, this);
	lockyou.join();
	repeat.join();
}

std::mutex cout_mutex;

void Check::check_lockyou()
{
	std::string cmd = "../script/main.sh " + check_pass;
	int script_return_value = system(cmd.c_str());

	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "\033[2A\033[10C";
		if (script_return_value == 0)
			std::cout << "\033[32mOK\033[0m";
		else
			std::cout << "\033[31mNG\033[0m";
		std::cout << "\033[2B\033[10D";
	}
}

void Check::check_repeat()
{
	double ans = 0;
	std::unordered_map<char, int> count_char;
	int word_count = check_pass.size();
	for (char c : check_pass)
		count_char[c]++;

	for (auto &p : count_char)
	{
		double num = static_cast<double>(p.second) / word_count;
		ans += num * num;
	}

	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "\033[1A\033[10C";
		if (ans >= 0.3)
			std::cout << "\033[32mOK\033[0m";
		else
			std::cout << "\033[31mNG\033[0m";
		std::cout << "\033[2B\033[10D";
	}
}
