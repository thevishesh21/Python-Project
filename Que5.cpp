5. Merge Two Sorted Arrays
#include <iostream>
using namespace std;
int main() {
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i = 0, j = 0, k = 0;

    cout << "Enter size of first array: ";
    cin >> n1;
    cout << "Enter sorted elements of first array: ";
    for (i = 0; i < n1; i++) cin >> arr1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    cout << "Enter sorted elements of second array: ";
    for (j = 0; j < n2; j++) cin >> arr2[j];

    i = 0; j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < n1)
        merged[k++] = arr1[i++];
    while (j < n2)
        merged[k++] = arr2[j++];

    cout << "Merged Array: ";
    for (int x = 0; x < k; x++)
        cout << merged[x] << " ";

    return 0;
}