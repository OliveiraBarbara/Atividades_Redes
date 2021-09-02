#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int qtdPacotes(int pacote){
	int pot2 = 1, i = 0;
	
	while(pacote > 0){
		pacote = pacote - pot2;
		pot2 = pot2 * 2;
		i++;
	}
	
	return i-1;
}

int main(void){
	int r, k, p, q, pp, n;
	float l, t, rtt, h, tempo;
	char s;
	
	scanf("%f %d %d %d", &t, &r, &p, &k);
	scanf(" %c", &s);
	
	switch(s){
		case 'A':
      		scanf("%f", &l);
      		
      		rtt = r / 2;
      		r = k * r;
      		rtt = (r + rtt);
      		rtt = rtt * pow(10, -3);
      		t = t * pow(10, 3);
			p = p * pow(10, 3);
			l = l * pow(10, 6);
      		tempo = ((t * p * 8)/l) + rtt;
      		
      		printf("Tempo de transmissão: %f\n", tempo);
		break;
		case 'B':
			scanf("%f", &l);
      		
      		rtt = r * pow(10, -3);
      		h = k * rtt;
      		pp = t / (p * pow(10,-3));
      		
      		tempo = (h + (rtt/2) + (rtt * (pp-1)) + (t*8 / l));
      		      		
      		printf("Tempo de transmissão: %f\n", tempo);
		break;
		case 'C':
			scanf("%d", &q);
			
			rtt = ((k + 0.5 + (((p*1000)/q)-1)) * r)/1000;
			  
			printf("Tempo de transmissão: %f\n", rtt);
		break;
		case 'D':
			rtt = r * pow(10, -3);
      		h = k * rtt;
      		pp = t / (p * pow(10,-3)) - 1;
      		
      		n = qtdPacotes(pp);
      		
      		tempo = h + (n * rtt) + (rtt/2); 
      		
      		printf("Tempo de transmissão: %f\n", tempo);
		break;
	}
	
	return 0;
}
