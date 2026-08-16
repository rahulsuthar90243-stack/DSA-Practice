#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
     data = val;
     next = NULL;
    }
};

class List{         
    Node* head;
    Node* tail;

public:
    List(){
    head = tail = NULL;
    }

    void push_front(int val){      //o(1)
        Node* newNode = new Node(val);     // Create a new node with the given value (dinemically memory allocation)
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){    //o(1)
        Node* newNode = new Node(val);
        if(head == NULL){
        head = tail = newNode;
        }else{
        tail->next = newNode;
        tail = newNode;
        }
    }

    void popFront(){    //o(1)
        if(head == NULL){
            return;
        }else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back(){    //o(n)
        if(head == NULL){
            return;
        }else{
            Node* temp = head;
            while (temp->next != tail)
            {
             temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void insert(int val, int poss){   //o(n)
        if(poss < 0){
            cout<<"invalid position";
            return;
        }
        if(poss == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < poss-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key){      //o(n)
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printLL(){             //o(n)
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main(){
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    // l1.printLL();

    // l1.push_back(5);
    // l1.printLL();
    // l1.popFront();
    // l1.printLL();
    // l1.pop_back();
    // l1.printLL();
    // l1.insert(10, 1);
    l1.printLL();
    cout<<l1.search(1)<<endl;

}