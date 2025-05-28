# Networked Connect 4

**Networked Connect 4** is a networked version of the classic Connect 4 game, built in C++ using [Raylib](https://www.raylib.com/) and custom socket programming. This project was developed during my final semester at Champlain College to explore the fundamentals of multiplayer networking and client-server architecture.

## Features
- **Multiplayer Networking**: Two players can connect and play over a local network using a custom TCP socket system.
- **Classic Ruleset**: Implements all standard Connect 4 rules, including vertical, horizontal, and diagonal win detection.
- **User-Friendly Interface**: Built with Raylib, the game features simple visual feedback for turn-taking, and win/loss states.
- **Connection Management**: Handles player joining, game state sync, and network disconnection.

## Development Highlights
- **Socket Programming**: Built custom client-server communication using C++ sockets to manage turn-based input and state syncing.
- **State Synchronization**: Designed a protocol to keep both players’ boards synchronized in real time using serialized move data.
- **Turn Enforcement**: Ensured fair gameplay by locking input on the client side based on turn state received from the server.
- **Minimal Latency**: Optimized communication loop to create a responsive experience across local connections.

## What I Learned
This project gave me practical experience with real-time multiplayer networking and helped me better understand the challenges of maintaining synchronized state across clients. It also strengthened my debugging and testing skills, especially when dealing with disconnections and client syncing. 

For more info on the development process, refer to the [full blog post](https://jeffreypopek.dev/blog-grav-sim.html).

## How to Run
1. Open a terminal window for the **server** and run:

2. Open a terminal window for each **client** and run:
  
3. Follow on-screen instructions to connect and begin playing.

## Controls
- **Enter/Space**: Drop a piece in the selected column
- **Escape**: Quit the game
