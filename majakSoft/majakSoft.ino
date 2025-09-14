#include <Dictionary.h>
#include <Servo.h>
#include <LiquidCrystal.h> 
#define ADAFRUIT_ASCII96 0
LiquidCrystal lcd(7,8,9,10,11,12);
Servo servo;
Dictionary &d = *(new Dictionary(29));
byte umlaut_a[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b01110,
    0b10001,
    0b11111,
    0b10001,
    0b10001
};

byte umlaut_o[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};

byte umlaut_u[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

String text = "ausgezeichnet";

void setup()
 {
      d("A" , "01");
      d("B" , "1000");
      d("C" , "1010");
      d("D", "100");
      d("E", "0");
      d("F","0010");
      d("G","110");
      d("H","0000");
      d("I","00");
      d("J","0111");
      d("K", "101");
      d("L","0100");
      d("M","11");
      d("N","10");
      d("O","111");
      d("P","0110");
      d("Q","1101");
      d("R","010");
      d("S","000");
      d("T" , "1");
      d("U","001");
      d("V","0001");
      d("W","011");
      d("X","1001");
      d("Y","1011");
      d("Z","1100");
      d("Ä","0101");
      d("Ö","1110");
      d("ß","000000");
      d("Ü","0011");
    Serial.begin(9600);
    splitIntoLetters(text);
    lcd.begin(16,2);
    servo.attach(3);
    lcd.createChar(1, umlaut_a);
        lcd.createChar(2, umlaut_u);
        lcd.createChar(3, heart);
  lcd.setCursor(0,1);


    
    
    

}
void loop(){}

void splitIntoLetters(const String text1)
{
  delay(3000);
  servo.write(97);
  text1.toUpperCase();
  int l = text1.length();
  for(int i = 0; i<l; i++)
  {
    
    int len = d[ String(text1[i])].length();
    if(String(text1[i]) == " ")
    {
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
            
          
         
          digitalWrite(5, LOW);
    }
    for(int x = 0; x< len; x++)
    {
    
    

      String letter = (String(d[String(text1[i])][x]));
      Serial.print(letter);
      lcd.print(Convert(String(letter)));
      Serial.println();
      delay(100);
     
       
      if(letter == "0")
      {
               digitalWrite(6, HIGH);
               
              delay(125);
               digitalWrite(6, LOW);
               delay(125);
      }
      else if(letter == "1")
      {
              digitalWrite(6, HIGH);
              
              delay(500);
               digitalWrite(6, LOW);
               delay(500);
      }
    }
      Serial.print("||");

              lcd.print("/");
              digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          lcd.clear();
          delay(100);
          
          digitalWrite(5, LOW);
  }
  lcd.clear();
  int leng = text.length();
  text.replace("ü","!");
  for(int i =0; i< leng; i++){
   
    if(String(text[i]) == "!")
    {
      lcd.write(byte(2));

    }
    else
    {
      lcd.write(text[i]);

    }
    if(i>13)
      lcd.scrollDisplayLeft();
    delay(500);
    
    }
    lcd.write(byte(3));
    

  }


String Convert(String val)
{
  if(String(val) == "1")
  {
    return "-";
  }
  if(String(val) == "0")
  {
    return ".";
  }
  if(String(val) == " ")
  {
    return "///";
  }
  return "";
}


