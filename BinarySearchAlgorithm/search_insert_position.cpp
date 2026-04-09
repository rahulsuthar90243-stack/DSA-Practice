#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int> arr, int target){
    int st = 0, end = arr.size()-1;

    while (st <= end)
    {
        int mid = st+(end-st)/2;

        if(target == arr[mid]) return mid;
        if(target < arr[mid]){
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return st;
    
}

int main(){

    vector<int> arr = {1, 3, 5, 6};
    int target = 5;
 
    cout << "index: "<< searchInsert(arr, target)<<endl;
    cout<<endl;

    target = 2;
    cout << "index: "<< searchInsert(arr, target)<<endl;
    cout<<endl;

    target = 7;
    cout << "index: "<< searchInsert(arr, target)<<endl;

}