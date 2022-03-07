#ifndef CANDIDATOS_H
#define CANDIDATOS_H

#include <string>
#include <iostream>
#include "Partidos.h"
using namespace std;

class Candidatos{
    private:
        int numero_candidato,votos_nominais,numero_partido;
        string nome_candidato,nome_urna,sigla_partido;
        time_t data_nasc;
        char situacao, sexo;

    public:
        Candidatos();
        Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido, string sigla_partido);
        void printaCandidato() const;
        int getVotos_Nominais() const;
        string getNome_Urna() const;
        string getNome_Candidato() const;
        int getNumero_Candidato() const; 
        int getNumero_Partido() const; 
        char getSituacao() const;
        time_t getdata_nasc() const;
        char getSexo() const;
        string getSigla_Partido() const;
};

#endif