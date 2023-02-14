#include "GL/glut.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTEXS 30
#define PHI 3.141572
GLenum doubleBuffer;

typedef struct spts {
    float v[3];
} tipoPto;

// tipoPto ppuntos[MAXVERTEXS];

tipoPto pvertex[MAXVERTEXS]; // vetor de MAXVERTEXS de v[3] como espaco maximo

// medidas das dimensoes da janela Canvas: W-Width-largura  H-Height-altura
int windW = 300, windH = 300;
int tipoPoligono;    // poligono preenchido, contorno ou pontos nos vertices
int gNumVert = 0;    // numero de pontos ou vertices do poligono criado
int jaPoligono = 0;  // modo de representacao--> 0: pontos;  1: poligono
float gMatriz[3][3]; // matriz de transformacao
int gIndVert = -1;   // indice do vertice selecionado
int gTransform = 0;  /* transformacao:
    0: nula;
    1: Translacao;
    2: Rotacao;
    3: Escala;
    4: Espelha;
    5: Cisalha
 */
float gCen[3];       // centroide do poligono
float gAng = 0.0f;   // angulo para rotacao

float lastSideX = 0.1f, lastSideY = 0.1f; // JV last Quadrant mouse position
float ctd_JV[3];
float neutralValue = 1.0f;

int matrixDimension = 3;

void init() {
    int i;

    jaPoligono = 0;
    gNumVert = 0; // zero pontos
    tipoPoligono = GL_POINTS;

    gTransform = 0; // transforma Nula
    gIndVert = -1;  // indice do vertice selecioado nulo

    // inicializa com ZERO o vetor pvertex
    for (i = 0; i < MAXVERTEXS; i++) {
        pvertex[i].v[0] = 0.0f;
        pvertex[i].v[1] = 0.0f;
        pvertex[i].v[2] = neutralValue;
    }
    // calcula o angulo basico de rotacao
    gAng = (2.0f * PHI) / 360.0f;
}

void matrizIdentidade() { // JVFD
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            gMatriz[i][j] = (i == j) ? neutralValue : 0.0f;
        }
    }
}

static void Reshape(int width, int height) {
    windW = width / 2;
    windH = height / 2;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-windW, windW, -windH, windH);
    glMatrixMode(GL_MODELVIEW);
}

static void Key(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    }
}

void coord_line() {
    glLineWidth(1);
    glColor3f(1.0, 0.0, 0.0);
    // vertical line
    glBegin(GL_LINE_STRIP);
    glVertex2f(-windW, 0);
    glVertex2f(windW, 0);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    // horizontal line
    glBegin(GL_LINE_STRIP);
    glVertex2f(0, -windH);
    glVertex2f(0, windH);
    glEnd();
}

void PolygonDraw() {
    int i;
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, tipoPoligono);
    glBegin(tipoPoligono);
    for (i = 0; i < gNumVert; i++) {
        glVertex2fv(pvertex[i].v);
    }
    glEnd();
}

static void Draw() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    coord_line();

    PolygonDraw();

    if (doubleBuffer) {
        glutSwapBuffers();
    } else {
        glFlush();
    }
}

/* - - - INICIO OPERAÇÕES - - - */

void operaTransforma(float v[]) { //  Vetor = Matriz x Vetor
    float temp[3];
    int i, j;
    // temp = Matriz x vetor
    for (i = 0; i < 3; i++) {
        temp[i] = 0.0f;
        for (j = 0; j < 3; j++) {
            temp[i] += gMatriz[i][j] * v[j];
        }
    }
    // copia vetor resultando no vetor original
    for (i = 0; i < 3; i++) {
        v[i] = temp[i];
    }
}

void runTransform() { // JVFD
    for (int i = 0; i < gNumVert; i++) {
        operaTransforma(pvertex[i].v);
    }
}

void calCentro(float cc[]) { // OK - computando o centroide
    int i;
    cc[0] = cc[1] = cc[2] = 0.0f;
    for (i = 0; i < gNumVert; i++) {
        cc[0] += pvertex[i].v[0];
        cc[1] += pvertex[i].v[1];
        cc[2] += pvertex[i].v[2];
    }
    cc[0] /= gNumVert;
    cc[1] /= gNumVert;
    cc[2] /= gNumVert;
}

void calCentro_JV() { // JVFD
    ctd_JV[0] = ctd_JV[1] = ctd_JV[2] = 0.0f;
    for (int i = 0; i < gNumVert; i++) {
        ctd_JV[0] += pvertex[i].v[0];
        ctd_JV[1] += pvertex[i].v[1];
        ctd_JV[2] += pvertex[i].v[2];
    }
    ctd_JV[0] /= gNumVert;
    ctd_JV[1] /= gNumVert;
    ctd_JV[2] /= gNumVert;
}

