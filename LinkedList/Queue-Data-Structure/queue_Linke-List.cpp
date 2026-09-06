#include<iostream>
#include<queue>
using namespace std;


// class Node {
// public: 
//   int data;
//   Node* next;

//   Node(int val){
//   data = val;
//   next = NULL;
//   }
// };

// class Queue{
//     Node* head;
//     Node* tail;

// public:
//     Queue(){
//     head = tail = NULL;
//     }


//     void push(int val){

//         Node* newNode = new Node(val);
    
//         if(empty()){
//             head = tail = newNode;
//         }else{
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop(){
//         if(empty()){
//            cout<<" Linke List is Empty";
//            return;
//         }else{
//             Node* temp = head;
//             head = head->next;
//             if(head == NULL){
//                 tail = NULL;
//             }
//             temp->next = NULL;
//             delete(temp);
//         }
//     }

//     int front(){
//        if(empty()){
//         cout<<"Linke List is Empty";
//         return -1;
//        }else{
//         return head->data;
//        }
//     }

//     bool empty(){
//         return head == NULL;
//     }
// };



// C++ STL create queue

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
       cout << q.front() << " ";
       q.pop();
    }

    return 0;
} 