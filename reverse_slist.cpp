// PROBLEM:
/*
    Given a singly-linked list and two indices, write a function that reverses the part of the linked list between those two indices.
*/


// SOLUTION:

#include <cassert> // assert
#include <iostream> // cout

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node* reverse_between(Node* head_, int left_, int right_)
{
    if (nullptr == head_)
    {
        return head_;
    }

    Node dummy(0, head_);
    Node *prev = &dummy;
    for (int i = 0; i < left_ - 1; ++i)
    {
        prev = prev->next;
    }
    Node *curr = prev->next;
    Node *temp = nullptr;

    for (int i = 0; i < right_ - left_; ++i)
    {
        temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}


// SIMPLE TESTS:

void print_slist(Node *head_)
{
    while (head_->next)
    {
        std::cout << head_->val << ", ";
        head_ = head_->next;
    }
    std::cout << head_->val << "\n";
}

int main()
{
    // test 1
    Node node5 = Node(5);
    Node node4 = Node(4, &node5);
    Node node3 = Node(3, &node4);
    Node node2 = Node(2, &node3);
    Node node1 = Node(1, &node2);
    int left1 = 2; 
    int right1 = 4;

    std::cout << "Before:" << "\n";
    print_slist(&node1);
    Node *ans1 = reverse_between(&node1, left1, right1);
    std::cout << "After:" << "\n";
    print_slist(ans1);

     // test 2
    Node node7 = Node(5);
    Node node6 = Node(3, &node7);
    int left2 = 1; 
    int right2 = 2;

    std::cout << "Before:" << "\n";
    print_slist(&node6);
    Node *ans2 = reverse_between(&node6, left2, right2);
    std::cout << "After:" << "\n";
    print_slist(ans2);
    
    // test 3
    Node node8 = Node(95);
    int left3 = 1; 
    int right3 = 1;

    std::cout << "Before:" << "\n";
    print_slist(&node8);
    Node *ans3 = reverse_between(&node8, left3, right3);
    std::cout << "After:" << "\n";
    print_slist(ans3);

    // test 4
    Node *ans4 = reverse_between(nullptr, 1, 2);
    assert (nullptr == ans4);

    std::cout << "All tests passed." << std::endl;
    return 0;
}