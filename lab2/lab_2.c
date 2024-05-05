#include <stdio.h>
#include <stdlib.h>
#include "lab_2.h"

typedef struct node {
    int key;
    node* left;
    node* right;
    node* parent;
} node;

node* NewNode(int val)
{
    node* n = (node*)malloc(sizeof(node));
    n->key = val;
    n->left = n->right = n->parent = NULL;
    return n;
}

void RotateLeft(node* v)
{
    node* p = v->parent;
    node* r = v->right;
    if (p != NULL) {
        if (p->left == v) {
            p->left = r;
        } else {
            p->right = r;
        }
    }
    node* tmp = r->left;
    r->left = v;
    v->right = tmp;
    v->parent = r;
    r->parent = p;
    if (v->right != NULL) {
        v->right->parent = v;
    }
}

void RotateRight(node* v)
{
    node* p = v->parent;
    node* l = v->left;
    if (p != NULL) {
        if (p->right == v) {
            p->right = l;
        } else {
            p->left = l;
        }
    }
    node* tmp = l->right;
    l->right = v;
    v->left = tmp;
    v->parent = l;
    l->parent = p;
    if (v->left != NULL) {
        v->left->parent = v;
    }
}

void Splay(node* v)
{
    while (v->parent != NULL) {
        if (v == v->parent->left) {
            if (v->parent->parent == NULL) {
                RotateRight(v->parent);
            } else if (v->parent == v->parent->parent->left) {
                RotateRight(v->parent->parent);
                RotateRight(v->parent);
            } else {
                RotateRight(v->parent);
                RotateLeft(v->parent);
            }
        } else {
            if (v->parent->parent == NULL) {
                RotateLeft(v->parent);
            } else if (v->parent == v->parent->parent->right) {
                RotateLeft(v->parent->parent);
                RotateLeft(v->parent);
            } else {
                RotateLeft(v->parent);
                RotateRight(v->parent);
            }
        }
    }
}

node* Search(node* tree, int x)
{
    node* element = tree;
    while (element != NULL) {
        if (element->key < x) {
            element = element->right;
        } else if (element->key > x) {
            element = element->left;
        } else {
            Splay(element);
            return element;
        }
    }
}

node* Insert(node* tree, int val)
{
    node* pre_insert = NULL;
    node* insert = tree;

    while (insert != NULL) {
        pre_insert = insert;
        if (insert->key < val) {
            insert = insert->right;
        } else if (insert->key >= val) {
            insert = insert->left;
        }
    }

    node* element = NewNode(val);
    element->parent = pre_insert;
    if (pre_insert == NULL) {
        tree = element;
    } else if (pre_insert->key < element->key) {
        pre_insert->right = element;
    } else if (pre_insert->key > element->key) {
        pre_insert->left = element;
    } else {
        free(element);
        return tree;
    }

    Splay(element);

    return element;
}

void Split(int key, node* tree, node* tree_1, node* tree_2)
{
    node* key_node = Search(tree, key);
    if (key_node == NULL) return;

    Splay(key_node);

    tree_1 = key_node->left;
    tree_1->parent = NULL;
    key_node->left = NULL;
    tree_2 = key_node;
}

node* Merge(node* tree_1, node* tree_2) //(all keys of tree_1) < (any key of tree_2)
{
    if (tree_1 == NULL) return tree_2;
    else if (tree_2 == NULL) return tree_1;

    node* check_1 = tree_1->right;
    while (check_1 != NULL) {
        check_1 = check_1->right;
    }
    node* check_2 = tree_2->left;
    while (check_2 != NULL) {
        check_2 = check_2->left;
    }
    if (check_1->key >= check_2->key) return NULL;

    node* result = tree_1->right;
    while (result != NULL) {
        result = result->right;
    }
    Splay(result);
    result->right = tree_2;

    return result;
}
