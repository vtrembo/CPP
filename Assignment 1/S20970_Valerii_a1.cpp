#include <iostream>
	using namespace std;
	void clean(char* n) {
		for (int i = 0; n[i] != '\0'; i++) {
			if (n[i] == ' ') {
				if (n[i] == n[i + 1]) {
					for (int j = i; n[j] != '\0'; ++j) {
						n[j] = n[j + 1];
					}
					--i;
				}
				if (n[0] == ' ') {
					for (int m = 0; n[m] != '\0'; ++m) {
						n[m] = n[m + 1];
					}
				}
				if (n[i + 1] == '\0') n[i] = '\0';
			}
		}
	}
		int main() {
			char n1[] = "a bc def   ghijk";
			cout << "Before: >" << n1 << "<" << endl;
			clean(n1);
			cout << " After: >" << n1 << "<" << endl;
			char n2[] = "   a bc def ghijk   ";
			cout << "Before: >" << n2 << "<" << endl;
			clean(n2);
			cout << " After: >" << n2 << "<" << endl;
			char n3[] = " ";
			cout << "Before: >" << n3 << "<" << endl;
			clean(n3);
			cout << " After:>" << n3 << "<" << endl;
		}

#include <iostream>
		using namespace std;
		void write_results(const char* s1, const char* s2);
		int main() {
			char str1[] = "A very long sentence";
			char str2[] = "Another not so short sentence";

			write_results(str1, str2);
		}
		void write_results(const char* s1, const char* s2) {
			char number1 = ' ', number2 = ' ', number3 = ' ', number4 = ' ';
			for (int i = 0; s1[i] != '\0'; i++) {
				for (int j = 0; s2[j] != '\0'; j++) {
					if (s1[i] == s2[j] && s1[i] != ' ') {
						if (s1[i] < 90) {
							char tmp = s1[i] + 32;
							number1 = tmp;
							cout << tmp;
							break;
						}
						else {
							number1 = s1[i];
							cout << s1[i];
							break;
						}
					}
				}
			}
		}