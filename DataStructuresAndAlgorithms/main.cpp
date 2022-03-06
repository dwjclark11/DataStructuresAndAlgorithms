
#include "CPP_Style/Vector.h"
#include "CPP_Style/Utils.h"

int main()
{
	Vector<float> vec;

	vec.push_back(8.5f);
	vec.push_back(5.5f);
	vec.push_back(1.5f);
	vec.insert(2, 22.0);
	//vec.pop_back();
	vec.push_back(14.1);
	vec.push_back(14.1);
	vec.push_back(14.1);
	vec.push_back(14.1);
	
	return 0;
} 