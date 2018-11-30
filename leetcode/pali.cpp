#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0) return true;
    if (n < 0 && n % 10 == 0) return 0;

    int sum = 0;
    int divider = 1;
    int reversed = 0;
    while ( true ) 
    {
        int k;
        bool check = false;
        if (INT_MAX / divider < 10) {
            k = n / divider;
            check = true;
        }
        else k = (((n / divider) * divider) - ((n / (divider * 10)) * divider * 10)) / divider;
        reversed = reversed * 10 + k;
        sum  += k * divider;
        divider *= 10;
        if (check || n / divider <= 0) break;
    }
    cout << reversed << endl;
    return reversed == n; 
}