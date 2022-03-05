#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "Candidatos.h"
#include "Partidos.h"
#include <list>
#include <map>

class Relatorios{
    public:
        void numero_de_vagas (int nVagas) const;
        void eleitos(list<Candidatos> &listCandidatosEleitos, map<int,Partidos> &hashMap) const;
        void mais_votados(list<Candidatos> &listCandidatos, int nEleitos, map<int,Partidos> &hashMap) const;
        void eleitos_se_majoritario(list<Candidatos> &listCandidatos,int nVagas, map<int,Partidos> &hashMap) const;
        void nao_eleitos_se_majoritario(list<Candidatos> &listCandidatos, int nVagas, map<int,Partidos> &hashMap) const;
        void votos_partido(list<Candidatos> &listCandidatos, list<Partidos> &listVotosPartidos) const;
        void votos_de_legenda(list<Partidos> &listVotosPartidos) const;
        void primeiro_ultimo(list<Partidos> &listVotosPartidos, list<Candidatos> &listCandidatos) const;
        void distribuicao_idade(list<Candidatos> &listCandidatosEleitos, string &dataEleicao) const;
        void distribuicao_sexo(list<Candidatos> &listCandidatosEleitos) const;
        void balanco_votos(list <Partidos> &listVotosPartidos) const;
};

#endif