#include <stdio.h>
#define PI 3.14

int main(int argc, char const *argv[])
{
    double area = 0.00, radius = 0.00;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = PI * radius * radius; 
    printf("The radius of the circle is %lf; the area of the circle is %lf sq. meters \n", radius, area);
    return 0;
}
