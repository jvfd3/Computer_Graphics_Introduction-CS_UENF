# Computação Gráfica - João Vítor Fernandes Dias
<!--
    Reproduzir em forma descritiva todos os tópicos abordados no capítulo 1. Podem adicionar novas abordagens dos tópicos abordados. Não será considerado trabalhos extensos e copias.
-->
## Plataforma para desenvolvimento

Para o desenvolvimento de aplicações utilizando computação gráfica dispomos da [OpenGL][L_OpenGL] que, segundo a [Professora Isabel Harb Manssour][L_OpenGL_cite], "é uma biblioteca de rotinas gráficas e de modelagem, bi (2D) e tridimensional (3D), extremamente portável e rápida. Usando OpenGL é possível criar gráficos 3D com uma qualidade visual próxima de um ray tracer."

Contamos também com o [GLUT][L_Glut] podemos implementar interfaces gráficas de forma mais simplificada; o [FLTK][L_FLTK] que apresenta um conjunto de ferramentas para o desenvolvimento de interfaces multi-plataformas; e o [IUP][L_IUP] que também é multi-plataformas e dispõe de uma API nas linguagens C, Lua e LED.

[L_OpenGL]: https://www.opengl.org/
[L_OpenGL_cite]: https://www.inf.pucrs.br/~manssour/OpenGL/Introducao.html#:~:text=%C3%A9%20uma%20biblioteca%20de%20rotinas%20gr%C3%A1ficas%20e%20de%20modelagem%2C%20bi%20(2D)%20e%20tridimensional%20(3D)%2C%20extremamente%20port%C3%A1vel%20e%20r%C3%A1pida.%20Usando%20OpenGL%20%C3%A9%20poss%C3%ADvel%20criar%20gr%C3%A1ficos%203D%20com%20uma%20qualidade%20visual%20pr%C3%B3xima%20de%20um%20ray%20tracer.
[L_Glut]: https://www.opengl.org/resources/libraries/glut/glut_downloads.php
[L_FLTK]: https://www.fltk.org/
[L_IUP]: https://www.tecgraf.puc-rio.br/iup/en/home.html

## Compilado

Como a computação gráfica exige muitos cálculos, mostra-se necessária o uso de programas computacionais adequadamente ágeis. Para isso, uma boa prática é utilizar linguagens de programação que são compiladas, pois estas tendem a ter maior velocidade e responder em tempo real. Esta agilidade se dá devido à não necessidade de tradução do código que as linguagens interpretadas demandam, o que as tornam lentas. [(FreecodeCamp)][VelocidadeCompilada]

[VelocidadeCompilada]: https://www.freecodecamp.org/portuguese/news/linguagens-de-programacao-interpretadas-x-compiladas-qual-e-a-diferenca/#:~:text=Vantagens%20das%20linguagens%20compiladas

## Bibliografia

- [Computação Gráfica – Eduardo Azevedo y Aura Conci][Bib_A]
- [Computer Graphics - Principles and Practice Foley - van Dam - Feiner - Hughes 2nd edition in C - Addison and Wesley][Bib_B]
- Notas do Curso ministrado na Universidade de Maryland pelo Prof. David Mount
  - [Nota 1][Bib_C]
  - [Nota 2][Bib_D]

[Bib_A]: https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxpYWNvbXB1dGFjYW9ncmFmaWNhfGd4OjU5ZWM3OGRjMTUwNWIwODM
[Bib_B]: https://www.cs.ucy.ac.cy/courses/EPL426/courses/eBooks/ComputerGraphicsPrinciplesPractice.pdf
[Bib_C]: ftp://ftp.cs.umd.edu/pub/faculty/mount/427/427lects.ps.gz
[Bib_D]: http://www.lcg.ufrj.br/~esperanc/CG/427lects.ps.gz

## O que é Computação Gráfica?

A computação gráfica consiste no uso de ferramentas computacionais com o objetivo de gerar representações visuais. Esse processo ocorre através de cálculos matemáticos para definir quais cores devem estar em quais posições da tela para que assim representem algum formato ou imagem. Seu uso varia desde jogos de computadores até a sétima arte.

## Origens da Computação Gráfica

Assim como boa parte das tecnologias computacionais em seus primórdios, a computação gráfica deu seus primeiros passos rumando a finalidade militar dos Estados Unidos nos anos 50. Com o tempo, passou a ser utilizada para outros fins por grandes empresas como por exemplo a Boeing que a utilizou para simular fatores humanos em aviões.

Com o tempo, a tecnologia foi se aperfeiçoando e tomando novos rumos. Ela passou a ser amplamente utilizada em outras áres como nos programas [CAD (Computer Aided Design)][L_CAD]. Para isso novos algoritmos foram surgindo, assim como o método de sombreamento [(Z-Buffer)][ZBuffer], [ray-tracing][RayTracing], gradualmente se tornando uma área distinta na Ciência da Computação.

