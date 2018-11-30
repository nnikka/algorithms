#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int size, arr[50], i, j, temp;
	cout<<"Enter Array Size : "<<endl;
	cin>>size;

	cout<<"Enter Array Elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}

    /* 
        Time: Best:  O(n^2)
        Time: Worst: O(n^2)
    */
	cout<<"Sorting array using selection sort...\n";
    for (int i = 0; i < size; i++) 
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

	cout<<"Now the Array after sorting is :\n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}

    return 0;
}