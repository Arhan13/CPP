#include<stdio.h>

int main()
{
    int t,n,i;
    float s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=0;
        for(i=1;i<=n;i++)
            s= s+ (float)1/(i);
        s=(float)(s*n);
        printf("%.2f\n",s);
    }



    return 0;
}