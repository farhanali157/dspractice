#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    int getData() const { return data; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    void setData(int val) { data = val; }
    void setLeft(Node* node) { left = node; }
    void setRight(Node* node) { right = node; }
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->getData()) {
            node->setLeft(insertRec(node->getLeft(), val));
        } else if (val > node->getData()) {
            node->setRight(insertRec(node->getRight(), val));
        }

        return node;
    }

    void inorderRec(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorderRec(node->getLeft());
        cout << node->getData() << " ";
        inorderRec(node->getRight());
    }

    void preorderRec(Node* node) const {
        if (node == nullptr) {
            return;
        }
        cout << node->getData() << " ";
        preorderRec(node->getLeft());
        preorderRec(node->getRight());
    }

    void postorderRec(Node* node) const {
        if (node == nullptr) {
            return;
        }
        postorderRec(node->getLeft());
        postorderRec(node->getRight());
        cout << node->getData() << " ";
    }

    Node* minValueNode(Node* node) const {
        Node* current = node;
        while (current != nullptr && current->getLeft() != nullptr) {
            current = current->getLeft();
        }
        return current;
    }

    Node* deleteRec(Node* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->getData()) {
            node->setLeft(deleteRec(node->getLeft(), val));
        } else if (val > node->getData()) {
            node->setRight(deleteRec(node->getRight(), val));
        } else {
            if (node->getLeft() == nullptr) {
                Node* temp = node->getRight();
                delete node;
                return temp;
            } else if (node->getRight() == nullptr) {
                Node* temp = node->getLeft();
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->getRight());
            node->setData(temp->getData());
            node->setRight(deleteRec(node->getRight(), temp->getData()));
        }

        return node;
    }

    void destroyTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroyTree(root); }

    void insert(int val) { root = insertRec(root, val); }
    void inorderTraversal() const { inorderRec(root); }
    void preorderTraversal() const { preorderRec(root); }
    void postorderTraversal() const { postorderRec(root); }
    void deleteNode(int val) { root = deleteRec(root, val); }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorderTraversal();
    cout << endl;

    cout << "Preorder traversal: ";
    bst.preorderTraversal();
    cout << endl;

    cout << "Postorder traversal: ";
    bst.postorderTraversal();
    cout << endl;

    return 0;
}