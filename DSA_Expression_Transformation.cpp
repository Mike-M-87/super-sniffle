#include <iostream>
#include <string>

using namespace std;

int priority(char opr)  //PRECENDENCE/PRIORITY CHECK FUNCTION
{
    if (opr == '^')
    {
        return 3;
    }
    else if (opr == '*' || opr == '/')
    {
        return 2;
    }
    else if (opr == '+' || opr == '-')
    {
        return 1;
    }
    else if (opr == '(')
    {
        return 4;
    }
    else if (opr == ')')
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

void postfix(string exp)
{
    string infixExpr = exp;
    string oprStack;
    string output;

    //PRINTS THE TABLE
    cout << "\n::INFIX TO POSTFIX::\n";
    cout << "\nInput   Stack\tOutput" << endl;
    cout << "__________________________________" << endl;

    for (int i = 0; i < infixExpr.length(); i++)
    {
        char scanned = infixExpr[i];
        int checkscan = priority(scanned);  //RETURNS THE PRECEDENCE/PRIORITY OF THE SCANNED ELEMENT

        if (checkscan != -1 && checkscan != 5)  //ENSURES THE SCANNED ELEMENT IS AN OPERATOR
        {
            if (oprStack.empty())   //ADDS THE OPERATOR IF THE STACK WAS INITIALLY EMPTY
            {
                oprStack.push_back(scanned);
            }

            else
            {   //CHECK PRECEDENCE/PRIORITY OF SCANNED OPERATOR IF LESS THAN OR EQUAL TO THE TOP OPERATOR IN THE STACK
                while (checkscan <= priority(oprStack.back()))
                {
                    if (oprStack.back() == '(')
                    {
                        break;
                    }
                    output.push_back(oprStack.back());
                    oprStack.pop_back();
                }
                oprStack.push_back(scanned);    //PUSHES IN THE SCANNED OPERATOR AFTER ALL THE CHECKS
            }
        }
        //HANDLES BRACKET OPERATORS  IN POSTFIX TRANSORMATION
        else if (checkscan == 5 && (oprStack.find('(') < oprStack.size()))
        {
            while (oprStack.back() != '(')  //LOOPS UNTIL THE BRACKETS CLEAR OUT
            {
                output.push_back(oprStack.back());
                oprStack.pop_back();
            }
            oprStack.pop_back();
        }
        //CHECK IF THE SCANNED INPUT IS A LETTER OR NUMBER
        else if (checkscan == -1)
        {
            output.push_back(scanned);
        }

        //PRINTS THE TABLE
        cout << scanned << "\t";
        cout << oprStack << "\t";
        cout << output << endl;
        cout << "__________________________________" << endl;
    }
    //PUSHES OUT REMAINING STACK ELEMENTS
    while (!oprStack.empty())
    {
        output.push_back(oprStack.back());
        oprStack.pop_back();
    }

    cout << "\n\tPostFix Expression: " << output;
    cout << endl;
}

void prefix(string exp)
{
    string Expr = exp;
    string oprStack;
    string output;
    string infixExpr;

    cout << "\n::INFIX TO PREFIX::\n";

    //REVERSING THE INFIX EPRESSION
    for (int i = Expr.size() - 1; i >= 0; i--)
    {
        infixExpr.push_back(Expr[i]);
    }

    //PRINTS THE TABLE
    cout << "Reversed: " << infixExpr << endl;
    cout << "\nInput   Stack\tOutput" << endl;
    cout << "__________________________________" << endl;

    for (int i = 0; i < infixExpr.length(); i++)
    {
        char scanned = infixExpr[i];
        int checkscan = priority(scanned); //RETURNS THE PRECEDENCE/PRIORITY OF THE SCANNED ELEMENT

        if (checkscan != -1 && checkscan != 4) //ENSURES THE SCANNED ELEMENT IS AN OPERATOR
        {
            if (oprStack.empty()) //ADDS THE OPERATOR IF THE STACK WAS INITIALLY EMPTY
            {
                oprStack.push_back(scanned);
            }
            else
            {   //CHECK PRECEDENCE/PRIORITY OF SCANNED OPERATOR IF LESS THAN THE TOP OPERATOR IN THE STACK
                while (checkscan < priority(oprStack.back()))
                {
                    if (oprStack.back() == ')') //BREAKS IF THE SCANNED OPERATOR IS CLOSING BRACKET WHICH IS THEN ADDED TO THE STACK
                    {
                        break;
                    }
                    output.push_back(oprStack.back());
                    oprStack.pop_back();
                }
                oprStack.push_back(scanned);    //PUSHES IN THE SCANNED OPERATOR AFTER ALL THE CHECKS
            }
        }

        //HANDLE BRACKET OPERATORS  IN PREFIX TRANSORMATION
        else if (scanned == '(' && (oprStack.find(')') < oprStack.size()))
        {

            while (oprStack.back() != ')') //LOOPS UNTIL THE BRACKETS CLEAR OUT
            {
                output.push_back(oprStack.back());
                oprStack.pop_back();
            }
            oprStack.pop_back();
        }

        //CHECK IF THE SCANNED INPUT IS A LETTER OR NUMBER
        else if (checkscan == -1)
        {
            output.push_back(scanned);
        }

        //PRINTS THE TABLE
        cout << scanned << "\t";
        cout << oprStack << "\t";
        cout << output << endl;
        cout << "__________________________________" << endl;
    }

    //PUSHES OUT REMAINING STACK ELEMENTS
    while (!oprStack.empty())
    {
        output.push_back(oprStack.back());
        oprStack.pop_back();
    }

    cout << "\n\tOutput: " << output;

    //REVERSING THE OUTPUT EXPRESSION
    string PrefixEprr;
    for (int i = output.size() - 1; i >= 0; i--)
    {
        PrefixEprr.push_back(output[i]);
    }

    cout << "\n\tPreFix Expression: " << PrefixEprr;
    cout << endl;
}


int main()
{
    string Expression;
    cout << "Enter Infix Expression: ";
    cin >> Expression;
    prefix(Expression);
    postfix(Expression);
    return 0;
}
