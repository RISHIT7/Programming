#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *path = "Text.txt";
    FILE *file = fopen(path, "r");
    if (!file)
    {
        printf("Could not open the file %s", path);
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buf = (char *)malloc(sizeof(char) * (size + 1)); // alloccating memory for the output file
    fread(buf, 1, size, file);
    buf[size] = '\n';

    

    return 0;
}