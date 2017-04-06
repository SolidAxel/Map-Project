//
//  main.cpp
//  Assignment 1
//
//  Created by Axel Garcia on 3/6/17.
//  Copyright © 2017 Axel Garcia. All rights reserved.
//

#include <stdio.h>
#include "Map.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(){
    Map m1;
    m1.insert("Fred", 2.956);
    cout<< m1.insertOrUpdate("Jim", 2.456)<<endl;
    m1.insert("r", 2.956);
    m1.insert("Fred", 2.956);
    m1.insert("Freed", 2.956);
    Map m2;
    m1.swap(m2);
    m1.swap(m2);
    m1.swap(m2);

    

    cout<< m1.size() << " " << m2.size()<<endl;


}


