#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binSearch(vector<int>& nums, int tar, int st, int end){
    if(st <= end){
        int mid = st+(end-st)/2;
        if(nums[mid] == tar) return mid;
        else if(nums[mid] <= tar){
            return binSearch(nums, tar, mid+1, end);
        }else{
            return binSearch(nums, tar, st, mid-1);
        }
    }
    return -1;
}

int findTarget(vector<int> &nums, int tar){
//    sort(nums.begin(), nums.end());
   return binSearch(nums, tar, 0, nums.size()-1);
}

int main(){
vector<int> num = {10, 20, 30, 40, 50};
int tar = 50;
cout<<findTarget(num, tar);
}