#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_a, const void *_b)
{
    int *a = (int *)_a, *b = (int *)_b;
    return *a == *b ? 0 : *a > *b ? 1
                                  : -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    printf("len:  %lu\n", sizeof(nums1) / sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int index1 = 0, index2 = 0;
    *returnSize = 0;
    int lenIntersect = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *intersection = (int *)malloc(lenIntersect * sizeof(int));
    printf("len1:  %d\n", (int)sizeof(nums2));
    printf("len:  %d\n", (int)sizeof(intersection) / (int)sizeof(int));
    while (index1 < nums1Size && index2 < nums2Size)
    {
        if (nums1[index1] > nums2[index2])
        {
            index2++;
        }
        else if (nums1[index1] < nums2[index2])
        {
            index1++;
        }
        else
        {
            intersection[(*returnSize)++] = nums1[index1];
            index1++;
            index2++;
        }
    }
    // num3 = (int *)malloc((index + 1) * sizeof(int));
    // memcpy(res, intersection, index * sizeof(int));
    // free(intersection);
    // printf("len:  %d\n", (int)sizeof(intersection) / (int)sizeof(int));
    // for (int i = 0; i < lenIntersect; i++)
    // {
    //     printf("%d   ", intersection[i]);
    // }
    return intersection;
}

int main()
{
    int nums1[] = {1, 2, 3, 1};
    int nums2[] = {2, 3, 5};
    printf("len:  %lu\n", sizeof(nums1) / sizeof(int));
    int *nums3;
    int *res = intersect(nums1, 4, nums2, 2, nums3);

    printf("hello world");
    return 0;
}