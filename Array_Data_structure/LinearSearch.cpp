#include<iostream>
using namespace std;

int LinearSearch(int arr[], int size){
    int start = 0, end = size -1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};

    LinearSearch(arr, 5);

    for(int i = 0; i < 5; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;

}