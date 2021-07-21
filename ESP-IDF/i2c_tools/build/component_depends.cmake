# Component requirements generated by expand_requirements.cmake

set(BUILD_COMPONENTS soc;log;heap;xtensa-debug-module;app_trace;freertos;vfs;newlib;esp_ringbuf;driver;esp_event;ethernet;mbedtls;micro-ecc;efuse;bootloader_support;partition_table;app_update;spi_flash;nvs_flash;lwip;tcpip_adapter;pthread;smartconfig_ack;wpa_supplicant;espcoredump;esp32;cxx;console;cmd_nvs;cmd_system;json;unity;protobuf-c;nghttp;esp_http_server;nimble;bt;protocomm;esp-tls;tcp_transport;esp_http_client;esp_https_ota;ulp;coap;spiffs;jsmn;esptool_py;sdmmc;wear_levelling;fatfs;esp_websocket_client;mqtt;openssl;esp_https_server;expat;bootloader;libsodium;freemodbus;esp_adc_cal;idf_test;asio;mdns;wifi_provisioning;aws_iot;main)
set(BUILD_COMPONENT_PATHS /home/pi/espressif/esp-idf/components/soc;/home/pi/espressif/esp-idf/components/log;/home/pi/espressif/esp-idf/components/heap;/home/pi/espressif/esp-idf/components/xtensa-debug-module;/home/pi/espressif/esp-idf/components/app_trace;/home/pi/espressif/esp-idf/components/freertos;/home/pi/espressif/esp-idf/components/vfs;/home/pi/espressif/esp-idf/components/newlib;/home/pi/espressif/esp-idf/components/esp_ringbuf;/home/pi/espressif/esp-idf/components/driver;/home/pi/espressif/esp-idf/components/esp_event;/home/pi/espressif/esp-idf/components/ethernet;/home/pi/espressif/esp-idf/components/mbedtls;/home/pi/espressif/esp-idf/components/micro-ecc;/home/pi/espressif/esp-idf/components/efuse;/home/pi/espressif/esp-idf/components/bootloader_support;/home/pi/espressif/esp-idf/components/partition_table;/home/pi/espressif/esp-idf/components/app_update;/home/pi/espressif/esp-idf/components/spi_flash;/home/pi/espressif/esp-idf/components/nvs_flash;/home/pi/espressif/esp-idf/components/lwip;/home/pi/espressif/esp-idf/components/tcpip_adapter;/home/pi/espressif/esp-idf/components/pthread;/home/pi/espressif/esp-idf/components/smartconfig_ack;/home/pi/espressif/esp-idf/components/wpa_supplicant;/home/pi/espressif/esp-idf/components/espcoredump;/home/pi/espressif/esp-idf/components/esp32;/home/pi/espressif/esp-idf/components/cxx;/home/pi/espressif/esp-idf/components/console;/home/pi/espressif/esp-idf/examples/system/console/components/cmd_nvs;/home/pi/espressif/esp-idf/examples/system/console/components/cmd_system;/home/pi/espressif/esp-idf/components/json;/home/pi/espressif/esp-idf/components/unity;/home/pi/espressif/esp-idf/components/protobuf-c;/home/pi/espressif/esp-idf/components/nghttp;/home/pi/espressif/esp-idf/components/esp_http_server;/home/pi/espressif/esp-idf/components/nimble;/home/pi/espressif/esp-idf/components/bt;/home/pi/espressif/esp-idf/components/protocomm;/home/pi/espressif/esp-idf/components/esp-tls;/home/pi/espressif/esp-idf/components/tcp_transport;/home/pi/espressif/esp-idf/components/esp_http_client;/home/pi/espressif/esp-idf/components/esp_https_ota;/home/pi/espressif/esp-idf/components/ulp;/home/pi/espressif/esp-idf/components/coap;/home/pi/espressif/esp-idf/components/spiffs;/home/pi/espressif/esp-idf/components/jsmn;/home/pi/espressif/esp-idf/components/esptool_py;/home/pi/espressif/esp-idf/components/sdmmc;/home/pi/espressif/esp-idf/components/wear_levelling;/home/pi/espressif/esp-idf/components/fatfs;/home/pi/espressif/esp-idf/components/esp_websocket_client;/home/pi/espressif/esp-idf/components/mqtt;/home/pi/espressif/esp-idf/components/openssl;/home/pi/espressif/esp-idf/components/esp_https_server;/home/pi/espressif/esp-idf/components/expat;/home/pi/espressif/esp-idf/components/bootloader;/home/pi/espressif/esp-idf/components/libsodium;/home/pi/espressif/esp-idf/components/freemodbus;/home/pi/espressif/esp-idf/components/esp_adc_cal;/home/pi/espressif/esp-idf/components/idf_test;/home/pi/espressif/esp-idf/components/asio;/home/pi/espressif/esp-idf/components/mdns;/home/pi/espressif/esp-idf/components/wifi_provisioning;/home/pi/espressif/esp-idf/components/aws_iot;/home/pi/espressif/final/i2c_tools/main)
set(BUILD_TEST_COMPONENTS )
set(BUILD_TEST_COMPONENT_PATHS )

