#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    int height = 795;
	ofSetupOpenGL(height * 1128 / 1364, height, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
