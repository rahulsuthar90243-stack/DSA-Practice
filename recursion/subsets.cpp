#include <iostream>
#include <vector>
using namespace std;

void getSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == nums.size())
    {
        allSubsets.push_back({ans});
        return;
    }

    // include
    ans.push_back(nums[i]);
    getSubsets(nums, ans, i + 1, allSubsets);

    // exclude
    ans.pop_back();
    getSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> allSubsets = subsets(nums);
    for (auto subset : allSubsets)
    {
        for (int val : subset)
        {
            cout << val << " ";
        }
        cout << endl;
    }   
}