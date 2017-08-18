//
//  LinkedList.h
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

struct Node;
typedef struct Node Node;

struct Node {
	Node *next;
	int value;
};

struct LinkedList;

typedef struct LinkedList LinkedList;

struct LinkedList {
	Node* head;
};
LinkedList *linkedList();
Node *nodeWithElement(int element);
void printLinkedList(LinkedList *list);
int linkedListMain();

#endif /* LinkedList_h */
