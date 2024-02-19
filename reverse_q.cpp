// PROBLEM:
/*  
    Given a queue, write a recursive function to reverse it. 
    Standard operations allowed: 
    q.push(x) : Add item x to end of queue.
    q.pop() : Remove an item from front of queue.
    q.empty() :  Checks if a queue is empty or not.
*/


// SOLUTION:

#include <iostream> // cout
#include <queue> // queue

void reverse_q(std::queue<int>& q_)
{
    if (q_.empty())
    {
        return;
    }
    int temp = q_.front();
    q_.pop();
    reverse_q(q_);
    q_.push(temp);
}


// SIMPLE TESTS:

void push_to_q(std::vector<int>& v_, std::queue<int>& q_)
{
    size_t size = v_.size();
    for (size_t i = 0; i < size; ++i)
    {
        q_.push(v_[i]);
    }
}

void print_q(std::queue<int>& q_)
{
    size_t size = q_.size();
    if (!size)
    {
        return;
    }
    int temp;
    std::cout << "[";
    for (size_t i = 0; i < size - 1; ++i)
    {
        temp = q_.front();
        q_.pop();
        std::cout << temp << ", ";
        q_.push(temp);
    }
    temp = q_.front();
    q_.pop();
    std::cout << temp << "]" << std::endl;
    q_.push(temp);
}

int main()
{
    // test 1
    std::vector<int> v1 = {5, 24, 9, 6, 8, 4, 1, 8, 3, 6};
    std::queue<int>q1;
    push_to_q(v1, q1);
    print_q(q1);
    reverse_q(q1);
    print_q(q1);

    // test 2
    std::queue<int>q2;
    print_q(q2);
    reverse_q(q2);
    print_q(q2);
    
    std::cout << "All tests passed." << std::endl;
    
    return 0;
}