#include <iostream>                  //Name-Himanshu Bansal
using namespace std;                 //Sid-21105050
//Creating Node class                //Branch-Ece
class Node{
    public:
    int data;
    Node*next;
    //constructor
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
//Function to insert a node at end on linked list
void append(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){
        head=new_node;new_node->next=head;return;
        }
    while(temp->next!=head){
        temp=temp->next;
        }   
    temp->next=new_node;
    new_node->next=head;
}

void print(Node*&head){
    Node*temp=head;
    do{
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    while(temp!=head);
}


int main(){
    Node*head=NULL;
    append(head,1);
    append(head,2);
    append(head,3);
    print(head);
    return 0;
}

/*Q1. While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?
Ans. Since tail node(last element) of a circularlinked list stores the address of head node(first element), therefore while traversing the linkedlist using while or for loop if currentnodes points to the headnode this means we have reached the first element.
Q2. What are the practical applications of a circular linked list? (Try to find applications in your respective fields)
Ans. Applications:
•	Multiple running applications can be placed in a circular linked list on an operating system. The OS keeps on iterating over these applications.
•	Implementation of Advanced data structures like Fibonacci Heap.
•	The browser cache which allows you to hit the BACK button.
•	Undo functionality in Photoshop or Word.
•	Circular linked list used Most recent list (MRU LIST)
•	Round Robin scheduling technique in games.
•	To repeat the playlist during audio video streaming.
*/
