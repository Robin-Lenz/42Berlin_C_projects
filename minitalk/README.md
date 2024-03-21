# Minitalk

Minitalk is a small data exchange program designed for UNIX systems utilizing signals for communication.
# Usage

    Compile the Project

```
make
```
    Start the Server

```
./server
```
Upon starting, the server will display its PID (Process ID) in the terminal.

    Sending Messages to the Server
    To send a message to the server, execute the client program with two arguments: the PID of the server and the message to be sent.

```
./client <server-PID> "message to send"
```

You can send multiple messages to the server without the need to restart it.
Bonus Features

For the bonus segment of the project, the server sends a confirmation message back to the client upon receiving the message. Although this functionality is implemented in the mandatory part, it's explicitly demonstrated in the client/server_bonus.

    Compile with Bonus Features

```
make bonus
```

    Start the Server with Bonus Features

```
./server_bonus
```

Upon starting, the server will display its PID in the terminal.

    Sending Messages with Bonus Features
    Similar to before, use the client program with two arguments: the PID of the server and the message to be sent.

```
./client_bonus <server-PID> "message to send"
```

This version explicitly demonstrates the confirmation message being printed to the terminal.