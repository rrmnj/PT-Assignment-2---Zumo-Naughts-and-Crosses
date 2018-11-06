/**
 * @brief 
 * 
 * @file latest ting.cpp
 * @author Jamie Pounds, Mark Scholefield, Rasesh Ramanuj
 * @date 2018-03-29
 */
#include <ZumoReflectanceSensorArray.h>

#include <Wire.h>
#include <LSM303.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
//LSM303 compass;
#define NUM_SENSORS 6

//NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

#include <Servo.h>

#define CALIBRATION_SAMPLES 70  // Number of compass readings to take when calibrating
#define CRB_REG_M_2_5GAUSS 0x60 // CRB_REG_M value for magnetometer +/-2.5 gauss full scale
#define CRA_REG_M_220HZ 0x1C    // CRA_REG_M value for magnetometer 220 Hz update rate
#define LED_PIN 13
// this might need to be tuned for different lighting conditions, surfaces, etc.
#define BLACK_THRESHOLD 300 // microseconds
#define QTR_THRESHOLD 200   // microseconds

// Speed/duration settings
#define SPEED 150           // Maximum motor speed when going straight; variable speed when turning
#define TURN_BASE_SPEED 100 // Base speed when turning (added to variable speed)

// Allowed deviation (in degrees) relative to target angle that must be achieved before driving straight
#define DEVIATION_THRESHOLD 5
#define REVERSE_SPEED 100
#define TURN_SPEED 150
#define FORWARD_SPEED 100
#define MAX_DISTANCE 30
#define REVERSE_DURATION 250
#define TURN_DURATION 200
LSM303 compass;
Pushbutton button(ZUMO_BUTTON);
//Created a new version of the code which I've tested with the Arduino that works.
ZumoMotors motors;
ZumoReflectanceSensorArray reflectanceSensors(QTR_NO_EMITTER_PIN);
char endDir1;
unsigned int sensor_values[NUM_SENSORS];

#define _COMPLETE 'c'

// Converts x and y components of a vector to a heading in degrees.
// This function is used instead of LSM303::heading() because we don't
// want the acceleration of the Zumo to factor spuriously into the
// tilt compensation that LSM303::heading() performs. This calculation
// assumes that the Zumo is always level.
/**
 * @brief 
    converts x and y components of a vector to a heading in degrees.
    This function is used instead of LSM303::heading() because we don't 
    want the acceleration of the Zumo to factor spuriously into the tilt
    compensation that LSM303::heading() performs. This calculation
    assumes that the Zumo is always level.
 * 
 * @tparam T 
 * @param v 
 * @return float 
 */
template <typename T> float heading(LSM303::vector<T> v)
{
  float x_scaled = 2.0 * (float)(v.x - compass.m_min.x) / (compass.m_max.x - compass.m_min.x) - 1.0;
  float y_scaled = 2.0 * (float)(v.y - compass.m_min.y) / (compass.m_max.y - compass.m_min.y) - 1.0;

  float angle = atan2(y_scaled, x_scaled) * 180 / M_PI;
  if (angle < 0)
    angle += 360;
  return angle;
}

/**
 * @brief 
    initialises the reflectance sensors and the compass so it can read lines it crosses and 
    turn in a more accurate way using degrees rather than a certain time/speed on the wheels.
 * 
 */
void setup()
{
  reflectanceSensors.init();
  reflectanceSensors.calibrate();

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("asdasdsada...");

  initialise_compass();
  button.waitForButton();
  //sensor_callibration();
  //theBigJamie();

  navigateZumo('N', 1.1, 1.2);
}

