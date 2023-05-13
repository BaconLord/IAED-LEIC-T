#include <stdio.h>
 int main(){
    char c;
    while ((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z'){
            c += 'a'- 'A';
            putchar(c);
        }
        else{
            putchar(c);
        }
    };
    return 0;
 }    