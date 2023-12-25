#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

int main() {
    const char* audioPath = "exit sound (run dari program).mp3";
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");

    // Initialize Windows Multimedia API
    if (waveOutGetNumDevs() == 0) {
        fprintf(stderr, "No audio devices available\n");
        return 1;
    }

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                
            }
        }
        printf("\x1b[H");
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }

        // Sleep for 30 milliseconds
        Sleep(30);

        // Play audio
        if (waveOutGetNumDevs() > 0) {
            // Use Windows Multimedia API to play audio
            PlaySound(audioPath, NULL, SND_FILENAME | SND_ASYNC);
        }
    }

    return 0;
}

