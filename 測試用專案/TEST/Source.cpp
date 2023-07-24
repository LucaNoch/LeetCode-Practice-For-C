#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 副程式定義
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}



int main() {
    int nums1[] = { 1, 2, 3, 0, 0, 0 };
    int m = 3;
    int nums2[] = { 2, 5, 6 };
    int n = 3;
    int nums1Size = 6;
    int nums2Size = 3;

    printf("原始 nums1 陣列: ");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("原始 nums2 陣列: ");
    for (int i = 0; i < nums2Size; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printf("合併後的 nums1 陣列: ");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}