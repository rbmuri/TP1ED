#include "node.h"
using namespace std;

class stack{
  private:
    int topo;
    string w[10000];
  public:
    stack(){
      topo = -1;
    }
    void place(string x){
      topo++;
      w[topo] = x;
    }
    string top(){
      return w[topo];
    }
    int size(){
      return topo+1;
    }
    string pop(){
      topo--;
      return w[topo+1];      
    }
};

class nodestack{
  private:
    int topo;
    node* w[10000];
  public:
    nodestack(){
      topo = -1;
    }
    void place(node* x){
      topo++;
      w[topo] = x;
    }
    node* top(){
      return w[topo];
    }
    int size(){
      return topo+1;
    }
    node* pop(){
      topo--;
      return w[topo+1];      
    }
};