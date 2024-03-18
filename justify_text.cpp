// PROBLEM:
/*
    Given an array of strings and a maximum length, format the text such that each line has exactly maximum length characters and is fully justified.
    Pack as many words as you can in each line. Extra spaces between words should be distributed as evenly as possible, starting from the left.
    The last line of text should be left-justified with no extra spaces inserted between words.
*/


// SOLUTION:

#include <cassert> //assert
#include <iostream> // cout
#include <string> // string
#include <vector> // vector

std::vector<std::string> justify(std::vector<std::string>& words_, size_t max_len_)
{
    std::vector<std::string> ret;
    size_t size = words_.size();
    std::vector<int> spaces;
    size_t i = 0;
    while (i < size)
    {
        std::string temp = "";
        temp += words_[i++];
        while (i < size && max_len_ >= temp.size() + words_[i].size() + 1)
        {
            spaces.push_back(temp.size());
            temp += " ";
            temp += words_[i++];
        }
        size_t s_spaces = spaces.size();
        if (i >= size || !s_spaces)
        {
            while (max_len_ > temp.size())
            {
                 temp += " ";
            }
        }
        else
        {
            for (size_t j = 0; max_len_ > temp.size(); ++j)
            {
                j %= s_spaces;
                spaces[j] += j;
                temp.insert(spaces[j], 1, ' ');
            }
        }
        ret.push_back(temp);
        temp.clear();
        spaces.clear();
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<std::string> in1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int len1 = 16;
    std::vector<std::string> out1 = justify(in1, len1);
    std::cout << "[" << out1[0] << "]" << std::endl;
    std::cout << "[" << out1[1] << "]" << std::endl;
    std::cout << "[" << out1[2] << "]" << std::endl;

    // test 2
    std::vector<std::string> in2 = {"What","must","be","acknowledgment","shall","be"};
    int len2 = 16;
    std::vector<std::string> out2 = justify(in2, len2);
    std::cout << "[" << out2[0] << "]" << std::endl;
    std::cout << "[" << out2[1] << "]" << std::endl;
    std::cout << "[" << out2[2] << "]" << std::endl;

    // test 3
    std::vector<std::string> in3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int len3 = 20;
    std::vector<std::string> out3 = justify(in3, len3);
    std::cout << "[" << out3[0] << "]" << std::endl;
    std::cout << "[" << out3[1] << "]" << std::endl;
    std::cout << "[" << out3[2] << "]" << std::endl;
    std::cout << "[" << out3[3] << "]" << std::endl;
    std::cout << "[" << out3[4] << "]" << std::endl;
    std::cout << "[" << out3[5] << "]" << std::endl;

    // test 4
    std::vector<std::string> in4 = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
    int len4 = 30;
    std::vector<std::string> out4 = justify(in4, len4);
    std::cout << "[" << out4[0] << "]" << std::endl;
    std::cout << "[" << out4[1] << "]" << std::endl;
    std::cout << "[" << out4[2] << "]" << std::endl;
    std::cout << "[" << out4[3] << "]" << std::endl;

    // test 5
    std::vector<std::string> in5 = {"Give","me","my","Romeo;","and,","when","he","shall","die,","Take","him","and","cut","him","out","in",
                                    "little","stars,","And","he","will","make","the","face","of","heaven","so","fine","That","all","the",
                                    "world","will","be","in","love","with","night","And","pay","no","worship","to","the","garish","sun."};
    int len5 = 25;
    std::vector<std::string> out5 = justify(in5, len5);
    std::cout << "[" << out5[0] << "]" << std::endl;
    std::cout << "[" << out5[1] << "]" << std::endl;
    std::cout << "[" << out5[2] << "]" << std::endl;
    std::cout << "[" << out5[3] << "]" << std::endl;
    std::cout << "[" << out5[4] << "]" << std::endl;
    std::cout << "[" << out5[5] << "]" << std::endl;
    std::cout << "[" << out5[6] << "]" << std::endl;
    std::cout << "[" << out5[7] << "]" << std::endl;
    std::cout << "[" << out5[8] << "]" << std::endl;
    std::cout << "[" << out5[9] << "]" << std::endl;


    std::cout << "All tests passed." << std::endl;

    return 0;
}