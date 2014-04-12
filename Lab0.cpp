/* 
 *  Christina Taggart
 *  Program 5: Final Project: 3D Coloring Book
 *  CSC 471 with Professor Zoe Wood
 *  Description: User may select a keyboard color that appears in an icon on the screen
 *  As the user explores the world, she or he may select the object they wish to color
 *    by moving near the object, centering the object in the middle of the screen, and
    right clicking to set the color. 
 *  User may move in forwards, backwards, and side to side directions relative to current gaze
 *    as well as perform view rotations using the mouse
 *  Objects in world comprised of hierarchical models, and includes animation
 *  glut/OpenGL/GLSL application   
 *  Uses glm and local matrix stack
 *  To handle matrix transforms for a view matrix, projection matrix and model transform matrix
 *  Base Code provided by Zoe Wood
 *
 **********************************************************************************************************/

#include "Models.h"

// Parameters
unsigned int const StepSize = 10;


// Program Variable (timer)
float Accumulator;

GLint h_aEye;
GLint h_uMaterial;
//Handles to the shader data
GLint h_aPosition;
GLint h_uColor;
GLint h_aNormal;
GLint h_uModelMatrix;
GLint h_uViewMatrix;
GLint h_uProjMatrix;
GLuint uNormalMatrix;

// Meshes
//unsigned int const MeshCount = 50;
Mesh * Meshes[MeshCount];
unsigned int CurrentMesh;

//Centers of Models - for coloring
vector <vec4> centers;

vector <vec3> changeColor; 
vec3 currentColor = vec3(1.0, 1.0, 1.0); 
vec3 groundColor = vec3((146.0/255.0), (255.0/255.0), (93.0/255.0));
vec3 skyColor = vec3((76.0/255.0), (182.0/255.0), (191.0/255.0));
int flag = 0;

/*data structure for the image used for  texture mapping */
typedef struct Image {
  unsigned long sizeX;
  unsigned long sizeY;
  char *data;
} Image;

Image *TextureImage;

typedef struct RGB {
  GLubyte r;
  GLubyte g; 
  GLubyte b;
} RGB;

RGB myimage[64][64];
RGB* g_pixel;

//forward declaration of image loading and texture set-up code
int ImageLoad(char *filename, Image *image);
GLvoid LoadTexture(char* image_file, int tex_id);

// Meshes
/*
unsigned int const MeshCount = 14;
Mesh * Meshes[MeshCount];
unsigned int CurrentMesh;
*/

//flag and ID to toggle on and off the shader
int shade = 1;
int ShadeProg;

float material = 0.5;

GLuint CubeBuffObj, CIndxBuffObj, GrndBuffObj, GIndxBuffObj, NormalBuffObj, GrndNormalBuffObj; // NormalIndxBuffObj; 
int g_CiboLen, g_GiboLen;

/* globals to control positioning and window size */
static float g_width, g_height;
float g_tx = 0;
float g_ty = 0;
float g_trans = -5.5;
float g_angle = 0;

static const float g_groundY = -0.501;      // y coordinate of the ground
static const float g_groundSize = 50.0;   // half the ground length

//declare a matrix stack
RenderingHelper ModelTrans;

//transform variables/mouse
int g_startx, g_starty, g_endx, g_endy;
float alpha;
float beta;
vec3 eye(0, 0, 0);
vec3 lookAtPoint(1, 0, 0);
vec3 up(0, 1, 0);
vec3 gaze = lookAtPoint - eye;
vec3 w, u, v;

  
/* projection matrix - do not change - sets matrix in shader */
void SetProjectionMatrix() {

  glm::mat4 Projection = glm::perspective(80.0f, (float)g_width/g_height, 0.1f, 100.f);	
  safe_glUniformMatrix4fv(h_uProjMatrix, glm::value_ptr(Projection));
}

/* camera controls - do not change - sets matrix in shader */
void SetView() {
  glm::mat4 View = glm::lookAt(eye, lookAtPoint, up);
  safe_glUniformMatrix4fv(h_uViewMatrix, glm::value_ptr(View));
  safe_glUniform3f(h_aEye, eye.x, eye.y, eye.z);
}

