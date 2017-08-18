//
//  2DDynamicArray.c
//  DSA
//
//  Created by Nikhil Bhownani on 12/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#include "DynamicArray2d.h"


DynamicArray2D* dynamicArray2D(int row, int column) {
	DynamicArray2D *dynamicArray2D = (DynamicArray2D *)malloc(sizeof(DynamicArray2D));
	dynamicArray2D->row = row;
	dynamicArray2D->column = column;
	int **arr = (int **)malloc(row*sizeof(int *));
	
	for(int i = 0; i<column; i++) {
		int *arr2 = malloc(sizeof(int)*column);
		arr[i] = arr2;
	}
	dynamicArray2D->array = arr;
 
	return dynamicArray2D;
}

void insertElement(int element, DynamicArray2D *dynamicArray2D, int row, int col) {
	dynamicArray2D->array[row][col] = element;
}

void printDynamicArray2d(DynamicArray2D *dynamicArray) {
	for (int i = 0; i < dynamicArray->row; i++) {
		for (int j = 0; j < dynamicArray->column; j++) {
			printf("Value at row %d, column %d is %d\n", i, j, dynamicArray->array[i][j]);
		}
	}
}


void dynamicMain2() {
	int num;
	DynamicArray2D *dynamic = dynamicArray2D(2, 3);
	for (int i = 0; i< 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &num);
			insertElement(num, dynamic, i, j);
			
		}
	}
	printDynamicArray2d(dynamic);
}
