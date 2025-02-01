// main.cpp
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <cmath>
#include "surrounding.cpp"
#include "house.cpp"
#include "tree.cpp"
#include "bird.cpp" // Include the bird header

// Global variables to keep track of boat positions and sun position
float boat1X = 0.0;
float boat2X = 0.0;
float sunY = 0.7; // Initial position of the sun

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawSun(float cx, float cy, float r) {
    // Draw the main sun circle
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // Draw sun rays
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.8, 0.0);  // Slightly darker yellow for rays
    for (int i = 0; i < 12; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / 12.0f;
        float x1 = (r * 1.1) * cosf(theta);
        float y1 = (r * 1.1) * sinf(theta);
        float x2 = (r * 1.5) * cosf(theta);
        float y2 = (r * 1.5) * sinf(theta);
        glVertex2f(x1 + cx, y1 + cy);
        glVertex2f(x2 + cx, y2 + cy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw rectangle with sky blue color
    glBegin(GL_POLYGON);
    glColor3f(0.529, 0.808, 0.922); // Sky blue color
    glVertex2f(-1, -1);   // Bottom-left corner
    glVertex2f(1, -1);    // Bottom-right corner
    glVertex2f(1, 1);     // Top-right corner
    glVertex2f(-1, 1);    // Top-left corner
    glEnd();

    // Ground with new color
    glBegin(GL_POLYGON);
    glColor3f(0.686, 0.933, 0.373);  // Light yellow-green color
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();

    drawSun(-0.7, sunY, 0.1);

    float x1 = -1.6, y1 = 0.5, x2 = -1.0, y2 = 0.5, x3 = -1.3, y3 = 0.8;

    // Draw triangle
    for (int i = 0; i <= 6; i++) {
        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.5, 0.0); // Green color
        glVertex2f(x1, y1);  // Bottom-left corner
        glVertex2f(x2, y2);   // Bottom-right corner
        glVertex2f(x3, y3);      // Top corner
        glEnd();

        x1 += 0.4;
        x2 += 0.4;
        x3 += 0.4;
    }

    glBegin(GL_LINES);
    glLineWidth(5.0);
    glColor3f(0.0, 0.0, 0.0); // Black color
    glVertex2f(-1, 0.5);    // Start point (left)
    glVertex2f(1, 0.5);     // End point (right)
    glEnd();

    // River
    glBegin(GL_POLYGON);
    glColor3f(0.529, 0.808, 0.922);
    glVertex2f(-1, 0.05);
    glVertex2f(1, 0.05);
    glVertex2f(1, 0.5);
    glVertex2f(-1, 0.5);
    glEnd();

    // Boat 1 moving to the right
    glPushMatrix();
    glTranslatef(boat1X, 0.0, 0.0);
    
    // Hull
    glBegin(GL_POLYGON);
    glColor3f(205/255.0, 170/255.0, 125/255.0);
    glVertex2f(0.39, 0.3);
    glVertex2f(0.61, 0.3);
    glVertex2f(0.56, 0.25);
    glVertex2f(0.44, 0.25);
    glEnd();

    // Sail
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);  // White sail
    glVertex2f(0.5, 0.3);      // Base of sail
    glVertex2f(0.5, 0.5);      // Top of sail
    glVertex2f(0.58, 0.35);    // Right corner
    glEnd();

    // Mast
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(139/255.0, 69/255.0, 19/255.0);  // Brown mast
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, 0.5);
    glEnd();
    glPopMatrix();

    // Boat 2 moving to the left
    glPushMatrix();
    glTranslatef(boat2X, 0.0, 0.0);
    
    // Hull
    glBegin(GL_POLYGON);
    glColor3f(205/255.0, 170/255.0, 125/255.0);
    glVertex2f(-0.64, 0.1);
    glVertex2f(-0.42, 0.1);
    glVertex2f(-0.47, 0.05);
    glVertex2f(-0.59, 0.05);
    glEnd();

    // Sail
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);  // White sail
    glVertex2f(-0.53, 0.1);    // Base of sail
    glVertex2f(-0.53, 0.3);    // Top of sail
    glVertex2f(-0.45, 0.15);   // Right corner
    glEnd();

    // Mast
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(139/255.0, 69/255.0, 19/255.0);  // Brown mast
    glVertex2f(-0.53, 0.1);
    glVertex2f(-0.53, 0.3);
    glEnd();
    glPopMatrix();

    house();
    drawCircle(-0.8, -0.15, 0.03, 100);
    surrounding();

    tree(-0.87, -0.75);
    tree(0.3, -0.60);
    tree(0.7, -0.6);
    tree(-0.3, -0.05);

    // Draw and update bird positions
    for (const auto& bird : birds) {
        drawBird(bird.x, bird.y, bird.wingAngle);
    }

    glFlush();
}

void updatePositions() {
    boat1X += 0.0005; // Reduced speed (half of previous)
    boat2X -= 0.0005; // Reduced speed (half of previous)

    // Reset positions if boats reach screen edges (adjusted to stay visible)
    if (boat1X > 0.9) {  // Changed from 1.5 to 0.9
        boat1X = -0.9;   // Changed from -1.5 to -0.9
    }
    if (boat2X < -0.9) { // Changed from -1.5 to -0.9
        boat2X = 0.9;    // Changed from 1.5 to 0.9
    }

    // Sun moving up until it reaches the top (increased speed)
    if (sunY < 0.9) {
        sunY += 0.00005;  // 10x faster than before
    }

    updateBirdPositions();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 1500);
    glutCreateWindow("Village Environment");
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
    
    initializeBirds();  // Add this line
    
    glutDisplayFunc(display);
    glutIdleFunc(updatePositions); 
    glutMainLoop();
    return 0;
}
