#include <opencv2/opencv.hpp>
    Mat image = imread("input.jpg");

    if (image.empty()) {
        cout << "ERROR: Could not load image." << endl;
        return -1;
    }

    Mat brightened;

    gammaCorrection(image, brightened, 0.45f);

    Mat lab;
    cvtColor(brightened, lab, COLOR_BGR2Lab);

    vector<Mat> channels;
    split(lab, channels);


    Ptr<CLAHE> clahe = createCLAHE();

    clahe->setClipLimit(4.0);
    clahe->setTilesGridSize(Size(8, 8));

    Mat enhancedL;
    clahe->apply(channels[0], enhancedL);

    channels[0] = enhancedL;

    merge(channels, lab);

    Mat result;
    cvtColor(lab, result, COLOR_Lab2BGR);


    namedWindow("Original", WINDOW_NORMAL);
    namedWindow("Enhanced", WINDOW_NORMAL);

    imshow("Original", image);
    imshow("Enhanced", result);


    imwrite("output.jpg", result);

    cout << "Enhanced image saved as output.jpg" << endl;

    waitKey(0);

    return 0;
}
