#ifndef CANDIDATOS_H
#define CANDIDATOS_H

#include <string>
#include <iostream>
using namespace std;


class Candidatos{
private:
    int numero_candidato,votos_nominais,numero_partido;
    string nome_candidato,nome_urna, data_nasc;
    char situacao, sexo;

public:
    Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido);
    int getVotos_Nominais() const;
    string getNome_Urna() const;
    int getNumero_Candidato() const; 
    char getSituacao() const;
    string getdata_nasc() const;
    char getSexo() const;
    //int Candidatos::compareTo(Candidatos &c);
};

#endif