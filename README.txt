/* 
 *  Christina Taggart
 *  Program 5: Final Project: 3D Coloring Book
 *  CSC 471 with Professor Zoe Wood
 *  Description: User may select a keyboard color that appears as
 *  an icon on the screen
 *  As the user explores the world, (s)he may select the object they
 *  wish to color by moving near the object, centering the object in 
 *  the middle of the screen, and right clicking to set the color. 
 *  User may move in forwards, backwards, and side to side directions 
 *  relative to current gaze as well as perform view rotations using the mouse
 *  Objects in world comprised of hierarchical models, and includes animation
 *  glut/OpenGL/GLSL application   
 *  Uses glm and local matrix stack
 *  To handle matrix transforms for a view matrix, projection matrix and model 
 *  transform matrix
 *  Base Code provided by Zoe Wood
 *
 *******************************************************/

 To Compile & Run: make

 Keyboard Inputs:
  'a' - moves to the left of current gaze
  'd' - moves to the right of current gaze
  'w' - moves forward in the scene along the current gaze
  's' - moves backward in the scene along the current gaze
  'r' - selcets red color
  'g' - selects green color
  'b' - selects blue color
  '1' - selcets burnt umber color
  '2' - selects turquoise color
  '3' - selects pink color
  '4' - selcets yellow color
  '5' - selects orange color
  '6' - selects violet color
  '7' - selects deep blue color
  '8' - selects brown color
  'right click' sets current color of object (in center of view) to the selected color
  'mouse drag' moves camera view throughout world
  'q' - quit the program
