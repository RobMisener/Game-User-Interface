<a href="http://www.robertmisener.com"> My Portfolio Website </a>

# Game User Interface - C++

## Installation:
Source code will be up shortly - I am removing all unnecessary classes and functions that do not specifically
relate to the GUI, there are also some ghost classes / functions that need to be cleaned up. I will probably post those specififc parts later in digestible chunks so people can see the individual elements and so the huge folder size can be broken up across different repos.

## Overview: 
Solo project built initially as a console application. The graphics/sprites/ and layout were created by myself in Blender/Gimp/Photoshop using 
3d models which were flattened into 2d sprites and then coded into the program using a hardware abstraction layer, specifically SDL (Simple Direct Media Layer).

<p align="center"> <https://www.libsdl.org/download-2.0.php"> <img width = "300px" src="https://upload.wikimedia.org/wikipedia/ru/2/26/SDL_logo.png" /> </a> </p>

This was built over many months, and I have learned much better programming practices since starting it, but I am proud of the overall result. 

## Title Screen:
<p>  To create the title animation, I created the 2D image of the title screen in Photoshop, the water background was created using white spraypaint textures over some previous textures I had designed prior. I then imported the title image as an image plane to Blender, a 3D modeling program. I subdivided the mesh
of the image plane into pieces and inserted animation key-frames containing their final connected positions on the last frame of the animation in Blender. I then separated the subdivisions of the mesh
plane and spread them apart, recording animation key-frames of the subdivided -and now separated- pieces at earlier frames of the animation timeline. </p>

<p align="center"> <a href="https://www.blender.org"> <img width = "400px" src="https://download.blender.org/institute/logos/blender-socket.png" /> </a> </p>

<p> The result was that the subdivisions of the image plane/mesh are initially
separated and then come together. I then rendered the animation and took the individual PNG frames and placed them in one GIMP image. Using a sprite creator plugin, the pictures were arranged into
a spritesheet which I then used as the final PNG file on which the final in-game rendered animation would be based on. </p>

<p align="center"> <a href="https://gimp.org"> <img width = "400px" src="https://charitycatalogue.com/wp-content/uploads/2017/04/gimp-logo-1-1024x482.png" /> </a> </p>


<p> 
I then coded the reference to the image as a texture object in SDL, and created a rectangle outline (called a clip in SDL) which represented the size of
one individual image in the sprite-sheet.  This representation of the rectangle was then multiplied by the number of frames in the image and put into an array, where through some 'for' loops, each frame
of the animation sprite was recorded as a seperate image relative to where the x and y location of each rectangle (clip) was assigned to. 
</p>

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM4.gif" /> </p>

<p>
The rectangle clip itself is only a reference to the location - it is a window into which portion of the sprite sheet you wish to project into the array.
By using SDL's built in functions you can assign pieces or frames of the image to individual indexes in an array, so that when you want to loop through the frames to create an animation, you can render using the index number of the frame you want rendered to the screen.
</p>

## Stat Bars:
Stats are randomly generated from characters and are visually represented in the stat bars. As you scroll over each character, the stats stored for each
are projected onto the right of the screen. This was done by modifying the integer values of the geometric shapes generated from SDL. The stats held by objects from the character class
affect and update each bar to represent the character that the mouse was hovering over.

## Character Sprites:
The character sprites were taken from 3d meshes I made in Blender. 

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM3.gif" /> </p>

<p>Similar to the process in the title screen I rendered the animation in Blender and put the frames together into a sprite sheet using Gimp.</p> 

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM2.gif" /> </p>

<p> I then used the same process that I used for the title screen, assigning each portion of the spritesheet to rectangle clips and storing them in arrays to pass them through as animations that loop in reverse and then back to create a more lifelike and continuous image.
</p>

## Turn order 
The turn order is decided based on individual character stats and the character's smaller portraits (top upper-middle of screen) are ordered by which characters performed best in the function I designed to determine turn order. Would this be an RPG, a visual representation of turn order may be useful to the player when making strategic decisons.

## Final Thoughts
Designing the title screen and learning how C++ and SDL worked was one of the more difficult programming challenges I have encountered. Useful, up-to-date, and helpful documentation regarding SDL is hard to come by, I could really only find one good tutorial and reference site that I kept coming back to while teaching myself it. These days, many people create games using third party systems like Unity, which offer a visual and user friendly approach. C++ and SDL on the other hand is almost entirely code based, it's like working in a mechanic shop with just a match; you always feel a bit left in the dark as to what you are exactly creating and the learning curve is very high. I do, however, think it can result in more unique and creative results as the creation of your game is left more in your own hands and not through a graphical package designed to make a graphical package like Unity. But despite the difficulties, I learned a lot and had a lot of fun - and frustration - putting this together.
