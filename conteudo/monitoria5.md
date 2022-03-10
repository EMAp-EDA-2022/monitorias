# Monitoria 5 (10/03)

## Linked List

Uma *linked list*, como o nome diz, é uma lista "ligada", vários nós são ligados em sequência para formar a estrutura. 

A estrutura do nó pode ser qualquer uma, contendo qualquer atributo, porém deve ter uma forma de encontrar os outros nós. Existem diferentes maneiras:

- Simples: o nó possui um ponteiro para o próximo;
- Dupla: o nó possui um ponteiro para o próximo e para o anterior;
- Circular: o último nó possui um ponteiro para o primeiro.

O algoritmos de uma *linked list* vão ser distintos para cada versão, por isso uma boa maneira é sempre fazer seu código desenhando a estrutura, para verificar se está correto.

![[linked-list.png]]

A ordem da *linked list* depende da aplicação desejada, uma maneira comum de construir uma é sempre inserir os dados na ordem.

A vantagem ao se utilizar uma *linked list*, é que a operação de se remover ou adicionar um novo nó pode ser feita em tempo constante,  o tempo é o mesmo se a lista seja de 10 elementos ou de 10mil. Existe um porém, só é constante se você já sabe onde vai inserir ou remover o nó, caso você tenha que procurar a posição, vai depender do tamanho.

### Inserção

Para inserir um elemento em uma *linked list*, você deve primeiro criar o nó que será adicionado na lista.

![[linked-list-insertion1.png]]

Em sequência, devemos atualizar os ponteiros do nó anterior e do nó seguinte ao nós que vamos adicionar. Primeiro ligamos o novo nó ao nó seguinte.

![[linked-list-insertion2.png]]

Depois ligamos o nó anterior ao novo nó.

![[linked-list-insertion3.png]]

Observe que ao inverter as duas operações, teríamos um problema: ao atualizarmos o *next* do nó anterior, não teríamos mais uma referência para o nó seguinte ao nó que será adicionado.

### Inserção código

### Remoção

Com o nó que desejamos remover identificado, devemos atualizar o ponteiro *next* do anterior a ele.

![[linked-list-deletion1.png]]

Salvamos uma referência para o *target* e atualizamos o ponteiro.

![[linked-list-deletion2.png]]

Podemos remover o *next* do *target*, porém apenas um *delete* do *target* já fará essa remoção.

![[linked-list-deletion3.png]]

![[linked-list-deletion4.png]]

### Remoção código
## Tree (árvore)
Uma *árvore* é um tipo específico de grafo, isso é, um conjunto de nós e arestas com a restrição de não ser cíclica e direcional.  

Uma maneira de interpretar uma *árvore* é com uma *raiz*, um nó que é pai de todos os outros nós, e cada nó possui seus nós filhos, os nós sem filhos são chamados de folhas.

![[tree.png]]

Existem diferentes tipos de *árvore*, o mais básico sendo a *árvore binária*  em que cada nó pode ter no máximo dois filhos (como na imagem anterior). Ela é construída com as seguintes regras:

- Cada nó tem no máximo 2 filhos.
- O filho da esquerda tem um valor de dado menor que o pai.
- O filho da direita tem um valor de dado maior que o pai.

![[binary-tree.png]]

### Inserção

Para inserir um dado em uma árvore, podemos interpretar cada nó como uma sub-árvore, e aplicar um algoritmo de forma recursiva.

Estamos em um nó, primeiro verificamos se o novo dado deveria ir para a esquerda ou para a direita.  Encontramos o lado, se o nó não existe, criamos esse novo filho. Caso o nó já exista, chamamos recursivamente nesse nó.

Para isso utilizaremos duas funções, um "inicializador" da busca que parte da raíz, e uma função recursiva que recebe um nó e realiza a verificação nesse nó.







