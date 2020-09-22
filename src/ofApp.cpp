#include "ofApp.h"

void ofApp::setup(){
    _midiIn.addListener(this);
    _midiIn.openVirtualPort("ofMIDI2MQTT");
    _iac.addListener(this);
    for(auto & port : _iac.getInPortList()){
        if (port.find("IAC") != std::string::npos) {
            _iac.openPort(port);
        }
    }


    _mqtt.begin("broker.shiftr.io", 1883);
    _mqtt.connect("openframeworks", "try", "try");

    ofAddListener(_mqtt.onOnline, this, &ofApp::onOnline);
    ofAddListener(_mqtt.onOffline, this, &ofApp::onOffline);
    ofAddListener(_mqtt.onMessage, this, &ofApp::onMessage);
}
void ofApp::update(){
    _mqtt.update();
}
void ofApp::draw(){}
void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}

void ofApp::newMidiMessage(ofxMidiMessage & message){
    ofLogNotice() << "new midi message";
    // TODO: send mqtt message
}
void ofApp::onOnline(){}
void ofApp::onOffline(){}
void ofApp::onMessage(ofxMQTTMessage &msg){}
