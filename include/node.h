using namespace std;

class node{
public:
  string valor;
  node* esq;
  node* dir;
  
  node(){
    valor = "INIT";
    esq = NULL;
    dir = NULL;
  }
};
