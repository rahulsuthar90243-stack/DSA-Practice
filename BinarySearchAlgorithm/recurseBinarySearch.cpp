#include<iostream>
#include<vector>

using namespace std;

int recBinarySearch(vector<int> ans, int target, int st, int end){
 if(st <= end){
    int mid = st + (end-st)/2;

    if(target > ans[mid]){
        recBinarySearch(ans, target, mid+1, end);
    }else if(target < ans[mid]){
        recBinarySearch(ans, target, st, mid-1);
    }else{
        return mid;
    }
 }
  return -1;
}

int main(){
    vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int n = nums.size();
    int st = 0, end = n-1 ;
    int target = 4;

    int result = recBinarySearch(nums, target, st, end);
    if(!result){
        cout << "element is not found!";
    }else{
        cout <<"element is found: "<<nums[result] <<" in index is: " <<result <<endl;
    }

}