/* Aim:Write a program to implement DFA accept all the string which followes language L=(aa)*b+  */
#include <iostream>
#include <string.h>
using namespace std;
int dfa = 0;

void start(char c)
{
    if (c == 'a')
    {
        dfa = 1;
    }
    else if (c == 'b')
    {
        dfa = 3;
    }

    else
    {
        dfa = -1;
    }
}

void state1(char c)
{
    if (c == 'a')
    {
        dfa = 2;
    }
    else if (c == 'b')
    {
        dfa = 4;
    }
    else
    {
        dfa = -1;
    }
}

void state2(char c)
{
    if (c == 'b')
    {
        dfa = 3;
    }
    else if (c == 'a')
    {
        dfa = 1;
    }
    else
    {
        dfa = -1;
    }
}

void state3(char c)
{
    if (c == 'b')
    {
        dfa = 3;
    }
    else if (c == 'a')
    {
        dfa = 4;
    }
    else
    {
        dfa = -1;
    }
}
void state4(char c)
{
    dfa = -1;
}

int isAccepted(char str[])
{
    int i, len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (dfa == 0)
            start(str[i]);

        else if (dfa == 1)
            state1(str[i]);

        else if (dfa == 2)
            state2(str[i]);

        else if (dfa == 3)
            state3(str[i]);

        else if (dfa == 4)
            state4(str[i]);
        else
            return 0;
    }
    if (dfa == 3)
        return 1;
    else
        return 0;
}

int main()
{
    char str[] = "aaaaaabbbb";
    if (isAccepted(str))
        cout << "ACCEPTED";
    else
        cout << "NOT ACCEPTED";
    return 0;
}
/* Output:ACCEPTED */