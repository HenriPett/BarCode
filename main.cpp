#include <iostream>

#include <string>

using namespace std;

string requestInput(bool wrongInput) {
    string barcode;
    
    //verificador de codigo de barras, so aceita 13 digitos.
    
    if (wrongInput) cout << "Insira o código de barras: ";
    else cout << "O código de barras inserido é inválido. Insira-o novamente: ";
    
    cin >> barcode;
    
    return barcode;
}

int main() {
  
  string codigo = requestInput(true);
  int len = codigo.length();

  while (len != 13) {
      codigo = requestInput(false); 
      len = codigo.length();
  };

  int resul = 0;

  //Loop for para iterar por todos os digitos e verificar quais sao pares e impares.
  for (int i = 1; i <= len - 1; i++) {
    int n = codigo[i - 1] - 48;

  //se a colocaçao do numero for impar, o numero é multiplicado por 3, se for par, nada acontece.
    if (i % 2 == 0) {             
      resul = resul + (n * 3);
    } else {
      resul = resul + n;
    }
  }

  //calculos feitos depois do resultado da soma dos caracteres.
  int divi = resul;

  divi = divi / 10;
  divi = divi + 1;
  divi = divi * 10;

  //Calculo do numero verificador
  int verif = divi - resul;

  //caso o numero seja multiplo de 10, sera substituido por 0.    
  if (verif % 10 == 0) verif = 0;

  //print do valor do verificador.
  cout << "verificador: " << verif << endl;
    
  //verificaçao se o codigo de barras é correto ou nao.
  if (codigo[len - 1] - 48 == verif) cout << "Codigo de barras correto! ";
      
  else cout << "Codigo de barras incorreto. ";

  return 0;
}