/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxGui.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		MAIN_WINDOW_W = 1280,
		MAIN_WINDOW_H = 720,
	};
	enum{
		NUM_FBOS = 5,
	};
	
	/****************************************
	****************************************/
	ofxPanel gui;
	ofxFloatSlider FboId_update;
	ofxFloatSlider FboId_draw;
	ofxToggle b_Assign;
	
	ofFbo fbo[NUM_FBOS];
	ofFbo fbo_temp;
	
	
	/****************************************
	****************************************/
	void ClearFbo(ofFbo& fbo);
	void draw_circle(ofFbo& fbo);
	void print_info();
	
public:
	/****************************************
	****************************************/
	ofApp();
	~ofApp();
	void exit();
	
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
	
};
