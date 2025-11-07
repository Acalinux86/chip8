#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <SDL2/SDL.h>

#define CHIP8_VREG_COUNT 16     /* V registers count */
#define CHIP8_STACK_CAP  64     /* Stack capacity */
#define CHIP8_DH         64     /* Display Height */
#define CHIP8_DW         32     /* Display Width */
#define CHIP8_RAM_CAP    1024*4 /* 4096 Addressable Memory */

#define CHIP8_WINDOW_HEIGHT 800 /* SDL Window Height */
#define CHIP8_WINDOW_WIDTH  600 /* SDL Window Width */

uint8_t  chip8_vregs[CHIP8_VREG_COUNT]; // Registers V0 - V15
uint8_t  chip8_stack[CHIP8_STACK_CAP];  // 64-Byte Stack
uint8_t  chip8_sp;                      // Stack Pointer
uint16_t chip8_idx_reg;                 // Index register
uint16_t chip8_prog_counter;            // Program Counter

uint8_t chip8_d_timer; // Delay Timer
uint8_t chip8_s_timer; // Sound Timer

static uint8_t chip8_frame_buffer[CHIP8_DH][CHIP8_DW] = {0}; // Frame Buffer
static uint8_t chip8_memory[CHIP8_RAM_CAP]; // Chip8 RAM

void chip8_load_fontset()
{
    assert(0 && "chip8_load_fontset unimplemented");
}

int main(void)
{
    // chip8_load_fontset();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "[ERROR] Failed to Initialize SDL: %s\n", SDL_GetError());
        return 1; // Exit if Error
    }

    SDL_Window *window = SDL_CreateWindow("Chip8",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          CHIP8_WINDOW_HEIGHT, CHIP8_WINDOW_WIDTH,
                                          SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fprintf(stderr, "[ERROR] Failed to Create Window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        fprintf(stderr, "[ERROR] Failed to Create Renderer: %s\n", SDL_GetError());
        return 1;
    }

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: quit = true; break;
            }
        }

        // Update
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
