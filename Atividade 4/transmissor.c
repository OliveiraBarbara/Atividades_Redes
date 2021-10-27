#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1500

void hexaTobin(char *hexa, int *protocol){
	int i;
	
	for(i=0; i<4; i++){
		if(hexa[i] == '0'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 0;
	    }else if(hexa[i] == '1'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 1;
	    }else if(hexa[i] == '2'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 0;
	    }else if(hexa[i] == '3'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 1;
	    }else if(hexa[i] == '4'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 0;
	    }else if(hexa[i] == '5'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 1;
	    }else if(hexa[i] == '6'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 0;
	    }else if(hexa[i] == '7'){
			protocol[(i*4)] = 0;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 1;
	    }else if(hexa[i] == '8'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 0;
	    }else if(hexa[i] == '9'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 1;
	    }else if((hexa[i] == 'A')||(hexa[i])=='a'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 0;
	    }else if((hexa[i] == 'B')||(hexa[i])=='b'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 0;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 1;
	    }else if((hexa[i] == 'C')||(hexa[i])=='c'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 0;
	    }else if((hexa[i] == 'D')||(hexa[i])=='d'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 0;
			protocol[(i*4)+3] = 1;
	    }else if((hexa[i] == 'E')||(hexa[i])=='e'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 0;
	    }else if((hexa[i] == 'F')||(hexa[i])=='f'){
			protocol[(i*4)] = 1;
			protocol[(i*4)+1] = 1;
			protocol[(i*4)+2] = 1;
			protocol[(i*4)+3] = 1;
		}
	}
}



void charTobinary(char *str, int n, int bin[MAX][8]){
	int i, j, valor;

	for(i = 0; i<n; i++){
		valor = str[i];
		if(valor != -61){
			if(valor < 0)
				valor = valor + 255;
			j=7;
			while(valor != 0){
				bin[i][j] = valor % 2;
				j--;
				valor = valor/2;
			}
			if(j != -1){
				while(j>=0){
					bin[i][j] = 0;
					j--;
				}
			}
		}
	}
}

void concatenation(int *vec1, int *vec2, int *concat){
	int i;
	
	for(i=0; i<8; i++){
		concat[i] = vec1[i];
		concat[i+8] = vec2[i];
	}
}

int sum(int *vec1, int *vec2, int *resp){
	int i, goOne=0;
	
	for(i=15; i>=0; i--){
		if((vec1[i] == 0 && vec2[i] == 0)){
			if(goOne == 1)
				resp[i] = 1;
			else
				resp[i] = 0;	
			goOne = 0;
		}else if((vec1[i] == 1 && vec2[i] == 0) || (vec1[i] == 0 && vec2[i] == 1)){
			if(goOne == 1){
				resp[i] = 0;
				goOne = 1;
			}else{
				resp[i] = 1;
				goOne = 0;
			}
		}else if(vec1[i] == 1 && vec2[i] == 1){
			if(goOne == 1){
				resp[i] = 1;
				goOne = 1;
			}else{
				resp[i] = 0;
				goOne = 1;
			}
		}
	}
	return goOne;
}

void join(int *resp, int *x){
	int i;

	for(i=0; i<16; i++)
		resp[i] = x[i];	
}

void comp1(int *resp, int *check, int goOne){
	int v1[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	
	if(goOne == 1)
		sum(resp, v1, check);
	else
		join(check, resp);
}

void comp(int *resp, int *check){
	int i;
	
	for(i=15; i>=0; i--){
		if(resp[i] == 1)
			check[i] = 0;
		else
			check[i] = 1;
	}
}

void vectorZero(int bin[MAX][8], int n){
	int i;
	
	for(i=0; i<8; i++)
		bin[n][i] = 0;
}

int stuffing_flag(int *bin, int *flag){
	int i, aux=0;
	
	for(i=0; i<8; i++){
		if(bin[i] != flag[i])
			aux = 1;
	}	
	if(aux == 0)
		return 1;
	else
		return 0;
}

int stuffing_escape(int *bin){
	int i, aux=0;
	int escape[8] = {0,1,1,1,1,1,0,1};
	
	for(i=0; i<8; i++){
		if(bin[i] != escape[i])
			aux = 1;
	}	
	if(aux == 0)
		return 1;
	else
		return 0;
}

void write(int *vec, int sep){
	int i;
	
	for(i=0; i<8; i++)
		printf("%d", vec[i]);
	
	printf(" ");
	
	if(sep == 1){
		for(i=8; i<16; i++)
			printf("%d", vec[i]);
		
		printf(" ");
	}
}

int main(){
	char m[MAX], p[4];
	int n=0, i, j, goOne=0, n_aux, concat[16], bin[MAX][8], check[16], protocol[16], adControl[16], checksum[16], resp[16], x[16];
	int flag[8] = {0,1,1,1,1,1,1,0};
	int adress[8] = {1,1,1,1,1,1,1,1};
	int control[8] = {0,0,0,0,0,0,1,1}; 
	
	scanf("%s ", p);
		
	scanf("%[^\n]s", m);

	n = strlen(m);
	
	n_aux = n;
	if(n%2 != 0){
		n_aux++;
		vectorZero(bin, n);
	}
	
	hexaTobin(p, protocol);
	
	charTobinary(m, n, bin);
	
	concatenation(adress, control, adControl);
	
	goOne = sum(adControl, protocol, check);
	
	comp1(check, resp, goOne);
	
	for(i=0; i<n_aux; i=i+2){
		concatenation(bin[i], bin[i+1], concat);
		goOne = sum(resp, concat, x);
		comp1(x, resp, goOne);
	}
	
	comp(resp, checksum);
	
	write(flag, 0);
	
	write(adress, 0);
	
	write(control, 0);
	
	write(protocol, 1);
		
	for(j=0; j<n; j++){
		if(stuffing_flag(bin[j], flag) == 1 || stuffing_escape(bin[j]) == 1)
			printf("01111101 ");
		write(bin[j], 0);
	}
	
	write(checksum, 1);
	
	write(flag, 0);
	
	return(0);
}
