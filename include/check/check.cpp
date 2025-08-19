#include "check.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <unordered_map>
#include <chrono>

std::mutex cout_mutex;

Check::Check() {}

void spinner(std::atomic<bool> &done, int row, int col)
{
	const char symbols[] = {'-', '\\', '|', '/'};
	int idx = 0;
	while (!done)
	{
		{
			std::lock_guard<std::mutex> lock(cout_mutex);
			std::cout << "\033[" << row << "A\033[" << col << "C"
								<< symbols[idx % 4] << "\033[" << row << "B\r" << std::flush;
		}
		idx++;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Check::check_func()
{
	std::cout << "Checker>Password to be confirmed:" << std::flush;
	std::cin >> check_pass;

	std::cout << "lockyou: [  ]\n";
	std::cout << "repeat : [  ]\n";

	std::atomic<bool> done_lockyou(false);
	std::atomic<bool> done_repeat(false);

	// spinner threads
	std::thread spin_lockyou(spinner, std::ref(done_lockyou), 2, 10);
	std::thread spin_repeat(spinner, std::ref(done_repeat), 1, 10);

	// work threads
	std::thread repeat(&Check::check_repeat, this, std::ref(done_repeat));
	std::thread lockyou(&Check::check_lockyou, this, std::ref(done_lockyou));

	repeat.join();
	lockyou.join();

	done_repeat = true;
	done_lockyou = true;

	spin_repeat.join();
	spin_lockyou.join();
	std::cout << "\033[4D";
}

void Check::check_lockyou(std::atomic<bool> &done_flag)
{
	std::string cmd = "../script/main.sh " + check_pass;
	int script_return_value = system(cmd.c_str());
	done_flag = true;

	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "\033[2A\033[8C";
		if (script_return_value == 0)
			std::cout << "\033[32mOK\033[0m";
		else
			std::cout << "\033[31mNG\033[0m";
		std::cout << "\033[2B\033[8D" << std::flush;
	}
}

void Check::check_repeat(std::atomic<bool> &done_flag)
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

	done_flag = true;

	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "\033[1A\033[10C";
		if (ans >= 0.3)
			std::cout << "\033[32mOK\033[0m";
		else
			std::cout << "\033[31mNG\033[0m";
		std::cout << "\033[2B\033[10D" << std::flush;
	}
}
