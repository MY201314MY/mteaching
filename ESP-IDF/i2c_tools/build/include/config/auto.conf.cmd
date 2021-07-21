deps_config := \
	/home/pi/espressif/esp-idf/components/app_trace/Kconfig \
	/home/pi/espressif/esp-idf/components/aws_iot/Kconfig \
	/home/pi/espressif/esp-idf/components/bt/Kconfig \
	/home/pi/espressif/esp-idf/components/driver/Kconfig \
	/home/pi/espressif/esp-idf/components/efuse/Kconfig \
	/home/pi/espressif/esp-idf/components/esp32/Kconfig \
	/home/pi/espressif/esp-idf/components/esp_adc_cal/Kconfig \
	/home/pi/espressif/esp-idf/components/esp_event/Kconfig \
	/home/pi/espressif/esp-idf/components/esp_http_client/Kconfig \
	/home/pi/espressif/esp-idf/components/esp_http_server/Kconfig \
	/home/pi/espressif/esp-idf/components/esp_https_ota/Kconfig \
	/home/pi/espressif/esp-idf/components/espcoredump/Kconfig \
	/home/pi/espressif/esp-idf/components/ethernet/Kconfig \
	/home/pi/espressif/esp-idf/components/fatfs/Kconfig \
	/home/pi/espressif/esp-idf/components/freemodbus/Kconfig \
	/home/pi/espressif/esp-idf/components/freertos/Kconfig \
	/home/pi/espressif/esp-idf/components/heap/Kconfig \
	/home/pi/espressif/esp-idf/components/libsodium/Kconfig \
	/home/pi/espressif/esp-idf/components/log/Kconfig \
	/home/pi/espressif/esp-idf/components/lwip/Kconfig \
	/home/pi/espressif/esp-idf/components/mbedtls/Kconfig \
	/home/pi/espressif/esp-idf/components/mdns/Kconfig \
	/home/pi/espressif/esp-idf/components/mqtt/Kconfig \
	/home/pi/espressif/esp-idf/components/nvs_flash/Kconfig \
	/home/pi/espressif/esp-idf/components/openssl/Kconfig \
	/home/pi/espressif/esp-idf/components/pthread/Kconfig \
	/home/pi/espressif/esp-idf/components/spi_flash/Kconfig \
	/home/pi/espressif/esp-idf/components/spiffs/Kconfig \
	/home/pi/espressif/esp-idf/components/tcpip_adapter/Kconfig \
	/home/pi/espressif/esp-idf/components/unity/Kconfig \
	/home/pi/espressif/esp-idf/components/vfs/Kconfig \
	/home/pi/espressif/esp-idf/components/wear_levelling/Kconfig \
	/home/pi/espressif/esp-idf/components/wifi_provisioning/Kconfig \
	/home/pi/espressif/esp-idf/components/wpa_supplicant/Kconfig \
	/home/pi/espressif/esp-idf/components/app_update/Kconfig.projbuild \
	/home/pi/espressif/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/pi/espressif/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/pi/espressif/final/i2c_tools/main/Kconfig.projbuild \
	/home/pi/espressif/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/pi/espressif/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
