#include "../include/Compara.h"

bool compara_candidato::operator ()(const Candidatos &c1, const Candidatos &c2){
    if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
        if(c2.getdata_nasc() > c1.getdata_nasc()) return true;
        return false;
    }
    if(c2.getVotos_Nominais() > c1.getVotos_Nominais()) return false;
    return true;
}

bool compara_vn_np::operator()(const Candidatos &c1, const Candidatos &c2){
    if(c1.getVotos_Nominais() == c2.getVotos_Nominais()){
        if(c1.getNumero_Partido() > c2.getNumero_Partido()) return false;
        return true;
    }
    if(c2.getVotos_Nominais() > c1.getVotos_Nominais()) return false;
    return true;
}

bool compara_vt_np::operator()(const Partidos &p1, const Partidos &p2){
    if(p1.getVotosTotal() == p2.getVotosTotal()){
            if(p1.getNumero() > p2.getNumero()) 
                return false;
            return true;
        }
        if(p2.getVotosTotal() > p1.getVotosTotal()) 
            return false;
        return true;
}
    

bool compara_vt_vl_np::operator ()(const Partidos &p1, const Partidos &p2){
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