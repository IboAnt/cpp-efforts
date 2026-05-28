#include <iostream>
#include <string>

double add(double a, double b)
{
	return a+b;
}

double subtract(double a, double b)
{
	return a-b;
}

double power(double a, int n)
{
	double result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result * a;
	}
	return result;
}

int main(int argc, char* argv[])
{
	if (argc > 4)
	{
		std::cout << "Too many arguments" << std::endl;
		return 1;
	}

	else if (argc < 4)
	{
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}

	double a = std::stod(argv[1]);
	std::string oper = argv[2];
	double b = std::stod(argv[3]);

	double result;

	if (oper == "+")
	{
		result = add(a, b);
	}

	else if (oper == "-")
	{
		result = subtract(a, b);
	}

	else if (oper == "^")
	{
		result = power(a, int(b));
	}

	else
	{
		std::cout << "Invalid operator" << std::endl;
		return 1;
	}

	std::cout << result << std::endl;
	return 0;
}
