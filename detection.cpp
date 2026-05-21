#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("input.jpg");
    if (image.empty()) {
        cout << "Could not load image." << endl;
        return -1;
    }
    Mat brightened;

    // Brightness adjustment
    image.convertTo(brightened, -1, 1.5, 40);
    imshow("Original", image);
    imshow("Brightened", brightened);
    imwrite("output.jpg", brightened);

    waitKey(0);

    return 0;
}
