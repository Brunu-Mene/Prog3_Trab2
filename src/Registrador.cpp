#include "../include/Registrador.h"

namespace registrador{

void preenche_listas_candidatos(list<Candidatos> &listCandidatos, list<Candidatos> &listCandidatosEleitos, map<int,Partidos> &hashMap, const char *caminho){
    fstream file;
    file.open(caminho,ios::in);
    if(!file.is_open()){
        cout <<"Erro na abertura do arquivo." << endl;
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
                                  ,separador[3],separador[4],separador[5],separador[6],stoi(separador[8]),
                                    hashMap[stoi(separador[8])].getSigla());
            listCandidatos.push_back(candidato);
            if(separador[2] == "Eleito"){
                listCandidatosEleitos.push_back(candidato);
            }
        }
    }
    file.close();
}

void preenche_hashmap_partidos(map<int,Partidos> &hashMap, const char *caminho){
    fstream file;
    file.open(caminho,ios::in);
    if(!file.is_open()){
        cout << "Erro na abertura do arquivo." << endl;
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

void preenche_lista_votos_partidos(const list<Candidatos> &listCandidatos, map<int,Partidos> &hashMap, list<Partidos> &listVotosPartidos){
    map<int, int> votosPartidos;

    for(int i=0; i<100 ;i++){
        votosPartidos[i] = 0;
    }

    for (const Candidatos &it : listCandidatos){
        votosPartidos[it.getNumero_Partido()] += it.getVotos_Nominais();
    }

    for(int i=0; i<100 ;i++){
        if(hashMap.find(i) != hashMap.end()){
            string nome = hashMap[i].getNome();
            string sigla = hashMap[i].getSigla();
            Partidos partido(i,hashMap[i].getVotosLegenda(),nome,sigla,
                                hashMap[i].getVotosLegenda() + votosPartidos[i]);
            
            listVotosPartidos.push_back(partido);
        }
    }
}

}
