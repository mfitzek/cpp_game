#include "Observer.h"



Observer::~Observer(){
    
}


void Subject::Attach(Observer* observer){
    observers.push_back(observer);
}

void Subject::Detach(Observer* observer){
    observers.remove(observer);
}

Subject::~Subject(){
    observers.clear();
}