/* model transforms - do not change - sets matrix in shader */
void SetModel() {
  safe_glUniformMatrix4fv(h_uModelMatrix, glm::value_ptr(ModelTrans.modelViewMatrix));
  safe_glUniformMatrix4fv(uNormalMatrix, glm::value_ptr(glm::transpose(glm::inverse(ModelTrans.modelViewMatrix))));
}

/* intialize ground data */
static void initGround() {

  // A x-z plane at y = g_groundY of dimension [-g_groundSize, g_groundSize]^2
    float GrndPos[] = { 
    -g_groundSize, g_groundY, -g_groundSize, 
    -g_groundSize, g_groundY,  g_groundSize, 
     g_groundSize, g_groundY,  g_groundSize, 
     g_groundSize, g_groundY, -g_groundSize
    };

    float GrndNormal[] = { 
      0, 1, 0,
      0, 1, 0,
      0, 1, 0,
      0, 1, 0,
      0, 1, 0,
      0, 1, 0,
    };

    unsigned short idx[] = {0, 1, 2, 0, 2, 3};
  
    g_GiboLen = 12; 
    glGenBuffers(1, &GrndBuffObj);
    glBindBuffer(GL_ARRAY_BUFFER, GrndBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GrndPos), GrndPos, GL_STATIC_DRAW);

    glGenBuffers(1, &GIndxBuffObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GIndxBuffObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idx), idx, GL_STATIC_DRAW);

    /* normal ground buff */
    glGenBuffers(1, &GrndNormalBuffObj);
    glBindBuffer(GL_ARRAY_BUFFER, GrndNormalBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GrndNormal), GrndNormal, GL_STATIC_DRAW);
}

/* intialize the cube data */
static void initCube() {

   float CubePos[] = {
    -0.5, -0.5, -0.5, /*back face 5 verts :0 */
    -0.5, 0.5, -0.5,
    0.5, 0.5, -0.5,
    0.5, -0.5, -0.5,
    0.0, 0.5, -0.5,
    -0.5, -0.5, 0.5, /*front face 5 verts :5*/
    -0.5, 0.5, 0.5,
    0.5, 0.5, 0.5,
    0.5, -0.5, 0.5,
    0.0, 0.5, 0.5,
    -0.5, -0.5, 0.5, /*left face 4 verts :10*/
    -0.5, -0.5, -.5,
    -0.5, 0.5, -0.5,
    -0.5, 0.5, 0.5,
    0.5, -0.5, 0.5, /*right face 4 verts :14*/
    0.5, -0.5, -.5,
    0.5, 0.5, -0.5,
    0.5, 0.5, 0.5
  };

   float CubeNormal[] = {
    0, 0, -1, /* back face -z is orthoganal (normal) */
    0, 0, -1,
    0, 0, -1,
    0, 0, -1,
    0, 0, -1,
    0, 0, 1, /* front face z is orthoganal (normal) */
    0, 0, 1, 
    0, 0, 1,
    0, 0, 1, 
    0, 0, 1, 
    -1, 0, 0, /* left face -x is orthoganal (normal) */
    -1, 0, 0,
    -1, 0, 0,
    -1, 0, 0,
    1, 0, 0, /* right face x axis is orthoganal (normal) */
    1, 0, 0,
    1, 0, 0,
    1, 0, 0
  }; 

   unsigned short idx[] = {0, 1, 2,  2, 3, 0,  1, 4, 2,  5, 6, 7,  7, 8, 5,  6, 9, 7,  10, 11, 12,  12, 13, 10,  14, 15, 16,  16, 17, 14};
 
    g_CiboLen = 36; 
    glGenBuffers(1, &CubeBuffObj);
    glBindBuffer(GL_ARRAY_BUFFER, CubeBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CubePos), CubePos, GL_STATIC_DRAW);

    glGenBuffers(1, &CIndxBuffObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, CIndxBuffObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idx), idx, GL_STATIC_DRAW);

    glGenBuffers(1, &NormalBuffObj);
    glBindBuffer(GL_ARRAY_BUFFER, NormalBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CubeNormal), CubeNormal, GL_STATIC_DRAW);
    
}

