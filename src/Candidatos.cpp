#include "Candidatos.h"

Candidatos::Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido){
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

int Candidatos::getVotos_Nominais() const{
    return votos_nominais;
}

string Candidatos::getNome_Urna() const{
    return nome_urna;
}

int Candidatos::getNumero_Candidato() const{
    return numero_candidato;
}

char Candidatos::getSituacao() const{
    return situacao;
}

string Candidatos::getdata_nasc() const{
    return data_nasc;
}

char Candidatos::getSexo() const{
    return sexo;
}

/*int Candidatos::compareTo(Candidatos &c){
        if(c.votos_nominais - votos_nominais == 0){
            //return c.data_nasc.compareTo(this.data_nasc)*(-1);
            //retorno da comparação entre idades;
        }
        return c.votos_nominais - votos_nominais;
    }*/