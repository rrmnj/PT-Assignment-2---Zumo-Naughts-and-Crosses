// Need G4P library
import g4p_controls.*;
import processing.serial.*;

final int _ONE = 1;
final int _TWO = 2;
final int _THREE = 3;

//Serial port for communication to/from Arduino
private Serial com4, com5;
private String message;
private boolean com4Connected, com5Connected;

public void setup() {
  size(480, 320, JAVA2D);
  createGUI();
  customGUI();
  // Place your setup code here

  com4 = new Serial(this, "COM4", 9600);
  com5 = new Serial(this, "COM5", 9601);
  com4.bufferUntil('\n');
  com5.bufferUntil('\n');
}

public void draw() {
  background(230);
}

void serialEvent(Serial myPort) {
  //read in data to string
  //new line command indicates end of message
  message = myPort.readString();
  //some value provided from Arduino
  if (message != null) {
    //remove whitespace and formatting
    message = trim(message);
    println(message); //TEST

    if (myPort == com4) {
      if (!com4Connected) { //executes on first message received
        if (message.equals("requestcontact")) {
          myPort.clear();
          com4Connected = true;
          myPort.write('t');
          txtOutput.setText("Connection to Arduino 'O' established!");
        }
      } else { //on all subsequent messages after contact established
        txtOutput.setText(message);
      }
    } else if (myPort == com5) {
      if (!com5Connected) { //executes on first message received
        if (message.equals("requestcontact")) {
          myPort.clear();
          com5Connected = true;
          myPort.write('t');
          txtOutput.setText("Connection to Arduino 'X' established!");
        }
      } else { //on all subsequent messages after contact established
        txtOutput.setText(message);
      }
    }
  }
}

// Use this method to add additional statements
// to customise the GUI controls
public void customGUI() {
}