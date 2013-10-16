#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowTitle("myLakephoto");
    
    
    ofSetVerticalSync(TRUE);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);
    
    
    pressed=false;
    
    
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
    
    sound.loadSound("A Moonlight Night.mp3");
    sound.setLoop(true);
    sound.play();
    sound.setSpeed(1);
    
    
    speed=0.5;
    //random=0;
    
    x1=x2=x3=x4=0;
    y1=100;
    
    
    imageWidth=1846;
}

//--------------------------------------------------------------
void testApp::update(){
    x1+=speed;
    x1=fmod(x1, imageWidth);
    
//    x2+=speed;
//    x2=fmod(x2, imageWidth);
//    
//    x3+=speed;
//    x3=fmod(x3, imageWidth);
//    
//    x4+=speed;
//    x4=fmod(x4, imageWidth);
//    
//    x5+=speed;
//    x5=fmod(x5, imageWidth);
    ofSoundUpdate();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Background Image..........
    
    ofSetColor(255, 255, 255, 255);
    a1.draw(x1, y1);
    a2.draw(x1-a1.getWidth(), y1);
    
    ofSetColor(255, 255, 255, 255-mouseX);
    b1.draw(x1, y1);
    b2.draw(x1-b1.getWidth(), y1);
    
    ofSetColor(255, 255, 255, mouseX-800);
    c1.draw(x1, y1);
    c2.draw(x1-c1.getWidth(), y1);
    
    ofSetColor(255, 255, 255, 255-mouseY);
    d1.draw(x1, y1);
    d2.draw(x1-d1.getWidth(), y1);
    
    ofSetColor(255, 255, 255, mouseY-600);
    e1.draw(x1, y1);
    e2.draw(x1-e2.getWidth(), y1);
    
    
    //Circles..........
    
    for (int i=0; i<12; i++) {
        
        
        float step=40;
        float x1=abs(ofGetWidth()/2-220+i*step-mouseX)/100;
        
        ofSetColor(255, 255, 255, 255-x1*40);
        ofCircle(ofGetWidth()/2-220+i*step, ofGetHeight()/2+200, 6-x1);
        
    }
    
    
    //Triangle..........
    
    ofSeedRandom();
    
    ofNoFill();
	ofSetColor(255, 255, 255, 255);
    ofSetLineWidth(2);
    tl= 300;
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(-ofGetElapsedTimef()/5*RAD_TO_DEG*(0.5+speed/6));
    
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    
    ofPushMatrix();
    ofRotateZ(-ofNoise(ofGetElapsedTimef())*20);
    ofTriangle(0, -sqrt(3)*2*tl/3, -300, sqrt(3)*100, 300, sqrt(3)*100);
    ofPopMatrix();
    
    ofPopMatrix();
    ofFill();
    
    
    //Words..........
    
    ofDrawBitmapString("f: Toggle Fullscreen", 20,ofGetHeight()-80);
    ofDrawBitmapString("w: Increase Speed", 20,ofGetHeight()-60);
    ofDrawBitmapString("s: Pause", 20,ofGetHeight()-40);
    ofDrawBitmapString("a/d: Music", 20,ofGetHeight()-20);
    
    //Sound..........
    //sound.setPaused(false);
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'w':
            if(pressed==false){
            speed=6;
            }else{
                speed=0.5;
            }
            
            pressed=!pressed;
            cout<<pressed<<endl;
            break;
        
        case 's':
            if (pressed1==false) {
                speed=0;
                sound.setPaused(true);
            }else{
                speed=0.5;
                sound.setPaused(false);
                sound.setSpeed(1);
            }
            pressed1=!pressed1;
            break;
            
        case 'a':
            if (pressed2==false) {
                sound.setSpeed(1.5);
            
            }else{
                sound.setSpeed(1);
                
            }
            pressed2=!pressed2;
            break;
            
        case 'd':
            if (pressed3==false) {
                sound.setSpeed(0.5);
            }else{
                sound.setSpeed(1);
            }
            pressed3=!pressed3;
            break;

        case 'f':
            ofToggleFullscreen();
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
