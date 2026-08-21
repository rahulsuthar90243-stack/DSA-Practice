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
class CircularList{
public:    
    Node*head;
    Node*tail;
    CircularList(){
        head = tail = NULL;
    }

    void insert_front(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }
    void insert_back(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void delete_head(){
        if(head == NULL) return;
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        Node* temp = head;
        
        head = head->next;
        tail->next = head;

        temp->next = NULL;
        delete temp;
    }

    void delete_tail(){
        if(head == NULL) return;
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        Node* temp = tail;
        Node* prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        
    }

    void print(){
        if(head == NULL) return;
        cout<<head->data<<"->";
        Node* temp = head->next;
    

        while (temp!=head)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }

};

int main(){

    CircularList cl;
    cl.insert_front(1);
    cl.insert_front(2);
    cl.insert_front(3);
    cl.print();
    cl.insert_back(4);
        cl.insert_back(5);
            cl.insert_back(6);
    cl.print();

    cl.delete_head();
    cl.print();
    cl.delete_tail();
    cl.print();
}