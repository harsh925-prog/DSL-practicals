//Harsh Gangadhar Chakote
//SE-II (Q)
//Roll No.: 31
//PRN: F23112034
/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.
*/

#include <iostream>
using namespace std;
#define size 10
class stackexp{
    int top;
    char stk[size];
public:
    stackexp(){
        top = -1;
    }
    void push(char);
    char pop();
    int isFull();
    int isEmpty();
};
void stackexp::push(char x){
    if (!isFull()){
        top++;
        stk[top] = x;
    }
    else{
        cout << "Stack overflow!" << endl;
    }
}
char stackexp::pop(){
    if (!isEmpty()){
        char s = stk[top];
        top--;
        return s;
    }
    else{
        cout << "Stack underflow!" << endl;
        return '\0';
    }
}
int stackexp::isFull(){
    return top == size - 1;
}
int stackexp::isEmpty(){
    return top == -1;
}
int isMatchingPair(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
int main(){
    stackexp s1;
    char exp[20], ch;
    int i = 0;
    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the expression to check whether it is well-formed or not:  ";
    cin >> exp;
    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')){
        cout << "\n Invalid Expression.....\n";
        return 0;
    }
    else{
        while (exp[i] != '\0'){
            ch = exp[i];
            if (ch == '(' || ch == '[' || ch == '{'){
                s1.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}'){
                if (s1.isEmpty() || !isMatchingPair(s1.pop(), ch)){
                    cout << "\nExpression is not well-parenthesized!!!" << endl;
                    return 0;
                }
            }
            i++;
        }
    }
    if (s1.isEmpty()){
        cout << "\nExpression is well-parenthesized!!!" << endl;
    }
    else{
        cout << "\nExpression is not well-parenthesized!!!" << endl;
    }
    return 0;
}

//Output:
/*
        !! Parenthesis Checker..!!!!

Enter the expression to check whether it is well-formed or not:  {a+n}

Expression is well-parenthesized!!!

        !! Parenthesis Checker..!!!!

Enter the expression to check whether it is well-formed or not:  [a+b)

Expression is not well-parenthesized!!!

        !! Parenthesis Checker..!!!!

Enter the expression to check whether it is well-formed or not:  }a+b}

 Invalid Expression.....
*/