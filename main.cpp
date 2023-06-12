#include "winbgim.h"
#include <stdlib.h>
#include <time.h>
/*
void dibujo(int x,int y,int tam)
{
    ellipse(x+2*tam,y+2*tam,0,360,tam,2*tam);
    line(x,y+tam,x+4*tam,y+tam);
    circle(x+1.5*tam,y+1.5*tam,4*tam/16);
    circle(x+2.5*tam,y+1.5*tam,4*tam/16);
    line(x+2*tam,y+2*tam,x+2*tam,y+2*tam+4*tam/8);
    arc(x+2*tam,y+2.75*tam,180,360,tam/2);
}
*/
void drawX(int xini, int yini, int xfin, int yfin )
{

}
void pacman(int x, int y, int e)
{
    setcolor(14);
    circle(x + 4 * e, y + 4 * e, 4 * e);
    setcolor(3);
    line(x + 5 * e, y + 4 * e, x + 8 * e, y + 4 * e);
    setcolor(4);
    rectangle(x + 3 * e, y + e, x + 4 * e, y + 3 * e);
}
void dibujo(int x, int y, int e)
{
    line(x + e, y + e, x + 4 * e, y + 4 * e);
}
int main()
{
    initwindow(800, 800);
    //line(50,50,400,150); //linea
/*  circle(100,250,50); //Circulo
    rectangle(50,50,400,150); //rectangulo
    /*ellipse(100, 250, 0, 360, 100, 50);
    ellipse(100, 250, 0, 360, 100, 50);
    ellipse(100, 250, 0, 360, 10, 50);
    arc(450, 150, 45,225 ,50),
    putpixel(400,450,10);*/
    //Ejercicio 1
    /*rectangle(100,100, 180, 180);
    circle(140,140,40);
    */
    //Ejercioio 2
    /*rectangle(200, 200, 300, 300);
    circle(200,200, 50);
    circle(200,300, 50);
    circle(300,200, 50);
    circle(300,300, 50);*/

    //Ejercicio 3
    /*
    line(100,100, 200, 100);
    line(200, 100, 100, 200);
    line(100,200, 100,100);

    arc(150,150, 225, 45, 45);
    arc(150,150, 225, 45, 70);
    */

    //Ejercicio 4
    /*
    setcolor(14);
    arc(150,150, 35, 325, 100);
    line(150,150, 230, 93);
    line(150,150, 230, 207);
    setcolor(4);
    ellipse(130, 100, 0, 360, 10, 20);
    getch();
    return 1;*/

    /*dibujo(10,10,5);
    dibujo(100,100,20);*/

    pacman(100, 100, 50);
    getch();
    return 1;
}
