#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <stdio.h>
using namespace std;
stack <char> para;
bool balanced(string);
int main(){
    cout << "Enter the expression\n";
    string expression;
    getline(cin,expression);
    if (balanced(expression))
        cout << "Balanced";
    else
        cout << "Not balanced";
    return 0;
}
bool balanced(string str){
    for (int i = 0; i < str.length(); i++){
        if (str[i]=='{'||str[i] == '(' || str[i] == '['){
            para.push(str[i]);
        }
        else if (str[i]==']'||str[i] == ')' || str[i] == '}'){
            if (!((str[i] == ']' && para.top()=='[')||(str[i] == ')' && para.top()=='(')||(str[i] == '}' && para.top()=='{'))){
                return false;
            }
            else{
                para.pop();
            }
        }
    }
        if (!para.empty())
            return false;
        return true;
}

