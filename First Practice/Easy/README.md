# Readme
```
About TCP Handshake Example
Lang : C
Compiler : G++
``` 

### File Introduction
```
Server.c : Source Code about Server code
Client.c : Source Code about Client code
./Server : Server Release File 
./Client : Client Release File 
```

### Installion
```
$ sudo apt update
$ sudo apt install g++
$ g++ --version
```

### User Guide
```
Step1 : Compile Server Code & Client Code, after this step you can see ./Server & ./Client these release file in floder
    $ g++ Server.c -o Server
    $ g++ Client.c -o Client

Step2 : Execute release file to validate the code.
        * Remember, you should execute ./Server first to ensure your server on listening
    $ ./Server
    $ ./Client

Step3 : try to input something in Client terminal
```