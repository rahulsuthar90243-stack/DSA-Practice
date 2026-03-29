#include<iostream>
using namespace std;

int printIntersection(int arr1[], int size1, int arr2[], int size2) {{
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr1[i] == arr2[j]){
                cout<<"common element: " << arr1[i] << " ";
            }
        }
    }
}
   
}

int main(){
   int arr1[5] = {1, 2, 3, 4, 5};
   int arr2[5] = {4, 5, 6, 7, 8};

   for(int i = 0; i < 5; i++){
    cout<< arr1[i] << " ";
   }

   cout << endl;

   for(int i = 0; i < 5; i++){
    cout<< arr2[i] << " ";
   }

    cout << endl;

    printIntersection(arr1, 5, arr2, 5);
  

}