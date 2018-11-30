#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000001
#define MAX_ANSWER 1000000007

unsigned long long f[MAX + 1];
unsigned long long g[MAX + 1];

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    f[0] = 1;
    f[1] = 0;
    g[0] = 0;
    g[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 1) {
            g[i] = (((f[i - 1] + g[i - 2]) % MAX_ANSWER) + MAX_ANSWER) % MAX_ANSWER;
        } else {
            f[i] = (((f[i - 2] + 2 * g[i - 1]) % MAX_ANSWER) + MAX_ANSWER) % MAX_ANSWER;
            g[i] = (((f[i - 1] + g[i - 2]) % MAX_ANSWER) + MAX_ANSWER) % MAX_ANSWER;
        }
    }

    cout << f[n] << endl; 

    return 0;
}