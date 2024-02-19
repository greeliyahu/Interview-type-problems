// PROBLEM:
/*
    Given two binary trees, write a function that checks if they are identical.
*/


// SOLUTION:

#include <cassert> //assert
#include <iostream> // cout

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

bool are_identical(Node* root1_, Node* root2_)
{
    if (!root1_ && !root2_)
    {
        return true;
    }
    if (!root1_ || !root2_ || root1_->val != root2_->val)
    {
        return false;
    }
    return are_identical(root1_->left, root2_->left) && are_identical(root1_->right, root2_->right);
}

// SIMPLE TESTS:

int main()
{
    // test 1
    Node *node1 = new Node (1);
    Node *node2 = new Node (3);
    Node *root1 = new Node (2, node1, node2);

    Node *node3 = new Node (1);
    Node *node4 = new Node (3);
    Node *root2 = new Node (2, node3, node4);

    assert (true == are_identical(root1, root2));
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete root1;
    delete root2;

    // test 2
    node1 = new Node (1);
    root1 = new Node (2, node1, nullptr);

    node2 = new Node (1);
    node3 = new Node (3);
    root2 = new Node (2, node2, node3);

    assert (false == are_identical(root1, root2));
    delete node1;
    delete node2;
    delete node3;
    delete root1;
    delete root2;

    // test 3
    node1 = new Node (2);
    node2 = new Node (8);
    node3 = new Node (3);
    node4 = new Node (4, node1, node2);
    root1 = new Node (6, node3, node4);

    Node *node5 = new Node (2);
    Node *node6 = new Node (9);
    Node *node7 = new Node (3);
    Node *node8 = new Node (4, node5, node6);
    root2 = new Node (6, node7, node8);

    assert (false == are_identical(root1, root2));
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete root1;
    delete root2;
    
    // test 4
    root1 = nullptr;
    root2 = nullptr;
    assert (true == are_identical(root1, root2));

    std::cout << "All tests passed." << std::endl;

    return 0;
}