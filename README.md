<a href="http://www.robertmisener.com"> My Portfolio Website </a>

# Game User Interface - C++

<p align="center"> <img src="https://github.com/RobMisener/Vending-Machine/raw/master/ReadMeImages/vendRAM1.gif" /> </p>

## Installation:
Clone and run with Visual Studio. The source code is not currently on GitHub - I am removing all unnecessary classes and functions that do not specifically
relate to the GUI, but it will be up shortly. I am trying to skim down the code from about 15,000 lines to about 2000 and perferably less as much of the code currently has other
functions and classes for features that are not specifically related to the UI. I will probably post those specififc parts later in digestible chunks that may help people working on specific elements. 

## Overview: 
Solo project built initially as a console application. The graphics/sprites/ and layout were created by myself in Blender/Gimp/Photoshop using 
3d models which were flattened into 2d sprites and then coded into the program using a hardware abstraction layer, specifically SDL (Simple Direct Media Layer).
This was built over many months, and I have learned much better programming practices since starting it, but I am proud of the overall result.

## Title Screen:
To create the title animation, I created the 2d image of the title screen in photoshop and then imported the image as an image plane to blender. I subdivided the mesh
of the image plane into pieces and inserted animation keyframes containing their final connected positions on the last frame of the animation playblack. I then seperated the subdivisions of the mesh
plane and spread them apart, recording keyframes of the subdivided and now seperated peices at earlier frames of the animation. The result was that the subdivisions of the image plane/mesh are initially
seperated and then come together. I then rendered the animation and took the individual png frames and placed them in one GIMP image. Using a sprite creator plugin, the pictures were arranged into
a spritesheet which I then used as the final png file on which the animation was based on. I then coded the reference to the image as a texture object in SDL, and created a rectangle outline which represented the size of
one individual image in the spritesheet.  This representation of the rectangle was then multipled by the number of frames in the image and put into an array, where through some 'for' loops, each position
of the animation was recorded relative to where the x and y location of each rectangle was. The rectangle itself is only a reference to the location of where you want the snapshot for that particular frame to be taken from in the picture.
By using SDL's built in functions you can assign peices or frames of the image to be assigned to individual images of an array, so that when you want to loop through the frames to
create an animation it is easy because it is simply looping through predefined points in the image.

## Stat Bars:
Stats are randomly generated from characters and are visually represented in the stat bars. As you scroll over each character, the stats stored for each
display onto the right of the screen. This was done by modifying the integer values of the geometric shapes generated from SDL. The stats held by objects from the character class
affect update each bar to represent the character that the mouse was hovering over.

## Character Sprites:
The character sprites were taken from 3d meshes I made in Blender. Similar to the process in the title screen I rendered the animaiton in Blender and put the frames together into a sprite sheet using Gimp. I then used the same process
that I used for the title screen. Is this the most efficient way to do this? Likely it is not, but it was the best wway I could see of putting this project together with my current knowledge level
of C++ and SDL.

## Turn order 
At end of the transaction, user change is returned in coins. The console machine returns coins like a real vending machine, starting with quarters, then dimes and nickels.
