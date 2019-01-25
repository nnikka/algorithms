#include <bits/stdc++.h> 
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("bugged.in" , "r" , stdin);

    int t;
    cin >> t;

    for (int pt = 0; pt < t; pt++) {

        int n;
        int m;
        cin >> n;
        cin >> m;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long result = 0;
        int coefs[n];
        for (int i = 0; i < n; i++) {
            coefs[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int s;
            int d;
            cin >> s;
            cin >> d;
            coefs[s - 1]--;
            coefs[d - 1]++;
            result += abs(arr[s - 1] - arr[d - 1]);
        }

        // cout << result << endl;

        bool noResult = false;
        for (int i = 0; i < n; i++) {
            // cout << coefs[i] << endl;
            if (coefs[i] != 0) {
                noResult = true;
                break;
            }
        }

        if (noResult) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }

    }
    
    return 0;
}