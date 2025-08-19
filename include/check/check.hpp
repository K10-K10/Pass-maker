#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
// 	std::string script_path = "../script/main.sh";

class Check
{
public:
	Check();
	std::string check_pass;
	void check_func();

private:
	int check_lockyou();
	int check_repeat();
};
