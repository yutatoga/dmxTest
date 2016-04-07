#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDmx.h"
#include "ofxTween.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void allChannelsOnButtonPressed();
    void allChannelsOffButtonPressed();
    void doEase(unsigned duration, unsigned delay);
    
    // gui
    ofxPanel gui;
    bool showGui;
    ofParameter<bool> enableChannel1;
    ofParameter<int> channel1;
    ofParameter<bool> enableChannel2;
    ofParameter<int> channel2;
    ofParameter<bool> enableChannel3;
    ofParameter<int> channel3;
    ofParameter<bool> enableChannel4;
    ofParameter<int> channel4;
    ofxButton allChannelsOnButton;
    ofxButton allChannelsOffButton;
    
    // dmx
    ofxDmx dmx;
    
    // tween
    ofxTween tween;
    ofxEasingSine easingSine;
    
    // debug
    bool enableDebugDraw;
    
};
