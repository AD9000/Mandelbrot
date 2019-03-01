#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;
    while (i < 50)
    {
        printf("%f\n", pow(2, -i));
    }
    
    return 0;
}
