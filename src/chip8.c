#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define CHIP8_VREG_COUNT 16     // V registers count
#define CHIP8_STACK_CAP  64     // Stack capacity
#define CHIP8_DH         64     // Display Height
#define CHIP8_DW         32     // Display Width
#define CHIP8_RAM_CAP    1024*4 // 4096 Addressable Memory

uint8_t  chip8_vregs[CHIP8_VREG_COUNT]; // Registers V0 - V15
uint16_t chip8_idx_reg;                 // Index register
uint16_t chip8_prog_counter;            // Program Counter
uint8_t  chip8_stack[CHIP8_STACK_CAP];  // 64-Byte Stack
uint8_t  chip8_sp;                      // Stack Pointer

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
    chip8_load_fontset();
    return 0;
}