void InitGeom() {
  initGround();
  initCube();
}

/*function to help load the shaders (both vertex and fragment */
int InstallShader(const GLchar *vShaderName, const GLchar *fShaderName) {
        GLuint VS; //handles to shader object
        GLuint FS; //handles to frag shader object
        GLint vCompiled, fCompiled, linked; //status of shader

        VS = glCreateShader(GL_VERTEX_SHADER);
        FS = glCreateShader(GL_FRAGMENT_SHADER);

        //load the source
        glShaderSource(VS, 1, &vShaderName, NULL);
        glShaderSource(FS, 1, &fShaderName, NULL);

        //compile shader and print log
        glCompileShader(VS);
        /* check shader status requires helper functions */
        printOpenGLError();
        glGetShaderiv(VS, GL_COMPILE_STATUS, &vCompiled);
        printShaderInfoLog(VS);

        //compile shader and print log
        glCompileShader(FS);
        /* check shader status requires helper functions */
        printOpenGLError();
        glGetShaderiv(FS, GL_COMPILE_STATUS, &fCompiled);
        printShaderInfoLog(FS);

        if (!vCompiled || !fCompiled) {
                printf("Error compiling either shader %s or %s", vShaderName, fShaderName);
                return 0;
        }

        //create a program object and attach the compiled shader
        ShadeProg = glCreateProgram();
        glAttachShader(ShadeProg, VS);
        glAttachShader(ShadeProg, FS);

        glLinkProgram(ShadeProg);
        /* check shader status requires helper functions */
        printOpenGLError();
        glGetProgramiv(ShadeProg, GL_LINK_STATUS, &linked);
        printProgramInfoLog(ShadeProg);

        glUseProgram(ShadeProg);

        /* get handles to attribute data */
        h_aPosition = safe_glGetAttribLocation(ShadeProg, "aPosition");
        /* add a handle for the normal */
        h_aNormal = safe_glGetAttribLocation(ShadeProg, "aNormal"); 

        h_aEye = safe_glGetAttribLocation(ShadeProg, "aEye");
        h_uMaterial = safe_glGetUniformLocation(ShadeProg, "uMaterial");
        h_uColor = safe_glGetUniformLocation(ShadeProg,  "uColor");
    	  h_uProjMatrix = safe_glGetUniformLocation(ShadeProg, "uProjMatrix");
    	  h_uViewMatrix = safe_glGetUniformLocation(ShadeProg, "uViewMatrix");
    	  h_uModelMatrix = safe_glGetUniformLocation(ShadeProg, "uModelMatrix");
        uNormalMatrix   = safe_glGetUniformLocation(ShadeProg, "uNormalMatrix");
        printf("sucessfully installed shader %d\n", ShadeProg);
        return 1;
}

/* Some OpenGL initialization */
void Initialize ()					// Any GL Init Code 
{
	// Start Of User Initialization
	//glClearColor (1.0f, 1.0f, 1.0f, 1.0f);		
  glClearColor(skyColor.x, skyColor.y, skyColor.z, 1.0f);						
	// Black Background
 	glClearDepth (1.0f);	// Depth Buffer Setup
 	glDepthFunc (GL_LEQUAL);	// The Type Of Depth Testing
	glEnable (GL_DEPTH_TEST);// Enable Depth Testing

    /* some matrix stack init */
    ModelTrans.useModelViewMatrix();
    ModelTrans.loadIdentity();
 
}

