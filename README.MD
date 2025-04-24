This is an external component for ESPHome.

It's using the pilight (https://pilight.org/) source for switches with 433Mhz

The user puuu has created ESPiLight to use that protocols for an ESP device. (https://github.com/puuu/ESPiLight)

I'm using that project and just to wrap a small layer so it can be used by ESPHome (https://esphome.io/)

Here is an example yaml for ESPHome

``` yaml
esphome:
  name: espilight

esp32:
  board: esp32dev
  framework:
    type: arduino

external_components:
  - source:
      type: git
      url: https://github.com/Micha10/espilightcomponent.git
    components: [ espilightsw ]
    refresh: 10s

espilightsw:
  pin: 19
  protocol: "quigg_gt1000"
  data: "{\"id\":1,\"unit\":1,\"state\":\"on\"}"

switch:
  platform: gpio
  pin: 2
  id: t2

# Enable logging
logger:

# Enable Home Assistant API
api:
  password: ""

#ota:
#  password: ""

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Espilight Fallback Hotspot"
    password: "xxxxx"

captive_portal:

```