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

A mensagem recebida tem formato de sequência de números binários e deve ser lida pelo programa receptor pela entrada padrão (scanf). Tal informação possui até 80 números binários positivos separados por espaços em branco. O primeiro número lido corresponde à quantidade de números binários que compõem a mensagem.

A pilha de protocolos empregada em tal comunicação é a mesma da Parte 1 da Atividade 01. A mensagem codificada em números binários deve ser convertida de volta à sua codificação original, em caracteres e exibida usando a saída padrão (printf).

Exemplo de mensagem:
1010100 1110010 1100101 1110011 100000 1110100 1101001 1100111 1110010 1100101 1110011 100000 1110100 1110010 1101001 1110011 1110100 1100101 1110011 101110

Em decimal:
84 114 101 115 32 116 105 103 114 101 115 32 116 114 105 115 116 101 115 46

String original:
Tres tigres tristes.