/* Main display function */
void Draw (void)
{

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				
	//Start our shader	
 	glUseProgram(ShadeProg);

	/* only set the projection and view matrix once */
    SetProjectionMatrix();
    SetView();
    
     /* set the matrix stack to the identity */
     ModelTrans.loadIdentity();
     SetModel();
            /* Draw the Ground */
            safe_glEnableVertexAttribArray(h_aPosition);
            // bind vbo
            glBindBuffer(GL_ARRAY_BUFFER, GrndBuffObj);
            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
            // bind ibo
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GIndxBuffObj);

            //normal ground buffer 
              safe_glEnableVertexAttribArray(h_aNormal); 
              //bind vbo
              glBindBuffer(GL_ARRAY_BUFFER, GrndNormalBuffObj);
              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0); 
              glUniform3f(h_uColor, groundColor.x, groundColor.y, groundColor.z);

            // draw!
            glDrawElements(GL_TRIANGLES, g_GiboLen, GL_UNSIGNED_SHORT, 0);

            // Disable the attributes used by our shader
            safe_glDisableVertexAttribArray(h_aPosition);
            safe_glDisableVertexAttribArray(h_aNormal); 


            /* color palette */

            CurrentMesh = 49;
            safe_glEnableVertexAttribArray(h_aPosition);
            safe_glEnableVertexAttribArray(h_aNormal); 

            ModelTrans.pushMatrix();
              
              ModelTrans.translate(vec3(eye.x, -0.2, eye.z)); 
              //ModelTrans.rotate(-alpha * (180/3.14), vec3(0, 0, 1));
              ModelTrans.rotate(-beta * (180/3.14), vec3(0, 1, 0) );
              ModelTrans.translate(vec3(0.5, 0, 0.3)); 

              SetModel();

              safe_glEnableVertexAttribArray(h_aPosition);
              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

              safe_glEnableVertexAttribArray(h_aNormal);
              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);

              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);

              glUniform3f(h_uColor, currentColor.x, currentColor.y, currentColor.z );
              safe_glUniform1f(h_uMaterial, 1.0);

              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
              ModelTrans.popMatrix();


     DrawMask1();
     DrawMask2();
        DrawFlower1();


     DrawFlower2();
     DrawFlower3();
     DrawFlower5();
     DrawFlower6();
     DrawFlower7();
     DrawFlower8();

     DrawFlower4();
     DrawFlower9();
     DrawFlower10();


     DrawTree1();
     DrawTree2();
     DrawTree3();
     DrawTree4();
     DrawTree5();
     DrawTree6();
     DrawTrunk1();
     DrawTrunk2();
     DrawTrunk3();
     DrawTrunk4();
     DrawTrunk5();
     DrawTrunk6();
     DrawMiniMask1();
     DrawMiniMask2();
     DrawMiniMask3();
     DrawMiniMask4();
     DrawMiniMask5();
     DrawMiniMask6();

    DrawCreature1();
    DrawCreature2();
    DrawCreature3();
    DrawCreature4();
    DrawCreature5();
    DrawCreature6();
    DrawCreature7();
    DrawCreature8();
    DrawCreature9();

   // DrawAnimal1();

     flag = 1;
	  //Disable the shader
	glUseProgram(0);	
	glutSwapBuffers();
  glutPostRedisplay();

}

/* Reshape */
void ReshapeGL (int width, int height)								
{
	g_width = (float)width;
	g_height = (float)height;
	glViewport (0, 0, (GLsizei)(width), (GLsizei)(height));				

}

