//
//  Hash.c
//  DSA
//
//  Created by Nikhil Bhownani on 13/08/17.
//  Copyright © 2017 Nikhil Bhownani. All rights reserved.
//

#include "Hash.h"

Hash *newHashWithSize(int size) {
	Hash *hash = malloc(sizeof(Hash));
	hash->nodes = malloc(sizeof(HashNode*)*size);
	for (int i = 0; i<size; i++) {
		hash->nodes[i] = malloc(sizeof(HashNode));
		hash->nodes[i]->isDeleted = 0;
		hash->nodes[i]->isFilled = 0;
	}
	hash->filledElements = 0;
	hash->size = size;
	return hash;
}

int getHashPosition(Hash *hash, int key) {
	int hashSize = hash->size;
	return key % hashSize;
}

int getLegitHashPosition(Hash *hash, int key) {
	int position = getHashPosition(hash, key);
	HashNode *node = hash->nodes[position];
	while(node != NULL && node->isFilled && node->isDeleted != 0) {
		
		position = position+1;
		node = hash->nodes[position];
	}
	
	return position;
}

void moveElementsFromOldHashToNewHash(Hash **oldHash, Hash **newHash) {
	for (int i = 0; i<(*oldHash)->size; i++) {
		HashNode* node = (*oldHash)->nodes[i];
		if (node != NULL && node->isDeleted == 0) {
			
			insertElementInHash(*newHash, node->key, node->value);
		}
	}
	oldHash = newHash;
}

void reHash(Hash *hash) {
	Hash * newHash = newHashWithSize(hash->size * 2);
	
	for (int i = 0; i<newHash->size; i++) {
		HashNode *node = malloc(sizeof(HashNode));
		node->isDeleted = 0;
		node->isFilled = 0;
		newHash->nodes[i] = node;
	}
	if (hash->filledElements > 0) {
		moveElementsFromOldHashToNewHash(&hash, &newHash);
	}
}

void insertElementInHash(Hash *hash, int key, int value) {
	if (hash->filledElements + 1 >= 0.7 * hash->size) {
		reHash(hash);
	}
	/*HashNode *node = malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->isDeleted = 0;
	 */
	int position = getLegitHashPosition(hash, key);
	HashNode *positionNode = hash->nodes[position];
	
	hash->nodes[position]->key = key;
	hash->nodes[position]->value = value;
	
	hash->filledElements = hash->filledElements + 1;
}

void deleteKey(Hash *hash, int key) {
	
}

int seekElementInHash(int key, Hash *hash) {
	int hashPosition = getHashPosition(hash, key)%hash->size;
	for (int i = hashPosition; i < hash->size; i++) {
		if (hash->nodes[i]->key == key) {
			return hash->nodes[hashPosition]->value;
		} else if (hash->nodes[hashPosition] == NULL && hash->nodes[hashPosition]->isDeleted == 0) {
			return -1;
		}
	}
	return -1;
}



Hash* newHash(){
	Hash *hash = newHashWithSize(1);
	
	return hash;
}

int HashMain() {
	Hash *hash = newHash();
	insertElementInHash(hash, 1, 4);
	
	insertElementInHash(hash, 3, 6);
	insertElementInHash(hash, 5, 8);
	insertElementInHash(hash, 7, 10);
	printf("seek %d", seekElementInHash(1, hash));
	seekElementInHash(3, hash);
	return 0;
}
