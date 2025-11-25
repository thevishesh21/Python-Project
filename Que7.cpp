7(a). GCD Using Recursion#include <iostream>
using namespace std;

int gcdRec(int a, int b) {
    if (b == 0) return a;
    return gcdRec(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD (Recursion) = " << gcdRec(a, b) << endl;
    return 0;
}

7(b). GCD Without Recursion#include <iostream>
using namespace std;

int gcdIter(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD (Loop) = " << gcdIter(a, b) << endl;
    return 0;
}