# Anadus
This is a very simple PortAudio text to speech engine written in C++.

# Getting Started

### Setup
Sudana depends on PortAudio and by default is compiled using clang. In Ubuntu you can install these with `sudo apt-get install libportaudio-dev clang-3.5`.

### Compiling
Simply run `make` and it will compile everything. 

### Running
The executable should be created in a subdirectory in the `dist` folder. To run it type `./dist/` followed by the full path of the binary. For me the command would be `dist/Debug/CLang-Linux/anadus`. It is important to run the executable from the root project directory since that is where the raw audio files resides.

# Development
This project uses Netbeans IDE although any editor of your choice will work. At the moment the engine an only produce a few phonemes in an incredibly buggy sounding way however work is planned to improve this in the future.

# Contact
Contact me either at `matthew3311999@gmail.com` or by filing an issue on GitHub.

