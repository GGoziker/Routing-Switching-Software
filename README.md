# Routing Switching Software
An application for my CSS432 class (Computer Networking).

### Project Objective:
To create programs that simulate receiving a packet, processing it, looking up the output interface in the table, and forwarding it.

##### Components
###### Router:
* A struct that holds an IPv4 packet.
* A function that reads necessary header information for the packet type, looks up what output port to send the packet out on, and returns that value.
* Use principle of longest match to determine output port.

##### Deployment
* Run testUI.java first (server), then run softTokenUI.java (client)
* Both components are designed to be run on the same device. Port numbers are hardcoded.

##### Notes
* [SHA2](https://en.wikipedia.org/wiki/SHA-2) used to generate password
* See [Assignment_2.pdf](https://github.com/GGoziker/Onetime-Password-System/blob/master/Assignment_2.pdf) for password generation details
