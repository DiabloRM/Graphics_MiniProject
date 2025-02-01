// bird.cpp
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <cmath>
#include <vector>

// Bird structure to hold position, speed, and wing angle
struct Bird {
    float x, y;
    float speedX, speedY;
    float wingAngle;
    bool wingUp;
    float color[3];  // RGB color for each bird
};

// Initialize birds vector
std::vector<Bird> birds;

// Add initialization in a function
void initializeBirds() {
    // Initialize birds with different colors
    birds = {
        {0.0, 0.5, 0.0002, 0.0001, 0.0, true, {0.2, 0.2, 0.2}},    // Dark grey
        {0.2, 0.6, 0.00015, 0.00012, 0.0, true, {0.4, 0.4, 0.4}},  // Medium grey
        {-0.2, 0.7, 0.00025, 0.00008, 0.0, true, {0.3, 0.3, 0.3}}, // Grey
        {0.4, 0.8, 0.00018, 0.0001, 0.0, true, {0.25, 0.25, 0.25}}, // Dark grey
        {-0.4, 0.55, 0.00022, 0.00014, 0.0, true, {0.35, 0.35, 0.35}} // Light grey
    };
}

// Function to draw a bird at given coordinates with wing flapping
void drawBird(float x, float y, float wingAngle) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    
    // Body (oval shape)
    glColor3f(0.2, 0.2, 0.2);  // Dark grey for body
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float dx = 0.03 * cosf(theta);  // Increased width of body
        float dy = 0.02 * sinf(theta);  // Increased height of body
        glVertex2f(dx, dy);
    }
    glEnd();

    // Left wing
    glPushMatrix();
    glRotatef(wingAngle, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);  // Slightly lighter grey for wings
    glVertex2f(-0.01, 0.0);    // Wing base
    glVertex2f(-0.05, 0.04);   // Wing tip
    glVertex2f(-0.03, -0.02);  // Wing back
    glEnd();
    glPopMatrix();

    // Right wing
    glPushMatrix();
    glRotatef(-wingAngle, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.01, 0.0);    // Wing base
    glVertex2f(0.05, 0.04);   // Wing tip
    glVertex2f(0.03, -0.02);  // Wing back
    glEnd();
    glPopMatrix();

    // Tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.25, 0.25, 0.25);  // Dark grey for tail
    glVertex2f(-0.02, -0.01);    // Tail base left
    glVertex2f(0.02, -0.01);     // Tail base right
    glVertex2f(0.0, -0.05);      // Tail tip
    glEnd();

    // Beak
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.6, 0.0);  // Orange-yellow for beak
    glVertex2f(0.03, 0.0);     // Beak base
    glVertex2f(0.06, 0.0);     // Beak tip
    glVertex2f(0.03, 0.01);    // Beak top
    glEnd();

    // Add eyes
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);  // Black color for eyes
    glVertex2f(0.02, 0.01);    // Eye position
    glEnd();

    glPopMatrix();
}

// Function to update bird positions and wing angles
void updateBirdPositions() {
    for (auto& bird : birds) {
        // Update position
        bird.x += bird.speedX;
        bird.y += bird.speedY;

        // Add slight vertical oscillation for more natural movement
        bird.y += 0.0001 * sinf(bird.x * 10.0);

        // Change direction if the bird reaches the edge of the window
        if (bird.x > 1.0 || bird.x < -1.0) {
            bird.speedX = -bird.speedX;
        }
        if (bird.y > 1.0 || bird.y < 0.3) {  // Keep birds above the ground
            bird.speedY = -bird.speedY;
        }

        // Update wing angle for flapping effect
        if (bird.wingUp) {
            bird.wingAngle += 2.0;  // Faster wing movement
            if (bird.wingAngle > 30.0) {  // Larger wing angle
                bird.wingUp = false;
            }
        } else {
            bird.wingAngle -= 2.0;
            if (bird.wingAngle < -30.0) {
                bird.wingUp = true;
            }
        }
    }
}
