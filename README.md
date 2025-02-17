# T03 – Struct Vector and Binary Search
The client data of a clinic is stored in a text file with the following format:
name: height weight (Texto.txt)

Consider that the data in this file is sorted in ascending order by height and weight. Also, assume that names never exceed 80 characters. When defining structures, use typedef mandatorily.

[1] Data Processing: 
Read the text file and create a vector of pointers to structures containing the client data.
Dynamically allocate memory with the exact required size.
Implement the function int countLines(char* fName) to count the number of lines in the file.
Implement the function lerMontarVetor, which receives the file name and the number of lines and returns the vector of pointers.
Implement the function imprimeVetor to print the vector.
Calculate the mean and standard deviation of weights using the functions mean and standardDeviation.

[2] Binary Search: 
Implement a binary search function that, given a height, returns the index of the person with the highest weight for that height.
Include comprehensive test cases, including:
Searching for an existing height and retrieving the last occurrence.
Searching for a height that does not exist in the dataset.
Implement an auxiliary comparison function comparaAltura, which takes a pointer to a Client structure (e.g., Client *b) and is used for all height comparisons during the search.

Main Function: 
Perform appropriate file and memory tests.
Handle cases where the file exists but is empty.
Close files and free allocated memory at the right moments using a mandatory auxiliary function freeMem.
***********
## Tradução
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
