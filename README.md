# QueenCitySecurityBadUSB
BadUSB supplemental/getting started instructions for the ATTiny85. Thanks to everyone that came!

These steps should work for Linux, MacOS, and Windows.

# Getting started with VSCode as your IDE

1. First, make sure VSCode is installed
2. Then, go to extensions (ctrl+shift+x)
3. Install the "PlatformIO" extension to interact with the ATTiny85
4. Open the command pallette (ctrl+shift+p) and type/click PlatformIO:Home
5. Create a new project and name it whatever you want, select "Digispark USB (Digistump)"
6. Once you see your project files, go to the src folder (close to the bottom)
7. Open up main.cpp
8. Get coding*
9. Once you're done, click the PlatformIO icon (little alien guy) and find "Upload". First it will download a dependency (when you're using it for the first time), and then ask you to plug the ATTiny85 in.
10. It'll take a second to upload all the code, but once it's done, you can unplug the USB, and after plug it back in. It'll take a couple seconds to initialize, this is normal. It's a 3 dollar microcontroller, not a quantum computer :p

# *Getting coding:

To ensure the BadUSB works, you can run "example.cpp". But believe it or not, some of you want to write your own code for it! So let's go over a few basics:

# Basic setup:

To import the library that the ATTiny85 uses for HIDi (Human Interface Device injection), we need to add this at the top of the file: 

#include "DigiKeyboard.h"

Once we've got that, it's highly recommended to add a delay in the setup() function to make sure the BadUSB is fully initialized before "typing" away like so:

DigiKeyboard.delay(1000) //delay for 1000 milliseconds or 1 second


But now let's get to the fun stuff!

# Simulating keypresses:

Let's say we want to 
