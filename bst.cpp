#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    // Helper function for searching
    bool search(Node* node, int data) {
        if (node == nullptr) {
            return false;
        }

        if (data == node->data) {
            return true;
        } else if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

    // Helper function for inorder traversal
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal: ";
    bst.inorderTraversal();

    int searchKey = 40;
    if (bst.search(searchKey)) {
        std::cout << "Element " << searchKey << " found in the BST." << std::endl;
    } else {
        std::cout << "Element " << searchKey << " not found in the BST." << std::endl;
    }

    return 0;
}
