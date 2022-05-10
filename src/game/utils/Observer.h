#pragma once

#include <memory>
#include <list>


class Observer {
 public:
  virtual ~Observer();
  virtual void OnUpdate() = 0;
};


class Subject {
 public:
  virtual ~Subject();
  virtual void Attach(Observer* observer);
  virtual void Detach(Observer* observer);
  virtual void Notify() = 0;
  protected:
    std::list<Observer*> observers;
};