#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int tar){
    int m = mat.size();
    int n = mat[0].size();
    // int r = 0, c = n-1;
    // while (r<m && c>=0)
    // {
    //    if(tar == mat[r][c]){
    //     return true;
    //    }else if(tar < mat[r][c]){
    //     c--;
    //    }else{
    //     r++;
    //    }
    // }
    
    int r = m-1, c = 0;
    while (r >= 0 && c < n)
    {
       if(tar == mat[r][c]){
        return true;
       }else if(tar < mat[r][c]){
        r--;
       }else{
        c++;
       }
    }


    return false;
}

int main(){
 vector<vector<int>> mat = {{1,4,7,11,15}, {2, 5, 8, 9, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
 int target = 20;

 if(searchMatrix(mat, target)){
    cout<<"True";
 }else{
    cout<<"False";
 }
}