#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> ans(n, vector<int>(n));
    int srow = 0, erow = n-1, scols = 0, ecols = n-1;
    int num = 1;
    while (srow <= erow && scols <= ecols)
    {
        for (int i = scols; i <= ecols; i++) {
            ans[srow][i] = num++;
        }
        srow++;

        for(int j = srow; j <= erow; j++){
        ans[j][ecols] = num++;
        }
        ecols--;

        // bottom row
        if(srow <= erow){
        for(int i = ecols; i >= scols; i--){
        ans[erow][i] = num++;
        }
        erow--;
        }

        // left column
        if(scols <= ecols){
        for(int j = erow; j >= srow; j--){
        ans[j][scols] = num++;
        }
        scols++;
        }
    }
    return ans;
    
}

int main(){
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);

    for(auto row: ans){
        for(int val: row){
            cout << val << " ";
        }
        cout<<endl;
    }

}