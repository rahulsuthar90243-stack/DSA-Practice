#include<iostream>

using namespace std;

int binarySeach(int arr[], int size, int target){
 int st = 0, end = size - 1;
 while (st <= end)
 {
    // int mid = (st + end)/2;
    int mid = st + (end - st)/2;

    if(target > arr[mid]){
        st = mid + 1;
    }else if(target < arr[mid]){
        end = mid - 1;
    }else{
        return mid;
    }
 }
 return -1;
 
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr);
    int target = 3;

    int result = binarySeach(arr, n, target);
    if(result != -1){
     cout << "Element is faund: " << arr[result]<<" in index: "<<result<< endl;
    }else{
        cout <<"element is not";
    }
}