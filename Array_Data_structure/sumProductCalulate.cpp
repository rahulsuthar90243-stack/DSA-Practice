#include<iostream>
using namespace std;

int Sum(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}

int Product(int n){
    int product = 1;

    for(int i = 1; i <=n; i++){
        product *= i;
    }
    return product;
}

int main(){
    cout<< "Sum of numbers from 0 to 5: " << Sum(5) << endl;
    cout << "Product of numbers from 0 to 5: " << Product(5) << endl;
}