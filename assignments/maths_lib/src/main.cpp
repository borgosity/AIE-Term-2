#include <iostream>
//#include "..\Math_Unit_Test\vectorTest.h"
//#include "..\Math_Unit_Test\matrixTest.h"
//#include "..\tests\unitTest_v2_m2.h"
//#include "..\tests\unitTest_v3_m3.h"
#include "unittest.h"

int main() {

	//if (runUnitTests() == false) 
	//{
	//	std::cout << "Unit test failed!" << std::endl;
	//	return -1;
	//}
	//else
	//{
	//	std::cout << "All Vector tests passed successfully." << std::endl;
	//}
	//if (runMatrixTests() == false) 
	//{
	//	std::cout << "Matrix test failed!" << std::endl;
	//	return -1;
	//}
	//else
	//{
	//	std::cout << "All Matrix tests passed successfully." << std::endl;
	//}
	if (runUnitTests() == false)
	{
		std::cout << "test failed!" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "All tests passed successfully." << std::endl;
	}
	int i = 0;
	std::cin >> i;
	return 0;
}