/*******************************************************************
    An example of bot that receives commands and turns on and off
    an relay.
 *                                                                 *
    written by Giacarlo Bacchio (Gianbacchio on Github)
    adapted by Brian Lough
 *******************************************************************/
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ESP32Servo.h>

// Initialize Wifi connection to the router
char ssid[] = "xxxxxxxxxxxxxxxxx";     // your network SSID (name)
char password[] = "xxxxxxxxxxxxxxxxx"; // your network key

// Initialize Telegram BOT
#define BOTtoken "xxxxxxxxxxx:xxxxxxxxxxxxxxxxxxxxxxxxxxx"  // your Bot Token (Get from Botfather)
String myUserID = "xxxxxxxxxxxxxxxxx";



WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done
bool Start = false;

const int relayPin = 12;
int relayStatus = 0;

Servo myservo;  // create servo object to control a servo
// GPIO the servo is attached to
static const int servoPin = 13;
int servoPos = 0;    // variable to store the servo position


void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    String from_name = bot.messages[i].from_name;
    String from_id = bot.messages[i].from_id;
    if (from_name == "") from_name = "Guest";

    if (from_id == myUserID) {

      if (text == "/relay_on") {
        digitalWrite(relayPin, HIGH);   // turn the relay on (HIGH is the voltage level)
        relayStatus = 1;
        bot.sendMessage(chat_id, "relay is ON", "");
      }

      if (text == "/relay_off") {
        relayStatus = 0;
        digitalWrite(relayPin, LOW);    // turn the relay off (LOW is the voltage level)
        bot.sendMessage(chat_id, "relay is OFF", "");
      }

      if (text == "/relay_status") {
        if (relayStatus) {
          bot.sendMessage(chat_id, "relay is ON", "");
        } else {
          bot.sendMessage(chat_id, "relay is OFF", "");
        }
      }


      if (text == "/push") {
        /*
          for (servoPos = 0; servoPos <= 180; servoPos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(servoPos);    // tell servo to go to position in variable 'servoPos'
          delay(5);             // waits 15ms for the servo to reach the position
          }
        */
        delay(100);
        myservo.write(90);    // tell servo to go to position in variable 'servoPos'

        delay(500);
        myservo.write(0);    // tell servo to go to position in variable 'servoPos'

        bot.sendMessage(chat_id, "Button has been pushed", "");

      }

      if (text == "/start") {
        String welcome = "Comandi:\n";
        welcome += "\nRALAY\n";
        welcome += "/relay_on          to switch the relay ON\n";
        welcome += "/relay_off         to switch the relay OFF\n";
        welcome += "/relay_status    Returns current status of relay\n";
        welcome += "\nSERVO\n";
        welcome += "/push      the servo pushes the button\n";
        welcome += "\nADVANCED\n";
        welcome += "/ngul      special function\n";
        bot.sendMessage(chat_id, welcome, "");
        //bot.sendMessage(chat_id, welcome, "Markdown");
      }

      if(text == "/ngul"){
        bot.sendMessage(chat_id, "a te", "");
        }
    } else {
      bot.sendMessage(chat_id, "e tu chi minchia sei?", "");
        
      }
  }
}

void setup() {
  Serial.begin(115200);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
  // http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf
  delay(100);
  myservo.write(0);    // tell servo to go to position in variable 'servoPos'

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(relayPin, OUTPUT); // initialize digital relayPin as an output.
  delay(10);
  digitalWrite(relayPin, LOW); // initialize pin as off
}

void loop() {
  if (millis() > Bot_lasttime + Bot_mtbs)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    Bot_lasttime = millis();
  }
}
