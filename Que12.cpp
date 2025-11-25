12. Remove Whitespaces from File#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    char ch;
    if (!in || !out) {
        cout << "File error.
";
        return 1;
    }
    while (in.get(ch)) {
        if (ch != ' ' && ch != '\t' && ch != '
')
            out << ch;
    }
    in.close();
    out.close();
    cout << "Whitespaces removed and content copied to output.txt.
";
    return 0;
}