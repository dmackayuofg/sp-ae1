struct node_t{
    int value;
    struct node_t * left;
    struct node_t * right;
};

node_t * search(node_t * node, int toFind) {
    if (node==NULL | toFind==node.value) {
        return node;
    }
    if toFind < node.value {
        return search(node.left, toFind);
    }
    else {
        return search(node.right, toFind);
    }

    // do as iterative?
}

node_t * createTree(int firstElem) {
    struct node_t node = {firstElem, NULL, NULL};
    struct node_t * p = malloc(sizeof(struct node_t));
    if (p==NULL) {
        return NULL;
    }
    (*p).value = node.value;
    (*p).left = node.left;
    (*p).right = node.right;
    return p;
}

void destroyTree(node_t * node) {

}

void insert(node_t * node, int elem) {
    parent_node = NULL;
    while (node != NULL) {
        parent_node = node;
        if elem < node.value {
            node = node.left;
        }
        else {
            node = node.right;
        }
    }
    if (parent_node == NULL) {
        createTree(elem);
    }
    else if (elem < parent_node.value) {
        parent_node.left = createTree(elem);
    }
    else (elem > parent_node.value) {
        parent_node.right = createTree(elem);
    }
}

void delete(node_t * node, int elem) {

}