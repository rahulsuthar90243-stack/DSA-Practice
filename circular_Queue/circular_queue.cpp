 // Circular Queue implementation in C++
 
 #include<iostream>
 using namespace std;
 #define SIZE 5

 int front = -1, rear = -1;
 int queue[SIZE];

 void enqueue(int value){
    if((rear + 1) % SIZE == front){
     cout << "Queue is overflow";
    }else{
        if(front == -1){
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
 }

 void dequeue(){
    if(front == -1){
        cout << "queue is underflow";
    }else{
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % SIZE;
        }
    }
 }

 void display(){
  if(rear == -1 || front == -1){
    cout << "Queue is Empty";
  }else{
    int i = front;
    while (1)
    {
       cout << queue[i] <<" "<<"Index is:  "<<i <<endl;
       if(i == rear){
        break;
       }
       i = (i + 1) % SIZE;
    }
    
  }
 }

 int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Queue after enqueuing 5 elements: " << endl;
    display();

    dequeue();
    dequeue();

    cout << "Queue after dequeuing 2 elements: " << endl;
    display();

    enqueue(60);
    enqueue(70);
    cout << "Queue after enqueuing 60: " << endl;
    display();


 }