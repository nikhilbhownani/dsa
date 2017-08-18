//
//  Hash.h
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#ifndef Hash_h
#define Hash_h

#include <stdio.h>

struct Hash;
typedef struct Hash Hash;

struct Node;
typedef struct HashNode HashNode;

struct HashNode {
	int key;
	int value;
	int isDeleted;
	int isFilled;
};

struct Hash {
	int size;
	int filledElements;
	HashNode **nodes;
};

void insertElementInHash(Hash *hash, int key, int value);
void deleteKey(Hash *hash, int key);
Hash* newHash();
int HashMain();

#endif /* Hash_h */
