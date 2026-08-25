// stack implementation using vector and linked list

#include<iostream>
#include<vector>
#include<list>
using namespace std;

// class stack{
//     vector<int> v;
// public:
 
//    void push(int val){
//     v.push_back(val);
//    }
//    void pop(){
//     v.pop_back();
//    }

//    int top(){
//     return v[v.size()-1];
//    }
//    int  empty(){
//     return v.size() == 0;
//    }
// };

// stack using linked list

class stack{
 list<int> ll;
 public:
   
   void push(int val){
    ll.push_front(val);
   }
   void pop(){
    ll.pop_front();
   }

   int top(){
    return ll.front();
   }
   int  empty(){
    return ll.size() == 0;
   }
};

int main(){
stack ll;
ll.push(1);
ll.push(2);
ll.push(3);

cout<<ll.top()<<' '<<endl;

while(!ll.empty()){
    cout<<ll.top() <<" ";
    ll.pop();
}
}