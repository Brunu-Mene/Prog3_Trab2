#include "Candidatos.h"

Candidatos::Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido, string &sigla_partido){
        this->numero_partido = numero_partido;
        this->numero_candidato = numero_candidato;
        if(situacao == "Eleito"){
            this->situacao = 'E';
        }else if(situacao == "Suplente"){
            this->situacao = 'S';
        }else{
            this->situacao = 'N';
        }
        this->votos_nominais = votos_nominais;
        this->sexo = sexo[0];
        this->nome_candidato = nome_candidato;
        this->nome_urna = nome_urna;
        
        this->data_nasc = data_nasc;
    }