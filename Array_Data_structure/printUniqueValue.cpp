#include<iostream>
using namespace std;

int uniqueValue(int arr[], int size){

    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count == 1){
            cout<< arr[i] << " ";
        }
    }
}

int main(){

    int n;

    cout<<"Enter the size of the array: ";
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<< "Unique values in the array: ";
    uniqueValue(arr, n);
}