/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(){
}

/******************************
******************************/
ofApp::~ofApp(){
}

/******************************
******************************/
void ofApp::exit(){

}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("fbo test");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MAIN_WINDOW_W, MAIN_WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	gui.setup();
	gui.add(FboId_update.setup("FboId_update", 0, 0, NUM_FBOS - 1));
	gui.add(FboId_draw.setup("FboId_draw", 0, 0, NUM_FBOS - 1));
	gui.add(b_Assign.setup("b_Assign", false));
	
	/********************
	********************/
	ofSetCircleResolution(40); // default = 22.
	
	/********************
	********************/
	print_info();
	
	for(int i = 0; i < NUM_FBOS; i++){
		fbo[i].allocate(MAIN_WINDOW_W, MAIN_WINDOW_H, GL_RGBA);
		ClearFbo(fbo[0]);
	}
	
	// fbo[1] = fbo[0];
	
	print_info();
}

/******************************
******************************/
void ofApp::print_info()
{
	printf("\n------------------------------\n");
	
	for(int i = 0; i < NUM_FBOS; i++){
		printf( "[%d]\n", i );
		printf( "\t&fbo              : %p\n", &fbo[i] );
		printf( "\t&fbo.getTexture() : %p\n", &(fbo[i].getTexture()) );
		printf( "\tfbo.getId()       : %d\n", fbo[i].getId() );
	}
	
	if(fbo_temp.isAllocated()){
		printf( "[fbp_temp]\n");
		printf( "\t&fbo              : %p\n", &fbo_temp );
		printf( "\t&fbo.getTexture() : %p\n", &(fbo_temp.getTexture()) );
		printf( "\tfbo.getId()       : %d\n", fbo_temp.getId() );
	}
	
	fflush(stdout);
}

/******************************
******************************/
void ofApp::ClearFbo(ofFbo& fbo)
{
	fbo.begin();
		ofBackground(0, 0, 0, 255);
	fbo.end();
}

/******************************
******************************/
void ofApp::update(){
	/********************
	********************/
	if(b_Assign){
		b_Assign = false;
		fbo[int(FboId_draw)] = fbo[int(FboId_update)];
		
		fbo_temp.allocate(MAIN_WINDOW_W, MAIN_WINDOW_H, GL_RGBA);
		print_info();
	}
	
	/********************
	********************/
	for(int i = 0; i < NUM_FBOS; i++){
		ClearFbo(fbo[i]);
	}
	
	/********************
	********************/
	draw_circle( fbo[int(FboId_update)] );
}

/******************************
******************************/
void ofApp::draw_circle(ofFbo& fbo){
	int now = ofGetElapsedTimeMillis();
	float r = 25 * sin(2 * 3.14 / 6000 * now) + 75; // 50 - 100.
	
	fbo.begin();
		ofBackground(0, 0, 0, 255);
		
		ofSetColor(255, 0, 0, 255);
		ofDrawCircle(fbo.getWidth()/2, fbo.getHeight()/2, r);
	fbo.end();
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(0, 0, 0, 255);
	fbo[int(FboId_draw)].draw(0, 0);
	
	gui.draw();
}

/******************************
******************************/
void ofApp::keyPressed(int key){
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
