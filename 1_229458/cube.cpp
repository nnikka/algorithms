#include <iostream>
#include <iostream>
#include <math.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int result = k / 6;
        result = sqrt(result);
        cout << result << endl;
    }

    return 0;
}