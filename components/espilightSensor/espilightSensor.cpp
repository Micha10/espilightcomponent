#include "espilightSensor.h"

namespace esphome {
namespace espilightsensor {

void EspilightSensor::dump_config() {
   LOG_SENSOR(TAG, "Espilight name", this);
}

void EspilightSensor::setup() {
   ESP_LOGI(TAG, "Initializing EspilightSensor");
   if (this->pESPiLight == nullptr) {
      this->pESPiLight = new ESPiLight(pin_);
   }
   this->pESPiLight->initReceiver(this->pin_);

   // Verwenden Sie eine Lambda-Funktion, um den `this`-Zeiger zu binden
//   this->pESPiLight->setCallback([this](const String &protocol, const String &message, int status, size_t repeats, const String &deviceID) {
//      this->rfCallback(protocol, message, status, repeats, deviceID);
//   });
//   this->pESPiLight->setCallback(this->rfCallback);
}

void EspilightSensor::set_pin(int pin) {
   this->pin_ = pin;
}
void EspilightSensor::update() {
   float value_v = 4.4f;
   ESP_LOGV(TAG, "'%s': Got demodata=%.4fV", this->get_name().c_str(), value_v);
   this->publish_state(value_v);
}

void EspilightSensor::rfCallback(const String &protocol, const String &message, int status, size_t repeats, const String &deviceID) {
   Serial.print("RF signal arrived [");
   Serial.print(protocol);  // protocoll used to parse
   Serial.print("][");
   Serial.print(deviceID);  // value of id key in json message
   Serial.print("] (");
   Serial.print(status);  // status of message, depending on repeat, either:
   // FIRST   - first message of this protocoll within the
   //           last 0.5 s
   // INVALID - message repeat is not equal to the
   //           previous message
   // VALID   - message is equal to the previous message
   // KNOWN   - repeat of a already valid message
   Serial.print(") ");
   Serial.print(message);  // message in json format
   Serial.println();

   // check if message is valid and process it
   if (status == VALID) {
      Serial.print("Valid message: [");
      Serial.print(protocol);
      Serial.print("] ");
      Serial.print(message);
      Serial.println();
   }
}

}
}

