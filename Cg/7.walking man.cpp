#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;

class walkingman {
    int rhx, rhy; // Right hand X, Right hand Y
public:
    void draw(int i); // Method to draw walking animation
    void draw(int x, int y); // Method to draw random lines (decorations)
};

// Function to draw walking man animation
void walkingman::draw(int i) {
    line(20, 380, 580, 380);  // Ground line
    if(i % 2) {
        // Left leg
        line(25 + i, 380, 35 + i, 340);
        // Right leg
        line(45 + i, 380, 35 + i, 340);
        // Left hand
        line(35 + i, 310, 25 + i, 330);
        delay(20);
    } else {
        // Right leg
        line(35 + i, 340, 35 + i, 310);
        // Right hand
        line(35 + i, 310, 40 + i, 330);
        delay(20);
    }
    line(35 + i, 340, 35 + i, 310);
    circle(35 + i, 300, 10);  // Head
    line(35 + i, 310, 50 + i, 330);  // Right hand
    line(50 + i, 330, 50 + i, 280);
    line(15 + i, 280, 85 + i, 280);  // Umbrella line
    arc(50 + i, 280, 180, 0, 35);    // Umbrella arc
    arc(50 + i, 245, 180, 0, 5);     // Umbrella arc
    arc(55 + i, 330, 0, 180, 5);     // Umbrella arc
}

// Function to draw random lines for decoration
void walkingman::draw(int x, int y) {
    int j;
    rhx = x;
    rhy = y;
    for(j = 0; j < 100; j++) {
        outtextxy(rand() % rhx, rand() % (rhy - 50), "|");
        setcolor(WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int rhx, rhy, j, i;
    walkingman obj;

    initgraph(&gd, &gm, NULL);

    // Loop to animate the walking man
    for(i = 0; i < 500; i++) {
        obj.draw(i);  // Draw walking man
        rhx = getmaxx();
        rhy = getmaxy();
        obj.draw(rhx, rhy);  // Draw random lines
        delay(150);  // Slow down the animation
        cleardevice();  // Clear screen for next frame
    }

    getch();  // Wait for a key press before exiting
    closegraph();  // Close the graphics mode

    return 0;
}