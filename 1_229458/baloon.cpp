#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int result = 0;
        for (int j = 0; j < k; j++) {
            int p;
            cin >> p;
            if (p > 0) result++;
        }
        cout << result << endl;
    }

    return 0;
}