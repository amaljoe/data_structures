int x=0;

void main()
{
    int n;
    printf("Enter the Size of the Array\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }

    printf("The unsorted array is:\n");
    for(int i=0;i<n;++i)
    {
        printf("%d\t",a[i]);
    }

    mergesort(a,n);

    printf("The sorted array is:\n");
    for(int i=0;i<n;++i)
    {
        printf("%d\t",a[i]);
    }
}



void mergesort(int a[],int n)
{
    printf("hi\n");
    if(n==1)
    {
        return;
    }
    else
    {
        int m,i=0,j=0;
        if(n%2==0)
        {
            m=(n/2);
        }
        else
        {
            m=(n/2)+1;
        }

        int b[m],c[(n-m)];

        for(i=0;i<m;++i)
        {
            b[i]=a[i];
        }

        printf("here\n");
    for(int i=0;i<m;++i)
        {
            printf("%d\t",b[i]);
        }
    printf("heredone\n");

        for(i=m+1;i<n;++i)
        {
            c[j]=a[i];
            ++j;
        }

        mergesort(b,m);
        mergesort(c,n-m);

        merge(a,b,c,n,m);

        /*printf("%d\t",++x);

        for(int i=0;i<n;++i)
        {
            printf("%d\t",a[i]);
        }

        printf("\n");*/

    }
}

void merge(int a[],int b[],int c[], int n,int m)
{

    int i=0,j=0,k=0;

    /*printf("here\n");
    for(int i=0;i<n;++i)
        {
            printf("%d\t",b[i]);
        }
    printf("heredone\n");*/

    while((k<n-m)&&(j<m))
    {
        if(b[j]<c[k])
        {
            a[i]=b[j];
            printf("%d\n",a[i]);
            i++;
            j++;

        }
        else
        {
            a[i]=c[k];
            printf("%d\n",a[i]);
            i++;
            k++;
        }
    }

    while(j<m)
    {
        a[i]=b[j];
        printf("%d\n",a[i]);
        i++;
        j++;
    }

    while(k<(n-m))
    {
        a[i]=c[k];
        printf("%d\n",a[i]);
        i++;
        k++;
    }

    printf("\n");
}