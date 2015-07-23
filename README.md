# eplayerendpoint
produced by our own element based on kurento service

## Searching
1. After creating eplayerendpoint by shell commend, modify the parameter in eplayerendpoint/src/server/interface/eplayerendpoint.eplayerendpoint.kmd.json
  * remoteClass "extend": object-oriented class of eplayerendpointImpl（e.g. Filter，UriEndpoint）
2. Modify the file, interface/eplayerendpoint.eplayerendpoint.kmd.json, can affect most of the structure in eplayerendpointImpl
  * Modify remoteClasses "constructor" : affect everything related to constructor (e.g. constructor parameter)
  * Add remotrClasses "method": Add any function derived from eplayerendpointImpl

## Question
1. How to catch the config from eplayerendpoint/src/server/interface by code generator?
2. Try to figure out the meaning of parameter "event", "properties" in eplayerendpoint.eplayerendpoint.kmd.json file works.

## Reminder
Re-install everything when you modify the interface/eplayerendpoint.eplayerendpoint.kmd.json
* rm -rf eplayerendpoint
* kurento-module-scaffold.sh eplayerendpoint ./
* cd eplayerendpoint
* vim src/server/interface/eplayerendpoint.eplayerednpoint.kmd.json
* mkdir build
* cd build
* cmake ..
* make -j4
