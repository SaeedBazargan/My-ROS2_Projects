## 1. System Architecture
The system consists of a simulated four-wheel mobile robot equipped with a camera. The camera captures images of the ground, and OpenCV processes these images to detect the line. The estimated line position is converted into a tracking error, which is used by the controller to generate wheel velocity commands. The robot's motion changes the camera's view, closing the feedback loop.

## 2. Camera Model and Image Processing
The camera provides RGB images at a specified resolution and frame rate. The image is converted to grayscale or HSV color space, and thresholding is applied to separate the line from the background. A region of interest near the bottom of the image can reduce processing cost. The line position is estimated using the centroid of the detected pixels.