//the keyboard callback to change the values to the transforms
void keyboard(unsigned char key, int x, int y ){
  switch( key ) {
    //change eye based on keyboard events
    case 'a':
      //strafe left, change camera angle and lookAtPoint
      gaze = -gaze;
      w = normalize(gaze); 
      u = normalize(cross(up, w));
      v = normalize(cross(w, u));

      eye.x -= .5*u.x;
      eye.z -= .5*u.z;

      lookAtPoint.x -= .5*u.x;
      lookAtPoint.z -= .5*u.z;

      gaze = lookAtPoint - eye;
      break;
    case 'd':
      //strafe right, change camera angle and lookAtPoint
      gaze = -gaze;
      w = normalize(gaze); 
      u = normalize(cross(up, w));
      v = normalize(cross(w, u));

      eye.x += .5*u.x;
      eye.z += .5*u.z;

      lookAtPoint.x += .5*u.x;
      lookAtPoint.z += .5*u.z;

      gaze = lookAtPoint - eye;
      break;
    case 's':
      //dolly backward, change camera angle and lookAtPoint
      gaze = -gaze;
      w = normalize(gaze); 
      u = normalize(cross(up, w));
      v = normalize(cross(w, u));

      eye.x += .5*w.x;
      eye.z += .5*w.z;

      lookAtPoint.x += .5*w.x;
      lookAtPoint.z += .5*w.z;

      gaze = lookAtPoint - eye;
      break;
    case 'w':
      //dolly forward, change camera angle and lookAtPoint
      gaze = -gaze;
      w = normalize(gaze); 
      u = normalize(cross(up, w));
      v = normalize(cross(w, u));

      eye.x -= .1*w.x;
      eye.z -= .1*w.z;

      lookAtPoint.x -= .1*w.x;
      lookAtPoint.z -= .1*w.z;

      gaze = lookAtPoint - eye;
      break;
    case 'r':
      currentColor = vec3(0.9, 0.0, 0.0);
      break;
    case 'g':
      currentColor = vec3(0.0, 0.9, 0.0);
      break;
    case 'b':
      currentColor = vec3(0.0, 0.0, 0.9);
      break;
    case '1':
      currentColor = vec3(0.69019608, 0.36470588, 0.15294118);
      break;
    case '2':
      currentColor = vec3(0.09019608, 0.45098039, 0.37254902);
      break;
    case '3':
      currentColor = vec3(0.64705882, 0.15686275, 0.25098039);
      break;
    case '4':
      currentColor = vec3(0.91764706, 0.78823529, 0.31764706);
      break;
    case '5':
      currentColor = vec3( (242.0/255.0), (125.0/255.0) , (26.0/255.0) );
      break;
    case '6':
      currentColor = vec3( (135.0/255.0), (50.0/255.0) , (191.0/255.0) );
      break;
    case '7':
      currentColor = vec3( (1.0/255.0), (31.0/255.0) , (38.0/255.0) );
      break;
    case '8':
      currentColor = vec3( (38.0/255.0), (19.0/255.0) , (13.0/255.0) );
      break;
    case '9':
      currentColor = vec3( (32.0/255.0), (141.0/255.0) , (166.0/255.0) );
      break;
    case 'q': case 'Q' :
      exit( EXIT_SUCCESS );
      break;
  }
  glutPostRedisplay();
}

void Timer(int param)
{
    Accumulator += StepSize * 0.001f;
    glutTimerFunc(StepSize, Timer, 1);
}

void mouse(int button, int state, int x, int y) {
  bool do_color = false;
      if (state == GLUT_DOWN) {
          g_startx = x;
          g_starty = g_height-y-1;
          if (button == GLUT_LEFT_BUTTON) { /* if the left button is clicked */

          } 
          if( button == GLUT_RIGHT_BUTTON){
            //color it !
              vec3 currGaze = lookAtPoint - eye;
              vec3 currModel;
              int index;
              int minAngle = 400;
              int minDist = INT_MAX;
              float distModel, distGaze, angle;
              distGaze = sqrt(dot(currGaze, currGaze));
              if(lookAtPoint.y < -0.5){
                groundColor = currentColor;

              }
              if(lookAtPoint.y > 85.0){
                skyColor = currentColor;

              }
              for(int i = 0; i<centers.size(); i++){
                vec3 temp = vec3(centers[i].x, centers[i].y, centers[i].z);
                currModel = temp - eye;
                distModel = sqrt( pow( (eye.x - centers[i].x), 2) + pow( (eye.y - centers[i].y), 2) + pow( (eye.z - centers[i].z), 2) );
                angle = abs ((acos( (dot(currModel, currGaze)) / ( distModel * distGaze) ) )* (180/3.14) );
                if(angle < 10.0){
                  if(angle < minAngle){
                    if(distModel < minDist){
                      minAngle = angle;
                      minDist = distModel;
                      index = i; //min obj distance = object index
                      do_color = true;
                    }
                  }
                }
              }

              if(do_color)
                 changeColor[index] = currentColor; 
          }
      }
}

void mouseMove(int x, int y) {
  g_endx = x;
  g_endy = g_height-y-1;
    
  alpha += (g_endy - g_starty)*3.14/g_height;
  beta += (g_endx - g_startx)*6.28/g_width; 

  float x_pt = 1.0*cos(alpha)*cos(beta);
  if(alpha > 1.54){ 
    alpha = 1.54;
  }
  float y_pt = 1.0*sin(alpha);
  float z_pt = 1.0*cos(alpha)*cos(1.57 - beta);

  lookAtPoint = glm::vec3(x_pt, y_pt, z_pt) + eye; 

  g_startx = g_endx;
  g_starty = g_endy;

  glutPostRedisplay();
}

