#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node Node;
struct Node {
    char value;
    Node* next;
};

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }
int power(int a, int b) {
    int ans = 1;
    for (;;) {
        if (b & 1) ans *= a;
        b >>= 1;
        if (!b) break;
        a *= a;
    }
    return ans;
}

int operate(int a, int b, char op) {
    typedef int (*func) (int, int);
    func fpArr[5] = {sub, power, divi, mul, add};
    func cal = fpArr[(op -27)%6];
    return cal(a, b);
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

int EvalPrefix(Stack* S, char* exp) {
    for (char c = *exp; c; c = *++exp)
        isdigit(c) ? push(S, c - '0') : push(S, operate(pop(S), pop(S), c));
    return pop(S);
}

int main() {
    Stack S1 = {NULL, 0}; 
    char string[] = "**2+345"; // A = 2, B = 3, C = 4, D = 5, **A+BCD
    strrev(string);
    printf("\nThe answer after evaluation is: %d\n", EvalPrefix(&S1, string));
}
