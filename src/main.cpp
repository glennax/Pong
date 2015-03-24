#line 1 "Pong"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "Pong"
float width = 500;
float height = 500;
float radius = 20;
ofVec2f pos = ofVec2f(width/2, height/2); 
ofVec2f vel = ofVec2f(3, 3);

void setup() {

	ofSetWindowShape(width, height);
	
}

void draw() {
    ofPoint rectloc1 = ofPoint(0, ofGetMouseY());
    ofPoint rectloc2 = ofPoint(490, ofGetMouseY());
    ofRect(rectloc1, 10, 100);
    ofRect(rectloc2, 10, 100);

    ofCircle(pos.x, pos.y, radius);
    pos+=vel;
    if( (pos.x - rectloc1.x <= radius + 10 || rectloc2.x - pos.x <= radius) && (pos.y >= rectloc1.y && pos.y <= 100 + rectloc1.y ) ) {
        vel.x*=-1;
       // std::cout << pos.y<< std::endl;
    }
    else if((pos.x <= -radius || pos.x >= width + radius ) && (pos.y < rectloc1.y || pos.y > rectloc1.y + 100)){
       //std::cout << "reset"<< std::endl;
        pos = ofVec2f(width/2,height/2); 
       }
    
    if(pos.y > width - radius || pos.y < radius) {
        vel.y*=-1;    
    }
    

}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

