//
//  DynamicArray.h
//  DSA
//
//  Created by Nikhil Bhownani on 12/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#ifndef DynamicArray_h

#include <stdio.h>

struct DynamicArray {
	int *array;
	int size;
};

typedef struct DynamicArray DynamicArray;
void insert(int *array, int count);
void insertIntoDynamicArrayAtIndex(int value, DynamicArray *dyn, int index);
void printArray(int *array, int count);
void printDynamicArray(DynamicArray *dyn);
int arraySize(int *array);
DynamicArray* dynamicArray(int numberOfElements);
void dynamicmain();

#define DynamicArray_h

#endif /* DynamicArray_h */
