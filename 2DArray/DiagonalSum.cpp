#include <iostream>
#include <vector>
using namespace std;

int diagonalSul(int mat[][4], int n){
    int sum = 0;
    // for (int i = 0; i < n; i++)   //TC = 0(n * n)
    // {
    //    for (int j = 0; j < n; j++)
    //    {
    //     if(i == j){
    //         sum += mat[i][j];
    //     }
    //     else if(j == n-i-1){
    //         sum += mat[i][j];
    //     }
    //    }
    // }

    // PD = j = i;
    // SD = j = n-i-1

    for (int i = 0; i < n; i++)  // TC = o(n)
    {
       sum += mat[i][i];
       if(i != n-i-1){
        sum += mat[i][n-i-1];
       }
    }
    
    return sum;
}

int main(){
    int matrix = {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}, {13, 14, 15, 16}};
    int = 4;
    cout<<diagonalSul(matrix, n);

    // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int r = mat.size(); //rows
    // int c = mat[0].size();  //column;

    // cout << mat[0][0]; // output: 1

}