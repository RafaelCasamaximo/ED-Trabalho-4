#include <stdio.h>
#include <stdlib.h>
#include "regiao.h"
#include "ponto.h"
#include "quadra.h"
#include "quadtree.h"
#include "lista.h"

typedef struct regiao {
    Ponto ponto;
    double w;
    double h;
    double d;
} RegiaoStruct;

Regiao criarRegiao(double x, double y, double w, double h, double d) {
    RegiaoStruct* regiao = (RegiaoStruct*) malloc(sizeof(RegiaoStruct));
    regiao->ponto = createPoint(x,y);
    regiao->w = w;
    regiao->h = h;
    regiao->d = d;
    return regiao;
}

Ponto getPontoRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->ponto;
}

void setPontoRegiao(Regiao reg, Ponto p) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->ponto = p;
}

double getWRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->w;
}

void setWRegiao(Regiao reg, double w) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->w = w;
}

double getHRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->w;
}

void setHRegiao(Regiao reg, double h) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->h = h;
}

double getDRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->d;
}

void setDRegiao(Regiao reg, double d) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->d = d;
}

void desidadeQuadras(Regiao reg, QuadTree quadras){
    RegiaoStruct* r = (RegiaoStruct*) reg;
    Lista list = nosDentroRetanguloQt(quadras, getX(r->ponto), getY(r->ponto), getX(r->ponto) + r->w, getY(r->ponto) + r->h);
    for(No node = getFirst(list); node != NULL; node = getNext(node)){
        setDensidade(getInfoQt(quadras,getInfo(node)),r->d);
    }
    removeList(list,0);
}
