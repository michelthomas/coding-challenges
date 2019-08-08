/*
 *
 * https://www.thehuxley.com/problem/1290
 * 
 */

#include <stdio.h>

int rickception(int n, int t);

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    printf("%d", rickception(n, t));

	return 0;
}

int rickception(int n, int t){
    if(t == 0) {
        return n;
    }
    if(t > 0) {
        n += 3;
        t--;
    } else {
        n += n % 5;
        t++;
    }   
    return rickception(n, (t * -1));
}