
/*
 * Object.h
 *
 *  Created on: Jan 28, 2021
 *      Author: tmuqbil
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */

#include <limits.h>

using std::vector;
using namespace std;

class GlodenNumber{
private:
    int _numberOfParamters =8;
public:
    GlodenNumber(){
        for (int i=0;i<_numberOfParamters;i++){
            paramters.push_back(0);
            mutate(i);
        }
    };

    vector<int> paramters;


    vector<int> fibonacci = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};


    unsigned long calculateScore(){
    	unsigned long score ;
        score =0;
        unsigned long value;
        for (unsigned int i =0 ; i< fibonacci.size(); i++){
        	value = fib_mem(i,paramters);
			score += (value - fibonacci[i])*(value - fibonacci[i]);
        }
        return  ULLONG_MAX-  score;
    }

    unsigned int NIL = 0;
    unsigned long fib_mem(unsigned int n, vector<int> &parm) {
    	unsigned long lookup_table[n+20];
    	for(unsigned int i=0; i<=n; i++)lookup_table[i] = NIL;
    	lookup_table[0]=0;
    	lookup_table[1]=1;
\
    	int numberOfHalfOfparamters= _numberOfParamters/2;
    	for(unsigned int i=0; i<=n; i++){

    		for (int j = 0; j< numberOfHalfOfparamters;j++){
    			lookup_table[i+parm[j]]+=lookup_table[i]*parm[numberOfHalfOfparamters+j];
    		}

    	}
    	return lookup_table[n];
    }

    void mutate(int index){
    	if (index <_numberOfParamters/2){
    		paramters[index] = rand()%15;
    	} else {
    		paramters[index] = rand()%3-1;
    	}

    }

    void printThis(){
		unsigned long score ;
		score =0;
		unsigned long value;
		for (unsigned int i =0 ; i< fibonacci.size(); i++){
			value = fib_mem(i,paramters);
			score += (value - fibonacci[i])*(value - fibonacci[i]);
		}
    	for (int i=0;i<_numberOfParamters;i++){
			std::cout<< paramters[i]<<",";
		}
    	std::cout<< "  | " << score <<"\n";;
    }
};





#endif /* OBJECT_H_ */
