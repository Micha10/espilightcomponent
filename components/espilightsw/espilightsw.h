#pragma once
#ifndef _ESPILIGHTSW_INCLUDE
#define _ESPILIGHTSW_INCLUDE

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/log.h"

#include <ESPiLight.h>


namespace esphome {
namespace espilightsw {

static const char *const TAG = "espilightsw";

class EspilightSwitch : public switch_::Switch, public Component {
   public:

   void set_protocol_name(String protocol_name) { this->protocol_name_ = protocol_name; }

   void set_protocol_data_on(String protocol_data) { this->protocol_data_on_ = protocol_data; }
   void set_protocol_data_off(String protocol_data) { this->protocol_data_off_ = protocol_data; }

   void set_pin(int pin) { pin_ = pin; }

   float get_setup_priority() const override { return setup_priority::LATE; }

   void dump_config() override;


   ESPiLight *pESPiLight = nullptr;
   protected:
   void write_state(bool state) override;

   void setup() override;

   void turn_switch(bool) ;

   String protocol_name_ = "";
   String protocol_data_on_ = "";
   String protocol_data_off_ = "";

   int8_t pin_ = 0;

};

}  // namespace espilightsw
}  // namespace esphome

#endif
