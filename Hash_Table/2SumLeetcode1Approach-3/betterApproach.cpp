#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> towSum(vector<int> &arr, int tar){       //Time Complexity → O(n log n)
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)   //o(n)
    {
        ans.push_back(arr[i]);
    }
    sort(ans.begin(), ans.end());   
    int st = 0, end = ans.size();
    while (st < end)                      //o(logn)
    {
        int sum = ans[st] + ans[end];
        if(sum == tar) return {st, end};
        else if(sum < tar) st++;
        else end--;
    }
    return {};

    // vector<pair<int,int>> temp;
    // for(int i = 0; i < nums.size(); i++){
    //     temp.push_back({nums[i], i});
    // }
    //     sort(temp.begin(), temp.end());
    //     int st = 0, end = temp.size()-1;
    //     while(st < end){
    //         int sum = temp[st].first + temp[end].first;
    //         if(sum == target)  return {temp[st].second, temp[end].second};
    //         else if(sum < target) st++;
    //         else end--;
    //     }
    //   return {};
    
}


int main(){
    vector<int> nums = {2,7,11,15};
    int tar = 9;

    vector<int> ans = towSum(nums, tar);
    for(int val: ans){
        cout<<val<<" ";
    }

}