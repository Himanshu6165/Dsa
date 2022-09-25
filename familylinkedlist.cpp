#include <iostream>                   
using namespace std;                  
//creating class
class Node{
    public:
    string name;
    int age;
    Node*next; //for next node
    Node*prev; //for prev
    //constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};
//for inserting data;
void append(Node* &head,string name,int age){
    
    Node*temp=head;
    Node*new_node=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            }
        temp->next=new_node;
        new_node->prev=temp;
    }
}
//for inserting data at start of linked list
void insert_at_head(Node*&head,string name,int age){ 
    Node*new_node=new Node(name,age);
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}
//to display data from start of linked list
void displaystart(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;
        }
    //Printing last element without "<=>" at the end
    if(temp->next==NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}


//to display data from end of linked list
void displayend(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        }
    while(temp->next!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;
        }
    //Printing first element without "<=>" 
    if(temp->prev==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}
//to delete index from (0,n-1)
void deleteind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }        
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){
            temp=temp->next;
            }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}
//for deleting last element
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        }
    temp->prev->next=NULL;
    delete temp;
}
int main(){
    Node*head=NULL;
	int family_members;
	cout<<"Enter Number Of Family Members:";
    cin>>family_members;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=family_members;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";
		
		//To prevent getlien from taking white space caused by previous cin to take as input we ignore one cin 
        cin.ignore();
		getline(cin,name);   ///Taking input with " " in the name by using getline function 
		
		cout<<"Enter Family Member "<<i<<" Age:";
        cin>>age;
        	
		//Appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;
    //Displaying Family details
    cout<<"Doubly Linked list is shown below:"<<endl;
    cout<<endl;
    displaystart(head);
}
/*Himanshu Bansal
sid-21105050*/
/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
One way is to take the input in form of the levels of a family tree , ie, taking the input generation wise and inserting the nodes
  in the list order-wise as in an generic tree.
 other way is we can make a family graph and relate through relation
and third way is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.
*/
