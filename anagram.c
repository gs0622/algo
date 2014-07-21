#include <stdio.h>
#include <string.h>

int anagram(char str1[], char str2[])
{
    int i, yes, map1[128]={}, map2[128]={};
    for (i=0;i<strlen(str1);i++) map1[(int)str1[i]]++;
    for (i=0;i<strlen(str2);i++) map2[(int)str2[i]]++;
    for (i=0,yes=1;i<128;i++) {
        if (map1[i]!=map2[i]) {
            yes=0; break;
        }
    }
    return yes;
}

int main(int argc, char *argv[])
{
    if (3!=argc) return 0;
    printf("str1=%s\nstr2=%s\n", argv[1], argv[2]);
    printf("%s\n", anagram(argv[1], argv[2])?"yes":"no");
    return 0;
}