# get_component_requirements: Generated function to read the dependencies of a given component.
#
# Parameters:
# - component: Name of component
# - var_requires: output variable name. Set to recursively expanded COMPONENT_REQUIRES 
#   for this component.
# - var_private_requires: output variable name. Set to recursively expanded COMPONENT_PRIV_REQUIRES 
#   for this component.
#
# Throws a fatal error if 'componeont' is not found (indicates a build system problem).
#
function(get_component_requirements component var_requires var_private_requires)
  if("${component}" STREQUAL "soc")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "log")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "heap")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "xtensa-debug-module")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "app_trace")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "xtensa-debug-module" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "freertos")
    set(${var_requires} "app_trace" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "vfs")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "newlib")
    set(${var_requires} "vfs" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_ringbuf")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "driver")
    set(${var_requires} "esp_ringbuf" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_event")
    set(${var_requires} "log" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "ethernet")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "tcpip_adapter;esp_event" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "mbedtls")
    set(${var_requires} "lwip" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "micro-ecc")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "efuse")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "bootloader_support" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "bootloader_support")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "spi_flash;mbedtls;micro-ecc;efuse" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "partition_table")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "app_update")
    set(${var_requires} "spi_flash;partition_table;bootloader_support" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "spi_flash")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "bootloader_support;app_update" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "nvs_flash")
    set(${var_requires} "spi_flash;mbedtls" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "lwip")
    set(${var_requires} "vfs" PARENT_SCOPE)
    set(${var_private_requires} "ethernet;tcpip_adapter;nvs_flash" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "tcpip_adapter")
    set(${var_requires} "lwip" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "pthread")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "smartconfig_ack")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "lwip;tcpip_adapter" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "wpa_supplicant")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "mbedtls" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "espcoredump")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "spi_flash" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp32")
    set(${var_requires} "driver;tcpip_adapter;esp_event;efuse" PARENT_SCOPE)
    set(${var_private_requires} "app_trace;app_update;bootloader_support;ethernet;log;mbedtls;nvs_flash;pthread;smartconfig_ack;spi_flash;vfs;wpa_supplicant;xtensa-debug-module;espcoredump" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "cxx")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "console")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "cmd_nvs")
    set(${var_requires} "console;nvs_flash" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "cmd_system")
    set(${var_requires} "console;spi_flash" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "json")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "unity")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "protobuf-c")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "nghttp")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_http_server")
    set(${var_requires} "nghttp" PARENT_SCOPE)
    set(${var_private_requires} "lwip" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "nimble")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "bt;nvs_flash" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "bt")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "nvs_flash;nimble" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "protocomm")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "protobuf-c;mbedtls;console;esp_http_server;bt" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp-tls")
    set(${var_requires} "mbedtls" PARENT_SCOPE)
    set(${var_private_requires} "lwip;nghttp" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "tcp_transport")
    set(${var_requires} "lwip;esp-tls" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_http_client")
    set(${var_requires} "nghttp" PARENT_SCOPE)
    set(${var_private_requires} "mbedtls;lwip;esp-tls;tcp_transport" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_https_ota")
    set(${var_requires} "esp_http_client;bootloader_support" PARENT_SCOPE)
    set(${var_private_requires} "log;app_update" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "ulp")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "coap")
    set(${var_requires} "lwip" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "spiffs")
    set(${var_requires} "spi_flash" PARENT_SCOPE)
    set(${var_private_requires} "bootloader_support" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "jsmn")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esptool_py")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "sdmmc")
    set(${var_requires} "driver" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "wear_levelling")
    set(${var_requires} "spi_flash" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "fatfs")
    set(${var_requires} "wear_levelling;sdmmc" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_websocket_client")
    set(${var_requires} "lwip;esp-tls;tcp_transport;nghttp" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "mqtt")
    set(${var_requires} "lwip;nghttp;mbedtls;tcp_transport" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "openssl")
    set(${var_requires} "mbedtls" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_https_server")
    set(${var_requires} "esp_http_server;openssl" PARENT_SCOPE)
    set(${var_private_requires} "lwip" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "expat")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "bootloader")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "libsodium")
    set(${var_requires} "mbedtls" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "freemodbus")
    set(${var_requires} "driver" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp_adc_cal")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "idf_test")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "asio")
    set(${var_requires} "lwip" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "mdns")
    set(${var_requires} "lwip;mbedtls;console;tcpip_adapter" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "wifi_provisioning")
    set(${var_requires} "lwip;protocomm" PARENT_SCOPE)
    set(${var_private_requires} "protobuf-c;bt;mdns;json" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "aws_iot")
    set(${var_requires} "mbedtls" PARENT_SCOPE)
    set(${var_private_requires} "jsmn" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "main")
    set(${var_requires} "cmd_nvs;cmd_system;json;unity;tcpip_adapter;protocomm;nimble;esp_https_ota;ulp;coap;lwip;nvs_flash;bootloader_support;spiffs;jsmn;esptool_py;app_update;log;sdmmc;fatfs;spi_flash;esp_event;wear_levelling;esp_websocket_client;smartconfig_ack;esp-tls;soc;mqtt;esp_https_server;newlib;console;bt;heap;expat;nghttp;ethernet;micro-ecc;efuse;bootloader;libsodium;openssl;protobuf-c;vfs;freemodbus;esp_adc_cal;idf_test;cxx;asio;esp32;esp_ringbuf;wpa_supplicant;freertos;app_trace;espcoredump;tcp_transport;partition_table;driver;esp_http_server;mbedtls;wifi_provisioning;xtensa-debug-module;aws_iot;pthread;mdns;esp_http_client" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  message(FATAL_ERROR "Component not found: ${component}")
endfunction()
