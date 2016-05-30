/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef UpdatePlayersPositionsWorker_hpp
#define UpdatePlayersPositionsWorker_hpp

#include <iostream>
#include "../core/Worker.hpp"

class UpdatePlayersPositionsWorker : public Worker {
public:
    UpdatePlayersPositionsWorker(CommonData* commonData);
    void run();
};

#endif
