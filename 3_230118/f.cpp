#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
using namespace std; 

#define maxn 1600
#define maxm 1600
#define maxk 76000

int mat[maxm][maxn];

bool bpm(int u, bool seen[], int matchR[], int matchRdvaRev[]) { 
    for (int v = 0; v < maxn; v++) 
    { 
        if (mat[u][v] && !seen[v]) 
        { 
            seen[v] = true;  
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR, matchRdvaRev)) 
            { 
                matchR[v] = u; 
                matchRdvaRev[u] = v;
                return true; 
            } 
        } 
    } 
    return false; 
} 

int maxBPM(int matchR[], int matchRdvaRev[]) {  
  
    int result = 0;  
    for (int u = 0; u < maxm; u++) 
    { 
        bool seen[maxn]; 
        memset(seen, 0, sizeof(seen)); 
  
        if (bpm(u, seen, matchR, matchRdvaRev)) 
            result++; 
    } 

    return result; 
} 

int main() {
    ios::sync_with_stdio(false);
    int m, n, k;
    cin >> m;
    cin >> n;
    cin >> k;

    map<int, int> mapi;

    for (int i = 0; i < k; i++) {
        int x;
        int y;
        cin >> x;
        cin >> y;
        mat[x - 1][y - 1] = 1;
        mapi[x - 1] += 1;
    } 

    int original = 0;

    int matchRdva[maxn]; 
    memset(matchRdva, -1, sizeof(matchRdva));

    int matchRdvaRev[maxm];
    memset(matchRdvaRev, -1, sizeof(matchRdvaRev));

    original = maxBPM(matchRdva, matchRdvaRev);


    int addon = 0;
    int addons[m];
    memset(addons, 0, sizeof(addons));
    for (int i = 0; i < n; i++) {
        int socket = matchRdva[i];
        if (socket != -1) {
            int wantsHere = 0;
            for (int j = 0; j < n; j++) {
                if (mat[socket][j] > 0) {
                    if (matchRdva[j] == -1) {
                        wantsHere++;
                    }
                }
            }
            addons[socket] = wantsHere;
            addon = max(addon, wantsHere);
            addon = min(addon, 2);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (addons[i] && addons[j]) {
                if (mat[i][matchRdvaRev[j]] || mat[j][matchRdvaRev[i]]) {
                    cout << original + 2 << endl;
                    return 0;
                }
            }
        }
    }

    cout << original + addon << endl;

    return 0;
}

/*
  
3 6 8
1 1
1 2
1 3
2 3
2 4
3 4
3 5
3 6

*/
