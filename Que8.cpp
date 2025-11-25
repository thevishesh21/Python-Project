8. Matrix Class: Sum, Product, Transpose#include <iostream>
using namespace std;

class Matrix {
    int a[10][10], r, c;
public:
    void input() {
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        cout << "Enter matrix elements:
";
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];
    }

    void display() {
        cout << "Matrix:
";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    void sum(Matrix m2) {
        if (r != m2.r || c != m2.c) {
            cout << "Can't add, sizes different.
";
            return;
        }
        cout << "Sum:
";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << a[i][j] + m2.a[i][j] << " ";
            cout << endl;
        }
    }

    void product(Matrix m2) {
        if (c != m2.r) {
            cout << "Can't multiply, column not equal to row.
";
            return;
        }
        cout << "Product:
";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m2.c; j++) {
                int sum = 0;
                for (int k = 0; k < c; k++)
                    sum += a[i][k] * m2.a[k][j];
                cout << sum << " ";
            }
            cout << endl;
        }
    }

    void transpose() {
        cout << "Transpose:
";
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++)
                cout << a[j][i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2;
    int choice;
    cout << "Enter Matrix 1:
";
    m1.input();
    cout << "Enter Matrix 2:
";
    m2.input();

    do {
        cout << "
Menu:
1.Sum
2.Product
3.Transpose(Matrix 1)
4.Exit
Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: m1.sum(m2); break;
            case 2: m1.product(m2); break;
            case 3: m1.transpose(); break;
            case 4: cout << "Exit.
"; break;
            default: cout << "Invalid choice!
";
        }
    } while(choice != 4);
    return 0;
}