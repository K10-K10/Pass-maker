#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <thread>
#include <atomic>

class Check
{
public:
	Check();
	void check_func();

private:
	std::string check_pass;
	void check_lockyou(std::atomic<bool> &done_flag);
	void check_repeat(std::atomic<bool> &done_flag);
};
