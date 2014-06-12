#pragma once
#ifndef GUARD_RandomNum_h
#define GUARD_RandomNum_h

#include <cstdio>
#include <stdexcept>
#include <ctime>

#include <stdlib.h> 
#include <time.h>
#include <random>
#include <functional>

using std::domain_error;


/********************************************************************************
*����������	����������ʵ��"���������"���ܣ�Ŀ���ǣ�����[lr,rr]�����ڵ��������
*���������	����int lr, int rr����ʾ������������ұ߽�
*����ֵ��	����ֵΪint�ͣ���ʾ�������ɵ��������
*******************************************************************************/
inline int nrand( int lr, int rr )
{
    static std::default_random_engine generator( ( unsigned ) time( nullptr ) );
    static std::uniform_int_distribution<int> dis( lr, rr );
    static auto dice = std::bind( dis, generator );

    return dice();
}


int nrand( int n ){
    if ( n <= 0 || n > RAND_MAX )
        throw domain_error( "Argument to nrand is out of range" );

    static bool flag = false;
    if ( !flag ){
        srand( ( unsigned ) time( NULL ) );
        flag = true;
    }

    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while ( r >= n );

    return r;
}

#endif