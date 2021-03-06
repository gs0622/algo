#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) ++s1, ++s2; /*s1 found*/
    return *s1 - *s2;
}

static int my_strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 && (*s1 == *s2) & (n-- > 1)) ++s1, ++s2; /*s1 found*/
    return *s1 - *s2;
}

static int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1 && ((*s1 == *s2) || ((*s1 ^ 0x20) == *s2))) ++s1, ++s2;
    return *s1 - *s2;
}

int main(int argc, char *argv[])
{
    if (4 > argc) return 0;
    printf("s1=%s s2=%s\n", argv[1], argv[2]);
    printf("strcmp       : %d\n", strcmp(argv[1], argv[2]));
    printf("my_strcmp    : %d\n", my_strcmp(argv[1], argv[2]));
    printf("strncmp      : %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
    printf("my_strncmp   : %d\n", my_strncmp(argv[1], argv[2], atoi(argv[3])));
    printf("strcasecmp   : %d\n", strcasecmp(argv[1], argv[2]));
    printf("my_strcasecmp: %d\n", my_strcasecmp(argv[1], argv[2]));
    return 0;
}

