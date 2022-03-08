#include "../include/Compara.h"

bool compara_candidato::operator ()(const Candidatos &c1, const Candidatos &c2){
    if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
        return c1.getdata_nasc() < c2.getdata_nasc();

    }
    return c1.getVotos_Nominais() > c2.getVotos_Nominais();
}

bool compara_vn_np::operator()(const Candidatos &c1, const Candidatos &c2){
    if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
        return c2.getNumero_Partido() > c1.getNumero_Partido();
    }
    return c1.getVotos_Nominais() > c2.getVotos_Nominais();
}

bool compara_vt_np::operator()(const Partidos &p1, const Partidos &p2){
    if(p1.getVotosTotal() == p2.getVotosTotal()){
        return p2.getNumero() > p1.getNumero();
    }
    return p1.getVotosTotal() > p2.getVotosTotal();
}
    

bool compara_vt_vl_np::operator ()(const Partidos &p1, const Partidos &p2){
    if(p1.getVotosLegenda() == p2.getVotosLegenda()){
            if(p1.getVotosTotal() - p1.getVotosLegenda() == p2.getVotosTotal() - p2.getVotosLegenda()){
                return p2.getNumero() > p1.getNumero();
            }
            return (p1.getVotosTotal() - p1.getVotosLegenda()) > (p2.getVotosTotal() - p2.getVotosLegenda());
        }
    return p1.getVotosLegenda() > p2.getVotosLegenda();
}