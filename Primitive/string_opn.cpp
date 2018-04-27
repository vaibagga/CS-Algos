#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int stringLength (string s){
    int length = 0;
    while (s[length]!='\0'){
        length++;
    }
    return length;
}

string stringCatenation(string s1, string s2){
    return s1 + s2;

}
/*
Substring function returns a substring
of the string s staring at start-index (inclusive)
and ending at end_index (exclusive)
*/
string subString(string s,int start_index,int end_index){
     string sub = "";
     for (int index = start_index; index < end_index; index++){
        sub+=s[index];
     }
     return sub;
}
int main()
{
    int userInput;
    string userString1, userString2;
    cout << "Enter string1\n";
    getline(cin,userString1);
    cout << "Enter the second string to be catenated to the first string(leave it blank if no string is to be catenated)\n";
    getline(cin,userString2);
    cout << "Press '1' for length, '2' for catenation and '3' for substring: ";
    cin >> userInput;
    if (userInput == 1){
        cout << stringLength(userString1);
    }
    else if (userInput == 2){
        cout << stringCatenation(userString1,userString2);
    }
    else if (userInput == 3){
        int start, ending;
        cout << "Enter the starting index: ";
        cin >> start;
        cout << "Enter the ending index: ";
        cin >> ending;
        if (ending > userString1.length() || start < 0){
            cout << "Invalid index\n";
        }
        else {
        cout << subString(userString1,start,ending);
        }
    }
    return 0;
}
