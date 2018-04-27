#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;
stack <char> operators;
bool IsOperator(char);
string infix2postfix(string userInput);
int operatorPrecedence(char );
int main(){
    cout << "Enter the expression with operands and operators separated by space\n";
    int option;
    string expression;
    getline(cin,expression);
    cout << infix2postfix(expression);
    return 0;
    }
int operatorPrecedence(char oper){
    if (oper == '/' || oper == '*')
        return 2;
    if (oper == '+' || oper == '-')
        return 1;
    if (oper =='(')
        return -1;
    }
string infix2postfix(string userInput){
    string postfix = "";
    //cout << operators.empty();
   for (int i = 0; i < userInput.length(); i++){   //traversing the string entered by user
        if (userInput[i]==' '){
            continue; //if a space is encountered it proceeds to next operator or operand
        }
        if ((int)userInput[i]>=48 && (int)userInput[i]<=57){ //digit is encountered
                string operand = "";
                while((int)userInput[i] >= 48 && (int)userInput[i] <= 57){//if operator is encountered

                    operand += userInput[i];
                    //cout << operand;
                    i++;
                }
            postfix += operand + " ";
            continue;
            //cout << atoi(operand.c_str()) << " ";
        }
        else if (IsOperator(userInput[i])){//operator is encountered
            while(!operators.empty() && operators.top() != '(' && operatorPrecedence(operators.top())>=operatorPrecedence(userInput[i]))
			{
				postfix += operators.top();
				operators.pop();
			}
            operators.push(userInput[i]);
        }
        else if(userInput[i] == '('){
            operators.push('(');
        }
        else if(userInput[i] == ')'){
            while(!operators.empty()) {
                if (operators.top()=='('){
                    operators.pop();
                    break;
                }
				postfix += operators.top();
				operators.pop();
			}
        }
    }
    //cout << operators.empty();
    while(!operators.empty()) {
		postfix += operators.top();
		operators.pop();
}
    return postfix;
}
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
