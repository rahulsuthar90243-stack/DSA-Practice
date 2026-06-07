// Given a string s, partition s such that every substring of the partition is a palindrome.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalin(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllPart(string s, vector<string> &partitions, vector<vector<string>> &ans){

    if(s.size() == 0){
        ans.push_back(partitions);      
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, (i+1));   // get the current part of the string from index 0 to i
        if(isPalin(part)){
            partitions.push_back((part));
            getAllPart(s.substr(i+1), partitions, ans);  // move to the next part of the string after the current palindrome
            partitions.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllPart(s, partitions, ans);
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for(auto v: ans){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
}