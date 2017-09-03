//
// Labb 3: Rekursiv triangelutskrift
// Örebro Universitet
// Tobias Lans, Bobo Lillqvist
// https://github.com/BoboLillqvist/doa
//
#include <iostream>
#include <sstream>  // ostream
using namespace std;

void triangle(ostream& os, size_t m, size_t n);
string lineOfNChars(char c, int n);

// Main app
void app()
{
    size_t m, n;

    cout << "Recursive triangle!" << endl << endl;
    cout << "Enter min size: "; cin >> m;
    cout << "Enter mind size: "; cin >> n;
    cout << endl;

    triangle(cout, m, n);
    cout << endl;
}

int main(void)
{
    app();
    system("PAUSE");
}

// Print a triangle of chars recursively
void triangle(ostream& os, size_t m, size_t n)
{
    // Termination
    if ((m - 1) == n)
        return;

    // Print m stars
    os << lineOfNChars('*', m);

    // Recursive part
    if (m <= n)
    {
        triangle(os, (m + 1), n);
        os << lineOfNChars('*', m);
    }
}

// Returns n number of chars as a string
string lineOfNChars(char c, int n)
{
    ostringstream oss;
    for (int i = 0; i < n; i++)
    {
        oss << "*";
    }
    oss << endl;

    return oss.str();
}
