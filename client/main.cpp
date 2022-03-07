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

    listCandidatosEleitos.sort(compara_candidato());
    listCandidatos.sort(compara_candidato());

    rl.eleitos(listCandidatosEleitos,hashMap);
    rl.mais_votados(listCandidatos, listCandidatosEleitos.size(), hashMap);
    rl.eleitos_se_majoritario(listCandidatos, listCandidatosEleitos.size(), hashMap);
    rl.nao_eleitos_se_majoritario(listCandidatos, listCandidatosEleitos.size(), hashMap);

    listVotosPartidos.sort(compara_vt_np());
    rl.votos_partido(listCandidatos, listVotosPartidos);

    listVotosPartidos.sort(compara_vt_vl_np());
    rl.votos_de_legenda(listVotosPartidos);
    rl.primeiro_ultimo(listVotosPartidos,listCandidatos,hashMap);
    string dataEleicao = "15/11/2020";
    rl.distribuicao_idade(listCandidatosEleitos,dataEleicao);
    rl.distribuicao_sexo(listCandidatosEleitos);
    rl.balanco_votos(listVotosPartidos);

    return 0;
}