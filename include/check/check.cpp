#include "check.hpp"

Check_lockyou::Check_lockyou()
{
	script_return_value = 128;
}
int Check_lockyou::check_script(std::string check_pass)
{
	std::string cmd = script_path + " " + check_pass;
	script_return_value = system(cmd.c_str());
	return 0;
}

Check_repeat::Check_repeat()
{
	word_count = 0;
}
int Check_repeat::check_repeat_fn(std::string check_pass)
{
	ans = 0;
	std::unordered_map<char, int> count_char;
	word_count = check_pass.size();
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
		std::cout << "\033[31mX\033[0m" << std::endl;
		return 256;
	}
	else
	{
		std::cout << "\033[32mO\033[0m" << std::endl;
		return 0;
	}
}
