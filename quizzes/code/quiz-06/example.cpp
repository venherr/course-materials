#include <iostream>
using std::cout;

int main() {
    // SECTION BEGIN array
    int a[] = { 3, 5, 7 };
    int b[3];
    // SECTION END array

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
        cout << a[i] << " ";

    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
        cout << b[i] << " ";

    return 0;
}
