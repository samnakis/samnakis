#include <iostream>
#include <string>

using namespace std;


template<typename T>
void printArray(const T * const a, const int size)
{
    for (int x=0; x < size; x++)
        cout << a[x] << " ";
    cout << endl;
} // end printArray (templated)

// void printArray(const int * const a, const int size)
// {
//     for (int x=0; x < size; x++)
//         cout << a[x] << " ";
//     cout << endl;
// } // end printArray (int)

// void printArray(const string * const a, const int size)
// {
//     for (int x=0; x < size; x++)
//         cout << a[x] << " ";
//     cout << endl;
// } // end printArray (string)

// void printArray(const double * const a, const int size)
// {
//     for (int x=0; x < size; x++)
//         cout << a[x] << " ";
//     cout << endl;
// } // end printArray (double)

int main() {
    int b[4] = {2, 4, 6, 8};
    string c[4] = {"two", "four", "six", "eight"};

    int s = 4;

    printArray(b, s);
    printArray(c, s);

    return 0;
}