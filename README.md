# 🧵 Task 1: Even-Odd Number Printing using Multithreading

## ✅ Status: Completed and Working

### 📌 Objective:
Print numbers from 0 to 10 alternately using two threads:
- One prints even numbers
- Another prints odd numbers

### ⚙️ Tools & Concepts:
- `std::thread` – to create threads
- `std::mutex` and `std::condition_variable` – for synchronization

### 🧠 Logic:
- A shared counter variable (`int counter`)
- Threads wait for their turn using `condition_variable`
- Alternates between even and odd prints

### ✅ Sample Output:
Even: 0
Odd: 1
Even: 2
Odd: 3
...
Even: 10
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🔐 Task 2: File Encrypt and Decrypt Storage System

## ✅ Status: Completed and Working

### 📌 Objective:
- Accept user input for Country, State, District, and Description
- Save content in a nested folder structure
- Encrypt the content using XOR
- Allow retrieval and decryption

### 📂 Folder Structure Example:
./data/India/TamilNadu/Chennai/info.txt

### 🔐 XOR Encryption Logic:
Each character is XORed with a fixed key (e.g., `'K'`)  
It’s reversible:
- `'A' ^ 'K' → encrypted`
- `encrypted ^ 'K' → 'A'` (original)

### 💡 Features:
- Menu: Store new file or retrieve existing one
- File I/O with error handling
- Encryption/Decryption handled in the same function

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🎥 Task 3: Video Capture App with Snapshot Feature (OpenCV + Threads)

## ✅ Status: Code Logic Completed  
 Binary not built with `g++` due to linking errors (explained below)

### 📌 Objective:
Create a real-time video recording app with:
- Live webcam feed
- Background thread for saving video
- Snapshot support

### ⚙️ Used:
- OpenCV: `VideoCapture`, `VideoWriter`, `imshow()`, `imwrite()`
- C++ thread: `std::thread`
- `std::atomic`: to safely stop background thread

### 🧪 User Options:
- Press `s`: Take snapshot
- Press `q`: Quit

### 💡 Why Multithreading?
To ensure smooth video capture and UI responsiveness while saving frames in the background.

### ⚠️ Issue Faced:
I encountered undefined reference errors when trying to compile this task using g++ and OpenCV due to linking issues:
- Tried static linking with `-lopencv_world490` and correct include/lib paths
- Still failed due to unresolved symbols from OpenCV

### ✔️ Temporary Resolution:
- Code logic works perfectly in Visual Studio (MSVC) with OpenCV
- So I uploaded only `main.cpp` for review

### 🔧 Next Steps:
Will retry with updated OpenCV CMake builds and MinGW setup for working `g++` compilation.


### Author: Meena Chandrasekar  
💼 Submission for: C++ Developer - Technical Assignment (HTIC)  
📅 Date: 25 June 2025  
📧 Email: meena27072001@gmail.com

✅ Thank you for reviewing my submission!
