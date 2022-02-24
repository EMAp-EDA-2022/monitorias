# Monitoria 4 (25/02)

- [Monitoria 4 (25/02)](#monitoria-4-2502)
	- [1. Header](#1-header)
		- [1.1 Declarações e definições](#11-declarações-e-definições)
		- [1.2 Include guard](#12-include-guard)
		- [1.3 Revisão](#13-revisão)
	- [2. Fila](#2-fila)
		- [2.1 Esqueleto da fila](#21-esqueleto-da-fila)
		- [2.2 Constructors](#22-constructors)
		- [2.3 Funções da queue](#23-funções-da-queue)
		- [2.4 Template](#24-template)

Nessa monitoria vamos construir uma estrutura de dados chamada *fila (queue)* separando os arquivos em headers.

## 1. Header 

Um *header* é geralmente utilizado para a construção de classes, nele criamos o código da classe que será utilizada em vários outros programas.

Mas por que usar um *header*?

### 1.1 Declarações e definições

Vamos relembrar algumas nomenclaturas:
- Declaração: uma "palavra" é reservada para um dado tipo `int num;`.
- Definição: a "palavra" já declarada recebe um valor, e o espaço de memória é reservado `num = 1;`.

Para qualquer variável ou função, ela deve ser declarada para depois ser definida. 

Para funções, nos chamamos as declarações de "prototype" e as definições de "implementação".

A declaração de uma função deve ocorrer antes de ela ser utilizada. Observe o exemplo:

```c

void funcA(int i) {
	funcB(i, i + 1);
	return;
}

void funcB(int x, int y) {
	x + y;
}


```

O código dessa forma não vai ser compilado, porque quando a função `funcA` chamar `funcB`, a função `funcB` ainda não foi declarada e isso vai resultar em um erro. Uma solução seria declarar e depois definir:

```c

void funcA(int);

void funcB(int, int);

void funcA(int i) {
	funcB(i, i + 1);
	return;
}

void funcB(int x, int y) {
	x + y;
}

```

Por esse motivo, é uma boa prática sempre declarar as funções para depois definir. E o mesmo ocorre para classes, o ideal é primeiro declarar as funções da classe e após fora do escopo definir elas.

Uma **recomendação** é **declarar** as funções de uma classe em um arquivo *header* com extensão *.h*, e após isso, **definir** as funções em outro arquivo com extensão *.hpp*.

### 1.2 Include guard

Nós vemos duas primeiras linhas dentro do arquivo *.h*,  `#ifndef` e `#define`, o que são elas?

O que o comando `#include` faz é pegar o conteúdo do arquivo chamado e inserir dentro do código. Quando chamamos `#include "myclass.h"`, inserimos todas as declarações desse arquivo. Porém, caso um *header* seja chamado mais de uma vez, o compilador vai resultar em um erro. 

Isso poderia ocorrer por exemplo se o arquivo A chamasse `#include` de B e C, e ambos chamam o *header* D. Dessa forma  utilizamos o chamado *include guard*. O comando `#ifndef` serve para verificar se a definição já existe, e se ela já existe, o que estiver dentro não é lido novamente. Já o comando `#define` serve para nomear a definição. 

### 1.3 Revisão

Juntando tudo:

```c
//arquivo myclass.h
#ifndef MYCLASS_H // É um "if" para o compilador só ler se o "MYCLASS_H" ainda não foi definido
#define MYCLASS_H // É um nome para a declaração

/*
Nesse arquivo vai ter a declaração da classe
E a declaração das funções
*/
class myclass {
 public:
	void funcA(int, char);
	int funcB(int, int);
}

#include "myclass.hpp"
#endif

```

```c
//arquivo myclass.hpp
#include "./myclass.h"
/*
Nesse arquivo vai ter a definição das funções da classe (os prototypes)
*/
void myclass::funcA(int x, char c) {
	std::cout << x << " ," << c << std::endl;
}

int myclass::funcB(int x, int y) {
	return x + y;
}

```

```c
//arquivo main.cpp
#include "myclass.h" //nós chamamos o arquivo .h que por sua vez chama o arquivo .hpp

int main() {
	myclass C;
	C.funcB(1, 2);
	return 0;
}
```

## 2. Fila

A fila é a estrutura de dados mais justa: quem chegou primeiro vai ser atendido primeiro.

Basicamente, a fila possui marcadores de **início** e **fim**, e possui duas operações: **inserir um novo elemento no fim** e **remover o primeiro elemento do início**.

![[queue.png]]

Uma fila pode ser implementada de diferentes maneiras, nós vamos implementar ela baseada em uma *linked list*. Cada item da fila vai ser um *node*, ele vai armazenar um valor qualquer e um ponteiro para o próximo *node*.

![[linked-list.png]]

### 2.1 Esqueleto da fila

Vamos iniciar então a estrutura da nossa classe, primeiro com o *struct* de um *node*. Ele vai armazenar um inteiro chamado `value` e um ponteiro para o próximo. Ele também vai ser um constructor que recebe o valor que será salvo como *value*.

```c

struct Node {
	int value;
	Node* next;

	Node(int);
}

```

Vamos começar a nossa classe também, chamando de Queue (fila em inglês, chique). Ela vai ter dois ponteiros, um que aponta para o início da fila e outro que aponta para o final. E as funções de *enqueue* e *dequeue*. O constructor vai começar vazio.

```c
class Queue {
	Node* ptr_start;
	Node* ptr_end;
 public:
	Queue();

	void Enqueue(int);

	int Dequeue();
	
}
```

### 2.2 Constructors

Vamos definir primeiro os constructors. O *node* vai iniciar com um valor desejado e vamos fixar o ponteiro para o próximo como `nullptr`.

```c

Node::Node(int x) {
	value = x;
	next = nullptr;
}

```

O constructor da *queue* deve iniciar os ponteiros de início e fim:

```c
Queue::Queue(){
	ptr_start = nullptr;
	ptr_end = nullptr;
}

```

### 2.3 Funções da queue

Vamos criar a função de inserir um elemento no final da fila.
Isso pode ocorrer de duas maneiras:
- Se a fila estiver vazia, tanto o primeiro como o último serão o único elemento adicionado.
- Se a fila possuir outros elementos, o `next` do último vai ser o nó adicionado, e atualizando o ponteiro `ptr_end`.

```c
void Queue::Enqueue(int x) {
	Node* ptr_new = new Node(x); //Criamos o novo elemento
	if (ptr_start == nullptr) { // Se a lista estiver vazia, ambos apontam para o novo
		ptr_start = ptr_new;
		ptr_end = ptr_new;
	} else {
		ptr_end->next = ptr_new; // O novo foi adicionado no final
		ptr_end = ptr_new; // Atualizamos o ponteiro para o novo final
	}
}

```

Vamos criar a função de remover o elemento do começo da fila.
Isso pode ocorrer de três maneiras:
- Se a fila estiver vazia, não retorna nada, joga um erro.
- Se a fila tiver um elemento, após ser removido ambos `ptr_start` e `ptr_end` serão `nullptr`.
- Se a fila possuir outros elementos, o `ptr_start` vai passar a ser seu `next` .

```c

int Queue::Dequeue() {
	//  Se a lista estiver vazia, retornamos um erro (vemos isso outro dia)
	if ((ptr_start == nullptr) & (ptr_end == nullptr)){
		return int();
	}

	//  Valor que iremos retornar
	int value = ptr_start->value;

	//  Guardamos um ponteiro para o start
	Node* aux = ptr_start;
	// E atualizamos o start
	ptr_start = ptr_start->next;
	// Se a lista só tinha um elemento, o start virou nullptr
	if (ptr_start == nullptr) {
		ptr_end = nullptr; //  O end também que ser null
	}

	// Deletamos a memória dinâmica (vemos isso outro dia)
	delete aux;
	return value;
	
}

```

### 2.4 Template

A Queue que nós construímos apenas suporta *inteiro*, e se quisermos fazer uma fila de *floats*? De _chars_? Para não precisar copiar todo o código trocando _int_ for _float_, criamos a classe com tipos genéricos, os templates.

Vamos realizar essa modificação. Primeiro temos que adicionar a linha `template<class T>` no início de cada classe e cada função:

```c
template<class T>
struct Node {}

template<class T>
class Queue {}
```

Agora no _node_, a variável `value` vai ser de tipo `T` e não `int`, alteramos:

```c
template<class T>
struct Node {
	T value;
	Node* next;

	Node(T);
}

template<class T>
Node::Node(T x) {
	value = x;
	next = nullptr;
}
```

Nas funções Enqueue e Dequeue da fila, também alteramos o tipo `int` para `T`:

```c

template<class T>
class Queue {
	Node* ptr_start;
	Node* ptr_end;
 public:
	Queue();

	void Enqueue(T);

	T Dequeue();
	
}


template<class T>
void Queue::Enqueue(T x) {
	Node* ptr_new = new Node(x); 
	if (ptr_start == nullptr) { 
		ptr_start = ptr_new;
		ptr_end = ptr_new;
	} else {
		ptr_end->next = ptr_new; 
		ptr_end = ptr_new; 
	}
}

template<class T>
T Queue::Dequeue() {
	if ((ptr_start == nullptr) & (ptr_end == nullptr)){
		return T();
	}

	T value = ptr_start->value;

	Node* aux = ptr_start;
	ptr_start = ptr_start->next;
	if (ptr_start == nullptr) {
		ptr_end = nullptr; 
	}
	delete aux;
	return value;
	
}

```

Por fim, sempre que for declarar um novo *node*, devemos escrever o tipo. Dentro da classe iremos trocar `Node` por `Node<T>`:

```c
template<class T>
struct Node {
	T value;
	Node<T>* next;

	Node(T);
}

template<class T>
Node::Node(T x) {
	value = x;
	next = nullptr;
}

```

```c

template<class T>
class Queue {
	Node<T>* ptr_start;
	Node<T>* ptr_end;
 public:
	Queue();

	void Enqueue(T);

	T Dequeue();
	
}


template<class T>
void Queue::Enqueue(T x) {
	Node<T>* ptr_new = new Node(x); 
	if (ptr_start == nullptr) { 
		ptr_start = ptr_new;
		ptr_end = ptr_new;
	} else {
		ptr_end->next = ptr_new; 
		ptr_end = ptr_new; 
	}
}

template<class T>
T Queue::Dequeue() {
	if ((ptr_start == nullptr) & (ptr_end == nullptr)){
		return T();
	}

	T value = ptr_start->value;

	Node<T>* aux = ptr_start;
	ptr_start = ptr_start->next;
	if (ptr_start == nullptr) {
		ptr_end = nullptr; 
	}
	delete aux;
	return value;
	
}

```