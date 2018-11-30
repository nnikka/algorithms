#include <iostream> 
#include <list> 
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std; 

pair<long long, long long> points[100010];

int main() 
{  
    ios::sync_with_stdio(false);
    
    int count;
    cin >> count;

    long long pointsOnEdge = 0;
    pair<long long, long long> prevPoint;

    for (int i = 0; i < count; i++) {
        long long x, y;
        cin >> x;
        cin >> y;
        points[i] = make_pair(x, y);
    }
    points[count] = points[0];

    long long A = 0;
    for (int i = 0; i < count; i++) {
        A += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
    }
    A = llabs(A);

    cout << A << endl;

    for (int i = 0; i < count; i++) {
        int diff;
        if (points[i].first == points[i + 1].first) {
            diff = abs(points[i].second - points[i + 1].second); 
        } else if (points[i].second == points[i + 1].second) {
            diff = abs(points[i].first - points[i + 1].first); 
        } else {
            diff = __gcd(abs(points[i].second - points[i + 1].second), abs(points[i].first - points[i + 1].first)); 
        }
        pointsOnEdge += diff;
    }

    cout << pointsOnEdge << endl;

    long long result = (A - pointsOnEdge + 2) / 2;
    cout << result << endl;

    return 0;
}