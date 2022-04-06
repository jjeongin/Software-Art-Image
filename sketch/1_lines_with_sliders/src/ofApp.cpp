#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    gui.setup();
    
    gui.add(numSlider.setup("num. of lines", 50, 0, 100));
    gui.add(thicknessSlider.setup("thickness", 5.0, 0.0, 10.0));
    
    gui.add(rSlider.setup("r", ofRandom(255), 0.0, 255.0));
    gui.add(gSlider.setup("g", ofRandom(255), 0.0, 255.0));
    gui.add(bSlider.setup("b", ofRandom(255), 0.0, 255.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // line color
    ofColor myColor(rSlider, gSlider, bSlider);
    ofSetColor(myColor);
    
    // line thickness
    ofSetLineWidth(thicknessSlider);
    
    // draw lines
    for (int i = 0; i < numSlider; i++) {
    ofDrawLine(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
