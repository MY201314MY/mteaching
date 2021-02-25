import cv2
import sys
import time
import numpy as np

string=''
i=0
j=0
value=0
consider=0
buff = []
logo=np.empty((8,128),np.uint8)
path = "x.PNG"
img = cv2.imread(path)
print(img.shape)
img = cv2.resize (img,(128,64))
print(img.shape)
print("Execute successfully.")
hsv_img = cv2.cvtColor (img,cv2.COLOR_BGR2HSV)
#color_lower = np.int32 ([0,0,48])
#color_upper= np.int32 ([255,255,255])
color_lower = np.int32 ([5,25,25])
color_upper= np.int32 ([255,255,255])
image = cv2.inRange (hsv_img,color_lower,color_upper)
print(image.shape)
for i in range(0,8):
    for j in range(0,128):
        for k in range(0,8):
            if(image[i*8+k][j]==0):
                color=0
            else:
                color=1
            value=value+(2**k)*color
        k=0
        logo[i][j]=value
        value=0
    j=0

i=0
j=0
for i in range(0,8):
        for j in range(0,128):
            if j % 16==0:
                print(hex(logo[i][j])+','+hex(logo[i][j+1])+','+hex(logo[i][j+2])+','+hex(logo[i][j+3])+','
                      +hex(logo[i][j+4])+','+hex(logo[i][j+5])+','+hex(logo[i][j+6])+','+hex(logo[i][j+7])+','
                      +hex(logo[i][j+8])+','+hex(logo[i][j+9])+','+hex(logo[i][j+10])+','+hex(logo[i][j+11])+','
                      +hex(logo[i][j+12])+','+hex(logo[i][j+13])+','+hex(logo[i][j+14])+','+hex(logo[i][j+15])+','
                      )
i=0
j=0
for i in range(0,8):
    for j in range(0,128):
        buff.append(logo[i][j])
i=0
for i in range(0,1024):
    string=string+str(buff[i])+','
string=string[:128]

print("data send successfully.")
               
cv2.imshow("img",image)
if cv2.waitKey (0)== ord('q'):
    cv2.destroyAllWindows ()
