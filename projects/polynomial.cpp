#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Polynomial {
private:
    int a, b, c;

public:
    Polynomial() {
        a = 1;
        b = 1;
        c = 1;
    }

    Polynomial(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
    }

    string format() {
        string aa = to_string(a);
        string bb = to_string(b);
        string cc = to_string(c);

        string out = aa + "x^2 + " + bb + "x + " + cc;

        return out;
    }

    int eval(int x) {
        return a * x * x + b * x + c;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        result.a = this->a + other.a;
        result.b = this->b + other.b;
        result.c = this->c + other.c;
        return result;
    }

    int& operator[](int index) {
        if (index == 0) {
            return a;
        } else if (index == 1) {
            return b;
        } else if (index == 2) {
            return c;
        } else {
            cout << "Invalid index. Exiting program." << endl;
            exit(EXIT_FAILURE);
        }
    }

    bool operator==(const Polynomial& other) const {
        return (this->a == other.a) && (this->b == other.b) && (this->c == other.c);
    }
};

int main() {
    Polynomial p1(2, 3, 4);
    Polynomial p2(1, -1, 2);

    cout << "Polynomial 1: " << p1.format() << endl;
    cout << "Polynomial 2: " << p2.format() << endl;

    Polynomial p3 = p1 + p2;
    cout << "Sum of Polynomials: " << p3.format() << endl;

    p1[0] = 5;
    p1[1] = -2;
    cout << "Modified Polynomial 1: " << p1.format() << endl;

    if (p1 == p2) {
        cout << "Polynomial 1 and Polynomial 2 are equal." << endl;
    } else {
        cout << "Polynomial 1 and Polynomial 2 are not equal." << endl;
    }

    return 0;
}
