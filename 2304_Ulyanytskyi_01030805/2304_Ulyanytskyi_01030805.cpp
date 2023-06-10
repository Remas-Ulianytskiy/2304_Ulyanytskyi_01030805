#include <iostream>
#include <array>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10;
const int MIN_RANGE = -100;
const int MAX_RANGE = 100;

void fill_array_rand(array<int, ARRAY_SIZE> & num_array);

int main()
{
    array<int, ARRAY_SIZE> num_array;
    int min_num = 0, max_num = 0;

	fill_array_rand(num_array);

	for (const auto& element : num_array) {
		if (min_num > element)
			min_num = element;
		if (max_num < element)
			max_num = element;
	}

	cout << "Array = { ";
	for (const auto& element : num_array) {
		cout << element << ", ";
	}
	cout << '}';

	cout << endl;
	cout << "min: " << min_num << endl;
	cout << "max: " << max_num << endl;

    return 0;
}

void fill_array_rand(array<int, ARRAY_SIZE> & num_array) {
	srand(time(0));

	for (int i = 0; i < num_array.size(); i++) {
		num_array[i] = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
	}
}