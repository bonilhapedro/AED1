#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} Node;

Node* insert(Node* root, int val) {
    if (!root) {
        Node* n = (Node*)malloc(sizeof(Node));
        n->val = val;
        n->left = n->right = NULL;
        return n;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void preOrder(Node* root, int *first) {
    if (root) {
        if (*first) {
            printf("%d", root->val);
            *first = 0;
        } else {
            printf(" %d", root->val);
        }
        preOrder(root->left, first);
        preOrder(root->right, first);
    }
}

void inOrder(Node* root, int *first) {
    if (root) {
        inOrder(root->left, first);
        if (*first) {
            printf("%d", root->val);
            *first = 0;
        } else {
            printf(" %d", root->val);
        }
        inOrder(root->right, first);
    }
}

void postOrder(Node* root, int *first) {
    if (root) {
        postOrder(root->left, first);
        postOrder(root->right, first);
        if (*first) {
            printf("%d", root->val);
            *first = 0;
        } else {
            printf(" %d", root->val);
        }
    }
} 

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            int v;
            scanf("%d", &v);
            root = insert(root, v);
        }
        printf("Case %d:\n", t);
        printf("Pre.: ");
        int f = 1;
        preOrder(root, &f);
        printf("\n");
        printf("In..: ");
        f = 1;
        inOrder(root, &f);
        printf("\n");
        printf("Post: ");
        f = 1;
        postOrder(root, &f);
        printf("\n\n");
        freeTree(root);
    }
    return 0;
}
