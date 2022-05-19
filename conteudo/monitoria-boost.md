# Monitoria Boost
Instalar o *Boost* e conseguir utilizar o *Python.Boost* é bastante difícil, é uma "arte". Eu já tive que passar por essa etapa de instalar o *Boost* 3 vezes na minha vida e até hoje ainda é difícil, então reservem um tempo para tentar fazer isso funcionar.

Eu nunca consegui instalar utilizando o *Windows* (usando o Prompt de Comando). Consegui seguir esse tutorial aqui usando o *Ubuntu* instalado em um computador e um *Ubuntu* através de um *WSL*.

Vocês terão que "conhecer bem" como funciona o sistema de instalação do *Ubuntu*, lidar com arquivos, etc. Uma maneira ideal é ter algum integrante do grupo que tenha mais conhecimento nisso.

## Instalar Boost
Eu vou tentar passar instruções gerais aqui de como eu consegui instalar o *Boost*.

Eu comecei seguindo esse tutorial: https://cosmiccoding.com.au/tutorials/boost

Vamos instalar o *Boost*  versão 1.73. Você pode baixar o *Boost* através do navegador Web clicando nesse link: https://boostorg.jfrog.io/artifactory/main/release/1.73.0/source/boost_1_73_0.tar.gz

 Escolha alguma pasta do seu sistema (pode ser o Desktop, Downloads, home) e coloque o arquivo nela. Caso você deseje fazer download pelo terminal, use o comando (dentro da pasta do sistema):

```shell
wget -O boost_1_73_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.73.0/boost_1_73_0.tar.gz/download
```

Depois dentro dessa pasta do sistema, extraía com esse comendo:

```shell
tar -xf boost_1_73_0.tar.gz
```

Vamos instalar uns pacotes (talvez você já tenha instalado alguns, como por exemplo o *g++*, mas não tem problema):

```shell
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev libboost-all-dev
```

Seguir o resto das instruções daquele tutorial não deu certo para mim, vou continuar de outra maneira agora. 

Vamos entender as instalações de Python no sistema. Digite o comando no terminal:

```shell
python -V
```

e depois:

```shell
python3 -V
```

No meu sistema, o "`python`" é a biblioteca versão 2.7 e o "`python3`" é a biblioteca versão 3.8, no seu caso pode ser diferente. Nós precisamos encontrar onde estão os arquivos de instalação. Digite o comando:

```shell
which python3
```


Ele vai retornar o local da instalação de Python, no meu caso ele retornou "`/usr/bin/python3`". Agora precisamos encontrar a localização da versão específica que estamos utilizando, use o comando:

```shell
which python[versao]
```

No caso, você deve substituir o campo `[versao]`, no meu caso o comando foi:

```shell
which python3.8
```

No meu caso retornou "`/usr/bin/python3.8`". Agora vamos voltar a lidar com *Boost*. Rode o seguinte comando (dentro da pasta que o *Boost* foi extraído) dentro da pasta `boost_1_73_0`:

```shell
./bootstrap.sh --with-python=[local-de-instalação-do-python] --with-python-version=[versão-do-python] --with-python-root=[local-das-bibliotecas-do-python-versão-específica]
```


Você deve substituir os campos `[local-de-instalação-do-python]`, `[versão-do-python]`  e `[local-das-bibliotecas-do-python-versão-específica]`, esse é o resultado do comando `which python3`, trocando o `bin` por `lib`. No meu caso, ficou assim:

```shell
./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.8 --with-python-root=/usr/lib/python3.8
```

E depois vamos usar o comando para completar a instalação:

```shell
sudo ./b2 install
```

Pronto, se tudo parecer certo, é porque instalamos o *Boost*! 🎉✨

## Rodando Python.Boost

Agora vamos tentar criar um exemplo com o *Python.Boost* e tentar compilar.

Vamos criar um exemplo de uma função "hello world". Crie o arquivo "`hello_world.hpp`" e coloque o seguinte código:


```c
// hello_world.hpp

char const* greet()
{
   return "hello world!";
}
```

Depois crie o arquivo "`wrap.cpp`", que vai ser responsável por pegar as funções do "`hello_world.hpp`" e criar a biblioteca *Python*. Coloque o seguinte código:

```c
// wrap.cpp
#include <boost/python.hpp>
#include "hello_world.hpp"

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
```

Vamos compilar esse arquivo "`wrap.cpp`". O comando de compilação é bastante extenso:

```shell
g++ -Wall -Wextra -fPIC -shared -I[local-de-instalação-do-python-versão-específica] -I[local-do-include-de-python-versão-específica] wrap.cpp -o hello_ext.so -lboost_python[versao-do-python-sem-ponto] -lboost_numpy[versao-do-python-sem-ponto]
```

São vários campos que devem ser substituídos. `[local-das-bibliotecas-do-python-versão-específica]` a mesma coisa de anteriormente, a localização obtida quando pesquisamos `which python[versão]` trocando `bin` por `lib`. `[local-do-include-de python-versão-específica]` essa opção eu tive que adicionar pois o código estava dando um erro, não consegui encontrar a biblioteca "`pyconfig.h`". É o mesmo endereço do resultado de `which python[versão]` trocando `lib` por `include`. `[versao-do-python-sem-ponto]` deve ser o número da versão do Python sem o ponto, por exemplo, versão 3.8 vira 38.

No meu caso, o comando de instalação será assim:

```shell
g++ -Wall -Wextra -fPIC -shared -I/usr/lib/python3.8/ -I/usr/include/python3.8/ wrap.cpp -o hello_ext.so -lboost_python38 -lboost_numpy38
```

(No meu caso isso deu um *warning*, mas vamos ignorar por enquanto). Isso vai gerar um arquivo chamado "`hello_ext.so`", que vai ser o arquivo da biblioteca, para testar, vamos criar o código *Python* "`test.py`" com o seguinte conteúdo:

```python
# test.py
import hello_ext
print(hello_ext.greet())
```

Ao executar com o comando "`python3 test.py`" vamos obter o resultado no terminal "*hello world!*". 🎉✨

Instalar o *Boost* é bastante complicado, é uma biblioteca muito antiga e muito grande,  caso algo nesse tutorial não dê certo, tente dar uma olhada no Google para ver se alguém teve o mesmo problema. Pode falar comigo também caso haja algum problema.

Caso alguém também esteja sofrendo muito para instalar o *Boost*, existe uma outra biblioteca chamada [Pybind11](https://github.com/pybind/pybind11) que se vende como sendo mais fácil de instalar do que o Boost. Eu tentei instalar por mais ou menos 1h30min e não consegui, mas talvez seja mais fácil no seu computador.
