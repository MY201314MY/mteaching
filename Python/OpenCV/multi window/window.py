import cv2
import time

argument = {"fps":0, "backup_time":0, "message":"loading. . ."}
if __name__ == '__main__':
    camera = cv2.VideoCapture(0, cv2.CAP_DSHOW)
    print("OpenCV:{0}".format(cv2.getVersionString()))
    camera.set(propId=3, value=800)
    camera.set(propId=4, value=480)
    print(camera.get(propId=3), camera.get(propId=4))

    while True:
        moment = time.gmtime().tm_sec
        if moment != argument["backup_time"]:
            argument["backup_time"] = moment
            argument["message"] = "\rfps:{0}".format(argument["fps"])
            print(argument["message"], end="")
            argument["fps"] = 0

        argument["fps"] += 1
        ret, frame = camera.read()
        frame = frame[0:480, 0:800]
        frame[0:480, 800:848] = [23, 56, 255]
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        result = frame
        result[0:240, 0:400] = cv2.resize(frame, (400, 240))
        result[0:240, 400:800] = cv2.resize(hsv, (400, 240))
        cv2.imshow(winname="frame width:800 height:480", mat=result)

        if cv2.waitKey(delay=10) & 0xFF == ord('q'):
            break

    camera.release()
    cv2.destroyAllWindows()