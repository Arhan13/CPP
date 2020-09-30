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

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;
}

void printKthLevel(node* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k==1) {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void printAllLevals(node* root) {
    int H = height(root);
    for(int i=1;i<=H;i++) {
        printKthLevel(root, i);
        cout<<endl;
    }
    return;
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);
    node*root = buildTree();
    printAllLevals(root);
    return 0;
}

/*
io - 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
op - 
     8 
     10 3 
     1 6 14 
     9 7 13 
*/