#include "ofApp.h"

const string kDir = "/home/david/playground/spring-2019/cs126/of-sound-demo";
const string kPianoDir = "Piano-Sounds-High-Quality-/All 88 Key Sounds EDITED (mp3)";
const double kThreshold = 0.05;

void getNote(const Note& note, ofSoundPlayer* player) {
  const string fileName = kDir + "/" + kPianoDir + "/" + note.toString(true) + ".mp3";
  player->load(fileName);
}

//--------------------------------------------------------------
void ofApp::setup() {
  noteIdx_ = 0;

  players_.resize(kNumNotes);

  for (ofSoundPlayer& player : players_) {
    player.setMultiPlay(true);
  }

  getNote(kBrokenThirdsUp[noteIdx_], &players_[0]);
}

//--------------------------------------------------------------
void ofApp::update() {
  if (noteIdx_ == 0 && !players_[0].isPlaying()) {
    players_[0].play();
  }

  if (noteIdx_ < kNumNotes - 1 && players_[noteIdx_].getPosition() > kThreshold) {
    noteIdx_++;
    getNote(kBrokenThirdsUp[noteIdx_], &players_[noteIdx_]);
    players_[noteIdx_].play();
  }

  ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
