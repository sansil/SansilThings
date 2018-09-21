// #include <iostream>
#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

typedef enum tipo_sensor_t {
  s10HS=0,
  s5TE=1,
  sSG411=2,
  sAnalogico=3
};

class Puerto {
  protected: 
    int m_puerto;
    tipo_sensor_t m_tipo_sensor;
  public:
    Puerto(int puerto): m_puerto(puerto){};
    Puerto(int puerto, tipo_sensor_t tipo_sensor): m_puerto(puerto), m_tipo_sensor(tipo_sensor){};
    int get_puerto() {
      return m_puerto;
    }
    void set_puerto(int puerto){
      m_puerto = puerto;
    }
    tipo_sensor_t get_tipo_sensor(){
      return m_tipo_sensor;
    }
};

#endif