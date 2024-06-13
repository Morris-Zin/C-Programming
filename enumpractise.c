#include <stdio.h>

enum days {monday, tuesday, wednesday, thursday, friday, saturday,sunday}; 
typedef enum days day;


int main(int argc, char const *argv[])
{
    enum days day = monday; 
    printf("%d", day);
    return 0;
}