void loop()
{
  reflectanceSensors.read(sensor_values);
  Serial.println(String(sensor_values[0]));
  char command;

  if (Serial.available() > 0)
  {
    command = Serial.read();
    if (command == 'm' || command == 'M')
    {
      char dir;
      while (Serial.available() <= 0)
      {
        dir = Serial.read();
      }
      while (Serial.available() <= 0)
      {
        delay(300);
      }
      double pos = Serial.readString().toDouble();
      while (Serial.available() <= 0)
      {
        delay(300);
      }
      double dest = Serial.readString().toDouble();

      navigateZumo(dir, pos, dest);
    }
  }
}
void theBigJamie()
{
  rotate(fmod(averageHeading() + 100, 360));
  rotate(fmod(averageHeading() + 90, 360));
  moveForward(3);
  rotate(fmod(averageHeading() - 80, 360));
  moveForward(3);
  motors.setSpeeds(0, 0);
}
/**
 * @brief 
    Handles the zumo code that gets it to move forward and then as it goes over a line it
    increments the start variable until it is equal to the destination variable.
 * 
 * @param destination 
 */
void moveForward(int destination)
{
  //destination refers to the amount of grey lines the zumo needs to cross before
  //it gets to its destination.
  int start = 0;
  while (start < destination)
  {
    if (line_detection() == "LINE")
    {
      start++; //increment the start variable after it crosses each line
    }
    motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  }

  motors.setSpeeds(0, 0);
  motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
  delay(250);
  motors.setSpeeds(0, 0);
}


/**
 * @brief 
      don't ask
 * 
 * @param  
 * @param  
 */
void Bread(char flex, double dagga) {
  Serial.println("WATSITS");
  Serial.println(flex);
  Serial.println(dagga);
}
/**
 * @brief 
    old placeholder function that was the pseudo-function for what moveForward() is now...
    kept in case we needed to add functionality later.
 * 
 */
void execute()
{
  //placeholder
}
/**
 * @brief 
    christ
 * 
 * @param dir 
 * @param pos 
 * @param dest 
 */
void navigateZumo(char dir, double pos, double dest)
{
  switch (dir)
  {
    case 'N':
      {
        //northX
        if (pos == 1.1)
        {
          if (dest == 1.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            Bread('E', dest);
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.2)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.3)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 2.1)
        {
          if (dest == 1.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.2)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.3)
        {
          if (dest == 1.1)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 3.1)
        {
          if (dest == 1.1)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.2)
        {
          if (dest == 1.1)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.3)
        {
          if (dest == 1.1)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
        }
      }
    case 'S':
      {
        //southX
        if (pos == 1.1)
        {
          if (dest == 1.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.2)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.3)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 2.1)
        {
          if (dest == 1.1)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.2)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
        }
        else if (pos == 2.3)
        {
          if (dest == 1.1)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 3.1)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.2)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.3)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
        }
      }
    case 'E':
      {
        //eastX
        if (pos == 1.1)
        {
          if (dest == 1.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.2)
        {
          if (dest == 1.1)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.3)
        {
          if (dest == 1.1)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 2.1)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.2)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight;
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.3)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 3.1)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.2)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.3)
        {
          if (dest == 1.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
        }
      }
    case 'W':
      {
        //westX
        if (pos == 1.1)
        {
          if (dest == 1.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.2)
        {
          if (dest == 1.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 1.3)
        {
          if (dest == 1.1)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 2.1)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.2)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 2.3)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.1)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            rotateLeft();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'S';
            break;
          }
        }
        else if (pos == 3.1)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.2)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.2)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
          else if (dest == 3.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.3)
          {
            rotateRight();
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'E';
            break;
          }
        }
        else if (pos == 3.3)
        {
          if (dest == 1.1)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.2)
          {
            rotateRight();
            moveForward(3);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 1.3)
          {
            rotateRight();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 2.1)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.2)
          {
            rotateRight();
            moveForward(2);
            execute();
            rotateLeft();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 2.3)
          {
            rotateRight();
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'N';
            break;
          }
          else if (dest == 3.1)
          {
            moveForward(3);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
          else if (dest == 3.2)
          {
            moveForward(2);
            execute();
            motors.setSpeeds(0, 0);
            endDir1 = 'W';
            break;
          }
        }
      }
      updatePosition(endDir1, dest);
  }
}
/**
 * @brief was a function to send back the final position and send back the direction the zumo
    would be facing at the end of the turn taken (being fed to it from navigateZumo() at the end of 
    each if statement)
 * 
 * @param dir 
 * @param pos 
 */
