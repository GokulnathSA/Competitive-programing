#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s)
{
    int n = s.length();
    bool ans = true;
    stack<char> st;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='[' or s[i]=='{' or s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.top()-s[i]>2)
            {
                return false;
            }
            else 
            {
                st.pop();
            }
        }
    }

    if(!st.empty()) return false;

    return true;

}

int main()
{
    string s = "{[()]}";
    if(isValid(s))
    {
        cout<<"Valid string"<<endl;
    }
    else 
    {
        cout<<"Invalid string"<<endl;
    }
    return 0;
}