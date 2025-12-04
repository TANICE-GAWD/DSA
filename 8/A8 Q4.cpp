#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int v){data=v;left=right=NULL;}
};
Node*newNode(int v){
    return new Node(v);
}
Node*prevNode=NULL;
bool isBSTInorder(Node*root){
    if(root==NULL){return true;}
    if(!isBSTInorder(root->left)) return false;
    if(prevNode != NULL && root->data <= prevNode->data){
        return false;
    }
    prevNode=root; 
    return isBSTInorder(root->right);
}
void inorder(Node*root){
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    // Valid BST
    Node*bst=newNode(4);
    bst->left=newNode(2);
    bst->right=newNode(6);
    bst->left->left=newNode(1);
    bst->left->right=newNode(3);
    bst->right->left=newNode(5);
    bst->right->right=newNode(7);
    cout<<"Inorder of first tree: ";inorder(bst);cout<<endl;
    prevNode=NULL;
    cout<<"First tree is "<<(isBSTInorder(bst)?"a BST":"NOT a BST")<<endl<<endl;
    // Not BST
    Node*notbst=newNode(4);
    notbst->left=newNode(2);
    notbst->right=newNode(6);
    notbst->left->left=newNode(1);
    notbst->left->right=newNode(5); // violates
    notbst->right->left=newNode(3); // violates
    cout<<"Inorder of second tree: ";inorder(notbst);cout<<endl;
    prevNode=NULL;
    cout<<"Second tree is "<<(isBSTInorder(notbst)?"a BST":"NOT a BST")<<endl;
    return 0;
}
