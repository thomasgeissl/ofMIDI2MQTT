#include "ofApp.h"
#include "ofxCommandLineUtils.h"

// ./bin/example-commandlineargs.app/Contents/MacOS/example-commandlineargs -v -d -p 8000 -h localhost

int main(int argc, char *argv[])
{
    // cxxopts::Options options("example-commandlineargs", "example application to demonstrate how ot use cxxopts");
    // options.add_options()("d,debug", "Enable debugging")
    //     ("p,port", "port", cxxopts::value<int>()->default_value("1883"))
    //     ("h,host", "host", cxxopts::value<std::string>()->default_value("localhost"))
    //     ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
    // auto result = options.parse(argc, argv);
    // auto port = result["p"].as<int>();
    // auto host = result["h"].as<int>();

    ofSetupOpenGL(640, 480, OF_WINDOW);
	return ofRunApp(new ofApp());
}