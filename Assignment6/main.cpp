#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    BSTNode* root;

    void IOT(BSTNode* current) {
        if (current != nullptr) {
            IOT(current->left);
            cout << current->data << " , ";
            IOT(current->right);
        }
    }

    void add(int data) {
        root = addNode(root, data);
    }

    BSTNode* addNode(BSTNode* node, int data) {
        if (node == nullptr) {
            return new BSTNode(data);
        }

        if (data < node->data) {
            node->left = addNode(node->left, data);
        } else if (data > node->data) {
            node->right = addNode(node->right, data);
        }

        return node;
    }

    void remove(int data) {
        root = removeNode(root, data);
    }

    BSTNode* removeNode(BSTNode* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data < node->data) {
            node->left = removeNode(node->left, data);
        } else if (data > node->data) {
            node->right = removeNode(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                BSTNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                BSTNode* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = removeNode(node->right, minNode->data);
            }
        }

        return node;
    }

    BSTNode* findMin(BSTNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    BST tree;

    // Add nodes to the BST
    tree.add(40);
    tree.add(20);
    tree.add(60);
    tree.add(10);
    tree.add(30);
    tree.add(50);
    tree.add(70);

    // Print the BST using inorder traversal
    cout << "Inorder Traversal: ";
    tree.IOT(tree.root);
    cout << endl;

    // Remove a node from the BST
    tree.remove(30);

    // Print the BST after removal
    cout << "Inorder Traversal after removing 30: ";
    tree.IOT(tree.root);
    cout << endl;

    return 0;
}


/*struct Node {
	int data;
	Node *left = nullptr;
	Node *right = nullptr;

};

class BSTNode {
	public:
		Node *root;

		void add (Node *root, int data) {
			if (root == NULL) {
				return new Node (data);
			}

		}

		int remove () {
			if (root == NULL) {

			}

		}

		void IOT (BTS *current) {
				if (current->left != nullptr) {
					IOT(current->left);

				}
				cout << current->data << " , ";

				if (current->right != nullptr) {
					IOT(current->right);

				}

			}
};*/

/*int main() {
	auto *root = new BTSNode{40, nullptr, nullptr};

	BTSNode *left = new BTSNode{20, nullptr, nullptr};
	BTSNode *right = new BTSNode{60, nullptr, nullptr};

	root->left = left;
	root->right = right;

    cout << "root->value: " << root->data << endl;
    cout << "root->left->value: " << root->left->data << endl;
    cout << "root->right->value: " << root->right->data;

	return 0;

}*/