void printCentroid(float ctd[]) {
    printf("Centroid: (%.1f, %.1f, %.1f)\n", ctd[0], ctd[1], ctd[2]);
}

void debug2d(float dx, float dy) {
    int debug2dging = 1;
    if (debug2dging) {
        printf("(%.2f, %.2f)\n", dx, dy);
    }
}

void printMatrix(float mat[3][3]) {
    printf("\n[");
    for (int i = 0; i < 3; i++) {
        printf("\t");
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}

/* TRANSLATE */

void createTranslationMatrix(float dx, float dy) { // JVFD
    matrizIdentidade();
    gMatriz[0][2] = dx;
    gMatriz[1][2] = dy;
}

void translate(float dx, float dy) { // JVFD
    createTranslationMatrix(dx, dy);
    runTransform();
}

/* ROTATION */

void createRotationMatrix(float dx, float dy) {
    matrizIdentidade();
    float oo, teta;
    oo = pvertex[gIndVert].v[1] * dx - pvertex[gIndVert].v[0] * dy;
    teta = gAng;
    if (oo > 0.0f) {
        teta = -neutralValue * gAng;
    }
    gMatriz[0][0] = cos(teta);
    gMatriz[0][1] = -sin(teta);
    gMatriz[1][0] = sin(teta);
    gMatriz[1][1] = cos(teta);
    // printMatrix(gMatriz);
}

void rotate(float dx, float dy) {
    calCentro_JV();
    translate(-1 * ctd_JV[0], -1 * ctd_JV[1]);
    createRotationMatrix(dx, dy);
    runTransform();
    translate(ctd_JV[0], ctd_JV[1]);
}

/* - - - INICIO OPERAÇÕES ESCALA - - - */

void createScaleMatrix(float dx, float dy) { // JVFD
    matrizIdentidade();
    float poorScale = dx + dy;
    float scaleFactor = 1.0f + (poorScale >= 0 ? -0.1f : 0.1f);
    gMatriz[0][0] = gMatriz[1][1] = scaleFactor;
}

void scale(float dx, float dy) { // JVFD
    calCentro_JV();
    translate(-1 * ctd_JV[0], -1 * ctd_JV[1]);
    createScaleMatrix(dx, dy);
    runTransform();
    translate(ctd_JV[0], ctd_JV[1]);
}

/* - - - INICIO OPERAÇÕES CISALHA - - - */

void debug1d(float value) {
    printf("(%.2f)\n", value);
}

void createShearMatrix(float dx, float dy) {
    matrizIdentidade();
    debug2d(dx, dy);
    float x = pvertex[gIndVert].v[0];
    float y = pvertex[gIndVert].v[1];

    float kx = dx / y;
    float ky = dy / x;
    gMatriz[0][1] = kx;
    gMatriz[1][0] = ky;
    // gMatriz[0][1] = dx;
    // gMatriz[1][0] = dy;
}

void shear(float x, float y, float dx, float dy) {
    calCentro_JV();
    translate(-1 * ctd_JV[0], -1 * ctd_JV[1]);
    createShearMatrix(dx, dy);
    runTransform();
    translate(ctd_JV[0], ctd_JV[1]);
}

/* - - - INICIO OPERAÇÕES JVFD - - - */

/* - - - INICIO OPERAÇÕES MIRROR - - - */

float calcMirrorSide(float value) { // JVFD
    float quadrant = value == 0.0 ? 1.0 : value / abs(value);
    return quadrant;
}

void createMirrorMatrix(float mouseX, float mouseY) { // JVFD
    matrizIdentidade();
    float x = calcMirrorSide(mouseX);
    float y = calcMirrorSide(mouseY);
    float newXSide;
    float newYSide;
    if (lastSideX == 0.1f || lastSideY == 0.1f) {
        newXSide = 1.0;
        newYSide = 1.0;
    } else {
        newXSide = x == lastSideX ? 1.0 : -1.0;
        newYSide = y == lastSideY ? 1.0 : -1.0;
    }

    gMatriz[0][0] = newXSide;
    gMatriz[1][1] = newYSide;

    // gMatriz[0][0] = newXSide;
    // gMatriz[1][1] = newYSide;

    lastSideX = x;
    lastSideY = y;
}

void mirror(float dx, float dy) { // JVFD
    createMirrorMatrix(dx, dy);
    runTransform();
}

/* - - - FIM OPERAÇÕES JVFD - - - */

/* - - - FIM OPERAÇÕES - - - */

// -------- verifica se um ponto (x, y) posia se considerar um vertice do
// poligono
// ---------------------------------------------------------------------------------
int clipVertex(int x, int y) {
    int i;
    float d;
    gIndVert = -1;
    // para cada vertice do poligono
    for (i = 0; i < gNumVert; i++) {
        // distancia do ponto (x, y) a cada vertice do poligono
        d = sqrt(pow((pvertex[i].v[0] - x), 2.0) +
                 pow((pvertex[i].v[1] - y), 2.0));
        // se a distancia d e bem proxima ( d < 3 pixel)
        if (d < 8.0) {
            gIndVert = i; // achou o indice do vertice
            break;
        }
    }
    return gIndVert;
}

// -------- Evento Arrastando o mouse pressionado o botao direito
// -------------- gerando manipulacao direta ---------------------
void motion(int x, int y) {
    float dx, dy;
    if (gIndVert > -1) {
        x = x - windW;
        y = windH - y;

        dx = x - pvertex[gIndVert].v[0];
        dy = y - pvertex[gIndVert].v[1];
        switch (gTransform) {
        case 1:
            translate(dx, dy);
            break;
        case 2:
            rotate(dx, dy);
            break;
        case 3:
            scale(dx, dy);
            break;
        case 4:
            mirror(x, y);
            break;
        case 5:
            shear(x, y, dx, dy);
            break;
        }
        Draw();
    }
}

// -------- Eveto CLICK botao MOUSE ----------
// -------------------------------------------
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_UP) //  botao SOLTO
    {
        // printf("\n jaPoligono %d ", jaPoligono);
        if (button == GLUT_LEFT_BUTTON) {
            if (jaPoligono == 0) { // ainda nao definido o poligono
                x = x - windW;
                y = windH - y;
                glPointSize(3);
                pvertex[gNumVert].v[0] = (float)x;
                pvertex[gNumVert].v[1] = (float)y;
                pvertex[gNumVert].v[2] = neutralValue;
                gNumVert++;
            }
        }
    } else {                   // state == GLUT_DOWN  --> botao pressionado
        if (jaPoligono == 1) { // poligono ja definido
            if (gTransform) {  // Uma ransformacao selecionada
                if (button == GLUT_LEFT_BUTTON) {
                    x = x - windW;
                    y = windH - y;
                    // clipingVertex
                    gIndVert = clipVertex(x, y);
                    // verificar e identificar um vertice selecionado
                    // printf("\n clipVetex: %d ", gIndVert);
                }
            }
        }
    }
    glutPostRedisplay();
}

