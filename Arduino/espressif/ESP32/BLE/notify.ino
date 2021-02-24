#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
char message[24]= "";

#define SERVICE_UUID        "4FAFC201-1FB5-459E-8FCC-C5C9C331914B"
#define CHARACTERISTIC_UUID "BEB5483E-36E1-4688-B7F5-EA07361B26A8"


class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("BLE Connected!");
    };

    void onDisconnect(BLEServer* pServer) {
      Serial.println("BLE Disconnected!");
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      int i =0;
      if (value.length() > 0) {
        Serial.println("*********");
        Serial.print("New value: ");
        for (i = 0; i < value.length(); i++){
          Serial.print(value[i]);
          message[i] = value[i];
        }
        message[i]='\0';
        Serial.println("\r\n*********");
        if((String)message == "READ"){
          pCharacteristic->setValue("Tel:17634802048");
          pCharacteristic->notify();
          Serial.println("message has been send successfully.");
        }
        else if((String)message == "PASSWORD"){
          Serial.println("Your HUAWEI mobile want to get the password.");
          pCharacteristic->setValue("abcd123GD");
          pCharacteristic->notify();
          Serial.println("Attention, your password 'abcd123GD' has been sent to iPhone 8.");
        }
        else if((String)message == "level"){
          pCharacteristic->setValue("Liquid Level:12 cm");
          pCharacteristic->notify();
          Serial.println("message has been send successfully.");
        }
        else if((String)message == "valve 1 on"){
          digitalWrite(2, HIGH);
          Serial.println("Turn on the blue LED");
        }
        else if((String)message == "valve 1 off"){
          digitalWrite(2, LOW);
          Serial.println("Turn off the blue LED");
        }
        else{
          ;
        }
      }
    }
};

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);

  // Create the BLE Device
  BLEDevice::init("espressif");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
  pCharacteristic->addDescriptor(new BLE2902());
  pCharacteristic->setCallbacks(new MyCallbacks());
  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}

void loop() {
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
    
}
