#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(ofColor(34, 107, 126));
    
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
    
    // gui
    showGui = true;
    allChannelsOnButton.addListener(this, &ofApp::allChannelsOnButtonPressed);
    allChannelsOffButton.addListener(this, &ofApp::allChannelsOffButtonPressed);
    gui.setup();
    gui.add(enableChannel1.set("Enable channel 1", false));
    gui.add(channel1.set("Channel 1", 127, 0, 255));
    gui.add(enableChannel2.set("Enable channel 2", false));
    gui.add(channel2.set("Channel 2", 127, 0, 255));
    gui.add(enableChannel3.set("Enable channel 3", false));
    gui.add(channel3.set("Channel 3", 127, 0, 255));
    gui.add(enableChannel4.set("Enable channel 4", false));
    gui.add(channel4.set("Channel 4", 127, 0, 255));
    gui.add(allChannelsOnButton.setup("All channels ON"));
    gui.add(allChannelsOffButton.setup("All channels OFF"));
    
    // dmx
    dmx.connect("tty.usbserial-ENY46L4I"); // use the name
    //dmx.connect(0); // or use a number
    
    // easing
    unsigned delay = 1000;
    unsigned duration = 2000;
    tween.setParameters(1, easingSine, ofxTween::easeInOut, 0, 255, duration, delay);
}

void ofApp::allChannelsOnButtonPressed(){
    enableChannel1.set(true);
    enableChannel2.set(true);
    enableChannel3.set(true);
    enableChannel4.set(true);
}

void ofApp::allChannelsOffButtonPressed(){
    enableChannel1.set(false);
    enableChannel2.set(false);
    enableChannel3.set(false);
    enableChannel4.set(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    channel1.set(tween.update());
    
    // dmx
    if (enableChannel1.get()) {
        dmx.setLevel(1, channel1);
    }else{
        dmx.setLevel(1, 0);
    }
    if (enableChannel2.get()) {
        dmx.setLevel(2, channel2);
    }else{
        dmx.setLevel(2, 0);
    }
    if (enableChannel3.get()) {
        dmx.setLevel(3, channel3);
    }else{
        dmx.setLevel(3, 0);
    }
    if (enableChannel4.get()) {
        dmx.setLevel(4, channel4);
    }else{
        dmx.setLevel(4, 0);
    }
    dmx.update();
    
    if (ofGetFrameNum() % 600 == 0){
        doEase(3000, 0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // gui
    if (showGui) gui.draw();
    
    // tween
    ofSetColor(ofColor::white);
//    ofRect(0, ofGetHeight()/2.0, tween.update(), 30);
    ofLogNotice(ofToString(tween.update()));
    ofLogNotice("0::::"+ofToString(tween.getTarget(0)));
    ofLogNotice("1::::"+ofToString(tween.getTarget(1)));
    
    // debug
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));
}

void ofApp::doEase(unsigned duration, unsigned delay){
    if (channel1 == 0) {
        // ease in
        tween.setParameters(1, easingSine, ofxTween::easeIn, 0, 255, duration, delay);
    }
    if (channel1 == 255) {
        tween.setParameters(1, easingSine, ofxTween::easeIn, 255, 0, duration, delay);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'd':
            // draw debug or disable to draw debug
            enableDebugDraw = !enableDebugDraw;
            break;
        case 'f':
            // full screen or disable full screnn
            ofToggleFullscreen();
            break;
        case 'h':
            // show or hide gui
            showGui = !showGui;
            break;
        case 'l':
            // load gui setting data
            gui.loadFromFile("settings.xml");
            
            break;
        case 's':
            // save gui setting
            gui.saveToFile("settings.xml");
            break;
            
        case 'i':{
            unsigned delay = 0;
            unsigned duration = 2000;
            tween.setParameters(1, easingSine, ofxTween::easeIn, 0, 255, duration, delay);
        }
            break;
        case 'o':{
            unsigned delay = 0;
            unsigned duration = 2000;
            tween.setParameters(1, easingSine, ofxTween::easeIn, 255, 0, duration, delay);
        }
            break;
        default:
            break;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
