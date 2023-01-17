# p9-patrones
![Logo](doc/media/logo.png)

Manage all your sensor from a single interface
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

## CLI Options
  * -u / --user: Logins with the specified number and NIF
  * -L / --lang: Change the login language to specified one. Only available English and Spanish
  * -b / --background: Change the login background color to specified rgb values
  * -f / --font: Change the login font color to specified rgb values
  * -l / --logo: Change the login logo color to specified rgb values

## Documentation

The documentation can be read from the following [pdf](/doc/refman.pdf).