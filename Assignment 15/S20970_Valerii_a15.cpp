#include <iostream>
using namespace std;
class Segment {
    double A, B;
public:
    friend ostream& operator << (ostream& s, const Segment& seg);
    Segment(double A, double B) : A(A), B(B) { }
    Segment operator* (double x)const {
        return Segment(A * x, B * x);
    }
    Segment operator/ (double x)const {
        return Segment(A / x, B / x);
    }
    Segment operator+ (double x)const {
        return Segment(A + x, B + x);
    }
    Segment operator- (double x)const {
        return Segment(A - x, B - x);
    }
    Segment operator+ (Segment x)const {
        if (A > x.A) {
            return Segment(x.A, B);
        }
        else {
            return Segment(A, x.B);
        }
    }
    bool operator()(double x) const {
        return A < x&& x < B;
    }
};
ostream& operator << (ostream& s, const Segment& seg) {
    return s << "[" << seg.A << "," << seg.B << "]";
}
Segment operator* (double x, const Segment& s) {
    return s * x;
}
Segment operator/ (double x, const Segment& s) {
    return s / x;
}
Segment operator+ (double x, const Segment& s) {
    return s + x;
}
int main() {
    Segment seg{ 2,3 }, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
    cout << s << endl << boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        cout << "x=" << x << ": " << s(x) << endl;
}