#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++){

        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

void display(int arr[], int n){
  for(int i = 0; i < n-1; i++){
    cout<< arr[i] <<" ";
  }
}

int mian(){
    int arr[] = {4, 3, 2, 1};
    int n = 4;
    bubbleSort(arr, n);
    display(arr, n);

    return 0;
}