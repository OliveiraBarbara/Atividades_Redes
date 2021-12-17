#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80 

int binary(int valor_real){
	int bin = 0, p = 1, r;

	while(valor_real != 0){
		r = valor_real % 2;
		bin = (r * p) + bin;
		p = p * 10;
		valor_real = valor_real/2;
	}
	printf("%d", bin);
	return bin;
}

void charForint(char *str, int n, int *bin){
	int valor[MAX], i;
	
	for(i=0; i<n; i++){
		valor[i] = str[i];
		bin[i] = binary(valor[i]);	
	}
}


void nrz(int *bin, int n){
	char resp[8];
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=7; j>=0; j--){
			if(bin[i]%10 == 1){
				resp[j] = 'A';
			}else{
				resp[j] = 'B';
			}
			bin[i] = bin[i]/10;
		}
		printf("%s", resp);
	}
	
}

void manches(int *bin, char k, int n){
	char resp[16];
	int i, j;

	for (i=0; i<n; i++) {
		for (j=16; j>0; j = j-2) {
			if(bin[i]%10 == 1 && k == 'A'){
				resp[j-2] = 'B';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 0 && k == 'A'){
				resp[j-2] = 'A';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 1 && k == 'B'){
				resp[j-2] = 'A';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 0 && k == 'B'){
				resp[j-2] = 'B';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}
			if(bin[i]%10 == 1 && k == 'A'){
				resp[j-1] = 'B';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 0 && k == 'A'){
				resp[j-1] = 'A';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 1 && k == 'B'){
				resp[j-1] = 'A';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}else if(bin[i]%10 == 0 && k == 'B'){
				resp[j-1] = 'B';
				if(k == 'A')
					k = 'B';
				else if(k == 'B')
					k = 'A';
			}

			bin[i] = bin[i]/10;
		}

		for (j = 0; j < 16; j++) {
			printf("%c", resp[j]);
		}
	}
}

int main(){
	char c[MAX], m[MAX], k;
	int n=0, bin[MAX];
	
	scanf("%s ", c);
		
	if(strcmp("NRZ", c) == 0){
		scanf("%[^\n]s", m);
		n = strlen(m);
		
		printf("%s %d ", c, n*8);
		charForint(m, n, bin);
		nrz(bin, n);		
	}
	
	else if(strcmp("Manchester", c) == 0){
		scanf("%c ", &k);
		scanf("%[^\n]s", m);

		n = strlen(m);

		printf("%s %c %d ", c, k, n*16);

		charForint(m, n, bin);
		manches(bin, k, n);
	}

	return(0);
}
