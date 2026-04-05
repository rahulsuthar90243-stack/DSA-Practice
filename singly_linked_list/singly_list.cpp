#include<iostream>
#include<algorithm>
using namespace std;

struct node{
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
        newnode->data = value;
        newnode->next = NULL;

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
    cout << "Singly list is empty"<<endl;
    return;
  }else{


  while (temp != NULL)
  {
    cout <<temp->data<< " -> ";
    temp = temp->next;
  }
  cout <<"NULL"<<endl;
  }
  
}

void insert_begin(int value){
    struct node *newnode;
    
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = head;

    head = newnode;
}

void insert_end(int value){
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

}

void insert_after(int key, int value){
    struct node *newnode;
    struct node *temp = head;

    while (temp != NULL && temp->data != key){
        temp = temp->next;
    }
    
    if(temp == NULL){
        cout << "Element is not found!";
    }else{
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode -> next = temp->next;
        temp->next = newnode;
    }
}


int main(){

    create(3);
    display();

    insert_begin(5);
    display();

    insert_end(10);
    display();

    insert_after(3, 7);
    display();

}