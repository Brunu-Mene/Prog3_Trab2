#include "Candidatos.h"
using namespace std;

class compara_candidato{
    public:
    bool operator ()(const Candidatos &c1, const Candidatos &c2);
};

class compara_vn_np{
    public:
    bool operator()(const Candidatos &c1, const Candidatos &c2);
};

class compara_vt_np{
    public:
    bool operator ()(const Partidos &p1, const Partidos &p2);
};

class compara_vt_vl_np{
    public:
    bool operator ()(const Partidos &p1, const Partidos &p2);
};