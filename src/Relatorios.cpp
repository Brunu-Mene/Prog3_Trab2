#include "../include/Relatorios.h"
#include "../include/DateUtils.h"

using namespace cpp_util;

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
    int matEleitosPartido[100][1];

    for(int i = 0; i<100 ;i++){
        matEleitosPartido[i][0] = 0;
    }
    for(const Candidatos &it : listCandidatos){
        if(it.getSituacao() == 'E')
            matEleitosPartido[it.getNumero_Partido()][0]++;
    }

    int i = 1;
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
    for(const Partidos &it : listVotosPartidos){
        cout << i << " - ";
        it.printaPartido();
        cout << ", " << it.getVotosTotal();
        it.getVotosTotal() > 1 ? cout << " votos (" : cout << " voto (";
        cout << (it.getVotosTotal() - it.getVotosLegenda());
        (it.getVotosTotal() - it.getVotosLegenda()) > 1 ? cout << " nominais e " : cout << " nominal e ";
        cout << it.getVotosLegenda() << " de legenda), " << matEleitosPartido[it.getNumero()][0];
        matEleitosPartido[it.getNumero()][0] > 1 ? cout << " candidatos eleitos" << endl: cout << " candidato eleito" << endl;
        i++;
    }
    cout << endl;
}

//tem que arrumar a historinha das viruglar aqui;
void Relatorios::votos_de_legenda(list<Partidos> &listVotosPartidos) const{
    int i = 1;
    cout << "Votação dos partidos (apenas votos de legenda):" << endl;

    for(const Partidos &it : listVotosPartidos){
        cout << i << " - ";
        it.printaPartido();
        cout << ", " << it.getVotosLegenda();
        it.getVotosLegenda() > 1 ? cout << " votos " : cout << " voto ";
        cout << "de legenda (";
        if(it.getVotosLegenda() == 0){
            cout << "proporção não calculada, " << it.getVotosTotal() << " voto no partido)" << endl;
        }else{
            printf("%.2f%% do total do partido)\n", 100*(static_cast <float> (it.getVotosLegenda())/static_cast <float> (it.getVotosTotal())));
        }

        i++;
    }
    cout << endl;
}

void Relatorios::primeiro_ultimo(list<Partidos> &listVotosPartidos, list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap) const{
    list<Candidatos> maisVotados, menosVotados;

    for(const Partidos &it : listVotosPartidos){
        if(it.getVotosTotal() != 0){
            for(const Candidatos &candidato : listCandidatos){
                if(candidato.getNumero_Partido() == it.getNumero()){
                    maisVotados.push_back(candidato);
                    break;
                }
            }
            for (std::list<Candidatos>::reverse_iterator i = listCandidatos.rbegin(); i != listCandidatos.rend(); ++i){
                if(i->getNumero_Partido() == it.getNumero()){
                    menosVotados.push_back(*i);
                    break;
                }
            }
        }
    }
    maisVotados.sort(compara_vn_np());
    int i = 1;
    cout << "Primeiro e último colocados de cada partido:" << endl;
    for(const Candidatos &it : maisVotados){
        cout << i << " - " << hashMap[it.getNumero_Partido()].getSigla() << " - " << it.getNumero_Partido() <<
                    ", " << it.getNome_Urna() << " (" << it.getNumero_Candidato() << ", " 
                        << it.getVotos_Nominais();
        it.getVotos_Nominais() > 1 ? cout << " votos)" : cout << " voto)";

        for(const Candidatos &candMenos : menosVotados){
            if(candMenos.getNumero_Partido() == it.getNumero_Partido()){
                cout << " / " << candMenos.getNome_Urna() << " (" << candMenos.getNumero_Candidato() <<
                            ", " << candMenos.getVotos_Nominais();
                candMenos.getVotos_Nominais() > 1 ? cout << " votos)" << endl : cout << " voto)" << endl;

                break;
            }
        }
        i++;
    }
    cout << endl;
}

void Relatorios::distribuicao_idade(list<Candidatos> &listCandidatosEleitos, string &dataEleicao) const{
    int intervalo1 = 0, intervalo2 = 0, intervalo3 = 0, intervalo4 = 0, intervalo5 = 0;
    time_t eleicao = parseDate(dataEleicao,DATE_FORMAT_PT_BR_SHORT);

    for(const Candidatos &it : listCandidatosEleitos){
        time_t diff = difftime(eleicao,it.getdata_nasc());
        int anos = diff/31557600;
        if(anos<30) intervalo1++;
        else if(anos >= 30 && anos < 40) intervalo2++;
        else if(anos >= 40 && anos < 50) intervalo3++;
        else if(anos >= 50 && anos < 60) intervalo4++;
        else intervalo5++;
    }
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    printf("      Idade < 30: %d (%.2f%%)\n",intervalo1,100*(static_cast <float>(intervalo1))/static_cast <float>(listCandidatosEleitos.size()));
    printf("30 <= Idade < 40: %d (%.2f%%)\n",intervalo2,100*(static_cast <float>(intervalo2))/static_cast <float>(listCandidatosEleitos.size()));
    printf("40 <= Idade < 50: %d (%.2f%%)\n",intervalo3,100*(static_cast <float>(intervalo3))/static_cast <float>(listCandidatosEleitos.size()));
    printf("50 <= Idade < 60: %d (%.2f%%)\n",intervalo4,100*(static_cast <float>(intervalo4))/static_cast <float>(listCandidatosEleitos.size()));
    printf("60 <= Idade     : %d (%.2f%%)\n\n",intervalo5,100*(static_cast <float>(intervalo5))/static_cast <float>(listCandidatosEleitos.size()));
}

//tem que arrumar a historinha das viruglar aqui;
void Relatorios::distribuicao_sexo(list<Candidatos> &listCandidatosEleitos) const{
    int candidatosM = 0, candidatosF = 0;

    for(const Candidatos &it : listCandidatosEleitos){
        if(it.getSexo() == 'F') candidatosF++;
        else if(it.getSexo() == 'M') candidatosM++;
    }

    cout << "Eleitos, por sexo:" << endl;
    printf("Feminino:  %d (%.2f%%)\n", candidatosF, 100*(static_cast <float> (candidatosF))/(static_cast <float> (listCandidatosEleitos.size())));;
    printf("Masculino: %d (%.2f%%)\n\n", candidatosM, 100*(static_cast <float> (candidatosM))/(static_cast <float> (listCandidatosEleitos.size())));
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