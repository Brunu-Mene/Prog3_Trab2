#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "Candidatos.h"
#include "Partidos.h"
#include <list>
#include <map>

namespace relatorios{
    void numero_de_vagas (const int nVagas);
    void eleitos(const list<Candidatos> &listCandidatosEleitos, map<int,Partidos> &hashMap);
    void mais_votados(const list<Candidatos> &listCandidatos, const int nEleitos, map<int,Partidos> &hashMap);
    void eleitos_se_majoritario(const list<Candidatos> &listCandidatos, const int nVagas, map<int,Partidos> &hashMap);
    void nao_eleitos_se_majoritario(const list<Candidatos> &listCandidatos, const int nVagas, map<int,Partidos> &hashMap);
    void votos_partido(const list<Candidatos> &listCandidatos, const list<Partidos> &listVotosPartidos);
    void votos_de_legenda(const list<Partidos> &listVotosPartidos);
    void primeiro_ultimo(const list<Partidos> &listVotosPartidos, list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap);
    void distribuicao_idade(const list<Candidatos> &listCandidatosEleitos, const string &dataEleicao);
    void distribuicao_sexo(const list<Candidatos> &listCandidatosEleitos);
    void balanco_votos(const list <Partidos> &listVotosPartidos);
};

#endif