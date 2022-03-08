#include "../include/Partidos.h"

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

void Partidos::printaPartido() const{
    cout << sigla << " - " << numero_partido;
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
