#include "../include/Registrador.h"
#include "../include/Relatorios.h"
#include "../include/Compara.h"

using namespace relatorios;
using namespace registrador;

int main(int agrv, char **agrs){
    list<Candidatos> listCandidatos, listCandidatosEleitos;
    list<Partidos> listVotosPartidos;
    map<int, Partidos> hashMap;
    
    preenche_listas_candidatos(listCandidatos,listCandidatosEleitos,agrs[1]);
    preenche_hashmap_partidos(hashMap,agrs[2]);
    preenche_lista_votos_partidos(listCandidatos,hashMap,listVotosPartidos);

    numero_de_vagas(listCandidatosEleitos.size());

    listCandidatosEleitos.sort(compara_candidato());
    listCandidatos.sort(compara_candidato());

    eleitos(listCandidatosEleitos,hashMap);
    mais_votados(listCandidatos, listCandidatosEleitos.size(), hashMap);
    eleitos_se_majoritario(listCandidatos, listCandidatosEleitos.size(), hashMap);
    nao_eleitos_se_majoritario(listCandidatos, listCandidatosEleitos.size(), hashMap);

    listVotosPartidos.sort(compara_vt_np());
    votos_partido(listCandidatos, listVotosPartidos);

    listVotosPartidos.sort(compara_vt_vl_np());
    votos_de_legenda(listVotosPartidos);
    primeiro_ultimo(listVotosPartidos,listCandidatos,hashMap);
    string dataEleicao = "15/11/2020";
    distribuicao_idade(listCandidatosEleitos,dataEleicao);
    distribuicao_sexo(listCandidatosEleitos);
    balanco_votos(listVotosPartidos);

    return 0;
}