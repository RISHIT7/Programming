#include <stdio.h>
#include <string.h>

int main()
{
    char name[3] = {'m', 'y', '\0'};
    char str1[65], str2[98], str3[32];
    strcpy(str1, name);
    strcpy(str2, "Rohan");
    strcat(str1, str2);
    printf("%s", str1);
    return 0;
}