// Count Inversions in an Array using Merge Sort

#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){   // merge two sorted subarrays and count inversions
    int i = st, j = mid+1;
    vector<int> temp;
    int invCount = 0;
    while (i <= mid && j <= end)
    {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            invCount += (mid-i+1);
        }
    }
    
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx+st] = temp[idx];
    }

    return invCount;
    
}

int mergeSort(vector<int> &arr, int st, int end){       // recursively sort the array and count inversions
    if(st < end){
        int mid = st+(end-st)/2;

        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid+1, end);

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}

int main(){
    vector<int> arr = {6, 3, 5, 2, 7};          
    int ans = mergeSort(arr, 0, arr.size()-1);

    cout<<"inversion count is: "<<ans;
}
