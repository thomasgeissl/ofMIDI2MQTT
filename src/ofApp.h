#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxMQTT.h"

class ofApp : public ofBaseApp, ofxMidiListener{
	public:
        ofApp(std::string host, int port, std::string topic, std::string username = "", std::string password = "");
		void setup();
		void update();

        void newMidiMessage(ofxMidiMessage & message);

        void onOnline();
        void onOffline();
        void onMessage(ofxMQTTMessage &msg);

        ofxMQTT _mqtt;
        ofxMidiIn _midiIn;
        ofxMidiIn _iac;
    
        std::vector<std::string> _messages;

        std::string _host;
        int _port;
        std::string _topic;
        std::string _username;
        std::string _password;
};
