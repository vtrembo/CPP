#include <iostream>
#include <functional> // std::function
#include <utility> // std::swap (not indispensable)
void mysort(int arr[], size_t size,
	std::function<bool(int, int)> cmp) {
	for (int i = 0, temp; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cmp(arr[j + 1], arr[j])) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int sumOfDigits(int x) {
	int sum = 0;
	while (x != 0) {
		sum = sum + x % 10;
		x = x / 10;
	}
	return sum;
}
void printArr(int arr[], size_t size) {
	std::cout << "[ ";
	for (int i = 0; i != size; i++) 	std::cout << arr[i] << " ";
	std::cout << "]\n";
}
int main() {
	int a[]{ 3, 77, 21, 19, 2, 54, 28, 91 };
	size_t size = std::size(a);
	std::cout << "Normal (natural) order\n";
	mysort(a, size, [](int a, int b) {
		return a < b;
		}
	);
	printArr(a, size);
	std::cout << "Natural order reversed\n";
	mysort(a, size, [](int a, int b) {
		return a > b;
		});
	printArr(a, size);
	std::cout << "By sum of digits, then natural\n";
	mysort(a, size, [](int a, int b) {
		int x = sumOfDigits(a); int y = sumOfDigits(b);
		if (x != y) return x < y; else return a < b;
		});
	printArr(a, size);
	int mod{};
	auto byrem =  [&mod](int a, int b) {
		int x = a % mod; int y = b % mod;
		if (x != y) return y > x; else return a > b;
		} ;
	for (int i : {3, 5, 7}) {
		mod = i;
			std::cout << "By remainder mod " << mod
			<< ", then natural reversed\n";
		mysort(a, size, byrem);
		printArr(a, size);
	}
} 