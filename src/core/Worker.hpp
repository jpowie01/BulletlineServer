/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Worker_hpp
#define Worker_hpp

#include <iostream>

#include "CommonData.hpp"

class Worker {
public:
    // Data
    CommonData* commonData;
    sf::Thread* thread;

    // Constructors
    Worker();
    Worker(CommonData* commonData);
    ~Worker();

    // Core
    virtual void run() = 0;
    void runConcurrent();
};

#endif
