#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(TRUE);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);
    
    
    a1.loadImage("a1.png");
    a2.setFromPixels(a1);
    
    b1.loadImage("b1.png");
    b2.setFromPixels(b1);
    
    c1.loadImage("c1.png");
    c2.setFromPixels(c1);
    
    d1.loadImage("d1.png");
    d2.setFromPixels(d1);
    
    e1.loadImage("e1.png");
    e2.setFromPixels(e1);
    
    speed=0.5;
    
    x1=x2=x3=x4=0;
    y1=100;
    y2=100;
    y3=100;
    y4=100;
    y5=100;
    
    imageWidth=1846;
}

//--------------------------------------------------------------
void testApp::update(){
    x1+=speed;
    x1=fmod(x1, imageWidth);
    
    x2+=speed;
    x2=fmod(x2, imageWidth);
    
    x3+=speed;
    x3=fmod(x3, imageWidth);
    
    x4+=speed;
    x4=fmod(x4, imageWidth);
    
    x5+=speed;
    x5=fmod(x5, imageWidth);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetColor(255, 255, 255, 255);
    a1.draw(x1, y1);
    a2.draw(x1-a1.getWidth(), y1);
    
    ofSetColor(255, 255, 255, 255-mouseX);
    b1.draw(x2, y2);
    b2.draw(x2-b1.getWidth(), y2);
    
    ofSetColor(255, 255, 255, mouseX-800);
    c1.draw(x3, y3);
    c2.draw(x3-c1.getWidth(), y3);
    
    ofSetColor(255, 255, 255, 255-mouseY);
    d1.draw(x4, y4);
    d2.draw(x4-d1.getWidth(), y4);
    
    //   x5=mouseX;
    ofSetColor(255, 255, 255, mouseY-600);
    e1.draw(x5, y5);
    e2.draw(x5-e2.getWidth(), y5);
    
    for (int i=0; i<12; i++) {
        
        ofSetLineWidth(2);
        
        float step=40;
        float x1=abs(i*step+300-mouseX)/100;
        
        ofSetColor(255-x1, 255-x1, 255-x1, 255-x1);
        ofCircle(i*step+300, ofGetHeight()/2+200, 6-x1);
    }
    
    ofNoFill();
	ofSetColor(255, 255, 255, 255);
    
    float tl= ofRandom(295,300);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(-ofGetElapsedTimef()/5*RAD_TO_DEG);
    
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    
    ofPushMatrix();
    ofRotateZ(-ofNoise(ofGetElapsedTimef())*20);
    ofTriangle(0, -sqrt(3)*2*tl/3, -300, sqrt(3)*100, 300, sqrt(3)*100);
    ofPopMatrix();
    
    ofPopMatrix();
    ofFill();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'w':
            speed=6;
            break;
            
        default:
            speed=0.5;
            break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //ofSetFrameRate(1);
    //ofSeedRandom(0);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
