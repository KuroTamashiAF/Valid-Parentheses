#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    static bool isValid(string s) {

        if (s[0] == ']' || s[0] == '}' || s[0] == ')')
            return false;
        int result = 0;
        map<char, int> vocab;
        vocab['['] = 3;
        vocab['('] = 2;
        vocab['{'] = 1;
        vocab[']'] = -3;
        vocab[')'] = -2;
        vocab['}'] = -1;
        for (int i = 0; i < s.size(); i++)
        {
            result += vocab[s[i]];
        }
        if (result == 0)
            return true;
        else
            return false;


    }
};



int main()
{
    string input = "(]";
    cout << Solution::isValid(input) << endl;
    return 0;
   
}