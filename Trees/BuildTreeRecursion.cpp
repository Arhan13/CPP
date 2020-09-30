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

void printTree(node* root) {
    if(root == NULL) {
        return;
    }
    //Otherwise print root followed by left and right subtree
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    node*root = buildTree();
    printTree(root);
    return 0;
}

/*
io - 3 4 -1 6 -1 -1 5 1 -1 -1 -1
op - 3 4 6 5 1
*/