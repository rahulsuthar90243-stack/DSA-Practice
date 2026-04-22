// 3Sum Leetocde 15 Appreach 3 Better Approach
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
    int n = nums.size();
    set<vector<int>> uniqueTriplets;
    
    for (int i = 0; i < n; i++)
    {
        set<int>s;
        int tar = -nums[i];
       for (int j = i+1; j < n; j++)
       {
        int third = tar - nums[j];

        if(s.find(third) != s.end()){
            vector<int> trip = {nums[i], nums[j], third};
            sort(trip.begin(), trip.end());
            uniqueTriplets.insert(trip);
        }
        s.insert(nums[j]);
       }
       
    }
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
    
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}