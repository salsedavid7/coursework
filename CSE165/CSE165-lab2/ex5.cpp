#include <iostream>
using namespace std;

//struct which holds data/address of next structure
struct Node {
   int data;
   struct Node *next;
};

//function to make list of number provided in argument
void makeList(struct Node *head, int num){
  int i;
  struct Node *temp = head;

  //iterate num's time loop
  for(i = 1; i <= num; i++){
    Node *node = new Node(); //creates new node
    node->next = NULL;
    node->data = i;

    //check if head is empty
    if(i == 1){    
      head->data = i;
    } else {
      
      while(temp->next != NULL){ //iterates until last node
        temp = temp->next;
      }
      temp->next = node; //copies node at the end
    }
  }
}
//displays each node's data address
void display(struct Node *head){
  struct Node *temp = head;

  //iterate throught each node
  while(temp != NULL){
    cout << temp << "\t" << temp->data << endl;
    temp = temp->next;
  }
}

int main() {
  Node* head = new Node(); //creates node
  
  makeList(head, 5); //call function to make linked list of argument number node

  cout<<"Address"<<"\t\t"<<"Data"<<endl;
  
  display(head); //call function display() to display linked list
}