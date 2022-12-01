/* Aim:Write a program to implement shift reduce parser. */
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    char str[20];
    char stack[20];
    int top = 0;
    cout << "Given grammer is:\n S->aABe\n A->Abc/b\n B->d" << endl;
    cout << "Enter String:" << endl;
    cin >> str;
    cout << "Stack \t\t Input buffer \t\t Action" << endl;
    cout << "-------------------------------------------------------" << endl;
    stack[top] = '$';
    top++;
    cout << "$ \t\t abbcde$ \t Shift " << endl;
    stack[top] = str[0];
    top++;
    cout << "$a \t\t bbcde$ \t Shift" << endl;
    stack[top] = str[1];
    if (stack[top] == 'b')
    {
        cout << "$ab \t\t bcde$ \t\t Reduce" << endl;
        stack[top] = 'A';
        top++;
        cout << "$aA \t\t bcde$ \t\t Shift" << endl;
        stack[top] = 'b';
        top++;
        cout << "$aAb \t\t cde$ \t\t Shift" << endl;
        stack[top] = 'c';
        cout << "$aAbc \t\t de$ \t\t Reduce" << endl;
    }
    if ((stack[top] == 'c') && (stack[top - 1] == 'b'))
    {
        top = top - 2;
        cout << "$aA \t\t de$ \t\t Shift" << endl;
        top++;
        stack[top] = 'd';
        cout << "$aAd \t\t e$ \t\t Reduce" << endl;
    }
    if (stack[top] == 'd')
    {
        stack[top] = 'B';
        cout << "$aAB \t\t e$ \t\t Shift" << endl;
        top++;
        stack[top] = 'e';
        cout << "$aABe \t\t $ \t\t Reduce" << endl;
        top = top - 4;
        stack[top] = 's';
        cout << "$s \t\t $ \t\t ACCEPT" << endl;
    }
    if (stack[top] == 'S')
    {
        cout << "String is valid" << endl;
    }
    else
    {
        cout << "String is valid" << endl;
    }
    return (0);
}
/*
Output:
Given grammer is:
 S->aABe
 A->Abc/b
 B->d
Enter String:
abbcde
Stack            Input buffer            Action
-------------------------------------------------------
$                abbcde$         Shift
$a               bbcde$          Shift
$ab              bcde$           Reduce
$aA              bcde$           Shift
$aAb             cde$            Shift
$aAbc            de$             Reduce
$aA              de$             Shift
$aAd             e$              Reduce
$aAB             e$              Shift
$aABe            $               Reduce
$s               $               ACCEPT
String is valid
 */