void updatePosition(char dir, double pos) {
  //Serial.write(_COMPLETE);
  //erial.write(dir);
  //Serial.write(String(pos));
}
/**
 * @brief Function to return when wall is crossed and used within main navigateZumo() function.
 * 
 * @return String 
 */
String line_detection()
{
  if (check_for_wall())
  {
    return "LINE";
  }

  /*  if (sensor_values[0] > QTR_THRESHOLD)
    {
      // if leftmost sensor detects line, reverse and turn to the right
      motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
      delay(REVERSE_DURATION);
      motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
      delay(TURN_DURATION);
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
      return "L";
    }
    else if (sensor_values[5] > QTR_THRESHOLD)
    {
      // if rightmost sensor detects line, reverse and turn to the left
      motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
      delay(REVERSE_DURATION);
      motors.setSpeeds(-TURN_SPEED, TURN_SPEED);
      delay(TURN_DURATION);
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
      return "R";
    }*/

  return "N/A";
}

//if sensors other than the far left and right are above the threshold it would indicate 
//we are on a wall.
/**
 * @brief if sensors other than the far left and right are above the threshold it would indicate
    we are on a wall
 * 
 * @return true 
 * @return false 
 */
bool check_for_wall()
{
  motors.setSpeeds(100, 100);
  reflectanceSensors.read(sensor_values);
  //if a given one of these values are above the qtr threshold, but we need to check if it's just the left side, or the entire zumo
  /**
   * @brief check if the values above the qtr are only on the left side or the entire zumo
   * 
   */
  if ((sensor_values[0] >= QTR_THRESHOLD) || (sensor_values[5] >= QTR_THRESHOLD))
  {
    delay(100); //pause the zumo to read the values in again
    reflectanceSensors.read(sensor_values);
    // if ((sensor_values[1] > QTR_THRESHOLD) || (sensor_values[2] > QTR_THRESHOLD) || (sensor_values[3] > QTR_THRESHOLD) || (sensor_values[4] > QTR_THRESHOLD))
    // { //if any of the middle sensors are above the QTR, stop the zumo.
    motors.setSpeeds(150, 150);
    delay(200);
    return true;
    // }
  }
  return false;
}
/**
 * @brief sets up the sensors by turning the zumo around left and right so that they 
 *  can properly read the lines/track to navigate itself
 * 
 */
void sensor_callibration()
{
  // Initialise the reflectance sensors module
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); // turn on LED to indicate we are in calibration mode

  unsigned long startTime = millis();
  while (millis() - startTime < 5000) // make the calibration take 5 seconds
  {
    //turn left
    motors.setSpeeds(-500, 500);
    delay(2500);
    Serial.println(sensor_values[1]);
    Serial.println(sensor_values[2]);
    Serial.println(sensor_values[3]);
    Serial.println(sensor_values[4]);
    Serial.println(sensor_values[5]);
    //turn right
    motors.setSpeeds(500, -500);
    delay(2500);
    Serial.println(sensor_values[1]);
    Serial.println(sensor_values[2]);
    Serial.println(sensor_values[3]);
    Serial.println(sensor_values[4]);
    Serial.println(sensor_values[5]);
  }
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(2);
  digitalWrite(13, LOW); // turn off LED to indicate we are through with calibration
}
/**
 * @brief spins the zumo around to initialise the compass and allows it to have more accurate rotations
 * 
 */
