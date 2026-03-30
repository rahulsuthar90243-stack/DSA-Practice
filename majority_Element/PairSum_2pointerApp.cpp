// 2 Pointer Approach

#include<iostream>
#include<vector>
using namespace std;

vector<int> PairSum(vector<int> nums, int target){
    vector<int> ans;
    int n = nums.size();
    int i = 0;
    int j = n -1;
    

    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if(pairSum > target){
            j--;
        }if(pairSum < target){
            i++;
        }if(pairSum == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = PairSum(nums, target);

    if(ans.size() == 0){
        cout<< "Not pair fount with the given target"<<endl;
    }else{
        cout << "Pair fount: " << ans[0] <<", " << ans[1] <<endl;
    }
}