#ifndef RECURSO_H
#define RECURSO_H
#include "Arduino.h"

#define MAX_LARGO_R_VALOR 30

class recurso {

private:

    // calback for function, input, output, or input/output
  struct callback {
    char* (*run)(int pin);
  };
public: 
  // thinger_resource():  {};
  callback callback_;
  char r_valor[MAX_LARGO_R_VALOR];

  
    /**
     * Establish a function with input parameters
     */
    void operator << (char* (*in_function)(int pin)){
        callback_.run = in_function;
    }

    void operator >> (int pin){
      callback_.run(pin);
    }
    
    void execute (int pin) {
      memset(r_valor,'\0', MAX_LARGO_R_VALOR);
      char* p_char = callback_.run(pin);
      if(strlen(p_char) < MAX_LARGO_R_VALOR)
        strcpy(r_valor, p_char);
      else
        strcpy(r_valor, "0");
    }
};

#endif
