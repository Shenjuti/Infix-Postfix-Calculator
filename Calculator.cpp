#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <windows.h>

using namespace std;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int ll;

/* Functions */
bool Digit(char C);
bool Operator(char C);
bool Operator(char C);
int prec(char C);
void init();
void Addition();
void Substraction();
void Multiplication();
void Division();
void Calculator(char C);
void postFixOpp(string str1);
void postFix();
void inFix();
/* Functions */


stack<ll>Stack;
string s;

void init()
{
    while (!Stack.empty())
        Stack.pop();
}

void Addition()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1+op2;
    Stack.push(S);
}

void Substraction()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1-op2;
    Stack.push(S);
}

void Multiplication()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1*op2;
    Stack.push(S);
}

void Division()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    if (op2)
    {
        op1=Stack.top();
        Stack.pop();
        S=op1/op2;
        Stack.push(S);
    }
    else
        cout << "\n\tWrong equation!!!\n\n\tInput Correctly Again...\n\n";
}
void Calculator(char C)
{
    if (C=='+')
        Addition();
    else if (C=='-')
        Substraction();
    else if (C=='*')
        Multiplication();
    else if (C=='/')
        Division();
}

bool Digit(char C)
{
    if(C>='0' && C<='9')
        return true;
    return false;
}

bool Operator(char C)
{
    if(C=='+' || C=='-' || C=='*' || C=='/')
        return true;
    return false;
}

int prec(char C)
{
    if(C=='*' || C=='/')
        return 2;
    else if(C=='+' || C=='-')
        return 1;
    else
        return -1;
}

void postFixOpp(string str1)
{
    int l=str1.length();
    for(int i=0; i<l; i++)
    {
        if(str1[i]==' ')
            continue;

        if(Operator(str1[i]))
            Calculator(str1[i]);

        else if(Digit(str1[i]))
        {
            ll opp=0;
            while(i<l && Digit(str1[i]))
            {
                opp=(opp*10)+(str1[i]-'0');
                i++;
            }
            i--;
            Stack.push(opp);
        }
    }
    cout << "\n\tResult: " << Stack.top() << endl << endl;
}

void postFix()
{
    printf("\nEnter The PostFix Equation: ");
    cin.ignore();
    getline(cin,s);
    postFixOpp(s);
}

void inFix()
{
    stack<char> st;
    string ns;

    printf("\nEnter The inFix Equation: ");
    cin.ignore();
    getline(cin,s);

    st.push('N');
    int l=s.length();
    for(int i=0; i<l; i++)
    {
        if(Digit(s[i]))
            ns+=s[i];

        else if (s[i]==' ')
            ns+=' ';

        else if(s[i]=='(')
            st.push('(');

        else if(s[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                ns+=st.top();
                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }
        else
        {
            while(st.top()!='N' && prec(s[i])<=prec(st.top()))
            {
                ns+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.top()!='N')
    {
        ns+=st.top();
        st.pop();
    }
    postFixOpp(ns);


}

int main()
{
    int choice,j=1;
    for (int i=1; i<=j; i++)
    {
        init();
        cout << "\t\t\t\t__________________________CALCULATOR_____________________________\n\n"
             << "\n\n\t\t\t\t\t\tWHICH ONE DO YOU WANNA CHOOSE:\n"
             << "\t\t\t Press 1 For Infix Calculation\t"
             << "\t\t Press 2 For Postfix Calculation\n"
             << "\n\n\t\t\t\t\t\tENTER YOUR CHOICE: ";
        cin >> choice;
        if(choice==1)
            inFix();
        else if(choice==2)
            postFix();

        else
            cout << "\n\n\t***Wrong Choice* \n\n";

        cout << "Do you want to continue??? y/n: ";
        char C;
        cin >> C;
        if(C=='y' || C=='Y')
            j++;
    }
}
