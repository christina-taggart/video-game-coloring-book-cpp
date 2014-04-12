/* 
 * Christina Taggart
 * Program 4: Simple World Scene: Stonehenge
 * CSC 471 with Professor Zoe Wood 
 *
 */

uniform float uMaterial;

varying vec3 lDir; 
varying vec3 vDist;
varying vec3 vNormal;
varying vec3 vColor;
varying vec3 lRef;

float ka = 0.5; //amount of ambient light
float Il = 0.999; //incoming light's intensity/color

void main() {

  float alpha = 5.0;
  float diffuse = uMaterial * max( (dot(vNormal, lDir)), 0.0) * Il; //lightDir
  float specular = uMaterial * max( pow(dot(vDist, lRef), alpha) ,0.0) * Il;
  float ambient = ka*Il;
  gl_FragColor = vec4(vColor.r * ( diffuse + specular + ambient ), 
			          vColor.g * ( diffuse + specular + ambient ), 
			          vColor.b * ( diffuse + specular + ambient ),
			          1.0);
}
