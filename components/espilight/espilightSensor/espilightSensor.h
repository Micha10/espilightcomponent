#pragma once
#ifndef ESPILIGHTSENSOR_H
#define ESPILIGHTSENSOR_H

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/log.h"

#include <ESPiLight.h>


namespace esphome {
namespace espilightsensor {

static const char *const TAG = "espilightsensor";

class EspilightSensor : public sensor::Sensor, public PollingComponent {
   public:
   void update() override;
   void set_pin(int pin);

   float get_setup_priority() const override { return setup_priority::LATE; }

   void dump_config() override;

   ESPiLight *pESPiLight = nullptr;

  void rfCallback(const String &protocol, const String &message, int status, size_t repeats, const String &deviceID);

   protected:
   void setup() override;
   int8_t pin_ = 0;

};

}
}

#endif
