#pragma once

#include "ofMain.h"

struct Note {
  const string name;
  const int octave;
  const double length;

  Note(const string& name, const int octave, const double length) :
    name(name), octave(octave), length(length) { }

  string toString(const bool edited) const {
    stringstream ss;
    if (!edited) {
      ss << name << octave;
      return ss.str();
    }

    int number = 0;
    if (name == "A") number = 0;
    if (name == "Bb") number = 1;
    if (name == "B") number = 2;
    if (name == "C") number = 3;
    if (name == "Db") number = 4;
    if (name == "D") number = 5;
    if (name == "Eb") number = 6;
    if (name == "E") number = 7;
    if (name == "F") number = 8;
    if (name == "Gb") number = 9;
    if (name == "G") number = 10;
    if (name == "Ab") number = 11;

    if (name == "A" || name == "Bb" || name == "B") {
      number += 13 * (octave + 1);
    } else {
      number += 13 * octave;
    }
    number -= (number + 1) / 13;
    number++;
    ss << number;
    return ss.str();
  }

};

constexpr int kO = 4;
constexpr int kNumNotes = 15;
const Note kBrokenThirdsUp[kNumNotes] = {
  {"C", kO, 1}, {"E", kO, 1},
  {"D", kO, 1}, {"F", kO, 1},
  {"E", kO, 1}, {"G", kO, 1},
  {"F", kO, 1}, {"A", kO, 1},
  {"G", kO, 1}, {"B", kO, 1},
  {"A", kO, 1}, {"C", kO+1, 1},
  {"B", kO, 1}, {"D", kO+1, 1},
  {"C", kO+1, 1}
};

class ofApp : public ofBaseApp {
 public:
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

 private:
  vector<ofSoundPlayer> players_;
  int noteIdx_;
};
