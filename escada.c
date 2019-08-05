/*
 *
 * https://www.thehuxley.com/problem/198
 * 
 */

#include <stdio.h>

int escada(int i, int n, int t);

int main() {
    int n;
    
    scanf("%d", &n);
    
    printf("%d", escada(0, n, 0));
    
	return 0;
}

int escada(int i, int n, int t){
    if(i == n){
        return t + 10;
    }
    
    int x;
    
    scanf("%d", &x);
    
    if(i == 0){
        return (x * -1) + escada(++i, n, x);
    }
    
    return (x - t - 10) > 0 ? ((x - t - 10) * -1) + escada(++i, n, x) : 0 +  escada(++i, n, x);
}