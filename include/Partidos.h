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
        Partidos();
        Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla);
        Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla, int votos_Total);
        string getSigla()const;
        string getNome()const;
        int getNumero()const;
        int getVotosLegenda()const;
        int getVotosTotal()const;
        //int Compara_Vt_Np(Partidos &p1);
        //int Compara_Vt_Vl_Np(Partidos &p1);
};

#endif