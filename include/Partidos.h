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

struct compara_vt_np{
    bool operator ()(const Partidos &p1, const Partidos &p2){
        if(p1.getVotosTotal() == p2.getVotosTotal()){
            if(p1.getNumero() > p2.getNumero()) 
                return false;
            return true;
        }
        if(p2.getVotosTotal() > p1.getVotosTotal()) 
            return false;
        return true;
    }
};

struct compara_vt_vl_np{
    bool operator ()(const Partidos &p1, const Partidos &p2){
        if(p1.getVotosLegenda() == p2.getVotosLegenda()){
            if(p1.getVotosTotal() - p1.getVotosLegenda() == p2.getVotosTotal() - p2.getVotosLegenda()){
                if(p1.getNumero() > p2.getNumero()) 
                    return false;
                return true;
            }
            if((p2.getVotosTotal() - p2.getVotosLegenda()) > (p1.getVotosTotal() - p1.getVotosLegenda()))
                return false;
            return true;
        }
        if(p2.getVotosLegenda() > p1.getVotosLegenda())
            return false;
        return true;
    }
};

#endif