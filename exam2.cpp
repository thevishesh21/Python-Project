#include <iostream>
#include <string>
using namespace std;

class Reverse {
public:
    // Reverse a string using a loop
    string reverseString(const string &str) {
        string reversed = "";
        for (int i = str.length() - 1; i >= 0; --i) {
            reversed += str[i];
        }
        return reversed;
    }
};

int main() {
    Reverse obj;
    string input = "Hello";
    cout << "Original: " << input << endl;
    cout << "Reversed: " << obj.reverseString(input) << endl;
    return 0;
}