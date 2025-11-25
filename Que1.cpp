1. Sum of Series
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char* argv[]) 
{
    int n;
    if (argc > 1) n = atoi(argv[1]);
    else {
        cout << "Enter n: ";
        cin >> n;
    }
    double sum = 1.0;
    for (int i = 2; i <= n; i++) {
        double term = 1.0 / pow(i, i);
        if (i % 2 == 0) sum -= term;
        else sum += term;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}