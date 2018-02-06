#include <stdio.h>
int decode(int x, int y, int z){
    int temp = y-z;
    int nextTemp = temp*x;
    temp = temp << 31;
    temp = temp >> 31;
    return temp ^ nextTemp;
}
/*set int temp equal to int y - int z. Then set the nextTemp euqal to temp times x. temp is then shifted to the left by 31 and then shifted to the right by 31. Return of exclusive or biswise operator of temp or nextTemp */

int main(int argc, char *argv[]){
    printf("%d\n", decode(1,2,4));
    return 0;
    }
