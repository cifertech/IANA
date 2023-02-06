<div align="center">

  <img src="https://user-images.githubusercontent.com/62047147/195847997-97553030-3b79-4643-9f2c-1f04bba6b989.png" alt="logo" width="100" height="auto" />
  <h1>IANA</h1>
   
  <p>
    A Game-Inspired Gadget for Remote Control of Devices
  </p>
   

 
<!-- Badges -->

<a href="https://github.com/cifertech/IANA" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=cifertech&message=IANA&color=white&logo=github" alt="cifertech - IANA"></a>
<a href="https://github.com/cifertech/IANA"><img src="https://img.shields.io/github/stars/cifertech/IANA?style=social" alt="stars - IANA"></a>
<a href="https://github.com/cifertech/IANA"><img src="https://img.shields.io/github/forks/cifertech/IANA?style=social" alt="forks - IANA"></a>
   
<h4>
    <a href="https://twitter.com/cifertech1">TWITTER</a>
  <span> · </span>
    <a href="https://www.instagram.com/cifertech/">INSTAGRAM</a>
  <span> · </span>
    <a href="https://www.youtube.com/c/cifertech">YOUTUBE</a>
  <span> · </span>
    <a href="https://cifertech.net/">WEBSITE</a>
  </h4>
</div> 
 
<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Pictures](#camera-Pictures)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Schematic](#electric_plug-Schematic)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [License](#warning-license)
- [Contact](#handshake-contact)

  

<!-- About the Project -->
## :star2: About the Project
We will be building a smart glove inspired by the game Rainbow Six Siege from IANA character. The project allows us to control a device remotely, using hand gestures captured by a MPU6050 accelerometer/gyroscope and two potentiometers. Wireless communication between the glove and the device is achieved using the nRF24 radio 

<!-- Pictures -->
### :camera: Pictures

<div align="center"> 
  <img src="https://user-images.githubusercontent.com/62047147/216934937-f575d50d-7b1b-42da-954e-891fc3831093.jpg" alt="screenshot" width="Auto" height="Auto" />
</div>


<!-- Features -->
### :dart: Features

- Uses 2.4Ghz band for comunication
- 2 potenciameter for track the movemnent of two finger
- MPU6050 for track the hand movement

<!-- Getting Started -->
## 	:toolbox: Getting Started

To build this project, you will need the following parts and tools:

- Arduino Nano
- MPU6050 Gyroscope
- nRF24L01 Wireless Transceiver
- 2 Potentiometers


<img src="https://user-images.githubusercontent.com/62047147/216935926-d0b43efa-496c-4c66-a027-0a72c062241f.jpg" alt="screenshot" width="Auto" height="300" />


<!-- Schematic -->
### :electric_plug: Schematic
Make the connections according to the table and schematic below.

* TRASMITTER

| Arduino| nRF24|  
| ----   | -----|
| 9  | CE   |
| 13 | SCK  |
| 12 | MISO |
| 10 | CSN  |
| 11 | MOSI |
| 3V3 | Vcc |
| GND | GND |

| Arduino | MPU6050 |
| ----  | -----|
| A4    | SDA  |
| A5    | SCL  |
| 5v    | VCC  |
| GND   | GND  |

| Arduino | Poyenciameter1 |
| ----  | -----|
| Wiper | A2   |
| 5v    | VCC  |
| GND   | GND  |

| Arduino | Poyenciameter2 |
| ----  | -----|
| Wiper | A3   |
| 5v    | VCC  |
| GND   | GND  |


* RECIVER

| Arduino| nRF24|  
| ----   | -----|
| 9  | CE   |
| 13 | SCK  |
| 12 | MISO |
| 10 | CSN  |
| 11 | MOSI |
| 3V3 | Vcc |
| GND | GND |

 
* Complete Schematic

<img src="https://user-images.githubusercontent.com/62047147/216943863-90ab0b6e-b0e2-4658-9633-10e5d9e782ec.png" alt="screenshot" width="800" height="auto" />


<!-- Installation -->
### :gear: Installation

you need to install the required library in Arduino IDE Follow these steps:

- Follow this path Sketch> Include Library> Manage Libraries
- Search for nRF24L01 and Install the library
- Search for RF24 and Install the library
- Search for MPU6050 and Install the library


<!-- Usage -->
## :eyes: Usage

After uploading the code, Finally, you can test the smart glove by sending data wirelessly to a device and verifying that it responds as expected. You can then customize the code further to suit your specific requirements and make the smart glove even more functional.


<!-- License --> 
## :warning: License
 
Distributed under the MIT License. See LICENSE.txt for more information.


<!-- Contact -->
## :handshake: Contact 

CiferTech - [@twitter](https://twitter.com/cifertech1) - CiferTech@gmali.com

Project Link: [https://github.com/cifertech/WiFiBox](https://github.com/cifertech/WiFiBox)

<!-- Acknowledgments -->
## :gem: Acknowledgements 

 - [Motion HID Glove](https://www.thingiverse.com/thing:3673439)
 - [Overwatch Junkrat Gauntlet](https://www.thingiverse.com/thing:1887603)
 
 
