#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
 int n = nums.size();
 vector<int> prefix(n, 1);
 vector<int> sufix(n, 1);
 vector<int> ans(n, 1);


//Prefix
// prefix[0] = 1;
for(int i = 1; i < n; i++){
 prefix[i] = prefix[i-1] * nums[i-1];
}

// sefix
// sufix[n-1] = 1;
for(int i = n-2; i >= 0; i--){
    sufix[i] = sufix[i+1] * nums[i+1];
}

for(int i = 0; i < n; i++){
 ans[i] = prefix[i] * sufix[i];
}
return ans;
}

int main(){

    vector<int> nums = {-1,1,0,-3,3};
    vector<int> ans;

    ans = productExceptSelf(nums);
    cout<<endl;

    for(int val: ans){
        cout<<val<<" ";
    }

}

// TC = o(n), SC = o(n)