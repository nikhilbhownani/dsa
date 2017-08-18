//
//  Stack.c
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#include "Stack.h"

Stack* push(int element, Stack *stack) {
	Stack *s = newStackWithElement(element);
	s->value = element;
	s->next = stack;
	return s;
}

Stack* pop(Stack *stack) {
	stack = stack->next;
	return stack;
}

void seek(Stack *stack) {
	printf("%d", stack->value);
}

Stack *newStackWithElement(int element) {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->next = NULL;
	stack->value = element;
	return stack;
}

void print(Stack *stack) {
	while(stack!= NULL) {
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int StackMain() {
	Stack *stack = newStackWithElement(4);
	stack = push(5, stack);
	stack = push(6, stack);
	print(stack);
	stack = pop(stack);
	return 0;
}
