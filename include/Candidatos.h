#ifndef CANDIDATOS_H
#define CANDIDATOS_H

#include <string>
using namespace std;


class Candidatos{
private:
    int numero_candidato,votos_nominais,numero_partido;
    string nome_candidato,nome_urna, data_nasc;
    char situacao, sexo;

public:
    Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido, string &sigla_partido);
    int getVotos_Nominais();
    string getNome_Urna();
    int getNumero_Candidato(); 
    char getSituacao();
    string getdata_nasc();
    char getSexo();
};

#endif