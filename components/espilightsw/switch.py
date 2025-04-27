import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
# from esphome import pins
from esphome.const import CONF_ID, CONF_PIN, CONF_NAME, CONF_DISABLED_BY_DEFAULT, CONF_RESTORE_MODE
from esphome.cpp_generator import add, get_variable



# DEPENDENCIES = ["ESPiLight"]
# MULTI_CONF = True
# Das sind die zu verwendenden Bezeichner in der Config.yaml
CONF_PROTOCOL_NAME = "protocol"
CONF_PROTOCOL_DATA = "data"

espilightsw_ns = cg.esphome_ns.namespace("espilightsw")
EspilightSwitch = espilightsw_ns.class_("EspilightSwitch", switch.Switch, cg.Component)

CONFIG_SCHEMA = switch.switch_schema(EspilightSwitch).extend({
    cv.GenerateID(): cv.declare_id(EspilightSwitch),
    cv.Required(CONF_PIN): int,
    cv.Required(CONF_NAME): cv.string,
    cv.Required(CONF_PROTOCOL_NAME): cv.string,
    cv.Required(CONF_PROTOCOL_DATA): cv.string,
}).extend(cv.COMPONENT_SCHEMA)

# CONFIG_SCHEMA = cv.Schema(
#     {
# cv.Required(CONF_PIN): pins.internal_gpio_output_pin_schema,
#         cv.GenerateID(): cv.declare_id(EspilightComponent),
# cv.Optional(CONF_DISABLED_BY_DEFAULT, default=False): cv.boolean,
# cv.Optional(CONF_RESTORE_MODE, default="RESTORE_DEFAULT_OFF"): cv.enum(
#     RESTORE_MODES, upper=True, space="_"        ),
#         # cv.Required(CONF_PIN): pins.internal_gpio_output_pin_schema,
#         cv.Required(CONF_PIN): int,
#         cv.Required(CONF_NAME): cv.string,
#         cv.Required(CONF_PROTOCOL_NAME): cv.string,
#         cv.Required(CONF_PROTOCOL_DATA): cv.string,
#         cv.Optional(CONF_DISABLED_BY_DEFAULT, default=False): cv.boolean,
#         cv.Optional(CONF_RESTORE_MODE, default="RESTORE_DEFAULT_OFF"): cv.enum(
#             RESTORE_MODES, upper=True, space="_"
#         ),
#
#     }
# ).extend(cv.COMPONENT_SCHEMA)

# async def setup_entity(var, config):
#     if CONF_DISABLED_BY_DEFAULT in config:
#         add(var.set_disabled_by_default(config[CONF_DISABLED_BY_DEFAULT]))
#     else:
#         add(var.set_disabled_by_default(False))  # Standardwert auf False setzen

async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)
    cg.add(var.set_pin(config[CONF_PIN]))


    # var = cg.new_Pvariable(config[CONF_ID])
    # pin = await cg.gpio_pin_expression(config[CONF_PIN])
    # cg.add(var.set_pin(pin))
    #cg.add(var.set_protocol_name(config[CONF_PROTOCOL_NAME]))
    #cg.add(var.set_protocol_data(config[CONF_PROTOCOL_DATA]))
    # FUNKTIONIERT
    cg.add_library("http://192.168.0.25:3000/gitea/espilight.git", None)



# Falscher Aufbau core/json fehlt
#    cg.add_library("https://github.com/puuu/ESPiLight.git", None)
# no with git    cg.add_library("http://192.168.0.25:3000/gitea/espilight.git", None)
#    cg.add_library("http://192.168.0.25:3000/gitea/espilight.git", None)
# Repo gelöscht    cg.add_library("http://192.168.0.25:3000/gitea/espilight.git", None)
#no    cg.add_library("http://192.168.0.25:3000/gitea/espilightcleantest.git", None)
# Das geht mit LOCAL. Verzeichnisstruktur: espilightsw\espilightsw
#    cg.add_library("https://github.com/Micha10/ESPiLight.git", None)
# local: .piolibdeps/espilight/ESPiLight/src/pilight/libs/pilight/protocols/protocol.h:26:10: fatal error: ../core/json.h: No such file or directory
# geht nicht    cg.add_library("ESPiLight.cpp", None)

# paren = await cg.get_variable(config[CONF_ID])
# var = cg.new_Pvariable(config[CONF_ID], paren)
# await cg.register_component(var, config)
# pin = await cg.gpio_pin_expression(config[CONF_PIN])
# cg.add(var.set_pin(pin))
# cg.add(var.set_protocol_name(config[CONF_PROTOCOL_NAME]))
# cg.add(var.set_protocol_data(config[CONF_PROTOCOL_DATA]))

# cg.add(paren.register_sensor(var))
# cg.add_library("puuu/espilight", "0.17.0")
# switch_ns = cg.esphome_ns.namespace("switch_")
# espilight_ns = cg.esphome_ns.namespace("espilightsw")
# espilightsw = espilight_ns.class_(
#     "espilightsw", switch.Switch, cg.Component)

# SwitchRestoreMode = switch_ns.enum("SwitchRestoreMode")

# RESTORE_MODES = {
#     "RESTORE_DEFAULT_OFF": SwitchRestoreMode.SWITCH_RESTORE_DEFAULT_OFF,
#     "RESTORE_DEFAULT_ON": SwitchRestoreMode.SWITCH_RESTORE_DEFAULT_ON,
#     "ALWAYS_OFF": SwitchRestoreMode.SWITCH_ALWAYS_OFF,
#     "ALWAYS_ON": SwitchRestoreMode.SWITCH_ALWAYS_ON,
#     "RESTORE_INVERTED_DEFAULT_OFF": SwitchRestoreMode.SWITCH_RESTORE_INVERTED_DEFAULT_OFF,
#     "RESTORE_INVERTED_DEFAULT_ON": SwitchRestoreMode.SWITCH_RESTORE_INVERTED_DEFAULT_ON,
#     "DISABLED": SwitchRestoreMode.SWITCH_RESTORE_DISABLED,
# }