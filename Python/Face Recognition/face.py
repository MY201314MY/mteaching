import cv2

face_cascade = cv2.CascadeClassifier("haar\\haarcascade_frontalface_default.xml")
eye_cascade = cv2.CascadeClassifier("haar\\haarcascade_eye.xml")
smile_cascade = cv2.CascadeClassifier("Shaar\\haarcascade_smile.xml")

cap = cv2.VideoCapture(0)

while (cap.isOpened()):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    for (x, y, w, h) in faces:
        img = cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
        roi_gray = gray[y:y + h, x:x + w]
        eyes = eye_cascade.detectMultiScale(img, 1.03, 5, 0, (40, 40))
        smile = eye_cascade.detectMultiScale(img, 1.03, 5, 0, (60, 60))

        for (sx, sy, sw, sh) in smile:
            cv2.rectangle(frame, (sx, sy), (sx + sw, sy + sh), (0, 0, 255), 2)
        for (ex, ey, ew, eh) in eyes:
            cv2.rectangle(frame, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 2)

    cv2.imshow('face', frame)

    if cv2.waitKey(1) & 0xff == ord(" "):
        break

cap.release()
cv2.destroyAllWindows()

