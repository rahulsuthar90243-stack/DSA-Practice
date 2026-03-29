#include<iostream>
#include<vector>
using namespace std;

int LinearSearch(vector<int>& nums, int target){
    for(int val: nums){
        if(val == target){
            return val;
        }
    }
    return -1;
}

int main(){

    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 60;

    int result = LinearSearch(nums , target);

    if(result != -1){
        cout<< "Element found: " << result << endl;
    } else {
        cout<< "Element not found" << endl;
    }


}