#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int v){data=v;left=right=NULL;}
};
Node*insertNode(Node*root,int key){
    if(root==NULL){return new Node(key);}
    if(key<root->data){root->left=insertNode(root->left,key);}
    else if(key>root->data){root->right=insertNode(root->right,key);}
    return root; 
}
// (a) SEARCH: RECURSIVE
Node*searchRec(Node*root,int key){
    if(root==NULL || root->data==key){return root;}
    if(key<root->data){return searchRec(root->left,key);}
    else{return searchRec(root->right,key);}
}
// (a) SEARCH: ITERATIVE / NON-RECURSIVE
Node*searchIter(Node*root,int key){
    Node*curr=root;
    while(curr!=NULL){
        if(key==curr->data){return curr;}
        else if(key<curr->data){curr=curr->left;}
        else{curr=curr->right;}
    }
    return NULL;
}
// (b) MAXIMUM element in BST
Node*findMax(Node*root){
    if(root==NULL){return NULL;}
    while(root->right!=NULL){root=root->right;}
    return root;
}
// (c) MINIMUM element in BST
Node*findMin(Node*root){
    if(root==NULL){return NULL;}
    while(root->left!=NULL){root=root->left;}
    return root;
}
// (d) IN-ORDER SUCCESSOR of given key
Node*inorderSuccessor(Node*root,int key){
    Node*curr=root;
    Node*target=NULL;
    // find the node with value 'key'
    while(curr!=NULL){
        if(key==curr->data){target=curr;break;}
        else if(key<curr->data){curr=curr->left;}
        else{curr=curr->right;}
    }
    if(target==NULL){return NULL;} // key not found
    // case 1: right subtree exists: successor = min of right subtree
    if(target->right!=NULL){return findMin(target->right);}
    // case 2: no right subtree: go from root and track last bigger ancestor
    Node*succ=NULL;
    curr=root;
    while(curr!=NULL){
        if(key<curr->data){succ=curr;curr=curr->left;}
        else if(key>curr->data){curr=curr->right;}
        else{break;}
    }
    return succ;
}
// (e) IN-ORDER PREDECESSOR of given key
Node*inorderPredecessor(Node*root,int key){
    Node*curr=root;
    Node*target=NULL;
    // find the node with value 'key'
    while(curr!=NULL){
        if(key==curr->data){target=curr;break;}
        else if(key<curr->data){curr=curr->left;}
        else{curr=curr->right;}
    }
    if(target==NULL){return NULL;} // key not found
    // case 1: left subtree exists: predecessor = max of left subtree
    if(target->left!=NULL){return findMax(target->left);}
    // case 2: no left subtree: go from root and track last smaller ancestor
    Node*pred=NULL;
    curr=root;
    while(curr!=NULL){
        if(key>curr->data){pred=curr;curr=curr->right;}
        else if(key<curr->data){curr=curr->left;}
        else{break;}
    }
    return pred;
}
void inorder(Node*root){
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root=NULL;
    int keys[]={50,30,70,20,40,60,80};
    for(int x:keys){root=insertNode(root,x);}
    cout<<"Inorder (BST): ";inorder(root);cout<<endl;
    // (a) Search demo
    int val=40;
    cout<<"\nSearching "<<val<<"...\n";
    cout<<"Recursive: "<<(searchRec(root,val)?"Found":"Not Found")<<endl;
    cout<<"Iterative: "<<(searchIter(root,val)?"Found":"Not Found")<<endl;
    // (b) Max
    cout<<"\nMaximum element: "<<findMax(root)->data<<endl;
    // (c) Min
    cout<<"Minimum element: "<<findMin(root)->data<<endl;
    // (d) Inorder successor
    int k=50;
    Node*succ=inorderSuccessor(root,k);
    if(succ){cout<<"Inorder successor of "<<k<<" = "<<succ->data<<endl;}
    else{cout<<"No inorder successor for "<<k<<endl;}
    // (e) Inorder predecessor
    Node*pred=inorderPredecessor(root,k);
    if(pred){cout<<"Inorder predecessor of "<<k<<" = "<<pred->data<<endl;}
    else{cout<<"No inorder predecessor for "<<k<<endl;}
    return 0;
}
