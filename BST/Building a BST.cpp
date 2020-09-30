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

struct node123{

};

//Binary Search Tree Class
class BST{
  int data;
  BST *left, *right;
  public:
  //Constructor
  BST();
  //Parametrized
  BST(int);
  //Insert Function
  BST* Insert(BST *, int);
  //Inorder Traversal
  void Postorder(BST *);
};

//Constructors
//Default Class Constructor
BST :: BST() : data(0), left(NULL), right(NULL){}

//Overloading
BST :: BST(int value){
    data = value;
    left = right = NULL;
}

//Insert function definition
BST* BST :: Insert(BST *root, int value){

    if(!root){
        //Insert the first node, if root is NULL
        return new BST(value);
    }
    //Insert data
    if(value > root->data){
        //In this case we wll need to insert it in the right node
        //As value to be inserted is greated than the root node data
        root->right = Insert(root->right, value);
    }
    else{
        //Insert it in the left node of the tree 
        root->left = Insert(root->left, value);
    }

    return root;
}

void BST :: Postorder(BST *root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<" "<<root->data;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;cin>>T;
    //Creating the tree using the root node
    int data;cin>>data;
    T--;
    BST b, *root = NULL;
    root = b.Insert(root, data);
    while(T--){
        cin>>data;
        b.Insert(root, data);
    }
    cout<<"Postorder Traversal:";
    b.Postorder(root);
    return 0;

}