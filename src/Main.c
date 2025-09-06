#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./MathLib.h"

int main(int argc,char **argv){
    printf("Out: %f\n",asinf(-0.5f));
    printf("Out: %f\n",asinSqF32(-0.5f));
    return 0;
}