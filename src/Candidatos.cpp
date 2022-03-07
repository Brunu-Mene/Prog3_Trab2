#include "Candidatos.h"
#include "DateUtils.h"

using namespace cpp_util;

Candidatos::Candidatos(){}

Candidatos::Candidatos(int numero_candidato, int votos_nominais,string &situacao, string &nome_candidato, string &nome_urna, string &sexo, string &data_nasc,int numero_partido, string sigla_partido){
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
    this->data_nasc = parseDate(data_nasc,DATE_FORMAT_PT_BR_SHORT);
    this->sigla_partido = sigla_partido;
}

void Candidatos::printaCandidato() const{
    cout << nome_candidato << " / " << nome_urna << " (" << 
                sigla_partido << ", " << votos_nominais;
    votos_nominais != 1 ? cout << " votos)\n" : cout << " voto)\n";
}

int Candidatos::getVotos_Nominais() const{
    return votos_nominais;
}

string Candidatos::getNome_Urna() const{
    return nome_urna;
}

string Candidatos::getNome_Candidato() const{
    return nome_candidato;
}

int Candidatos::getNumero_Candidato() const{
    return numero_candidato;
}

int Candidatos::getNumero_Partido() const{
    return numero_partido;
}

char Candidatos::getSituacao() const{
    return situacao;
}

time_t Candidatos::getdata_nasc() const{
    return data_nasc;
}

char Candidatos::getSexo() const{
    return sexo;
}

string Candidatos::getSigla_Partido() const{
    return sigla_partido;
}