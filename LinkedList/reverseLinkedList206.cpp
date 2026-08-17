#include<iostream>
using namespace std;

class LinkedList{
public:    
    int val;
    LinkedList* next;

    LinkedList(int val){
        this->val = val;
        this->next = NULL;
    }
};
class List{
    LinkedList* head;

public:
    List(){
        head = NULL;
    }

    void pushBack(int val){
        LinkedList* newNode = new LinkedList(val);
        if(head == NULL){
            head = newNode;
            return;
        }else{
            LinkedList* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    LinkedList* reverseList(){
        LinkedList* prev = NULL;
        LinkedList* curr = head;
        LinkedList* next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    // print
    void printList(LinkedList* head){
        LinkedList* temp = head;
        while (temp != NULL)
        {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};



int main(){
    List l1;
    l1.pushBack(10);
    l1.pushBack(20);
    l1.pushBack(30);
    l1.pushBack(40);
    l1.pushBack(50);


    l1.printList(l1.reverseList());
}