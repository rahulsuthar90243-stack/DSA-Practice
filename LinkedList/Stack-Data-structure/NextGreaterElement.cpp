#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main(){

    vector<int> arr {6, 8, 0, 1, 3};

    vector<int> ans(arr.size(), 0);
    stack<int> s;
    
    int n = arr.size()-1;
    for(int i = n; i>=0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }
    if(s.empty()){
        ans[i] = -1;
    }else{
        ans[i] = s.top();
    }

    s.push(arr[i]);
    }

    for(int val : ans){
        cout<<val<<" ";
    }
}