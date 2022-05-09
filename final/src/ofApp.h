#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxAssimpModelLoader avatar;
    ofLight light;
    ofShader shader;
    bool isShader;
    
    ofVideoGrabber webcam;
    ofMesh camMesh;
    
    // GUI
    bool isDrawGUI;
    ofxPanel gui;
//    ofParameter <ofVec3f> uiPosition;
    
//    ofxColorSlider c1;
    ofxLabel label;
    ofxToggle isLine;
    ofxToggle isSphere;
    
    ofxLabel label2;
    ofxToggle isAnimal;
    ofxToggle isWater;
    ofxToggle isSpace;
    ofxToggle isMetal;
    
    ofImage animal;
    ofImage water;
    ofImage space;
    ofImage silver;
    ofTexture texture;
    
    
    ofVboMesh mesh;
    ofVboMesh sphere_mesh;
    ofSpherePrimitive sphere;
    int sphere_rand_vertex;
    int radius = 100;
    int total = 10;
    
    vector< ofPoint > points;
    float rotateY;
    
    int count = 0;
    bool startScreen = false;
};
