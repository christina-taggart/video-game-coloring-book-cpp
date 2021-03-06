# Jungle Boogie

<a target="_blank" href="http://minus.com/i/ed7ooRJtqKc9"><img src="http://i.minus.com/jed7ooRJtqKc9.png" border="0"/></a>

## Overview

Individual Video Game Development in CPP

## Description

* A user may select a keyboard color that appears as an icon on the screen
* A user can explores the 3D world
* A user may select an object (hierarchical model) to color by selecting an object, centering the object in the middle of the screen, and right clicking to set the object to the selected color
* A user may move forwards, backwards, and side to side directions relative to the camera's current gaze
* A user may perform view rotations using the mouse objects in the world 

## Basics

<a target="_blank" href="http://minus.com/i/ID3FZimcomQn"><img src="http://i.minus.com/jID3FZimcomQn.png" border="0"/></a>

* Animation and movement uses glut/OpenGL/GLSL 
* Camera transforms: application uses glm and local matrix stack to handle matrix transforms for a view matrix, projection matrix and model transform matrix 
* Full phong lighting: Kd(N*L)id  +  Ks(V*R)^a *is  +  Ka*il  +  0 (diffuse + specular + ambient + emissive)
* Hierarchical models
* To compile and run: 'make'
* Base code provided by Zoe Wood, CPE 471, Program 5: Final Project, Cal Poly

# Keyboard Inputs

* 'w' - dolly forward
* 'a' - strafe left
* 's' - dolly backward
* 'd' - strafe right
* 'r' - selcets red color
* 'g' - selects green color
* 'b' - selects blue color
* '1' - selcets burnt umber color
* '2' - selects turquoise color
* '3' - selects pink color
* '4' - selcets yellow color
* '5' - selects orange color
* '6' - selects violet color
* '7' - selects deep blue color
* '8' - selects brown color
* 'right click' sets current color of object (in center of view) to the selected color
* 'mouse drag' moves camera view throughout world
* 'q' - quit the program

## Coloring the World

<a target="_blank" href="http://minus.com/i/bqqSIuKdbEHuv"><img src="http://i.minus.com/jbqqSIuKdbEHuv.png" border="0"/></a>

