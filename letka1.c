#include <stdio.h>
#include <math.h>


void main(){
    float x = 0.000000001;
    int neighbouringZero(float n);
    printf("is %f zero? %s\n", x, neighbouringZero(x) ? "Yes" : "No");
}


int nRoots(float a, float b, float c, float *x1, float *x2){
    int neighbouringZero(float n);
    if (neighbouringZero(a)){
        printf("Linear equation is not quadratic");
        return 0;
    }
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0){
        if (neighbouringZero(discriminant)){
            discriminant = 0;
        } else {
            printf("No roots, discriminant lesser than zero");
            return 0;
        }
    }
}


int neighbouringZero(float n){
    return fabs(n) <= 0.0000001;
}