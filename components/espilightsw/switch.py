import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
# from esphome import pins
from esphome.const import CONF_ID, CONF_PIN, CONF_NAME, CONF_DISABLED_BY_DEFAULT, CONF_RESTORE_MODE
from esphome.cpp_generator import add, get_variable

# Das sind die zu verwendenden Bezeichner in der Config.yaml
CONF_PROTOCOL_NAME = "protocol"
CONF_PROTOCOL_DATA_ON = "dataon"
CONF_PROTOCOL_DATA_OFF = "dataoff"

espilightsw_ns = cg.esphome_ns.namespace("espilightsw")
EspilightSwitch = espilightsw_ns.class_("EspilightSwitch", switch.Switch, cg.Component)

CONFIG_SCHEMA = switch.switch_schema(EspilightSwitch).extend({
    cv.GenerateID(): cv.declare_id(EspilightSwitch),
    cv.Required(CONF_PIN): int,
    cv.Required(CONF_NAME): cv.string,
    cv.Required(CONF_PROTOCOL_NAME): cv.string,
    cv.Required(CONF_PROTOCOL_DATA_ON): cv.string,
    cv.Required(CONF_PROTOCOL_DATA_OFF): cv.string,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)
    cg.add(var.set_pin(config[CONF_PIN]))
    cg.add(var.set_protocol_name(config[CONF_PROTOCOL_NAME]))
    cg.add(var.set_protocol_data_on(config[CONF_PROTOCOL_DATA_ON]))
    cg.add(var.set_protocol_data_off(config[CONF_PROTOCOL_DATA_OFF]))
    cg.add_library("puuu/ESPiLight", None)

