#include<iostream>
using namespace std;

struct  node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n){
    struct node *newnode, *temp;
    
    for(int i = 0; i < n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        int value;
        cout<<"Enter value: ";
        cin>>value;

        newnode ->data = value;
        newnode ->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
    }

}

void display(){
    struct node *temp = head;
    if(head == NULL){
        cout<<"singly is empty"<<endl;
        return;
    }else{

    while (temp != NULL)
    {
        cout <<temp->data<<"-> ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
     
    }
}

int main(){

    create(3);
    display();

}