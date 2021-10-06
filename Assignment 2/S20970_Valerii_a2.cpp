#include <iostream>
using namespace std;
void write_results(const char* s1, const char* s2);
int main() {
	char str1[] = "A very long sentence";
	char str2[] = "Another not so short sentence";
	write_results(str1, str2);
}
void write_results(const char* s1, const char* s2) {
	bool num = true;
	for (char lowerCaseLetter = 'a', upperCaseLetter = 'A'; lowerCaseLetter != ('z' + 1), upperCaseLetter != ('Z' + 1); lowerCaseLetter++, upperCaseLetter++) {
		for (int i = 0; s1[i] != '\0'; i++) {
			if (lowerCaseLetter == s1[i] || upperCaseLetter == s1[i]) {
				for (int j = 0; s2[j] != '\0'; j++) {
					if (lowerCaseLetter == s2[j] || upperCaseLetter == s2[j]) {
						num = false;
						cout << lowerCaseLetter << " ";
						break;
					}
				}
			}
			if (num == false) {
				num = true;
				break;
			}
		}
	}
	cout << endl;
	for (char lowerCaseLetter = 'a', upperCaseLetter = 'A'; lowerCaseLetter != ('z' + 1), upperCaseLetter != ('Z' + 1); lowerCaseLetter++, upperCaseLetter++) {
		for (int i = 0; s1[i] != '\0'; i++) {
			if (lowerCaseLetter == s1[i] || upperCaseLetter == s1[i]) {
				for (int j = 0; s2[j] != '\0'; j++) {
					if (s1[i] == s2[j]) {
						num = false;
						break;
					}
				}
				if (num == false) {
					num = true;
				}
				else {
					cout << lowerCaseLetter << " ";
				}
			}
		}
	}
}