#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int d, v, t;
	double l, rp, tt;

	scanf("%d %d %d", &d, &v, &t);

	d = d * pow(10, 3);
	rp = d / v;
	t = t * 8;
	tt = t * pow(10, -6);
	l = tt / rp;

	printf("O tempo de transmissão será equivalente ao retardo de propagação na largura de banda %.2fMbps.", l);
    
    
    return 0;
}
