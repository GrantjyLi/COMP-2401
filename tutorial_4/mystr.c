#include "mystr.h"

int myStrCmp(char *s1, char *s2){
    if(*s1 != '\0' && *s2 != '\0' && *s1 == *s2){
       
        return myStrCmp(++s1, ++s2);
    }

    if(*s1 < *s2){
        return -1;
    }else{
        return (*s1 > *s2);
    }
}