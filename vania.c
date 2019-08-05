/*
 *
 * https://www.thehuxley.com/problem/561
 * 
 */

#include <stdio.h>

int qtdDigitos(int n);
unsigned long loopDeNove(int qtdDigitos);
unsigned long restanteDaSoma(int qtdDigitos);
unsigned long digitosNecessarios(int n);

int main() {
    int n;
    
    scanf("%d", &n);
    
    printf("\n%lu", digitosNecessarios(n));
    
	return 0;
}

int qtdDigitos(int n){
    return n / 10 == 0 ? 1 : 1 + qtdDigitos(n / 10);
}

unsigned long loopDeNove(int qtdDigitos){
    if(qtdDigitos == 1){
        return 0;
    }
    return qtdDigitos == 2 ? 9 : 9 * pow(10, qtdDigitos - 2) + loopDeNove(qtdDigitos - 1); 
}

unsigned long restanteDaSoma(int qtdDigitos){
    return qtdDigitos == 1 ? 0 :
                         9 * pow(10, qtdDigitos - 2) * (qtdDigitos - 1) + restanteDaSoma(qtdDigitos - 1);
}

unsigned long digitosNecessarios(int n){
    int quantidadeDigitos = qtdDigitos(n);
    unsigned long qtdParaSomar = restanteDaSoma(quantidadeDigitos);
    
    return (n - loopDeNove(quantidadeDigitos)) * quantidadeDigitos + qtdParaSomar;
}