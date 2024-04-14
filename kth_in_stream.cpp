// PROBLEM:
/*
    Given an infinite stream of integers, find the k'th largest element at any point in time.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <string> // string
#include <queue> // priority_queue

std::vector<std::string> kth_largest(std::vector<int>& stream_, size_t k_)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::vector<std::string> ret;
    size_t i = 0;
    for (; i < k_-1; ++i)
    {
        ret.push_back("_");
        pq.push(stream_[i]);
    }
    size_t size = stream_.size();
    pq.push(stream_[i++]);
    for (; i < size; ++i)
    {
        ret.push_back(std::to_string(pq.top()));
        if (stream_[i] > pq.top())
        {
            pq.pop();
            pq.push(stream_[i]);
        }
    }
    ret.push_back(std::to_string(pq.top()));
    return ret;
}


// SIMPLE TESTS:

void print_vector(std::vector<std::string>& vec_)
{
    for (std::string str : vec_)
    {
        std::cout << str << ", ";
    }
    std::cout << "\n";
}

int main()
{
    // test 1
    std::vector<int> stream1 = {10, 20, 11, 70, 50, 40, 100, 5};
    int k1 = 3;
    std::vector<std::string> ans1 = kth_largest(stream1, k1);
    print_vector(ans1);


    std::cout << "All tests passed." << std::endl;

    return 0;
}