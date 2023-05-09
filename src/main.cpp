#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stack.h"
#include "actions.h"

using namespace std;

int main() {
  
  string cmd, infixa; 
  int u=0;
  
  fstream input;
  node* g = new node();
  string file;
  cin >> file; //o endereço local do arquivo é recebido como input
  input.open(file);
  
  while(!input.eof()){
 
    input >> cmd;
    if (cmd=="LER")
    {
      input >> cmd;
      if (cmd=="INFIXA"){ //armazenamento da infixa
        
        string str = "";
        while (!input.eof()){ //transforma a expressão em uma string str
          input >> cmd;      
          if (strver(cmd)=='l') { //l = letras
              break;
          } else {str = str + cmd;}
        }
        g = infix_store(str, u);  
        cout << "EXPRESSAO OK: ";
        infix_print(g);
        cout << "\n";
      } //fim do armazenamento da expressão infixa
      
      else if (cmd=="POSFIXA"){ //armazenamento da posfixa
        string array[10000];
        int i=0;
        while (!input.eof()){ //transforma a expressão em uma array de strings
          input >> cmd;
          if (strver(cmd)=='l') { //l = letras
              break; 
          } else {array[i]=cmd;}
          i++;
        }
        array[i] = "STOP"; //condição de parada para a função
        g = posfix_store(array);
        cout << "EXPRESSAO OK: ";
        posfix_print(g);
        cout << "\n";
          } // fim do armazenamento da posfixa

    } if (cmd=="POSFIXA"){ //conversão para posfixa
        if (g->valor=="INIT") cout << "ERRO: EXP NAO EXISTE";
        else{
        cout << "POSFIXA: ";
        posfix_print(g);
        cout << "\n";
        }
    } if (cmd=="INFIXA"){ //conversão para infixa
        if (g->valor=="INIT") cout << "ERRO: EXP NAO EXISTE";
        else{
        cout << "INFIXA: ";
        infix_print(g);
        cout << "\n";
        }
    } if (cmd=="RESOLVE"){ 
        if (g->valor=="INIT") cout << "ERRO: EXP NAO EXISTE";
        else{
        printf("VAL: %.6f\n", resolver(g));
        }
    }
  }
   
  return 0;
}

