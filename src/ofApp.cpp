#include "ofApp.h"

ofApp::ofApp(std::string host, int port, std::string topic, std::string username, std::string password) : 
    _host(host), _port(port), _topic(topic), _username(username), _password(password) {}
void ofApp::setup(){
    ofSetFrameRate(60);
    _midiIn.addListener(this);
    _midiIn.ignoreTypes(true, true, true);
    _midiIn.openVirtualPort("ofMIDI2MQTT");
    _iac.addListener(this);
    for(auto & port : _iac.getInPortList()){
        if (port.find("IAC") != std::string::npos) {
            _iac.ignoreTypes(true, true, true);
            _iac.openPort(port);
        }
    }


    _mqtt.begin(_host, _port);
    std::string name = "ofMIDI2MQTT_";
    name += ofToString(ofRandom(1024));
    _mqtt.connect(name, _username, _password);

    ofAddListener(_mqtt.onOnline, this, &ofApp::onOnline);
    ofAddListener(_mqtt.onOffline, this, &ofApp::onOffline);
    ofAddListener(_mqtt.onMessage, this, &ofApp::onMessage);
}
void ofApp::update(){
    _mqtt.update();
    while(_messages.size()){
        auto message = _messages.back();
        _messages.pop_back();
        ofLogNotice() << _topic << " " << message;
        _mqtt.publish(_topic, message);
    }
}

void ofApp::newMidiMessage(ofxMidiMessage & message){
    ofJson payload;
    payload["channel"] = message.channel;
    payload["status"] = message.status;
    payload["deltaTime"] = message.deltatime;
    // TODO: should bytes be always sent or just for sysex
    payload["bytes"] = message.bytes;
    // TODO: if noteon, notoff
    payload["note"] = message.pitch;
    payload["velocity"] = message.velocity;
    // TODO: if cc, pc
    payload["control"] = message.control;
    payload["value"] = message.value;
    _messages.push_back(payload.dump());
}
void ofApp::onOnline(){}
void ofApp::onOffline(){}
void ofApp::onMessage(ofxMQTTMessage &msg){}
