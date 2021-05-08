wpa_passphrase SSID PASSWORD >> /etc/wpa_supplicant.conf
wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf
sleep 2
iw wlan0 link 
udhcpc -i wlan0
ping www.baidu.com -c 4

wpa_passphrase myss myss002714 >> /etc/wpa_supplicant.conf