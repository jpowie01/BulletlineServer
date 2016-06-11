/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef UpdatePlayersWorker_hpp
#define UpdatePlayersWorker_hpp

#include <iostream>
#include "../core/Worker.hpp"

class UpdatePlayersWorker : public Worker {
public:
    UpdatePlayersWorker(CommonData* commonData);
    void run();
};

#endif
