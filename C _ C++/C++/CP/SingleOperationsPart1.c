#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l, count = 0;
        scanf("%d",&l);
        char str[l];
        scanf("%s",str);
        for(int i = 0;str[i]!='\0';i++)
        {
            if(str[i]=='1')
            {
                count++;
            }
            else{
                
                break;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}