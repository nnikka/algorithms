#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std; 

int getSum(int BITree[], int size, int index) 
{ 
    int sum = 0; 
    index = index + 1; 
    while (index>0) 
    { 
        if (index >= size) break; 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(int BITree[], int size, int index, int val) 
{ 
    index = index + 1;   
    while (index <= size) 
    { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
}   
  
int main() 
{ 
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int MAX_SCORE = 1000001;
    int BITree[MAX_SCORE];

    for (int i = 0; i < MAX_SCORE; i++) {
        BITree[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        int score;
        cin >> score;
       
        cout << n - getSum(BITree, MAX_SCORE, MAX_SCORE - score ) << endl;

        updateBIT(BITree, MAX_SCORE, MAX_SCORE - score, 1);
    }
  
    return 0; 
} 