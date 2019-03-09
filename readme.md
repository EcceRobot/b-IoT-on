# Arduino MKR 1010
https://store.arduino.cc/arduino-mkr-wifi-1010

https://www.arduino.cc/en/Guide/MKRWiFi1010 

https://www.arduino.cc/en/Reference/WiFiNINA

https://www.arduino.cc/en/Tutorial/WiFiNINAScanNetworks

https://www.arduino.cc/en/Tutorial/WiFiNINAWiFiPing


# Telegram Bot
https://core.telegram.org/bots
# Relè
https://s3-eu-west-1.amazonaws.com/rpf-futurelearn/how-computers-work/week_1/1.12-Relay.gif
# Servomotore
https://www.arduino.cc/en/reference/servo 
## PWM
![PWM on LED](https://cdn-images-1.medium.com/max/1600/0*8aKMKfT-FwswIeyx.)

https://cdn-images-1.medium.com/max/1600/0*8aKMKfT-FwswIeyx.
https://backyardbrains.com/experiments/img/Graphs_PWM_web.jpg
http://archive.fabacademy.org/fabacademy2016/fablabshangai/students/96/Week13/servo.gif




Perchè Telegram?
Perchè con WhatsApp non si può. 
Perchè Telegram mette a disposizione delle API per parlare con i BOT.

Cosa sono i BOT?
Sono dei servizi automatizzati, programmati con delle logiche più o meno complesse.

Cosa sono i BOT in Telegram?
Sono degli interlocutori virtuali.

Cosa sarà il nostro BOT?
Sarà una conversazione in cui scriveremo delle parole chiave che verranno lette da una applicazione Arduino attraverso delle librerie.
Il nostro Arduino, opportunamente programmato, svolgerà dei compiti dopo aver riconosciuto tali parole chiave.


Esempio comunicazione Seriale.
Modifichiamo l'esempio Blink per effettare delle operazioni in corrispondenza di lettura stringhe

```java
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {


  if (Serial.available() > 0) {

    String myRead = Serial.readStringUntil('\r');

    Serial.println(myRead);
    if (myRead == "ON") {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }

    if (myRead == "OFF") {
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }
  }
  
}
```
