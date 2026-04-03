#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
 vector<int> ans(n, 1);

 int prefix = 1;
 for(int i = 1; i < n; i++){
    ans[i] = ans[i-1] * nums[i-1];
 }

 int sufix = 1;
 for(int i = n-2; i >= 0; i--){
 sufix *= nums[i+1];
 ans[i] *= sufix;
 }
 return ans;
}

int main(){

    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans;

    ans = productExceptSelf(nums);

    for(int val: ans){
        cout << val<<" ";
    }

}