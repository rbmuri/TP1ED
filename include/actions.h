using namespace std;


double resolver(node* exp){
  if (exp->esq == NULL && exp->dir == NULL ){
    return stod(exp->valor);
  } 
else{if (exp->valor == "+") 
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
  int i = 0, u=0;
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
bool isvalid(string str, int &i){
  
}

char strver(char c){
  if (c=='*' || c=='+' || c=='-' || c=='/'){
    return 'o';
  } else if (c=='(' || c==')'){
    return 'p';
  } else if (c=='0' || c=='1' || c=='2' || c=='3' 
          || c=='4' || c=='5' || c=='6' || c=='7'
          || c=='8' || c=='9' || c=='.'){
    return 'n';
  } else {
    return 'l';
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
    if (strver(array[i])=='n') {
      node* p = new node();
      p->valor = array[i];
      stk.place(p);
    }
    else if (strver(array[i])=='o') {
      node* p = new node();
      p->valor = array[i];
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
/*
node* infix_store(string str, int &i){
  node *exp = new node(), *exp2 = new node(), *exp3 = new node();
  
    string cmd="";
    //cout << "BREAKPOINT!\n";
    if (strver(str[i])=='n'){ //se for numero
      while(strver(str[i])=='n'){ 
        cmd = cmd + str[i]; //combina em uma string
        i++;
      }
      //cout << "BREAKPOINT!\n";
      exp->valor = cmd; //guarda e retorna
      //cout << cmd << endl;
      
    }
    if (str[i]=='('){
      i++;
      exp = infix_store(str, i);
    }
    if (str[i]==')'){ 
      i++;
      cout << exp->valor << " BREAKPOINT!\n";
      return exp;
    }   
    if (strver(str[i])=='o'){
      exp2->valor = str[i];
      exp2->esq = exp;
      i++;
    }
    if (str[i]=='('){
      i++;
      exp = infix_store(str, i);
    }
    if (str[i]==')'){
      exp2->dir = exp;
      cout << exp2->valor << " " << exp->valor << " BREAKPOINT!\n";
      return exp2;
    }
    return exp;
}
*/

node* infix_store(string str, int &i){
  node *exp = new node(), *exp2 = new node();
  
    string cmd="";
    //cout << "BREAKPOINT!\n";
    if (strver(str[i])=='n'){ //se for numero
      while(strver(str[i])=='n'){ 
        cmd = cmd + str[i]; //combina em uma string
        i++;
      }
      //cout << "BREAKPOINT!\n";
      exp->valor = cmd; //guarda e retorna
      //cout << cmd << endl;
      
    }
    if (str[i]=='('){
      i++;
      exp = infix_store(str, i);
    }
    if (str[i]==')'){ 
      i++;
      //cout << exp->valor << " BREAKPOINT!\n";
      return exp;
    }   
    if (strver(str[i])=='o'){
      exp2->valor = str[i];
      exp2->esq = exp;
      i++;
      exp2->dir = infix_store(str, i);
      return exp2;
    }
    return exp;
}

void infix_print(node* exp){
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

void posfix_print(node* exp){
    if (exp->esq == NULL){
        cout << exp->valor << " ";
    } else {
        posfix_print(exp->esq);
        posfix_print(exp->dir);
        cout << exp->valor << " ";
    }
}
