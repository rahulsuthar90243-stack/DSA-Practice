#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossible(vector<int> arr, int n, int c, int minDistance){
    int cows = 1, lastStattPos = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - lastStattPos >= minDistance){
            cows++;
            lastStattPos = arr[i];
        }
        if(cows == c) return true;
    }
    return false;
}

int getDistance(vector<int> &arr, int n, int c){
    sort(arr.begin(), arr.end());

    int st = 1, end = arr[n-1] - arr[0], ans = 0;

    for(int i = st; i < end; i++){
        cout << i;
    }

    while (st <= end)
    {
        int mid = st+(end-st)/2;
        if(isPossible(arr, n, c, mid)){
           ans = mid;
           st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;

}

int main(){
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int c = 3;

    int distance = getDistance(arr, n, c);
    cout<<"Largest Minimum Distance: " << distance <<endl;

}