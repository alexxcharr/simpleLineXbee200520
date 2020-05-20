#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
  osc.setup(57120);
  ofSetWindowShape(1024, 720);
  ofEnableSmoothing();
  ofEnableDepthTest();
  baseNode.setPosition(0, 0, 0);
  childNode.setParent(baseNode);
  childNode.setPosition(0, 0, lineX);
  grandChildNode.setParent(childNode);
  grandChildNode.setPosition(0, 50,0);
}

//--------------------------------------------------------------
void ofApp::update(){
  while (osc.hasWaitingMessages()) {
    ofxOscMessage m;
    osc.getNextMessage(&m);
    if (m.getAddress() == "/minibee/data") {
       x = m.getArgAsFloat(1);
       y = m.getArgAsFloat(2);
       z = m.getArgAsFloat(3);
       lineX = ofMap(x, 0.2, 0.7, -512, 512);
       lineY = ofMap(y, 0, 1, -360, 360);
       lineZ = ofMap(z, 0, 1, 0, 1);
       printf("%f\n", x);
      printf("hi");
    }
  }
  baseNode.pan(1);
  childNode.tilt(3);
  // baseNode.setPosition(lineX, lineY, lineZ);
  childNode.setPosition(0, 0, lineX);
  grandChildNode.setPosition(0,lineY,0);
  // line.addVertex(ofVec3f(lineX, lineY, lineZ));
   line.addVertex(grandChildNode.getGlobalPosition());
  if (line.size() > 300){
    line.getVertices().erase(
                             line.getVertices().begin()
                             );
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  //uncomment these 3 lines to understand how nodes are moving
  baseNode.draw();
  childNode.draw();
  grandChildNode.draw();
  line.draw();
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
