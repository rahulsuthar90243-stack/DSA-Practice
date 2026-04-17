#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool searchInRow(vector<vector<int>> &mat, int t, int midRow){
    int n = mat[0].size();
    int st = 0, end = n-1;

    while (st <= end)
    {
        int mid = st+(end-st)/2;
        if(t == mat[midRow][mid]){
            return true;
        }else if(t > mat[midRow][mid]){
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return false;
    
}

bool searchMatrix(vector<vector<int>> &mat, int t){
    int m = mat.size();
    int n = mat[0].size();
    int st = 0, end = m-1;
    while (st <= end)
    {
        int midRow = st+(end-st)/2;
        if(t >= mat[midRow][0] && t <= mat[midRow][n-1]){
            return searchInRow(mat, t, midRow);
        }else if(t > mat[midRow][n-1]){
            st = midRow+1;
        }else{
            end = midRow-1;
        }
    }
    return false;
    
}

int main(){

    vector<vector<int>> mat = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    int t = 4;
    cout<<searchMatrix(mat, t);

}

