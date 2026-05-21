#include <opencv/cv.h>
#include <opencv/highgui.h>

int main() {
    CvCapture* capture;
    IplImage* frame;

    capture = cvCreateFileCapture("videos/night_drive.mp4");

    if (!capture) {
        printf("Failed to open video.\n");
        return -1;
    }

    cvNamedWindow("NightDrive AI", CV_WINDOW_AUTOSIZE);

    while (1) {
        frame = cvQueryFrame(capture);

        if (!frame)
            break;


        enhance_frame(frame);


        reduce_glare(frame);


        detect_lanes(frame);


        detect_objects(frame);


        process_warnings(frame);

        cvShowImage("NightDrive AI", frame);

        if (cvWaitKey(10) == 27)
            break;
    }

    cvReleaseCapture(&capture);
    cvDestroyAllWindows();

    return 0;
}

void gamma_correction(IplImage* img, float gamma) {
    unsigned char lut[256];

    for (int i = 0; i < 256; i++) {
        lut[i] = pow(i / 255.0, gamma) * 255.0;
    }

    for (int y = 0; y < img->height; y++) {
        unsigned char* row =
            (unsigned char*)(img->imageData + y * img->widthStep);

        for (int x = 0; x < img->width * img->nChannels; x++) {
            row[x] = lut[row[x]];
        }
    }
}
