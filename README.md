# RockSmithController

This is the source code for a MIDI controller to control Rocksmith2014

## table of contents

1.[Basic idea](#idea)
2.[functions](#functions)
3.[requirements](#requirements)
4.[code](#code)
5.[howto](#howto)

## idea

This project is based of the game rocksmith 2014. The perpose of the game is to learn you guiter while having a GUI play-along on your tv or monitor.
The game requires a real electric guitar to work and a keyboard to navigate the menus ect. I played this game for almost 20 hours and noticed what was missing for me.
While playing the guitar standing, I dont have my keyboard at hand at every moment, while playing guitar seated, I don't really have the space to move around that much. So I tought of a solution to fix my problem. An Arduino based stompbox which contains all the functions used in the game.

## functions

The game funtions are fairly limited, I've listed them all below.

2 buttons to represent the up and down arrow keys - used to navigate on every screen
2 buttons to represent the right and left keys - these get used to choose a style to play / can be used to riffrepeat
esc button - back button on most screens
spacebar button - tools and more
ctrl button - change input or guitar
enter button - obvious
delete - gets used for certain options like skip tuner and account menu
\+ - gets used to favourite items in the game. Not sure I'm going to implement this.

----------------------

4 arrows + esc + space + ctrl + enter + del = 4 + 5 = 9

----------------------

maybe a volume control? = 10 buttons
maybe a favourite button = 11 buttons max

## requirements

This projects needs a certain list of items. I've listed them below:

- An Arduino Uno
- Atmel Flip (software)
- arduino Uno R3 firmware (Located in the firmware folder)
- a pdf of HID usage tables (located in master of this project)
- Basics of arduino skills
- type of buttons you want to use
- electrical wires
- a led

## code

All code is inside of controller.ino
Here's how it works:

## howto

Here's how to make this project for yourself:

## ideas & todo

- Rotating button as volume
- Audio Jack troughput
- USB troughput or guitar troughput
- ON/OFF pickup selector

StompSwitches for normal keys
<https://www.banggood.com/5Pcs-Electric-Guitar-Effect-Momentary-Push-Button-Stomp-Foot-Pedal-Switch-p-1134006.html?rmmds=search&cur_warehouse=CN>

Search other option for arrows

    _________________________
    |                       |
    |       x   x   x       |
    |                       |
    |   x   x   x   x   x   |
    |_______________________|
