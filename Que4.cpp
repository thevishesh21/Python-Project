4. Menu Driven String Operations (Easy C++ Code)
#include <iostream>
#include <cstring>
using namespace std;

void showAddress(char str[]) {
    for (int i = 0; str[i]; i++)
        cout << "Address of " << str[i] << " = " << (void*)&str[i] << endl;
}

void concat(char str1[], char str2[]) {
    cout << "Concatenated: " << strcat(str1, str2) << endl;
}

void compare(char str1[], char str2[]) {
    if (strcmp(str1, str2) == 0)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;
}

// Length using pointers
int lengthPointer(char *str) {
    int len = 0;
    while (*(str + len)) len++;
    return len;
}

void toUppercase(char str[]) {
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    cout << "Uppercase: " << str << endl;
}

void reverseStr(char str[]) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) cout << str[i];
    cout << endl;
}

void insertStr(char str1[], char str2[], int pos) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char res[200];
    int i;
    for (i = 0; i < pos; i++) res[i] = str1[i];
    for (int j = 0; j < len2; j++, i++) res[i] = str2[j];
    for (int j = pos; j < len1; j++, i++) res[i] = str1[j];
    res[i] = '';
    cout << "After insertion: " << res << endl;
}

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    int choice, pos;
    do {
        cout << "
Menu:
1. Show address
2. Concatenate
3. Compare
4. Length (pointer)
5. To Uppercase
6. Reverse
7. Insert at position
8. Exit
Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: showAddress(str1); break;
            case 2: concat(str1, str2); break;
            case 3: compare(str1, str2); break;
            case 4: cout << "Length: " << lengthPointer(str1) << endl; break;
            case 5: toUppercase(str1); break;
            case 6: reverseStr(str1); break;
            case 7:
                cout << "Enter position: "; cin >> pos;
                insertStr(str1, str2, pos);
                break;
            case 8: cout << "Exit.
"; break;
            default: cout << "Invalid choice.
";
        }
    } while (choice != 8);
    return 0;
}