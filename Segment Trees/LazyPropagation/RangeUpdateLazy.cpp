//Template for Lazy Propagation in Segment Tree
//Arhan Choudhury
#include <bits/stdc++.h>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index){

    //Before going down resolve the lazy value if it exists
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        //Non leaf node then propagate the value
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        //Claring the lazy value at the current node
        lazy[index] = 0;
    }

    //Base Case - Out of bounds
    if(ss>r or se<l){
        //out of bounds
        return;
    }

    //Another case - full overlap
    //Segment is completely overlaped by the query
    if(ss>=l and se<=r){
        //Complete Overlap
        //1)Increment the tree[index]+=inc
        //2)Lazy propagation of inc to the children

        tree[index] += inc;

        //Create a lazy value for the child nodes

        if(ss!=se){
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return;
    }

    //Recursive Case
    int mid = (ss+se)/2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2*index);
    updateRangeLazy(tree, mid+1, se, l, r, inc, 2*index+1);
    //Update the tree[index] value
    tree[index] = min(tree[2*index], tree[2*index+1]);
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index){
    //Resolve the lazy value
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index] = 0;//Clear the lazy propagation value
    }
    //Query Logic
    

    //No overlap
    if(ss>qe || se<qs){
        return INT_MAX;
    }
    //Complete Overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    //Partial Overlap
    int mid = (ss+se)/2;
    int left = queryLazy(tree, ss, mid, qs, qe, 2*index);
    int right = queryLazy(tree, mid+1, se, qs, qe, 2*index+1);

    return min(left, right);
}

void buildTree(int *a, int s, int e, int *tree, int index) {
    if(s==e) {
        tree[index] = a[s];
        return;
    }
    //Recursive Case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    int *tree = new int[4*n+1];
    buildTree(a, 0, n-1, tree, 1);

    updateRangeLazy(tree, 0, n-1, 0, 2, 10, 1);
    updateRangeLazy(tree, 0, n-1, 0, 4, 10, 1);
    cout<<"Q1 1-1 "<<queryLazy(tree, 0, n-1, 1, 1, 1)<<endl;
    updateRangeLazy(tree, 0, n-1, 3, 4, 10, 1);
    cout<<"Q2 3-5 "<<queryLazy(tree, 0, n-1, 3, 5, 1);
    return 0;

}