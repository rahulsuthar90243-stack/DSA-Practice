#include<iostream>
using namespace std;

bool isPowerOfTwo(int n){
    if(n < 0) return false;

    for (int i = 0; i < n; i++)
    {
        if(n % 2 != 0){
            return false;
        }
    }
    return true;
}

int main(){

    int n = 4;

    if(isPowerOfTwo(n)){
        cout<< n << " is a power of 2 (true): "<<endl;
    }else{
        cout<< n << " is not a power of 2 (false): "<<endl;
    }

}