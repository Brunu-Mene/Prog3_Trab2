#include "../include/Relatorios.h"

void Relatorios::numero_de_vagas(int nVagas) const{
    cout << "Número de vagas: " << nVagas << endl << endl;
}

void Relatorios::eleitos(list<Candidatos> &listCandidatosEleitos, map<int,Partidos> &hashMap) const{
    cout << "Vereadores eleitos:" << endl;
    list<Candidatos>::iterator it;
    Candidatos aux;
    int i = 1;
    for (const Candidatos &it : listCandidatosEleitos){
        cout << i << " - ";
        it.printaCandidato(hashMap);
        i++;
    }
    cout << endl;
}

void Relatorios::mais_votados(list<Candidatos> &listCandidatos, int nEleitos, map<int,Partidos> &hashMap) const{
    int i = 1;
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    for(const Candidatos &it : listCandidatos){
        if(i > nEleitos) break;
        cout << i << " - ";
        it.printaCandidato(hashMap);
        i++;
    }
    cout << endl;
}

void Relatorios::eleitos_se_majoritario(list<Candidatos> &listCandidatos,int nVagas, map<int,Partidos> &hashMap) const{
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" <<
                "\n(com sua posição no ranking de mais votados)" << endl;
    int i = 1;
    for(const Candidatos &it : listCandidatos){
        if(it.getSituacao() != 'E' && i <= nVagas){
            cout << i << " - ";
            it.printaCandidato(hashMap);
        }else if(i > nVagas) break;
        i++;
    }
    cout << endl;
}

void Relatorios::nao_eleitos_se_majoritario(list<Candidatos> &listCandidatos, int nVagas, map<int,Partidos> &hashMap) const{
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" <<
                "\n(com sua posição no ranking de mais votados)" << endl;
    int i = 1;

    //nao sei se a posição de acesso ta realmente, testar depois
    auto candidatoAux = listCandidatos.begin();
    advance(candidatoAux, nVagas - 1);

    for(const Candidatos &it : listCandidatos){
        if(it.getSituacao() == 'E'){
            if(it.getVotos_Nominais() < candidatoAux->getVotos_Nominais()){
                cout << i << " - ";
                it.printaCandidato(hashMap);
            }
        }
        i++;
    }
    cout << endl;
}

void Relatorios::votos_partido(list<Candidatos> &listCandidatos, list<Partidos> &listVotosPartidos) const{

}

void Relatorios::votos_de_legenda(list<Partidos> &listVotosPartidos) const{

}

void Relatorios::primeiro_ultimo(list<Partidos> &listVotosPartidos, list<Candidatos> &listCandidatos) const{

}

void Relatorios::distribuicao_idade(list<Candidatos> &listCandidatosEleitos, string &dataEleicao) const{

}

void Relatorios::distribuicao_sexo(list<Candidatos> &listCandidatosEleitos) const{

}

//tem que arrumar a historinha das viruglar aqui;
void Relatorios::balanco_votos(list <Partidos> &listVotosPartidos) const{
    int totalVotos = 0, totalVotosNominais = 0, totalVotosLegenda = 0;

    for(const Partidos &it : listVotosPartidos){
        totalVotos += it.getVotosTotal();
        totalVotosLegenda += it.getVotosLegenda();
        totalVotosNominais += (it.getVotosTotal() - it.getVotosLegenda());
    }

    cout <<"Total de votos válidos:    " << totalVotos << endl;
    printf("Total de votos nominais:   %d (%.2f%%)\n",totalVotosNominais, 100*(static_cast <float> (totalVotosNominais))/(static_cast <float> (totalVotos)));
    printf("Total de votos de legenda: %d (%.2f%%)\n\n\n", totalVotosLegenda, 100*(static_cast <float> (totalVotosLegenda))/(static_cast <float> (totalVotos)));
}