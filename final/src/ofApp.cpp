#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    isDrawGUI = false;
    ofSetBackgroundColor(0);
    ofEnableDepthTest();
    
    webcam.setup(ofGetWidth(), ofGetHeight());
    //store the width and height for convenience
    int width = webcam.getWidth();
    int height = webcam.getHeight();
    
    //add one vertex to the mesh for each pixel
    camMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            camMesh.addVertex(glm::vec3(x,y,0));    // mesh index = x + y*width
                                                // this replicates the pixel array within the camera bitmap...
            camMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
        }
    }
    
    // avatar
    avatar.loadModel("LowPoly-Characters.fbx");
    
    // shader
//    isShader = false;
    
//    shader.load("shadersES2/shader");
//    #ifdef TARGET_OPENGLES
//        shader.load("shadersES2/shader");
//    #else
//        if(ofIsGLProgrammableRenderer()){
//            shader.load("shadersGL3/shader");
//        }else{
//            shader.load("shadersGL2/shader");
//        }
//    #endif
    
    
    // GUI
    gui.setup();
//    gui.add(uiPosition.set("position", ofVec3f(0, 0, 0), ofVec3f(-300, -300, -300), ofVec3f(300, 300, 300)));
//    gui.add(c1.setup("Color",
//                            255,
//                            ofColor(0, 0),
//                            ofColor(255, 255)));
    gui.add(label.setup("Mode", "Select mode"));
    gui.add(isLine.setup("Plane", false));
    gui.add(isSphere.setup("Sphere", true));
    
    gui.add(label2.setup("Textile", "Select textile"));
    gui.add(isAnimal.setup("Furry", false));
    gui.add(isMetal.setup("Glossy", false));
    gui.add(isWater.setup("Watery", false));
    gui.add(isSpace.setup("Milky Way", false));
    
    ofDisableArbTex();
    silver.load("textile/glossy-2.jpeg");
    animal.load("textile/leopard-f.jpeg");
    water.load("textile/wave2.jpeg");
    space.load("textile/milky-2.jpeg");
    
    silver.resize(10, 10);
    animal.resize(20, 20);
    water.resize(100, 100);
    space.resize(50, 50);
    
    texture.generateMipmap();
