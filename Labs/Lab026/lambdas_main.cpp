/**
 * @file     lambdas.hpp
 * @author   Student Name
 * @date     Mar 21, 2019
 * John Quan
 *
 * Practice using lambda functions
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>

#include "lambdas.hpp"

int main() {

	// TODO: REQUIRED
	//       Create a vector<pair<size_t, string>> to enumerate
	//       each string in the WIKIPEDIA_CPP string vector.
	std::vector<std::pair<size_t, std::string>> wikivec;
	for (const auto& n : WIKIPEDIA_CPP)
	{
		wikivec.push_back({ n.size(), n });
	}


	// TODO: REQUIRED
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the first member in descending order.
	std::sort(wikivec.begin(), wikivec.end(),
		[](auto a, auto b)
		{
			return a > b;
		});


	// TODO: REQUIRED
	//       Use printVectorPairs() to print the vector
	std::cout << printVectorPairs(wikivec.begin(), wikivec.end());


	// TODO: ADDITIONAL 1
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the second member in ascending order.
	std::cout << std::endl << "ADDITIONAL 1:" << std::endl << std::endl;
	std::sort(wikivec.begin(), wikivec.end(),
		[](auto a, auto b)
		{
			return a.second < b.second;
		});

	// TODO: ADDITIONAL 1
	//       Use printVectorPairs() to print the vector
	std::cout << printVectorPairs(wikivec.begin(), wikivec.end());


	// TODO: ADDITIONAL 2
	//       Use std::find_if with a comparison lambda function that prints
	//       the vector pairs where the pair's second.length() > 15.
	//       Print the vector as described in the lab.



	return 0;
}
