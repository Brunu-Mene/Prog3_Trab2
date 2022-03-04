#ifndef REGISTRADOR_H
#define REGISTRADOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "Candidatos.h"
using namespace std;

class Registrador{
    
public:
    void preenche_listas_candidatos(list<Candidatos> &listCandidatos,list<Candidatos> &listCandidatosEleitos,char *caminho);
    void printa_test(list<Candidatos> &listCandidatos);
};

#endif

