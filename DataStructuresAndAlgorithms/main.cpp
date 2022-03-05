
#include "CPP_Style/List.h"

int main()
{
	List<int> list;

	list.push_back(7.5);
	list.push_back(8.5);
	list.push_back(4.5);

	if (!list.empty())
		list.Display();

	auto val = list.pop_back();
	auto val2 = list.pop_front();
	if (list.length() > 0)
		list.Display();

	list.push_front(val);
	list.push_back(val2);

	list.Display();


	return 0;
} 