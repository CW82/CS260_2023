

struct BSTNode { //struct for the data to be enterered on the tree and the left and right pointers

    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

};