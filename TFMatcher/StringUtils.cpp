#include "StringUtils.h"

string StringUtils::OutputMatlabVector(string _vectorName, const vector<double>& _vec)
{
	ostringstream ss;

	ss << _vectorName << " = [";
	for (vector<double>::const_iterator iter = _vec.begin(); iter != _vec.end(); iter++)
	{
		if (iter + 1 != _vec.end())
			ss << *iter << ", ";
		else
			ss << *iter << "]" << endl;
	}

	return ss.str();
}