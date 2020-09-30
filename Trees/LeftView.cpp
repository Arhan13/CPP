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

class node{
public:
    int data;
    node *left, *right;
};

node* newNode(int d){
    node* temp = new node();
    temp->data = d;
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewHelper(node* root, int level, int* max_level){
    //Base Case
    if(root==NULL){
        return;
    }
    if(*max_level<level){
        cout<<root->data<<" ";
        *max+level = level;
    }

    leftViewHelper(root->left, level+1, max_level);
    leftViewHelper(root->right, level+1, max_level);
}

void leftView(node* root){
    int max_level = 0;
    leftViewHelper(root, 1, &max_level);
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    node* root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root);
    return 0;

}