#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>

using namespace std;

bool bsearch(int arr[], int i, int j,  int k) {
    if (i == j) {
        if (arr[i] == k) {
            return true;
        } else {
            return false;
        }
    }
    int mid = (i + j) / 2;
    if (arr[mid] == k) return true; 
    if (arr[mid] < k) {
        return bsearch(arr, mid + 1, j, k);
    } else {
        return bsearch(arr, i, mid - 1, k);
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << bsearch(arr, 0, 7, 2) << endl;
    cout << bsearch(arr, 0, 7, 8) << endl;
    cout << bsearch(arr, 0, 7, 1) << endl;
    cout << bsearch(arr, 0, 7, 222) << endl;

    return 0;
}