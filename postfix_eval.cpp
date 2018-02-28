#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <stdio.h>
using namespace std;
stack <int> eval;
int postfix(string userInput);
int main(){
    cout << "Enter the expression with operands and operators separated by space";
    string expression;
    getline(cin,expression);
    cout << postfix(expression);
    }
int postfix(string userInput){
    for (int i = 0; i < userInput.length(); i++){   //traversing the string entered by user
        char t = userInput[i];
        if (userInput[i]==' '){
            continue; //if a space is encountered it proceeds to next operator or operand
        }
        if ((int)t>=48 && (int)t<=57){
                string operand = "";
                while((int)userInput[i] >= 48 && (int)userInput[i] <= 57){//if operator is encountered
                    operand += userInput[i];
                    //cout << operand;
                    i++;
                }
            eval.push(atoi(operand.c_str()));
            //cout << atoi(operand.c_str()) << " ";
            continue;
        }
        else if (userInput[i]=='+'|| userInput[i]=='-'|| userInput[i] =='/'|| userInput[i] =='*'){//operator is encountered
            int op1 = eval.top();
            eval.pop();
            int op2 = eval.top();
            eval.pop();
            if (t == '+'){
                eval.push(op1 + op2);
            }
            if (t  == '-'){
                eval.push(op2 - op1);
            }
            if (t == '/'){
                eval.push(op2 / op1);
            }
            if (t == '*'){
                eval.push(op1 * op2);
            }
        }
    }
    return eval.top();
}
