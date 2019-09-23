#include<string>
#include"modifyString.h"

int modifyString(std::string & inputstring, int n)
{
	inputstring += std::to_string(n);
	return inputstring.size();
}