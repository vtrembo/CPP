#include <iostream>
size_t length(const char* cstr) {
	size_t length = 0;
	for (int i = 0; cstr[i] != '\0'; i++, length++) {}
	return length;
}
bool checkUpperCaseLetter(const char* cstr) {
	bool isUpperCaseLetter = false;
	for (int i = 0; cstr[i] != '\0'; i++) {
		for (char upperCaseLetter = 'A'; upperCaseLetter != ('Z' + 1); upperCaseLetter++) {
			if (cstr[i] == upperCaseLetter) {
				return isUpperCaseLetter = true;
			}
		}
	}
	return isUpperCaseLetter;
}
bool checkLowerCaseLetter(const char* cstr) {
	bool isLowerCaseLetter = false;
	for (int i = 0; cstr[i] != '\0'; i++) {
		for (char lowerCaseLetter = 'a'; lowerCaseLetter != ('z' + 1); lowerCaseLetter++) {
			if (cstr[i] == lowerCaseLetter) {
				return isLowerCaseLetter = true;
			}
		}
	}
	return isLowerCaseLetter;
}
bool checkDigit(const char* cstr) {
	bool isDigit = false;
	for (int i = 0; cstr[i] != '\0'; i++) {
		for (char digit = '0'; digit != ('9' + 1); digit++) {
			if (cstr[i] == digit) {
				return isDigit = true;
			}
		}
	}
	return isDigit;
}
bool checkNonAlphanumeric(const char* cstr) {
	bool isNonAlphanumeric = false;
	for (int i = 0; cstr[i] != '\0'; i++) {
		for (char NonAlphanumeric = 32; NonAlphanumeric != 48; NonAlphanumeric++) {
			if (cstr[i] == NonAlphanumeric) {
				return isNonAlphanumeric = true;
			}
		}
		for (char NonAlphanumeric = 58; NonAlphanumeric != 65; NonAlphanumeric++) {
			if (cstr[i] == NonAlphanumeric) {
				return isNonAlphanumeric = true;
			}
		}
		for (char NonAlphanumeric = 91; NonAlphanumeric != 97; NonAlphanumeric++) {
			if (cstr[i] == NonAlphanumeric) {
				return isNonAlphanumeric = true;
			}
		}
		for (char NonAlphanumeric = 123; NonAlphanumeric != 127; NonAlphanumeric++) {
			if (cstr[i] == NonAlphanumeric) {
				return isNonAlphanumeric = true;
			}
		}
	}
	return isNonAlphanumeric;
}
int checkAmountOfDifferentCharacters(const char* cstr) {
	bool isDifferent = false;
	int amountOfDifferentCharacters = 0;
	for (int i = 0; cstr[i + 1] != '\0'; i++) {
		for (int j = i + 1; cstr[j] != '\0'; j++) {
			if (cstr[i] == cstr[j]) {
				isDifferent = false;
				break;
			}
			else {
				isDifferent = true;
			}
		}
		if (isDifferent) amountOfDifferentCharacters++;
	}
	return amountOfDifferentCharacters;
}
bool checkpass(const char* pass) {
	bool goodPass = true;
	if (length(pass) < 8) {
		std::cout << "Too short" << "\n";
		goodPass = false;
	}
	if (checkAmountOfDifferentCharacters(pass) >= 6) { }
	else {
		std::cout << "Too few different characters" << "\n";
		goodPass = false;
	}
	if (checkDigit(pass)) { }
	else {
		std::cout << "No digit" << "\n";
		goodPass = false;
	}
	if (checkUpperCaseLetter(pass)) { }
	else {
		std::cout << "No uppercase letter" << "\n";
		goodPass = false;
	}
	if (checkLowerCaseLetter(pass)) { }
	else {
		std::cout << "No lowercase letter" << "\n";
		goodPass = false;
	}
	if (checkNonAlphanumeric(pass)) {}
	else {
		std::cout << "No non-alphanumeric character" << "\n";
		goodPass = false;
	}
	return goodPass;
}
int main() {
	using std::cout; using std::endl;
	const char* passes[] =
	{
	"AbcDe93", "A1b:A1b>", "Ab:Acb<",
	"abc123><", "Zorro@123", nullptr
	};
	for (int i = 0; passes[i] != nullptr; ++i) {
		cout << "checking " << passes[i] << endl;
		if (checkpass(passes[i])) cout << "OK" << endl;
		cout << endl;
	}
}