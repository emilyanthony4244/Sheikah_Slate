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
    <a href="https://github.com/emilyanthony4244/Sheikah_Slate"><strong>Explore the slate »</strong></a>
<br />
<img src="Assets/rear render.png" alt="rear render" width="50%">


<br />
    
<a href=" ">Demo Placeholder Link</a>
<br />

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
A prototype was built with the following specifications and functions:
* ESP32 based microcontroller integrated with a custom PCB
* Light up orange and blue pieces along parts of the body
* Generate a “chirping” sound to mimic a Sheikah Sensor
* Simulate the “sleep” image, the sheikah logo shown above, when not in use
* Display basic menus for information 

Prototype Photos:


<center><img src="https://github.com/emilyanthony4244/Sheikah_Slate/blob/main/Assets/296172815_10220211113417289_6492841646193638318_n.jpg" width"100"></center>

<center><img src="https://github.com/emilyanthony4244/Sheikah_Slate/blob/main/Assets/297153859_10220211113337287_6166251877348932006_n.jpg?" width"100"></center>


However, the prototype had a LONG way to go… so I went back to the drawing board and rolled up a V2.0. Improvements:
* On-board SD card integration to delete the SD shield
* Shrunk the board considerably (check out the photos!)
* Moved from DAC audio to a proper IIS solution
* Deleted all the bulb LEDs, moved to addressable everything for color coordination
* Integration of a TTL camera
* Board updates for noise shielding
* Proper GUI built using <a href=" https://github.com/ImpulseAdventure/GUIslice/wiki">
GUISlice Builder</a>

V1 vs V2 board size:


<center><img src="https://github.com/emilyanthony4244/Sheikah_Slate/blob/main/Assets/20220824_190129.jpg" width"100"></center>

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

See the BOM in root directory for parts information. 3D print costs are estimates and will be higher if you outsource this print. PCBs can be ordered at various online vendors such as PCBway.com. I have extras and can sell you one for $12 + shipping. Otherwise, you can order from PCBway where I get a cut:


<a href="https://www.pcbway.com/project/shareproject/Sheikah_Slate_for_Cosplay_951a0c22.html"><img src="https://www.pcbway.com/project/img/images/frompcbway-1220.png" alt="PCB from PCBWay" /></a>

### Installation

To Use the Adafruit Feather ESP32 v2 board in the Arduino IDE, you’ll need to follow the guide linked here: https://learn.adafruit.com/adafruit-esp32-feather-v2

All the necessary libraries “should” be in the Arduino folder above. Drop these in your local Arduino libraries folder for use. Open the SheikahSlate.ino file, select your board, and upload. If this doesn’t work, toss the library files in your default Arduino Libraries folder. Make sure you don’t have any conflicts in names or versions.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- HOW IT WORKS -->
## How it works

The Sheikah Slate combines the Adafruit RA8875 TFT driver board and Adafruit 7in 800x480 resistive touch TFT screen to simulate the in-game sheikah slate interface. The menus were created with GUIslice Builder (linked above) using the Adafruit GFX library. The SS V2 uses an ESP32 Pico microcontroller from Adafruit: the ESP32 Feather V2.

### SD Implementation

A SD card slot is provided on the board. This is a cloned circuit of the Adafruit MicroSD SPI or SDIO Breakout Board. The SD is SPI only.

<i> A note: RA8875 uses SPI mode 3 and SD uses SPI mode 0, so they are not compatible in the same SPI bus without isolation. This is why the 74HC125 chip is present. If you want to DIY you must populate this chip. </i>

In firmware, the SD CS is set to GPIO12.

### TFT Setup 

An example config file was used as a base and modified. This was renamed to sheikah_tft_config.h and included at the top of sheikahslate.ino. This can also be called in GUIslice_config.h.

Unfortunately the RA8875 is not compatible with TFT_eSPI from @Bodmer, so the AdafruitGFX and RA8875 libraries must be used.
The following items were modified from the base config:

<code>#define ADAGFX_PIN_CS       27    // Display chip select changed from 10 to 25
  #define ADAGFX_PIN_RST      23     // Display Reset is changed from 5 to 23
#define ADAGFX_PIN_SDCS     12    //SD CS</code>

For development, <code>#define DEBUG_ERR</code> was changed to 2. For release this will toggle to 0.

All optional features toggled to 1 for development; likely won’t need GPIO input in the end but who knows.

<code>#define GSLC_FEATURE_COMPOUND       1   // Compound elements (eg. XSelNum)
  #define GSLC_FEATURE_XTEXTBOX_EMBED 1   // XTextbox control with embedded color
  #define GSLC_FEATURE_INPUT          1   // Keyboard / GPIO input control</code>

SD enabled for obvious reasons:

