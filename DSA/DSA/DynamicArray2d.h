//
//  2DDynamicArray.h
//  DSA
//
//  Created by Nikhil Bhownani on 12/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#ifndef _DDynamicArray_h
#define _DDynamicArray_h

#include <stdio.h>

struct DynamicArray2D {
	int **array;
	int row;
	int column;
};

typedef struct DynamicArray2D DynamicArray2D;
DynamicArray2D* dynamicArray2D(int row, int column);
void insertElement(int element, DynamicArray2D *dynamicArray2D, int row, int col);
void printDynamicArray2d(DynamicArray2D *dynamicArray);
void dynamicMain2();


#endif /* _DDynamicArray_h */
