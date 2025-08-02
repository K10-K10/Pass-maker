#pragma once
#include "create.hpp"
#include <iostream>
#include <string>

class home
{
public:
	home();
	std::string pass;
	int cmd;
	void home_event();

private:
	std::string help;
	bool loop_flag;
};
