/*
Luke Underwood
10/2/19
vector_manip.cpp
Has functions for additional portions of lab013
*/

#include "vector_manip.hpp"


void firstLetterChange(std::vector<std::string>& strVec, const char& c)
{
	for (auto & n : strVec)
	{
		if ( n.size() > 0 )
			n[0] = c;
	}
}
