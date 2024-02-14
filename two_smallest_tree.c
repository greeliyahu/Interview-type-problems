// PROBLEM:
/*
    Find and return the two smallest memebers in a binary tree of integers.
*/


// SOLUTION:

#include <stdio.h> // printf
#include <limits.h> // INT_MAX

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct int_pair
{
    int smallest;
    int s_smallest;
} pair;


void FindTwo(Node *root_, pair *min_)
{
    if (!root_)
    {
        return;
    }
    
    if (min_->smallest > root_->val)
    {
        min_->s_smallest = min_->smallest;
        min_->smallest = root_->val;
    }
    else if (min_->s_smallest > root_->val)
    {
        min_->s_smallest = root_->val;
    }
    
    FindTwo(root_->left, min_);
    FindTwo(root_->right, min_);
}

pair FindTwoSmallest(Node *root_)
{
    pair ret = {INT_MAX, INT_MAX};
    FindTwo(root_, &ret);
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    Node left = {2, NULL, NULL};
    Node right = {1, NULL, NULL};
    Node root1 = {4, &left, &right};
    pair smallest_two1 = FindTwoSmallest(&root1);
    printf("Smallest pair is: %d, %d\n", smallest_two1.smallest, smallest_two1.s_smallest);

    // test 2
    Node node3 = {12, NULL, NULL};
    Node node4 = {31, NULL, NULL};
    Node node1 = {6, &node3, &node4};
    Node node2 = {7, NULL, NULL};
    Node root2 = {2, &node1, &node2};
    pair smallest_two2 = FindTwoSmallest(&root2);
    printf("Smallest pair is: %d, %d\n", smallest_two2.smallest, smallest_two2.s_smallest);

    return 0;
}