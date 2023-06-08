//https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp

// Indroduction to threads in c++

/**
 *  0.  In Every appplication there is a default thread called main thread.  
 *  1.  Thread is a sequence of instructions within a process.
 *  2.  A process can have multiple threads.
 *  3.  Threads in a process share the same address space.
 *  4.  Threads in a process share the same data.
 *  5.  Threads in a process share the same heap but have their own stack.
 *  6.  Threads in a process have their own register values and program counter.  
 *  7.  Threads in a process have their own thread id.
 *  8.  Threads in a process have their own priority.
*/  

/*
    Ways to create threads in c++:
    1.  Using function pointer
    2.  Using lambda function
    3.  Using member function
    4.  Using static member function
    5.  Using functor

*/

// In this demonstration , we whill create threads using function pointer.'
// There will be two funxtion findEven and findOdd.
// Both function will find sum of even and odd numbers respectively from 1 to 1900000000.
// We will create two threads using function pointer and pass the function name as argument.

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddsum =0;
ull evensum =0;

ull oddsum1 =0;
ull evensum1 =0;


void findeven(ull begin, ull end){
    for(ull i=begin; i<=end; i++){
        if((i&1)==0){
            evensum +=i;
        }
    }
}

void findodd(ull begin, ull end){
    for(ull i=begin; i<=end; i++){
        if((i&1)==1){
            oddsum +=i;
        }
    }
}

int main(){
    //meke me a program which demonstrates time taken by single thread and multithread.
    ull start = 0;
    ull end = 1900000000;

    auto startTime = high_resolution_clock::now();

    findeven(start, end);
    findodd(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout<<"Single thread even sum: "<<evensum<<endl;
     cout<<"Single thread odd sum: "<<oddsum<<endl;
    cout<<"Single thread time: "<<duration.count()/1000<<" milliseconds"<<endl;

    evensum = 0;
    oddsum = 0;

    startTime = high_resolution_clock::now();

    thread t1(findeven, start, end);
    thread t2(findodd, start, end);

    t1.join();
    t2.join();

    stopTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stopTime-startTime);
    cout<<"Multi thread even sum: "<<evensum<<endl;
    cout<<"Multi thread odd sum: "<< oddsum<<endl;
    cout<<"Multi thread time: "<<duration.count()/1000<<" milliseconds"<<endl;
    
    return 0;

}