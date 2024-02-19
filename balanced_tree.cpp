// PROBLEM:
/*  
    Implement a function tthat checks if a binary tree is balanced.
    In a balanced tree, the heights of the subtrees of any node differ by at most one.
*/


// SOLUTION:

#include <cmath> // abs
#include <iostream> // size_t, cout
#include <cassert> // assert

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

int max_depth(Node* root_)
{
    if (!root_)
    {
        return 0;
    }
    int max_left = max_depth(root_->left);
    int max_right = max_depth(root_->right);
    return std::max(max_left, max_right) + 1;
}

bool is_balanced(Node *root_)
{
    if (!root_)
    {
        return true;
    }
    int l_depth = max_depth(root_->left);
    int r_depth = max_depth(root_->right);
    int max_diff_ = std::abs(l_depth - r_depth);
    return (2 > max_diff_) && is_balanced(root_->left) && is_balanced(root_->right);
}


// SIMPLE TESTS:

int main()
{
    // test 1
    Node *node1 = new Node (1);
    Node *node2 = new Node (2);
    Node *node3 = new Node (3);
    Node *node4 = new Node (4, node2, node3);
    Node *root = new Node (0, node1, node4);

    assert (true == is_balanced(root));
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete root;

    // test 2
    node1 = new Node (1);
    node2 = new Node (2, node1, nullptr);
    node3 = new Node (3, node2, nullptr);
    root = new Node (0, node3, nullptr);

    assert (false == is_balanced(root));
    delete node1;
    delete node2;
    delete node3;
    delete root;

    // test 3
    node1 = new Node (1);
    node2 = new Node (2);
    node3 = new Node (3, node1, node2);
    node4 = new Node (4);
    Node *node5 = new Node (5);
    Node *node6 = new Node (6, node4, node5);
    Node *node7 = new Node (7);
    Node *node8 = new Node (8, node6, node7);
    root = new Node (0, node3, node8);

    assert (true == is_balanced(root));
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete root;
    
    // test 4
    root = nullptr;
    assert (true == is_balanced(root));

    std::cout << "All tests passed." << std::endl;

    return 0;
}