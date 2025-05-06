#pragma once
#ifndef _ESPILIGHTSW_INCLUDE
#define _ESPILIGHTSW_INCLUDE

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/log.h"

#include <ESPiLight.h>


namespace esphome {
namespace espilightswitch {

static const char *const TAG = "espilightswitch";

class EspilightSwitch : public switch_::Switch, public Component {
   public:

   void set_pin(int pin);

   float get_setup_priority() const override { return setup_priority::LATE; }

   void dump_config() override;

   ESPiLight *pESPiLight = nullptr;

   void set_protocol_name(String protocol_name) { this->protocol_name_ = protocol_name; }

//   void set_use_for_send(bool use_for_send) ;
   void set_protocol_data_on(String protocol_data) { this->protocol_data_on_ = protocol_data; }

   void set_protocol_data_off(String protocol_data) { this->protocol_data_off_ = protocol_data; }

//   void EspilightSwitch::rfCallback(const String &protocol, const String &message, int status, size_t repeats, const String &deviceID)
   protected:
   void setup() override;
   int8_t pin_ = 0;

   void write_state(bool state) override;

   void turn_switch(bool) ;
   String protocol_name_ = "";
   String protocol_data_on_ = "";
   String protocol_data_off_ = "";

//   bool use_for_send_ = false;

};

}  // namespace espilightsw
}  // namespace esphome

#endif