static void Args(int argc, char **argv) {
    GLint i;

    doubleBuffer = GL_FALSE;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-sb") == 0) {
            doubleBuffer = GL_FALSE;
        } else if (strcmp(argv[i], "-db") == 0) {
            doubleBuffer = GL_TRUE;
        }
    }
}

// ----------- Eventos definidos no MENU -----------

void processMenuEvents(int option) { // Evento do menu geral
    switch (option) {
    case 0:
        init();
        break;
    }
    glutPostRedisplay();
}

// Eventos do menu de geracao de poligono
void processSubMenuEventsPolig(int option) {
    if (option == 0)
        tipoPoligono = GL_POINTS;
    else if (option == 1) {
        tipoPoligono = GL_LINE_LOOP;
        jaPoligono = 1;
    }

    glutPostRedisplay();
}

// Eventos do menu de transformadas
void processSubMenuEventsTransf(int option) {
    if (jaPoligono) {
        gTransform = option;
        printf("\n Transforma: %d ", gTransform);
    }
    glutPostRedisplay();
}

void createGLUTMenus() { // OK+- - Definicao do Menu principal
    int menu, submenu1, submenu2;

    submenu1 = glutCreateMenu(processSubMenuEventsPolig);
    glutAddMenuEntry("Pontos", 0);
    glutAddMenuEntry("Poligono", 1);

    submenu2 = glutCreateMenu(processSubMenuEventsTransf);
    glutAddMenuEntry("Translacao", 1);
    glutAddMenuEntry("Rotacao", 2);
    glutAddMenuEntry("Escala", 3);
    glutAddMenuEntry("Espelho", 4);
    glutAddMenuEntry("Cisalha", 5);

    menu = glutCreateMenu(processMenuEvents);
    glutAddMenuEntry("Limpar", 0);
    glutAddSubMenu("Tipo Objeto", submenu1);
    glutAddSubMenu("transformacao", submenu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    GLenum type;

    glutInit(&argc, argv);
    Args(argc, argv);

    type = GLUT_RGB;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;

    glutInitDisplayMode(type);
    glutInitWindowSize(windW, windH);
    glutCreateWindow("Basic Program Using Glut and Gl");
    init();
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);
    glutMotionFunc(motion);
    glutMouseFunc(mouse); // CLICK e RELEASE botao de mouse
    //    glutIdleFunc(idle);
    createGLUTMenus();
    glutMainLoop();
}
