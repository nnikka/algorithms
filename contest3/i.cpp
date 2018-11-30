#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    int members[n];
    int results[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> members[i];
    }

    for (int i = 0; i < n; i++) 
    {
      if (i < m) {

      } else {
          results[i] = 0;
      }
    }
    
}