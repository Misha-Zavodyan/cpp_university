#include <iostream>
#include "date.h"
int main(void)
{
	int info[6];
	std::cout << "Enter first date day: ";
	std::cin >> info[0];
	std::cout << "Enter first date month: ";
	std::cin >> info[1];
	std::cout << "Enter first date year: ";
	std::cin >> info[2];
	std::cout << "Enter second date day: ";
	std::cin >> info[3];
	std::cout << "Enter second date month: ";
	std::cin >> info[4];
	std::cout << "Enter second date year: ";
	std::cin >> info[5];
	if ((info[0] > 0)&&(info[0] < 31)&&(info[3] > 0)&&(info[3] < 31)&&(info[1] > 0)&&(info[1] < 13)&&(info[4] > 0)&&(info[4] < 13))
	{
		Date date1(info[0], info[1], info[2]), date2(info[3], info[4], info[5]);
		std::cout << date1 + date2 << std::endl;
	} else std::cout << "Wrong input data" << std::endl;
	return 0;
}