<code>#define GSLC_SD_EN    1</code>

Pixel Buffer increased because I’m impatient

<code>#define GSLC_SD_BUFFPIXEL   85</code>

<i>A note: this pixel buffer is by default 8 bit. Even though the ESP32 can handle it, the display will not work if you increase this past 85 due to the way the SD library and GFX library reads files to the RA8875 LCD buffer. I may write a buffer for the buffer to send to the screen in larger chunks and am investigating how to speed this whole thing up. I am really concerned about the rate I can write images to the screen.</i>

### Camera

The Sheikah Slate features the Adafruit Miniature TTL Serial JPG camera. The camera captures 640x480 images and saves them to the SD in jpg format using the Adafruit VC0706 Camera library. The file names are formatted “IMAGExx.JPG” from 00 to 99.

When the Camera menu is selected, the user has the option to turn “flash” on and off. “Flash” is just lighting the NeoPixels on the back 100% brightness full white. This is just to help in low light; the VC0706 has auto brightness so there are no other settings in this menu.

Using the TJpg_Decoder library (also from @Bodmer), the jpgs are processed and resaved as 24bit BMP files and then displayed on the TFT. Jpeg files must be in 24bit format; luckily, the Adafruit TTL Serial Camera takes 24bit depth jpg images so it’s an easy conversion.

The Sheikah Slate does not and will never support streamed video to the display. Sorry.

### Audio

TODO

### Add features

There are 5 GPIO pins broken out in case you ever want to add something. Be aware that GPIO34, 36, and 39 are input only.

### NeoPixels

Finally, the slate has 11 button NeoPixels, a 16 pixel Ring, a Flora, and a 20 LED strip all from Adafruit. They’re all strung together and addressed on GPIO26. The order of the NeoPixels is as follows:

