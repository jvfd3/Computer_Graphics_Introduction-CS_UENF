# Computação Gráfica - Rivera
<!--
Reproduzir em forma descritiva todos os tópicos abordados no capítulo 1. Podem adicionar novas abordagens dos tópicos abordados. Não será considerado trabalhos extensos e copias.
-->
## Plataforma para desenvolvimento

- Ambiente Windows
  - Compiladores Visual C
  - Fonte pode ser compilável em Linux
- Ambiente Linux
  - gcc / g++
- Bibliotecas Gráficas
  - OpenGL y Glut
  - OpenGL y FLTK
  - OpenGL y IUP
  - Iup y CV

## Compilado

- Tempo REAL
  - Ex. Elisson - Avatares

## Bibliografía

- Computação Gráfica – Eduardo Azevedo y Aura
Conci
- Computer Graphics - Principles and Practice Foley - van Dam - Feiner - Hughes 2nd edition in C - Addison and Wesley
- Notas do Curso ministrado na Universidade de Maryland pelo Prof. David Mount
  - [Nota 1](ftp://ftp.cs.umd.edu/pub/faculty/mount/427/427lects.ps.gz)
  - [Nota 2](http://www.lcg.ufrj.br/~esperanc/CG/427lects.ps.gz)

## O que é Computação Gráfica?

- Conjunto de ferramentas e técnicas para converter dados para o de um dispositivo gráfico através do computador
  - Imagens geradas por computador
  - Operações de objetos gráficos
  - Usados em: revistas, jogos, web, cinema, televisão, etc.
- Computação gráfica, Arte e Matemática

## Origens da Computação Gráfica (1)

- 1950 - MIT (fins militares): Whirlwind
  - Visualizar dados numéricos
- \[2 imagens\]

## Origens da Computação Gráfica (2)

- 1955 - Defensa Área Americana: Whirlwind I
  - SAGE: Sistema gráfico para monitorar de vôs
    - Radar oferece dados - Uso de caneta ótica
- \[3 imagens\]

## Origens da Computação Gráfica (3)

- 1959: COMPUTER GRAPHICS (Verne Hudson)
  - PROJETO BOEING
    - Simulador de fatores humanos em aviões
- \[1 imagem\]

## Origens da Computação Gráfica (4)

- 1962: Ivan Sutherland (A Man-Machine Graphical
Comunication System)
  - Estrutura de dados espaciais
  - CAD
    - General Motors
    - Aeroespacial
- \[1 imagem\]

## Origens da Computação Gráfica (5)

- 1970: Métodos de Sombreamento (Z-Buffer)
  - Interface gráfico (Macintosh, 1975)
  - Computação Gráfica como área da Ciência da Computação
  - Aparece SIGGRAPH
  - Livros de computação gráfica
- \[2 imagens\]

## Origens da Computação Gráfica (6)

- 1980: Plume 2 (Scientific American): imagem de erupção vulcânica no
espaço (Voyager I) – processamento de imagem
  - Processamento de dados
  - Técnicas de iluminação (Ray-tracing, 1980 e radiosidad, 1984)
- \[4 imagens\]

## Origens da Computação Gráfica (7)

- 1990: Cinemas
  - Jurassic Park (1993),
  - Exterminador del futuro 2,
  - Toy Store (1995),
  - Placas Gráficas NVIDIA (1999).
- \[2 imagens\]

## Origens da Computação Gráfica (8)

- 2000: Orientado a PC
  - Shrek, Matrix Reloader, Jogos interativos, etc.
- \[3 imagens\]

## Primeira Generação <!-- Stopped here -->
(WireFrame – até 1987)
- Vértices: transformações, projeções
- Rasterização: interpolação de cores (pontos e retas)
- Fragmentos: overwrite

- Primeiros projetos desenvolvidos por computador

## Segunda Geração

(Sólidos com Sombreamento – 1982 - 1992)
- Vértices: cálculo de luz
- Rasterização: interpolação de profundidade (triângulos)
- Fragmentos: depth buffer, color blending

## Terceira Geração

(Texturização: 1992 - 2000)
- Vértices: transformação de coordenada de textura
- Rasterização: interpolação de coordenada de textura
- Fragmentos: evaluação de textura, antialiasing

## Quarta Geração

(Programação: 2000 - 2002)
- Sombreamento programado
- Image-based rendering
- Convergência das medias de produção
- Superfícies curvas

## Quinta Geração

(Iluminação Global: 2002 - atual)
- Ray tracing / Radiosidade: visibilidade e integração
- True shadows, path tracing, photon mapping

## Computação Gráfica, Arte e Matemática

- Ferramenta não convencional de produção de arte
- Imagens geradas a partir das equações que podem ser
consideradas arte
- Maior poder de abstração

Imagem
generada por
equações
fractais

## Áreas de Computação Gráfica

- Síntese de Imagens
- Análise de Imagens
  - Pattern Recognition

- Processamento de Imagens
- Visualização Computacional

## Computação Gráfica

Análise
(reconhecimento de
patrões)

Modelos
Matemáticos

Imágens

Síntese

(rendering)

Modelagem

Processamento
de Imágens

## Disciplinas relacionadas

- Computação
  - Algoritmos
  - Estruturas de Dados
  - Inteligência Artificial
  - Métodos Numéricos

- Matemática
  - Diferencial e Integral
  - Geometria,
  - Álgebra Linear
  - Processos estocásticos

- Física
  - Ótica
  - Mecânica

- Psicologia
  - Percepção
  - Cognição

- Artes

## Aplicações

- Desenho Assistido por Computador (CAD)
- Desenho Geométrico Assistido por Computador
(CAGD)
- Sistemas de Informações Geográficas (GIS)
- Visualização Científica
- Visualização Médica
- Educação
- Entretenimento
- Interfaces humano-computador
- Outros

## Dispositivos Gráficos

- Dispositivos vetoriais
  - Terminais gráficos vetoriais (obsoletos)
  - Plotters
  - Dispositivos virtuais
- Ex.: Linguajes de descrição de página (HPGL /
Postscript)
- Rasterização implícita

- Dispositivos Matriciais
  - Praticamente sinônimo de dispositivo gráfico
  - Impressoras, displays

## Displays

- Resolução espacial
  - Tipicamente de 640x480 até 1600x1200
  - Tendência de aumento
- Resolução no espaço de cor
  - Monocromático (negro e branco)
  - Tabela de cores

- Cada pixel é representado por um número (tipicamente 8 bits
– de 0 a 255) que indexa uma tabela de colores (tipicamente
RGB 24 bits)
- Poucas (ex.: 256) colores simultâneas mas cada cor pode ser
escolhida de um universo grande (ex.: 224)
- Problema da quantização de cores

  - RGB

- Cor expressada por quantidades discretas de vermelho (red),
verde (green) e azul (blue)
- Tipicamente 24 bits (8 bits para cada componente)

## Arquitetura de Sistemas Gráficos (1)

CPU

Periféricos

Arquitetura Simples

Barramento (BUS)

Memória

Frame
Buffer

Controlador
de vídeo

Monitor

## Arquitetura de Sistemas Gráficos (2)

CPU

Periféricos
Arquitetura
com processador
gráfico

Barramento (BUS)

Memória
do
Sistema

Processador
gráfico

Memória

Frame
Buffer
Monitor
Controlador de
vídeo

## Processador (acelerador) gráfico

- Hardware especializado
- Uso de paralelismo para atingir alto desempenho
- Libera o CPU do sistema de algumas tarefas, incluindo:
  - Transformações
- Rotação, translação, escala, etc.

  - Recorte (clipping)
- Supressão de elementos fora da janela de visualização

  - Projeção (3D →2D)
  - Mapeamento de texturas
  - Rasterização
  - Pontos de curvas y superfícies paramétricas
- Geração de pontos a partir de formas polinomiais

- Normalmente usa memória separada do sistema
  - Maior banda
