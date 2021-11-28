# Trabalho de Computação II - Métodos de Organização
Trabalho feito por: 
- Lucas Cardoso dos Santos (Nº USP: 9865492)
- Paulo Guilherme Pinheiro Pereira (Nº USP: 12542755)

O código total do trabalho, junto com um histórico de edições, 
pode ser encontrado no GitHub através do seguinte link: 
https://github.com/LucasCardoso910/trabalho_icii, sendo tornado 
público após a data máxima de entrega do trabalho.

## Enunciado:
Os arquivos “mes_i.txt”(sendo i=1,...5) anexos contém códigos de
operação de transações realizadas por uma empresa obtidos em 5
meses diferentes. Cada código de operação contém 10 letras.
Deseja-se um aplicativo que verifique se um determinado código de
operação (com 10 letras) digitado pelo usuário está presente  em 
um  dos  arquivos  mes_i.txt,  ou  seja,  deseja-se  saber  se 
esta operação foi realizada e, em caso afirmativo, em que mês.
Pede-se:

- Para acelerar o processo de busca, um algoritmo de busca 
binária deverá ser utilizado.  Para  isso,  o  conjunto  de  dados 
de  cada  arquivo será ordenado.  No  entanto,  deseja-se 
primeiro  determinar  qual  algoritmo  de ordenação   é   mais  
rápido   para   este   problema através   da   análise
experimental  do  número  de  comparação entre  chaves  e 
movimentações de registros. Sejam os seguintes algoritmos de
ordenação: 
  - Inserção direta;
  - Inserção binária;
  - Seleção;
  - Bubblesort;
  - Heapsort;
  - Fusão;
  - Quicksort.
- Pede-se:
  - a) Implemente os algoritmos relacionados. 
  - b) Obtenha   os números   de   comparações   entre chaves   e 
  de   movimentações   realizadas para cada  arquivo  (cada 
  arquivo  tem  um  tamanho diferente).
  - c) Gere dois gráficos, um com número comparações  entre
  chaves  e  outro  com  número de  movimentações  realizadas  
  (eixo  vertical)  x número  de códigos (eixo  horizontal) para  
  cada algoritmo.
  - d) Analise   os   algoritmos   através   dos   gráficos 
  obtidos,   comentando   se   os   resultados   são condizentes  
  com  a  análise  assintótica  de  cada algoritmo.
  - e) Baseado  nos  resultados  obtidos,  comente  qual (ou 
  quais) algoritmo(s)de ordenação é (são) mais apropriado(s) para 
  este problema.

- Implemente o   aplicativo   pedido   utilizando   busca
  binária.   Para   isso, primeiro,  ordene  o  conjunto  de
  dados  de  cada  arquivo utilizando um método  qualquer  e
  salve  os  dados  ordenados  em  novos  arquivos.  O aplicativo
  deve, portanto, carregar os arquivos ordenados e localizar (caso
  esteja  presente) o  código digitado. Caso  esteja  presente,
  deve  também indicarem qual mês o código foi encontradoe em que
  posição do arquivo (índice do vetor) ele se encontra.

Observações:
- Os grupos devem ter no máximo 2 alunos.
- Os códigos devem ser entregues junto com o material do trabalho.
- Os  programas serão  testados  na  presença  do  professor  no
  dia  da entrega do trabalho.
- Trabalhos  com  programas  com  partes  iguais  a  encontradas
  em  outras fontes (internet, colegas, etc...) terão nota igual a zero

## Da Organização do Trabalho
Para fins de organização e melhores práticas, foram criados alguns 
diretórios dentro da pasta principal do trabalho. Cada uma tem um
tema específico e um motivo para estar aqui. Para garantir que o 
seu funcionamento esteja claro, aqui serão descritos mais a fundo
seus motivos:

### data/
Um dos principais objetivos do trabalho é a obtenção de dados 
mensuráveis sobre a eficiência de cada um dos diversos algoritmos 
de ordenação que foram estudados, então fica encarregado a essa 
pasta armazenar e gerir esses dados obtidos. Ela é composta por 
mais três pastas e um script em Python (que será detalhado mais 
abaixo):
- data/files: O programa em C que executa todas as funções de 
  ordenação gera dados em uma tabela do formato livre .csv, essas 
  tabelas ficam armazenadas dentro dessa pasta.
- data/graphs: As tabelas .csv são acessadas pelo script em Python 
  para obter tabelas que sejam fáceis de visualizar e obter 
  informações sobre a complexidade e eficiência de cada uma das 
  funções.
- data/tables: As tabelas .csv são muito úteis em manipulação e 
  versatilidade, porém para uma exibição esteticamente mais 
  agradável foi escolhido usar o mesmo script em Python 
  anteriormente citado para gerar tabelas com as informações 
  desses arquivos em formato de imagem.

### etc
Para a automatização das tarefas e uso inteligente do nosso tempo, 
foram criados alguns scripts em Bash, de forma que executem as 
funções mais repetitivas e entediantes do desenvolvimento dos 
códigos do trabalho. Esses scripts estão aqui, com exceção dos 
principais que estão na pasta principal, e serão detalhados mais a 
frente.

### input
Os arquivos de texto originais não organizados estão aqui, apenas 
com a pasta renomeada para `input`.

### output
Os arquivos de texto gerados pelos programas em C estão aqui, 
tendo inicialmente uma pasta vazia para os arquivos da ordenação, 
chamada `sorting`, e outra pasta vazia para os arquivos da busca, 
chamada `search`.

