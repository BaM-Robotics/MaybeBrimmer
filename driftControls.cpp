// User defined function
void myblockfunction_left();
// User defined function
void myblockfunction_right();
// User defined function
void myblockfunction_move_forwards();
// User defined function
void myblockfunction_move_backwards();

float myVariable;

// User defined function
void myblockfunction_left() {
  Lmotors.spin(reverse);
  Rmotors.spin(reverse);
}

// User defined function
void myblockfunction_right() {
  Lmotors.spin(forward);
  Rmotors.spin(forward);
}

// User defined function
void myblockfunction_move_forwards() {
  Lmotors.spin(forward);
  Rmotors.spin(reverse);
}

// User defined function
void myblockfunction_move_backwards() {
  Rmotors.spin(forward);
  Lmotors.spin(reverse);
}

// "when Controller1 Axis3 changed" hat block
void onevent_Controller1Axis3Changed_0() {
  if (0.0 < Controller1.Axis3.position()) {
    myblockfunction_move_forwards();
  } else if (Controller1.Axis3.position() < 0.0) {
    myblockfunction_move_backwards();
  } else {
    if (0.0 == Controller1.Axis3.position()) {
      Lmotors.stop();
      Rmotors.stop();
    }
  }
}

// "when Controller1 Axis1 changed" hat block
void onevent_Controller1Axis1Changed_0() {
  if (0.0 < Controller1.Axis1.position()) {
    myblockfunction_right();
  } else if (Controller1.Axis1.position() < 0.0) {
    myblockfunction_left();
  } else {
    if (0.0 == Controller1.Axis1.position()) {
      Lmotors.stop();
      Rmotors.stop();
    }
  }
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // register event handlers
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);

  wait(15, msec);
}

