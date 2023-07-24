/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0)
        return NULL;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    int n = numsSize / 2;
    root->val = nums[n];
    root->left = sortedArrayToBST(nums, n);
    root->right = sortedArrayToBST(nums + n + 1, numsSize - n - 1);
    return root;
}