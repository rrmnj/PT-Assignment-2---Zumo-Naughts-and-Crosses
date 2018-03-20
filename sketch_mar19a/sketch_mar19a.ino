int turnSpeedHigh = 100;
int turnSpeedMid = 90;
int turnSpeedLow = 80;

void rotateRight() {
  rotate(fmod(averageHeading() + turnSpeedMid, 360));
}

void rotateLeft() {
  rotate(fmod(averageHeading() - turnSpeedMid, 360));
}

void updatePosition(float pos) {
  Serial.println("movecomplete");
  Serial.println(String(pos));
}

void execute(); {

}

void moveForward(int i) {

}

void bigTing() {
  switch(direction) {
    case 'N': {
      if (pos == 1.1) {
        if(dest == 1.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0);
        }
        if (dest == 2.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.2) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.3) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.1) {
        if(dest == 1.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.2) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0);           
        }
        if (dest == 1.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.3) {
        if(dest == 1.1) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.1) {
        if(dest == 1.1) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.2) {
        if(dest == 1.1) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.3) {
        if(dest == 1.1) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
    }
    case 'S': {
      if (pos = 1.1) {
        if(dest = 1.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 1.2) {
        if(dest = 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 1.3) {
        if(dest = 1.1) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 2.1) {
        if(dest = 1.1) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 2.2) {
        if(dest = 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0);           
        }
        if (dest = 1.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 2.3) {
        if(dest = 1.1) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 3.1) {
        if(dest = 1.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 3.2) {
        if(dest = 1.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos = 3.3) {
        if(dest = 1.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.2) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 1.3) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 2.3) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.1) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest = 3.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
    }
    case 'E': {
      if (pos == 1.1) {
        if(dest == 1.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.2) {
        if(dest == 1.1) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          decCount = 1;
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.3) {
        if(dest == 1.1) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.1) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.2) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0);           
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.3) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.1) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.2) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.3) {
        if(dest == 1.1) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
    }
    case 'W': {
      if (pos == 1.1) {
        if(dest == 1.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.2) {
        if(dest == 1.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 1.3) {
        if(dest == 1.1) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.1) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.2) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0);           
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 2.3) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateLeft();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.1) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.2) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(2);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.3) {
          rotateRight();
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
      if (pos == 3.3) {
        if(dest == 1.1) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.2) {
          rotateRight();
          moveForward(2);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 1.3) {
          rotateRight();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.1) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.2) {
          rotateRight();
          moveForward(1);
          execute();
          rotateLeft();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 2.3) {
          rotateRight();
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.1) {
          moveForward(2);
          execute();
          motors.setSpeeds(0, 0); 
        }
        if (dest == 3.2) {
          moveForward(1);
          execute();
          motors.setSpeeds(0, 0); 
        }
      }
    } updatePostion(dest);
  }
}
