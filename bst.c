#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertToBST(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertToBST(root->left, data);
    } else {
        root->right = insertToBST(root->right, data);
    }
    
    return root;
}

struct Queue {
    struct node* arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->front > q->rear);
}

void enqueue(struct Queue* q, struct node* treeNode) {
    if (q->rear < MAX_QUEUE_SIZE - 1) {
        q->arr[++(q->rear)] = treeNode;
    } else {
        printf("Queue is full!\n");
    }
}

struct node* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    return q->arr[(q->front)++];
}

void levelOrderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }

    free(q);
}

struct node* searchinBST(struct node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    
    if (x < root->data) {
        return searchinBST(root->left, x);
    } else {
        return searchinBST(root->right, x);
    }
}

struct node* minVal(struct node* root) {
    struct node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

struct node* maxVal(struct node* root) {
    struct node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

struct node* deletefromBST(struct node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        //0 child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        //1 child left
        if (root->left != NULL && root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
         //1 child right
        if (root->left == NULL && root->right != NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        //2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    } else if (val < root->data) {
        root->left = deletefromBST(root->left, val);
    } else {
        root->right = deletefromBST(root->right, val);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    root = insertToBST(root, 45);
    insertToBST(root, 32);
    insertToBST(root, 60);
    insertToBST(root, 21);
    insertToBST(root, 40);
    insertToBST(root, 55);
    insertToBST(root, 70);
    insertToBST(root, 18);
    insertToBST(root, 36);

    printf("Level-order traversal of the BST:\n");
    levelOrderTraversal(root);
    printf("\n");

    // Uncomment to test search
    // int valueToSearch = 40;
    // struct node* result = searchinBST(root, valueToSearch);
    // if (result != NULL) {
    //     printf("Value %d found in the BST.\n", valueToSearch);
    // } else {
    //     printf("Value %d not found in the BST.\n", valueToSearch);
    // }

    // Uncomment to find max value
    // struct node* maxNode = maxVal(root);
    // if (maxNode != NULL) {
    //     printf("Max value is: %d\n", maxNode->data);
    // } else {
    //     printf("Tree is empty.\n");
    // }

    // Uncomment to find min value
    // struct node* minNode = minVal(root);
    // if (minNode != NULL) {
    //     printf("Min value is: %d\n", minNode->data);
    // } else {
    //     printf("Tree is empty.\n");
    // }

    return 0;
}
