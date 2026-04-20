#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int tar){      //o(n*2);
    for (int i = 0; i < nums.size(); i++)     // o(n)
    {
        for (int j = i+1; j < nums.size(); j++)      // o(n)
        {
            int sum = nums[i] + nums[j];
            if(sum == tar){
                return {i, j};
            }
        }
        
    }
    return {};
}


int main(){

    vector<int> nums = {2,7,11,15};
    int tar = 9;

    vector<int> res = twoSum(nums, tar);
    for(int i : res){
        cout << i << " ";
    }

}