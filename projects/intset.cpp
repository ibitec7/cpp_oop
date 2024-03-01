#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IntegerSet {
private:
    vector<bool> a;

public:
    IntegerSet() {
        // Initialize the vector with a size of 101 and set all elements to false
        a.resize(101, false);
    }

    IntegerSet(vector<int> vec) {
        // Initialize the vector with a size of 101 and set all elements to false
        a.resize(101, false);
        
        for (int i = 0; i < vec.size(); i++) {
            // Check if the index is within bounds before accessing
            if (vec[i] >= 0 && vec[i] < a.size()) {
                a[vec[i]] = true;
            }
        }
    }

    IntegerSet unionOfSets(IntegerSet y) {
        IntegerSet out;
        int cap = max(a.size(), y.a.size());

        // Resize the output vector to the maximum size
        out.a.resize(cap, false);

        for (int i = 0; i < cap; i++) {
            // Check if the index is within bounds before accessing
            if (i < a.size() && i < y.a.size()) {
                out.a[i] = a[i] || y.a[i];
            }
        }

        return out;
    }

    IntegerSet intersectionOfSets(IntegerSet y) {
        IntegerSet out;
        int cap = min(a.size(), y.a.size());

        // Resize the output vector to the minimum size
        out.a.resize(cap, false);

        for (int i = 0; i < cap; i++) {
            // Check if the index is within bounds before accessing
            if (i < a.size() && i < y.a.size()) {
                out.a[i] = a[i] && y.a[i];
            }
        }

        return out;
    }

    void insertElement(int k) {
        // Check if the index is within bounds before accessing
        if (k >= 0 && k < a.size()) {
            a[k] = true;
        }
    }

    void deleteElement(int k) {
        // Check if the index is within bounds before accessing
        if (k >= 0 && k < a.size()) {
            a[k] = false;
        }
    }

    string to_String() {
        string out = "{ ";
        for (int i = 0; i < a.size(); i++) {
            if (a[i]) {
                string temp = to_string(i);
                out = out + temp + " ";
            }
        }
        out = out + "}";
        return out;
    }

    bool isEqualTo(IntegerSet y) {
        if (a.size() != y.a.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != y.a[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> b = {1, 4, 7};
    IntegerSet alpha = IntegerSet();
    IntegerSet beta = IntegerSet(b);
    alpha.insertElement(4);
    alpha.insertElement(7);
    IntegerSet gamma = alpha.intersectionOfSets(beta);
    beta.insertElement(19);
    beta.insertElement(29);
    IntegerSet phi = alpha.unionOfSets(beta);
    cout << alpha.to_String() << endl;
    cout << beta.to_String() << endl;
    cout << gamma.to_String() << endl;
    cout << phi.to_String() << endl;
}