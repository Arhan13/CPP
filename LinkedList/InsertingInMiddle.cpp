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

//Length of LL
int lengthLL(node* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length;
}

//Inserting at position p
void insertAtMiddle(node* head, int data, int p) {
    if(head==NULL || p==0) {
        insertAtHead(head, data);
    }
    else if(p>lengthLL(head)) {
        insertAtTail(head, data);
    }
    //We need to take p-1 jumps to reach position p
    else {
        int jump = 1;
        node* temp = head;
        while(jump<=p-1) {
            temp = temp->next;
            jump++;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
    return;
}

void printll(node* head) {
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
    insertAtHead(head, 2);
    insertAtMiddle(head, 3, 2);
    insertAtTail(head, 4);
    insertAtHead(head, 1);
    insertAtTail(head, 5);
    printll(head);
    return 0;

}