void initialise_compass()
{

  // The highest possible magnetic value to read in any direction is 2047
  // The lowest possible magnetic value to read in any direction is -2047
  LSM303::vector<int16_t> running_min = {32767, 32767, 32767}, running_max = { -32767, -32767, -32767};
  unsigned char index;

  // Initiate the Wire library and join the I2C bus as a master
  Wire.begin();

  // Initiate LSM303
  compass.init();

  // Enables accelerometer and magnetometer
  compass.enableDefault();

  compass.writeReg(LSM303::CRB_REG_M, CRB_REG_M_2_5GAUSS); // +/- 2.5 gauss sensitivity to hopefully avoid overflow problems
  compass.writeReg(LSM303::CRA_REG_M, CRA_REG_M_220HZ);    // 220 Hz compass update rate

  // To calibrate the magnetometer, the Zumo spins to find the max/min
  // magnetic vectors. This information is used to correct for offsets
  // in the magnetometer data.
  motors.setLeftSpeed(SPEED);
  motors.setRightSpeed(-SPEED);

  for (index = 0; index < CALIBRATION_SAMPLES; index++)
  {

    // Take a reading of the magnetic vector and store it in compass.m
    compass.read();

    running_min.x = min(running_min.x, compass.m.x);
    running_min.y = min(running_min.y, compass.m.y);

    running_max.x = max(running_max.x, compass.m.x);
    running_max.y = max(running_max.y, compass.m.y);
    delay(50);
  }

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);

  // Set calibrated values to compass.m_max and compass.m_min
  compass.m_max.x = running_max.x;
  compass.m_max.y = running_max.y;
  compass.m_min.x = running_min.x;
  compass.m_min.y = running_min.y;
}

// Average 10 vectors to get a better measurement and help smooth out
// the motors' magnetic interference.
/**
 * @brief average 10 vectors to get a better measurement and help smooth out the motors' magnetic interference
 * 
 * @return float 
 */
float averageHeading()
{
  LSM303::vector<int32_t> avg = {0, 0, 0};

  for (int i = 0; i < 10; i++)
  {
    compass.read();
    avg.x += compass.m.x;
    avg.y += compass.m.y;
  }
  avg.x /= 10.0;
  avg.y /= 10.0;

  // avg is the average measure of the magnetic vector.
  return heading(avg);
}

/**
 * @brief more compass code to calculate relative amount turned within 360 degrees
 * 
 * @param heading_from 
 * @param heading_to 
 * @return float 
 */
float relativeHeading(float heading_from, float heading_to)
{
  float relative_heading = heading_to - heading_from;

  // constrain to -180 to 180 degree range
  if (relative_heading > 180)
    relative_heading -= 360;
  if (relative_heading < -180)
    relative_heading += 360;
  return relative_heading;
}
/**
 * @brief turn right function to rotate zumo, used in navigateZumo() function to face zumo in correct direction
 * 
 */
void rotateRight()
{
  rotate(fmod(averageHeading() + 90, 360));
}
/**
 * @brief turn left function to rotate zumo, used in navigateZumo() function to face zumo in correct direction
 * 
 */
void rotateLeft()
{
  rotate(fmod(averageHeading() - 80, 360));
}

//this function rotates the zumo based on degrees passed in by the user (i.e. 90)
//this was heavily inspired from the compass example
/**
 * @brief source of rotate logic that handles how much zumo needs to turn in relative to it's current
 *  direction. where degrees to turn and other parameters are passed for turn to be as accurate as possible
 * 
 * @param degrees 
 */
void rotate(int degrees) //rotate to an angle based on compass
{
  int speed;
  float heading = averageHeading();
  float relative = relativeHeading(heading, degrees);
  while (abs(relative) > DEVIATION_THRESHOLD)
  {
    heading = averageHeading();
    relative = relativeHeading(heading, degrees);
    speed = SPEED * relative / 180;
    if (speed < 0)
      speed -= TURN_BASE_SPEED;
    else
      speed += TURN_BASE_SPEED;
    motors.setSpeeds(speed, -speed);
  }
  motors.setSpeeds(0, 0);
  delay(400);
}