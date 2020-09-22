#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxMQTT.h"

class ofApp : public ofBaseApp, ofxMidiListener{
	public:
        ofApp(std::string host, int port, std::string topic);
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void newMidiMessage(ofxMidiMessage & message);

        void onOnline();
        void onOffline();
        void onMessage(ofxMQTTMessage &msg);

        ofxMQTT _mqtt;
        ofxMidiIn _midiIn;
        ofxMidiIn _iac;

        std::string _host;
        int _port;
        std::string _topic;
};
