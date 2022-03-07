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
        void printaPartido() const;
        string getSigla()const;
        string getNome()const;
        int getNumero()const;
        int getVotosLegenda()const;
        int getVotosTotal()const;
};

#endif