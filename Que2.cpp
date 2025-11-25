2. Remove Duplicates from Array

#include <iostream>
using namespace std;
int main() {
    int arr[100], n;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++)
            if (arr[i] == arr[j]) found = true;
        if (!found) cout << arr[i] << " ";
    }
    return 0;
}