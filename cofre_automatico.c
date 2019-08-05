/*
 *
 * https://www.thehuxley.com/problem/102
 * 
 */

#include <stdio.h>

void lerArray(int i, int n, int array[]);
void lerComandos(int vAnterior, int n, int array[]);
void imprimir(int i, int n, int tamanho, int array[]);

int main() {
    int n;
    
    scanf("%d", &n);
    
    int array[n];
    
    lerArray(0, n, array);
    
    lerComandos(0, n, array);
    
	return 0;
}

void lerArray(int i, int n, int array[]){
    if(i < n){
        scanf("%d", &array[i]);
        lerArray(++i, n, array);
    }
}

void lerComandos(int indice, int n, int array[]){
    char ch;
    scanf(" %c", &ch);
    
    if(ch != 'S'){
        int v;
        scanf("%d", &v);
        
        int i;
        if(ch == 'D'){
            i = (indice +  n - (v % n)) % n;
            
        } else{
            i = (indice +  (v % n)) % n;
        }

        if(!i){
            imprimir(i, n - 1, n, array);
        } else{
            imprimir(i, i - 1, n, array);
        }
        
        lerComandos(i, n, array);
    }
    
}

void imprimir(int i, int n, int tamanho, int array[]){
    if(i == tamanho){
        i = 0;
    }
    
    if(i == n){ 
        printf("%d \n", array[i]);
    } else{
        printf("%d ", array[i]);
        imprimir(++i, n, tamanho, array);
    }
    
}