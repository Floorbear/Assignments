import cv2
import numpy as np


def make_gaussian_nosie(noise_size, image): 
    height, width = image.shape 
    img_noise = np.zeros((height, width), dtype=np.float) 
    for i in range(height): 
        for a in range(width): 
            make_noise = np.random.normal()
            set_noise = noise_size * make_noise 
            img_noise[i][a] = image[i][a] + set_noise 
            
    return img_noise


img_ori = cv2.imread('image.jpg')
img = cv2.cvtColor(img_ori, cv2.COLOR_BGR2GRAY)

height,width = img.shape

img_noise = make_gaussian_nosie(15,img)
img_noise2 = make_gaussian_nosie(15,img)
img_noise3 = make_gaussian_nosie(15,img)
img_noise4 = make_gaussian_nosie(15,img)

out = np.zeros((height,width),dtype=np.float)
out2 = np.zeros((height, width), dtype=np.float)

for i in range(height): 
    for j in range(width): 
        if (img_noise[i][j] + img_noise2[i][j] + img_noise3[i][j] + img_noise4[i][j]) / 4 > 255:
            out[i][j] = 255
        elif 0<((img_noise[i][j] + img_noise2[i][j] + img_noise3[i][j] + img_noise4[i][j]) / 4)<255 :
            out[i][j] = (img_noise[i][j] + img_noise2[i][j] + img_noise3[i][j] + img_noise4[i][j]) / 4
        else:
            out[i][j] = 0



cv2.imshow('df',img_noise.astype(np.uint8))
cv2.imshow('avr2', out.astype(np.uint8))

cv2.waitKey(0)






