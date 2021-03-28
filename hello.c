#include <stdio.h>
void test(int* c){
    *c = *c * 5 + 5;
    return;
}
int main(){
    int c = 0, d  = 3;
    float f = 1.5;
    test(&c);
    printf("%.2d:%.2d", c, d);
    return 0;
}