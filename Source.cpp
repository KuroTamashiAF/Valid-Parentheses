#include <iostream>
#include <map>
#include<stack>
using namespace std;

class Solution {
public:
    static void print(stack<char>);
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
        
            if ((s[i] == ']' || s[i] == ')' || s[i] == '}')&& !tack.empty())
            {
                char current = tack.top();

                if (voc[current] != s[i])
                {
                    i++;
                }
                else
                    tack.pop();
                    
            }
        }
        if (tack.empty())
            return true;
        else
            return false;
    }
};
void Solution::print(stack<char> tt)
{
    for (int i = 0; i < tt.size(); i++)
    {
        cout << tt.top() << endl;
    }
}



int main()
{
    string input = "(}{)";
    cout << Solution::isValid(input) << endl;
    return 0;
   
}