#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class List{
    Node* head;
    Node* tamp;

public:
    List(){
        head = NULL;
        tamp = NULL;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tamp = newNode;
            return;
        }else{
            tamp->next = newNode;
            tamp = newNode;
        }
    }
    
    // int middleNode(){
    //     int count = 0;
    //     Node* temp = head;
    //     while (temp != NULL)
    //     {
    //         count++;
    //         temp = temp->next;
    //     }
        
    //     temp = head;
    //     for(int i = 0; i < count/2; i++){
    //     temp = temp->next;
    //     }
    //     return temp->val;
    // }

    int middleNode(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->val;
    }

};


int main(){
    List l1;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);
    l1.pushBack(5);
    l1.pushBack(6);


    cout<< "middle Node: " << l1.middleNode();

}