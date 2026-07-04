#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

    int getData(){
        return data;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    void setLeft(Node* node){
        left = node;
    }

    void setRight(Node* node){
        right = node;
    }
};

class BST{
private:
    Node* root;

public:
    BST(){
        root = nullptr;
    }

    void insert(Node* root, int val){
        if(root == nullptr){
            root = new Node(val);
        }

        if(val < root->getData()){
            insert(root->getLeft(), val);
        }
        else{
            insert(root->getRight(), val);
        }
    }

    Node* inorderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        inorderTraversal(root->getLeft());
        cout<<root->getData()<<" ";
        inorderTraversal(root->getRight());
    }

    Node* preorderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<root->getData()<<" ";
        preorderTraversal(root->getLeft());
        preorderTraversal(root->getRight());
    }

    Node* postorderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        postorderTraversal(root->getLeft());
        postorderTraversal(root->getRight());
        cout<<root->getData()<<" ";
    }

};

int main(){


    return 0;
}