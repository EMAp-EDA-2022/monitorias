# Dúvidas

Algumas dúvidas respondidas podem ser importantes para mais de uma pessoa, por esse motivo estou organizando aqui os assuntos que já comentei com alguém.

## QuadTree

> Por que a QuadTree está com pontos na divisão do espaço?

Existem dois tipos comuns de QuadTree, a Point Region QuadTree e a Point QuadTree. Ambas dividem sub-regiões (quadradas) em 4 dividindo na cordenada x e na coordenada y, a diferença é que a Point Region divide ambas as coordenadas na metade, enquanto que a Point divide na coordenada do ponto.
Por exemplo, suponha uma QuadTree no intervalo $[0, 1] \times [0, 1]$ sem pontos, o primeiro a ser adicionado é o ponto $(0.3, 0.2)$. A Point Region vai dividir a coordenada x na posição $0.5$ e a cordenada y na posição $0.5$, o ponto ficará na sub-divisão sudoeste (SW). A Point vai dividir horizontalmente x na coordenada $0.3$ e y na coordenada $0.2$, e os quadrados que surgiram da subdivisão permancerão vazios.

Referência adicional: https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/quadtrees.pdf

> Na figura da lista 6, por que os pontos E e H não estão na divisão de quadrados?

Essa foi uma decisão de representação, porque os pontos E e H na realidade estão dividindo o quadrado em que estão presente sim. Só que essa divisão não é marcada na figura pois eles não tem nós filhos, os quatro quadrados que foram da sua divisão estão vazios.

> Como se remove um ponto da Point QuadTree?

Algoritmos eficientes de remoção da Point QuadTree são bastante complexos. Com isso, uma das maneiras simples de se resolver (e comumente utilizada) é remover o nó, caso esse nó tenha filhos (sub-árvore), remova todos e adicione novamente. Existe uma ordem convencionada sobre quais adicionar primeiro. A ordem de reinseção é (NW, NE, SW, SE), e adicionamos os filhos de NW antes de adicionar os filhos de NE.

## R-Tree

A R-Tree não é uma estrutura com muitos textos básicos disponíveis online. Uma referência é o artigo original que propôs a estrutura, que apresenta os algoritmos básicos sem muita complexidade de terminologia: http://www-db.deis.unibo.it/courses/SI-LS/papers/Gut84.pdf

> O que o `insert` receberia?

Na nossa implementação, a função `insert` vai receber um ponto (de duas coordenadas) e possívelmente algum valor extra. Com esse ponto, nós vamos percorrer a árvore até chegar em uma folha, cada folha representa um retângulos (todos nós representam retângulos). Pode ser que encontremos uma folha com um retângulo que contém o ponto, mas pode ser também que o ponto não esteja dentro de nenhum retângulo. No primeiro caso, adicionamos o filho, no segundo caso, precisamos aumentar o retângulo de alguma folha para "caber" o ponto.
