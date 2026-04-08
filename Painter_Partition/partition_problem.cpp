#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int minTime){
    int painter = 1, time = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > minTime) return false;
        if(time + arr[i] <= minTime){
            time += arr[i];
        }else{
            painter++;
            time = arr[i];
        }
    }
    return painter <= m ? true : false;
}

int minTimePrint(vector<int> &arr, int n, int m){
 int sum = 0, maxValue = 0, ans = -1;
 for(int val: arr){
    sum += val;
    maxValue = max(maxValue, val);
 }

 int st = maxValue, end = sum;
 while(st <= end){
    int mid = st+(end-st)/2;

    if(isPossible(arr, n, m, mid)){
        ans = mid;
        end = mid-1;
    }else{
        st = mid+1;
    }
 }
 return ans;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size();
    int m = 2;

    int result = minTimePrint(arr, n, m);
    cout<<"Minimum Time is: "<<result <<endl;

    return 0;
}