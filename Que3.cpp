3. Count Occurrences of Alphabets

#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]) {
    char str[100];
    if (argc > 1) strcpy(str, argv[1]);
    else {
        cout << "Enter text: ";
        cin.getline(str, 100);
    }
    int count[26] = {0};
    for (int i = 0; str[i]; i++)
        if (isalpha(str[i]))
            count[tolower(str[i]) - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << char('a' + i) << ": " << count[i] << endl;
    return 0;
}