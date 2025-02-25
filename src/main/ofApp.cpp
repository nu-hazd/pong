#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);
    ofSetRandomSeed(ofGetElapsedTimeMillis());  // Random seed

    this->pongFont.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/pong/bin/Assets/pongFont.ttf", 200);
    this->ball = Entity(600, 450, 20, 20, ofColor::white);
    this->verticalWalls.push_back(Entity(0, 0, 900, 10, ofColor::paleVioletRed));
    this->verticalWalls.push_back(Entity(1190, 0, 900, 10, ofColor::skyBlue));
    this->horizontalWalls.push_back(Entity(0, 0, 10, 1200, ofColor::purple));
    this->horizontalWalls.push_back(Entity(0, 890, 10, 1200, ofColor::purple));
    this->paddles.push_back(Entity(20, 450, 100, 20, ofColor::white));
    this->paddles.push_back(Entity(1160, 450, 100, 20, ofColor::white));
    ofSetRandomSeed(ofGetElapsedTimeMillis());
    this->ball.setSpeedX(5);
    this->ball.setSpeedY(1);
}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::update() {
    for (Entity& wall : horizontalWalls) { 
        if (ball.collidesWith(wall)) ball.setSpeedY(-ball.getSpeedY()); 
        wall.update();
        }
    for (Entity& paddle : paddles) { 
        if (ball.collidesWith(paddle)) ball.setSpeedX(-ball.getSpeedX()); 
        // Check if the paddle collides with the wall after projecting the paddle's next position FIX
        // if (paddle.collidesWith(ofRectangle(horizontalWalls[0].getPosX()+horizontalWalls[0].getSpeedX(),horizontalWalls[0].getPosY()+horizontalWalls[0].getPosY(),horizontalWalls[0].getWidth(),horizontalWalls[0].getHeight())) || paddle.collidesWith(ofRectangle(horizontalWalls[1].getPosX()+horizontalWalls[1].getSpeedX(),horizontalWalls[1].getPosY()+horizontalWalls[1].getPosY(),horizontalWalls[1].getWidth(),horizontalWalls[1].getHeight()))) {
        //     paddle.setSpeedY(0);
        // } 
        if (paddle.getPosY()-6 <= 0 || paddle.getPosY()+10 >= 800) paddle.setSpeedY(0);
        paddle.update();
        }
    for (unsigned int i =0; i < verticalWalls.size(); i++) {
        if (ball.collidesWith(verticalWalls[i])) {
            ball.setSpeedX(-ball.getSpeedX());
            i == 0 ? playerTwoScore++ : playerOneScore++;
        }
        horizontalWalls[i].update();
    }
    
    ball.update();
 }
void ofApp::draw() {
    for (Entity& wall : verticalWalls) {wall.draw();}
    for (Entity& wall : horizontalWalls) { wall.draw(); }
    for (Entity& paddle : paddles) { paddle.draw();}
    ball.draw();
    ofSetColor(105,105,105,125);
    if (playerOneScore >= 10) { pongFont.drawString(to_string(playerOneScore), 100, 500);}
    else {pongFont.drawString(to_string(playerOneScore), 200, 500);}
    if (playerTwoScore >= 10) { pongFont.drawString(to_string(playerTwoScore), 700, 500);}
    else {pongFont.drawString(to_string(playerTwoScore), 800, 500);}
    ofSetColor(ofColor::white);
}
void ofApp::keyPressed(int key) {
    if (key == 'w' || key == 'W')  paddles[0].setSpeedY(-5); 
    if (key == 's'|| key == 'S')   paddles[0].setSpeedY(5);
    if (key == 'i'|| key == 'I')   paddles[1].setSpeedY(-5);
    if (key == 'k'|| key == 'K')   paddles[1].setSpeedY(5);
 }
void ofApp::keyReleased(int key) {
    if (key == 'w' || key == 'W')  paddles[0].setSpeedY(0);
    if (key == 's'|| key == 'S')   paddles[0].setSpeedY(0);
    if (key == 'i'|| key == 'I')   paddles[1].setSpeedY(0);
    if (key == 'k'|| key == 'K')   paddles[1].setSpeedY(0);
}

void ofApp::mouseMoved(int x, int y) {  }
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}
void ofApp::windowResized(int w, int h) {}
void ofApp::gotMessage(ofMessage msg) {}
void ofApp::dragEvent(ofDragInfo dragInfo) {}