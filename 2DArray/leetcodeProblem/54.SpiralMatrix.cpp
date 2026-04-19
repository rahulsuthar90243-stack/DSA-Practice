#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();
    int srow = 0, erow = m-1, scols = 0, ecols = n-1;
    vector<int> ans;

    while (srow <= erow && scols <= ecols)
    {
        for (int i = srow; i <= ecols; i++)   //top
        {
            ans.push_back(mat[srow][i]);
        }
        
        for (int i = srow+1; i <= erow; i++)    //right
        {
            ans.push_back(mat[i][ecols]);
        }

        for (int i = ecols-1; i >= scols; i--)    //Button
        {
            if(srow == erow) break;
            ans.push_back(mat[erow][i]);
        }

        for (int i = erow-1; i >= srow+1; i--)    //left
        {
            if(scols == ecols) break;
            ans.push_back(mat[i][scols]);
        }

        srow++, erow--;
        scols++, ecols--;
    }
    return ans;

}

int main(){

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> ans = spiralOrder(mat);

    for(int val: ans){
        cout<<val<<" ";
    }
}


// TC = o(m * n)