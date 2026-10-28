#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
 if (top == MAX - 1) {
 printf("Stack Overflow\n");
 } else {
 stack[++top] = x;
 }
}
char pop() {
 if (top == -1) {
 return -1;
 } else {
 return stack[top--];
 }
}
int precedence(char x) {
 if (x == '(')
 return 0;
 if (x == '+' || x == '-')
 return 1;
 if (x == '*' || x == '/')
 return 2;
 if (x == '^')
 return 3;
 return -1;
}
int main() {
 char infix[MAX], postfix[MAX];
 char *e, x;
 int k = 0;
 printf("Enter infix expression: ");
 scanf("%s", infix);
 e = infix;
 while (*e != '\0') {
 if (isalnum(*e)) {
 postfix[k++] = *e;
 }
 else if (*e == '(') {
 push(*e);
 }
 else if (*e == ')') {
 while ((x = pop()) != '(') {
 postfix[k++] = x;
 }
Experiment No : 15
/**********************************************************************/
Name : Akshaya P Sudheesh
Roll No : 05
Alphons C S
08 }
 else {
 while (top != -1 &&
 precedence(stack[top]) >= precedence(*e)) {
 postfix[k++] = pop();
 }
 push(*e);
 }
 e++;
 }
 while (top != -1) {
 postfix[k++] = pop();
 }
 postfix[k] = '\0';
 printf("Postfix expression: %s\n", postfix);
 return 0;
}
