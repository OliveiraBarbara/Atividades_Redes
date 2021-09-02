#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 640

int bin_int(int bin){
	int potenc = 1, total = 0;
	
	while(bin > 0) {
	   total += bin % 10 * potenc;
	   bin /= 10;
	   potenc *= 2;
	}

	return total;	
}

void nrz(int n, char *m){
	int i, j, num, dec, pot, bin[MAX];
	num = 0;	
	n = n/8;
	
	for (i = 0; i < n; i++) {
		num = 0;
		pot = 10000000;
		for (j = 0; j < 8; j++) {
			if(m[(i*8)+j] == 'A'){
				num = num + pot;
			}else if(m[(i*8)+j] == 'B'){
				num = num + 0;
			}
			pot = pot / 10;
		}
		bin[i] = num;		
	}
	for(j = 0; j < n; j++){
		dec = bin_int(bin[j]);
		printf("%c ", dec);
	}	
}

void manchester(int n, char *m, char k){
	int i, j, num, dec[MAX], pot, bin[MAX];
	num = 0;
	
	for (i = 0; i < n / 16; i++) {
		num = 0;
		pot = 10000000;
		for (j = 0; j < 16; j++) {
			if(((i*16)+j) % 2 == 0){
				if(m[(i*16)+j] == 'A'){
					if(k == 'A')
						num = num + 0;
					else if(k == 'B')
						num = num + pot;
				}else if(m[(i*16)+j] == 'B'){
					if(k == 'A')
						num = num + pot;
					else if(k == 'B')
						num = num + 0;
				}
				pot = pot / 10;
			}
		}
		bin[i] = num;
		
	}
	for(j=0; j<n/16; j++){
		dec[j] = bin_int(bin[j]);
		printf("%c", dec[j]);
	}	
}

int main(){
	char c[MAX], m[MAX], k;
	int n;
	
	scanf("%s ", c);
		
	if(strcmp("NRZ", c) == 0){
		scanf("%d ", &n);
		scanf("%[^\n]s", m);
		
		nrz(n, m);		
	}
	
	else if(strcmp("Manchester", c) == 0){
		scanf("%c ", &k);
		scanf("%d ", &n);
		scanf("%[^\n]s", m);
		
		manchester(n, m, k);
	}

	return(0);
}
