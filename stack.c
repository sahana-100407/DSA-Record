#include <stdio.h>
#define MAX 5  // Define maximum size of the stack

int stack[MAX];
int top = -1;  // Stack is initially empty

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;  // Increment top and add element
        printf("%d pushed onto stack\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];  // Return top element and decrement top
    }
}

// Function to view the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element is %d\n", peek());

    printf("%d popped from stack\n", pop());
    printf("%d popped from stack\n", pop());

    return 0;
}

