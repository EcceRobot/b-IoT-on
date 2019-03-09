# MKR Family

## In origine
https://store.arduino.cc/arduino-mkrzero

## WiFi
https://store.arduino.cc/arduino-mkr1000
https://store.arduino.cc/arduino-mkr1000-with-headers-mounted

## Evoluzione WIFi
https://store.arduino.cc/mkr-wifi-1010

### Altri membri della famiglia

https://store.arduino.cc/arduino-mkrfox1200
https://store.arduino.cc/mkr-wan-1300
https://store.arduino.cc/mkr-gsm-1400
https://store.arduino.cc/arduino-mkr-nb-1500
https://store.arduino.cc/mkr-vidor-4000




# Arduino MKR 1010

![](https://store-cdn.arduino.cc/uni/catalog/product/cache/1/image/500x375/f8876a31b63532bbba4e781c30024a0a/a/b/abx00023_iso.jpg)

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
PWM per controllare luminosità di un LED

![PWM per controllare luminosità di un LED](https://cdn-images-1.medium.com/max/1600/0*8aKMKfT-FwswIeyx.)

PWM per controllare posizione di un servo

![PWM per controllare posizione di un servo](https://backyardbrains.com/experiments/img/Graphs_PWM_web.jpg)

PWM per controllare movimento di un servo

![PWM per controllare movimento di un servo](http://archive.fabacademy.org/fabacademy2016/fablabshangai/students/96/Week13/servo.gif)




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
