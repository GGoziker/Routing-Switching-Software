# Routing Switching Software
An application for my CSS432 class (Computer Networking).

### Project Objective:
To create programs that simulate receiving a packet, processing it, looking up the output interface in the table, and forwarding it.

##### Components
###### Router:
* A struct that holds an IPv4 packet.
* A function that reads necessary header information for the packet type, looks up what output port to send the packet out on, and returns that value.
* Use principle of longest match to determine output port.
* Main driver function to generate packets that test routing functionality and output the results in the format "Packet from IP to IP was routed on interface X".

###### Switch:
* A struct that holds an Ethernet frame.
* A function that reads necessary header information for the packet type, looks up what output port to send the packet out on and returns that value.
* Learn the table from packets that travel through the switch.
* Main driver function to generate packets that test switching functionality and output the results in the format "Frame from MAC to MAC was switched onto interface(s) X".

##### Deployment
* Run testUI.java first (server), then run softTokenUI.java (client)
* Both components are designed to be run on the same device. Port numbers are hardcoded.

##### Notes
* The router and switch should each have at least 4 network interfaces.
