# QueenCitySecurityBadUSB
BadUSB supplemental/getting started instructions for the ATTiny85. Thanks to everyone that came!

These steps should work for Linux, MacOS, and Windows.

# Getting started with VSCode as your IDE

1. First, make sure VSCode is installed
2. Then, go to extensions (ctrl+shift+x)
3. Install the "PlatformIO" extension to interact with the ATTiny85
4. Open the command pallette (ctrl+shift+p) and type/click PlatformIO:Home
(if this does not work, just click the platformio alien icon and click create new project)
5. Create a new project and name it whatever you want, select "Digispark USB (Digistump)"
6. Once you see your project files, go to the src folder (close to the bottom)
7. Open up main.cpp
8. Get coding*
9. Once you're done, click the PlatformIO icon (little alien guy) and find "Upload". First it will download a dependency (when you're using it for the first time), and then ask you to plug the ATTiny85 in.
10. It'll take a second to upload all the code, but once it's done, you can unplug the USB, and after plug it back in. It'll take a couple seconds to initialize, this is normal. It's a 3 dollar microcontroller, not a quantum computer :p
# Setting up FAQ/Issues
 - If you're using linux, you may need to copy/create this file: /etc/udev/rules.d/49-micronucleus.rules with the following content: https://github.com/micronucleus/micronucleus/blob/master/commandline/49-micronucleus.rules
 - The open source rendition of ```code``` (vscode) doesn't contain the PlatformIO extension due to its closed source dependencies. On Arch Linux this can be resolved with installing microsoft's bin (```yay -S visual-studio-code-bin```), or by downloading it from microsoft on any other distributions

# *Getting coding:

To ensure the BadUSB works, you can run "example.cpp". But believe it or not, some of you want to write your own code for it! So let's go over a few basics:

# Basic setup:

To import the library that the ATTiny85 uses for HIDi (Human Interface Device injection), we need to add this at the top of the file: 

```#include "DigiKeyboard.h"```

Once we've got that, it's highly recommended to add a delay in the setup() function to make sure the BadUSB is fully initialized before "typing" away like so:

```DigiKeyboard.delay(1000) //delay for 1000 milliseconds or 1 second```


But now let's get to the fun stuff!

# Simulating keypresses:

Let's say you want to simulate a keypress to open up a program launcher in Linux/MacOS, using "windows+space" (with the windows key commonly being referred to as GUI).
To do this, you can simply type:
```DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT, KEY_SPACE); //MOD = modifier, GUI = windows/super key, LEFT = the left windows key``` 

Now let's type "terminal" to open up a bash terminal, and execute further commands:
```DigiKeyboard.print("terminal");```

To continue, we also need to press enter like so:
```DigiKeyboard.sendKeyStroke(KEY_ENTER);```

But this is a bit of a hassle, so alternatively, you could also use the Java friendly version, println:
```DigiKeyboard.println("terminal");```

Which would press enter at the end for you.

Now that we're in the terminal, you can apply whatever skills you already have for actual exploitation. This can range to anything from a reverse shell to installing a full bootkit, which will not be discussed here.

For those that are just getting started in security, you could run something like "tree", a command that lists all of the device files in a cool tree-like format, which doesn't do much, but looks pretty cool:
```DigiKeyboard.println("tree");```

# Extras:

Lastly, there are 2 more cool features I'll discuss, the loop() function and the DigiSpark's built in LED:

The loop() function is pretty self explanatory, repeating whatever's in the function over and over, once the setup() function is complete. This on its own might not look like much, but paired with the DigiSpark's LED, can be used to indicate when the BadUSB is done like so:
```
loop() {
    digitalWrite(0, HIGH);
    delay(300);
    digitalWrite(0, LOW);
    delay(300);
}```
