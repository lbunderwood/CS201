/**
 * @file     insertion_sort.cpp
 * @author   Student Name
 * @version  Feb 17, 2019
 * John Quan
 * @brief
 */

#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& data) {
	for (size_t i = 1; i < data.size(); i++)
	{
		int current = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > current)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = current;
	}
}

bool isEqual(const std::vector<int> & v1, const std::vector<int> & v2) {
	// compare lengths
	if (v1.size() != v2.size()) {
		return false;
	}
	// compare elements
	for (unsigned long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}
	// must be the same
	return true;
}

void printVector(const std::vector<int>& vec) {
	for (const auto& element : vec) {
		std::cout << element << ' ';
	}
}
