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
    node* left;
    node* right;
    //Constructor
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int d;
    cin>>d;
    if(d==-1) {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printTreePreorder(node* root) {
    if(root == NULL) {
        return;
    }
    //Otherwise print root followed by left and right subtree
    cout<<root->data<<" ";
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

void printTreeInorder(node* root) {
    if(root == NULL) {
        return;
    }
    //Otherwise print root followed by left and right subtree
    printTreeInorder(root->left);
    cout<<root->data<<" ";
    printTreeInorder(root->right);
}

void printTreePostorder(node* root) {
    if(root == NULL) {
        return;
    }
    //Otherwise print root followed by left and right subtree
    printTreePostorder(root->left);
    printTreePostorder(root->right);
    cout<<root->data<<" ";
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    node*root = buildTree();
    printTreePreorder(root);
    cout<<endl;
    printTreeInorder(root);
    cout<<endl;
    printTreePostorder(root);
    cout<<endl;
    return 0;
}

/*
io - 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
op - 
     8 10 1 6 9 7 3 14 13 
     1 10 9 6 7 8 3 13 14 
     1 9 7 6 10 13 14 3 8 
tree - 
     8 
     10 3 
     1 6 14 
     9 7 13 
*/