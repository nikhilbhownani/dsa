//
//  LinkedList.c
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#include "LinkedList.h"


LinkedList *linkedList() {
	LinkedList *list = malloc(sizeof(LinkedList));
	
	return list;
}

Node *nodeWithElement(int element) {
	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->value = element;
	return node;
}

void printLinkedList(LinkedList *list) {
	Node *node = list->head;
	while(node != NULL) {
		printf("value is %d\n", node->value);
		node = node->next;
	}
}


void deleteElementInList(int num, LinkedList *list) {
	Node *node = list->head;
	if (list->head->value == num) {
		list->head = list->head->next;
	}
	while (node != NULL && node->next != NULL) {
		if (node->next->value == num) {
			Node* next = node->next;
			node->next = node->next->next;
			//free(&next);
		}
		node = node->next;
	}
	printLinkedList(list);
}

int linkedListMain() {
	LinkedList *list = linkedList();
	list->head = nodeWithElement(5);
	Node *currentNode = list->head;
	for(int i = 0; i< 10; i++) {
		Node *newNode = nodeWithElement(i);
		currentNode->next = newNode;
		currentNode = currentNode->next;
	}
	
	
	printLinkedList(list);
	int num;
	printf("Enter a number to delete ");
	scanf("%d", &num);
	deleteElementInList(num, list);
	return 0;
}
