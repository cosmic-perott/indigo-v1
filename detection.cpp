#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    // Load image
    Mat image = imread("input.jpg");

    // Check if image loaded
    if (image.empty()) {
        cout << "Could not load image." << endl;
        return -1;
    }

    // Create brighter image
    Mat brightened;

    // Brightness adjustment
    image.convertTo(brightened, -1, 1.5, 40);

    // Show original
    imshow("Original", image);

    // Show enhanced
    imshow("Brightened", brightened);

    // Save output
    imwrite("output.jpg", brightened);

    waitKey(0);

    return 0;
}
