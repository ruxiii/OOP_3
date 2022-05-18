#include <bits/stdc++.h>

using namespace std;

template<typename T> class Arr{
    vector<T> v;
public:
    Arr(vector<T>v);
    void Sortare(){
        for(int i=0;i<v.size()-1;i++){
            int j=i+1;
            while(j<v.size()){
                if(v[i]>v[j])
                    swap (v[i], v[j]);
                j++;
            }
        }
    };
    void print(){
        for (int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout << endl;
    }
};

template <typename T> Arr<T>::Arr(vector<T> aux) {
    v = aux;
}

class Agentie_Turism{
    string denumire;
    static Agentie_Turism* i;
    Agentie_Turism(){
        denumire="Travel1";
    }
public:
    void set_denumire(string denumire){
        this->denumire=denumire;
    }
    string get_denumire(){
        return this->denumire;
    }
    static Agentie_Turism* get_i() {
        if (!i)
            i = new Agentie_Turism;
        return i;
    }
};

Agentie_Turism* Agentie_Turism::i = 0;

class Vacante{
public:
    virtual int pret();
};

class Franta: public Vacante{
public:
    int pret(){
        return 100;
    }
};

class Spania: public Vacante{
public:
    int pret(){
        return 500;
    }
};

class SUA: public Vacante{
public:
    int pret(){
        return 900;
    }
};

class Canada: public Vacante{
public:
    int pret(){
        return 600;
    }
};

class Factory{  //factory
public:
    virtual Vacante* scump();
    virtual Vacante* ieftin();
};

class Destinatii_Europa: public Factory{
public:
    Vacante* scump(){
        return new Spania;
    }
    Vacante* ieftin(){
        return new Franta;
    }
};

class Destinatii_America_de_Nord: public Factory{
public:
    Vacante* scump(){
        return new SUA;
    }
    Vacante* ieftin(){
        return new Canada;
    }
};

int main() {
    Agentie_Turism *a= a->get_i();
    vector<int>p;
    a->set_denumire("Travel2");
    cout<<a->get_denumire();

    Factory *f1;
    Vacante *v1, *v2;
    f1= new Destinatii_Europa;
    v1= f1->scump();
    p.push_back(v1->pret());
    v2= f1->ieftin();
    p.push_back(v2->pret());

    Factory *f2;
    Vacante *v3, *v4;
    f2= new Destinatii_America_de_Nord;
    v3= f2->scump();
    p.push_back(v3->pret());
    v4= f2->ieftin();
    p.push_back(v4->pret());

    Arr<int> pr(p);
    pr.Sortare();
    pr.print();
}
