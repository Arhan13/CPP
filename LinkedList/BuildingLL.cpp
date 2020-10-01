//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll; 
using namespace std;

class node {
public:
    int data;
    node*next;
    //Constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

// class LinkedList {
//     node* head;
//     node* tail;
// public: 
//     LinkedList() {
//         head = NULL;
//         tail = NULL;
//     }
//     void insert() {

//     }
// };

//Passing a pointer variable as a refrence
void insertAtHead (node*&head, int data) {
    node* n = new node(data);
    n->next = head; //Assigning the next to the new node
    head = n; //Updating the head
}

void insertAtTail(node*head, int data) {
    if(head==NULL) {
        head = new node(data);
    }
    else {
        node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = new node(data);
    }
}

void printLL(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    node* head = NULL;
    insertAtHead(head, 5); //inserts new element at starting if list
    insertAtHead(head, 4);
    insertAtTail(head, 6);
    printLL(head);
    return 0;

}
