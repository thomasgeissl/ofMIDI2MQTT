# ofMIDI2MQTT

## Build status
[![Build Status](https://travis-ci.com/thomasgeissl/ofMIDI2MQTT.svg?branch=master)](https://travis-ci.com/thomasgeissl/ofMIDI2MQTT)

## Description
cli tool that converts midi messages to mqtt messages. it can be used to trigger events on web apps from your DAW.
documentation will follow.

## Installation
### osx
```
brew tap thomasgeissl/tools
brew install ofmidi2mqtt
# brew upgrade ofmidi2mqtt
```


```
ofMIDI2MQTT -h broker.shiftr.io -p 1883 -t vgig/HALLID/orchestra -u try -r try

```
