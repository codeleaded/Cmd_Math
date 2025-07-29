#pragma once

#define PI 3.141592654f

typedef float F32;
typedef double F64;
typedef long double F80;

int sqrtI32(long long a){
    if(a==0LL) return 0;
    int max = 1000;
    long long num = 1;
    for(int i = 0;i<max;i++){
        long long  z = num;
        num = (num + (a / num)) >> 1;
        if(num==z) break;
    }
    return num;
}

F32 sqrtF32(F32 a){
    if(a==0.0f) return 0.0f;
    F32 max = 1000;
    F32 num = 1.0f;
    for(int i = 0;i<max;i++){
        num = (num + (a / num)) * 0.5f;
    }
    return num;
}

F32 absF32(F32 x){
    if(x>0) return x;
    return -x;
}

F32 minF32(F32 x,F32 y){
    if(y<x) return y;
    return x;
}

F32 sinSqF32(F32 x){
    F32 y = x / (2*PI);
    y = y - (int)y;
    y = y + 1.0f;
    y = y - (int)y;
    if(y<0.5f){
        return -16*y*y+8*y; 
    }
    return 16*y*y-16*y-8*y+8;
}

F32 cosSqF32(F32 x){
    return sinSqF32(x+PI/2);
}

F32 sinCbF32(F32 x){
    F32 y = x / (2*PI);
    y = y - (int)y;
    y = y + 1.0f;
    y = y - (int)y;
    return 20.785f * (y-0.0f) * (y-0.5f) * (y-1.0f);
}

F32 cosCbF32(F32 x){
    return sinCbF32(x+PI/2);
}

F32 tanSqF32(F32 x){
    F32 y = cosSqF32(x);
    if(y==0.0f) return 0.0f;
    return sinSqF32(x) / y;
}

F32 tanCbF32(F32 x){
    F32 y = cosCbF32(x);
    if(y==0.0f) return 0.0f;
    return sinCbF32(x) / y;
}

F32 asinSqF32(F32 y){
    F32 a,b,c;
    if(y>=0){
        a = -16.0f;
        b = 8.0f;
        c = -y;
    }else{
        a = 16.0f;
        b = -24.0f;
        c = 8.0f-y;
    }
    F32 x = (-b+sqrtF32(b*b-4.0f*a*c)) / (2.0f*a);
    x *= 2*PI;
    return x;
}

F32 acosSqF32(F32 y){
    return asinSqF32(y)-(PI/2);
}
