#include "espilightSensor.h"

namespace esphome {
namespace espilightsensor {


EspilightSensor *EspilightSensor::instance = nullptr; // Initialisierung des statischen Zeigers

void rfCallback(const String &protocol, const String &message, int status, size_t repeats, const String &deviceID) {

   ESP_LOGI(TAG, "RF signal arrived [%s][%s] (%i) %s", protocol.c_str(), deviceID.c_str(), status, message.c_str());

   // check if message is valid and process it
   if (status == VALID) {
      ESP_LOGI(TAG, "RF signal valid [%s][%s]", protocol.c_str(), message.c_str());

         std::string outstr ="";
         outstr.append( protocol.c_str());
         outstr.append(". ");
         outstr.append(message.c_str());
      if (EspilightSensor::instance != nullptr) {
         //EspilightSensor::instance->publish_state(outstr);
         EspilightSensor::instance->last_state.empty();
         EspilightSensor::instance->last_state.append(outstr);
      }
   }
}
void rfRawCallback(const uint16_t* codes, size_t length) {
   // print pulse lengths
   ESP_LOGI(TAG, "***************************RAW signal arrived ");
   for (unsigned int i = 0; i < length; i++) {
      ESP_LOGI(TAG, "%i ", codes[i]);
   }

   // format of pilight USB Nano
   String data = ESPiLight::pulseTrainToString(codes, length);
   ESP_LOGI(TAG, "*********************string format: %s ", data.c_str());
}


void EspilightSensor::dump_config() {
   LOG_TEXT_SENSOR(TAG, "Espilight name", this);
}

void EspilightSensor::setup() {
   ESP_LOGI(TAG, "***********************Initializing EspilightSensor. Receiver Pin: %i", this->pin_);
   if (this->pESPiLight == nullptr) {
      this->pESPiLight = new ESPiLight(-1);
   }

   // Setze den statischen Zeiger auf die aktuelle Instanz
   EspilightSensor::instance = this;

// region callback
   this->pESPiLight->setCallback(rfCallback);
   this->pESPiLight->initReceiver(this->pin_);
   rfCallback("******************************* DEMOPROTOKOLL", "DEMODATA", VALID, 0, "DEMOID");

   ESP_LOGI(TAG, "**************AvailProtocols: %s", this->pESPiLight->availableProtocols().c_str());
// endregion

//region raw callback
//   this->pESPiLight->setPulseTrainCallBack(rfRawCallback);
//   this->pESPiLight->initReceiver(this->pin_);
//endregion raw callback

}
void EspilightSensor::loop() {
   this->pESPiLight->loop();
}

void EspilightSensor::set_pin(int pin) {
   this->pin_ = pin;
}
void EspilightSensor::update() {
   this->publish_state(this->last_state);
}

}
}

