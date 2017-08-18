//
//  DynamicArray.c
//  DSA
//
//  Created by Nikhil Bhownani on 12/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#include "DynamicArray.h"
void insert(int *array, int count) {
	int num;
	for (int i = 0; i < count ; i++) {
		scanf("%d", &num);
		array[i] = num;
	}
}

void insertIntoDynamicArrayAtIndex(int value, DynamicArray *dyn, int index) {
	dyn->array[index] = value;
}

void printArray(int *array, int count) {
	for (int i = 0; i < count ; i++) {
		printf("%d", array[i]);
	}
}

void printDynamicArray(DynamicArray *dyn) {
	for (int i = 0; i < dyn->size; i++) {
		printf("Index %d value %d\n", i, dyn->array[i]);
	}
}

int arraySize(int *array){
	return sizeof(array)/sizeof(int);
}

DynamicArray* dynamicArray(int numberOfElements) {
	DynamicArray *dyn = (DynamicArray *)malloc(sizeof(DynamicArray));
	int *arr = (int *)malloc(sizeof(int) * numberOfElements);
	dyn->array = arr;
	dyn->size = numberOfElements;
	return dyn;
}

void dynamicmain() {
	printf("Hello, World!\n");
	int num;
	
	DynamicArray *dyn = dynamicArray(6);
	
	for (int i = 0; i< dyn->size; i++) {
		scanf("%d", &num);
		insertIntoDynamicArrayAtIndex(num, dyn, i);
	}
	
	printDynamicArray(dyn);
}
