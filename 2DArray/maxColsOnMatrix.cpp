#include<iostream>
#include<vector>
using namespace std;

int maxColumn(vector<vector<int>> &met){
  int maxColumn = INT8_MIN;
  int n = met.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
        maxColumn = max(maxColumn, met[i][j]);
    }
    
  }
  return maxColumn; 
}

int main(){
    vector<vector<int>> mat = {{1, 2, 10}, {4, 5, 6}, {7, 8, 9}};

    cout<<"Maximum Column is: "<<maxColumn(mat);
}