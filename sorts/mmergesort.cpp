#include <iostream>
#include <iostream>
#include <search.h>
#include <climits>
#include <cstdlib>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int temp1[n1];
    int temp2[n2];

    for (i = 0; i < n1; i++) {
        temp1[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        temp2[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }

    
}

void mergeSort(int arr[], int i, int j) {
    if (i < j) {
        int mid = i + (j - i) / 2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);
        merge(arr, i, mid, j);
    }
}

int main()
{
    int arr[] = {1, 3, 4, 2, 8, 7, 5, 6};

    mergeSort(arr, 0, 7);

    for (int i = 0; i < 8; i++) {
        cout << arr[i] << endl;
    }


    return 0;
}