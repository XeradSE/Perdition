# Perdition

A terminal-based roguelike dungeon crawler written in C++, featuring procedural generation, a turn-based combat system, and ASCII rendering via FTXUI.

> Work on hold ! (I prefer to wait for the motivation to come back than to rush the project)

## Features (planned)

- Procedurally generated dungeons with rooms and corridors
- Multiple floors with increasing difficulty
- Turn-based combat with stats (attack, defense, HP)
- Enemy AI with distinct behaviors (Goblin, Troll, Boss...)
- Player progression system (experience, levels, stats)
- Inventory system with weapons and potions
- Fog of war — explored tiles remain visible, unseen tiles are hidden
- ASCII rendering in the terminal via FTXUI

## Architecture

The project is split into clearly separated layers, keeping game logic fully independent from rendering:

- **Entity / Player / Enemy** — entity hierarchy using polymorphism. Each enemy type overrides `update()` with its own behavior.
- **Tile / Room / Map** — world representation. `Map` handles procedural generation: random room placement with intersection checks, L-shaped corridors, and stair placement.
- **CombatSystem** — handles combat resolution between entities.
- **Inventory / Item** — player inventory with weapons and consumables.
- **GameEngine** — main game loop, orchestrates entities, map, and combat.
- **Renderer** — all FTXUI rendering, completely decoupled from game logic.

## Dependencies

- [FTXUI](https://github.com/ArthurSonzogni/FTXUI) — terminal UI library, automatically fetched via CMake FetchContent

No manual installation required — FTXUI is downloaded and compiled automatically at build time.

## Build & Run

**Requirements:** g++ or clang++, CMake 3.16+, Git

```bash
# Clone the repository
git clone https://github.com/XeradSE/Perdition.git
cd Perdition

# Configure and build
mkdir build
cd build
cmake ..
cmake --build .

# Run
./Perdition
```

## Author

Made as a personal C++ project to practice procedural generation, OOP architecture, and terminal rendering.
