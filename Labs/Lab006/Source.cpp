/*
Luke Underwood
9/16/19
Lab006.cpp

*/

#include<iostream>
#include<string>
#include<vector>

void testVector()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(3);

	for (const int& x : v)
	{
		std::cout << "x: " << x << std::endl;
	}
}

int main()
{

	testVector();
	return 0;
}