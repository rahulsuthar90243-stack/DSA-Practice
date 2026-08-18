#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class ListNode{
public:
    Node *head;
    ListNode(){   //constructor to initialize head pointer
        head = NULL;
    }
    void addNode(int n)              //creates a linked list with n nodes by taking input from the user
    {
        Node *temp;
        for (int i = 0; i < n; i++)
        {
            int val;
            cout << "Enter Value: ";
            cin >> val;

            Node *newNode = new Node(val);
            newNode->next = NULL;
            if (head == NULL)
            {
                head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }
    
    void createCycle(int pos){        //creates a cycle in the linked list at the given position
        if(head == NULL || pos < 0){
            return;
        }

        Node* temp = head;
        Node* cycleNode = NULL;
        int index = 0;

        while(temp->next != NULL){
            if(index == pos){
             cycleNode = temp;
            }

            temp = temp->next;
            index++;
        }

        temp->next = cycleNode;
    }
    int checkCycle(){            //checks if there is a cycle in the linked list using Floyd's Cycle Detection Algotrithm
     Node* slow = head;
     Node* fast = head;
     while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
     }
     return 0;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int
main(){
    ListNode l1;
    l1.addNode(5);
    l1.print();
    l1.createCycle(2);
    cout<<l1.checkCycle()<<endl;
}