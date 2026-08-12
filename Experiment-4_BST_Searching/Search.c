#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int search(struct Node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    struct Node *root = NULL;
    int n, data, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("%d is present in the BST.\n", key);
    else
        printf("%d is not present in the BST.\n", key);

    return 0;
}