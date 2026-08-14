#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expVal){

    if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal){     //check if the current possition is valid or not
        return false;
    }

    if(expVal == n*n-1){          //if the expected value is equal to n*n-1, the knight has completed the tour and return true
        return true;
    }


    // 8 possible moves of a knight 
    int ans1 = isValid(grid, r-2, c-1, n, expVal+1);
    int ans2 = isValid(grid, r-2, c+1, n, expVal+1);
    int ans3 = isValid(grid, r-1, c-2, n, expVal+1);
    int ans4 = isValid(grid, r-1, c+2, n, expVal+1);
    int ans5 = isValid(grid, r+1, c-2, n, expVal+1);
    int ans6 = isValid(grid, r+1, c+2, n, expVal+1);
    int ans7 = isValid(grid, r+2, c-1, n, expVal+1);
    int ans8 = isValid(grid, r+2, c+1, n, expVal+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;     //return true if any of the 8 moves is valid
}

int main(){
   vector<vector<int>> grid = {{0,3,6}, {5,8,1}, {2,7,4}};
   isValid(grid, 0, 0, 3, 0) ? cout << "true" : cout << "false";

}


