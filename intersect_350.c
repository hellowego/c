#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_a, const void *_b)
{
    int *a = _a, *b = (int *)_b;
    return *a == *b ? 0 : *a > *b ? 1
                                  : -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    for (int i = 0; i < nums1Size; i++)
    {
        printf("%d   ", nums1[i]);
    }
}

int main()
{
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int *nums3;
    int *res = intersect(nums1, 4, nums2, 2, nums3);

    printf("hello world");
    return 0;
}