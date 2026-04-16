#include<iostream>
#include<vector>
using namespace std;

pair<int, int> linearSearch(vector<vector<int>>& mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == target){
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main(){
    vector<vector<int>> mat = { 
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 6;

    pair<int, int> result = linearSearch(mat, target);

    cout << "Row: " << result.first << ", Col: " << result.second;
}