## C-process-raw-data

This is a script for processing the raw data collected from [pinetime-zephyr](https://github.com/MarcusNordstrom/pinetime-zephyr) and the nRF connect app.

## Guide

 - Take the raw log from nRF connect and remove everything outside of *Notifications and indications enabled/disabled*
 - run the command `grep '"(0x' LOGNAME.txt | grep -o '".*"' | sed 's/"//g' | cut -c 6- > raw_data.txt`
 - edit PATH in main.c to your point to raw_data.txt that you just made
 - Build with cmake
 - run and capture the output e.g `./build/processRawData > data.csv`
 - This data can then be used in [C-optimize-variables](https://github.com/MarcusNordstrom/C-optimize-variables)