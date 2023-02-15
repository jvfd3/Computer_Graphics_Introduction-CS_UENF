# Representação e Modelagem - WIP

Aluno: João Vítor Fernandes Dias
Professor: Luis Antonio Rivera Escriba

## Representação e Modelagem

Para realizar uma simples animação, muitos polígonos são criados e precisam ser guardados e manipulados. Cada um deles sofrem inúmeros cálculos para computar qual o seu comportamento esperado. Para lidar com isso tudo, é necessário haver um armazenamento apropriado e também eficiência suficiente para realizar os cômputos em tempo adequado.

À medida em que o poder de processamento aumenta, acaba havendo a capacidade do desenvolvimento de novas simulações gráficas ainda mais realísticas.

<!-- [Se vem o urso, sinal de que ele tá sendo perseguido] -->

Para haver esta representação gráfica, é necessário primeiro haver a modelagem. Isto demanda do desenvolvedor muita intuição para alcançar a imagem final que visa representar. Além disso, demanda também conhecimento e experiência para que possa criar modelos de acordo com a realidade e uma boa percepção das pessoas que futuramente verão.

## Pivô

Cada vez que um objeto é criado ele surge com um Centro de Referência Local. Com ele é possível realizar as operações de transformação geométrica.

## Sólidos Uni, Bi e Tridimensionais

...

Bidimensional:

os cálculos de produtos vetoriais sempre têm que ser de mesmo sinal, senão quer dizer que elee foi pra um lado que não deveria, logo, convexo, logo não sendo adequado

Os ângulos internos não podem ser nem passar de 180°.

## Sólidos Realizáveis

Klein Bottle: é realizável.

Propriedades:

- Rígido
- Finito
- Homogêneo: Todos os pontos são exatamente iguais entre si.
- Determinação dos limites: Conseguimos definir
- Descritível
- Operações fechadas

## Formas de representação do objeto

### alambrado

Uma das formas de representar o objeto é a forma "aramada". Neste caso, a visualização é composta apenas por arestas e vértices.
A vantagem é que é rápido de exibir, entretanto, por haver poucas superfícies ilustradas, acaba havendo maior dificuldade para realizar operações como intercessão, visto que não é facilmente visualizável onde que a intercessão ocorre.

### por faces

Para um objeto ser 2-manifold é necessário que todas as partes dele tenham uma intercessão com algum outro. (clipping)

### Faces poligonais

Tesselation (ou tiling): Cobrir uma área plana

...

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