#include <iostream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        map<int, int> integersCounter;
        int result = 0;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            if (integersCounter.find(num) != integersCounter.end()) {
                integersCounter.at(num) = integersCounter.at(num) + 1;
            } else {
                integersCounter[num] = 1; 
            }

            int curResult = integersCounter.at(num);
            int up = 0;
            int down = 0;
            if (integersCounter.find(num - 1) != integersCounter.end()) {
                down = curResult + integersCounter.at(num - 1);
            }
            if (integersCounter.find(num + 1) != integersCounter.end()) {
                up = curResult + integersCounter.at(num + 1);
            }
            curResult = max(curResult, up);
            curResult = max(curResult, down);
            if (curResult > result) result = curResult;
        }
        cout << result << endl;
    }

    return 0;
}