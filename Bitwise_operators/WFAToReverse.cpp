#include<iostream>
using namespace std;

int reverseDigit(int n){
    int temp = n;
    int rev = 0;

    while (temp != 0)
    {
       int digit = temp % 10;
       rev = rev * 10 + digit;
       temp /= 10;
    }
    return rev;
    
}

int main(){
    int n = 123;

    int result = reverseDigit(n);

    cout<<"Original Number: "<< n<<endl;
    cout<<"Reverse Number: "<< result;
    return 0;
}