#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;

    stack[++top] = root;
    while (top != -1) {
        struct TreeNode* current = stack[top--];
        printf("%d\n", current->value);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    free(stack);
}

void inorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1;
    struct TreeNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d\n", current->value);
        current = current->right;
    }
    free(stack);
}

struct TreeNode* printparent(struct TreeNode* root, int target) {
    if (!root) {
        return NULL;
    }
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* current = queue[front++];
        if ((current->left && current->left->value == target) || (current->right && current->right->value == target)) {
            return current;
        }
        if (current->left) {
            queue[rear++] = current->left;
        }
        if (current->right) {
            queue[rear++] = current->right;
        }
    }
    return NULL;
}

int treedepth(struct TreeNode* root) {
    if (root == NULL) {
        return -1;  
    }
    int left = treedepth(root->left);
    int right = treedepth(root->right);
    return 1 + (left > right ? left : right);
}

bool printancestors(struct TreeNode* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->value == target) {
        return true;
    }
    
    if (printancestors(root->left, target) || printancestors(root->right, target)) {
        printf("%d ", root->value);  
        return true;
    }
    return false;
}

int countleaf(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }
    return countleaf(root -> left) + countleaf(root -> right);
}

struct TreeNode* createtree(){
    int value;
    printf("Enter value : ");
    scanf("%d" , &value);
    if(value == -1){
        return NULL;
        
          }
        struct TreeNode* node = createNode(value);
        node -> left = createtree();
        node -> right = createtree();
        return node;
}
void printInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return; 
    }

    
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}



struct TreeNode* buildtree(){
    int value;
    char choice;

    printf("Enter value:");
    scanf("%d" , &value);
   struct  TreeNode* node = createNode(value);
   printf("Does %d have a left child:(y/n)" , value);
   scanf("%c" , &choice);

   if(choice == 'y'){
    node -> left = buildtree();

   }
  printf("Does %d have a right child:(y/n)" , value);
  scanf("%c" , &choice);

   if(choice == 'y'){
    node -> right = buildtree();
   }
   return node;

}


bool isIdentical(struct TreeNode* r1 , struct TreeNode* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL || r2 == NULL){
        return false;
    }
    return  isIdentical(r1 -> left , r2 -> left) && isIdentical(r1 -> right , r2 -> right) && (r1 -> value == r2 -> value);
}

bool isMirrors(struct TreeNode* r1 , struct TreeNode* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL || r2 == NULL){
        return false;
    }
    return (r1 -> value== r2 -> value) && isMirrors(r1 -> left , r2 -> right) && isMirrors(r1 -> right , r2 -> left);
}


struct TreeNode* cloneTree(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    struct TreeNode* newnode = createNode(root -> value);
    newnode-> left = cloneTree(root -> left);
    newnode -> right = cloneTree(root -> right);
    return newnode;

}



int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->left = createNode(7);
    root->left->right = createNode(11);
    root->right->left = createNode(17);

 struct TreeNode *r2 = createNode(1);
    r2->left = createNode(2);
    r2->right = createNode(3);
    r2->left->left = createNode(4);


   struct TreeNode *r1 = createNode(1);
    r1->left = createNode(2);
    r1->right = createNode(3);
    r1->left->left = createNode(4);

     if (isIdentical(r1, r2))
        printf("Yes\n");
    else
        printf("No\n");




    printf("Preorder traversal of the binary tree:\n");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    struct TreeNode* parent = printparent(root, 11);
    if (parent) {
        printf("Parent of 11: %d\n", parent->value);
    } else {
        printf("Parent not found.\n");
    }

    int depth = treedepth(root);
    printf("Depth of tree: %d\n", depth);

    printf("Ancestors of 7: ");
    printancestors(root, 7);
    printf("\n");
    printf("%d" , countleaf(root));

     struct TreeNode* root = createtree();

    
    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");


 printf("Building the binary tree...\n");
    struct TreeNode* root = buildtree();

    printf("In-order Traversal: ");
    printInOrder(root);
    printf("\n");


printf("Building the original binary tree...\n");
    struct TreeNode* originalTree = buildtree();

    printf("In-order Traversal of Original Tree: ");
    printInOrder(originalTree);
    printf("\n");

    struct TreeNode* clonedTree = cloneTree(originalTree);

    printf("In-order Traversal of Cloned Tree: ");
    printInOrder(clonedTree);
    printf("\n");




   

   

 // Representation of input binary tree 1
    //        1
    //       / \
    //      3   2
    //          / \
    //         5   4
 struct TreeNode *root1 = createNode(1);
    root1->left = createNode(3);
    root1->right = createNode(2);
    root1->right->left = createNode(5);
    root1->right->right = createNode(4);

    // Representation of input binary tree 2 (mirror)
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct TreeNode *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (isMirrors(root1, root2))
        printf("true\n");
    else
        printf("false\n");

}
