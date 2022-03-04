#include "../include/Registrador.h"


void Registrador::preenche_listas_candidatos(list<Candidatos> &listCandidatos,list<Candidatos> &listCandidatosEleitos,char *caminho){
    fstream file;
    file.open(caminho,ios::in);
    if(!file.is_open()){
        cout <<"Erro na abertura do arquivo";
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
