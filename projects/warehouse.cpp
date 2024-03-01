#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class WareHouse {
private:
    vector<int> code = {};
    vector<int> qnty = {};

public:
    void stock(int c, int q) {
        auto it = find(code.begin(), code.end(), c);
        if (it != code.end()) {
            int index = distance(code.begin(), it);
            qnty[index] += q;
        } else {
            code.push_back(c);
            qnty.push_back(q);
            cout << q << " items with code " << c << " added" << endl;
        }
    }

    void order(int c, int q) {
        auto it = find(code.begin(), code.end(), c);
        if (it != code.end()) {
            int index = distance(code.begin(), it);
            if (qnty[index] >= q) {
                qnty[index] -= q;
                cout << q << " items delivered with code " << c << endl;
            } else {
                cout << "The requested quantity is not available" << endl;
            }
        } else {
            cout << "Invalid code" << endl;
        }
    }

    void show(int c) {
        auto it = find(code.begin(), code.end(), c);
        if (it != code.end()) {
            int index = distance(code.begin(), it);
            cout << qnty[index] << " items are stored with code " << c << endl;
        } else {
            cout << "Invalid Code!" << endl;
        }
    }
};

int main() {
    WareHouse w;
    w.stock(1, 10);
    w.stock(2, 20);
    w.stock(3, 30);
    w.stock(1, 5);
    w.order(1, 3);
    w.order(2, 25);
    w.order(2, 11);
    w.order(4, 5);
    w.show(1);
    w.show(2);
    w.show(3);
    w.show(4);

    return 0;
}
