import cv2

original_image = cv2.imread("dgu_night_color.png")
changed_image = cv2.cvtColor(original_image,cv2.COLOR_BGR2YCrCb) #���� �̹����� BGR ä���� Color Space�� YCrCb�� �ٲ��ش�

changed_image[:,:,0] = cv2.equalizeHist(changed_image[:,:,0]) #0��ä�� �� Y�� ���ؼ� histogram equalization�� �����Ѵ�

changed_image = cv2.cvtColor(changed_image,cv2.COLOR_YCrCb2BGR) #YCrCbä���� �̹����� �ٽ� RGB�� �ٲ��ش�

cv2.imshow("original_img",original_image)
cv2.imshow("changed_img",changed_image)
cv2.waitKey()