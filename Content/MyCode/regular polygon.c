#include <stdio.h>
#include <math.h>

typedef struct nome_da_estrutura_ponto
{
  float x;
  float y;
} ponto;

/*
  Dados n pontos (x, y), e ordenados de forma a definir um polígono regular. Calcular área do polígono pela integral método trapézio.
*/
int obter_numero_de_pontos()
{
  int numero_de_pontos;
  printf("Digite o numero_de_pontos a serem calculados: ");
  // scanf("%d", &numero_de_pontos);
  numero_de_pontos = 5;
  printf("%d\n\n", numero_de_pontos);
  return numero_de_pontos;
}

float min(float a, float b)
{
  float valor_retornado;
  // if (a<b) {
  //   valor_retornado = a;
  // } else {
  //   valor_retornado = b;
  // }
  valor_retornado = (a < b) ? (a) : (b);
  return valor_retornado;
}

float max(float a, float b)
{
  return (a > b) ? a : b;
}

void mostrar_vetor_pontos(int tamanho, ponto vetor_de_pontos[tamanho])
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("Ponto[%d]: (x,y)=(%.1f,\t%.1f)\n", i, vetor_de_pontos[i].x, vetor_de_pontos[i].y);
  }
}

void preenche_vetor_coord_polar(int num_lados, float raio, ponto vetor_pontos_polares[num_lados])
{
  float ang_circ = 360;
  int num_ang_int = num_lados;
  int ang_int_tri = ang_circ / num_ang_int;
  float ang_atual = 0;
  int i;
  for (i = 0; i < num_lados; i++)
  {
    vetor_pontos_polares[i].x = raio;
    vetor_pontos_polares[i].y = ang_atual;
    ang_atual += ang_int_tri;
  }
}

void tornar_coord_positivas(int num_lados, ponto vetor_cartesiano[num_lados])
{
  printf("\n\nESSE É O VETOR CARTESIANO NEGATIVO:\n");
  mostrar_vetor_pontos(num_lados, vetor_cartesiano);
  int i;
  float min_x = vetor_cartesiano[0].x;
  float min_y = vetor_cartesiano[0].y;
  for (i = 1; i < num_lados; i++)
  {
    if (vetor_cartesiano[i].x < min_x)
    {
      min_x = vetor_cartesiano[i].x;
    }
    if (vetor_cartesiano[i].y < min_y)
    {
      min_y = vetor_cartesiano[i].y;
    }
  }
  for (i = 0; i < num_lados; i++)
  {
    vetor_cartesiano[i].x -= min_x;
    vetor_cartesiano[i].y -= min_y;
  }
  printf("\n\nESSE É O VETOR CARTESIANO POSITIVO:\n");
  mostrar_vetor_pontos(num_lados, vetor_cartesiano);
}

void preenche_vetor_coord_cartesiana(int num_lados, ponto vetor_polar[num_lados], ponto vetor_cartesiano[num_lados])
{
  int i;
  float raio_atual;
  float angulo;
  float seno_atual, cos_atual, rad;
  float pi = atan(1) * 4;
  float to_rad = pi / 180;

  for (i = 0; i < num_lados; i++)
  {
    raio_atual = vetor_polar[i].x;
    angulo = vetor_polar[i].y;
    rad = angulo * to_rad;
    vetor_cartesiano[i].x = raio_atual * sin(rad);
    vetor_cartesiano[i].y = raio_atual * cos(rad);
  }

  tornar_coord_positivas(num_lados, vetor_cartesiano);
}

float calcular_area_trapezio(float base1, float base2, float altura)
{
  float area_trapezio = (base1 + base2) * altura / 2;
  return area_trapezio;
}

float calcular_integral_metodo_trapezio(int num_lados, ponto vetor_cartesiano[num_lados])
{
  float x1, x2, y1, y2;
  printf("\n\n");
  int i;
  float area_total = 0, area_atual;
  for (i = 1; i < num_lados; i++)
  {
    x1 = vetor_cartesiano[i - 1].x;
    y1 = vetor_cartesiano[i - 1].y;
    x2 = vetor_cartesiano[i].x;
    y2 = vetor_cartesiano[i].y;
    printf("(x1, y1)=(%.1f, %.1f)\n", x1, y1);
    printf("(x2, y2)=(%.1f, %.1f)\n\n", x2, y2);

    float base1 = y1;
    float base2 = y2;
    float altura = x2 - x1;
    area_atual = calcular_area_trapezio(base1, base2, altura);

    float base1_red = min(y1, y2);
    float base2_red = min(y1, y2);
    float alt_red = x2 - x1;
    float area_atual_reduzida = calcular_area_trapezio(base1_red, base2_red, alt_red);

    area_total += area_atual;
    area_total -= area_atual_reduzida;
  }
  return area_total;
}

void gerar_pontos_de_um_polígono(int num_lados)
{
  /*
    lados [3, infinito[
    raio  ]0, infinito[
    angulo circulo = 360
    quant de triangulos internos = lados
    angulo interno triangulo = angulo circulo / triangulos internos
  */

  float raio = 1.0;
  ponto vetor_pontos_polares[num_lados];
  ponto vetor_pontos_cartesianos[num_lados];
  preenche_vetor_coord_polar(num_lados, raio, vetor_pontos_polares);
  preenche_vetor_coord_cartesiana(num_lados, vetor_pontos_polares, vetor_pontos_cartesianos);

  // printf("\n\nVETOR POLAR:\n");
  // mostrar_vetor_pontos(num_lados, vetor_pontos_polares);
  // printf("\n\nVETOR CARTESIANO:\n");
  // mostrar_vetor_pontos(num_lados, vetor_pontos_cartesianos);

  float area_final = calcular_integral_metodo_trapezio(num_lados, vetor_pontos_cartesianos);
  printf("AREA TOTAL: %.2f", area_final);
}

int main()
{
  int numero_de_lados_do_poligono = 4;
  // int numero_de_lados_do_poligono = obter_numero_de_pontos();
  gerar_pontos_de_um_polígono(numero_de_lados_do_poligono);
}