//
//  Stack.h
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

struct Stack;
typedef struct Stack Stack;

struct Stack {
	Stack *next;
	int value;
};

Stack* push(int element, Stack *stack);
Stack* pop(Stack *stack);
void seek(Stack *stack);

Stack *newStackWithElement(int element);
int StackMain();
#endif /* Stack_h */
