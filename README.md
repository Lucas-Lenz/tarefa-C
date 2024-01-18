# T03 – Vetor de struct e Busca Binária
Os dados dos clientes de uma clínica estão registrados em um arquivo texto no seguinte formato: nome:
altura peso (arquivo Texto.txt)  
Considere que os dados neste arquivo estão ordenados crescentemente por altura e por peso. Considere também 
que os nomes nunca têm mais do que 80 caracteres. Na definição de estruturas, use obrigatoriamente typedef.  

[1] A partir do arquivo texto, crie um vetor de ponteiros para estruturas contendo os dados de cada cliente. Você deve alocar dinamicamente a memória do tamanho exato. Para tanto, escreva 
obrigatoriamente a função int countLines(char* fName) que conta as linhas do arquivo texto. Para ler e montar o 
vetor escreva obrigatoriamente uma função chamada lerMontarVetor que recebe o nome do arquivo e o número de 
linhas e retorna o vetor de ponteiros. E, para imprimir o vetor, escreva obrigatoriamente uma função chamada 
imprimeVetor. Por fim, calcule a média de pesos e o desvio padrão, escrevendo as funções mean
e standardDeviation.  
[2] Escreva uma função que faça uma busca binária de maneira que, dada uma altura, retorna o índice (do vetor) 
que corresponde à pessoa de maior peso com a altura especificada1
. Faça testes adequados. Por exemplo, teste também a situação que 
retorna o último elemento. Nos testes, imprima 
mensagens adequadas (i.e., informativas, que não sejam apenas a exibição do índice). Faça também um teste no 
qual a busca não encontra a informação. Use obrigatoriamente uma função auxiliar de comparação, chamada 
comparaAltura, que tenha como argumento um ponteiro para Client (e.g., Client * b). E, em qualquer comparação 
durante a busca envolvendo a altura, use sempre esta mesma função.  
Na main, faça os testes adequados de arquivo e memória. Faça também, no momento adequado, o teste para o 
caso do arquivo existir e estar vazio. Feche os arquivos e libere a memória nos momentos adequados (para liberar 
a memória escreva obrigatoriamente uma função auxiliar chamada freeMem).
