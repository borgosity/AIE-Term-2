#include <iostream>
#include "..\Math_Unit_Test\vectorTest.h"
#include "..\tests\unitTest_v2_m2.h"
#include "..\tests\unitTest_v3_m3.h"

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;
	int i = 0;
	std::cin >> i;
	return 0;
}