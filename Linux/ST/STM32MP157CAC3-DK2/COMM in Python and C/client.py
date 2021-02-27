import socket

if __name__ == "__main__":
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 18880))
    while True:
        message = input("msh>")
        client.send(message.encode())
        recv = client.recv(1024)
        if recv:
            print("meassage:{0}".format(recv.decode()))
        if message == "quit":
            break
    
    client.close
    