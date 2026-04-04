#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>arr, int target){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(target == arr[i]){
            return i;
        }
    }
    return -1;
}
int main(){

    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    int target = 12;

    int result = linearSearch(arr, target);

    if(result != -1){
         cout <<"element is found: "<<arr[result] <<" in index is: " <<result <<endl;
    }else{
        cout <<"element is not found!";
    }
}