int main( int argc, char *argv[] )
{
   	glutInit( &argc, argv );
   	glutInitWindowPosition( 20, 20 );
   	glutInitWindowSize( 800, 800 );
   	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
   	glutCreateWindow("Cube and Transforms");
   	glutReshapeFunc( ReshapeGL );
   	glutDisplayFunc( Draw );
	  glutKeyboardFunc( keyboard ); 
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutTimerFunc(StepSize, Timer, 1);
   	Initialize();
	
	//test the openGL version
	getGLversion();
	//install the shader
	if (!InstallShader(textFileRead((char *)"Lab0_vert.glsl"), textFileRead((char *)"Lab0_frag.glsl"))) {
		printf("Error installing shader!\n");
		return 0;
	}
		
	InitGeom();

  for(int i = 0; i<40; i++){
    changeColor.push_back(vec3(1.0, 1.0, 1.0));
  }

     /* Mask 1 */
     Meshes[1] = GeometryCreator::CreateSphere(glm::vec3(0.8f, 2.3f, 0.5f), 300, 60); //outer ear
     Meshes[2] = GeometryCreator::CreateCube(vec3(0.5f, 0.5f, 0.4f) ); //small cube
     Meshes[3] = GeometryCreator::CreateSphere(glm::vec3(0.5f)); //spheres
     Meshes[5] = GeometryCreator::CreateSphere(glm::vec3(7.0f, 0.3f, 0.4f), 300, 60); //feather
     Meshes[6] = GeometryCreator::CreateTorus(0.08f, 0.35f, 6, 12); // pupils
     Meshes[7] = GeometryCreator::CreateSphere(glm::vec3(0.6f, 7.0f, 1.0f), 300, 60); //nose
     Meshes[8] = GeometryCreator::CreateSphere(glm::vec3(5.0f, 11.0f, 1.2f), 300, 60); //ellipse 6
     Meshes[9] = GeometryCreator::CreateSphere(glm::vec3(4.6f, 10.1f, 1.0f), 150, 30); //ellipse inside 5.5
     Meshes[10] = GeometryCreator::CreateTorus(0.7f, 1.0f, 6, 12); // eyes
     Meshes[13] = GeometryCreator::CreateSphere(glm::vec3(0.5f, 2.0f, 0.5f), 300, 60); //nose holes

     /* Mask 2 */
     Meshes[14] = GeometryCreator::CreateSphere(glm::vec3(5.0f, 11.0f, 1.2f), 300, 60); //ellipse 6
     Meshes[15] = GeometryCreator::CreateSphere(glm::vec3(4.6f, 10.1f, 1.0f), 150, 30); //ellipse inside 5.5
     Meshes[16] = GeometryCreator::CreateTorus(0.6f, 1.0f, 6, 12); // eyes
     Meshes[17] = GeometryCreator::CreateSphere(glm::vec3(0.6f, 7.0f, 1.0f), 300, 60); //nose
     Meshes[18] = GeometryCreator::CreateSphere(glm::vec3(0.6f, 1.5f, 0.5f), 300, 60); //nose holes
     Meshes[19] = GeometryCreator::CreateSphere(glm::vec3(0.2f, 1.0f, 0.5f), 300, 60); //whitenose holes
     Meshes[20] = GeometryCreator::CreateTorus(0.4f, 0.9f, 6, 12); // ears
     Meshes[21] = GeometryCreator::CreateTorus(0.08f, 0.35f, 6, 12); // pupils
     Meshes[22] = GeometryCreator::CreateCube(vec3(0.8f, 0.8f, 0.4f) ); //small cube
     Meshes[23] = GeometryCreator::CreateSphere(glm::vec3(0.2f)); //spheres
     Meshes[24] = GeometryCreator::CreateTorus(1.7f, 2.0f, 6, 12); // hat

     /* Flower */
     Meshes[62] = GeometryCreator::CreateSphere(glm::vec3(0.01f)); //little arbitrary center: use for others
     Meshes[25] = GeometryCreator::CreateSphere(glm::vec3(0.1f, 0.34f, 0.16f), 300, 60); //black leaf ellipse
     Meshes[26] = GeometryCreator::CreateSphere(glm::vec3(0.05f, 0.28f, 0.1f), 128, 32); //white leaf ellipse
     Meshes[63] = GeometryCreator::CreateSphere(glm::vec3(0.03f, 0.5f, 0.03f), 128, 32); //pistol 
     Meshes[30] = GeometryCreator::CreateSphere(glm::vec3(0.06f)); //pollen
     Meshes[31] = GeometryCreator::CreateSphere(glm::vec3(0.05f)); //pollen white

     Meshes[27] = GeometryCreator::CreateSphere(glm::vec3(0.056f, 0.17f, 0.04f), 128, 32); //ellipse

     /* Flower 2 */
     Meshes[35] = GeometryCreator::CreateTorus(1.f, 2.f, 12, 24); //wheel
     Meshes[36] = GeometryCreator::CreateCube(); //cube

     Meshes[37] = GeometryCreator::CreateTorus(0.5f, 1.f, 6, 12); // small wheel
     //Meshes[38] = GeometryCreator::CreateCube(vec3(0.5f, 0.5f, 0.5f) ); //small cube
     Meshes[38] = GeometryCreator::CreateSphere(glm::vec3(0.5f, 0.84f, 0.55f), 128, 32); //ellipse

     Meshes[42] = GeometryCreator::CreateSphere(glm::vec3(0.5f)); //center point for flower rotation
     Meshes[43] = GeometryCreator::CreateSphere(glm::vec3(0.5f, 0.84f, 0.55f), 128, 32); //ellipse

     /* Lion */
     Meshes[64] = GeometryCreator::CreateSphere(glm::vec3(1.5f, 1.5f, 1.f), 300, 60); //ellipse
     Meshes[65] = GeometryCreator::CreateSphere(glm::vec3(1.2f, 1.2f, 0.8f), 300, 60);  //ellipse

     /* Tree */
     Meshes[45] = GeometryCreator::CreateSphere(glm::vec3(5.0f)); //sphere
     Meshes[46] = GeometryCreator::CreateSphere(glm::vec3(4.7f)); //sphere

     /*trunk */
     Meshes[47]= GeometryCreator::CreateCube(vec3(1.3f, 12.f, 2.f)); //rectangle
     Meshes[48]= GeometryCreator::CreateCube(vec3(1.0f, 11.5f, 1.5f)); //rectangle
     Meshes[50]= GeometryCreator::CreateCube(vec3(1.1f, 5.f, 0.5f)); //rectangle
     Meshes[51]= GeometryCreator::CreateCube(vec3(0.8f, 5.f, 0.4f)); //rectangle

     /* smaller masks! */
     Meshes[52] = GeometryCreator::CreateSphere(glm::vec3(0.2f, 1.0f, 0.8f), 300, 60); //ellipse
     Meshes[53] = GeometryCreator::CreateSphere(glm::vec3(0.05f, 0.9f, 0.7f), 300, 60);  //ellipseUSE FOR LIL FACES
     Meshes[54] = GeometryCreator::CreateSphere(glm::vec3(0.12f)); //spheres
     Meshes[55] = GeometryCreator::CreateSphere(glm::vec3(0.05f, 0.05f, 0.2f), 300, 60); //face markings
     Meshes[56] = GeometryCreator::CreateSphere(glm::vec3(0.05f, 0.7f, 0.05f), 300, 60); //ellipse center slit!!!
     Meshes[57] = GeometryCreator::CreateSphere(glm::vec3(0.18f)); //spheres: EYES
     Meshes[60] = GeometryCreator::CreateSphere(glm::vec3(0.06f, 0.4f, 0.05f), 300, 60); //bigger markings

     /* little forrest ones */
    Meshes[58] = GeometryCreator::CreateSphere(glm::vec3(0.8f)); //spheres
    Meshes[59] = GeometryCreator::CreateSphere(glm::vec3(0.77f)); //spheres

    /* Tree*/
    Meshes[61] = GeometryCreator::CreateSphere(glm::vec3(0.1f)); //arbitrary center: use for others

     /* pallette */
    Meshes[49] = GeometryCreator::CreateSphere(glm::vec3(0.03f), 4, 2); //diamond


  	glutMainLoop();
   	return 0;
}

