/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Worker.hpp"

//================================================================================
// Constructors
//================================================================================

Worker::Worker() {
    this->commonData = NULL;
}

Worker::Worker(CommonData* commonData) {
    this->commonData = commonData;
}

Worker::~Worker() {
    this->thread->terminate();
}

//================================================================================
// Core
//================================================================================

void Worker::runConcurrent() {
    this->thread = new sf::Thread(&Worker::run, this);
    this->thread->launch();
}
