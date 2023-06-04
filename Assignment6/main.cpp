#include <iostream>

#include "BST.h"

using namespace std;

class BST {
public:
    BSTNode *root;

    BST() {
        root = nullptr; // Initialize root to nullptr
    }

    //In Order Traversal of the tree
	void IOT(BSTNode *current) {
		if (current->left != nullptr) { //if the current's left isn't NULL, go left
			IOT(current->left);

		}

		cout << current->data << ", "; //print the current's data

		if (current->right != nullptr) { //now go down the right side
			IOT(current->right);

		}
	}

    //add function to add to the BST where less than or equal to going to the left and greater than values going to the right
    void add(int data) {
        root = add(root, data); 

    }

    BSTNode *add(BSTNode *node, int data) { //pointer to the current node and the data that needs to be inserted
        if (node == nullptr) { 
            return new BSTNode(data); //traveres tree to find where to place data
            
        }

        if (data < node->data) { //if the data is less than the current node's data, go to the left
            node->left = add(node->left, data);

        } else if (data > node->data) { //if the data is larger than place the data on the right
            node->right = add(node->right, data);
			
        }

        return node; //return the pointer of the current node
    }

    void remove(int data) { //takes 'data' for input
        root = removeNode(root, data);
    }

    BSTNode *removeNode(BSTNode *node, int data) { //pointer to the current node and the data that's going to be removed
        if (node == nullptr) { //if the node to be remomved is NULL, then return null pointer
            return nullptr;
        }

        if (data < node->data) { //if data is less than the current node's data
            node->left = removeNode(node->left, data); //the data to be removed is to the elft 

        } else if (data > node->data) {
            node->right = removeNode(node->right, data); //same thing, but on the right

        //test cases
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr; //if the current node is nullptr, the leaf was reached and didn't find the data specified so return nullptr

            } else if (node->left == nullptr) { //cases for if the node that's going to be deleted doesn't have 'children'
                BSTNode* temp = node; 
                node = node->right;
                delete temp; //delete the node and set to nullptr

            } else if (node->right == nullptr) { //same, but on the right side
                BSTNode* temp = node;
                node = node->left;
                delete temp;

            } else {
                BSTNode *minNode = findMin(node->right); //both have left and right children so find the min data on the right side
                node->data = minNode->data;
                node->right = removeNode(node->right, minNode->data); //replace current nodes data with data of the min value then remove

            }
        }

        return node;
    }

    BSTNode *findMin(BSTNode *node) { //to find the min data in the tree. takes the pointer to current node 
        while (node->left != nullptr) { //iterates the left node until it gets the min data and returns a ptr to that min data node
            node = node->left;
        }
        return node;
    }
};

int main() {
    BST tree;



    return 0;
}