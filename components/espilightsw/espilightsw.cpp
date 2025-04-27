#include "espilightsw.h"


namespace esphome {
namespace espilightsw {

void EspilightSwitch::dump_config() {
   LOG_SWITCH(TAG, "Espilight name", this);
//        LOG_SWITCH(TAG, "Espilight name", this->protocol_name_);
//        LOG_SWITCH(TAG, "Espilight data", this->protocol_data_);
//        LOG_PIN("Pin:", this->pin_);
}

void EspilightSwitch::setup() {
   ESP_LOGI(TAG, "Initializing EspilightSwitch");
   this->turn_off();

}

void EspilightSwitch::write_state(bool state) {
   LOG_STR("EspilightSwitch::write_state");
   if (state) {
      LOG_STR("Write_starte State on");
      this->turn_switch();
//turn_switch();
   } else {
      LOG_STR("Write_starte State off");

   }
   this->publish_state(state);
}
void EspilightSwitch::turn_switch(void) {
   if (this->pESPiLight == nullptr) {
      this->pESPiLight =  new ESPiLight( pin_);
   }
   ESP_LOGI(TAG, "switching prname:%s data:%s", this->protocol_name_.c_str(), this->protocol_data_.c_str());
   this->pESPiLight->send(this->protocol_name_, this->protocol_data_);
}


}
}