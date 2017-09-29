#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np

#1
def signal(N):
    error = 0
    for x in range(N):
        m = np.random.rand()
        if m < 0.4:
            s = 0
        else:
            s = 1
        
        eZero = 0.02
        eOne = 0.03
        t = np.random.rand()
        #if r != s count the error
        if s == 0 and t <= eZero:
            r = 1
            error += 1
        elif s == 0 and t > eZero:
            r = 0
        elif s == 1 and t <= eOne:
            r = 0
            error += 1
        elif s == 1 and t > eOne:
            r = 1

                
    print('Prob(Error) = ', error / N)

    
#2    
def signalTwo(N):
    success = 0
    countS = 0
    for x in range(N):
        m = np.random.rand()
        if m < 0.4:
            s = 0
        else:
            s = 1
            countS += 1
        
        eOne = 0.03
        t = np.random.rand()
        if s == 1 and t > eOne:
            r = 1
            success += 1

                
    print('Prob(R = 1|S = 1) = ', success / countS)
    

#3
def signalThree(N):
    rcount = 0
    success = 0
    for x in range(N):
        m = np.random.rand()
        if m < 0.4:
            s = 0
        else:
            s = 1
        
        eZero = 0.02
        eOne = 0.03
        t = np.random.rand()
        if s == 0 and t <= eZero:
            r = 1
            rcount += 1
        elif s == 1 and t > eOne:
            r = 1
            rcount += 1
            success += 1
            
    print('Prob(S = 1|R = 1) = ', success / rcount)
    
#4 
def signalFour(N):
    error = 0
    for x in range(N):
        m = np.random.rand()
        if m < 0.4:
            s = 0
        else:
            s = 1
        
        eZero = 0.02
        eOne = 0.03
        countZero = 0
        countOne = 0
        for y in range(3):
            t = np.random.rand()
            if s == 0 and t <= eZero:
                r = 1
                countOne += 1
                #print('One = ', countOne)
            elif s == 0 and t > eZero:
                r = 0
                countZero += 1
                #print('Zero ', countZero)
            elif s == 1 and t <= eOne:
                r = 0
                countZero += 1
                #print('Zero ', countZero)
            elif s == 1 and t > eOne:
                r = 1
                countOne += 1
                #print('One = ', countOne)
                
         #count == 2 because of majority rule    
        if countZero == 2:
            r = 0
            if s != r:
                error += 1
                #print('R = ', r, 'S = ', s)
                #print('Zero ', countZero)
        elif countOne == 2:
            r = 1
            if s != r:
                error += 1
                #print('R = ', r, 'S = ', s)
                #print('One = ', countOne)
            


    print('Prob(Error) = ', error / N)
    