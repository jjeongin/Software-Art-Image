#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(10); // slow down
    
    // original gif source : https://gfycat.com/alertwarlikeass
    video.load("flower-blooming.mp4");
    video.play();
    
    texture.allocate(video.getWidth(), video.getHeight(), OF_PIXELS_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if (video.isFrameNew()) {
        ofPixels pixels = video.getPixels();
        texture.loadData(pixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float sinTime = sin(ofGetElapsedTimef());
//    float sinTimeRadius = ofMap(sinTime, -1, 1, 10, ofGetWidth()/2); // experiment with circle
    float sinTimeAlpha = ofMap(sinTime, -1, 1, 0, 255);
    float sinTimeReverseAlpha = ofMap(sinTime, -1, 1, 255, 0);
    
    // background
    ofSetColor(255, 255, 255);
    texture.draw(ofGetWidth()/2 - ofGetHeight()/2, 0, ofGetHeight(), ofGetHeight());
    ofEnableAlphaBlending();
    
    // left top & right bottom
    ofSetColor(150, sinTimeReverseAlpha, sinTimeReverseAlpha, sinTimeAlpha); // bloody red
    texture.draw(ofGetWidth()/2 - ofGetHeight()/2, 0, ofGetHeight()/2, ofGetHeight()/2); // left top corner
    texture.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2, ofGetHeight()/2); // right bottom corner
    
    // left bottom & right top
    ofSetColor(sinTimeReverseAlpha * 0.6, sinTimeReverseAlpha, sinTimeReverseAlpha * 0.9, sinTimeReverseAlpha); // toned-down blue
    texture.draw(ofGetWidth()/2, 0, ofGetHeight()/2, ofGetHeight()/2); // right top corner
    texture.draw(ofGetWidth()/2 - ofGetHeight()/2, ofGetHeight()/2, ofGetHeight()/2, ofGetHeight()/2); // left bottom corner
    ofDisableAlphaBlending();
    
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
