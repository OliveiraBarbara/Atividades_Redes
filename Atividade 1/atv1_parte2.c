#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int bin_int(int bin){
	int potenc = 1, total = 0;
	
	while(bin > 0) {
	   total += bin % 10 * potenc;
	   bin = bin / 10;
	   potenc = potenc * 2;
	}
	return total;	
}


int main(void){
	char bin[MAX], vetor[MAX][MAX];
	int i, k, j, dec[MAX], num[MAX];
	
	scanf("%d", &i);
	
	k = bin_int(i);
	
	for(j=0;j<k;j++){
		scanf("%d", &num[j]);
	}
	for(i=0;i<k;i++){
		dec[i] = bin_int(num[i]);
		printf("%c", dec[i]);
	}
}

