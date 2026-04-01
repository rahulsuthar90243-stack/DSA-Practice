#include<iostream>
#include<algorithm>
using namespace std;

int stock(int prices[], int n){
    int bestBuy = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++){
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main(){
    int prices[7] = {7, 1, 5, 3, 6, 4};

    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "The maximum profit is: " << stock(prices, n) << endl;

}