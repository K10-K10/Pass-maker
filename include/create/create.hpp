#pragma once
#include <iostream>
#include <random>
#include <string>

class Create
{
public:
	Create();
	std::string pass;
	std::string pass_creator();
	int input_length();

private:
	const std::string chars =
			"0123456789"
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"!@#$%^&*";
	const int zero_ascii = 48;
	unsigned int pass_long = 0;
	int cmd = 0;
	std::random_device rng;
};
