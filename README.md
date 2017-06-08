#Internets of Beds

IoB is a Bluetooth Low Energy weight sensor, placed under your bed, that force you to get-up in order to stop your alarm clock! 

Two weight sensors (from a cheap scale) are placed under the bed frame. The sensors are connected to an Adafruit Feather 32u4 BLE via an HX711 . TheFeather board send the measured values to an Android alarm clock application through Bluetooth. 

When the alarm startm the application try to connect the IoB . If it didn't manage ( IoB is out of reach, or you are not at home) the application remains a standard alarm clock. But if the connection is established, all the buttons are disabled and the only way to stop the music is to get-up. 

Of course if you go back to bed within a short amount of time (15 min) the alarm is trigger again. 


The android application is base on Clock+ designed by Phillip Hsu wich have been modified to fit my needs. Thank you very much PHILLIP HSU!!

## Clock+
Clock+ is a simple alarm clock, timer, and stopwatch app that offers a delightful user experience
for all your timing needs.

Highlights:

- **Clean, minimalistic design:** Features Material Design throughout.
- **New time pickers:** Enjoy setting alarms with two new time pickers! Beautifully crafted and
intuitively designed for ease of use.
- **List of timers:** See all of your timers in one scrollable list, and control each one individually.
- **Themes:** Choose between light, dark, and black themes.

[<img src="https://play.google.com/intl/en_us/badges/images/generic/en_badge_web_generic.png"
      alt="Get it on Google Play"
      height="80">](https://play.google.com/store/apps/details?id=com.philliphsu.clock2)
[<img src="https://f-droid.org/badge/get-it-on.png"
      alt="Get it on F-Droid"
      height="80">](https://f-droid.org/app/com.philliphsu.clock2)

<img src="https://cloud.githubusercontent.com/assets/19766085/19008497/830d2844-8720-11e6-8b8e-ff01ebcc26fe.png" width="180" height="320" />
<img src="https://cloud.githubusercontent.com/assets/19766085/19008498/8312eeaa-8720-11e6-9dc8-2079eb9c50f7.png" width="180" height="320" />
<img src="https://cloud.githubusercontent.com/assets/19766085/19008382/cc800614-871f-11e6-8fab-d1be69807e91.png" height="320" />

### License
```
Copyright 2017 Phillip Hsu

This file is part of ClockPlus.

ClockPlus is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ClockPlus is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ClockPlus.  If not, see <http://www.gnu.org/licenses/>.
```
