#!/bin/bash 
cd ~/PiBits/ServoBlaster/user && sudo ./servod --p1pins=12 && sudo echo P1-12=60% > /dev/servoblaster