//    texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
//    texture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    
//    ofLoadImage(silver,"textile/silver2.jpeg");
//    ofLoadImage(animal,"textile/leopard-f.jpeg");
//    ofLoadImage(water,"textile/wave2.jpeg");
//    ofLoadImage(space,"textile/milky-2.jpeg");
    
    
    // set mesh mode
    mesh.setMode(OF_PRIMITIVE_LINES);
    sphere_mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    // create sphere mesh
    // sphere mesh code from https://github.com/alptugan/3D-Studies-with-openFrameworks/tree/master/3_generate3DSphereMeshPoints
    for (int i= 0; i < total; i++) {
        float lat = ofMap(i,0,total-1,0.0,PI);
        for (int j= 0; j<total; j++) {
            float lon = ofMap(j,0,total-1,0.0,TWO_PI);
            float x = (radius*1.3) * sin(lat) * cos(lon) + ofGetWidth()/4;
            float y = (radius*2.2) * sin(lat) * sin(lon) + ofGetHeight()/2;
            float z = radius * cos(lat);
            
            sphere_mesh.addVertex(ofVec3f(x,y,z));
        }
    }
    
    for (int j = 0; j < total - 1; j++) {
        for (int i = 0 ; i < total - 1 ; i++) {
            sphere_mesh.addIndex(i+j*total);         // 0
            sphere_mesh.addIndex((i+1)+j*total);     // 1
            sphere_mesh.addIndex(i+(j+1)*total);     // 6

            sphere_mesh.addIndex((i+1)+j*total);     // 1
            sphere_mesh.addIndex((i+1)+(j+1)*total); // 7
            sphere_mesh.addIndex(i+(j+1)*total);     // 6
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
    
//    light.setPosition(uiPosition->x, uiPosition->y, uiPosition->z);
    light.setPosition(30, -190, -300); // x = -55
    
    // 3d graphic rotation
    rotateY++;
    
    if(isAnimal)
        texture = animal.getTexture();
    else if(isMetal)
        texture = silver.getTexture();
    else if(isWater)
        texture = water.getTexture();
    else if(isSpace)
        texture = space.getTexture();
        
    
    // update mesh with new points
    int i = 0;
    int num_points = points.size();
    
    if (num_points >= 2) {
        if (isLine) {
            for(auto p : points) {
//                ofLog(OF_LOG_NOTICE, "p " + ofToString(i) + ": " + ofToString(p.x) + ", " + ofToString(p.y) + ", " + ofToString(p.z)); // TEST
                
//                p.z = i
                mesh.addVertex(p); // make a new vertex
                // COLOR
    //            mesh.setColor(i, c1);  // add a color at that vertex
//                mesh.addColor(c1);
                i++;
            }
            
            
        }
        else if (isSphere) {
            for (auto p : points) {
//                ofLog(OF_LOG_NOTICE, "p " + ofToString(i) + ": " + ofToString(p.x) + ", " + ofToString(p.y) + ", " + ofToString(p.z)); // TEST
                
                
                sphere_mesh.setVertex(sphere_rand_vertex, p);
                i++;
            }
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    webcam.draw(0,0);
    ofFill();
    ofSetColor(255);
    ofDrawBitmapString("Click the screen to design your Meta-clothes : " + ofToString(points.size()) + "/10", ofGetWidth()/3, ofGetHeight()/8*7);
    
    if (points.size() == 10) {
        webcam.draw(0,0);
        
        ofDrawBitmapString("Try it on in the real world !" + ofToString(points.size()) + "/10", ofGetWidth()/3, ofGetHeight()/8*1);
        
        texture.bind();
        
        light.enable();
        // 3d demo on webcam
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateY(rotateY);
        ofTranslate(-ofGetWidth()/6, -ofGetHeight()/2);
        if (isLine) {
            ofBeginShape();
            for (auto p : points) {
                ofVertex(p.x, p.y, p.z);
            }
            ofEndShape();
        }
        else if (isSphere) {
            sphere_mesh.draw();
        }
        ofPopMatrix();
        light.disable();
        
        texture.unbind();
    }
    else {
        light.enable();
        
        avatar.enableColors();
        ofFill();
        ofSetColor(100, 233, 237); // avatar color
        avatar.setScale(1.3, 1.3, 1.3);
        avatar.setPosition(ofGetWidth()/4, ofGetHeight() - 70, 0);
        
        avatar.drawFaces();
        
        ofFill();
        ofSetColor(255); // pointer color
        ofDrawCircle(mouseX, mouseY, 2); // pointer
        
        texture.bind();
//        texture.draw(0,0,0);
        
        // draw wireframe on left
        if (isLine) {
            mesh.drawWireframe();
        }
        else if (isSphere) {
            sphere_mesh.drawWireframe();
        }
            
        // 3d demo on right
        ofPushMatrix();
        ofTranslate(ofGetWidth()/4 * 3, ofGetHeight()/2);
        ofRotateY(rotateY);
        ofTranslate(-ofGetWidth()/4 * 1, -ofGetHeight()/2);
        if (isLine) {
//            mesh.draw();
            ofBeginShape();
            for (auto p : points) {
                ofVertex(p.x, p.y, p.z);
            }
            ofEndShape();
        }
        else if (isSphere) {
            sphere_mesh.draw();
        }
        ofPopMatrix();
        
        texture.unbind();
        
        
        light.disable();
        ofDisableLighting();
        ofDisableDepthTest();
        if (isDrawGUI) {
            gui.draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if (key == "g") {
//        // display gui
//        isDrawGUI = !isDrawGUI;
//    }
    isDrawGUI = !isDrawGUI;
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
    // Plot points
    ofPoint p;
    p.x = mouseX;
    p.y = mouseY;
    p.z = ofRandom(122, 255);
    

    points.push_back(p);
    
    // for sphere
    sphere_rand_vertex = ofRandom(0, sphere_mesh.getNumVertices());
    
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
