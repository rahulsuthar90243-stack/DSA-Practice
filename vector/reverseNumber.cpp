#include<iostream>
#include<vector>
using namespace std;

void reverseNumber(vector<int> &nums){
    // int start = 0, end = nums.size() - 1;

    // while(start < end){
    //     swap(nums[start], nums[end]);
    //     start++;
    //     end--;
    // }

    int n = nums.size();

    for(int i = 0; i < n / 2; i++){
        for(int j = n - 1; j > i; j--){
            swap(nums[j], nums[j - 1]);
        }
    }

}

int main(){

    vector<int> nums = {1, 2, 3, 4, 5};

    reverseNumber(nums);

    cout<<"Reversed vector: ";

    for(int val: nums){
        cout<< val <<" ";
    }
    cout << endl;

    return 0;
}