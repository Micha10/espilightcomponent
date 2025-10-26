#include "espilightSwitch.h"


namespace esphome {
namespace espilightswitch {

void EspilightSwitch::dump_config() {
   LOG_SWITCH(TAG, "Espilight name", this);
}

void EspilightSwitch::setup() {
//   ESP_LOGI(TAG, "Initializing EspilightSwitch");
   if (this->pESPiLight == nullptr) {
      this->pESPiLight = new ESPiLight(pin_);
   }
//   if (this->use_for_send_) {
   this->turn_switch(false);
//   } else {
//      this->pESPiLight.setCallback(this->rfCallback);
//      this->pESPiLight.initReceiver();
//   }
}

void EspilightSwitch::set_pin(int pin) {
   this->pin_ = pin;
}
//
//void EspilightSwitch::set_use_for_send(bool use_for_send) {
//   this->use_for_send_ = use_for_send;
//}

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

   //   ESP_LOGI(TAG, "switching prname:%s data:%s --- %s", this->protocol_name_.c_str(), this->protocol_data_on_.c_str(),  this->protocol_data_off_.c_str());
   if (on_off) {
      this->pESPiLight->send(this->protocol_name_, this->protocol_data_on_);
   } else {
      this->pESPiLight->send(this->protocol_name_, this->protocol_data_off_);
   }
}
//
//void EspilightSwitch::rfCallback(const String &protocol, const String &message, int status, size_t repeats,
//                                 const String &deviceID) {
//   Serial.print("RF signal arrived [");
//   Serial.print(protocol);  // protocoll used to parse
//   Serial.print("][");
//   Serial.print(deviceID);  // value of id key in json message
//   Serial.print("] (");
//   Serial.print(status);  // status of message, depending on repeat, either:
//   // FIRST   - first message of this protocoll within the
//   //           last 0.5 s
//   // INVALID - message repeat is not equal to the
//   //           previous message
//   // VALID   - message is equal to the previous message
//   // KNOWN   - repeat of a already valid message
//   Serial.print(") ");
//   Serial.print(message);  // message in json format
//   Serial.println();
//
//   // check if message is valid and process it
//   if (status == VALID) {
//      Serial.print("Valid message: [");
//      Serial.print(protocol);
//      Serial.print("] ");
//      Serial.print(message);
//      Serial.println();
//   }
//}

}
}

