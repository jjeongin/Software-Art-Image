precision highp float;

uniform samplerCube cubeMap;

varying vec3 ViewDirection;
varying vec3 Normal;

const float mother_pearl_brightness = 1.5;

#define MOTHER_PEARL

void main()
{
   vec3  fvNormal         = normalize(Normal);
   vec3  fvViewDirection  = normalize(ViewDirection);
   vec3  fvReflection     = normalize(reflect(fvViewDirection, fvNormal));

    #ifdef MOTHER_PEARL
       float view_dot_normal = max(dot(fvNormal, fvViewDirection), 0.0);
       float view_dot_normal_inverse = 1.0 - view_dot_normal;

       gl_FragColor = textureCube(cubeMap, fvReflection) * view_dot_normal;
       gl_FragColor.r += mother_pearl_brightness * textureCube(cubeMap, fvReflection + vec3(0.1, 0.0, 0.0) * view_dot_normal_inverse) * (1.0 - view_dot_normal);
       gl_FragColor.g += mother_pearl_brightness * textureCube(cubeMap, fvReflection + vec3(0.0, 0.1, 0.0) * view_dot_normal_inverse) * (1.0 - view_dot_normal);
       gl_FragColor.b += mother_pearl_brightness * textureCube(cubeMap, fvReflection + vec3(0.0, 0.0, 0.1) * view_dot_normal_inverse) * (1.0 - view_dot_normal);
    #else
       gl_FragColor = textureCube(cubeMap, fvReflection);
    #endif
}

//void main()
//{
//    // gl_FragCoord contains the window relative coordinate for the fragment.
//    // we use gl_FragCoord.x position to control the red color value.
//    // we use gl_FragCoord.y position to control the green color value.
//    // please note that all r, g, b, a values are between 0 and 1.
//    
////    float windowWidth = 1024.0;
////    float windowHeight = 768.0;
//    
//    float avatarW = ofGetWidth()/2;
//    float avatarH = ofGetHeight();
//    
//    
//    
////	float r = gl_FragCoord.x / avatarW;
////	float g = gl_FragCoord.y / avatarH;
////	float b = 1.0;
////	float a = 1.0;
////	gl_FragColor = vec4(r, g, b, a);
//    
//    
//}
