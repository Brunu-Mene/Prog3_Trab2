#include "Partidos.h"

Partidos::Partidos(){}

Partidos::Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla){
    this->numero_partido = numero_partido;
    this->votos_Legenda = votos_Legenda;
    this->nome = nome;
    this->sigla = sigla;
}

Partidos::Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla, int votos_Total){
    this->numero_partido = numero_partido;
    this->votos_Legenda = votos_Legenda;
    this->nome = nome;
    this->sigla = sigla;
    this->votos_Total = votos_Total;
}

string Partidos::getSigla() const{
    return sigla;
}

string Partidos::getNome() const{
    return nome;
}

int Partidos::getNumero() const{
    return numero_partido;
}

int Partidos::getVotosLegenda()const {
    return votos_Legenda;
}

int Partidos::getVotosTotal() const{
    return votos_Total;
}

/*int Partidos::Compara_Vt_Np(Partidos &p1){
    if(p1.getVotosTotal() == votos_Total){
            return p1.getNumero() - numero_partido;
        }
        return votos_Total - p1.getVotosTotal();
}

int Partidos::Compara_Vt_Vl_Np(Partidos &p1){
        if(p1.getVotosLegenda() == votos_Legenda){
            if(p1.getVotosTotal() - p1.getVotosLegenda() == votos_Total - votos_Legenda) 
                return p1.getNumero() - numero_partido;
            return (votos_Total - votos_Legenda) - (p1.getVotosTotal() - p1.getVotosLegenda());
        }
        return votos_Legenda - p1.getVotosLegenda();
}*/