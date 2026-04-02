#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mostWater(vector<int> &heights){
    int maxWater = 0, ans = 0;
    int n = heights.size();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j< n; j++){
            int width = j - i;
            int height = min(heights[i], heights[j]);
            ans = width*height;

            maxWater = max(maxWater, ans);
        }
    }
    return maxWater;
}

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int maxWater = mostWater(height);;

    cout << "The maximum water that can be contained is: " << maxWater << endl;

    return 0;
}