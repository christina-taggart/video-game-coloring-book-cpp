/* 
 * Christina Taggart
 * Program 4: Simple World Scene: Stonehenge
 * CSC 471 with Professor Zoe Wood 
 *
 */

attribute vec3 aPosition;
attribute vec3 aNormal; 
attribute vec3 aEye; 

uniform mat4 uProjMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uModelMatrix;
uniform mat4 uNormalMatrix;
uniform vec3 uColor;
uniform float uMaterial;

varying vec3 vColor;
varying vec3 gColor;
varying vec3 lDir; 
varying vec3 vNormal;
varying vec3 vDist;
varying vec3 lRef; 

float ka = 0.5; //ambient
float Il = 0.999; // incoming light's intensity or color


void main() {
  vec4 vPosition;
  vec3 lPos;

  /* First model transforms, view position */
  vPosition = uModelMatrix* vec4(aPosition.x, aPosition.y, aPosition.z, 1);
  lPos = vec3(0.9, 0.9, 0.9); 
  lDir = vec3( lPos.x - aPosition.x, lPos.y - aPosition.y, lPos.z - aPosition.z );  

  vDist = normalize(vec3( aEye.x - vPosition.x, aEye.y - vPosition.y, aEye.z - vPosition.z));
  lRef = normalize(-lPos + 2.0*( max(dot(lPos, vNormal), 0.0) ) * vNormal) ;

  vPosition = uViewMatrix* vPosition;
  gl_Position = uProjMatrix*vPosition;

  vec4 Normal = vec4(aNormal, 1.0); 
  vNormal = normalize((uNormalMatrix * Normal).xyz);

  lDir = normalize(lDir);
  gl_FrontColor = vec4(uColor.r, uColor.g, uColor.b, 1.0);
  float alpha = 1.0;
  float diffuse = uMaterial * max( (dot(vNormal, lDir)), 0.0) * Il; 
  float specular = uMaterial * max( pow(dot(vDist, lRef), alpha) ,0.0) * Il;
  float ambient = ka*Il;

  vColor = vec3(  uColor.r * ( diffuse + specular + ambient ), 
            uColor.g * ( diffuse + specular + ambient ), 
            uColor.b * ( diffuse + specular + ambient ) );

}
