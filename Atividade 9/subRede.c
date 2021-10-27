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

int mascara(int maxHost){
	int pot2 = 1, i = 0;
	
	while(maxHost > 0){
		maxHost = maxHost - pot2;
		pot2 = pot2 * 2;
		i++;
	}
	
	return i;
}

int main(void){
	int cp1, cp2, cp3, cp4, qtdHost;
	int bcp1, bcp2, bcp3, bcp4, masc;
	
	scanf("%d.%d.%d.%d %d", &cp1, &cp2, &cp3, &cp4, &qtdHost);
	bcp1 = binary(cp1);
	bcp2 = binary(cp2);
	bcp3 = binary(cp3);
	bcp4 = binary(cp4);
	
	masc = mascara(qtdHost);
	printf("%d\n", masc);
	
	printf("Endereço informado: %d.%d.%d.%d (%08d %08d %08d %08d)\n", cp1, cp2, cp3, cp4, bcp1, bcp2, bcp3, bcp4);
	printf("Máscara da sub-rede: 255.255.255.0 (11111111 11111111 11111111 00000000)\n");
	printf("Endereço da sub-rede: 192.168.0.0 (11000000 10101000 00000000 00000000)\n");
	printf("End. broadcast da sub-rede: 192.168.0.255 (11000000 10101000 00000000 11111111)\n");
	return(0);

}
