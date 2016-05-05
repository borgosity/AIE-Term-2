#include <iostream>

/****************************************************************************************
Returns true if the left most(the most significant) bit of value is set and
false otherwise
*****************************************************************************************/
bool IsLeftMostBitSet(unsigned int value)
{
		// moves x number of places to the left and checks if value is set
	if (value & 1 << 31)
	{
		std::cout << "Right most Bit True = " << (value & 1 << 31) << std::endl;
		return true;
	}
	else
	{
		std::cout << "Right Most Bit False = " << (value & 1 << 31) << std::endl;
		return false;
	}

}
/****************************************************************************************
Returns true if the right most(the least significant) bit of value is set and
false otherwise
*****************************************************************************************/
bool IsRightMostBitSet(unsigned int value)
{
	// moves x number of places to the left and checks if value is set
	if (value & 1 << 0)
	{
		std::cout << "Left most Bit True = " << (value & 1 << 0) << std::endl;
		return true;
	}
	else
	{
		std::cout << "Left Most Bit False = " << (value & 1 << 0) << std::endl;
		return false;
	}

}

/****************************************************************************************
Returns true if the asked for bit is set, and false otherwise.bit_to_check is
zero indexed from the right most bit.i.e 0 is the right most bit and 31 is the
left most.
*****************************************************************************************/
bool IsBitSet(unsigned int value, unsigned char bit_to_check)
{
	// moves x number of places to the left and checks if value is set
	return value & 1<<bit_to_check;
}

/****************************************************************************************
- This function returns the index of the right most bit set to 1 in value
- If no bits are set, it returns - 1
- For example
o 00000001 would return 0
o 10011100 would return 2
o 01010000 would return 4
o 00000000 would return -1
*****************************************************************************************/
int GetRightMostSetBit(unsigned int value)
{
	for (int i = 0; i < 32; i++)
	{
		if (value & 1 << i)
		{
			std::cout << "Index of the right most bit for " << value << " = " << i << std::endl;
			return i;
		}
	}
}

/****************************************************************************************
- Prints value to the console as a binary number
*****************************************************************************************/
void PrintBinary(unsigned char value)
{
	std::cout << value << " in Binary = ";
	for (int i = 31; i >= 0; i--)
	{
		if (value & 1 << i)
		{
			std::cout << "1";
		}
		else
		{
			std::cout << "0";
		}
	}
	std::cout << std::endl;
}

/****************************************************************************************
CHALLENGE :
- Returns true of value is a power of 2 and false otherwise.
- Use only bitwise and arithmetic operators.
*****************************************************************************************/
bool IsPowerOf2(unsigned int value)
{
	return false;
}

int main()
{
	unsigned int v1 = 1;
	unsigned int v2 = 3;
	unsigned int v3 = 4;
	unsigned int v4 = 8;
	unsigned int v5 = 16;
	unsigned int v6 = 32;
	unsigned int v7 = 7;
	unsigned int v8 = 2147483648;

	unsigned char vc1 = 1;
	unsigned char vc2 = 3;
	unsigned char vc3 = 4;
	unsigned char vc4 = 8;
	unsigned char vc5 = 16;
	unsigned char vc6 = 32;
	unsigned char vc7 = 7;
	unsigned char vc8 = 2147483648;

	IsLeftMostBitSet(v1);
	IsLeftMostBitSet(v2);
	IsLeftMostBitSet(v3);
	IsLeftMostBitSet(v4);
	IsLeftMostBitSet(v5);
	IsLeftMostBitSet(v6);
	IsLeftMostBitSet(v7);
	IsLeftMostBitSet(v8);

	IsRightMostBitSet(v1);
	IsRightMostBitSet(v2);
	IsRightMostBitSet(v3);
	IsRightMostBitSet(v4);
	IsRightMostBitSet(v5);
	IsRightMostBitSet(v6);
	IsRightMostBitSet(v7);
	IsRightMostBitSet(v8);

	for (int i = 0; i < 32; i++)
	{
		if (IsBitSet(v2, i))
		{
			std::cout << "Bit " << i << " is set" << std::endl;
		}

		if (IsBitSet(v8, i))
		{
			std::cout << "Bit " << i << " is set" << std::endl;
		}
	}

	GetRightMostSetBit(v2);
	GetRightMostSetBit(v6);
	GetRightMostSetBit(v8);

	PrintBinary(v2);
	PrintBinary(v6);
	PrintBinary(v8);

	std::cout << "finished!! \n\n" << std::endl;
	std::getc;
}
