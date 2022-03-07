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

// MANO KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
// ARRANJAR UM JEITO DE FAZER ISSO CERTO, PQ IMPOSSIVEL Q ISSO SEJA ACEITÁVEL
//macaquice.
struct compara_candidato{
    bool operator ()(const Candidatos &c1, const Candidatos &c2){
        if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
            if(c2.getdata_nasc() > c1.getdata_nasc()) return true;
            return false;
        }
        if(c2.getVotos_Nominais() > c1.getVotos_Nominais()) return false;
        return true;
    }
};

struct compara_vn_np{
    bool operator()(const Candidatos &c1, const Candidatos &c2){
        if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
            if(c1.getNumero_Partido() > c2.getNumero_Partido()) return false;
            return true;
        }
        if(c2.getVotos_Nominais() > c1.getVotos_Nominais()) return false;
        return true;
    }
};

#endif