#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int bin_int(int bin){
	int potenc = 1, total = 0;
	
	while(bin > 0) {
	   total += bin % 10 * potenc;
	   bin /= 10;
	   potenc *= 2;
	}

	return total;	
}

int mascara(int maxHost){
	int pot2 = 1, i = 0;
	
	while(maxHost > 0){
		maxHost = maxHost - pot2;
		pot2 = pot2 * 2;
		i++;
	}
	
	return i;
}

void subRede(int aux, int *mascBin, int *mascDec){
	int i, j, num, cont=1, pot;
	
	for(i=0; i<4; i++) {
		num = 0;
		pot = 10000000;
		for (j=0; j<8; j++) {
			if(aux >= cont){
				num = num + pot;
				cont++;
			}else
				num = num + 0;
			pot = pot / 10;
		}
		mascBin[i] = num;		
	}
	
	for(j=0; j<4; j++)
		mascDec[j] = bin_int(mascBin[j]);
}

void endSubRede(int *ipBin, int *mascBin, int *endBin, int *endDec){
	int i, j, auxIP, auxI, auxM, auxMasc, num, pot;
	
	for(i=0; i<4; i++) {
		num = 0;
		pot = 10000000;
		auxIP = ipBin[i];
		auxMasc = mascBin[i];
		for (j=0; j<8; j++){
			auxI = auxIP / pot;
			auxM = auxMasc / pot;
			if(auxI == 1 && auxM == 1)
				num = num + pot;
			else
				num = num + 0;
			auxIP = auxIP % pot;
			auxMasc = auxMasc % pot;
			pot /= 10;
		}
		endBin[i] = num;		
	}
	
	for(j=0; j<4; j++)
		endDec[j] = bin_int(endBin[j]);
}

void broadcast(int *ipBin, int *mascBin, int *broadBin, int *broadDec){
	int i, j, auxIP, auxI, auxM, auxMasc, num, pot;
	
	for(i=0; i<4; i++) {
		num = 0;
		pot = 10000000;
		auxIP = ipBin[i];
		auxMasc = mascBin[i];
		for (j=0; j<8; j++){
			auxI = auxIP / pot;
			auxM = auxMasc / pot;
			if(auxI == 1 || auxM == 0)
				num = num + pot;
			else
				num = num + 0;
			auxIP = auxIP % pot;
			auxMasc = auxMasc % pot;
			pot /= 10;
		}
		broadBin[i] = num;		
	}
	
	for(j=0; j<4; j++)
		broadDec[j] = bin_int(broadBin[j]);
}

void imprime(int *vec1, int *vec2){
	int i;
	
	for(i=0; i<4; i++){
		printf("%d", vec1[i]);
		if(i<4-1)
			printf(".");
	}
	
	printf(" (");
	for(i=0; i<4; i++){
		printf("%08d", vec2[i]);
		if(i<4-1)
			printf(" ");
	}
	printf(")\n");
}

int main(void){
	char ip[36], *ipDiv;
	int i, ipDec[4], qtdHost, auxMasc, ipBin[4], mascBin[4], mascDec[4], endBin[4], endDec[4], broadBin[4], broadDec[4]; 
	
	scanf("%s %d", ip, &qtdHost);
	
	ipDiv = strtok(ip, ".");
	for(i = 0; i < 4; i++){
		ipDec[i] = atoi(ipDiv);
		ipDiv = strtok(NULL, ".");
	}
	
	for(i = 0; i<4; i++)
		ipBin[i] = binary(ipDec[i]);
		
	auxMasc = mascara(qtdHost);
	auxMasc = 32 - auxMasc;
	
	subRede(auxMasc, mascBin, mascDec);
	
	endSubRede(ipBin, mascBin, endBin, endDec);
	
	broadcast(ipBin, mascBin, broadBin, broadDec);
	
	printf("Endereço informado: ");
	imprime(ipDec, ipBin);
	printf("Máscara da sub-rede: ");
	imprime(mascDec, mascBin);
	printf("Endereço da sub-rede: ");
	imprime(endDec, endBin);
	printf("End. broadcast da sub-rede: ");
	imprime(broadDec, broadBin);
	
	return(0);
}
