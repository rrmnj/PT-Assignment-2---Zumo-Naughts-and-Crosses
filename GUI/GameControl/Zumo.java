import processing.serial.*;

public class Zumo {
  
  public char symbol;
  public float lastKnownPos;
  public Serial connection;
  public char currDirection;
  
  public Zumo(char sym) {
    symbol = sym;
    lastKnownPos = 0;
    connection = null;
  }
}