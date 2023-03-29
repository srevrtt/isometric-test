# **Isometric Test**

**Note:** this is not really supposed to be an actual game; rather just a test to see what I can do.

## **About**

A simple isometric 2.5D building system. Not intended for actual gameplay, but this is supposed to act as a template and/or reference for any of my future projects. If you would like to copy any of my code, I would appreciate it if you would give attribution in a single line comment at the top of the code you are using. Please not that for now, there are no prebuilt binaries for this; you need to build it yourself.

## **Controls**

- Left click to place a sand tile
- Right click to destroy a tile

## **Building**

### **Windows**

To build on Windows, you need CMake, Git, and MinGW installed. If you only have MSVC then you will need to download SDL2 and put the files in the correct folders manually.

Once you installed everything, open up a new powershell window and type in the following commands:

- `git clone https://github.com/srevrtt/isometric-test.git`
- `cd isometric-test`
- `./fetch_dependencies.ps1` -- make sure that running Powershell scripts is enabled on your system!
- `cd bin`
- `cmake .. -G "MinGW Makefiles"`
- `mingw32-make`
- `./IsometricTest.exe`

If followed correctly and there are no errors, the game should boot up!

### **Linux**

On Linux, it's a whole lot easier to run. Type in these following commands (assuming you are using a Debian or Ubuntu distro):

- `sudo apt update && sudo apt upgrade -y`
- `sudo apt install git libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev cmake make g++`
- `git clone https://github.com/srevrtt/isometric-test.git`
- `cd isometric-test && mkdir bin && cd bin`
- `cmake ..`
- `make`
- `./IsometricTest`

### **macOS**

If you are building on a Mac, install Homebrew and Xcode. Then, type in the following commands:

- `brew install sdl2 sdl2_image sdl2_ttf git cmake`
- `git clone https://github.com/srevrtt/isometric-test.git`
- `cd isometric-test && mkdir bin && cd bin`
- `cmake ..`
- `make`
- `./IsometricTest`
