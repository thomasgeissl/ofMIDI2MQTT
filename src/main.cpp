#include "ofAppNoWindow.h"
#include "ofApp.h"
#include "ofxCommandLineUtils.h"

// ./bin/example-commandlineargs.app/Contents/MacOS/example-commandlineargs -v -d -p 8000 -h localhost

int main(int argc, char *argv[])
{
    cxxopts::Options options("ofMIDI2MQTT", "MIDI to MQTT bridge");
    options.add_options()("d,debug", "Enable debugging")
        ("p,port", "port", cxxopts::value<int>()->default_value("1883"))
        ("h,host", "host", cxxopts::value<std::string>()->default_value("localhost"))
        ("t,topic", "topic", cxxopts::value<std::string>()->default_value("ofMIDI2MQTT"))
        ("u,user", "user", cxxopts::value<std::string>()->default_value(""))
        ("r,pass", "pass", cxxopts::value<std::string>()->default_value(""));
    //     ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
    auto result = options.parse(argc, argv);

    ofAppNoWindow window;
    ofSetupOpenGL(&window, 640, 480, OF_WINDOW);
	return ofRunApp(new ofApp(
        result["h"].as<std::string>(),
        result["p"].as<int>(),
        result["t"].as<std::string>(),
        result["u"].as<std::string>(),
        result["r"].as<std::string>()
        ));
}