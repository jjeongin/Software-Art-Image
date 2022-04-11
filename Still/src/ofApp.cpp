#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    isDrawGUI = false;
    ofSetBackgroundColor(255);
    
    // default colors
    ofColor defaultColor1(255, 173, 232); // 255, 196, 239 // pink
    ofColor defaultColor2(196, 255, 200); // green
    ofColor defaultColor3(255, 247, 196); // yellow
    
    // GUI
    gui.setup();
//    gui.add(layers.setup("Layers", ofRandom(10, 20), 10, 20));
    gui.add(c1.setup("Color 1",
                            defaultColor1,
                            ofColor(0, 0),
                            ofColor(255, 255)));
    gui.add(c2.setup("Color 2",
                            defaultColor2,
                            ofColor(0, 0),
                            ofColor(255, 255)));
    gui.add(c3.setup("Color 3",
                            defaultColor3,
                            ofColor(0, 0),
                            ofColor(255, 255)));
    
    // global variables
    layers = ofRandom(10, 20);
    minRadius = ofGetWidth() / 50;
    maxRadius = ofGetWidth() / 5;
    minAngle = 30.0;
    numPetals = ofRandom(40);
    
    // create basic petals
    for (int i = 0; i < numPetals; i++) {
        Petal petal;
        petal.c = ofRandom(0,3); // select one of the colors in color scheme
        petal.p1.x = ofRandom(ofGetWidth());
        petal.p1.y = ofRandom(ofGetHeight());
        petal.radius = ofRandom(minRadius, maxRadius);
        petal.angleStep = ofMap(petal.radius, minRadius, maxRadius, 0.5, 3); // speed to increase the angle of each line
        petal.startAngle = ofRandom(ofDegToRad(360.0)); // angle to start drawing petal
        petal.endAngle = ofRandom(petal.startAngle + ofDegToRad(minAngle), petal.startAngle + ofDegToRad(180.0)); // angle to stop drawing petal
        petals.push_back(petal); // add to the vector
    }
    
    // add new layers of petal on top of the basic layer
    for (int i = 0; i < layers; i++) {
        for (auto petal : petals) {
            int drawOrNot = ofRandom(0, 2); // randomly choose if new petal to be drawn
            if (drawOrNot < 1) {
                Petal newPetal;
                newPetal.c = ofRandom(0,3); // select random color
                newPetal.p1.x = petal.p1.x; // same center point as the basic layer
                newPetal.p1.y = petal.p1.y;

                newPetal.radius = ofRandom(minRadius, maxRadius);
                newPetal.angleStep = ofMap(petal.radius, minRadius, maxRadius, 0.5, 3);
                newPetal.startAngle = ofRandom(ofDegToRad(360.0));
                newPetal.endAngle = ofRandom(petal.startAngle + ofDegToRad(minAngle), petal.startAngle + ofDegToRad(180.0));
                petals.push_back(newPetal);

                // experiment
    //            newPetal.radius = petal.radius / ofRandom(2, 4);
    //            newPetal.startAngle = petal.endAngle;
    //            newPetal.endAngle = ofRandom(newPetal.startAngle + ofDegToRad(minAngle), MIN(newPetal.startAngle + ofDegToRad(180.0), 360.0));
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw all the existing petals
    for (auto petal : petals) {
        for (float a = petal.startAngle; a < petal.endAngle; a += ofDegToRad(petal.angleStep)) { // rotate
            float alpha = ofMap(petal.radius, minRadius, maxRadius, 0, 50); // longer line more opaque
            ofSetColor(c1, alpha); // set color
            if (petal.c < 1)
                ofSetColor(c2, alpha);
            else if (petal.c < 2)
                ofSetColor(c3, alpha);
            
            petal.p2.x = petal.p1.x + cos(a) * petal.radius; // second point
            petal.p2.y = petal.p1.y - sin(a) * petal.radius;
            ofDrawLine(petal.p1, petal.p2);
        }
    }
    
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
    else if (key == 's') {
        // screenshot
        string filename = ofGetTimestampString("screenshot-%Y%m%d-%H%M%S-%i.png");
        screenImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenImage.save(filename);
    }
    else if (key == 'f') {
        // fullscreen
         ofToggleFullscreen();
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
