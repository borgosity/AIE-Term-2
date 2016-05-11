#include <iostream>
#include "..\tests\unitTest_v2_m2.h"
#include "..\tests\unitTest_v3_m3.h"

int main() {

	runTests_2();
	runTests_3();
	std::cout << "All tests passed successfully." << std::endl;
	int i = 0;
	std::cin >> i;
	return 0;
}