Nos anos 90 a computação gráfica passou a ser mais utilizada na indústria do entretenimento com filmes e na primeira década do século XXI, jogos.

[L_CAD]: https://en.wikipedia.org/wiki/Computer-aided_design
[ZBuffer]: https://en.wikipedia.org/wiki/Z-buffering
[RayTracing]: "https://en.wikipedia.org/wiki/Ray_tracing_(graphics)"

## Gerações

O desenvolvimento da computação gráfica passou por diversos segmentos relevantes em relação ao nível de sua tecnologia, cada uma com suas características específicas:

### Primeira: ] Início, 1987]

A primeira geração traz a estrutura base para a computação gráfica que consiste do uso de triângulos, o polígono com menor número de lados, para traçar a superfície de um objeto através da interligação dos vértices. Essa estrutura passou a ser chamada de [WireFrame][L_WireFrame].

[L_WireFrame]: https://en.wikipedia.org/wiki/Wire-frame_model

### Segunda: ] 1982, 1992]

Em seu segundo avanço notável, temos os sólidos com sombreamento obtidos ao se realizar cálculos de luz em cada um dos vértices dos triângulos que compõem o objeto. Operações obtidas através das técnicas de [rasterização][Raster], [Depth Buffer][ZBuffer] e [Color][ColorBlending1] [Blending][ColorBlending2].

[Raster]: https://en.wikipedia.org/wiki/Raster_graphics
[ColorBlending1]: https://cglearn.codelight.eu/pub/computer-graphics/blending
[ColorBlending2]: https://www.cs.csustan.edu/~rsc/SDSU/Color.Blending.pdf

### Terceira: ] 1992, 2000]

Em sua terceira geração contamos com a chegada da transformação de coordenadas de [textura][Texture] e o [anti][L_Antialiasing]-[aliasing][L_Aliasing].

[Texture]: https://en.wikipedia.org/wiki/Texture_mapping
[L_Antialiasing]: https://en.wikipedia.org/wiki/Anti-aliasing
[L_Aliasing]: https://en.wikipedia.org/wiki/Aliasing

### Quarta: ] 2000, 2002]

A quarta geração traz um [sombreamento mais avançado][ShadowVolume], [renderização baseada em imagens][ImageBasedRendering] e superfícies curvas.

[ShadowVolume]: https://en.wikipedia.org/wiki/Shadow_volume
[ImageBasedRendering]: https://en.wikipedia.org/wiki/Image-based_modeling_and_rendering

### Quinta: ] 2002, Hoje[

Com a quinta e última geração, até o presente momento, os conceitos de [Ray-tracing][RayTracing] e [radiosidade][Radiosidade], e também os conceitos de True [Shadows][Sombras], [path tracing][PathTracing] e [photon][PhotonMapping1] [mapping][PhotonMapping2].

[Radiosidade]: https://www.cin.ufpe.br/~marcelow/Marcelow/programacao%20pg_files/radiosidade.pdf
[Sombras]: https://cglearn.codelight.eu/pub/computer-graphics/shadows
[PathTracing]: https://blogs.nvidia.com/blog/2022/03/23/what-is-path-tracing/
[PhotonMapping1]: https://en.wikipedia.org/wiki/Photon_mapping
[PhotonMapping2]: https://web.cs.wpi.edu/~emmanuel/courses/cs563/write_ups/zackw/photon_mapping/PhotonMapping.html

## Computação Gráfica, Arte e Matemática

Como dito, a computação gráfica, através de cálculos matemáticos, já foi utilizada até mesmo em filmes cinematográficos. Recentemente tendo até ocorrido, em abril de 2022, o anúncio do [DALL-E 2][DallE2] que reproduz imagens fotorealistas através de descrições textuais. Representações estas que possuem a capacidade de confundir-se com obras de arte humanas.

[DallE2]: https://openai.com/dall-e-2/

## Áreas de Computação Gráfica

A computação gráfica, ao se estabelecer como uma das áreas da Ciência da Computação, acabou, por sua vez, adquirindo também para si diversas sub-áreas, tais como:

- [Síntese de imagens][ImageSynthesis]
- [Análise de imagens][ImageAnalysis]
  - [Pattern Recognition][PatternRecognition]
- [Processamento de imagens][ImageProcessing]
- [Visualização computacional][VisãoComputaciona]

[ImageSynthesis]: https://www.sciencedirect.com/topics/engineering/image-synthesis
[ImageAnalysis]: https://en.wikipedia.org/wiki/Image_analysis
[PatternRecognition]: https://en.wikipedia.org/wiki/Pattern_recognition
[ImageProcessing]: https://www.cl.cam.ac.uk/teaching/1998/CGraphIP/cgip.pdf
[VisãoComputaciona]: https://pt.wikipedia.org/wiki/Vis%C3%A3o_computacional

## Computação Gráfica

