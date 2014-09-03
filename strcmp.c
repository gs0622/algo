#include <stdio.h>
#include <string.h>

static int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) ++s1, ++s2; /*s1 found*/
    return *s1 - *s2;
}
int main(int argc, char *argv[])
{
    if (3 > argc) return 0;
    printf("strcmp   : %d\n", strcmp(argv[1], argv[2]));
    printf("my_strcmp: %d\n", my_strcmp(argv[1], argv[2]));
    return 0;
}

