#pragma once

#include "ofMain.h"
#include "ofxImageSequence.h"


class testApp : public ofBaseApp{
    
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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;
    
    ofSoundPlayer sound;
    bool pressed,pressed1,pressed2,pressed3;
    float x1,x2,x3,x4,x5,y1,imageWidth,speed,tl;
};

