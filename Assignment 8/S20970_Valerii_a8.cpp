#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
using std::vector;
using std::function;
template <typename T, typename FunType>
vector<T> filter(const vector<T>& v, FunType p) {
	vector<T> w;
	for (int i = 0; i < v.size(); i++) {
		if (p(v[i])) w.push_back(v[i]);
	}
	return w;
}
template <typename T, typename FunType1, typename FunType2>
vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p) {
	vector<T> w;
	for (int i = 0; i < v.size(); i++) {
		v[i] = t(v[i]);
		if (p(v[i])) w.push_back(v[i]);
	}
	return w;
}
template <typename T>
void printVec(const vector<T>& v) {
	std::cout << "[ ";
	for (int i = 0; i < v.size(); i++) 	std::cout << v[i] << ' ';
	std::cout << "]" << '\n';
}
int main() {
	vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
	printVec(v);
	vector<int> r = filter(v, [](int a) {
		return a % 2 == 0;
		});
	printVec(r);
	vector<int> s = filter(v, [](int a) {
		return a > 0;
		});
	printVec(s);
	vector<double> w{ 1.5, -3.1, 4.0, -2.0, 6.3 };
	printVec(w);
	double mn = -0.5, mx = 0.5;
	vector<double> d =
		transfilt(w, [](double a) {
		return sin(a);
			}, [mn, mx](double a) {
				return mn < a && a < mx;
			});
	printVec(w);
	printVec(d);
}