#include <stdio.h>
#include <math.h>
#include <assert.h>

void moveBodyRukaBoga(double *x, double *y, double vx, double vy, double dt);


int main(){
	double x = 100, y = 100;
	double vx = 7, vy = 5;
	double dt = 1;
	while (x < 1000){
		printf("x = %lf, y = %lf\n", x, y);
		moveBodyRukaBoga(&x, &y, vx, vy, dt);
		printf("x = %lf, y = %lf\n\n", x, y);
	}
	return 1;
}


void moveBodyRukaBoga(double *x, double *y, double vx, double vy, double dt){
	*x += dt * vx;
	*y += dt * vy;
}