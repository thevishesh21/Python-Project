6(a). Binary Search (Recursion)#include <iostream>
using namespace std;

int binarySearchRec(int arr[], int low, int high, int key) 
{
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearchRec(arr, low, mid - 1, key);
    else
        return binarySearchRec(arr, mid + 1, high, key);
}

int main() {
    int arr[50], n, key;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;
    int pos = binarySearchRec(arr, 0, n - 1, key);
    if (pos != -1) cout << "Element found at index " << pos << endl;
    else cout << "Element not found." << endl;
    return 0;
}




6(b). Binary Search (Without Recursion)
#include <iostream>
using namespace std;

int binarySearchIter(int arr[], int n, int key) 
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[50], n, key;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;
    int pos = binarySearchIter(arr, n, key);
    if (pos != -1) cout << "Element found at index " << pos << endl;
    else cout << "Element not found." << endl;
    return 0;
}