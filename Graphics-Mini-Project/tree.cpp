#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include<cmath>

void drawLeafLayer(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void tree(float x1, float x2) {
    // Draw trunk with gradient effect
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075);  // Brown color
    glVertex2f(x1, x2);
    glVertex2f(x1+0.06, x2);
    
    glColor3f(0.402, 0.200, 0.030);  // Darker brown at the top
    glVertex2f(x1+0.055, x2+0.15);
    glVertex2f(x1+0.005, x2+0.15);
    glEnd();

    // Draw multiple layers of leaves with different sizes and slightly different colors
    float centerX = x1 + 0.03;
    float baseY = x2 + 0.25;
    
    // Bottom layer (largest and darkest)
    drawLeafLayer(centerX, baseY, 0.12, 0.0, 0.5, 0.0);
    
    // Middle layer
    drawLeafLayer(centerX, baseY + 0.05, 0.09, 0.0, 0.6, 0.0);
    
    // Top layer (smallest and brightest)
    drawLeafLayer(centerX, baseY + 0.1, 0.06, 0.0, 0.7, 0.0);
}