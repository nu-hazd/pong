#pragma once
#include "ofMain.h"
#include <iostream>
#include "Entity.h"
using namespace std;

/**
 * @class ofApp
 * @brief Main application class for the game.
 */
class ofApp : public ofBaseApp {
    public:
        // Variables
        Entity ball;
        vector<Entity> paddles;
        vector<Entity> verticalWalls;
        vector<Entity> horizontalWalls;
        int playerOneScore;
        int playerTwoScore;
        ofTrueTypeFont pongFont;

        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void keyReleased(int key);



        //--UNUSED--//
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void mouseDragged(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
};
