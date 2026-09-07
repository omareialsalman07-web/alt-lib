#include<iostream>
#include "alt/array.h"

void Print(const alt::array<int, 5>& arr)
{
	for (auto x : arr) {
		std::cout << x << std::endl;
	}
}

int main() {

	alt::array<int, 5> arr;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	alt::array<int, 5> arr2 = arr;
	std::cout << "\nArr 2 : \n";
	Print(arr2);

	arr2[2] = 0;

	std::cout << "Arr 1 : \n";
	Print(arr);
	

	return 0;
}