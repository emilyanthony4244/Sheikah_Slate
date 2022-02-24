<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
   
<img src="https://i.etsystatic.com/14675880/r/il/ea402a/2162910604/il_794xN.2162910604_d0df.jpg" alt="Logo" width="80" height="80">

  <h3 align="center">Sheikah Slate Cosplay Project</h3>

  <p align="center">
    A functional, open source Sheikah Slate for cosplay or collectors.
    <br />
    <a href="https://github.com/emilyanthony4244/Shiekah_Slate"><strong>Explore the slate »</strong></a>
    <br />
    <br />
    <a href=" ">Demo Placeholder Link</a>
    <br />
    <br />
<img src="Assets/rear render.png" alt="rear render" width="50%">


<a href="https://github.com/othneildrew/Best-README-Template/issues">Report Bug</a>

<a href="https://github.com/othneildrew/Best-README-Template/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

In November 2021 I decided to tackle my next cosplay build – Nintendo’s Zelda Breath of the Wild’s Link, specifically his Royal Guardsman armor from the Champions Ballad DLC.

Sewing aside, the biggest part of the project proved to be the Sheikah slate. Initially I considered making a “dummy” prop, maybe with lights, but after doing some research I started down the Adafruit rabbit hole (thanks @ladyada) and opted to integrate a 7inch TFT touch screen, a small camera, a noisemaker, and various light sources.

This piece packages an Arduino-based Microcontroller from Adafruit with various modules and a custom main control board to perform the following functions: 
* Light up orange and blue pieces along parts of the body
* Generate a “chirping” sound to mimic a Sheikah Sensor
* Take basic photographs and display them on screen
* Simulate the “sleep” image, the sheikah logo shown above, when not in use
* Provide basic menus for information and as a digital resume for the costume


<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [Arduino IDE](https://www.arduino.cc/en/software)
* [SOLIDWORKS Educational Edition 2020](https://www.solidworks.com)
* [Blender 2.90.1](https://www.blender.org/)
* [DipTrace PCB Layout](https://diptrace.com/diptrace-software/pcb-layout/)
* [DipTrace Schematic Capture](https://diptrace.com/diptrace-software/pcb-layout/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Building your own Sheikah Slate requires approximately $450, access to a 3D printer, some basic soldering skills, acrylic paints, and patience.

### Materials

Soldering Iron, a computer capable of running the Arduino IDE, glue, Philips head screwdriver, double sided tape.

<p align="center">AND</p>

FDM 3D printer capable of printing clear and solid color PLA filament with a minimum build volume of 275mm x 175mm x 25mm.

<p align="center">OR</p>

FDM 3D printer capable of printing solid PLA/ABS/PETG/etc AND an SLA printer capable of printing clear UV resin. I use an Anycubic Photon Mono X for SLA prints and a Creality CR10s Pro V2 for FDM prints.

<p align="center">OR</p>

Money to spend at www.HUBS.com or www.shapeways.com to outsource prints.

See the BOM in root directory for parts information. 3D print costs are estimates and will be higher if you outsource this print. PCBs can be ordered at various online vendors such as PCBway.com. It’s recommended to shop around to get your best price. PCBway has a minimum order of 5 boards per order; I have extras and can sell you one for $12 + shipping.

### Installation

To Use the Adafruit Adalogger M0 board in the Arduino IDE, you’ll need to follow the guide linked here: https://learn.adafruit.com/adafruit-feather-m0-adalogger/using-with-arduino-ide.

All the necessary libraries “should” be in the Arduino folder above. Drop these in your local Arduino libraries folder for use.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Placeholder for menu items and features

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Add Readme
- [x] Add back to top links
- [x] Add Installation instructions
- [ ] Add Arduino Firmware
- [ ] Add Menu Images in Usage Section
- [ ] Film Demo and take pretty photos

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

See `LICENSE.txt` for information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Emily Anthony - [@thelegendofemily](https://instagram.com/thelegendofemily) 

Project Link: [https://github.com/emilyanthony4244/Sheikah_Slate](https://github.com/emilyanthony4244/Sheikah_Slate)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Use this space to list resources you find helpful and would like to give credit to. I've included a few of my favorites to kick things off!

* [OthNealDrew’s Readme template]( https://github.com/othneildrew/Best-README-Template)
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/emilyanthony4244/Sheikah_Slate.svg?style=for-the-badge
[contributors-url]: https://github.com/emilyanthony4244/Sheikah_Slate/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/emilyanthony4244/Sheikah_Slate.svg?style=for-the-badge
[forks-url]: https://github.com/emilyanthony4244/Sheikah_Slate/network/members
[stars-shield]: https://img.shields.io/github/stars/emilyanthony4244/Sheikah_Slate.svg?style=for-the-badge
[stars-url]: https://github.com/emilyanthony4244/Sheikah_Slate/stargazers
[issues-shield]: https://img.shields.io/github/issues/emilyanthony4244/Sheikah_Slate.svg?style=for-the-badge
[issues-url]: https://github.com/emilyanthony4244/Sheikah_Slate/issues
[license-shield]: https://img.shields.io/github/license/emilyanthony4244/Sheikah_Slate.svg?style=for-the-badge
[license-url]: https://github.com/emilyanthony4244/Sheikah_Slate/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/emilyanthony


