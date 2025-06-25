/*
 * main.cpp
 *
 *  Created on: 24-Jun-2025
 *      Author: meena
 */




#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace cv;

atomic<bool> running(true);

// Thread function for recording
void record(VideoCapture& cap, VideoWriter& writer) {
    Mat frame;
    while (running) {
        cap >> frame;
        if (frame.empty()) break;
        writer.write(frame);
        this_thread::sleep_for(chrono::milliseconds(10)); // prevent CPU overload
    }
}

int main() {
    VideoCapture cap(0); // open default camera
    if (!cap.isOpened()) {
        cout << "Cannot open webcam!" << endl;
        return -1;
    }

    int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    Size frameSize(width, height);

    VideoWriter writer("recorded_video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, frameSize);

    thread recordThread(record, ref(cap), ref(writer)); // start recording in a thread

    Mat frame;
    cout << "Press 's' to take screenshot, 'q' to quit.\n";
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow("Live Video", frame);

        char key = waitKey(1);
        if (key == 's') {
            // Save current frame
            string filename = "snapshot_" + to_string(time(0)) + ".jpg";
            imwrite(filename, frame);
            cout << "Snapshot saved: " << filename << endl;
        } else if (key == 'q') {
            break;
        }
    }

    running = false; // stop recording
    recordThread.join();
    cap.release();
    writer.release();
    destroyAllWindows();
    return 0;
}
