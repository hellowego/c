#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int b=0;
    int e=0;
    int len=strlen(s);
    for(int i=0; i<=len; i++ )
    {
        if(s(i)==' ' || i==len)
        {
            b=e;
            e=i-1;
            for(j=b;j<=(e-b)/2;j++)
            {
                char tmp = s[b];
                s[b]=s[e];
                s[e]=tmp;
            }
        }
    }
    return s;
}

char *str[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
int cmp(const void *a, const void *b)
{
    const int *aa = (const int *)a;
    const int *bb = (const int *)b;
    return aa[0] - bb[0];
}
char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    int arr[scoreSize][2];
    *returnSize = scoreSize;
    for (int i = 0; i < scoreSize; i++)
    {
        arr[i][0] = -score[i];
        arr[i][1] = i;
    }
    qsort(arr, scoreSize, sizeof(arr[0]), cmp);
    char **ans = (char **)malloc(scoreSize * sizeof(char *));
    for (int i = 0; i < scoreSize; i++)
    {
        char *tmp = (char *)malloc(13 * sizeof(char));
        sprintf(tmp,"%d",i+1);
        if(i<3)
        {
            sprintf(tmp,"%s",str[i]);
        }else{
            sprintf(tmp,"%d",i+1);
        }
        printf("len: %d\n",strlen(tmp));
        ans[arr[i][1]]=tmp;

       
    }
    return ans;
}
int main()
{
    int arr[] = {10, 3, 8, 9, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // qsort(arr, n, sizeof(arr[0]), cmp);

    int *returnsize = (int *)malloc(sizeof(int));
    char **ans = findRelativeRanks(arr, 5, returnsize);
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", ans[i]);
    }
    printf("\n ");
    return 0;
}