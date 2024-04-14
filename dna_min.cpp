// PROBLEM:
/*
A non-empty string representing a DNA sequence consists only of upper-case letters A, C, G, T. These letters have integer impact factors 1, 2, 3 and 4, respectively.
Queries are given in non-empty arrays 'from' and 'to', each consisting of the same number of integers.
The I-th query requires you to find the minimal impact factor contained in the DNA sequence between positions from[I] and to[I], inclusive.
Write a function that, given a string and two arrays 'from' and 'to', returns an array specifying the consecutive answers to all queries.
*/


// SOLUTION:

#include <iostream> //cout
#include <vector> // vector
#include <string> // string

std::vector<int> dna_min(std::string &dna_, std::vector<int> &from_, std::vector<int> &to_)
{
    int s_size = dna_.size();
    int q_size = from_.size();

    std::vector<int> A_sums(s_size + 1, 0);
    std::vector<int> C_sums(s_size + 1, 0);
    std::vector<int> G_sums(s_size + 1, 0);

    for (int i = 0; i < s_size; ++i)
    {
        A_sums[i + 1] = A_sums[i] + (dna_[i] == 'A');
        C_sums[i + 1] = C_sums[i] + (dna_[i] == 'C');
        G_sums[i + 1] = G_sums[i] + (dna_[i] == 'G');
    }

    std::vector<int> ret;
    for (int i = 0; i < q_size; ++i)
    {
        int start = from_[i];
        int end = to_[i] + 1;

        if (0 < A_sums[end] - A_sums[start])
        {
            ret.push_back(1);
        }
        else if (0 < C_sums[end] - C_sums[start])
        {
            ret.push_back(2);
        }
        else if (0 < G_sums[end] - G_sums[start])
        {
            ret.push_back(3);
        } 
        else
        {
            ret.push_back(4);
        }
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::string dna1 = "CAGCCTA";
    std::vector<int> from1 = {2, 5, 0};
    std::vector<int> to1 = {4, 5, 6};
    std::vector<int> ans = dna_min(dna1, from1, to1);
    for (int num : ans)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n";
    


    return 0;
}
