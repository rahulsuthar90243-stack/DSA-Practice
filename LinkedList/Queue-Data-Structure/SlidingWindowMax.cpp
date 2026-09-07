#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k){
    vector<int> res;
    deque<int> dq;
    // step (1) analyze 1st window
    for (int i = 0; i < k; i++){
        while (dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        
    }

    // step(2) SWM for other window
    for(int i = k; i < nums.size(); i++){
        res.push_back(nums[dq.front()]);

        // remove element from dq which are not part of window
        while(dq.size() > 0 && dq.front() <= i-k){
            dq.pop_front();
        }

        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    
    return res;
}

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
}