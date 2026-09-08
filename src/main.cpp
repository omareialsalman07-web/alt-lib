#include<iostream>
#include "alt/array.h"

#include "alt/vector.h"
#include <vector>

void testArray()
{
	alt::array<int, 5> arr;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	//arr.reverse();

	for (auto x : arr) {
		std::cout << x << std::endl;
	}
}

void testVector()
{
	alt::vector<int> arr;

	arr.clear();

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	//arr.reverse();
	//arr.erase(2);

	for (auto x : arr) {
		std::cout << x << std::endl;
	}

	//std::vector<int> v;
	
}

int main() {

	//testArray();
	testVector();
	

	return 0;
}