/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef StartNewGameWorker_hpp
#define StartNewGameWorker_hpp

#include <iostream>
#include "../core/Worker.hpp"

class StartNewGameWorker : public Worker {
public:
    StartNewGameWorker(CommonData* commonData);
    void run();
};

#endif
