-Gabriel Tomazini Marani
-Paulo Victor Nogueira Rodriges
-Pedro Augusto Senger Piana

**Ideia de projeto**
- A ideia foi criar uma linguagem c, com palavras reservadas e delimitadores (,{,[ invertidos;
- Nomeamos a linguagem de --c porque é mais limitada que o c padrão e é invertida;

**Como Funciona**
- Análise léxica é feita no arquivo analizador.l;
- Análise Sintática, Semântica e geração de código é feito em bison.y;
- Assembly de três endereços implementado em C++;
- Programa escrito em --c gera um código em assembly, rodando o código em assembly temos o programa funcionando;

** Restrições da linguagem: **
- Comando ftnirp (printf) só mostra (01) texto ou (01) variável, não é possível concatenar várias variáveis
com pedaços de texto, para isso é necessário vários comandos ftnirp;
- Cada declaração de variável ou vetor deve ocupar uma linha cada, não é possível declarar várias variáveis
do mesmo tipo em uma única linha; 
- É necessário o uso de delimitadores mesmo que a instrução tenha apenas uma linha;

** Como rodar a linguagem e observações **
-bison -d bison.y
-flex analizador.l
-gcc -o compilador lex.yy.c bison.tab.c
-./compilador <arquivo_teste> > assembly.rap
-./raposeitor assembly.rap

OBS:. Caso o programa seja rodado conforme acima, erros semânticos aparecerão dentro de assembly.rap
