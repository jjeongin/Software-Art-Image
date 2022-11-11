#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Petal {
public:
    int c;
    ofPoint p1;
    ofPoint p2;
    float radius;
    float startAngle;
    float endAngle;
    float angleStep;
};

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
		
    
    bool isDrawGUI;
    
    // GUI
    ofxPanel gui;
    ofxColorSlider c1;
    ofxColorSlider c2;
    ofxColorSlider c3;
//    ofxIntSlider layers;
    
    float minRadius;
    float maxRadius;
    float minAngle;
    int numPetals;
    int layers;
    
    vector < Petal > petals;
    
    // for screenshot
    ofImage screenImage;
};
