#ifndef REGISTRADOR_H
#define REGISTRADOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include "Candidatos.h"
#include "Partidos.h"
using namespace std;

class Registrador{   
    public:
        void preenche_listas_candidatos(list<Candidatos> &listCandidatos,list<Candidatos> &listCandidatosEleitos,char *caminho);
        void preenche_hashmap_partidos(map<int,Partidos> &hashMap, char *caminho);
        void preenche_lista_votos_partidos(list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap, list<Partidos> &listVotosPartidos);


        void printa_test(list<Candidatos> &listCandidatos);
        void printa_test2(list<Partidos> &listPartidos);
};

#endif

