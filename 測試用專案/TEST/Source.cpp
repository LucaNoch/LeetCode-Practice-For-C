#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Ƶ{���w�q
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

    printf("��l nums1 �}�C: ");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("��l nums2 �}�C: ");
    for (int i = 0; i < nums2Size; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printf("�X�᪺֫ nums1 �}�C: ");
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}