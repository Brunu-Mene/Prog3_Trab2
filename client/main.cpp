#include "../include/Registrador.h"

int main(int agrv, char **agrs){
    list<Candidatos>listCandidatos,listCandidatosEleitos;
    Registrador rg;
    rg.preenche_listas_candidatos(listCandidatos,listCandidatosEleitos,agrs[1]);
    rg.printa_test(listCandidatos);
    return 0;
}