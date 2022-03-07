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

namespace registrador{   
    void preenche_listas_candidatos(list<Candidatos> &listCandidatos,list<Candidatos> &listCandidatosEleitos,const char *caminho);
    void preenche_hashmap_partidos(map<int,Partidos> &hashMap, const char *caminho);
    void preenche_lista_votos_partidos(const list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap, list<Partidos> &listVotosPartidos);
};

#endif

