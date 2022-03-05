#include "../include/Registrador.h"


void Registrador::preenche_listas_candidatos(list<Candidatos> &listCandidatos,list<Candidatos> &listCandidatosEleitos,char *caminho){
    fstream file;
    file.open(caminho,ios::in);
    if(!file.is_open()){
        cout <<"Erro na abertura do arquivo" << endl;
        exit(1);
    }

    string separador[9];
    string line;
    string delimitador = ",";
    size_t i = 0;
    string token;
    getline(file, line);
    while(getline(file, line)){
        int j=0;
        while((i = line.find(delimitador)) != string::npos){
            token = line.substr(0, i);
            separador[j] = token;
            line.erase(0, i + delimitador.length());
            j++;
        }
        separador[8] = line;
        if(separador[7] == "Válido"){
            Candidatos candidato(stoi(separador[0]),stoi(separador[1]),separador[2]
                                  ,separador[3],separador[4],separador[5],separador[6],
                                  stoi(separador[8]));
                            
            listCandidatos.push_back(candidato);
            if(separador[2] == "Eleito"){
                listCandidatosEleitos.push_back(candidato);
            }
        }
    }
    file.close();
}

void Registrador::preenche_hashmap_partidos(map<int,Partidos> &hashMap, char *caminho){
    fstream file;
    file.open(caminho,ios::in);
    if(!file.is_open()){
        cout << "Erro na abertura do arquivo" << endl;
        exit(1);
    }

    string separador[4];
    string line;
    string delimitador = ",";
    size_t i = 0;
    string token;
    getline(file, line);
    while(getline(file,line)){
        int j=0;
        while((i = line.find(delimitador)) != string::npos){
            token = line.substr(0, i);
            separador[j] = token;
            line.erase(0, i + delimitador.length());
            j++;
        }
        separador[3] = line;
        Partidos partido(stoi(separador[0]),stoi(separador[1]),separador[2],separador[3]);
        hashMap.insert(pair<int,Partidos>(stoi(separador[0]),partido));
    }

    file.close();
}

void Registrador::preenche_lista_votos_partidos(list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap, list<Partidos> &listVotosPartidos){
    int matVotosPartidos[100][1];

    for(int i=0; i<100 ;i++){
        matVotosPartidos[i][0] = 0;
    }

    for (const Candidatos &it : listCandidatos){
        matVotosPartidos[it.getNumero_Partido()][0] += it.getVotos_Nominais();
    }

    for(int i=0; i<100 ;i++){
        if(hashMap.find(i) != hashMap.end()){
            string nome = hashMap[i].getNome();
            string sigla = hashMap[i].getSigla();
            Partidos partido(i,hashMap[i].getVotosLegenda(),nome,sigla,
                                hashMap[i].getVotosLegenda() + matVotosPartidos[i][0]);
            
            listVotosPartidos.push_back(partido);
        }
    }
}

void Registrador::printa_test(list<Candidatos> &listCandidatos){
    //Create an iterator of std::list
    list<Candidatos>::iterator it;
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = listCandidatos.begin(); it != listCandidatos.end(); it++)
    {
        cout << "Numero:" << it->getNumero_Candidato()<< ",VT: " << it->getVotos_Nominais() << 
            ",Situation: "<< it->getSituacao() << ",Nome: " << it->getNome_Urna() << endl;
    }
}


void Registrador::printa_test2(list<Partidos> &listPartidos){

    list<Partidos>::iterator it;
    for (it = listPartidos.begin(); it != listPartidos.end(); it++){
        cout << "N° partido: " << it->getNumero() << ", Votos Legenda: " << it->getVotosLegenda();
        cout << ", Nome: " << it->getNome() << ", Sigla: " << it->getSigla() << ", Votos Totais: ";
        cout << it->getVotosTotal() << endl;
    }
}
