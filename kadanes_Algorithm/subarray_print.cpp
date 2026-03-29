#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    cout<<"The subarrays are: "<<endl;

    for(int str = 0; str < n; str++){
        for(int end = str; end < n; end++){
            for(int i = str; i <= end; i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}