# Monitoria 2 (17/02)

- [Monitoria 2 (17/02)](#monitoria-2-1702)
  - [1. Arrays e Vectors](#1-arrays-e-vectors)
    - [1.1 Arrays](#11-arrays)
    - [1.2 Vectors](#12-vectors)
    - [1.3 Tempo de processamento: Array x Vectors](#13-tempo-de-processamento-array-x-vectors)
  - [2. Ponteiros](#2-ponteiros)
    - [2.1 Referências e ponteiros](#21-referências-e-ponteiros)
    - [2.2 Exemplo de uso](#22-exemplo-de-uso)

---

## 1. Arrays e Vectors

### 1.1 Arrays

_Arrays_ são "containers" básicos que já existiam em C: eles armazenam uma grande quantidade de valores **de um único tipo** e possuem apenas funcionalidades básicas. Observe a sintaxe para criar um array:

```c
// Cria um array com um tamanho fixo e sem valores
tipo nome_array[tamanho];

// Cria um array com tamanho fixo (inferido) e com valores
tipo nome_array[] = {valor1, valor2, ...};

```

---

 Após um array ser criado, os valores podem ser acessados utilizando o índice da posição (começando em 0):

 ```c
tipo nome_array[] = {valor1, valor2, valor3};
nome_array[0]; //valor1
nome_array[2]; //valor3
nome_array[1] = nome_array[2]; //array se tornou {valor1, valor3, valor3}
 ```

---

É importante compreender como os arrays __armazenam os valores na memória__, quando utilizamos uma expressão `int myarray[5]`, o que ocorre é que um bloco contínuo de 3 vezes 4 bytes (o espaço ocupado pelo `int`) é reservado para esse array em específico.

![[array_memoria.png]]

---

Vamos olhar isso na prática:

```c

int myarray[] = {78, 45, 12, 89, 56};

for(int i = 0; i < 5; i++){
	cout << "Valor do array: " << myarray[i] 
		 << " Endereço de memória: " << &myarray[i] << endl;

	//Utilizei do caracter & para obter o endereço de memória
	//Mais tarde comentarei sobre isso
}

/*

O resultado esperado depende do seu computador, mas em todos, o que pode se ver é que o endereço das posições vai pulando de 4 em 4, isso ocorre pois um int tem 4 bytes

exemplo: 


Valor do array: 78 Endereço de memória: 0x7ffd5206da40
Valor do array: 45 Endereço de memória: 0x7ffd5206da44
Valor do array: 12 Endereço de memória: 0x7ffd5206da48
Valor do array: 89 Endereço de memória: 0x7ffd5206da4c
Valor do array: 56 Endereço de memória: 0x7ffd5206da50

*/

```

---

Quais a **vantagem** de se armazenar na memória assim? A principal é que se torna **mais eficiente obter os dados do _array_**, pois se eu sei a posição inicial dele na memória, eu sei a posição de todos os outros elementos, basta apenas somar o índice.

E a **desvantagem**? O problema é que você precisa definir o tamanho do _array_ já de início, e não é possível aumentar o tamanho depois que a memória for reservada (a única maneira é apagando tudo e criando um array do 0).

---

### 1.2 Vectors

_Vectors_ é um outro tipo de "container" em C++ que vem da biblioteca `vector` que também armazena um único tipo de dado. Vamos olhar a sintaxe. Diferentemente do _array_, o tipo de dado que irá conter no _vector_ vem dentro de `<>`, vocês irão entender mais sobre isso quando aprenderem sobre classes e templates.

```c
//precisa do include
#include<vector>

// ...
vector<tipo> nome_vector;

vector<tipo> nome_vector = {valor1, valor2, ...};

vector<tipo> nome_vector(n_repetições, valor); // {valor, valor, valor, ...}
```

---

Da mesma forma que os *arrays*, os *vectors* armazenam a memória de forma contínua, dessa forma facilitando de se acessar valores apenas baseado no índice. No entanto, a vantagem do *vector* é que ele possui suporte para adicionar novos elementos com o comando `push_back()`:

```c

vector<int> myvector;
for(int i = 0; i < 10; i++){
	myvector.push_back(i);
}
```

--- 
Mas se ele pode aumentar de tamanho, como que ele consegue ser armazenado de forma contínua? Ele lida com esse problema de forma interna, o que ele faz é apenas encontrar um outro local na memória quando não houver mais espaço para ficar armazenado de forma contínua. Para lidar com isso, existe o comando `reserve` para que você possa reservar uma quantidade de memória:

```c

vector<int> myvector;
myvector.reserve(100); 

//equivalente a:  myvector<int> myvector(100);
```

--- 

Elementos de _vectors_ podem ser acessados iguais a *arrays*:

```c

vector<int> myvector(10);
for(int i = 0; i < 10; i++){
	myvector[i] = i;
}

```

--- 

Também podem ser acessados com _iterators_ (não possuem vantagem):

```c

#include<iterator>

...

vector<int> myvector(10);
for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++){
	*it = -999;
}


```

---

Os comandos `begin()` e `end()` retornam _iterators_ que apontam para o primeiro, e para o __primeiro após o último (não o último)__, de um vector. Dessa forma, utilizamos a comparação ` it != myvector.end()`, pois queremos que ele continue enquanto for diferente do primeiro após o último.

---

### 1.3 Tempo de processamento: Array x Vectors

Vamos comparar o tempo de processamento de criar _arrays_, _vectors_ e _vectors_ com memória reservada?

```c
#include<iostream>
#include<vector>
#include<chrono> //usado para medir o tempo

using namespace std;

int main(){
	// Vou testar criar containers com o seguinte número de elementos:
    int ns[] = {1000, 10000, 100000, 1000000};

    for(int i = 0; i < 4; i++){
        int n = ns[i];
        cout << "Number of elements: " << n << endl;
        //array

		// Por enquanto pode ignorar o comando "auto"
		// Esses medidores de tempo
        auto start = chrono::high_resolution_clock::now();
        int myarray[n];
        for(int i = 0; i < n; i++){
            myarray[i] = i;
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "array: " << duration.count() << "ms." << endl;
        
        //vector
        start = chrono::high_resolution_clock::now();
        vector<int> myvector1;
        for(int i = 0; i < n; i++){
            myvector1.push_back(i);
        }
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "vector (not reserved): " << duration.count() << "ms." << endl;
        
        //vector com memória pré reservada
        start = chrono::high_resolution_clock::now();
        vector<int> myvector2;
        myvector2.reserve(n);
        for(int i = 0; i < n; i++){
            myvector2.push_back(i);
        }
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "vector (reserved) " << duration.count() << "ms." << endl;

    }

    return 0;
}

/*

O resultado vai depender do seu computador, rodando no meu, obtive:

Número de elementos: 1000
array: 5ms.
vector (sem reserved): 60ms.
vector (reserved) 30ms.
Número de elementos: 10000
array: 82ms.
vector (sem reserved): 475ms.
vector (reserved) 377ms.
Número de elementos: 100000
array: 654ms.
vector (sem reserved): 2008ms.
vector (reserved) 1842ms.
Número de elementos: 1000000
array: 3943ms.
vector (sem reserved): 15189ms.
vector (reserved) 12553ms.


*/

```

---

Podemos ver que o _array_ acaba sempre sendo mais rápido, e que é sempre melhor  reservar a memória de um *vector* do que não reservar. No entanto, na maioria das discussões é se recomendado utilizar o *vector* pois facilita bastante os algoritmos, com um tempo de processamento que não é tão problemático. 

---

Existe um outro tipo de _array_ com funcionalidade extras, é o `std::array` que precisa da biblioteca `#include<array>`, mas vou deixar para vocês olharem caso tenham interesse.

---

## 2. Ponteiros

### 2.1 Referências e ponteiros

Vocês já viram o uso de referências com o símbolo `&`:

```c
int a = 5;
int &b = a;
b = 10;
// a == 10

```

---

Mas o que exatamente é uma referência? Pensando no próprio significado da palavra, uma referência é uma "palavra" utilizada para se falar sobre algo. Neste pequeno exemplo que criamos, primeiro temos a palavra `a` e depois a palavra `b`, que falam sobre a mesma coisa. E o que é essa coisa? É o espaço de memória que está armazenando o valor 5 (e depois o 10).

---

Observe que não criamos um novo valor `5`, não utilizamos um novo espaço de memória. Apenas temos duas variáveis que se referem ao mesmo espaço de memória.

```c
cout << "Espaço de memória de a: " << &a << endl;
cout << "Espaço de memória de b: " << &b << endl;

/*
O resultado vai depender do seu computador, mas no meu obtive:
Espaço de memória de a: 0x7fff4624fb6c
Espaço de memória de b: 0x7fff4624fb6c
*/
```

---

E o que faz um ponteiro? Parecido com a referência, o ponteiro cria uma nova forma de falar sobre o mesmo espaço de memória, porém ele salva esse valor em outro local.

![[ponteiro_memoria.png]]

--- 

Vamos olhar o nosso exemplo anterior, note que vamos salvar em um outro local de memória o endereço da variável `a`.

```c
int* pa = &a;
cout << "Endereço de pa:" << &pa << endl;
cout << "Valor salvo em pa:" << pa << endl;
cout << "Endereço de a:" << &a << endl;

/* 
O resultado depende do seu computador. Obtive:
Endereço de pa:0x7ffde7ae8ff8
Valor salvo em pa:0x7ffde7ae8ff4
Endereço de a:0x7ffde7ae8ff4
*/
```

---

No começo, modificamos `b` e essa modificação também afetou `a`. Podemos fazer isso também com `pa`:

```c
*pa = 20;
//a == 20
```

Dessa forma, quando salvamos o endereço de `a`, também somos capazes de modificar `a` ao adicionarmos o símbolo `*`.

---

Deixando claro a sintaxe de `*` e `&`:

```c
// Se for uma declaração de variável (isto é, o símbolo está do lado esquerdo)

int &b = a; // Cria uma referência
int *pa = a; // Cria um ponteiro

// Se não for uma declaração de variável (símbolo do lado direito)

&b; // retorna o endereço de memória
*pa; // Acessa o valor que está apontando

```

---

Até agora ponteiros e referências foram bastante similares. É comum que você use referências sempre que possível, e quando necessário, passe a utilizar ponteiros. Mas vocês verão que ponteiros serão úteis em algumas situações como:

- Criação de uma estrutura de dados (classe)
- Utilização de memória dinâmica

---
### 2.2 Exemplo de uso

Vamos pensar em um exemplo para as coisas fazerem mais sentido. Suponha que você tem 5 dados em um _array_ ou um _vector_, porém a sua memória só tem espaço para esses 5 dados (você não pode criar uma cópia). A tarefa que você quer fazer é multiplicar cada dado por 2 utilizando uma função. Como fazer isso?

___

```c
#include<iostream>
#include<vector>

using namespace std;

void print_array(int arr[], int size){
    cout << "array: [";
    for(int i = 0; i < (size - 1); i++){
        cout << arr[i] <<  ", ";
    }
    cout << arr[size - 1] << "]" << endl;
    return;
}

void print_vector(vector<int> vec){
    cout << "vector: [";
    for(int i = 0; i < (vec.size() - 1); i++){
        cout << vec[i] <<  ", ";
    }
    cout << vec[vec.size() - 1] << "]" << endl;
    return;
}

void dobrar_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = 2 * arr[i];
    }
    return;
}

void dobrar_vector(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        vec[i] = 2 * vec[i];
    }
    return;
}

void dobrar_vector_real_oficial(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        vec[i] = 2 * vec[i];
    }
    return;
}

void dobrar_pointer_vector_real_oficial(vector<int> * pVec){
    for(int i = 0; i < (*pVec).size(); i++){
        (*pVec)[i] = 2 * (*pVec)[i];
    }
    return;
}

int main(){
    int myarray[] = {1, 2, 3, 4, 5};
    
    print_array(myarray, 5);
    dobrar_array(myarray, 5);
    print_array(myarray, 5);


    vector<int> myvec = {1, 2, 3, 4, 5};
    print_vector(myvec);
    dobrar_vector(myvec);
    print_vector(myvec);
    dobrar_vector_real_oficial(myvec);
    print_vector(myvec);

    vector<int> * pVec;
    pVec = &myvec; 

    dobrar_pointer_vector_real_oficial(pVec);
    print_vector(*pVec);
    return 0;
}
```
