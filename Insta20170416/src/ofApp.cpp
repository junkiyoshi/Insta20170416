#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	ofSetFrameRate(30);
	ofSetWindowTitle("NoiseBox");

	this->x_noise = ofRandom(10.0);
	this->y_noise = ofRandom(10.0);
	this->z_noise = ofRandom(10.0);
	
	for (int x = 0; x < this->x_len; x++) {
		for (int y = 0; y < this->x_len; y++) {
			for (int z = 0; z < this->z_len; z++) {
				locations[x][y][z] = ofVec3f(x * this->box_size + this->box_size / 2 - ofGetWidth() / 2, y * this->box_size + this->box_size / 2 - ofGetHeight() / 2, z * this->box_size + this->box_size / 2 - ofGetWidth() / 2);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();

	float tmp_x_noise = x_noise;
	float tmp_y_noise = y_noise;
	float tmp_z_noise = z_noise;
	float noise_value = 0.1;

	for (int x = 0; x < this->x_len; x++) {

		tmp_x_noise += noise_value;
		tmp_y_noise = y_noise;
		for (int y = 0; y < this->y_len; y++) {

			tmp_y_noise += noise_value;
			tmp_z_noise = z_noise;
			for (int z = 0; z < this->z_len; z++) {

				if ((x == 0 || x == this->x_len - 1) || (y == 0 || y == this->y_len -1)){
					ofVec3f location = this->locations[x][y][z];

					ofColor body_color;
					body_color.setHsb(ofNoise(tmp_x_noise, tmp_y_noise, tmp_z_noise) * 255, 255, 255);
					ofSetColor(body_color);

					ofPushMatrix();
					ofTranslate(location);
					ofBoxPrimitive box;
					box.set(this->box_size * 0.85);
					box.draw();
					ofPopMatrix();
				}

				tmp_z_noise += noise_value;
			}
		}
	}

	this->x_noise += noise_value;
	this->y_noise += noise_value;
	this->z_noise += noise_value;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
