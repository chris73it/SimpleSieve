#include <cstdint>
#include <iostream>
#include <array>
#include "Quot.h"

int main()
{
	//Quot qa{ 5,20 };
	//std::cout << qa << " (" << qa.approx() << ")" << std::endl;

	Quot qb{ 6,15 };
	std::cout << qb << " (" << qb.approx() << ")" << std::endl;

	/*Quot result = qa + qb;
	std::cout << result << " (" << result.approx() << ")" << std::endl;*/

	return 0;
}
