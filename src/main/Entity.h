#pragma once
#include "ofMain.h"

class Entity {
    private:
        int posX;
        int posY;
        int speedX;
        int speedY;
        int height;
        int width;
        ofColor color;
    public:
        Entity(){}; // Default constructor
        Entity(int pX, int pY, int h, int w, ofColor c) {
            this->posX = pX;
            this->posY = pY;
            this->height = h;
            this->width = w;
            this->color = c;
            this->speedX = 0;
            this->speedY = 0;
    }

        // Getters
        int getPosX() { return posX; }
        int getPosY() { return posY; }
        int getSpeedX() { return speedX; }
        int getSpeedY() { return speedY; }
        int getHeight() { return height; }
        int getWidth() { return width; }
        ofColor getColor() { return color; }
        // Setters
        void setPosX(int pX) { posX = pX; }
        void setPosY(int pY) { posY = pY; }
        void setSpeedX(int sX) { speedX = sX; }
        void setSpeedY(int sY) { speedY = sY; }
        void setHeight(int h) { height = h; }
        void setWidth(int w) { width = w; }
        void setColor(ofColor c) { color = c; }

        // Collision detection
        bool collidesWith(ofRectangle projection) {return projection.intersects(ofRectangle(posX+speedX,posY+speedY,width,height)); }
        // Update
        void update() {
            posX += speedX;
            posY += speedY;
        }
        // Draws the entity
        void draw() {
            ofSetColor(color);
            ofDrawRectangle(posX, posY, width, height);
            // Reset color
            ofSetColor(ofColor::white);
        }
        // Converts the entity to a rectangle to check collisions
        // Allows for the use of the intersects(Entity).
        operator ofRectangle() const {
            return ofRectangle(posX, posY, width, height);
        }
};