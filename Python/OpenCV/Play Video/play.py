import numpy as np
import cv2
i = 0
cap=cv2.VideoCapture('apple.avi')

while(True):
    ret, frame = cap.read()
    image = cv2.resize(frame, (240, 136))
    cv2.imshow('frame', image)
    i=i+1

    if cv2.waitKey(1)&0xFF ==ord('q'):
    	break

print("There're {0} frp .".format(i))
cap.release()
cv2.destroyAllWindows()
