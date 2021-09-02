#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80 

void * inteiro(char *str, int n, int *bin){
	int valor[MAX], i;
	
	for(i = 0; i<n; i++){
		valor[i] = str[i];
		bin[i] = binary(valor[i]);
	}
}

int binary(int valor_real){
	int bin = 0, p = 1, r;

	while(valor_real != 0){
		r = valor_real % 2;
		bin = (r * p) + bin;
		p*=10;
		valor_real = valor_real/2;
	}
	return bin;
}

int main(void){
	char str[MAX];
	int i, n=0, bin[MAX], n_bin;
	
	scanf("%[^\n]s", str);
	
	n = strlen(str);
	
	inteiro(str, n, bin);
	
	n_bin = binary(n);
	printf("%d ", n_bin);
	
	for(i = 0; i<n; i++){
		printf("%d ", bin[i]);
	}

	return(0);

}
