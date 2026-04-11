#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int piv = -1, n = nums.size();
    for(int i = n-2; i >= 0; i--){   //find the Pivot
        if(nums[i] < nums[i+1]){
            piv = i;
            break;
        }
    }      
    if(piv == -1){
        reverse(nums.begin(), nums.end());   //Not found Pivot to reverse array
        return;
    }

    for(int i = n-1; i > piv; i--){   //find the right most element > Pivot(to swap element)
        if(nums[i] > nums[piv]){
        swap(nums[i], nums[piv]);
        break;
       }
    }

    int st = piv+1, end = n-1;
    while(st <= end){               //reverse (Pivot+1) to n-1
        swap(nums[st], nums[end]);
        st++;
        end--;
        }
    }
int main(){

    vector<int> nums = {1, 2, 5, 4, 3};
    nextPermutation(nums);

    for(int val: nums){                 // print nums
        cout << val <<" ";
    }

}