#ifndef CANDIDATOS_H
#define CANDIDATOS_H

#include <string>
#include <iostream>
#include <map>
#include "Partidos.h"
using namespace std;

class Candidatos{
    private:
        int numero_candidato,votos_nominais,numero_partido;
        string nome_candidato,nome_urna;
        time_t data_nasc;
        char situacao, sexo;

    public:
        Candidatos();
        Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido);
        void printaCandidato(map<int,Partidos> &hashMap) const;
        int getVotos_Nominais() const;
        string getNome_Urna() const;
        string getNome_Candidato() const;
        int getNumero_Candidato() const; 
        int getNumero_Partido() const; 
        char getSituacao() const;
        time_t getdata_nasc() const;
        char getSexo() const;
};

#endif