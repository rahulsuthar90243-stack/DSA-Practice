#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

int create(int n){
    struct node *newnode, *temp,

    for (int i = 0; i < n; i++)
    {
      cout<<"Enter value: ";
      cin>>value;

      newnode = (struct node*)malloc(sizeof(struct node))
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

int changeValue(int key, int value){
    struct node *temp = head;
    if(head == NULL){
        cout<<"Linked List is Empty";
        return;
    }


}

int main(){
    int n;
    cout<<"Enter size of Linked List: ";
    cin>>n;
    create(n);

    

}