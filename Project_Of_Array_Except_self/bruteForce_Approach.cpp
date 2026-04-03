#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 1);


    for(int i = 0; i < n; i++){
        // int product = 1;
        for(int j = 0; j < n; j++){
        
            if(j != i){
            ans[i] *= nums[j];
            // product *= nums[j];
            }
            // ans[i] = product;
        }
        
    }
    return ans;
}


int main(){
    vector<int> nums = {1, 2, 3, 4};

    cout << "Origin nums element: "<<endl;
    for(int val: nums){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> ans;
    ans = productExceptSelf(nums);

    cout << "Product Except Self: "<<endl;
    for(int val: ans){
        cout<<val<<" ";
    }
}