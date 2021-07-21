import cv2
import struct
import time
import numpy as np

if __name__ == '__main__':
    print("version: {0}".format(cv2.getVersionString()))

    temp = cv2.imread(filename="WeChat.jpg")
    target = cv2.resize(src=temp, dsize=(390, 209))

    start = time.time()
    with open(file="image.bin", mode="rb") as f:
        buff = f.read(209*390*4)
        for i in range(209):
            for j in range(390):
                target[i][j] = np.array([buff[i*390*4+j*4+0], buff[i*390*4+j*4+1], buff[i*390*4+j*4+2]], dtype=np.uint8)

    end = time.time()
    print("assignment cost: %.3f s" % (end - start))

    while True:
        cv2.imshow("target", target)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cv2.destroyAllWindows()