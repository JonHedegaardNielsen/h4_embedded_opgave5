
# Opgave 5 - UART handshake og ringbuffer

Programmet bruger begge USART'er på ATmega328PB:

- `USART0` er som udgangspunkt den valgte modtage-UART (CP2102-forbindelsen).
- `USART1` bruges til at sende brugernavnet og til at sende de modtagne tegn tilbage.

Forløbet er:

1. Der ventes på `:` på modtage-UART'en.
2. Når `:` modtages, sendes `:Betjenten:` på den anden UART.
3. Der ventes på `;` på modtage-UART'en.
4. Når `;` modtages, startes ringbufferen, og alle modtagne tegn sendes tilbage
   på den anden UART, indtil ringbufferen er tom.

Indstillinger ændres i `include/ProjectDefines.h`:

- `USERNAME` er brugernavnet, der sendes i handshaket.
- `RX_UART` vælger modtage-UART (`0` = USART0/CP2102, `1` = USART1).
- `BAUD` er baudraten på begge UART'er.

## Getting Started

- Press **Ctrl + Shift + B** to build the project.
- Open the Command Palette (**Ctrl + Shift + P**) and search for "MPLAB" to discover other available commands.
- Need more help? Visit the [MPLAB support site](https://www.microchip.com/en-us/support/all) or the [MPLAB website](https://www.microchip.com).
- Found a bug or have feedback? Open the Command Palette (**Ctrl + Shift + P**) and run
  **MPLAB: Report Issue** to let us know.

## Project Structure

- 📦 `_build` — The [CMake build tree](https://cmake.org/cmake/help/latest/manual/cmake.1.html#introduction-to-cmake-buildsystems); safe to delete, regenerated on next build.
- 📦 `cmake` — Generated [CMake](https://cmake.org/) files; can be deleted if `user.cmake` has not been added.
- 🚀 `out` — Final build artifacts.
- ⚙️ `.vscode` — VS Code workspace configuration; see [VS Code docs](https://code.visualstudio.com/docs/getstarted/settings).
- ⚙️ `.vscode/settings.json` — Workspace-specific settings.
- 📝 `.vscode/..mplab.json` — The MPLAB project file. ❗ Should not be deleted.
