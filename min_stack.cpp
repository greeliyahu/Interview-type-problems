// PROBLEM:
/*
    Write a stack class which, in addition to push and pop, also has a function min which returns the smallest element.
    Push, pop and min should all operate in 0(1) time. 
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <stack> // stack

// T should implement operator <=
template <class T>
class MinStack
{
public:
    explicit MinStack() = default;
    ~MinStack() = default;
    MinStack(const MinStack& other_) = default;
    MinStack& operator=(const MinStack& other_) = default;

    void push(T elem_);
    T pop();
    T min();

private:
    std::stack<T> m_stack;
    std::stack<T> m_min_stack;
};

template <class T>
void MinStack<T>::push(T elem_)
{
    if (m_min_stack.empty() || elem_ <= m_min_stack.top())
    {
        m_min_stack.push(elem_);
    }
    m_stack.push(elem_);
}

template <class T>
T MinStack<T>::pop()
{
    if (m_min_stack.top() == m_stack.top())
    {
        m_min_stack.pop();
    }
    T ret = m_stack.top();
    m_stack.pop();
    return ret;
}

template <class T>
T MinStack<T>::min()
{
    return m_min_stack.top();
}


// SIMPLE TESTS:

int main()
{
    // test 1
    MinStack<int> min_stack1;
    min_stack1.push(2);
    min_stack1.push(4);
    min_stack1.push(1);
    min_stack1.push(5);

    assert (1 == min_stack1.min());
    assert (5 == min_stack1.pop());
    assert (1 == min_stack1.min());
    assert (1 == min_stack1.pop());
    assert (2 == min_stack1.min());
    assert (4 == min_stack1.pop());
    assert (2 == min_stack1.min());
    assert (2 == min_stack1.pop());

    std::cout << "All tests passed." << std::endl;

    return 0;
}