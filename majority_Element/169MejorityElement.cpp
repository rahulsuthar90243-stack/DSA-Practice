// Brute Force Approach

#include<iostream>
#include<vector>
using namespace std;

int majorityElem(vector<int> &nums){
    int n = nums.size();

    for(int val: nums){
        int freq = 0;
        for(int ele: nums){
            if(ele == val){
                freq++;
            }
        }
        if(freq > n/2){
            return val;
        }
    } 
    return -1;
}

int main(){
    vector<int> nums = {3, 2, 3};

    int ans = majorityElem(nums);

    if(ans == -1){
        cout << "No majority element found." << endl;
    } else {
        cout << "Majority element: " << ans << endl;
    }

}