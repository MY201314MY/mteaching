import cv2

print("OpenCV Version{0}".format(cv2.__version__))

image = cv2.imread("apple.jpg")
image = cv2.resize (image,(192*5,108*5))
print(image.shape[1])
x_middle = int(image.shape[0]/2)
y_middle = int(image.shape[1]/2)
print(x_middle, y_middle)
img = image[(x_middle-136):(x_middle+136), (y_middle-240):(y_middle+240)]

print(img.shape)
print(len(img[0]))

for i in range(2):
    for j in range(480):
        color = img[i][j][2]*256*256 + img[i][j][1]*256 + img[i][j][0]
        print(hex(color), end=',')
    print("")


cv2.imshow("img",img)
if cv2.waitKey(0)== ord('q'):
    cv2.destroyAllWindows()