# Atividades_Redes
Todas as atividades relacionadas a disciplina de Redes de Computadores.

##  Atividade 1
###  Parte  1
Pilha de Protocolos - Transmissor: programa que implementam uma comunicação ponto a ponto entre dois nós, empregando organização de camadas e protocolos. O enlace (meio físico) dessa conexão simulada será a saída padrão.

Exemplo de mensagem:
Tres tigres tristes.

Em decimal:
84 114 101 115 32 116 105 103 114 101 115 32 116 114 105 115 116 101 115 46

Em binário:
1010100 1110010 1100101 1110011 100000 1110100 1101001 1100111 1110010 1100101 1110011 100000 1110100 1110010 1101001 1110011 1110100 1100101 1110011 101110

###  Parte  2
Pilha de Protocolos - Receptor: programa que implementam uma comunicação ponto a ponto entre dois nós, empregando organização de camadas e protocolos. O enlace (meio físico) dessa conexão simulada será a saída padrão. 

A mensagem recebida tem formato de sequência de números binários e deve ser lida pelo programa receptor pela entrada padrão.

Exemplo de mensagem:
1010100 1110010 1100101 1110011 100000 1110100 1101001 1100111 1110010 1100101 1110011 100000 1110100 1110010 1101001 1110011 1110100 1100101 1110011 101110

Em decimal:
84 114 101 115 32 116 105 103 114 101 115 32 116 114 105 115 116 101 115 46

String original:
Tres tigres tristes.

##  Atividade 2
### Parte 1 - Tempo de transferência de arquivo
Programa que calcula o tempo total necessário (valor real, em segundos) para transferir um arquivo de tamanho t (valor real, em MB) em algumas situações.  Considere um RTT r (valor inteiro, em ms), um tamanho de pacote p (valor inteiro, em KB) e um handshaking inicial de k (valor inteiro) RTTs  antes que os dados sejam enviados.

As situações s são: 

- Situação A: largura de banda l, valor real em Mbps, e os pacotes podem ser enviados continuamente;
- Situação B: largura de banda l, valor real em Mbps, e deve-se esperar um RTT após o envio de cada pacote até que se envie o próximo;
- Situação C: largura de banda "infinita" (tempo de transmissão irrelevante). Entretanto, q pacotes (valor inteiro) podem ser enviados por RTT;
- Situação D: largura de banda "infinita" (tempo de transmissão irrelevante). No primeiro RTT, entretanto, um pacote pode ser enviado. No segundo, dois pacotes podem ser enviados. No terceiro, quatro pacotes podem ser enviados. E assim sucessivamente.

### Parte 2 - Cálculo de largura de banda
Programa que lê uma distância d (valor inteiro, em quilômetros), uma velocidade de propagação do sinal v (inteiro, em metros por segundo) e um tamanho de pacote t (inteiro, em bytes) e calcula o valor de largura de banda l (real, em Mbps) tal que o retardo de propagação calculado em função de d e de v, é igual ao tempo de transmissão para pacotes de tamanho t.

## Atividade 3
### Parte 1 - Codificação de bits (transmissor)
Programa codifica os caracteres da mensagem em sua representação binária (passando pela representação decimal de cada caractere) e gera um sinal usando uma das seguintes codificações: NRZ ou Manchester.

### Parte 2 - Codificação de bits (receptor)
Programa efetua a decodificação do sinal NRZ ou Manchester.

## Atividade 4
### Parte 1 - Enquadramento PPP (transmissor)
Programa efetua o enquadramento de uma mensagem a ser transmitida usando o protocolo PPP. O quadro PPP é apresentado no documento Request For Comments 1331 (RFC 1331), disponível em: https://tools.ietf.org/html/rfc1331 

### Parte 2 - Enquadramento PPP (receptor)
Programa que interpreta um fluxo de bits que contém quadros PPP.

## Atividade 09 - Analisador de sub-redes IP
Programa efetua a análise dos endereços de uma sub-rede (IPv4) onde se encontra um determinado host H1.
