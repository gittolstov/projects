#include <stdio.h>
#include <math.h>

int neighbouringZero(double n);
int nRoots(double a, double b, double c, double *x1, double *x2);

int main(){
    double x1 = 0, x2 = 0, a = 0, b = 0, c = 0;

    scanf("%lf %lf %lf", &a, &b, &c);

    int tst = 0;
    tst = nRoots(a, b, c, &x1, &x2);
    switch (tst){
        case -1:{
            printf("The inputed equation: (%g)x^2 + (%g)x + (%g) = 0\nhas infinite solutions: x can be any number\n", a, b, c);
            break;
        }
        case 1:{
            printf("The inputed equation: (%g)x^2 + (%g)x + (%g) = 0\nhas 1 solution: %g\n", a, b, c, x1);
            break;
        } 
        case 2:{
            printf("The inputed equation: (%g)x^2 + (%g)x + (%g) = 0\nhas 2 solutions: %g, %g\n", a, b, c, x1, x2);
            break;
        }
        default:{
            printf("The inputed equation: (%g)x^2 + (%g)x + (%g) = 0\nhas no solutions. D < 0\n", a, b, c);
            break;
        }
    }
    return 1;
}


//a, b, c - coefficients of a quadratic equation. x1, x2 - pointers to vars for roots
int nRoots(double a, double b, double c, double *x1, double *x2){
    double discriminant = 0.0;
    if (neighbouringZero(a)){
        //printf("Linear equation is not quadratic");
        if (neighbouringZero(b)){
            if (neighbouringZero(c)){// x is anything
                *x1 = *x2 = 0;
                return -1;
            }
            *x1 = *x2 = 0;
            return 0;
        }
        *x1 = *x2 = -c / b;
        return 1;
    }

    discriminant = b * b - 4 * a * c;
    if (neighbouringZero(discriminant)){
        *x1 = *x2 = -b / 2 / a;
        return 1;
    }
    if (discriminant < 0){
        *x1 = *x2 = 0;
        return 0;
    }
    *x1 = (-b - sqrt(discriminant)) / 2 / a;
    *x2 = (-b + sqrt(discriminant)) / 2 / a;
    return 2;
}


int neighbouringZero(double n){
    return (fabs(n) <= 1e-5);
}