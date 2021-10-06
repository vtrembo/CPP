#include <iostream>
size_t length(const char* cstr);
bool isLetter(char c);
char* reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char* concat(char* t, const char* s);
int main() {
	using std::cout; using std::endl;
	char s1[] = "Alice in Wonderland";
	cout << "reverse: " << reverse(s1) << endl;
	cout << "length : " << length(s1) << endl;
	char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
	cout << "words  : " << words(s2) << endl;
	cout << "words2 : " << words2(s2) << endl;
	char s3[100] = "Hello";
	cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;
}
size_t length(const char* cstr) {
	size_t length = 0;
	for (int i = 0; cstr[i] != '\0'; i++, length++) {}
	return length;
}
bool isLetter(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 	return true;
	return false;
}
char* reverse(char* cstr) {
	for (int i = length(cstr) - 1, j = 0, tmp; i > j; tmp = cstr[j], cstr[j] = cstr[i], cstr[i] = tmp, i--, j++) {}
	return cstr;
}
size_t words(const char* cstr) {
	size_t amountOfWords = 0;
	for (int i = 0; cstr[i] != '\0'; i++)
		if (isLetter(cstr[i]) == true && isLetter(cstr[i + 1]) == false) 	amountOfWords++;
	return amountOfWords;
}
size_t words2(const char* cstr) {
	size_t amountOfWords = 0;
	for (int i = 0; cstr[i] != '\0'; i++)
		if (isLetter(cstr[i - 1]) == true && isLetter(cstr[i]) == true && isLetter(cstr[i + 1]) == false) 	amountOfWords++;
	return amountOfWords;
}
char* concat(char* t, const char* s) {
	for (int i = 0; s[i] != '\0'; i++) {
		t[length(t)] = s[i];
	}
	return t;
}