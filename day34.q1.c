#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            continue;
        }

        // If operator
        int val2 = pop();
        int val1 = pop();
        int result;

        switch (exp[i]) {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
        }

        push(result);
        i++;
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
