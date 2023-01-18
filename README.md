# p9-patrones
![Logo](doc/media/logo.png)

Manage all your sensor from a single interface
## Index
 * [Features](#feature)
 * [Requirements](#requirements)
 * [Installation](#installation)
 * [Execution](#execution)
 * [First execution and account set up](#First-execution-and-account-set-up)
 * [CLI Options](#cli-options)
 * [Interface Terminal Commands](#interface-terminal-commands)
 * [Available sensors](#available-sensors)
 * [Documentation](#documentation)
 * [Design pattern used](#design-pattern-used)

## Features
  * 2 Languages supported: English and Spanish
  * Almost total configuration of the interface
  * Change the configuration without restarting the interface
  * Dynamic interface
  * Real time control of the sensors
  * Terminal like interface with unique graphics
  * Administrator and normal user distintions
  * Administrators can manage the users
  * Administrator can manage the sensors
## Requirements

  * Linux
  * g++ v9.4.0 or newer
  * Make


## Compilation

The code can be compiled with the provided commands.
```bash
git clone https://github.com/clases-julio/p9-patrones-JavierIzqUni.git
cd p9-patrones-JavierIzqUni
```

## Installation
Being in the base directory (p9-patrones-JavierIzqUni)run to install:
```bash
chmod +x install
sudo ./install
```
This will install a bash command to launch the program.

To uninstall run in the base direcory:
```bash
sudo ./uninstall
```

## Execution

If run without command line arguments, using

```bash
jveh
```

the program will start using the default configuration, using the command line interface.


To know more about the options available use:
```bash
man jveh
```

## First execution and account set up 

When running the program for the first time, you need to login with the following number and NIF:
  * Default: employee number = 98765  NIF = 1234567A  Privileges = admin

After login with that user create your own administrator account using the command admin. See [Interface Terminal Commands](#interface-terminal-commands).
```
admin <newEmployeeNumber> <newNIF> [name]
```
Remember that the employee number must be 5 digits or less and the NIF must be 8 digits (normally 7 digits and a letter).

After creating the new account, logout and login with the new account.

Then remove the default account using:
```
rm 98765 1234567A
```
You have finshed the setting up your admin account

## CLI Options
  * -u / --user: Logins with the specified number and NIF
  * -L / --lang: Change the login language to specified one. Only available English and Spanish
  * -b / --background: Change the login background color to specified rgb values
  * -f / --font: Change the login font color to specified rgb values
  * -l / --logo: Change the login logo color to specified rgb values

## Interface Terminal Commands
To know more about the following commands type man <command>.
  * add
  * admin
  * back
  * background
  * clear
  * config
  * cs
  * exit
  * font
  * graphic
  * lang
  * left
  * log
  * logout
  * ls
  * man
  * name
  * right
  * rm
  * set
  * update
  * user

## Available sensors
The following types are the ones supported:
  * Camera RGB: rgbcamera
  * Camera BW: bwcamera
  * Thermometer: thermometer
  * Moisture sensor: moisture
  * Humidity sensor: humidity
  * Air quality sensor: airquality

## Documentation

The documentation can be read from the following [pdf](/doc/doxygen/refman.pdf). 

If you want to see the class diagram, it can be read from the next [pdf](doc/uml/ClassDiagram.pdf).

You can also see the documentation if you have the repository cloned opening the file /doc/doxygen/html/index.html in a search engine.

## Design pattern used
I used various design patterns, but the most significant one would be the Singleton used in the login interface and in the dashboard, so you
can only create one, making the login much easier than before.

The other important one would be factory method, used for creating the correct interface for each platform, making expandability easier and faster.