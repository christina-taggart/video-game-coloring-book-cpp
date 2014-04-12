/*
 *  Models.h
 *  CSC471
 */

#ifndef Models_h
#define Models_h

#ifdef __APPLE__

#endif
#ifdef __unix__
#include <GL/glut.h>
#endif

#include "GLUT/glut.h"
#include <OPENGL/gl.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" //perspective, trans etc
#include "glm/gtc/type_ptr.hpp" //value_ptr
#include "GLSL_helper.h"
#include "MStackHelp.h"
#include "GeometryCreator.h"
#include <math.h>

using namespace std;
using namespace glm;

// Program Variable (timer)
extern float Accumulator;

extern GLint h_aEye;
extern GLint h_uMaterial;
//Handles to the shader data
extern GLint h_aPosition;
extern GLint h_uColor;
extern GLint h_aNormal;
extern GLint h_uModelMatrix;
extern GLint h_uViewMatrix;
extern GLint h_uProjMatrix;
extern GLuint uNormalMatrix;

// Meshes
unsigned int const MeshCount = 100;
extern Mesh * Meshes[MeshCount];
extern unsigned int CurrentMesh;
extern RenderingHelper ModelTrans;

extern vector <vec4> centers;
extern vector <vec3> changeColor;
extern int flag;
extern vec3 currentColor;

void SetModel();
void DrawMask1();
void DrawMask2();

void DrawFlower1();
void DrawFlower2();
void DrawFlower3();
void DrawFlower5();
void DrawFlower6();
void DrawFlower7();
void DrawFlower8();

void DrawFlower4();
void DrawFlower9();
void DrawFlower10();

void DrawTree1();
void DrawTree2();
void DrawTree3();
void DrawTree4();
void DrawTree5();
void DrawTree6();
void DrawTrunk1();
void DrawTrunk2();
void DrawTrunk3();
void DrawTrunk4();
void DrawTrunk5();
void DrawTrunk6();

void DrawMiniMask1();
void DrawMiniMask2();
void DrawMiniMask3();
void DrawMiniMask4();
void DrawMiniMask5();
void DrawMiniMask6();

void DrawCreature1();
void DrawCreature2();
void DrawCreature3();
void DrawCreature4();
void DrawCreature5();
void DrawCreature6();
void DrawCreature7();
void DrawCreature8();
void DrawCreature9();

void DrawAnimal1();


 #endif //cant include something in 2 places at once