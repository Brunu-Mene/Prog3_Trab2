#include "../include/Registrador.h"
#include "../include/Relatorios.h"

int main(int agrv, char **agrs){
    list<Candidatos> listCandidatos, listCandidatosEleitos;
    list<Partidos> listVotosPartidos;
    map<int, Partidos> hashMap;

    Registrador rg;
    Relatorios rl;
    
    rg.preenche_listas_candidatos(listCandidatos,listCandidatosEleitos,agrs[1]);
    rg.preenche_hashmap_partidos(hashMap,agrs[2]);
    rg.preenche_lista_votos_partidos(listCandidatos,hashMap,listVotosPartidos);

    rl.numero_de_vagas(listCandidatosEleitos.size());
    rl.eleitos(listCandidatosEleitos,hashMap);


    //rg.printa_test(listCandidatos);
    //rg.printa_test2(listVotosPartidos);

    return 0;
}