#include <stdio.h>
#define M_PI 3.14159265358979323846

int main(void) {
    int D = 0;
    scanf("%d", &D);

    double d = D / 2.0;
    double answer = (double)d * d * M_PI;
    printf("%.10f\n", answer);
    
    return 0;
}
