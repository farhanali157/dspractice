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

int main(){


    return 0;
}