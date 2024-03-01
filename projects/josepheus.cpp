#include <iostream>
#include <queue>

using namespace std;

int josephus(int n, int k) {
    queue<int> circle;

    for (int i = 1; i <= n; ++i) {
        circle.push(i);
    }

    while (circle.size() > 1) {
        for (int i = 0; i < k - 1; ++i) {
            int front = circle.front();
            circle.pop();
            circle.push(front);
        }
        circle.pop();
    }

    return circle.front();
}

int main() {
    int n, k;
    cout << "Enter the number of people in the circle: ";
    cin >> n;
    cout << "Enter the value of k (every kth person gets eliminated): ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "The person to survive is: " << survivor - 1 << endl;

    return 0;
}
