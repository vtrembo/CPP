#define _CRT_SECURE_NO_WARNINGS = 1
#include <iostream>
#include <cstring>   // strlen, strcpy, strcat, strcmp...
#include <cctype>    // tolower, toupper
class String {
    char* str;
public:
    String(const char* s) {
        str = strcpy(new char[strlen(s) + 1], s);
    }
    String(const String& s) {
        str =strcpy(new char[strlen(s.str) + 1], s.str);
    }
    String() {
        str = nullptr;
    }
    ~String() {
        delete[] str;
    }
    String& operator= (const String& other) {
        if (this == &other) return *this;
        delete[] str;
        str = strcpy(new char[strlen(other.str) + 1], other.str);
        return *this;
     }

    friend std::ostream& operator << (std::ostream& stream, const String& a) {
        return stream << a.str;
    }
     size_t length() {
        size_t length = 0;
        for (int i = 0; str[i] != '\0'; i++, length++);
        return length;
    }
     String toUpper() {
         for (int i = 0; str[i] != '\0';i++) {
             str[i] = toupper(str[i]);
         }
         return str;
     }
     String toLower() {
         for (int i = 0; str[i] != '\0';i++) {
             str[i] = tolower(str[i]);
         }
         return str;
     }
     friend String operator+ (const String& a, const String& b);
     friend String operator+ (const char* a, const String& b);
     friend String operator+ (const String& a, const char* b);
};
// ...
String operator+ (const String& a, const String& b)  {
    char* cstr = new char [strlen(a.str) + strlen(b.str) + 1];
    strcpy(cstr, a.str);
    strcat(cstr, b.str);
    String x;
    x.str = cstr;
    return x;
}
String operator+ (const char* a, const String& b) {
    char* cstr = new char[strlen(a) + strlen(b.str) + 1];
    strcpy(cstr, a);
    strcat(cstr, b.str);
    String x;
    x.str = cstr;
    return x;
}
String operator+ (const String& a, const char* b) {
    char* cstr = new char[strlen(a.str) + strlen(b) + 1];
    strcpy(cstr, a.str);
    strcat(cstr, b);
    String x;
    x.str = cstr;
    return x;
}
int main() {
    char b[] = "Hello";
    String mystring(b);
    std::cout << mystring << std::endl;
    String anotherStr(mystring);
    std::cout << anotherStr << std::endl;
    std::cout << anotherStr + mystring << std::endl;
    String s = ("To " + String("be ") +
        "or not to be").toUpper() + "!";
    std::cout << s << std::endl;
    String a("a"), A = "A";
 //   std::cout << std::boolalpha
 //       << ("a" == a && "a" != A && a != A &&
 //           a == "a" && A != "a" && a == A.toLower() &&
  //          s.length() == 19) << std::endl;
    a = String(a).toUpper() + "li" + String("ce");
    std::cout << a << ", len=" << a.length() << std::endl;
}