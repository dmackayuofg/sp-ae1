struct node_t{
    int value;
    struct node_t * left;
    struct node_t * right;
};

node_t * search(node_t * node, int toFind) {

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

}

void delete(node_t * node, int elem) {

}