#include<bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *next;
}*head,*temp;

void printLL(node* head) {
    cout<<"Linked List : ";
    temp = head;
    while(temp!=0) {
        cout<<"->"<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
  int n;
  cin>>n;
//   cout<<n<<endl;
  head = 0;
  for(int i=0;i<n;i++) {
      struct node* new_node =(struct node*) malloc(sizeof(struct node));
      cin>>new_node->data;
    //   cout<<new_node->data<<endl;
      new_node->next = 0;
      if(head==0) {
          head = temp = new_node;
      }
      else {
          temp->next = new_node;
          temp = new_node;
      }
  }
  printLL(head);
  return 0;
}