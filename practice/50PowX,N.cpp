#include<iostream>
using namespace std;

int myPow(int x, int n){
    int binform = n;
    int ans = 1;

    while(binform > 0){
       if(binform % 2 == 1){
        ans *= x;
       }

       x *= x;
       binform /= 2;
    }
    return ans;
    
}

int main(){

    double x = 2.10000;
    int n = 3;

    cout << "The value of " << x << " raised to the power of " << n << " is: " << myPow(x, n) << endl;

    return 0;

}