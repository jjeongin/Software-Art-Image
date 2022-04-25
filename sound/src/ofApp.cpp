#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    isDrawGUI = false;
    ofBackground(0);
    ofSetFrameRate(20);
    
    sound.load("250-BangBus-edited.mp3");
    sound.play();
    
    gui.setup();
    gui.add(volume.set("volume", 0.5, 0.0, 1.0));
    gui.add(decay.set("decay", 0.1, 0.0, 1.0)); // how fast the visual will be changing
    
    tiger.load("tiger-kkachi.jpeg");
    
    ofDisableArbTex();
    ofLoadImage(danchung_texture,"danchung.jpeg");
}

//--------------------------------------------------------------
void ofApp::update(){
    // update the sound playing system:
    ofSoundUpdate();
    sound.setVolume(volume);
    
    // grab the fft, and put in into a "smoothed" array,
    // by taking maximums, as peaks and then smoothing downward
    float * val = ofSoundGetSpectrum(nBandsToGet);        // request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= decay;
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    float width = (float)(5*128) / nBandsToGet;
    float threshold = 0.6;
    
    // background
    int random = ofRandom(0,4);
    if(random == 0)
        ofSetColor(255, 0, 0, 100); //r
    else if (random == 1)
        ofSetColor(252, 186, 3, 100); //y
    else if (random == 2)
        ofSetColor(5, 158, 0, 100); //g
    else
        ofSetColor(255, 255, 255);
    tiger.draw(0, 0, 0, ofGetWidth(), ofGetHeight());
    
    
//    ofLog(OF_LOG_NOTICE, ofToString(ofGetWidth()) + ofToString(ofGetHeight())); // to check window size
    
    for (int i = 0; i < nBandsToGet; i++) {
//        if (fftSmoothed[i] < threshold) {
////            danchung_texture.bind();
//
////            ofSetColor(255, 0, 212);
////            box.setPosition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(0, 255));
////            box.set(fftSmoothed[i] * 200, fftSmoothed[i] * 200, fftSmoothed[i] * 200);
////            box.draw();
//
////            danchung_texture.unbind();
//        }
//        else {
////            int random = ofRandom(0,3);
////            if(random == 0)
////                ofSetColor(255, 0, 0, 100);
////            else if (random == 1)
////                ofSetColor(252, 186, 3, 100);
////            else
////                ofSetColor(252, 186, 3, 100);
//        }
        ofSetColor(230, 230, 230);
        danchung_texture.bind();
        sphere.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
        sphere.setResolution(fftSmoothed[i]*50);
        sphere.rotate(mouseX, 1.0, 0.0, 0.0);
        sphere.rotate(mouseY, 0, 1.0, 0.0);
        sphere.setRadius(fftSmoothed[i] * 300);
        sphere.draw();
        danchung_texture.unbind();
    }
    
//    gui.draw();
    if (isDrawGUI) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        // display gui
        isDrawGUI = !isDrawGUI;
    }
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
