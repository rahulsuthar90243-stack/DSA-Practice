#include<iostream>
#include<vector>
using namespace std;

int searchPeak(vector<int> &peak){
    int n = peak.size();
    int st = 1, end = n - 2;

    while (st <= end)
    {
        int mid = st +(end-st)/2;

        if(peak[mid-1] < peak[mid] && peak[mid] > peak[mid+1]){
            return mid;
        }

        if(peak[mid-1] < peak[mid]){
            st = mid +1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){

    vector<int> peaks = {3, 5, 6, 8, 9, 6};

    int result = searchPeak(peaks);

    if(result != 1){
        cout <<"Peak element is: "<< peaks[result]<< " in index: "<< result <<endl;
    }else{
        cout <<"Peask is not found: " << result<<endl;
    }

}