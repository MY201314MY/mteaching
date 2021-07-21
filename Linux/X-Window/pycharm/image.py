import cv2
import struct
import time
import numpy as np

if __name__ == '__main__':
    print("version: {0}".format(cv2.getVersionString()))

    temp = cv2.imread(filename="WeChat.jpg")
    temp = cv2.resize(src=temp, dsize=(390, 209))

    pixel = np.array([1, 2, 3], dtype=np.uint8)

    start = time.time()
    with open(file="image.bin", mode="rb") as f:
        for i in range(209):
            for j in range(390):
                for k in range(4):
                    data = f.read(1)
                    num = struct.unpack('B', data)

                    if k == 3:
                        temp[i][j] = pixel
                        continue

                    pixel[k] = num[0]
    end = time.time()
    print("assignment cost: %.3f s" % (end - start))

    while True:
        cv2.imshow("preview", temp)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cv2.destroyAllWindows()