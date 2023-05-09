#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stack.h"
#include "actions.h"

using namespace std;

int main() {
  /*
  string str[6] = {"1", "1", "+", "3", "*", "STOP"};
  //string str;
  //cin >> str;
  int i = 0;
  cout << "BREAKPOINT!\n";
  infix_print(posfix_store(str));
  cout << "BREAKPOINT!\n";
  */
  
  string cmd, infixa; 
  int u=0;
  
  fstream input;
  node* g = new node();
  string file;
  cin >> file; 
  input.open(file);
  //node armazenado;
  
  while(!input.eof()){
    //cout << "BREAKPOINT!\n";
    input >> cmd;
    //cout << cmd << endl;
    if (cmd=="LER")
    {
      input >> cmd;
      if (cmd=="INFIXA"){ //armazenamento da infixa
        
        string str = "";
        while (!input.eof()){
          input >> cmd;
          if (strver(cmd)=='l') { //letras
              break;
          } else {str = str + cmd;}
        }
        //cout << str;
        g = infix_store(str, u); 
        cout << "EXPRESSAO OK: ";
        infix_print(g);
        cout << "\n";
        //cout << "BREAKPOINT!2\n";
      } //fim do armazenamento da expressão infixa
      
      else if (cmd=="POSFIXA"){ //armazenamento da posfixa
        string array[10000];
        int i=0;
        while (!input.eof()){
          input >> cmd;
          if (strver(cmd)=='l') { //letras
              break; 
          } else {array[i]=cmd;}
          i++;
        }
        array[i] = "STOP";
        g = posfix_store(array);
        cout << "EXPRESSAO OK: ";
        posfix_print(g);
        cout << "\n";
          } // fim do armazenamento da posfixa

    } if (cmd=="POSFIXA"){
        if (g->valor=="INIT") cout << "ERRO: EXP NAO EXISTE";
        else{
        cout << "POSFIXA: ";
        posfix_print(g);
        cout << "\n";
        }
    } if (cmd=="INFIXA"){ 
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
   
  
}

/*
else if (cmd=="POSFIXA"){ //binary tree
        cmd = "";
        infixa = "";
        while(cmd != "INFIXA" && cmd != "POSFIXA" && 
              cmd != "LER" && cmd != "RESOLVE"){
          infixa = infixa + cmd;
          input >> cmd;
              }
        pfstore(infixa);
      }


*/