#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int v){data=v;left=right=NULL;}
};
// (a) INSERT (no duplicates)
Node*insertNode(Node*root,int key){
    if(root==NULL){return new Node(key);}
    if(key<root->data){root->left=insertNode(root->left,key);}
    else if(key>root->data){root->right=insertNode(root->right,key);}
    // if key==root->data do nothing (no duplicates)
    return root;
}
// (b) DELETE a node from BST
Node*findMin(Node*root){
    while(root->left!=NULL){root=root->left;}
    return root;
}
Node*deleteNode(Node*root,int key){
    if(root==NULL){return NULL;}
    if(key<root->data){root->left=deleteNode(root->left,key);}
    else if(key>root->data){root->right=deleteNode(root->right,key);}
    else{
        // node found
        if(root->left==NULL && root->right==NULL){
            delete root;return NULL;
        }else if(root->left==NULL){
            Node*temp=root->right;
            delete root;return temp;
        }else if(root->right==NULL){
            Node*temp=root->left;
            delete root;return temp;
        }else{
            Node*succ=findMin(root->right);
            root->data=succ->data;
            root->right=deleteNode(root->right,succ->data);
        }
    }
    return root;
}
// (c) MAXIMUM depth of BST
int maxDepth(Node*root){
    if(root==NULL){return 0;}
    int ld=maxDepth(root->left);
    int rd=maxDepth(root->right);
    return 1+(ld>rd?ld:rd);
}
// (d) MINIMUM depth of BST
int minDepth(Node*root){
    if(root==NULL){return 0;}
    if(root->left==NULL && root->right==NULL){return 1;}
    if(root->left==NULL){return 1+minDepth(root->right);}
    if(root->right==NULL){return 1+minDepth(root->left);}
    int ld=minDepth(root->left);
    int rd=minDepth(root->right);
    return 1+(ld<rd?ld:rd);
}
int main(){
    Node*root=NULL;
    // sample insert
    int arr[]={50,30,70,20,40,60,80};
    for(int x:arr){root=insertNode(root,x);}
    cout<<"Max depth: "<<maxDepth(root)<<endl;
    cout<<"Min depth: "<<minDepth(root)<<endl;
    cout<<"Deleting 70...\n";
    root=deleteNode(root,70);
    cout<<"Max depth: "<<maxDepth(root)<<endl;
    cout<<"Min depth: "<<minDepth(root)<<endl;
    return 0;
}
