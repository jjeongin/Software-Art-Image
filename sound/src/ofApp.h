#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    // GUI
    bool isDrawGUI;
    ofxPanel gui;
    ofParameter<float> volume;
    ofParameter<float> decay;
    
    ofImage tiger;
    ofImage danchung;
    ofTexture danchung_texture;
    ofEasyCam cam;
    ofSpherePrimitive sphere;
    ofBoxPrimitive box;
    
    
    // Sound
    ofSoundPlayer sound;
    static constexpr size_t nBandsToGet = 128;
    std::array<float, nBandsToGet> fftSmoothed{{0}};
    
};
