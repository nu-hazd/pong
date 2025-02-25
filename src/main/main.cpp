#include "ofMain.h"
#include "ofApp.h"

//=======================================================================
int main() {
	ofSetupOpenGL(	// <-------- setup the GL context	
		1200, 900, 
		OF_WINDOW
	);			
	ofSetWindowTitle("Pong");
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());
}
