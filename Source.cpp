#include <iostream>
#include <map>
#include<stack>
using namespace std;

class Solution {
public:
    static bool isValid(string s) {


        if (s[0] == ']' || s[0] == '}' || s[0] == ')'||s.size() == 1)
            return false;

        map<char, char> voc;
        voc['['] = ']';
        voc['('] = ')';
        voc['{'] = '}';
        stack<char> tack;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                tack.push(s[i]);
            }
            
            else if ((s[i] == ']' || s[i] == ')' || s[i] == '}')&& !tack.empty())
            {
                char current = tack.top();
                if (voc[current] == s[i])
                    tack.pop();
            }
        }
        if (tack.empty())
            return true;
        else
            return false;
    }
};



int main()
{
    string input = "(])";
    cout << Solution::isValid(input) << endl;
    return 0;
   
}