#ifndef PARTIDOS_H
#define PARTIDOS_H

#include <string>
#include <iostream>
using namespace std;

class Partidos{
private:
    int numero_partido, votos_Legenda, votos_Total;
    string nome, sigla;

public:
    Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla, int votos_Total);
    string getSigla();
    string getNome();
    int getNumero();
    int getVotosLegenda();
    int getVotosTotal();
    int Compara_Vt_Np(Partidos p1, Partidos p2);
    int Compara_Vt_Vl_Np(Partidos p1, Partidos p2);
};

#endif