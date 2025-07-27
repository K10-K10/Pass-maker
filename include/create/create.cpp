#include "include/create/create.hpp"
#include "include/check/check.hpp"

std::string create_pass::pass_creator(int8_t &cmd)
{
	switch (cmd)
	{
	case 1:
	case 2:
	default:
		std::cout << "Chose cmd" << std::endl;
	}
}
