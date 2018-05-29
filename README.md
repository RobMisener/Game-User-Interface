<a href="http://www.robertmisener.com"> My Portfolio Website </a>

# Game User Interface, Title Screen, Turn Order : C++ and SDL
#### By: Robert Misener


## Installation:
* Download and run in visual studio. Visit the <a href="http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvsnet2010u/index.php"> SDL setup tutorial </a> if you have problems or errors running it in Visual Studio. If there is any difficulty you can always contact myself as well.

## Overview: 
* This is a small part of a solo project I have been building, on and off, for about 2 years. It was built from the ground up, starting as an empty console program. The graphics, sprites, and layout were created by myself in Blender, Gimp, and Photoshop using 3D models which were flattened into 2D sprites and then coded into the program using a hardware abstraction layer, specifically SDL (Simple Direct Media Layer).

<p align="center"> <https://www.libsdl.org/download-2.0.php"> <img width = "300px" src="https://upload.wikimedia.org/wikipedia/ru/2/26/SDL_logo.png" /> </a> </p>

* As mentioned, this is part of a project that was made over a long period of time. Many of the variable names were not named with group work in mind and were created to be more understandable to myself while developing. As for the program in general, I admit the code is not perfect, but I am proud of the overall result. Unfortunately, like any creature bound by the laws of evolution, the program must stand on the shoulders of it's previous design decisions and I have learned much better programming practices since starting the project. There are still classes I want to modify and change dramatically, but in the meantime I must make due like the panda and grasp for my bamboo sticks using thumbs designed for tree-climbing; at least I will until the next coding monolith materializes.

## Title Screen:
* To create the title animation, I created a 2D image of the final title screen image in Photoshop, the water background was created using white spraypaint textures over some previous textures I had created for prior projects. 
* I then imported the title image as an image-plane into Blender, a 3D modeling program. I subdivided the mesh
of the image plane into pieces and inserted animation key-frames containing their final connected positions. 
* I then separated the subdivisions of the mesh and recorded the now parted pieces as seperate key-frames at the start of the timeline. I then rendered the result, which resulted in the appearance of the pieces of the title coming together as a whole.

<p align="center"> <a href="https://www.blender.org"> <img width = "400px" src="https://download.blender.org/institute/logos/blender-socket.png" /> </a> </p>

<p> I then placed the rendered PNG images in a spritesheet using GIMP 2.0. </p>

<p align="center"> <a href="https://gimp.org"> <img width = "400px" src="https://charitycatalogue.com/wp-content/uploads/2017/04/gimp-logo-1-1024x482.png" /> </a> </p>

* After, I coded a reference to the image as a texture object in SDL, and created a rectangle outline which represented the size of
one individual image in the sprite-sheet.  
* This representation of the rectangle was then multiplied by the number of frames in the image and put into an array, where through some 'for' loops, each frame
of the animation sprite was recorded as a seperate image relative to where the x and y location of each rectangle (clip) was assigned to.

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM4.gif" /> </p>
## Stat Bars:
* Stats are randomly generated from characters and are visually represented in the stat bars. 
* As you scroll over each character, the stats stored for each
are projected onto the right of the screen in the form of graph bars for each respective stat. 
* This was done by entering the various stat properties for each character into a method that passed the integer values of each stat as the x-axis for SDL geometrical rectangles. The rectangles were then drawn to the screen whenever the mouse hovered over the character.

## Character Sprites:
* The character sprites were taken from 3d meshes I made in Blender. The skins for the characters were created in Gimp 2.0.

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM3.gif" /> </p>

* Like the title screen animation, the animation was rendered in Blender using keyframes. 
* Bones for each person had to be created and assigned in Blender. 
* The bones were moved and the keyframes of their position were recorded to make the human mesh move.   

<p align="center"> <img src="https://github.com/RobMisener/Game-User-Interface/raw/master/ReadMeImages/torRAM2.gif" /> </p>

* The animation was rendered in Blender, creating PNG images for each frame of the animation. The PNG frames were then arranged into a spreadsheet using Gimp, merging them into one image file. 
* Using the colorize function in Gimp, multiple copies of the image were created, with each copy containing a character in a now different colored shirt. 
* These five spritesheets were then used to render each of the five character sprites rendered on the screen,

## Turn order 
* The initial turn order for each character is decided via a function that measures various character stats. The number is modified based on the stats of the other characters at the time of program compilation, so it is dynamically generated each time. 
* The rough turn order numbers of each character are sorted in an array. The values are sorted by turn order number and an array is returned that points to the reference of each character in order of their turn.
* Using the new pointer array as an argument, an icon of each individual character are rendered to the screen in order of their turn.

## Final Thoughts
* Useful, up-to-date, and helpful documentation regarding SDL is hard to come by
* Using SDL and C++ was challenging commpared to using a third party engine like Unity, but seemed to result in more organic choices
* Writing a good object oriented foundation from beginning is important, as design choices you make later will increasingly become afected by choices you made before

<a href="http://www.robertmisener.com"> See More Projects on My Portfolio Website</a>

