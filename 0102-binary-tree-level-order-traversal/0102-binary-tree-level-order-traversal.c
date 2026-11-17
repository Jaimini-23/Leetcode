/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #define max 2000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode* q[max];
    int front = 0, rear = 0;
    q[rear++] = root;

    int** result = (int**)malloc(max * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max * sizeof(int));
    int levelCount = 0;
    while(front < rear) {
        int levelSize = rear - front;
        result[levelCount] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[levelCount] = levelSize;
        for(int i = 0; i < levelSize; i++) {
            struct TreeNode* current = q[front++];
            result[levelCount][i] = current->val;

            if(current->left) q[rear++] = current->left;
            if(current->right) q[rear++] = current->right;
        }
        levelCount++;
    }
    *returnSize = levelCount;
    return result;
}