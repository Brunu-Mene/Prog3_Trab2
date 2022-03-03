#include "Partidos.h"

Partidos::Partidos(int numero_partido, int votos_Legenda, string &nome, string &sigla, int votos_Total){
    this->numero_partido = numero_partido;
    this->votos_Legenda = votos_Legenda;
    this->nome = nome;
    this->sigla = sigla;
    this->votos_Total = votos_Total;
}