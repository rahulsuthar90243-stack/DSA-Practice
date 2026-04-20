#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &arr, int tar){   //o(n)
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)    //o(n)
    {
        int first = arr[i];
        int sec = tar - first;

        if(m.find(sec) != m.end()){    //o(1)
            ans.push_back(m[sec]);
            ans.push_back(i);
            break;
        }
        m[first] = i;
    }
    // for(auto val = m.begin(); val != m.end(); val++){
    //     cout<<val->first<<" " <<val->second <<endl;
    // }

    // for(auto val: m){
    //     cout<<val.first<<" "<<val.second<<endl;
    // }

    return ans;
}


int main(){
  vector<int> nums = {5, 2, 11, 7, 15};
  int target = 9;
  vector<int> ans = twoSum(nums, target);

  for(int val: ans){
    cout<<val<<" ";
  }

}