//routines to load in a bmp files - must be 2^nx2^m and a 24bit bmp
GLvoid LoadTexture(char* image_file, int texID) { 
  
  TextureImage = (Image *) malloc(sizeof(Image));
  if (TextureImage == NULL) {
    printf("Error allocating space for image");
    exit(1);
  }
  cout << "trying to load " << image_file << endl;
  if (!ImageLoad(image_file, TextureImage)) {
    exit(1);
  }  
  /*  2d texture, level of detail 0 (normal), 3 components (red, green, blue),            */
  /*  x size from image, y size from image,                                              */    
  /*  border 0 (normal), rgb color data, unsigned byte data, data  */ 
  glBindTexture(GL_TEXTURE_2D, texID);
  glTexImage2D(GL_TEXTURE_2D, 0, 3,
    TextureImage->sizeX, TextureImage->sizeY,
    0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); /*  cheap scaling when image bigger than texture */    
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); /*  cheap scaling when image smalled than texture*/
  
}

static unsigned int getint(FILE *fp) {
  int c, c1, c2, c3;
  
  /*  get 4 bytes */ 
  c = getc(fp);  
  c1 = getc(fp);  
  c2 = getc(fp);  
  c3 = getc(fp);
  
  return ((unsigned int) c) +   
    (((unsigned int) c1) << 8) + 
    (((unsigned int) c2) << 16) +
    (((unsigned int) c3) << 24);
}

