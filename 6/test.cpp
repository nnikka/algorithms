#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;


int mainArray[501][501];
int leftArray[501][501];
int rightArray[501][501];
int leftBelowArray[501][501];
int rightBelowArray[501][501];

int main(){
    int T;
    int n,m;
    cin>>T;
   
    for(int v =0; v<T;v++){
         cin>>n; cin>>m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num;
                cin>>num;
                mainArray[i][j] = num;
                leftArray[i][j] = num;
                rightArray[i][j] = num;
                leftBelowArray[i][j] = num;
                rightBelowArray[i][j] =num;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int current = leftArray[i][j];
                int leftCurrent, topCurrent = -1;
                if(j-1 >= 0) leftCurrent = leftArray[i][j-1];
                if(i-1 >= 0) topCurrent = leftArray[i-1][j];
                if(leftCurrent != -1 && leftCurrent > current) current = leftCurrent;
                if(topCurrent != -1 && topCurrent > current) current = topCurrent;
                leftArray[i][j] = current;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=m-1; j>=0;j--){
                int current = rightArray[i][j];
                int rightCurrent = -1;
				int topCurrent = -1;
                if(j+1 <= m - 1) {
                    rightCurrent = rightArray[i][j+1];
                    cout<< i << " " << j+1 << " " << rightCurrent << endl;
                }
                if(i-1 >= 0) {
					topCurrent = rightArray[i-1][j];
					cout<< i - 1 << " " << j << " " << topCurrent << endl;
				}
                if(rightCurrent != -1 && rightCurrent > current)current = rightCurrent;
                if(topCurrent != -1 && topCurrent > current) current = topCurrent;
                rightArray[i][j] = current;
               
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0;j--){
                int current = rightBelowArray[i][j];
                int rightCurrent, belowCurrent = -1;
                if(j+1 <= m - 1) rightCurrent = rightBelowArray[i][j+1];
                if(i+1 <= n - 1) belowCurrent = rightBelowArray[i+1][j];
                if(rightCurrent != -1 && rightCurrent > current)current = rightCurrent;
                if(belowCurrent != -1 && belowCurrent > current) current = belowCurrent;
                rightBelowArray[i][j] = current;
            }
        }


        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m;j++){
                int current = leftBelowArray[i][j];
                int leftCurrent, belowCurrent = -1;
                if(j-1 >= 0) leftCurrent = leftBelowArray[i][j-1];
                if(i+1 <= n - 1) belowCurrent = leftBelowArray[i+1][j];
                if(leftCurrent != -1 && leftCurrent > current)current = leftCurrent;
                if(belowCurrent != -1 && belowCurrent > current) current = belowCurrent;
                leftBelowArray[i][j] = current;
            }
        }





        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<leftArray[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<rightArray[i][j]<<" ";
            }
            cout<<endl;
        }

        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<leftBelowArray[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<rightBelowArray[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
}