<table border="0" cellpadding="0" cellspacing="0" id="sheet0" class="sheet0 gridlines">
        <colgroup><col class="col0">
        <col class="col1">
        <col class="col2">
        <col class="col3">
        <col class="col4">
        <col class="col5">
        <col class="col6">
        <col class="col7">
        <col class="col8">
        <col class="col9">
        <col class="col10">
        <col class="col11">
        <col class="col12">
        <col class="col13">
        <col class="col14">
        <col class="col15">
        <col class="col16">
        <col class="col17">
        <col class="col18">
        <col class="col19">
        <col class="col20">
        <col class="col21">
        <col class="col22">
        <col class="col23">
        <col class="col24">
        <col class="col25">
        <col class="col26">
        <col class="col27">
        <col class="col28">
        <col class="col29">
        <col class="col30">
        <col class="col31">
        <col class="col32">
        <col class="col33">
        <col class="col34">
        <col class="col35">
        <col class="col36">
        <col class="col37">
        <col class="col38">
        <col class="col39">
        <col class="col40">
        <col class="col41">
        <col class="col42">
        <col class="col43">
        <col class="col44">
        <col class="col45">
        <col class="col46">
        <col class="col47">
        <col class="col48">
        <col class="col49">
        <col class="col50">
        <col class="col51">
        <col class="col52">
        <col class="col53">
        <col class="col54">
        <col class="col55">
        </colgroup><tbody>
          <tr class="row0">
            <td class="column0 style0 s">Position</td>
            <td class="column1 style0 n">0</td>
            <td class="column2 style0 n">1</td>
            <td class="column3 style0 n">2</td>
            <td class="column4 style0 n">3</td>
            <td class="column5 style0 n">4</td>
            <td class="column6 style0 n">5</td>
            <td class="column7 style0 n">6</td>
            <td class="column8 style0 n">7</td>
            <td class="column9 style0 n">8</td>
            <td class="column10 style0 n">9</td>
            <td class="column11 style0 n">10</td>
            <td class="column12 style0 n">11</td>
            <td class="column13 style0 n">12</td>
            <td class="column14 style0 n">13</td>
            <td class="column15 style0 n">14</td>
            <td class="column16 style0 n">15</td>
            <td class="column17 style0 n">16</td>
            <td class="column18 style0 n">17</td>
            <td class="column19 style0 n">18</td>
            <td class="column20 style0 n">19</td>
            <td class="column21 style0 n">20</td>
            <td class="column22 style0 n">21</td>
            <td class="column23 style0 n">22</td>
            <td class="column24 style0 n">23</td>
            <td class="column25 style0 n">24</td>
            <td class="column26 style0 n">25</td>
            <td class="column27 style0 n">26</td>
            <td class="column28 style0 n">27</td>
            <td class="column29 style0 n">28</td>
            <td class="column30 style0 n">29</td>
            <td class="column31 style0 n">30</td>
            <td class="column32 style0 n">31</td>
            <td class="column33 style0 n">32</td>
            <td class="column34 style0 n">33</td>
            <td class="column35 style0 n">34</td>
            <td class="column36 style0 n">35</td>
            <td class="column37 style0 n">36</td>
            <td class="column38 style0 n">37</td>
            <td class="column39 style0 n">38</td>
            <td class="column40 style0 n">39</td>
            <td class="column41 style0 n">40</td>
            <td class="column42 style0 n">41</td>
            <td class="column43 style0 n">42</td>
            <td class="column44 style0 n">43</td>
            <td class="column45 style0 n">44</td>
            <td class="column46 style0 n">45</td>
            <td class="column47 style0 n">46</td>
            <td class="column48 style0 n">47</td>
            <td class="column49 style0 n">48</td>
            <td class="column50 style0 n">49</td>
            <td class="column51 style0 n">50</td>
            <td class="column52 style0 n">51</td>
            <td class="column53 style0 n">52</td>
            <td class="column54 style0 n">53</td>
            <td class="column55 style0 n">54</td>
          </tr>
          <tr class="row1">
            <td class="column0 style0 s">Description</td>
            <td class="column1 style1 s style1" colspan="3">Lashes</td>
            <td class="column4 style1 s style1" colspan="5">Dots Back</td>
            <td class="column9 style1 s style1" colspan="16">Ring</td>
            <td class="column25 style1 s style1" colspan="7">Flora</td>
            <td class="column32 style1 s style1" colspan="4">Dots Front</td>
            <td class="column36 style1 s style1" colspan="20">Strip Handle</td>
          </tr>
          <tr class="row2">
            <td class="column0 style0 s">Default Color</td>
            <td class="column1 style1 s style1" colspan="24">Amber</td>
            <td class="column25 style1 s style1" colspan="11">Blue</td>
            <td class="column36 style1 s style1" colspan="20">Amber</td>
          </tr>
          <tr class="row3">
            <td class="column0 style0 s">Default Brightness</td>
            <td class="column1 style2 n style2" colspan="55">30%</td>
          </tr>
          <tr class="row4">
            <td class="column0 style0 s">Low Battery Color</td>
            <td class="column1 style1 s style1" colspan="8">Amber</td>
            <td class="column9 style1 s style1" colspan="16">Red</td>
            <td class="column25 style1 s style1" colspan="11">Blue</td>
            <td class="column36 style1 s style1" colspan="20">Amber</td>
          </tr>
          <tr class="row5">
            <td class="column0 style0 s">Low Battery Brightness</td>
            <td class="column1 style2 n style2" colspan="8">10%</td>
            <td class="column9 style2 n style2" colspan="16">40%</td>
            <td class="column25 style2 n style2" colspan="31">10%</td>
          </tr>
          <tr class="row6">
            <td class="column0 style0 s">Idle Color</td>
            <td class="column1 style1 s style1" colspan="24">Amber</td>
            <td class="column25 style1 s style1" colspan="11">Blue</td>
            <td class="column36 style1 s style1" colspan="20">Amber</td>
          </tr>
          <tr class="row7">
            <td class="column0 style0 s">Idle Brightness</td>
            <td class="column1 style1 s style1" colspan="55">Breathe 1% to 25%</td>
          </tr>
          <tr class="row8">
            <td class="column0 style0 s">Photo Menu Color</td>
            <td class="column1 style1 s style1" colspan="35">White</td>
            <td class="column36 style1 s style1" colspan="20">Amber</td>
          </tr>
          <tr class="row9">
            <td class="column0 style0 s">Photo Menu Brightness</td>
            <td class="column1 style2 s style2" colspan="35">toggle 0% or 100%</td>
            <td class="column36 style2 n style2" colspan="20">30%</td>
          </tr>
        </tbody>
    </table>

### A note regarding memory, core usage, etc

The libraries required for this project built with an entirely empty sketch took uses about 0.3MB of flash memory. Be wise about adding screens with the GUISlice Builder and store all images on the SD. Don’t try to be sly and write to FLASH.

Currently I am not fiddling with the default core assignments in the Arduino IDE for the ESP32. I am considering offloading the SD buffer to LCD Buffer to core 1 as well as the jpg to bmp file conversion. I’d love to use both cores of the ESP32, but just one can do everything I’d like it to do.

TJpg_Decoder has an example where it renders a Jpeg file that is stored in an array within Flash memory. The Jpeg decoding is done by one processor core 0 and the rendering to TFT by processor 1. I may be able to reformat this to use the 2MB of PSRAM available.
<!-- USAGE EXAMPLES -->
## Usage

Placeholder for menu items and features

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Add Readme
- [x] Add back to top links
- [x] Add Installation instructions
- [WIP] Add Arduino Firmware
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


