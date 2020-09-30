//Template
//Minimum element in a range
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
#define endl "\n"
#define vi vector<int>
// #define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;

/*
 Build - O(n)
 query - O(log n)
 update - O(log n)
*/
int query(int*tree ,int ss,int se,int qs,int qe,int index)
{
    //Complete Overlap
    if (ss >= qs and se <= qe)
    {
        return tree[index];
    }
    //No overlap
    if (qe < ss || qs > se)
    {
        return INT_MAX;
    }
    //Partial Overlap
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(left, right);
}

void updateNode(int*tree, int ss, int se, int i, int increment, int index) {
    //When i is out of bound
    if(i>se || i<ss) {
        return;
    }
    //Leaf Node
    if(ss==se) {
        tree[index] += increment;
        return;
    }
    //Otherwise
    int mid = (ss+se)/2;
    updateNode(tree, ss, mid, i, increment, 2*index);
    updateNode(tree, mid+1, se, i, increment, 2*index+1);

    tree[index] = min(tree[2*index+1], tree[2*index]);
}

void updateRange(int*tree, int ss, int se, int l, int r, int increment, int index) {
    //When i is out of bound
    if(l>se || r<ss) {
        return;
    }
    //Leaf Node
    if(ss==se) {
        tree[index] += increment;
        return;
    }
    //Otherwise
    int mid = (ss+se)/2;
    updateRange(tree, ss, mid, l, r, increment, 2*index);
    updateRange(tree, mid+1, se, l, r, increment, 2*index+1);

    tree[index] = min(tree[2*index+1], tree[2*index]);
    return;
}

void buildTree(int *a, int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s] ;
        return;
    }
    //Recursive Case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    int *tree = new int[4 * n + 1];
    buildTree(arr, 0, n - 1, tree, 1); //1 is the index
    //Updating a point using function
    updateRange(tree, 0, n-1, 0, 5, 10, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, n - 1, l, r, 1) << endl;
    }
    return 0;
}
