#include<iostream>
using namespace std;

int swapMaxMin(int arr[], int size){
    int maxIndex = 0, minIndex = 0;

    int max = INT8_MIN, min = INT8_MAX;

    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }

    swap(arr[maxIndex], arr[minIndex]);
    return 0;
}


int main(){
    int arr[5] = {10, 4, 30, 3, 7};

    swapMaxMin(arr, 5);;

    cout<< "Array after swapping max and min: ";
    for(int i =0; i < 5; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}