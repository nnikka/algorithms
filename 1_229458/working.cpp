#include <iostream>
#include <iostream>
#include <math.h> 
#include <string>
#include <cstdlib> 
using namespace std;

struct Time {
    int hours;
    int minutes;
};

int main()
{
    int counter = 0;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int m;
        cin >> m;

        int minutes = 0;
        for (int j = 0; j < n; j++) {
            string start;
            string end;
            cin >> start;
            cin >> end;

            int starthour;
            int startminute;
            int endhour;
            int endminute;

            if (start.substr(0, 1) == "0")  starthour = atoi(start.substr(1, 2).c_str());
            else starthour = atoi(start.substr(0, 2).c_str());

            if (start.substr(3, 4) == "0")  startminute = atoi(start.substr(4,5).c_str());
            else startminute = atoi(start.substr(3,5).c_str());

            if (end.substr(0, 1) == "0")  endhour = atoi(end.substr(1, 2).c_str());
            else endhour = atoi(end.substr(0, 2).c_str());

            if (end.substr(3, 4) == "0")  endminute = atoi(end.substr(4,5).c_str());
            else endminute = atoi(end.substr(3,5).c_str());

            minutes = minutes + (endhour - starthour) * 60;
            minutes = minutes + endminute - startminute;
         
        }
        if (minutes >= m * 60) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}