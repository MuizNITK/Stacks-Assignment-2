#include <iostream>
#include <stack>
using namespace std;


bool isValid(string s) {
       stack<char> st;
       for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            } 
            else if(s[i]==')' || s[i]=='}' || s[i]==']') {
                if(st.size()==0) return false;
                else{
                    if((s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[') || (s[i]==')' && st.top()=='(')) st.pop();
                    else return false;
                }
            }
       }
       if(st.size()==0) return true;
       else return false;
    }

    int main(){
        string s1 = "()[]{}";
        string s2 = "({)}";
        bool t1 = isValid(s1);
        bool t2 = isValid(s2);
        if(t1==1) cout<<"s1 is valid"<<endl;
        else cout<<"s1 is invalid"<<endl;
        if(t2==1) cout<<"s2 is valid"<<endl;
        else cout<<"s2 is invalid"<<endl;
    }