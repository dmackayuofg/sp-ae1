#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    int value;
    struct node_t * left;
    struct node_t * right;
} node_t;

node_t * search(node_t * node, int toFind) {
    if (node == NULL | toFind == (*node).value) {
        return node;
    }
    if (toFind < (*node).value) {
        return search((*node).left, toFind);
    }
    else {
        return search((*node).right, toFind);
    }
}

node_t * createTree(int firstElem) {
    node_t node = {firstElem, NULL, NULL};
    node_t * p = malloc(sizeof(node_t));
    if (p==NULL) {
        return NULL;
    }
    (*p).value = node.value;
    (*p).left = node.left;
    (*p).right = node.right;
    return p;
}

void destroyTree(node_t * node) {
    if (node == NULL) {
        return;
    }
    while (node) {
        printf("start of while: %d\n", node->value);
        node_t * node_left = node->left;
        node_t * node_right = node->right;
        if (node_right == NULL | node_left == NULL) {
            printf("inside if: %d\n", node->value);
            free(node);
            node = NULL;
            return;
        }
        if (node_right != NULL) {
            destroyTree(node_right);
            node->right = NULL;
        }
        else if (node_left != NULL) {
            destroyTree(node_left);
            node->left = NULL;
        }
        else {
            destroyTree(node_left);
            node->left = NULL;
            destroyTree(node_right);
            node->right = NULL;
        }
    }
}

void insert(node_t * node, int elem) {
    node_t * parent_node = NULL;
    while (node != NULL) {
        parent_node = node;
        if (elem < (*node).value) {
            node = (*node).left;
        }
        else {
            node = (*node).right;
        }
    }
    if (parent_node == NULL) {
        createTree(elem);
    }
    else if (elem < (*parent_node).value) {
        (*parent_node).left = createTree(elem);
    }
    else {
        (*parent_node).right = createTree(elem);
    }
}

void delete(node_t * node, int elem) {

}

int main() {
    node_t * head_pointer = createTree(5);
    insert(head_pointer, 3);
    insert(head_pointer, 4);
    insert(head_pointer, 2);
    insert(head_pointer, 1);
    insert(head_pointer, 7);
    insert(head_pointer, 8);
    insert(head_pointer, 6);
    destroyTree(head_pointer);
}