Colocando então de um modo geral, a Computação gráfica atualmente não apenas gera imagens, mas também contrói modelos matemáticos baseados em imagens já existentes.

Inicialmente a computação gráfica utilizava da modelagem matemática de vértices e superfícies para que, através da síntese (rendering) uma imagem fosse gerada. Atualmente já é possível, através do processamento de imagens haver a análise (reconhecimento de padrões) para gerar modelos matemáticos referentes à imagem analisada.

## Disciplinas relacionadas

A computação gráfica acaba então sendo uma área multidisciplinar. Tendo surgido no campo da **computação** contendo *algoritmos*, *estruturas de dados* e alcançando um novo patamar com a *inteligência artificial*, tem em suas raízes a **física** ao lidar com a *mecânica* da interação entre objetos e a *ótica* da visualização das imagens. A **física** por sua vez depende amplamente da **matemática** e das suas várias ferramentas como *equações diferenciais e integrais*, *geometria*, *álgebra linear* e *processos estocásticos*. Por fim, não podemos deixar de citar também as áreas envolvidas no processo como a **psicologia** que lida com a *cognição* e *percepção*; e as **artes** já citadas.

## Aplicações

Além das aplicações iniciais como [CAD][L_CAD] e visualizações envolvendo aeronaves, outras aplicações incluem o seu uso na [medicina][CG_medicine], [educação][CG_education], [entretenimento][CG_entertainment], dentre outros.

[CG_medicine]: https://www.inf.pucrs.br/~manssour/Publicacoes/tutorial-cg&m.pdf
[CG_education]: https://www.thectejournal.com/uploads/1/0/6/8/10686931/bajracharya_computer_graphics_applications.pdf
[CG_entertainment]: https://www.insider.com/most-groundbreaking-cgi-movies-ever-created-2020-1

## Dispositivos Gráficos <!-- Não entendi direito -->

Os dispositivos gráficos utilizados para se visualizar toda essa complexidade abordada podem ser vetoriais ou matriciais. Os terminais vetoriais, atualmente já se encontram obsoletos, mas deram espaço para o surgimento de plotters e também de outras ferramentas virtuais. Os matriciais por sua vez, tendem a apresentar a visualização gráfica em duas dimensões, ao se utilizar de impressoras e displays de vídeo.

## Displays

Os displays ao longo dos anos vêm aumentando sua resolução, sendo ela tipicamente entre 640x480 e 1600x1200. Em seu início era monocromático, representando apenas o preto e o branco, ou, de acordo com a tela, alguma outra cor que se assemelhasse ao preto. Atualmente já conta com uma ampla de cores, geralmente simplificada pela divisão da mesma em três diferentes canais de cores: vermelho, verde e azul, também conhecido como [RGB][L_RGB]. Cada um desses canais apresentando um valor que varia de 0 a 255 usando o espaço de 8 bits de memória.

[L_RGB]: https://en.wikipedia.org/wiki/RGB_color_model

## Arquitetura de Sistemas Gráficos

Os sistemas gráficos têm sua arquitetura geral composta por uma CPU que é ligada à periféricos através do barramento.

Esta arquitetura geral apresenta duas vertentes: a simples e a que contém processamento gráfico.

Na arquitetura simples, temos a conexão do barramento com a memória que armazena temporariamente frames em um buffer que é utilizado pelo controlador de vídeo também contectado ao barramento. O controlador de vídeo por sua vez decide quando deve mostrar este frame armazenado ao monitor.

Por outro lado, na arquitetura mais complexa, temos o sistema com sua própria memória conectada ao barramento, assim como está também conectado o proessador gráfico. Ele por sua vez se conecta à memória e ao buffer de frames que, assim como na arquitetura simples são gerenciados e exibidos no monitor pelo controlador de vídeo.

## Processador (acelerador) gráfico

Como já foi repetidamente comentado sobre a gama matemática envolvida na computação gráfica, fez-se necessária o desenvolvimento de hardware especializados para tal função. Estes hardwares contam com o conceito de [paralelismo][Paralelism] para aumentar seu desempenho. Assim podendo garantir parte do processamento da CPU e um armazenamento próprio para tarefas amplamente utilizadas da computação gráfica como:

- [Transformações][Transformations]
  - [Rotação][Rotation]
  - [Translação][Translation]
  - etc.
- [Recorte][Clipping]
- [Projeção][Projection]
- [Mapeamento de texturas][Texture]
- [Rasterização][Raster]
- etc.

[Paralelism]: https://en.wikipedia.org/wiki/Parallel_computing
[Transformations]: https://www.javatpoint.com/computer-graphics-introduction-of-transformations
[Rotation]: https://www.javatpoint.com/computer-graphics-rotation
[Translation]: https://www.javatpoint.com/computer-graphics-translation
[Clipping]: https://www.javatpoint.com/computer-graphics-clipping
[Projection]: https://www.javatpoint.com/computer-graphics-projection
