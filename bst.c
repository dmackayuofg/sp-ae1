#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    int value;
    struct node_t * left;
    struct node_t * right;
} node_t;

node_t * search(node_t * node, int toFind) {
    if (node == NULL || toFind == node->value) {
        return node;
    }
    if (toFind < node->value) {
        return search(node->left, toFind);
    }
    else {
        return search(node->right, toFind);
    }
}

node_t * createTree(int firstElem) {
    node_t * p = malloc(sizeof(node_t));
    if (p == NULL) {
        return NULL;
    }
    p->value = firstElem;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void destroyTree(node_t * node) {
    if (node == NULL) {
        return;
    }
    destroyTree(node->right);
    destroyTree(node->left);
    free(node);
    node = NULL;
}

void insert(node_t * node, int elem) {
    if (node == NULL) {
        return;
    }
    node_t * parent_node = NULL;
    while (node != NULL) {
        parent_node = node;
        if (elem == node->value) {
            return;
        }
        else if (elem < node->value) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if (elem < parent_node->value) {
        parent_node->left = createTree(elem);
    }
    else {
        parent_node->right = createTree(elem);
    }
}

void delete(node_t * node, int elem) {
    if (node == NULL) {
        return;
    }
    node_t * parent_node = NULL;
    while (node != NULL && node->value != elem) {
        parent_node = node;
        if (elem < node->value) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if (node == NULL || parent_node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        if (parent_node->left == node) {
            parent_node->left = NULL;
        }
        else {
            parent_node->right = NULL;
        }
        free(node);
        node = NULL;
    }
    else if (node->left != NULL && node->right == NULL) {
        node_t * left_child = node->left;
        if (parent_node->left == node) {
            parent_node->left = left_child;
        }
        else {
            parent_node->right = left_child;
        }
        free(node);
        node = NULL;
    }
    else if (node->left == NULL && node->right != NULL) {
        node_t * right_child = node->right;
        if (parent_node->left == node) {
            parent_node->left = right_child;
        }
        else {
            parent_node->right = right_child;
        }
        free(node);
        node = NULL;
    }
    else {
        node_t * successor_parent = node;
        node_t * successor = node->right;
        while (successor->left != NULL) {
            successor_parent = successor;
            successor = successor->left;
        }
        node-> value = successor->value;
        if (successor_parent->left == successor) {
            successor_parent->left = successor->right;
        }
        else {
            successor_parent->right = successor->right;
        }
        free(successor);
        successor = NULL;
    }
}