#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mostWater(vector<int> height){
    int maxWater = 0, ans = 0;
    int n = height.size();
    int left = 0, right = n -1;
    
    while (left < right)
    {
        int width = right - left;
        int h = min(height[left], height[right]);
        ans = width*h;

        maxWater = max(maxWater, ans);

        height[left] < height[right] ? left++ : right--;
    }
    return maxWater;
    
}

int main(){

    vector<int> height = {2, 4, 5, 3, 2};

    int maxWater = mostWater(height);

    cout << "The maximum water that can be contained is: " << maxWater << endl;

}
