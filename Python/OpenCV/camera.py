import cv2
import time
import numpy as np
font = cv2.FONT_HERSHEY_SIMPLEX

print("version:{0}".format(cv2.__version__))
number = 0
black_Lower = np.array([0, 0, 221])
black_Upper = np.array([180, 30, 255])
camera = cv2.VideoCapture(0)
if camera is None:
    print('Please connect the camera firstly.')
    exit()
print("视频采集的宽度为:%s pixel" % camera.get(3))
print("视频采集的高度为:%s pixel" % camera.get(4))
time.sleep(2)

while True:
    (ret, frame) = camera.read()
    if ret != True:
        print('No camera!')
        break
    hsv = cv2.cvtColor(frame[0:480, 100:540], cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, black_Lower, black_Upper)
    RED = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.erode(mask, None, iterations=5)
    mask = cv2.dilate(mask, None, iterations=5)
    count = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]
    for i in range(0, len(count)):
        ((x, y), radius) = cv2.minEnclosingCircle(count[i])
        center = (int(x)+100, int(y))
        if radius > 10:
            number = number+1
            cv2.circle(frame, center, 3, (0, 255, 0), -1)
            cv2.circle(frame, center, int(radius), (0, 0, 255), 3)
            cv2.rectangle(frame, (100, 0), (540, 480), (255, 0, 0), 2)
    string = "No:" + str(number)
    cv2.putText(frame, string, (0, 30), font, 1, (0, 0, 255), 1, cv2.LINE_AA)

    cv2.imshow('region', frame)
    cv2.imshow('mask', mask)

    infor = cv2.waitKey(20) & 0xFF

    if infor == ord('q'):
        break
camera.release()
cv2.destroyAllWindows()