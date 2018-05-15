<a href="http://www.robertmisener.com"> My Portfolio Website </a>

# Game User Interface - C++

## Installation:
Clone and run with Visual Studio. The source code is not currently on GitHub - I am removing all unnecessary classes and functions that do not specifically
relate to the GUI, but it will be up shortly. I am trying to skim down the code from about 15,000 lines to about 2000 and perferably less as much of the code currently has other
functions and classes for features that are not specifically related to the UI. I will probably post those specififc parts later in digestible chunks that may help people working on specific elements. But regardless, this should all be up shortly.

## Overview: 
Solo project built initially as a console application. The graphics/sprites/ and layout were created by myself in Blender/Gimp/Photoshop using 
3d models which were flattened into 2d sprites and then coded into the program using a hardware abstraction layer, specifically SDL (Simple Direct Media Layer).



<p align="center"> <https://www.libsdl.org/download-2.0.php"> <img width = "300px" src="https://upload.wikimedia.org/wikipedia/ru/2/26/SDL_logo.png" /> </a> </p>

This was built over many months, and I have learned much better programming practices since starting it, but I am proud of the overall result. Also, the project as it currently is is well over the gigabyte limit GitHub places on projects, so I have to pick and choose what to transfer first.

## Title Screen:
<p>  To create the title animation, I created the 2D image of the title screen in Photoshop and then imported the image as an image plane to Blender, a 3D modeling program. I subdivided the mesh
of the image plane into pieces and inserted animation key-frames containing their final connected positions on the last frame of the animation playback. I then separated the subdivisions of the mesh
plane and spread them apart, recording animation key-frames of the subdivided and now separated pieces at earlier frames of the animation. </p>

<p align="center"> <a href="https://www.blender.org"> <img width = "400px" src="https://download.blender.org/institute/logos/blender-socket.png" /> </a> </p>

<p> The result was that the subdivisions of the image plane/mesh are initially
separated and then come together. I then rendered the animation and took the individual PNG frames and placed them in one GIMP image. Using a sprite creator plugin, the pictures were arranged into
a spritesheet which I then used as the final png file on which the animation was based on. </p>

<p align="center"> <a href="https://gimp.org"> <img width = "400px" src="https://charitycatalogue.com/wp-content/uploads/2017/04/gimp-logo-1-1024x482.png" /> </a> </p>


<p> 
I then coded the reference to the image as a texture object in SDL, and created a rectangle outline which represented the size of
one individual image in the sprite-sheet.  This representation of the rectangle was then multiplied by the number of frames in the image and put into an array, where through some 'for' loops, each position
of the animation was recorded relative to where the x and y location of each rectangle was. 
</p>

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM4.gif" /> </p>

<p>
The rectangle itself is only a reference to the location of where you want the snapshot for that particular frame to be taken from in the picture.
By using SDL's built in functions you can assign pieces or frames of the image to be assigned to individual images of an array, so that when you want to loop through the frames to
create an animation it is easy because it is simply looping through predefined points in the image.
</p>

## Stat Bars:
Stats are randomly generated from characters and are visually represented in the stat bars. As you scroll over each character, the stats stored for each
display onto the right of the screen. This was done by modifying the integer values of the geometric shapes generated from SDL. The stats held by objects from the character class
affect update each bar to represent the character that the mouse was hovering over.

## Character Sprites:
The character sprites were taken from 3d meshes I made in Blender. 

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM3.gif" /> </p>

Similar to the process in the title screen I rendered the animaiton in Blender and put the frames together into a sprite sheet using Gimp. 

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM2.gif" /> </p>

 I then used the same process
that I used for the title screen, assigning each portion of the spritesheet to rectangle clips and storing them in arrays to pass them through as animations that loop in reverse and back to create a more lifelike and non-distracting effect. 

## Turn order 
The turn order is decided based on stats and the characters smaller portraits (top upper-middle of screen) are ordered by which characters performed best in the function to determine turn order. Would this be an RPG, a visual representation of turn order may be useful to the player when making strategic decisons.

## Final Thoughts
Designing the title screen and learning how C++ and SDL worked was one of the more difficult programming challenges I have encountered. Useful, up-to-date, and helpful documentation regarding SDL is hard to come by, I could really only find one good tutorial and reference site that I kept coming back to while teaching myself it. These days, many people create games using third party systems like Unity, which offer a visual and user friendly approach. C++ and SDL on the other hand is almost entirely code based, its like working in a mechanics shop with a match, you always feel a bit left in the dark as to what you are exactly creating and the learning curve is very high. I do, however, think it can result in more unique and creative results as the creation of your game is left in your hands - however unsteady they may be- and not created through graphical package designed to make a graphical package like Unity - which to be fair I have not personally tried myself albeit to me - and it may just be me - there seems to be a certain artistic staleness in both gameplay and design in some unity games, some seem to share  a similar graphical /stylistic aura to them. But despite the difficulties, I learned a lot and had a lot of fun - and frustration - putting this together.
