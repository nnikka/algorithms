#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;

    string output = "";

    int CCount = 0;
    int SCount = 0;

    for(string::iterator it = input.begin(); it != input.end(); ++it) {
        if (*it == 'C') {
            SCount = 0;
            CCount ++;
            if (CCount == 3) {
                output += 'P';
                CCount = 0;
            } else {
                output += 'B';
            }
        } else {
            CCount = 0;
            SCount ++;
            if (SCount == 3) {
                output += 'T';
                SCount = 0;
            } else {
                output += 'D';
            }
        }
    }

    cout << output << endl;

    return 0;
}