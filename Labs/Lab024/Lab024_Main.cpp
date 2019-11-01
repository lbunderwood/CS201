//Luke Underwood
//10/30/19
//CS201
//Lab024_Main.cpp
//Source file for Lab024

#include<iostream>
#include<vector>
#include<algorithm>

//prints the vector
void printvec(const std::vector<int> vec)
{
	for (const auto& n : vec)
			std::cout << n << " ";
		std::cout << std::endl;
}

int main()
{
	int start;
	int end;

	//print the vector
	std::vector<int> vec = { 9, 7, 5, 1, 2, 4, 0, 3, 8, 6 };
	printvec(vec);

	std::cout << "How much would you like to modify?\n"
		<< "start: ";
	std::cin >> start;
	std::cout << "end: ";
	std::cin >> end;

	//print the sorted vector
	std::cout << "Sorted: \n";
	std::sort(vec.begin() + start, vec.begin() + end);
	printvec(vec);

	//print the reverse of the sorted vector
	std::cout << "Reversed: \n";
	std::reverse(vec.begin() + start, vec.begin() + end);
	printvec(vec);

	//print the vector with part of it filled with 2's
	std::cout << "Filled: \n";
	std::fill(vec.begin() + start, vec.begin() + end, 2);
	printvec(vec);

	//rotate and print
	std::cout << "Rotated: \n";
	std::rotate(vec.begin(), vec.begin() + end - start, vec.end());
	printvec(vec);
}