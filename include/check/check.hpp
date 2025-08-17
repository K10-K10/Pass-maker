#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
class Check_lockyou
{
public:
	Check_lockyou();
	int check_script(std::string);

private:
	std::string script_path = "../script/main.sh";
	int script_return_value = 128;
};
class Check_repeat
{
public:
	Check_repeat();
	int check_repeat_fn(std::string);

private:
	int word_count = 0;
	double ans;
};
