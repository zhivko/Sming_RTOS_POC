# default SMING_HOME. Can be overriden.
SMING_HOME ?= /opt/sming/Sming

# ESP8266 sdk package home directory
ESP_HOME ?= /opt/esp-open-sdk

# default COM port
COM_PORT ?= /dev/ttyUSB0

# base directory of the ESP8266 SDK package, absolute
SDK_BASE  ?= /opt/ESP8266_RTOS_SDK
SDK_TOOLS ?= $(SDK_BASE)/tools

# other tools mappings
ESPTOOL      ?= $(ESP_HOME)/esptool/esptool.py

KILL_TERM    ?= pkill -9 -f "$(COM_PORT) $(COM_SPEED_SERIAL)" || exit 0
GET_FILESIZE ?= stat --printf="%s"
TERMINAL     ?= python -m serial.tools.miniterm $(COM_PORT) $(COM_SPEED_SERIAL)
MEMANALYZER  ?= $(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text
