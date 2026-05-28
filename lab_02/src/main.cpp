#include <iostream>
#include <ctime>
#include <string>

double calculate(double x)
{
    return x*x - x*x + x*4 - x*5 + x + x;
}

int main()
{
    int n;
    std::string input;
    double x = 1.0;

    while (true)
    {
        std::cout << "Enter num of iterations: " << std::endl;
        std::cin >> input;

	try {
            n = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input. Please, enter a number" << std::endl;
            break;
        }

	n = std::stoi(input);

        if (n <= 0) break;

        clock_t start = clock();
        for (int i = 0; i < n; i++)
	{
            calculate(x);
        }
        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << "Time: " << seconds << " sec\n";
    }

    std::cout << "Error. Try again" << std::endl;
    return 0;
}
