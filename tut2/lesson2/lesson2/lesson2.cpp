#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; // переменная для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); // очитска буфера цвета

    glEnableVertexAttribArray(0); //включение индексации атрибутов вершин
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Enable or disable a generic vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // говорит конвейеру, как воспринимать данные внутри буфера
                                                           // Первый параметр - индекс атрибута
                                                           // Второй параметр - количество компонентов в атрибуте
                                                           // Третий параметр - тип данных для каждого компонента
                                                           // Четвертый - хотим ли мы нормализовать атрибуты перед использованием в конвейере
                                                           // Пятый параметр  является числом байтов между 2 экземплярами атрибута
                                                           // Последний параметр - смещение в структуре

    glDrawArrays(GL_POINTS, 0, 1); // функция непосредственной отрисовки

    glDisableVertexAttribArray(0); // отключение атрибута вершины

    glutSwapBuffers(); // меняет фоновый буфер и буфер кадра местами(двойная буферизация)
    
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB); // колбэк-функция отрисовки кадра
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1]; // создание массива экзепляра структуры vector3f для реализации вершины
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f); // задаем XYZ по нулям

    glGenBuffers(1, &VBO); // создание буфера для вершин
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // функция для указанря задачи, первый параметр означает, что буфер будет хранить массив вершин
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // наполнение буфера данными
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); // инициализируем GLUT

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // задаеn настройки: режим двойной буферизации и буфер цвета


    glutInitWindowSize(1024, 768); //задает размер окна
    glutInitWindowPosition(100, 100); //задает изначальную позицию окна
    glutCreateWindow("Tutorial 02"); // создает окно и присваивает ей заголовок

    InitializeGlutCallbacks();// вызываем функции обратного вызова у GLUT

    GLenum res = glewInit(); // инициалиация glew
    if (res != GLEW_OK) { //проверка на успешную инициализацию glew
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливает цвет, который будет использован во время очистки буфера кадра

    CreateVertexBuffer(); // функция создания вершин

    glutMainLoop(); // вход в цикл

    return 0;
}

