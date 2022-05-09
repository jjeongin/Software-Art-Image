#version 150

attribute vec4 position;

uniform mat4 modelViewProjectionMatrix;

uniform vec3 fvEyePosition;

varying vec3 ViewDirection;
varying vec3 Normal;

void main( void )
{
   gl_Position = ftransform();
   vec4 fvObjectPosition = gl_ModelViewMatrix * gl_Vertex;

   ViewDirection  = fvEyePosition - fvObjectPosition.xyz;
   Normal         = gl_NormalMatrix * gl_Normal;
}
