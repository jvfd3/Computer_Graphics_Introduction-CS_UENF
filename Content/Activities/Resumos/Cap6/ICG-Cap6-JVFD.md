# Representação e Modelagem

Aluno: João Vítor Fernandes Dias
Professor: Luis Antonio Rivera Escriba

<!--
Já tá semi pronto feito em aula.

Comecei:    15/02/23 -  18h27
Finalizei:  15/02/23 -  ...
Duração:                
-->

## Introdução

Para realizar uma simples animação, muitos polígonos são criados e precisam ser guardados e manipulados. Cada um deles sofrem inúmeros cálculos para computar qual o seu comportamento esperado. Para lidar com isso tudo, é necessário haver um armazenamento apropriado e também eficiência suficiente para realizar os cômputos em tempo adequado.

À medida em que o poder de processamento aumenta, acaba havendo a capacidade do desenvolvimento de novas simulações gráficas ainda mais realísticas.

<!--
[Se vem o urso, sinal de que ele tá sendo perseguido]
-->

Para haver esta representação gráfica, é necessário primeiro haver a modelagem. Isto demanda do desenvolvedor muita intuição para alcançar a imagem final que visa representar. Além disso, demanda também conhecimento e experiência para que possa criar modelos de acordo com a realidade e uma boa percepção das pessoas que futuramente verão.

## Pivô

Cada vez que um objeto é criado ele surge com um Centro de Referência Local. Com ele é possível realizar as operações de transformação geométrica.

## Sólidos Uni, Bi e Tridimensionais

Um sólido pode ser definido como um subconjunto fechado e limitado de um Espaço Euclidiano Tridimensional ($E^3$).

Tempos também as figuras bidimensionais como polígonos. E as curvas unidimensionais.

**Observações:**

Os cálculos de produtos vetoriais das faces sempre têm que ser de mesmo sinal, senão quer dizer que a face está voltada para uma região que não deveria, similar a um sólido convexo, logo não sendo considerado um sólido adequado

Os ângulos internos não podem ser nem passar de 180°.

## Sólidos Realizáveis

Os sólidos realizáveis são aqueles que, ao seguir um determinado conjunto de propriedades, se aproxima de um sólido real.

As propriedades são as seguintes:

- Rigizes: não varia sua forma nem posição de acordo com sua posição ou orientação
<!-- Um tesseract então não seria rígido? Pois ele em 3D aparenta mudar de posição -->
- Finitude: está contido em uma dimensão finita
- Homogeneidade: Todos os pontos são exatamente iguais entre si e apresentam as mesmas características
- Determinação dos limites: Os limites entre interior e exterior são identificáveis
- Descritibilidade: possível de ser descrito segundo propriedades físicas, químicas, etc.
- Operações fechadas: operações entre os objetos devem ser válidas.

Obs.: Klein Bottle: é realizável.

## Formas de representação do objeto

Cada objeto pode ser representado de diversas formas diferentes. Abaixo são exemplificados algumas dessas formas.

### Wireframe

Uma das formas de representar o objeto é a forma "aramada". Neste caso, a visualização é composta apenas por arestas e vértices.
A vantagem é que é rápido de exibir, entretanto, por haver poucas superfícies ilustradas, acaba havendo maior dificuldade para realizar operações como intercessão, visto que não é facilmente computável onde que a intercessão ocorre.

### Faces

Ao representarmos os objetos por faces limitantes, conseguimos obter superfícies fechadas e orientadas.

Nela, as arestas são definidas pelos vértices que a limitam e quais são as duas faces com as quais ela se conecta.

Para um objeto ser 2-manifold é necessário que ele não seja composto por dois objetos aparentes que estejam apenas costando entre si em um único ponto ou aresta.

#### Faces poligonais

Nesta vertente, utilizam-se de polígonos definidos para gerar a figura.

Pode-se utilizar essa propriedade para realizar o Tesselation (Tiling) que consistem em cobrir uma área plana utilizando estes polígonos.

O benefício desse método é que ele apresenta maior facilidade para rendering, visto que com polígonos já pre definidos, há menor variedade de formas a serem computadas.

### Fórmula de Euler

V - A + F = 2

Também aplicado à fórmula de Euler.

### Estrutura de dados

#### baseada em vértices

Essa estrutura consiste em duas tabelas: a primeira é a definição de Vértice-Coordenadas (A: (0,0,0), B: (1,0,1), ...); a segunda é a definição de faces-Vértices (F1: ABCD, ...):. Sempre sendo representados em um mesmo sentido. Senão na hora do cálculo de luminosidade a face fica invertida.

<!-- Pesquisar imagem que represente isso -->

#### baseada em arestas

Segue uma estrutura similar à anterior, mas dessa vez as faces são definidas por areastas e não por vértices. E há uma nova tabela equivalendo cada aresta a um par de vértices. A sequência das arestas também precisa estar em sentido horário ou anti-horário. Uma aresta sempre separa duas faces em um objeto.

#### Winged-Edge e half Winged-edge

Para cada aresta é definido qual é a face que se encontra à esquerda e à direita dela.

### Decomposição do espaço em Octree

Forma 3d do Quadtree.

Algoritmo recursivo para ir segmentando o objeto em paralelepídeos menores. Esses menores são definidos como vazios, cheios ou parciais. Apenas o que nos interessa é o parcial.

## Técnicas de Modelagem Geométrica

- ...

### Instanciamento de primitivas

Cada primitiva é um objeto simples. Cada novo objeto é criado por transformações geométricas

### Geometria Sólida Constructiva - CSG: Constructive Solid Geometry

Uso de operações: Interseção, união e Subtração

## Trabalho

Um sólido com N faces e  número de arestas variadas usando estrutura de dados baseada e vértices e faces.

Shear:
$$
  \begin{bmatrix}
    1 && k \\
    0 && 1
  \end{bmatrix}
  \begin{bmatrix}
    x \\ y
  \end{bmatrix}
  \begin{bmatrix}
    x + k*y \\ y
  \end{bmatrix}\\
  x + K*y = x + \Delta x \\
  K*y = \Delta x \\
  k = \frac{\Delta x}{y} \\
$$

<!-- Isso é camisa de maconha -->