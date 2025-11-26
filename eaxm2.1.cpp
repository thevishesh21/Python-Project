#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Reverse {
public:
    // Function to reverse a string
    string reverseString(string str) {
        reverse(str.begin(), str.end());
        return str;
    }

    // Function to reverse a number
    int reverseNumber(int num) {
        int reversed = 0;
        while (num != 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
};

int main() {
    Reverse r;
    string s = "Hello";
    int n = 12345;

    cout << "Original String: " << s << endl;
    cout << "Reversed String: " << r.reverseString(s) << endl;

    cout << "Original Number: " << n << endl;
    cout << "Reversed Number: " << r.reverseNumber(n) << endl;

    return 0;
}