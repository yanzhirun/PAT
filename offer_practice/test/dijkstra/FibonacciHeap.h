#ifndef _FIBONACCI_HEAP_H_INCLUDED__
#define _FIBONACCI_HEAP_H_INCLUDED__

#include <funtional>
#include <algorithm>

template<typename T>
struct Fib_node
{
    Fib_node* ns_;
    Fib_node* pt_;
    Fib_node* ps_;
    Fib_node* fc_;
    int rank_;
    bool marked_;
    T* pv_;
    Fib_node(T* pv = 0):pv_(pv){}
    T& value(void){return *pv_;}
    void set_src(T* pv){pv_ = pv;}
};

