The report is in the Latex folder. 
    The report will be added step by step. 
    Need to read more paper to find the messages fit for the Frame.

31.08.17: begin to code the first simulation. 
    Program language: Java is good for the further extension.
                C/c++ has many examples.
                Python may be easy.
04.09.17: learn the usage of docker
08.09.17: 
    tasks:
        1. figure out which one is used in NC(TCP or UDP)
        2. build a socket code that can communicate between C/S
        3. build the simple frame in detail
        4. read the paper Towards Effective Intra-Flow Network Coding in Software Defined Wireless Mesh Networks
        
14.09.17
    There is a method called “Coded TCP”
    Instead of ACK, they modify the TCP with a 'seen' back.
    I think I can add some similiar functions that I need to my UDP communication.
19.09.17
    In Towards Effective Intra-Flow Network Coding in Software Defined Wireless Mesh Networks, they didn't talk about TCP or UDP or how to solve the retransmission problem in TCP.
20.09.17
    Already have a udp communication program that runs on the local, still try to find the way to run that on different dockers.
22.09.17
    The client docker can send data to the server and the server can repeatedly receive them and send an ACK back.
25.09.17
    Combine the docker with the mininet(control the dockers by multi-terminals)
    The client can send data to the server repeatedly, but without receiving acks from the server. The problem comes from the packet loss. When the packet or the ack is lost, the client can't receive an ACK, and it blocks until one ACK is received. But another ACK needs new packet from client
    Next step: use the select() to build a timeout mechanism, so that the client don't wait for the ACK that won't come.
