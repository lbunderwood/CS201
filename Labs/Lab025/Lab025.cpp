// Luke Underwood
// 11/1/2019
// CS201
// Lab025
// Lab025.cpp

#include<iostream>
#include<vector>
#include<algorithm>

struct vector 
{
	std::vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> v2 = { 0, 1, 4, 2, 3, 5, 6, 9, 8, 7 };
};


int main()
{
	vector vec;

	while (vec.v1 != vec.v2)
	{
		auto p1 = std::mismatch(vec.v1.begin(), vec.v1.end(), vec.v2.begin());

		std::cout << "There was a mismatch at index " << *p1.first << std::endl
			<< "The values were " << vec.v1[*p1.first] << ", " 
			<< vec.v2[*p1.first] << std::endl;

		vec.v2[*p1.first] = vec.v1[*p1.first];

	}

	std::cout << "There was no mismatch!" << std::endl;
}