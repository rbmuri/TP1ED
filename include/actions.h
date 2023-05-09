using namespace std;


double resolver(node* exp){
  if (exp->esq == NULL && exp->dir == NULL ){
    return stod(exp->valor); //se estiver em uma folha, retorne o valor
  } 
else{if (exp->valor == "+") //se não, realize a operação entre os filhos
     return resolver(exp->esq) + resolver(exp->dir);
else if (exp->valor == "-") 
     return resolver(exp->esq) - resolver(exp->dir);
else if (exp->valor == "*") 
     return resolver(exp->esq) * resolver(exp->dir);
else if (exp->valor == "/") 
     return resolver(exp->esq) / resolver(exp->dir);
  }
  
}

bool isvalid(string array[]){
  int i = 0, u=0; //função que não foi implementada no resultado final
  while (array[u]!="STOP"){
    if (strver(array[u])=='o'){
      if (i<2) return false;
      i--;
    } else if (strver(array[u])=='n'){
      i++;
    }
    u++;
    if (i<0) return false;
  }
  if (i!=1) return false;
  return true;
}


char strver(char c){ //função para verificar o conteúdo de uma string
  if (c=='*' || c=='+' || c=='-' || c=='/'){
    return 'o'; //operação
  } else if (c=='(' || c==')'){
    return 'p'; //parenteses
  } else if (c=='0' || c=='1' || c=='2' || c=='3' 
          || c=='4' || c=='5' || c=='6' || c=='7'
          || c=='8' || c=='9' || c=='.'){
    return 'n'; //números
  } else {
    return 'l'; //letras
  }
}

char strver(string str){
  if (str[0]=='*' || str[0]=='+' || str[0]=='-' || str[0]=='/'){
    return 'o';
  } else if (str[0]=='(' || str[0]==')'){
    return 'p';
  } else if (str[0]=='0' || str[0]=='1' || str[0]=='2' || str[0]=='3' 
          || str[0]=='4' || str[0]=='5' || str[0]=='6' || str[0]=='7'
          || str[0]=='8' || str[0]=='9' || str[0]=='.'){
    return 'n';
  } else {
    return 'l';
  }
}

node* posfix_store(string array[]){
  int i=0;
  node* res = new node();
  nodestack stk;
  while (1){
    if (strver(array[i])=='n') { //armazena os números em stacks de nodes
      node* p = new node();
      p->valor = array[i];
      stk.place(p);
    }
    else if (strver(array[i])=='o') { // as remove e coloca como folhas quando
      node* p = new node();           // encontra operações, depois insere a
      p->valor = array[i];            // operação de volta na pilha
      p->dir = stk.pop();
      p->esq = stk.pop();
      res = p;
      stk.place(p);
    }
    else if (array[i]=="STOP"){
      break;
    }
    i++;
  }
  return res;        
}

node* infix_store(string str, int &i){
  node *exp = new node(), *exp2 = new node();
  
    string cmd="";
    
    if (strver(str[i])=='n'){ //n = numero
      while(strver(str[i])=='n'){ 
        cmd = cmd + str[i]; //combina em uma string
        i++;
      }
      exp->valor = cmd; //guarda em exp
    }
    if (str[i]=='('){ //se achar um parenteses, entra em recursão
      i++;
      exp = infix_store(str, i);
    }
    if (str[i]==')'){ 
      i++;
      return exp; //retorna da recursão
    }   
    if (strver(str[i])=='o'){ //fixa os valores dos filhos do node
      exp2->valor = str[i];   //e entra em recursão para fixar seu
      exp2->esq = exp;        //filhos direitos
      i++;
      exp2->dir = infix_store(str, i);
      return exp2;
    }
    return exp; //depois de tudo, retorna o resultado final 
}               //(em algumas ocasiões, o resultado já é retornado antes de chegar aqui)

void infix_print(node* exp){ //converte para in fixo
    if (exp->esq == NULL){
        cout << "( " << exp->valor << " ) ";
    } else {
        cout << "( ";
        infix_print(exp->esq);
        cout << exp->valor << " ";
        infix_print(exp->dir);
        cout << " ) ";
    }
}

void posfix_print(node* exp){ //converte para pos fixo
    if (exp->esq == NULL){
        cout << exp->valor << " ";
    } else {
        posfix_print(exp->esq);
        posfix_print(exp->dir);
        cout << exp->valor << " ";
    }
}
