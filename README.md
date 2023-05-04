# 42_minitalk
*The purpose of this project is to code a small data exchange program
using UNIX signals.*

CONTENTS:
1. Project instructions
2. Personal notes

## Project instructions
- Name your executable files client and server.
- You have to turn in a Makefile which will compile your source files. It must not
relink.
- You can definitely use your libft.
- You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
- Your program mustn’t have memory leaks.
- You can have one global variable per program (one for the client and one for
the server), but you will have to justify their use.
- In order to complete the mandatory part, you are allowed to use the following
functions:
 - write
 - ft_printf and any equivalent YOU coded
 - signal
 - sigemptyset
 - sigaddset
 - sigaction
 - kill
 - getpid
 - malloc
 - free
 - pause
 - sleep
 - usleep
 - exit

## Mandatory Part
You must create a communication program in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
 - The server PID.
 - The string to send.
- The client must send the string passed as a parameter to the server.
- **Once the string has been received, the server must print it.**ℹ️
- The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
> ℹ️ 1 second for displaying 100 characters is way too much!

- Your server should be able to receive strings from several clients in a row without
needing to restart.
- The communication between your client and your server has to be done only using
UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.
>  ℹ️ Linux system does NOT queue signals when you already have pending
signals of this type!

## Bonus part
Bonus list:
- The server acknowledges every message received by sending back a signal to the
client.
- Unicode characters support!


# Personal notes

After thinking and consulting my ideas with my peers, I have decided to use the following approach:
- As only 2 signals are availabe to move information among client and server, the obvious way of handling it is interpret it as binary data sequence. (`SIGUSR1` = 0, `SIGUSR2` = 1)
- For optimal behaviour, I have decided to split the sent data into 2 sections.
 - First, the **`client`** performs `strlen()` of the string to send `string_length` to the server.
 This `string_length` number in its binary form will be transferred as first part of the binary sequence sent to the server.
 - Second, the characters of the actual string are being sent in their binary form to the client untill it reaches the `'\0'`.
 
- The **`server`** has a global control data structure in which are various variables which save current state of the operation, which bit of which byte is the last received, if it was already processed, pid of the client transmitting etc.
 - First server awaits 32 bits to complete the `string_length` number. After receiving all bits of this number, a malloc of `string_length` length is created and will be operated upon. This malloc is first filled with `'\0'`s so we can do bitwise operations  starting from zero.
  - Then it is adding each received bit to it's corresponding position in it's corresponding byte of the allocated memory untill reached the last position according the `string_length` variable.
  - Once the transmission is finished, the string is printed and `free()` is performed to not leak data on exit as the subject does not specify any other use of this received string and the server program will terminate itself.
  - As no other signals shall be used, I can not protect from memory leaks if i terminate the program in the middle of a transmission with `CTRL+C` for example.

- Server performs various **`control checks`** along the way.
  - **Bits mismatch detection:**
  When received bits reach and complete the `string_length` position, server checks, it is a `'\0'` because strlen() and strings itself terminate on `'\0'`. If it is not `'\0'`, something is wrting and `bits mismatch error message` is shown.
  - **Timeout detection**:
  If a transmission started (server received some SIGUSR1 / SIGUSR2 signal / signals) and no next signals received within 5 seconds, and the transmission did not completes, then a `timeout` occurs, shows `timeout error mesage` and the server environment resets to await another message from start.
  - **Avoid simultaneous transmissions to a single server:**
  When a transmission starts, server stores `initial_pid` value of PID of the first signal received and handles only the signals received from this particular PID.

And that's all.
...anyways, it's waaay more than the mandatory requirements.
 
