#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

//Comentario de prueba
GLUquadricObj *p = gluNewQuadric();
float angHelicopteroX = 0;
float angHelicopteroY = 0;
float angHelicopteroZ = 0;

float nivelHelicopteroX = 0;
float nivelHelicopteroY = 0;
float nivelHelicopteroZ = 0;

float elicesRotacion = 0;



void inicializar()
{
    glClearColor(0.7,0.7,0.7,0.0);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_LINE);
}

void graficarEjes()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(50,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,50,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,50);
    glEnd();
}

void graficar()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20,20,20, 0,0,0, 0,1,0);

    graficarEjes();


    //Cabina
    glPushMatrix();
        glColor3f(1,1,0.5);
        glRotatef(angHelicopteroX,1,0,0);
        glRotatef(angHelicopteroY,0,1,0);
        glRotatef(angHelicopteroZ,0,0,1);
        glTranslatef(nivelHelicopteroX,nivelHelicopteroY,nivelHelicopteroZ);
        glutWireCube(5);

    //Trompa
    glPushMatrix();
        glColor3f(1,1,0.5);
        glTranslatef(0,0,4);
        glutWireCube(3);

    //Cola
    glPushMatrix();
        glColor3f(1,1,0.5);
        glTranslatef(0,0,-7.8);
        glutWireCube(2.8);
        glTranslatef(0,0,-2.6);
        glutWireCube(2.6);
        glTranslatef(0,0,-2.6);
        glutWireCube(2.4);
        glTranslatef(0,0,-2.4);
        glutWireCube(2.2);
        //glutSolidCube(2);

    //Elise 1
    glPushMatrix();
        glColor3f(1,1,0.5);
        glRotatef(elicesRotacion,1,0,0);
        glTranslatef(1,0,0);
        glutWireCube(1);
    glPushMatrix();
        //R
        glColor3f(0.5,0.3,0.5);
        glRotatef(0,0,1,0);
        glTranslatef(0.5,0,-3);
        glutWireCone(0.5, 3, 16, 16);
        //t
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);
        //L
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);
        //B
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);
    //Elise 2
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glColor3f(1,1,0.5);
        glTranslatef(0,3,-4);
        glRotatef(elicesRotacion,0,1,0);
        glutWireCube(1);
    glPushMatrix();
        //R
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,0,0,1);
        glTranslatef(0.5,0,-3);
        glutWireCone(0.5, 3, 16, 16);
        //t
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);
        //L
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);
        //B
        glColor3f(0.5,0.3,0.5);
        glRotatef(90,1,0,0);
        glTranslatef(0,3,-3);
        glutWireCone(0.5, 3, 16, 16);



    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //std::cout<<"Pop"<<"\n";

    glutSwapBuffers();
}
void manejarTeclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'A': angHelicopteroY = angHelicopteroY + 5;
                  break;
        case 'D': angHelicopteroY = angHelicopteroY - 5;
                  break;
        case 'a': angHelicopteroY = angHelicopteroY + 5;
                  break;
        case 'd': angHelicopteroY = angHelicopteroY - 5;
                  break;
        case 'W': nivelHelicopteroY = nivelHelicopteroY + 0.2;
                  break;
        case 'S': nivelHelicopteroY = nivelHelicopteroY - 0.2;
                  break;
        case 'w': nivelHelicopteroY = nivelHelicopteroY + 0.2;
                  break;
        case 's': nivelHelicopteroY = nivelHelicopteroY - 0.2;
                  break;
        case '6': //angHelicopteroZ = angHelicopteroZ + 5;
                  nivelHelicopteroX = nivelHelicopteroX - 2;
                  break;
        case '4': //angHelicopteroZ = angHelicopteroZ - 5;
                  nivelHelicopteroX = nivelHelicopteroX + 2;
                  break;
        case '8': //angHelicopteroX = angHelicopteroX + 5;
                  nivelHelicopteroZ = nivelHelicopteroZ + 2;
                  break;
        case '5': //angHelicopteroX = angHelicopteroX - 5;
                  nivelHelicopteroZ = nivelHelicopteroZ - 1;
                  break;
    }
    std::cout<<angHelicopteroY<<"\n";
    glutPostRedisplay();
}

void redimensionar(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1,100);

}



void rotarElise(int i)
{
    elicesRotacion = elicesRotacion + 10;
    glutPostRedisplay();
    glutTimerFunc(10,rotarElise,2);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Modelo");
    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutKeyboardUpFunc(manejarTeclado);

    glutTimerFunc(200,rotarElise,3);


    glutMainLoop();

    return 0;
}
