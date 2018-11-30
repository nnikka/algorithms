#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int q;
        cin >> q;
        int arr[n];
        map<int, int> mp;
        int result = 0;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            arr[j] = num;
            if (num != 0) {
                map<int, int>::iterator fnd = mp.find(num);
                if (fnd != mp.end()) {
                    fnd->second = fnd->second + 1;
                } else {
                    mp.insert(pair<int, int>(num, 1));
                }
            }
        }
        result = mp.size();
        for (int j = 0; j < q; j++) {
            int op;
            cin >> op;
            if (op == 1) {
                int p;
                int v;
                cin >> p;
                cin >> v;
                int prevNum = arr[p - 1];
                if (prevNum != 0) {
                    map<int, int>::iterator fnd = mp.find(prevNum);
                    if (fnd->second > 1) {
                        fnd->second = fnd->second - 1;
                    } else {
                        fnd->second = fnd->second - 1;
                        result--;
                    }
                }
                if (v != 0) {
                    map<int, int>::iterator fnd = mp.find(v);
                    if (fnd != mp.end()) {
                        int asd = fnd->second + 1;
                        fnd->second = fnd->second + 1;
                        if (asd == 1) result++;
                    } else {
                        mp.insert(pair<int, int>(v, 1));
                        result++;
                    }
                }
                arr[p - 1] = v;
            } else {
                cout << result << endl;
            }
        }
    }

    return 0;
}