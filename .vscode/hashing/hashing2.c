#include<stdio.h>
void main()
{
    int n,h;
    printf("\nEnter the Size of the Array\n");
    scanf("%d",&n);
    h=prime(n);
    //printf("/n Next Prime: %d",h);
    linprob(h,n);
}

int prime(int n)
{
    //printf("hi");
    int i,np=0;
    i=n;
    while(i>=n)
    {

        for(int j=2;j<i;j++)
        {
           // printf("hi");
            if(i%j==0)
            {
                np=1;
                //printf("shi");
                break;
            }
        }

        if(np==0)
        {
            return i;
        }
        else
        {
            np=0;
            i++;
        }
    }
}

void linprob(int h, int n)
{
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=NULL;
    }
    int j,k;
    printf("Enter The Values:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        j=k%h;
        while(j>=n)
        {
            j=j-n;
        }
        while(a[j]!=NULL)
        {
            if(j==n-1)
            {
                j=0;
            }
            else
            {
                j++;
            }
        }
        a[j]=k;
    }

    display(a,n);

}

void display(int a[],int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}