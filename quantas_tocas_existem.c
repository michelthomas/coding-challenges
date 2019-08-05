/*
 *
 * https://www.thehuxley.com/problem/1032
 * 
 */

#include <stdio.h>

void lerArray(int i, int n, int array[]);
void imprimirArray(int i, int n, int array[]);
int calcularTamanhoToca(int i, int n, int buracos[]);
int calcularQtdTocas(int i, int n, int buracos[]);

int main(void) {
  int n;
  scanf("%d", &n);

  int buracos[n];
  lerArray(0, n, buracos);

  printf("%d", calcularQtdTocas(0, n, buracos));
  return 0;
}

void lerArray(int i, int n, int array[]){
    if(i < n){
        scanf("%d", &array[i]);
        lerArray(++i, n, array);
    }
}

void imprimirArray(int i, int n, int array[]){
    if(i < n){
        printf("%d ",array[i]);
        imprimirArray(++i, n, array);
    }
}

int calcularTamanhoToca(int i, int n, int buracos[]){
  if(buracos[i] == -1){
    return 1;
  }

  int j = buracos[i];
  buracos[i] = -1;
  i = j;

  return calcularTamanhoToca(j, n, buracos);
}

int calcularQtdTocas(int i, int n, int buracos[]){
  if(i == n){
    return 0;
  }

  return buracos[i] != -1 ? calcularTamanhoToca(i, n, buracos) + calcularQtdTocas(i + 1, n, buracos)
                          : calcularQtdTocas(i + 1, n, buracos);
}
