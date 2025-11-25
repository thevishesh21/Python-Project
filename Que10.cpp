10. Triangle Class with Exception Handling#include <iostream>
#include <cmath>
using namespace std;

class InvalidTriangleException {};

class Triangle {
    double a, b, c;
public:
    void input() {
        cout << "Enter three sides: ";
        cin >> a >> b >> c;
    }

    void checkValid() {
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw InvalidTriangleException();
        }
    }

    double area() {
        checkValid();
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double rightAngleArea() {
        checkValid();
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            // for right triangle, area = (base * height) / 2
            // pick the two smallest sides
            double sides[3] = {a,b,c};
            sort(sides, sides+3);
            return (sides[0] * sides[1]) / 2.0;
        } else {
            cout << "Not a right triangle, calculating using Heron's formula.
";
            return area();
        }
    }
};

int main() {
    Triangle t;
    t.input();
    try {
        cout << "Area (Heron's formula) = " << t.area() << endl;
        cout << "Area (Right angle logic) = " << t.rightAngleArea() << endl;
    } catch(InvalidTriangleException&) {
        cout << "Invalid triangle: Sum of any two sides must be greater than third side.
";
    }
    return 0;
}