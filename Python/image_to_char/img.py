import numpy as np
from PIL import Image

image = Image.open("pig.jpg")
image = image.resize((128, 64), Image.ANTIALIAS)
data = np.array(image.convert('L'))
chars = "MUYUANHENANNANYANG****$$$$&&&&%%%%$$$$####@@@@!!!!    "
n = chars.__len__()
result = ""
for i in range(64):
    for j in range(128):
        result += chars[(int)(data[i][j]*n/256)]
    result += '\n'
print(result)
'''
with open(file="image.txt", mode='w') as file:
    file.write(result)
'''