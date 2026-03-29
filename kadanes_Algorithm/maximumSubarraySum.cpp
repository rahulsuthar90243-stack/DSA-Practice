// Brute Force Approach

#include<iostream>

using namespace std;

int main(){
    int n = 7;

    int arr[n] = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = INT8_MIN;

    for(int str = 0; str < n; str++){
        int currSum = 0;
        for(int end = str; end < n; end++){
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "Maximum subarray sum is: " << maxSum << endl;
}