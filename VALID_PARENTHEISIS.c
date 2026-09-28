#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}
char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}
int isMatching(char open, char close) {
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}
int main() {
    char s[MAX];
    char open;
    int i;
    int valid = 1;
    printf("Enter brackets: ");
    scanf("%99s", s);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1) {
                valid = 0;
                break;
            }
            open = pop();
            if (isMatching(open, s[i]) == 0) {
                valid = 0;
                break;
            }
        }
    }
    if (top != -1) {
        valid = 0;
    }

    if (valid == 1) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }
    return 0;
}

