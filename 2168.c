#include <stdio.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int rua[n+1][n+1];
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            scanf("%d", &rua[i][j]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(rua[i][j]+rua[i][j+1]+rua[i+1][j]+rua[i+1][j+1] < 2)
                printf("U");
            else printf("S");
        }
        printf("\n");
    }

    return 0;
}
