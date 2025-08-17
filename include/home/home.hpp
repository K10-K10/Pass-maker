#pragma once
#include "create/create.hpp"
#include "check/check.hpp"
#include <iostream>
#include <string>

class Home
{
public:
	Home();
	std::string pass;
	int cmd;
	void home_event();

private:
	std::string help;
	bool loop_flag;
};
