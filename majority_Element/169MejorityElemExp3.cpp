// Boyer-Moore Voting Algorithm implementation to find the majority element in an array.
#include<iostream>
#include<vector>

using namespace std;

int mejorityElem(vector<int> &nums){
    int n = nums.size();

    int freq = 0, ans = 0;

    for(int i = 0; i < n; i++){
        if(freq == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    }

    int count = 0;
    for(int val: nums){
        if(val == ans){
            count++;
        }
    }

    if(count > n/2){
        return ans;
    }else{
        return -1;
    }
}

int main(){

    vector<int> nums = {1, 1, 2, 2, 2};

    int result = mejorityElem(nums);

    if(result == -1){
        cout << "No majority element found." << endl;
    } else {
        cout << "Majority element: " << result << endl; 
    }
}