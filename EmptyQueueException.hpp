#ifndef EMPTYQUEUEEXCEPTION_HPP
#define EMPTYQUEUEEXCEPTION_HPP
#include <exception>
using namespace std;

class EmptyQueueException: public exception {

  virtual char const* what() const throw() {

    return "Blad. Kolejka jest pusta.";
    
  }
};

#endif
