#include <stdio.h>

 struct person {
    int age;
    char gender; 
} Morris, Apk ;

int main(int argc, char const *argv[])
{
    Morris.gender = 'M'; 
    Morris.age = 2; 

    printf("%d\n\t %c", Morris.age, Morris.gender); 
    
    struct person *pointToApk = &Apk; 
    pointToApk -> gender = 'f'; 
    pointToApk -> age = 3; 

    printf("%d\n\t %c\n", pointToApk->age, pointToApk->gender);
    return 0;
}
