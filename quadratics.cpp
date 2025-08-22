#include <stdio.h>
#include <math.h>
#include <assert.h>

int neighbouringZero(double n);
int nRoots(double a, double b, double c, double *x1, double *x2);
void adequacyCheck(double *root);
int getInputNumber(double *n);

int main(){
    double a = NAN, b = NAN, c = NAN;
    double *list[] = {&a, &b, &c};
    int i = 0;
    while (i < 3){
        if (getInputNumber(list[i])){//if number is received -> TRUE
            i++;
        }
    }

    int amount_roots = 0;
    double x1 = NAN, x2 = NAN;
    amount_roots = nRoots(a, b, c, &x1, &x2);
    assert(!isnan(x1));
    assert(!isnan(x2));
    printf("The inputed equation: (%lg)x^2 + (%lg)x + (%lg) = 0\n", a, b, c);
    assert(!isnan(x1));
    assert(!isnan(x2));
    switch (amount_roots){
        case -1:{
            printf("has infinite solutions: x can be any number\n");
            break;
        }
        case 1:{
            printf("has 1 solution: %lg\n", x1);
            break;
        }
        case 2:{
            printf("has 2 solutions: %lg, %lg\n", x1, x2);
            break;
        }
        default:{
            printf("has no solutions. D < 0\n");
            break;
        }
    }
    return 1;
}


int getInputNumber(double *n){//returns 1 if correct arg or 0 if not;
    assert(n != NULL);
    char check = '\n';
    int amount = scanf("%lf%c", n, &check);
    if (check != '\n' || amount != 2){
        printf("Incorrect character %c\n", (check != '\n') ? check : ' ');
        check = ' ';
        while (check != '\n'){
            scanf("%c", &check);
        }
        return 0;
    }
    printf("number accepted: (%lg)\n", *n);
    return 1;
}


void adequacyCheck(double *root){
    assert(root != NULL);
    *root = (neighbouringZero(*root)) ? 0 : *root;
}


//a, b, c - coefficients of a quadratic equation. x1, x2 - pointers to vars for roots
int nRoots(double a, double b, double c, double *x1, double *x2){
    double discriminant = NAN;
    if (neighbouringZero(a)){
        if (neighbouringZero(b)){
            if (neighbouringZero(c)){// x is anything
                *x1 = *x2 = 0;
                return -1;
            }
            *x1 = *x2 = 0;
            return 0;
        }
        *x1 = *x2 = -c / b;
        adequacyCheck(x1);
        adequacyCheck(x2);
        return 1;
    }

    discriminant = b * b - 4 * a * c;
    assert(!isnan(discriminant));
    if (neighbouringZero(discriminant)){
        *x1 = *x2 = -b / 2 / a;
        adequacyCheck(x1);
        adequacyCheck(x2);
        return 1;
    }
    if (discriminant < 0){
        *x1 = *x2 = 0;
        return 0;
    }
    *x1 = (-b - sqrt(discriminant)) / 2 / a;
    *x2 = (-b + sqrt(discriminant)) / 2 / a;
    adequacyCheck(x1);
    adequacyCheck(x2);
    return 2;
}


int neighbouringZero(double n){
    return (fabs(n) <= 1e-5);
}