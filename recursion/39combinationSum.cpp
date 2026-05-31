#include<iostream>
#include<vector>
using namespace std;

set<vector<int>> st;  // to store unique combinations
void combSum(vector<int> &arr, int idx, vector<int> &combin, vector<vector<int>> &ans, int tar){
    if(idx == arr.size() || tar < 0){   
        return; 
    }

    if(tar == 0){
        if(st.find(combin) == st.end()){
            ans.push_back({combin});
            st.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);                      // pick the current element
    combSum(arr, idx+1, combin, ans, tar-arr[idx]);  // single move to the next element and reduce the target by the current element
    combSum(arr, idx, combin, ans, tar-arr[idx]);    // multiple
    combin.pop_back();                               // backtrack to explore other combinations
    combSum(arr, idx+1, combin, ans, tar);           // skip the current element
}

vector<vector<int>> combinationSum(vector<int> &arr, int tar){
    vector<vector<int>> ans;
    vector<int> combin;
    combSum(arr, 0, combin, ans, tar);
    return ans;
}


int main(){
    vector<int> arr = {2,3,5};
    int tar = 7;
    vector<vector<int>> ans = combinationSum(arr, tar);
    for(auto v: ans){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

}