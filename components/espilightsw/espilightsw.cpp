#include "espilightsw.h"


namespace esphome {
namespace espilightsw {

void EspilightSwitch::dump_config() {
   LOG_SWITCH(TAG, "Espilight name", this);
}

void EspilightSwitch::setup() {
//   ESP_LOGI(TAG, "Initializing EspilightSwitch");
   this->turn_off();

}

void EspilightSwitch::write_state(bool state) {
//   LOG_STR("EspilightSwitch::write_state");
   if (state) {
//      LOG_STR("Write_starte State on");
      this->turn_switch(true);
   } else {
//      LOG_STR("Write_starte State off");
      this->turn_switch(false);

   }
   this->publish_state(state);
}

void EspilightSwitch::turn_switch(bool on_off) {
   if (this->pESPiLight == nullptr) {
      this->pESPiLight = new ESPiLight(pin_);
   }
//   ESP_LOGI(TAG, "switching prname:%s data:%s --- %s", this->protocol_name_.c_str(), this->protocol_data_on_.c_str(),  this->protocol_data_off_.c_str());
   if (on_off) {
      this->pESPiLight->send(this->protocol_name_, this->protocol_data_on_);
   } else {
      this->pESPiLight->send(this->protocol_name_, this->protocol_data_off_);
   }
}

}
}