# Vex Robotics
Notes about how to use and upload this code

Made using PROS, probably will not work without it installed https://pros.cs.purdue.edu/
You will need to make a project, replace main.cpp in src/ with this file, then you can compile it 

All operator control code (pretty much everything) is in the operator_control function at the bottom

If you need to reverse something, put a minus after the = where the code says to set the speed

If you need anything majorly changed, please open an issue 

When editing code, always `git pull` and `git push` so the code stays 

If you need to run the code on your own computer, makre sure PROS and Git is installed, make a project, and use `git clone https://github.com/NULL0404/vexrobotics/ 
src/` in terminal and you will be ready to run, edit, and push changes to this server

If you can't figure this out or suffer a *windows moment* you can copy and paste from `main.cpp` but if you plan to edit this code more often and it's not a one time thing setting up Git is worth it

## Wiring

1 - 3 	- Left motors

4 - 6 	- Right motors

PNEUMATIC lift on A
