#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
	int arr[MAX_SIZE];
	int top;
} Stack;

void initialize(Stack *stack) {
	stack->top = -1;
}

bool isEmpty(Stack *stack) {
	return stack->top == -1;
}

bool isFull(Stack *stack) {
	return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
	if (isFull(stack)) {
		return;
	}
	stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	int popped = stack->arr[stack->top];
	stack->top--;
	return popped;
}

int peek(Stack *stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	return stack->arr[stack->top];
}
