#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <thread>

class Check
{
public:
	Check();
	std::string check_pass;
	void check_func();

private:
	void check_lockyou();
	void check_repeat();
};
