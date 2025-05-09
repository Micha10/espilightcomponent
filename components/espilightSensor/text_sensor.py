import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, text_sensor
from esphome.const import CONF_ID, CONF_PIN, CONF_NAME
from esphome.cpp_generator import add, get_variable


espilightsensor_ns = cg.esphome_ns.namespace("espilightsensor")
EspilightSensor = espilightsensor_ns.class_("EspilightSensor", text_sensor.TextSensor, cg.PollingComponent)

CONFIG_SCHEMA = text_sensor.text_sensor_schema(EspilightSensor).extend({
    cv.GenerateID(): cv.declare_id(EspilightSensor),
    cv.Required(CONF_PIN): int,
    cv.Required(CONF_NAME): cv.string,
}).extend(cv.COMPONENT_SCHEMA)
# }).extend(cv.polling_component_schema("60s"))

async def to_code(config):
    var = await text_sensor.new_text_sensor(config)
    # await cg.register_component(var, config)
    await text_sensor.register_text_sensor(var, config)
    cg.add(var.set_pin(config[CONF_PIN]))
    # cg.add(var.set_protocol_name(config[CONF_PROTOCOL_NAME]))
    # cg.add(var.set_protocol_data_on(config[CONF_PROTOCOL_DATA_ON]))
    # cg.add(var.set_protocol_data_off(config[CONF_PROTOCOL_DATA_OFF]))
    cg.add_library("puuu/ESPiLight", None)

