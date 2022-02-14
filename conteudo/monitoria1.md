# Monitoria 1 (13/02)

__Conteúdo__:
- [Configuração C++ nas máquinas](#configuração-c);
- Revisão conteúdo base C++ apresentado em aula.

## Configuração C++

C++ é uma linguagem compilada, dessa forma, para transformar o código em um arquivo executável, é necessário a instalação de um compilador, geralmente falamos sobre essa instalação como "instalar o C++". Existem diferentes compiladores, e entre eles os mais comuns são o MinGW (especial para Windows) e o g++. Aqui vamos falar brevemente como instalar eles, com referências para tutoriais mais completos. A instalação é diferente para sistemas Linux e Windows, dessa forma será apresentado separadamente.

### Linux

Utilizar do C++ em um ambiente Linux pode acabar sendo mais fácil devido uma maior comunidade online e maior quantidade de ferramentas adaptadas para esse sistema. Para instalar o compilador g++ nesse ambiente, use-os comandos: (Obs.: esses comandos são baseados na distribuição Ubuntu 20.04).

Utilize o comando para se certificar que o apt está atualizado:

```
sudo apt-get update
```

E instale com o comando:

```
sudo apt install g++
```

#### Configuração VSCode
Nós recomendamos a utilização do VSCode para criar seus programas em C++, é uma ferramenta com uma grande quantidade de extensões que facilitam o desenvolvimento. O download é possível no [link](https://code.visualstudio.com/Download), e também pode ser obtido na Central de programas do Ubuntu. Em seguida, instale a extensão "C/C++" no VSCode e criei um diretório com seu primeiro arquivo `main.cpp`, crie um código "hello world":

```c
#include<iostream>

int main(){
  std::cout << "Hello world!" << std::endl;
  return 0;
}

```

Agora, para executar esse código com o VSCode (e não no terminal), precisamos configurar o arquivo de build. Vá em _Terminal -> Configurar Tarefa de Build Padrão_ e selecione  _g++ arquivo de build ativo_. Isso irá criar o arquivo `tasks.json` que contém configurações sobre o comando que o terminal irá executar para compilar o arquivo, que por enquanto pode ser mantido do jeito que está. Volte para o `main.cpp` e use as teclas Ctrl+Shift+B para executar a tarefa de build, que irá compilar o arquivo e criar o executável. Para mais detalhes, utilize da seguinte [referência](https://medium.com/floppy-disk-f/setting-up-visual-studio-code-vs-code-with-c-on-ubuntu-linux-506aa02cacb5).

### Windows

Em certas situações pode ser desvantajoso utilizar c++ em um ambiente Windows, com uma grande dificuldade de instalar algumas bibliotecas, por exemplo. No entanto, nos últimos anos esse problema vem sendo solucionado. Existem diferentes maneiras de se instalar um compilador no Windows, vamos aprensentar algumas delas:

#### Instalar o compilador MinGW

Para a instalação do MinGW, recomendamos seguir os passos apresentados no seguinte [vídeo](https://www.youtube.com/watch?v=BAa7ftan_Fo&t). As etapas consistem no download do MinGW disponível no seguinte [link](https://sourceforge.net/projects/mingw/), a instalação seguida por adicionar o MinGW nas variáveis de ambiente do Windows, seguidas pela configuração do VSCode.

#### Instalar o compilador g++ via WSL

WSL é uma adição recente do Windows em que uma máquina virtual Linux é criada dentro do ambiente Windows. Essa máquina virtual é bastante "pequena" e possui boa relação com as outras ferramentas do ambiente Windows. Existe o tutorial [oficial](https://docs.microsoft.com/pt-br/windows/wsl/install) que apresentaremos de forma resumida aqui.

É necessário ter Windows 11 ou Windows 10 com versão superior a 19041 (possível de se verificar em "Informações do sistema"). No Prompt de comando use:

```
wsl --install
```

Esse comando instalará uma distribuição Ubuntu no seu ambiente Windows. No final do processo irá pedir por um nome de usuário e senha, escolha essas credenciais. Agora, para instalar o g++, basta abrir o Ubuntu e utilizar os mesmos passos do tutorial [anterior](#linux).

É possível utilizar o VSCode com o WSL, para isso, seguinte a referência [oficial](https://code.visualstudio.com/docs/cpp/config-wsl). Com o VSCode e o WSL instalados, crie um repositório e um arquivo dentro do Ubuntu e use o comando `code .` para chamar o VSCode de dentro da distribuição, na primeira vez isso irá instalar um pacote e logo após abrir o VSCode. Nele, instale a extensão "Remote - WSL", e após isso basta seguir os mesmos passos da [configuração](#configuração-vscode) de VSCode em um Ubuntu.

