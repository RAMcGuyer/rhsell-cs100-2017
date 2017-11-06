# RSHELL README

## Author: Sean Doerr, Ross McGuyer

## Introduction
Welcome to rshell! The exciting and best way to type unix commands! This program accepts input enmasse from you, the user. The commands must be unix commands located in the /bin folder. These commands can be seperated by ';', indicating a new line. Or you can use '&&' or '||' to connect two or more commands together!


## Commands
Write unix commands after the '$' prompt. You may use
the following commands to enhance your experience!

;  ----> Place after a unix command. Indicates new line.

&& ----> Place between two unix commands, the second command will only run if the first succeeds.

|| ----> Place between two unix commands, the second command will only work if the first fails

\# ----> Place anywhere and anything after will be commented out.

## Known Bugs
* Program attempts to execute command twice if the command fails. More likely to occur in conjection with a connector. This also causes the exit command to not exit the program.
* echo "&&" or any other connector does not print as expected. It is most likely because it is reading it as a command, since we assume users will not use just connectors
* failed commands can cause previous commands to print again after the next set of inputs. 
