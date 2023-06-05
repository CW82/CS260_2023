struct BSTNode { //struct for the data to be enterered on the tree and the left and right pointers

    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int value) { //constructor, sets data to value and left and right to null so the nodes doesn't have any kids
        data = value;
        left = nullptr;
        right = nullptr;
    }

};