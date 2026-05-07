#include<iostream>
#include<vector>
using namespace std;

void getpermutation(vector<char> &s, int idx){
    if(idx == s.size()){
        for(char val: s){
            cout<<val<<"";
        }
        cout<<endl;
        return;
    }

    for(int i = idx; i < s.size(); i++){
        swap(s[idx], s[i]);
        getpermutation(s, idx+1);
        swap(s[idx], s[i]);
    }
}

int main(){
    string str = "abc";
    vector<char> s(str.begin(), str.end());
    getpermutation(s, 0);

    return 0;
}