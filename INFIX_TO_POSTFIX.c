#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
    }
}
char pop() {
    if (top == -1) {
        return -1;
    } else {
        char item = stack[top];
        top--;
        return item;
    }
}
int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}
void infixToPostfix(char infix[]) {
    char x;
    printf("Postfix Expression: ");
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            printf("%c",infix[i]);
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                printf("%c", pop());
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
}
int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
