/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef GameSimulationWorker_hpp
#define GameSimulationWorker_hpp

#include <iostream>
#include "../core/Worker.hpp"

class GameSimulationWorker : public Worker {
public:
    GameSimulationWorker(CommonData* commonData);
    void run();
};

#endif
