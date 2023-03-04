// lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <gl\freeglut.h>

static void RenderSB() {
    glClear(GL_COLOR_BUFFER_BIT); // эта функция очищает буферы, здесь конкректно буфер цвета
    glutSwapBuffers(); // меняет фоновый буфер и буфер кадра местами(двойная буферизация)
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); //инициализается GLUT и передача ей параметров main 

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Option set. Двойная буферизация и буфер цвета

    glutInitWindowSize(1024, 768); //установка размера окна
    glutInitWindowPosition(100, 100); //установка изначальной позиции окна
    glutCreateWindow("Tutorial01"); //создание окна и присвоение ему заголовка

    glutDisplayFunc(RenderSB); // функция обратного вызова, которая отрисовывает 1 кадр

    glutMainLoop();//вхождение в процесс GLUT с образованием цикла

    return 0;
}

