#include<iostream>
#include <iomanip>

int main()
{
	int cols = 27;
	int rows = 10;
	char letter = 'A';
	for (unsigned int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			
			if (j > 0)
			{
				std::cout << std::setw(8) << letter;
				letter++;
			}
			if (i > 0)
				std::cout << i;
			if (i == 0)
				std::cout << " ";
		}
		std::cout << std::endl;
		letter = 'A';
	}
}