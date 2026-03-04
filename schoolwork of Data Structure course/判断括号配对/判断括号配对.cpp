#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;
bool Is_paired(const string str) {
    int l=str.length();
    ArrayStack<char> par;    //存放括号
    for (int i=0; i <= str.length() - 1;i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            par.push(str[i]);
        }
        else if (str[i] == ')') {
            if (par.isEmpty()) return 0;
            else {
                if (par.top() == '(') par.pop();
                else return 0;
            }
            
        }

        else if (str[i] == ']') {
            if (par.isEmpty()) return 0;
            else {
                if (par.top() == '[') par.pop();
                else return 0;
            }

        }

        else if (str[i] == '}') {
            if (par.isEmpty()) return 0;
            else {
                if (par.top() == '{') par.pop();
                else return 0;
            }

        }
        
    }
    if (par.size() == 0) return 1;
    else return 0;
}
int main()
{
    string right_str = "{a1+[b2+(b3-c1)]-d3}";
    string wrong_str1 = "{a1+[b2+(b3-c1)]-d3";
    string wrong_str2 = "{a1+[b2+(b3-c1]]-d3}";
    string wrong_str3 = "{a1+[b2+(b3-c1)]-d3}}";
    if (Is_paired(right_str)) cout << "right" << endl;
    else cout << "wrong" << endl;
    if (Is_paired(wrong_str1)) cout << "right" << endl;
    else cout << "wrong" << endl; 
    if (Is_paired(wrong_str2)) cout << "right" << endl;
    else cout << "wrong" << endl;
    if (Is_paired(wrong_str3)) cout << "right" << endl;
    else cout << "wrong" << endl;
}
