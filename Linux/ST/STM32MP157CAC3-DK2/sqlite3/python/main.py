#MQTT communicate and store data in SQLite

import time
import sqlite3
import paho.mqtt.client as mqtt

connection = sqlite3.connect(database="moon.db")
handler = connection.cursor()

def on_connect(client, userdata, flags, rc):
    print('Connected with result code ' + str(rc))
    client.subscribe(topic="T-BOX/EC600S/download")

def on_message(client, userdata, msg):
    global i, j
    message = msg.payload.decode()
    print('[topic]: '+msg.topic + ' ' + '[payload]: ' + message)
    if msg.topic == "T-BOX/EC600S/download":
        command = "INSERT INTO example VALUES (NULL , {0}, \'{1}\')".format(time.time().__int__(), message)
        handler.execute(command)
        connection.commit()

if __name__ == '__main__':
    client = mqtt.Client(client_id='1763480204888888888', clean_session=True, userdata=None, protocol=mqtt.MQTTv311, transport="tcp")
    client.username_pw_set(username="aicp_track", password="aicp_track")
    client.on_connect = on_connect
    client.on_message = on_message
    client._will_topic = "DELL"
    client._will_payload = "Goodbye"

    try:
        client.connect('82.157.101.63', 1883, 60)
        client.loop_forever()
    except KeyboardInterrupt:
        client.disconnect()
        connection.close()