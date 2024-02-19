// PROBLEM:
/*
    Given the root of a binary tree, determine if it is a valid binary search tree.
*/


// SOLUTION:

#include <iostream> // cout
#include <climits> // LONG_MIN, LONG_MAX

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

bool helper(Node* root_, long min_, long max_)
{
    if(!root_)
    {
        return true;
    }
    if (root_->val <= min_ || root_->val >= max_)
    {
        return false;
    }
    return helper (root_->left, min_, root_->val) && helper (root_->right, root_->val, max_);
}

bool is_valid_bst(Node* root_)
{
    return helper(root_, LONG_MIN, LONG_MAX);
}


// SIMPLE TESTS:

int main()
{
    // test 1
    Node *node1 = new Node (1);
    Node *node2 = new Node (3);
    Node *root = new Node (2, node1, node2);
    std::cout << is_valid_bst(root) << std::endl;
    delete node1;
    delete node2;
    delete root;

    // test 2
    node1 = new Node (2);
    node2 = new Node (8);
    Node *node3 = new Node (3);
    Node *node4 = new Node (4, node1, node2);
    root = new Node (6, node3, node4);
    std::cout << is_valid_bst(root) << std::endl;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete root;

    return 0;
}