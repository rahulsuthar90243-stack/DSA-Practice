#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<int> &arr, int n, int m, int maxPage){
    int student = 1, page = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxPage) return false;

        if(page + arr[i] <= maxPage){
            page += arr[i];
        }else{
             student++;
             page = arr[i];
        }
    }

    return student > m ? false : true;
}


int bookAllocate(vector<int> &arr, int n, int m){
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int st = 0, end = sum;
    while (st < end)
    {
        int mid = st +(end-st)/2;

        if(isValid(arr, n, m, mid)){
          ans = mid;
          end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return ans;
    
}

int main(){

    vector<int> books = {2, 1, 3, 4};
    int m = 2;
    int n = 4;

    int result = bookAllocate(books, n, m);

    cout << "Minimum possible page: "<< result <<endl;

    return 0;
}