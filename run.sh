#!/bin/bash

if [[ ! -e /tmp/virtual_mic ]]; then
  mkfifo tmp/virtual_mic
fi


#Create Virtual Microphone
pacmd load-module module-pipe-source source_name=virtual_mic file=/tmp/virtual_mic format=s16le rate=16000 channels=1
sleep 1
pacmd load-module module-pipe-source source_name=virtual_mic file=/tmp/virtual_mic format=s16le rate=16000 channels=1


#open zoom application and join to host
xdg-open "zoommtg://zoom.us/join?action=join&confno=8784588697&pwd=927063"