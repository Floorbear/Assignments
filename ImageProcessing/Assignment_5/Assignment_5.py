import cv2

original_image = cv2.imread("dgu_night_color.png")
changed_image = cv2.cvtColor(original_image,cv2.COLOR_BGR2YCrCb) #기존 이미지의 BGR 채널의 Color Space를 YCrCb로 바꿔준다

changed_image[:,:,0] = cv2.equalizeHist(changed_image[:,:,0]) #0번채널 즉 Y에 대해서 histogram equalization을 진행한다

changed_image = cv2.cvtColor(changed_image,cv2.COLOR_YCrCb2BGR) #YCrCb채널의 이미지를 다시 RGB로 바꿔준다

cv2.imshow("original_img",original_image)
cv2.imshow("changed_img",changed_image)
cv2.waitKey()