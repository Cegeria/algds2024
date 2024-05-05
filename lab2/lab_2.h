#include <stdio.h>
#ifndef LAB_2_H_SENTRY
#define LAB_2_H_SENTRY

typedef struct node node;

node* NewNode(int val);

void RotateLeft(node* v);

void RotateRight(node* v);

void Splay(node* v);

node* Search(node* tree, int x);

node* Insert(node* tree, int val);

void Split(int key, node* tree, node* tree_1, node* tree_2);

node* Merge(node* tree_1, node* tree_2);

#endif