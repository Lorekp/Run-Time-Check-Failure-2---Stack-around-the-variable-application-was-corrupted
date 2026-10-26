# SFML tile-game debugging example

A small C++/SFML prototype preserved under the repository name **Run-Time-Check-Failure-2---Stack-around-the-variable-application-was-corrupted**. It contains a menu and an experimental tile-based movement system for a game titled “Labyrinth.” Treat this as source material for investigating a runtime failure, rather than a finished game or a confirmed fix.

## What is implemented

- A 1920 × 1080 menu with Play, Options, About, and Quit Game entries.
- Keyboard and mouse menu-selection handlers.
- A hard-coded 20 × 20 grid of 64-pixel tiles, a player, a start arrow, and one slanted tile.
- Texture caching by filename and a shared rendering helper.
- Movement routines that scan for nonempty tiles, with experimental tile-direction changes and console diagnostics.

Options and About are placeholders: their current handlers fall through to the quit behavior. The supplied board does not place a goal tile, although a goal check exists.

## Source layout

| Files | Responsibility |
| --- | --- |
| `Main.cpp` | Creates the windows, routes menu events, and starts the game loop. |
| `MainMenu.h`, `MainMenu.cpp` | Menu text, selection state, and navigation. |
| `Application.h`, `Application.cpp` | Board construction, player input, and movement routines. |
| `AssetManager.h`, `AssetManager.cpp` | Singleton-style texture cache. |
| `RenderCycle.h` | Draws the background, tiles, and player. |

## Build and runtime requirements

The repository contains source files only. There is no Visual Studio solution, CMake project, Makefile, dependency lockfile, or build/test script, so there is no repository-supported build command to run unchanged.

Reconstructing a local build requires a C++ toolchain and SFML headers/libraries compatible with the APIs used here. The source uses the SFML 2-style API; no exact SFML release, compiler version, or original linker configuration is recorded. Add the four `.cpp` files and their headers to a local project and configure SFML for that toolchain.

The following runtime assets are referenced but **not included**. Texture paths are relative to the process working directory:

- `EmptyWhiteTile.png`, `Arrow.png`, `Player.png`, `SlantedLU.png`, `Goal.png`
- `SlantedLUArrowRight.png`, `SlantedLUArrowLeft.png`, `SlantedLUArrowUp.png`, `SlantedLUArrowDown.png`
- `FlatHArrowUp.png`, `FlatHArrowDown.png`, `FlatVArrowL.png`, `FlatVArrowR.png`
- `fonts/SquaresBoldFree.otf`

Supply appropriately licensed assets at those paths before attempting an interactive run. Texture loading currently does not check for failure.

## Controls and debugging status

The intended menu controls are Up/Down and Enter, plus mouse hover/click. Arrow keys feed the game’s movement handlers; Escape closes the game window. These controls describe the implementation’s intent, not a verified playable build.

Several defects remain visible in the source:

- The menu initializes its selected index to `-1`, then indexes the text array with that value on the first Down press or first hover over an item. This is an out-of-bounds access.
- All four directional input branches call `movePlayerRight`; the other movement routines are not connected to those inputs.
- Some menu event cases fall through, and the mouse-button branch reads the keyboard event field.
- The movement clock is recreated inside the loop and adds one second to its measured delta, so movement timing needs correction.

The invalid menu index is relevant to investigating memory corruption, but the repository contains no debugger trace or regression test establishing the precise cause of the failure in its name. No fix is included here. There are no automated tests or CI workflows. A useful first manual debugging check, once the build and assets are restored, is to inspect the selected index while entering the menu and selecting its first item.

## Attribution and license

This source snapshot was uploaded to Lorekp’s repository. It uses SFML; the repository does not document the provenance of the missing artwork or font. No project license is included.
