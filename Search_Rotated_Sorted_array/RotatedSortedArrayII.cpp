#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &nums, int tag){
    int n = nums.size();
    int st = 0, end = n-1;

    while(st <= end){
        int mid = st +(end-st)/2;

        if(nums[mid] == tag) {
           return mid;
        }

        if(nums[st] == nums[mid] && nums[mid] == nums[end]){
            st++;
            end--;
        }else if(nums[st] <= nums[mid]){ // left  sort
         if(nums[st] <= tag && tag <= nums[mid]){
            end = mid -1;
         }else{
            st = mid +1;
         }
        }else{
            if(nums[mid] <= tag && tag <= nums[end]){
                st = mid +1;
            }else{
                end = mid -1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 0, 1, 1, 1};
    int tag = 0;
    int result = search(nums, tag);

    cout << "element is found: " << nums[result] <<" in index: " << result<<endl;

    return 0;
}