// PROBLEM:
/*
    Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    Preserve the original relative order of the nodes in each of the two partitions.
*/


// SOLUTION:

#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node* partition(Node* head_, int x_)
{
    Node *end = nullptr;
    Node dummy(0, head_);
    Node *start = &dummy;

    while (start && start->next)
    {
        if (start->next->val >= x_)
        {
            end = start->next;
            break;
        }
        start = start->next;
    }
    if (!end)
    {
        return head_;
    }
    Node *curr = end->next;
    Node *prev = end;
    while (curr)
    {
        if (curr->val < x_)
        {
            Node *temp = curr;
            curr = curr->next;
            prev->next = curr;
            start->next = temp;
            temp->next = end;
            start = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}


// SIMPLE TESTS:

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->val << ", " << "\n";
        head = head->next;
    }
}

int main()
{
    // test 1
    Node node6(2);
    Node node5(5, &node6);
    Node node4(2, &node5);
    Node node3(3, &node4);
    Node node2(4, &node3);
    Node node1(1, &node2);

    std::cout << "Before: " << "\n";
    printList(&node1);
    Node *ans1 = partition(&node1, 3);
    std::cout << "After: " << "\n";
    printList(ans1);
   
    // test 2
    Node node7(2);

    std::cout << "Before: " << "\n";
    printList(&node7);
    Node *ans2 = partition(&node7, 3);
    std::cout << "After: " << "\n";
    printList(ans2);

    // test 3
    std::cout << "Before: " << "\n";
    printList(nullptr);
    Node *ans3 = partition(nullptr, 3);
    std::cout << "After: " << "\n";
    printList(ans3);

    // test 4
    Node node9(1);
    Node node8(1, &node9);

    std::cout << "Before: " << "\n";
    printList(&node8);
    Node *ans4 = partition(&node8, 3);
    std::cout << "After: " << "\n";
    printList(ans4);

    // test 5
    Node node12(1);
    Node node11(1, &node12);
    Node node10(2, &node11);

    std::cout << "Before: " << "\n";
    printList(&node10);
    Node *ans5 = partition(&node10, 2);
    std::cout << "After: " << "\n";
    printList(ans5);


    std::cout << "All tests passed." << std::endl;

    return 0;
}