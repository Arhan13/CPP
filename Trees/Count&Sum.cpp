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

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << ",";
            q.pop();
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

int count_nodes(node *root) {
    if(root==NULL) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int sum_nodes(node *root) {
    if(root==NULL) {
        return 0;
    }
    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = buildTree();
    bfs(root);
    cout<<endl;
    cout<<sum_nodes(root);
    cout<<endl;
    cout<<count_nodes(root);
    cout<<endl;
    return 0;

}

/*

ip - 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

op - 
    8,
    10,3,
    1,6,14,
    9,7,13,

    71
    9

*/