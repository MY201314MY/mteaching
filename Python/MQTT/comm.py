import time
import threading
from  queue import Queue
import paho.mqtt.client as mqtt

import time
import threading
from queue import Queue
import paho.mqtt.client as mqtt

client = ""
R = Queue(maxsize=8)
T = Queue(maxsize=8)

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connect the server successfully.")
    client.subscribe("Chrome")

def on_message(client, userdata, msg):
    message = msg.payload.decode()
    if msg.topic == 'Chrome':
        print("\nMessage: {0}".format(message))
        if message == "1":
            print("接收到打开报警命令！")
        elif message == "0":
            print("接收到关闭报警命令！")
        else:
            print("Command error!")

def mosquitto():
    global client
    client = mqtt.Client(client_id='ubuntu', clean_session=True, userdata=None, protocol=mqtt.MQTTv311, transport="tcp")
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect('120.26.185.144', 1883, 60)
    R.put("Ready")
    loop = True

    while loop:
        client.loop(timeout=0.200)
        for i in range(T.qsize()):
            send = T.get()
            if send == "QUIT,maria":
                loop = False
                client.disconnect()
                print("Thread MQTT killed.")
            client.publish(topic="MC20E", payload=send)


def content():
    while True:
        if R.empty():
            time.sleep(0.500)
        else:
            flag = R.get()
            if flag == "Ready":
                break

    while True:
        message = input("请输入健康数据（心率、血氧浓度、温度）:")
        message=message+",maria"
        T.put(message)
        if message == "QUIT,maria":
            print("Thread Input killed.")
            break


if __name__ == '__main__':
    MQTT = threading.Thread(target=mosquitto)
    Input = threading.Thread(target=content)

    MQTT.start()
    Input.start()

    MQTT.join()
    Input.join()

    print("End . . .")