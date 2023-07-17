#pragma once
#include "Components.h"
#include <random>

#define M 100
#define P 200
#define C 300
#define T 400

class Matrix{
    private:
        int **juego;
        int filas;
        int columnas;
        int numA;
    public:
        
        Matrix(){};

        void SetMatriz(int f,int c){

            filas = f;
            columnas = c;
            juego = new int*[filas];

            srand(time(NULL));

            for(int i=0;i<filas;i++){
                juego[i]=new int[columnas];
            }

            for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                    juego[i][j]=0;
                }
            }

            for(int i=0;i<columnas;i++){
                juego[0][i]=M;
                juego[filas-1][i]=M;
            }

            for(int i=0;i<filas;i++){
                juego[i][0]=M;
                juego[i][columnas-1]=M;
            }

            // for(int i = 1; i<filas-1;i++){
            //     if(filas > columnas){
            //         numA = rand()%filas;
            //     }
            //     else{
            //         numA = rand()%columnas;
            //     }
                
            //     for(int j = 1; j<columnas-1;j++){
            //         juego[i][numA]= M;
            //     }
            // }
        }
        int getFilas(){
            return filas;
        }
        int getColumas(){
            return columnas;
        }
        int getValor(int i,int j){
            return juego[i][j];
        }
};

class Juego{
    private:
        int filas;
        int columnas;
        int xini;
        int yini;
        int escala;
        CShape *g;
        Matrix m;
    public:
        Juego(){}

        void setFilas(int f){
            filas=f;
        }
        void setColumnas(int c){
            columnas=c;
        }
        void setPosJuego(int x,int y){
            xini=x;
            yini=y;
        }
        void setEscala(int e){
            g = new CShape(e);
        }
        void crearMatriz(){
            m.SetMatriz(filas,columnas);
        }
        void mostrarJuego(){
            for(int i=0;i<m.getFilas();i++){
                for(int j=0;j<m.getColumas();j++){
                    g->V(xini+j*escala,yini+i*escala,escala);
                    if(m.getValor(i,j)==M){
                        g->StoneWall(xini+j*escala,yini+i*escala);
                    }
                    // if(m.getValor(i,j)==P){
                    //     g->knightRight(xini+j*escala,yini+i*escala);
                    // }
                    // if(m.getValor(i,j)==C){
                    //     g.comida(xini+j*escala,yini+i*escala,escala,COLOR(255,0,0));
                    //     //draw_manza(xini+j*e,yini+i*e,e);
                    // }
                    // if(m.getValor(i,j)==T){
                    //     g.bomba(xini+j*escala,yini+i*escala,escala,COLOR(0,255,0));
                    // }
                }
            }
        }
};