### src
Os arquivos com os códigos fontes criados em C estão nessa pasta. 
Existe, como em outras anteriores, uma divisão interna entre 
pastas dos arquivos da aplicação de busca e dos arquivos da 
aplicação de testes de ordenação. Dentro de cada uma dessas existe 
uma outra pasta chamada `methods`, onde são salvos as funções 
relevantes a essa aplicação, como os algoritmos de ordenação e o 
algoritmo de busca binária, e os arquivos main, tanto o .c quanto 
o .h. Na pasta src existe também a biblioteca library.h, onde 
estão armazenadas as funções de uso comum. Essa é a pasta mais 
relevante do trabalho.

### tests
Durante o desenvolvimento, é útil fazer testes com casos mais 
simples ou cuja resposta já sabemos, assim como uma variedade 
grande para evitar erros inesperados. Essa pasta armazena arquivos 
de texto com esses testes para serem usados toda vez que for 
desejado.

### .
A pasta do trabalho em si, ou seja, `.`, também vale a pena ser 
mencionada. Nela temos os arquivos compilados em C, tanto para 
Windows quanto para Linux (sistema operacional usado pelos dois 
alunos no desenvolvimento do trabalho). Existe também arquivos de 
configuração, como o `.gitignore`, `.git`, `.vscode` e `.
clang-format`, o README.md em questão e também havia um TODO 
durante o desenvolvimento, além do PDF original com o enunciado do 
trabalho.

## Dos Scripts em Bash
Como dito anteriormente, houve uma preocupação durante o 
desenvolvimento do trabalho em evitar ficar executando ações 
repetitivas e mais complicadas, portanto foram criados alguns 
scripts em Bash para automatização dessas tarefas. Bash foi 
escolhido por conta da sua relação com o terminal do Ubuntu.

Não é de forma alguma essencial ao funcionamento dos códigos 
principais, mas apenas uma forma de garantir o seu funcionamento 
correto e mais robusto com apenas um comando.

Temos:
- etc/compare_files.sh: Para garantir que a execução do programa 
  em C deu certo de forma rápida e fácil, esse script percorre os 
  arquivos gerados e usa uma função do Bash `sort -C` que verifica 
  se dado arquivo está ordenado ou não. Caso não esteja, imprime 
  uma mensagem de erro.
- etc/format.sh: Para evitar que perdesse-se tempo corrigindo
  mínimos detalhes meramente estéticos, assim como garantir uma 
  padronização da escrita dos programas, foi criado esse script 
  que usa formatadores tanto de C, como de Bash, como de Python 
  para garantir que eles estejam dentro de um padrão.
- etc/run_tests.sh: Como dito ao falar sobre o diretório de tests, 
  a execução automatizada de testes ajudou em muito o 
  desenvolvimento do trabalho ao testar os resultados fornecidos 
  pelos programas em duas formas: que o algoritmo recém-criado 
  estava ordenando corretamente os arquivos, com dois casos 
  simples de teste criados para isso, assim como garantir que as 
  contabilizações de movimentações e comparações estivessem de 
  acordo com os dados fornecidos junto do pseudo-código.
- run1: Script que chama os anteriores para formatar o código do
  programa em C que gera os dados sobre ordenações, compila o seu 
  código e o executa, realizando os testes se o usuário quiser, 
  conferindo os resultados produzidos e chamando o script em 
  Python para gerar os gráficos e tabelas.
- run2: Uma versão mais simplificada da anterior para a aplicação 
  de busca, uma vez que não há testes escritos para ela, assim 
  como não é necessário gerar gráficos ou tabelas, nem como 
  conferir resultados produzidos por ela. Apenas formata os 
  arquivos, compila seu código e o executa, passando o comando ao 
  usuário.

## Do Script em Python
Pelo pedido de criar gráficos, tabelas e outras formas numéricas 
de comparações sobre as eficiências, foi escolhido usar Python 
devido a sua grande quantidade de bibliotecas elaboradas e 
robustas para tratamento de dados. Usamos a biblioteca 
`matplotlib` para a geração das tabelas e dados em si, `pandas` 
pela facilidade para ler um arquivo csv e transformá-lo em um 
array automaticamente e a biblioteca `os`, para garantir que não 
importasse quantos arquivos fossem criados após o script estar 
pronto eles seriam tratados.

## Da execução do trabalho como um todo
Como dito anteriormente, não há necessidade alguma de usar os 
scripts criados aqui para executar o trabalho, porém eles 
facilitam e muito essa parte do trabalho, uma vez que há pastas 
específicas em que se deve estar para a correta execução dos 
arquivos, coisa que o script lida. Portanto, se possível, nossa 
posição é de incentivar o seu uso.

Porém, se por qualquer motivo, não for possível o uso de um script 
em Bash, aqui estão algumas informações necessárias para a 
execução do trabalho como um todo:
- Os arquivos C compilados devem ser executados dentro da pasta 
  principal do trabalho.
- O arquivo run_tests.sh deve ser executado dentro da pasta tests. 

Para sua conveniência, os comandos usados para compilar os arquivos
durante o trabalho foram:

- Para o programa da questão 1: `gcc src/sorting/main.c -o main.out`
- Para o programa da questão 2: `gcc src/search/main.c -o main.out`.

Com as devidas alterações aplicáveis, como a extensão do arquivo
compilado. 

Por garantia, os arquivos .c foram compilados no formato do Windows
também e estão disponíveis na extensão .exe dentro da pasta principal
do trabalho, onde devem ser rodados.
