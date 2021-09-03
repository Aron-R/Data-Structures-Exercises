#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node Node;
struct Node {
    char value;
    Node* next;
};

typedef struct OP {
    char val;
    int prec;
} OP[5];
OP SET = {{'^', 3}, {'/', 2}, {'*', 2}, {'-', 1}, {'+', 1}};

int order(char op) {
    for (int i = 0; i < 5; i++) 
        if (op == SET[i].val) return SET[i].prec;
    return -1;
}

typedef struct Stack {
    Node* top;
    size_t size;
} Stack;

void push(Stack* S, char value) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = value;
    temp->next = S->top;
    S->top = temp;
    S->size++;
}

char pop(Stack *S) {
    Node* temp = S->top;
    S->top = S->top->next;
    char value = temp->value;
    free(temp);
    S->size--;
    return value;
}

char peek(Stack* S) { return S->top->value; }

char* postfix(char* exp) {
    Stack S = {NULL, 0};
    char* out = (char*) malloc(strlen(exp));
    int i = 0;
    for (char c = *exp; c; c = *++exp) {
        if (isalpha(c)) out[i++] = c;
        else if (c == '(') push(&S, c);
        else if (c == ')') {
            while ((S.size) && peek(&S) != '(') out[i++] = pop(&S);
            if ((S.size) && peek(&S) != '(') return 0;
            else pop(&S);
        } else {
            while ((S.size) && order(c) <= order(peek(&S))) out[i++] = pop(&S);
            push(&S, c);
        }
    }
    while (S.size) out[i++] = pop(&S);
    out[i] = 0;
    return out;
}

int main() {
    char string[] = "A*(B+C)*D";
    printf("\nThe postfix conversion of string \"%s\" is: "  
              "%s\n", string, postfix(string));
}