static unsigned int getshort(FILE *fp){
  int c, c1;
  
  /* get 2 bytes*/
  c = getc(fp);  
  c1 = getc(fp);
  
  return ((unsigned int) c) + (((unsigned int) c1) << 8);
}

/*  quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  */
int ImageLoad(char *filename, Image *image) {
  FILE *file;
  unsigned long size;                 /*  size of the image in bytes. */
  unsigned long i;                    /*  standard counter. */
  unsigned short int planes;          /*  number of planes in image (must be 1)  */
  unsigned short int bpp;             /*  number of bits per pixel (must be 24) */
  char temp;                          /*  used to convert bgr to rgb color. */
  
  /*  make sure the file is there. */
  if ((file = fopen(filename, "rb"))==NULL) {
    printf("File Not Found : %s\n",filename);
    return 0;
  }
  
  /*  seek through the bmp header, up to the width height: */
  fseek(file, 18, SEEK_CUR);
  
  /*  No 100% errorchecking anymore!!! */
  
  /*  read the width */    image->sizeX = getint (file);
  
  /*  read the height */ 
  image->sizeY = getint (file);
  
  /*  calculate the size (assuming 24 bits or 3 bytes per pixel). */
  size = image->sizeX * image->sizeY * 3;
  
  /*  read the planes */    
  planes = getshort(file);
  if (planes != 1) {
    printf("Planes from %s is not 1: %u\n", filename, planes);
    return 0;
  }
  
  /*  read the bpp */    
  bpp = getshort(file);
  if (bpp != 24) {
    printf("Bpp from %s is not 24: %u\n", filename, bpp);
    return 0;
  }
  
  /*  seek past the rest of the bitmap header. */
  fseek(file, 24, SEEK_CUR);
  
  /*  read the data.  */
  image->data = (char *) malloc(size);
  if (image->data == NULL) {
    printf("Error allocating memory for color-corrected image data");
    return 0; 
  }
  
  if ((i = fread(image->data, size, 1, file)) != 1) {
    printf("Error reading image data from %s.\n", filename);
    return 0;
  }
  
  for (i=0;i<size;i+=3) { /*  reverse all of the colors. (bgr -> rgb) */
    temp = image->data[i];
    image->data[i] = image->data[i+2];
    image->data[i+2] = temp;
  }
  
  fclose(file); /* Close the file and release the filedes */
  
  /*  we're done. */
  return 1;
}
