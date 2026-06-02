#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cstring>

#define PI 3.14159265358979323846

int currentDisplay = 0;

struct {
    GLfloat position   = 0.0f;
    GLfloat speed      = 5.0f;
    GLfloat carposition= 0.0f;
    GLfloat carspeed   = 5.0f;
    GLfloat cloudPos1  = 0.0f;
    GLfloat cloudSpeed1= 1.0f;
    GLfloat cloudPos2  = 0.0f;
    GLfloat cloudSpeed2= 0.5f;
    GLfloat sunPosY    = 0.0f;
    GLfloat sunSpeed   = 0.5f;
    bool sunGoingDown  = true;
    bool isNight       = false;
    bool NightSound    = false;
    bool daySound      = false;
} E;

struct {
    GLfloat position   = 0.0f;
    GLfloat speed      = 5.0f;
    GLfloat cloudPos1  = 0.0f;
    GLfloat cloudSpeed1= 1.0f;
    GLfloat cloudPos2  = 0.0f;
    GLfloat cloudSpeed2= 0.5f;
    GLfloat sunPosY    = 0.0f;
    GLfloat sunSpeed   = 0.5f;
    bool sunGoingDown  = true;
    bool isNight       = false;
    bool daySound      = false;
    bool nightSound    = false;
} F;


struct {
    GLfloat position   = 0.0f;
    GLfloat speed      = 5.0f;
    GLfloat cloudPos1  = 0.0f;
    GLfloat cloudSpeed1= 1.0f;
    GLfloat cloudPos2  = 0.0f;
    GLfloat cloudSpeed2= 0.5f;
    GLfloat cloudPos3  = 0.0f;
    GLfloat cloudSpeed3= 2.0f;
    GLfloat cloudPos4  = 0.0f;
    GLfloat cloudSpeed4= 2.5f;
    GLfloat sunPosY    = 0.0f;
    GLfloat sunSpeed   = 0.5f;
    bool sunGoingDown  = true;
    bool isNight       = false;
} R;



void drawText(float x, float y, const char *text, void *font)
{
    glRasterPos2f(x, y);
    for (int i = 0; i < (int)strlen(text); i++)
        glutBitmapCharacter(font, text[i]);
}

void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawCircle(float x, float y, float radius, float r, float g, float b)
{
    int i;
    int triangleAmount = 40;
    float twicePi = 2.0f * PI;

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}


void coverPage()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    glColor3f(0.90f, 0.96f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-800, -600);
    glVertex2f( 800, -600);
    glVertex2f( 800,  600);
    glVertex2f(-800,  600);
    glEnd();

    // Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-730, -540);
    glVertex2f( 730, -540);
    glVertex2f( 730,  540);
    glVertex2f(-730,  540);
    glEnd();

    // Title
    glColor3f(0.0f, 0.0f, 0.35f);
    drawText(-360, 470, "AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH", GLUT_BITMAP_TIMES_ROMAN_24);
    drawText(-250, 430, "FACULTY OF SCIENCE & TECHNOLOGY",              GLUT_BITMAP_TIMES_ROMAN_24);

    // Project Proposal
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(-100, 350, "Project", GLUT_BITMAP_TIMES_ROMAN_24);
    drawText( -90, 315, "Spring 2025-26",   GLUT_BITMAP_HELVETICA_18);

    // Course Info
    drawText(-260, 240, "Course Title : Computer Graphics", GLUT_BITMAP_HELVETICA_18);
    drawText(-260, 205, "Course Code  : CSC4118",           GLUT_BITMAP_HELVETICA_18);
    drawText(-260, 170, "Section      : D",                 GLUT_BITMAP_HELVETICA_18);
    drawText(-260, 135, "Course Teacher: Mahfujur Rahman",  GLUT_BITMAP_HELVETICA_18);

    drawText(100, -520, "Press Right button",  GLUT_BITMAP_HELVETICA_18);

    // Project Title Box
    glColor3f(0.75f, 0.88f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-520, 35);
    glVertex2f( 520, 35);
    glVertex2f( 520, 95);
    glVertex2f(-520, 95);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-520, 35);
    glVertex2f( 520, 35);
    glVertex2f( 520, 95);
    glVertex2f(-520, 95);
    glEnd();

    drawText(-390, 58, "Project Title: Waves of Cox's Bazar: A Coastal Visualization", GLUT_BITMAP_HELVETICA_18);

    // Group Members
    drawText(-110, -20, "Group Members", GLUT_BITMAP_TIMES_ROMAN_24);

    // Table
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-420, -260);
    glVertex2f( 420, -260);
    glVertex2f( 420,  -60);
    glVertex2f(-420,  -60);
    glEnd();

    drawLine(-420, -110,  420, -110);
    drawLine(-420, -160,  420, -160);
    drawLine(-420, -210,  420, -210);
    drawLine(-100, -260, -100,  -60);
    drawLine( 160, -260,  160,  -60);

    drawText(-300,  -90, "Name",    GLUT_BITMAP_HELVETICA_18);
    drawText( -35,  -90, "ID",      GLUT_BITMAP_HELVETICA_18);
    drawText( 230,  -90, "Program", GLUT_BITMAP_HELVETICA_18);

    drawText(-390, -140, "Anindo Mahmood",     GLUT_BITMAP_HELVETICA_18);
    drawText( -70, -140, "23-55004-3",        GLUT_BITMAP_HELVETICA_18);
    drawText( 220, -140, "B.Sc. CSE",         GLUT_BITMAP_HELVETICA_18);

    drawText(-390, -190, "Rifat Hasan",       GLUT_BITMAP_HELVETICA_18);
    drawText( -70, -190, "23-55022-3",        GLUT_BITMAP_HELVETICA_18);
    drawText( 220, -190, "B.Sc. CSE",         GLUT_BITMAP_HELVETICA_18);

    drawText(-390, -240, "Nishat Tasnim Ema", GLUT_BITMAP_HELVETICA_18);
    drawText( -70, -240, "23-55028-3",        GLUT_BITMAP_HELVETICA_18);
    drawText( 220, -240, "B.Sc. CSE",         GLUT_BITMAP_HELVETICA_18);

    glFlush();
}


void instructionPage()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    glColor3f(0.90f, 0.96f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-800, -600);
    glVertex2f( 800, -600);
    glVertex2f( 800,  600);
    glVertex2f(-800,  600);
    glEnd();

    // Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-730, -540);
    glVertex2f( 730, -540);
    glVertex2f( 730,  540);
    glVertex2f(-730,  540);
    glEnd();

    // Title
    glColor3f(0.0f, 0.0f, 0.4f);
    drawText(-170, 450, "INSTRUCTION", GLUT_BITMAP_TIMES_ROMAN_24);

    // Instruction Box
    glColor3f(0.80f, 0.90f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-550, -250);
    glVertex2f( 550, -250);
    glVertex2f( 550,  300);
    glVertex2f(-550,  300);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-550, -250);
    glVertex2f( 550, -250);
    glVertex2f( 550,  300);
    glVertex2f(-550,  300);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(-500,  220, "1. Press W and S to Control Speed.",          GLUT_BITMAP_HELVETICA_18);
    drawText(-500,  140, "2. Press W in keyboard to move Faster.",      GLUT_BITMAP_HELVETICA_18);
    drawText(-500,   60, "3. Press S in keyboard to move Slower.",      GLUT_BITMAP_HELVETICA_18);
    drawText(-500,  -20, "4. Press Right Click of Mouse to Transition", GLUT_BITMAP_HELVETICA_18);
    drawText(-460,  -70, "   from One Scenario to Another.",            GLUT_BITMAP_HELVETICA_18);

    glFlush();
}

void SoundDay_E()
{
    PlaySound("freesound_community-car-horn-6408.wav",         NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("mixkit-small-waves-harbor-rocks-1208 (1).wav",  NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("freesound_community-ship-horn-6456.wav",        NULL, SND_ASYNC|SND_FILENAME);
}

void SoundNight_E()
{
    PlaySound("schorsch1964-night-atmosphere-with-crickets-374652.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void drawSun_E()
{
    glPushMatrix();
    glTranslatef(0.0f, E.sunPosY, 0.0f);
    drawCircle(600, 450, 60, 1.0f, 0.9f, 0.0f);
    glPopMatrix();
}

void updateSun_E(int value)
{
    if (E.sunGoingDown)
        {
        E.sunPosY -= E.sunSpeed;
        if (E.sunPosY < -300) E.sunGoingDown = false;
        }
    else
    {
        E.sunPosY += E.sunSpeed;
        if (E.sunPosY > 0)   E.sunGoingDown = true;
    }

    if (E.sunPosY < -220)
        E.isNight = true;
    else if (E.sunPosY > -180)
      E.isNight = false;

    glutPostRedisplay();
    glutTimerFunc(25, updateSun_E, 0);
}

void drawClouds_E()
{
    glPushMatrix();
    glTranslatef(E.cloudPos1, 0.0f, 0.0f);
    drawCircle(-500, 480, 40, 1.0f, 1.0f, 1.0f);
    drawCircle(-460, 490, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(-420, 480, 40, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(E.cloudPos2, 0.0f, 0.0f);
    drawCircle(100, 520, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(140, 530, 45, 1.0f, 1.0f, 1.0f);
    drawCircle(180, 520, 35, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
}

void updateCloud1_E(int value)
{
    if (E.cloudPos1 > 1500.0f)
        E.cloudPos1 = -800.0f;
        E.cloudPos1 += E.cloudSpeed1;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud1_E, 0);
}

void updateCloud2_E(int value)
{
    if (E.cloudPos2 < -900.0f)
        E.cloudPos2 = 800.0f;
    E.cloudPos2 -= E.cloudSpeed2;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud2_E, 0);
}

void drawShip_E()
{
    glPushMatrix();
    glTranslatef(E.position, 0.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(260, 220);
    glVertex2i(320, 180);
    glVertex2i(540, 180);
    glVertex2i(600, 220);
    glEnd();

    glColor3f(0.628f, 0.503f, 0.394f);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 220);
    glVertex2i(340, 280);
    glVertex2i(380, 220);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_QUADS);
    glVertex2i(370, 240);
    glVertex2i(520, 240);
    glVertex2i(520, 220);
    glVertex2i(380, 220);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2i(400, 240);
    glVertex2i(480, 240);
    glVertex2i(480, 280);
    glVertex2i(400, 280);
    glEnd();

    glPopMatrix();
}

void update_E(int value)
{
    if (E.position < -1500.0f)
        E.position = 800.0f;
    E.position = E.position - E.speed;
    glutPostRedisplay();
    glutTimerFunc(25, update_E, 0);
}

void Car_E()
{
    glPushMatrix();
    glTranslatef(E.position, 0.0f, 0.0f);

    //Car body
    glColor3f(0.836f, 0.469f, 0.051f);
    glBegin(GL_QUADS);
    glVertex2i(300, -160);
    glVertex2i(300, -260);
    glVertex2i(700, -260);
    glVertex2i(700, -160);
    glEnd();

    glColor3f(0.836f, 0.469f, 0.051f);
    glBegin(GL_QUADS);
    glVertex2i(300, -160);
    glVertex2i(400, -60);
    glVertex2i(500, -60);
    glVertex2i(500, -160);

    glColor3f(0.836f, 0.469f, 0.051f);
    glBegin(GL_QUADS);
    glVertex2i(300, -160);
    glVertex2i(240, -200);
    glVertex2i(240, -260);
    glVertex2i(300, -260);

    glColor3f(0.836f, 0.469f, 0.051f);
    glBegin(GL_QUADS);
    glVertex2i(500, -60);
    glVertex2i(500, -160);
    glVertex2i(700, -160);
    glVertex2i(700, -60);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2i(500, -60);
    glVertex2i(520, -60);
    glVertex2i(520, -160);
    glVertex2i(500, -160);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2i(270, -180);
    glVertex2i(300, -160);
    glVertex2i(700, -160);
    glVertex2i(700, -180);
    glEnd();

    //wheel 1
    drawCircle(400, -260, 40, 0.0f, 0.0f, 0.0f);
    //inner circle
    drawCircle(400, -260, 20, 0.8f, 0.8f, 0.8f);
    //wheel 2
    drawCircle(600, -260, 40, 0.0f, 0.0f, 0.0f);
    //inner circle
    drawCircle(600, -260, 20, 0.8f, 0.8f, 0.8f);

    glPopMatrix();
}

void updateCar_E(int value)
{
    if (E.carposition < -1500.0f)
        E.carposition = 800.0f;
    E.carposition = E.carposition - E.carspeed;
    glutPostRedisplay();
    glutTimerFunc(25, updateCar_E, 0);
}

void display_E()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Gradient Sky
    if (!E.isNight) {
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.4f, 0.8f); // Top Color (Deep Blue)
        glVertex2i(-800, 600);
        glVertex2i( 800, 600);
        glColor3f(0.6f, 0.8f, 1.0f); // Bottom Color (Light Blue)
        glVertex2i( 800, 80);
        glVertex2i(-800, 80);
        glEnd();

        if (!E.daySound) {
            PlaySound(NULL, 0, 0); // stop previous sound
            SoundDay_E();
            E.daySound   = true;
            E.NightSound = false;
        }
    } else {
        // Night Sky
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.1f);
        glVertex2i(-800, 600);
        glVertex2i( 800, 600);
        glColor3f(0.0f, 0.0f, 0.3f);
        glVertex2i( 800, 80);
        glVertex2i(-800, 80);
        glEnd();

        // Stars
        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(-600, 500);
        glVertex2i(-300, 550);
        glVertex2i(  0, 520);
        glVertex2i( 300, 570);
        glVertex2i( 600, 500);
        glVertex2i(200, 480);
        glVertex2i(-200, 470);
        glEnd();

        if (!E.NightSound) {
            PlaySound(NULL, 0, 0); // stop previous sound
            SoundNight_E();
            E.daySound   = false;
            E.NightSound = true;
        }
    }

    // Sun
    drawSun_E();

    // Clouds
    if (!E.isNight)
        drawClouds_E();

    // ROADS
    glColor3f(0.593f, 0.605f, 0.589f);
    glBegin(GL_QUADS);
    glVertex2i(-800,   0);
    glVertex2i(-800, -400);
    glVertex2i(800, -400);
    glVertex2i(800, 0);
    glEnd();

    //RoadLine
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(-800, -200);
    glVertex2i(-800, -220);
    glVertex2i(-640, -220);
    glVertex2i(-640, -200);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(-380, -200);
    glVertex2i(-80, -200);
    glVertex2i(-80, -220);
    glVertex2i(-380, -220);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(200, -200);
    glVertex2i(600, -200);
    glVertex2i(600, -220);
    glVertex2i(200, -220);
    glEnd();

    Car_E();

    // Green Grass
    glColor3f(0.808f, 0.679f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(-800, -600);
    glVertex2i(-800, -400);
    glColor3f(0.027f, 0.4296f, 0.050f);
    glVertex2i( 800, -400);
    glVertex2i( 800, -600);
    glEnd();

    //Tree3
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_QUADS);
    glVertex2i(-620, -600);
    glVertex2i(-600, -600);
    glVertex2i(-600, -460);
    glVertex2i(-620, -460);
    glEnd();

    glColor3f(0.017f, 0.320f, 0.144f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-610, -360);
    glVertex2i(-700, -460);
    glVertex2i(-520, -460);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-610, -320);
    glVertex2i(-540, -400);
    glVertex2i(-680, -400);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-610, -280);
    glVertex2i(-560, -340);
    glVertex2i(-660, -340);
    glEnd();

    //Tree4
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_QUADS);
    glVertex2i(-420, -600);
    glVertex2i(-440, -600);
    glVertex2i(-440, -460);
    glVertex2i(-420, -460);
    glEnd();

    glColor3f(0.017f, 0.320f, 0.144f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-430, -360);
    glVertex2i(-360, -460);
    glVertex2i(-500, -460);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-430, -320);
    glVertex2i(-380, -380);
    glVertex2i(-480, -380);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-430, -300);
    glVertex2i(-400, -340);
    glVertex2i(-460, -340);
    glEnd();

    //Surface
    glBegin(GL_QUADS);
    glColor3f(0.1328f, 0.542f, 0.13f);
    glVertex2i(-800, 0);
    glVertex2i(-800, 140);
    glColor3f(0.808f, 0.679f, 0.5f);
    glVertex2i(800, 140);
    glVertex2i(800, 0);
    glEnd();

    //Sea
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.4f, 0.8f);
    glVertex2i( 800, 140);
    glVertex2i(-800, 140);
    glColor3f(0.443f, 0.7070f, 0.8555f);
    glVertex2i(-800, 300);
    glVertex2i( 800, 300);
    glEnd();

    drawShip_E();

    //trees 2
    glBegin(GL_QUADS);
    glColor3f(0.457f, 0.293f, 0.0313f);
    glVertex2i(-250, 0);
    glVertex2i(-270, 0);
    glVertex2i(-270, 100);
    glVertex2i(-250, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.043f, 0.468f, 0.172f);
    glVertex2i(-320, 100);
    glVertex2i(-280, 180);
    glVertex2i(-220, 180);
    glVertex2i(-180, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.148f, 0.738f, 0.273f);
    glVertex2i(-300, 180);
    glVertex2i(-260, 240);
    glVertex2i(-250, 240);
    glVertex2i(-200, 180);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.535f, 0.965f, 0.184f);
    glVertex2i(-280, 235);
    glVertex2i(-220, 235);
    glVertex2i(-250, 290);
    glEnd();

    //Mountain
    glBegin(GL_QUADS);
    glColor3f(0.359f, 0.386f, 0.449f);
    glVertex2i(-800, 140);
    glVertex2i(-800, 180);
    glColor3f(0.472f, 0.496f, 0.667f);
    glVertex2i(-650, 410);
    glVertex2i(-520, 140);
    glEnd();

    //Mountain
    glBegin(GL_TRIANGLES);
    glColor3f(0.335f, 0.339f, 0.335f);
    glVertex2i(-700, 140);
    glVertex2i(-500, 460);
    glColor3f(0.472f, 0.496f, 0.667f);
    glVertex2i(-360, 140);
    glEnd();

    //Trees 1
    glBegin(GL_QUADS);
    glColor3f(0.457f, 0.293f, 0.0313f);
    glVertex2i(-400, 0);
    glVertex2i(-400, 140);
    glVertex2i(-380, 140);
    glVertex2i(-380, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.043f, 0.468f, 0.172f);
    glVertex2i(-460, 140);
    glVertex2i(-390, 240);
    glVertex2i(-320, 140);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.148f, 0.738f, 0.273f);
    glVertex2i(-440, 220);
    glVertex2i(-390, 280);
    glVertex2i(-340, 220);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.535f, 0.965f, 0.184f);
    glVertex2i(-420, 260);
    glVertex2i(-390, 300);
    glVertex2i(-360, 260);
    glEnd();

    //Mountain
    glBegin(GL_TRIANGLES);
    glColor3f(0.335f, 0.339f, 0.335f);
    glVertex2i(400, 140);
    glColor3f(0.472f, 0.496f, 0.667f);
    glVertex2i(500, 360);
    glVertex2i(640, 140);
    glEnd();

    //Mountain
    glBegin(GL_QUADS);
    glColor3f(0.359f, 0.386f, 0.449f);
    glVertex2i(500,   0);
     glVertex2i(660, 380);
    glColor3f(0.472f, 0.496f, 0.667f);
    glVertex2i(800, 140);
     glVertex2i(800, 0);
    glEnd();

    glFlush();
}



void SoundDay_F()
{
    PlaySound("freesound_community-paddle-boat-on-waterwav-14861.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void SoundNight_F()
{
    PlaySound("schorsch1964-night-atmosphere-with-crickets-374652.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void drawSun_F()
{
    glPushMatrix();
    glTranslatef(0.0f, F.sunPosY, 0.0f);
    drawCircle(600, 450, 60, 1.0f, 0.9f, 0.0f);
    glPopMatrix();
}

void updateSun_F(int value)
{
    if (F.sunGoingDown)
        {
        F.sunPosY -= F.sunSpeed;
        if (F.sunPosY < -400)
F.sunGoingDown = false;
    }

    else {
        F.sunPosY += F.sunSpeed;
        if (F.sunPosY > 0)
            F.sunGoingDown = true;
    }

    if (F.sunPosY < -310)
        F.isNight = true;
    else if (F.sunPosY > -300)
        F.isNight = false;

    glutPostRedisplay();
    glutTimerFunc(25, updateSun_F, 0);
}

void drawClouds_F()
{
    glPushMatrix();
    glTranslatef(F.cloudPos1, 0.0f, 0.0f);
    drawCircle(-500, 480, 40, 1.0f, 1.0f, 1.0f);
    drawCircle(-460, 490, 50, 1.0f, 1.0f, 1.0f);
    drawCircle(-420, 480, 40, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(F.cloudPos2, 0.0f, 0.0f);
    drawCircle(100, 520, 35, 1.0f, 1.0f, 1.0f);
    drawCircle(140, 530, 45, 1.0f, 1.0f, 1.0f);
    drawCircle(180, 520, 35, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
}

void updateCloud1_F(int value)
{
    if (F.cloudPos1 > 1500.0f)
        F.cloudPos1 = -800.0f;
    F.cloudPos1 += F.cloudSpeed1;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud1_F, 0);
}

void updateCloud2_F(int value)
{
    if (F.cloudPos2 < -900.0f)
        F.cloudPos2 = 800.0f;
    F.cloudPos2 -= F.cloudSpeed2;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud2_F, 0);
}

void drawBoat1_F()
{
    glPushMatrix();
    glTranslatef(F.position, 0.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(300, -280);
    glVertex2i(700, -280);
    glVertex2i(600, -360);
    glVertex2i(400, -360);
    glEnd();

    glColor3f(0.628f, 0.503f, 0.394f);
    glBegin(GL_TRIANGLES);
    glVertex2i(400, -280);
    glVertex2i(440, -200);
    glVertex2i(480, -280);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_QUADS);
    glVertex2i(440, -200);
    glVertex2i(560, -200);
    glVertex2i(600, -280);
    glVertex2i(480, -280);
    glEnd();

    glPopMatrix();
}

void update_F(int value)
{
    if (F.position < -1500.0f)
        F.position = 800.0f;
    F.position = F.position - F.speed;
    glutPostRedisplay();
    glutTimerFunc(25, update_F, 0);
}

void display_F()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Gradient Sky
    if (!F.isNight) {
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.4f, 0.8f); // Top Color (Deep Blue)
        glVertex2i(-800, 600);
        glVertex2i( 800, 600);
        glColor3f(0.6f, 0.8f, 1.0f); // Bottom Color (Light Blue)
        glVertex2i( 800, 80);
        glVertex2i(-800, 80);
        glEnd();

        if (!F.daySound) {
            PlaySound(NULL, 0, 0); // stop previous
            SoundDay_F();
            F.daySound   = true;
            F.nightSound = false;
        }
    } else {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.1f);
        glVertex2i(-800, 600);
        glVertex2i( 800, 600);
        glColor3f(0.0f, 0.0f, 0.3f);
        glVertex2i( 800, 80);
        glVertex2i(-800, 80);
        glEnd();

        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(-600, 500);
        glVertex2i(-300, 550);
        glVertex2i(  0, 520);
        glVertex2i( 300, 570);
        glVertex2i( 600, 500);
        glVertex2i(200, 480);
        glVertex2i(-200, 470);
        glEnd();

        if (!F.nightSound) {
            PlaySound(NULL, 0, 0); // stop previous sound
            SoundNight_F();
            F.nightSound = true;
            F.daySound   = false;
        }
    }

    drawSun_F();

    if (!F.isNight)
        drawClouds_F();

    // Green Grass
    glColor3f(0.027f, 0.4296f, 0.050f);
    glBegin(GL_TRIANGLES);
    glVertex2i(-800,-600);
    glVertex2i(800, -490);
    glVertex2i(800, -600);
    glEnd();

    // Gradient Water
    glBegin(GL_QUADS);
    glColor3f(0.6641f, 0.8359f, 0.9141f);
    glVertex2i(-800, -120);
    glVertex2i(800, 60);
    glColor3f(0.443f, 0.7070f, 0.8555f);
    glVertex2i(800, -490);
    glVertex2i(-800, -600);
    glEnd();

    //Surface
    glBegin(GL_QUADS);
    glColor3f(0.808f, 0.679f, 0.5f);
    glVertex2i(-800, 80);
    glVertex2i(800, 80);
    glColor3f(0.027f, 0.4296f, 0.050f);
    glVertex2i(800, 60);
    glVertex2i(-800, -120);
    glEnd();

    //Tree 2
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_QUADS);
    glVertex2i(280, 80);
    glVertex2i(300, 80);
    glVertex2i(300, 160);
    glVertex2i(280, 160);
    glEnd();

    glColor3f(0.017f, 0.320f, 0.144f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(290, 240);
    glVertex2i(360, 160);
    glVertex2i(220, 160);
    glEnd();

    glColor3f(0.039f, 0.476f, 0.230f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(290, 280);
    glVertex2i(340, 200);
    glVertex2i(240, 200);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(290, 300);
    glVertex2i(320, 260);
    glVertex2i(260, 260);
    glEnd();

    //Tree 3
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_QUADS);
    glVertex2i(740, 80);
    glVertex2i(760, 80);
    glVertex2i(760, 120);
    glVertex2i(740, 120);
    glEnd();

    glColor3f(0.017f, 0.320f, 0.144f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(750, 180);
    glVertex2i(800, 120);
    glVertex2i(700, 120);
    glEnd();

    glColor3f(0.039f, 0.476f, 0.230f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(750, 220);
    glVertex2i(780, 160);
    glVertex2i(720, 160);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(750, 260);
    glVertex2i(770, 200);
    glVertex2i(730, 200);
    glEnd();

    //2nd House
    glColor3f(0.718f, 0.660f, 0.523f);
    glBegin(GL_QUADS);
    glVertex2i(-160, 80);
    glVertex2i(180, 80);
    glVertex2i(180, 180);
    glVertex2i(-160, 180);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_QUADS);
    glVertex2i(-220, 180);
    glVertex2i(240, 180);
    glVertex2i(100, 340);
    glVertex2i(-100, 340);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_QUADS);
    glVertex2i(-30, 80);
    glVertex2i(40, 80);
    glVertex2i(40, 160);
    glVertex2i(-30, 160);
    glEnd();

    //1st House
    glColor3f(0.718f, 0.660f, 0.523f);
    glBegin(GL_QUADS);
    glVertex2i(-500, 80);
    glVertex2i(-400, 80);
    glVertex2i(-400, 200);
    glVertex2i(-500, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.628f, 0.503f, 0.394f);
    glVertex2i(-400, 80);
    glVertex2i(-400, 200);
    glColor3f(0.718f, 0.660f, 0.523f);
    glVertex2i(-220, 200);
    glVertex2i(-220, 80);
    glEnd();

    glColor3f(0.628f, 0.503f, 0.394f);
    glBegin(GL_QUADS);
    glVertex2i(-590, 200);
    glVertex2i(-160, 200);
    glVertex2i(-240, 300);
    glVertex2i(-500, 300);
    glEnd();

    glColor3f(0.507f, 0.449f, 0.394f);
    glBegin(GL_QUADS);
    glVertex2i(-480, 110);
    glVertex2i(-420, 110);
    glVertex2i(-420, 160);
    glVertex2i(-480, 160);
    glEnd();

    glColor3f(0.507f, 0.449f, 0.394f);
    glBegin(GL_QUADS);
    glVertex2i(-340, 80);
    glVertex2i(-280, 80);
    glVertex2i(-280, 160);
    glVertex2i(-340, 160);
    glEnd();

    //3rd House
    glColor3f(0.628f, 0.503f, 0.394f);
    glBegin(GL_TRIANGLES);
    glVertex2i(360, 180);
    glVertex2i(540, 180);
    glVertex2i(460, 280);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_TRIANGLES);
    glVertex2i(460, 280);
    glVertex2i(740, 140);
    glVertex2i(540, 180);
    glEnd();

    glColor3f(0.718f, 0.660f, 0.523f);
    glBegin(GL_QUADS);
    glVertex2i(540, 180);
    glVertex2i(540, 80);
    glVertex2i(400, 80);
    glVertex2i(400, 180);
    glEnd();

    glColor3f(0.507f, 0.449f, 0.394f);
    glBegin(GL_QUADS);
    glVertex2i(540, 180);
    glVertex2i(540, 80);
    glVertex2i(700, 80);
    glVertex2i(700, 150);
    glEnd();

    glColor3f(0.718f, 0.660f, 0.523f);
    glBegin(GL_QUADS);
    glVertex2i(580, 100);
    glVertex2i(650, 100);
    glVertex2i(650, 140);
    glVertex2i(580, 140);
    glEnd();

    glColor3f(0.5f, 0.468f, 0.449f);
    glBegin(GL_QUADS);
    glVertex2i(440, 80);
    glVertex2i(500, 80);
    glVertex2i(500, 160);
    glVertex2i(440, 160);
    glEnd();

    drawBoat1_F();

    //2nd Boat
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(-580, -140);
    glVertex2i(-360, -140);
    glVertex2i(-400, -180);
    glVertex2i(-540, -180);
    glEnd();

    glColor3f(0.347f, 0.300f, 0.1953f);
    glBegin(GL_QUADS);
    glVertex2i(-580, -180);
    glVertex2i(-590, -180);
    glVertex2i(-590, -60);
    glVertex2i(-580, -60);
    glEnd();

    //Tree 1
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_QUADS);
    glVertex2i(-700, -80);
    glVertex2i(-660, -80);
    glVertex2i(-660, 40);
    glVertex2i(-700, 40);
    glEnd();

    glColor3f(0.017f, 0.320f, 0.144f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-680, 140);
    glVertex2i(-580, 40);
    glVertex2i(-780, 40);
    glEnd();

    glColor3f(0.039f, 0.476f, 0.230f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-680, 200);
    glVertex2i(-600, 100);
    glVertex2i(-760, 100);
    glEnd();

    glColor3f(0.0585f, 0.566f, 0.277f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2i(-680, 260);
    glVertex2i(-620, 160);
    glVertex2i(-740, 160);
    glEnd();

    glFlush();
}



void sound1_R()
{
    PlaySound("kokoreli777-sea-waves-169411.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void drawSun_R()
{
    glPushMatrix();
    glTranslatef(0.0f, R.sunPosY, 0.0f);
    drawCircle(0, 400, 100, 0.99f, 0.42f, 0.089f);
    glPopMatrix();
}

void updateSun_R(int value)
{
    if (R.sunGoingDown) {
        R.sunPosY -= R.sunSpeed;
        if (R.sunPosY < -500)
        R.sunGoingDown = false;
    } else {
        R.sunPosY += R.sunSpeed;
        if (R.sunPosY > 0)
        R.sunGoingDown = true;
    }

    if (R.sunPosY < -340)
        R.isNight = true;
    else if (R.sunPosY > -330)
        R.isNight = false;

    glutPostRedisplay();
    glutTimerFunc(25, updateSun_R, 0);
}

void drawClouds_R()
{
    float cr = 0.795f, cg = 0.425f, cb = 0.105f;

    glPushMatrix();
    glTranslatef(R.cloudPos1, 0.0f, 0.0f);
    drawCircle(-500, 480, 40, cr, cg, cb);
    drawCircle(-460, 490, 50, cr, cg, cb);
    drawCircle(-420, 480, 40, cr, cg, cb);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(R.cloudPos2, 0.0f, 0.0f);
    drawCircle(100, 520, 35, cr, cg, cb);
    drawCircle(140, 530, 45, cr, cg, cb);
    drawCircle(180, 520, 35, cr, cg, cb);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(R.cloudPos3, 0.0f, 0.0f);
    drawCircle(-400, 380, 35, cr, cg, cb);
    drawCircle(-360, 390, 45, cr, cg, cb);
    drawCircle(-320, 380, 35, cr, cg, cb);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(R.cloudPos4, 0.0f, 0.0f);
    drawCircle(300, 320, 35, cr, cg, cb);
    drawCircle(340, 330, 45, cr, cg, cb);
    drawCircle(380, 320, 35, cr, cg, cb);
    glPopMatrix();
}

void updateCloud1_R(int value)
{
    if (R.cloudPos1 > 1500.0f)
        R.cloudPos1 = -800.0f;
    R.cloudPos1 += R.cloudSpeed1;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud1_R, 0);
}

void updateCloud2_R(int value)
{
    if (R.cloudPos2 < -900.0f)
        R.cloudPos2 = 800.0f;
    R.cloudPos2 -= R.cloudSpeed2;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud2_R, 0);
}

void updateCloud3_R(int value)
{
    if (R.cloudPos3 > 1500.0f)
        R.cloudPos3 = -800.0f;
    R.cloudPos3 += R.cloudSpeed3;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud3_R, 0);
}

void updateCloud4_R(int value)
{
    if (R.cloudPos4 < -900.0f)
        R.cloudPos4 = 800.0f;
    R.cloudPos4 -= R.cloudSpeed4;
    glutPostRedisplay();
    glutTimerFunc(25, updateCloud4_R, 0);
}

void drawMiniShip_R()
{
    glPushMatrix();
    glTranslatef(R.position, 0.0f, 0.0f);

    glColor3f(0.05f, 0.08f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2i(-560, -90);
     glVertex2i(-220, -90);
    glVertex2i(-160, -40);
    glVertex2i(-520, -40);
    glEnd();

    glColor3f(0.55f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2i(-530, -90);
    glVertex2i(-230, -90);
     glVertex2i(-250, -70);
    glVertex2i(-510, -70);
    glEnd();

    glColor3f(0.85f, 0.85f, 0.85f);
    glBegin(GL_QUADS);
    glVertex2i(-480, -40);
     glVertex2i(-260, -40);
      glVertex2i(-260, 10);
    glVertex2i(-480, 10);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(-430, 10);
     glVertex2i(-310, 10);
    glVertex2i(-310, 80);
     glVertex2i(-430, 80);
    glEnd();

    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2i(-445, 80);
    glVertex2i(-295, 80);
    glVertex2i(-295, 95);
    glVertex2i(-445, 95);
    glEnd();

    glColor3f(0.0f, 0.55f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2i(-410, 35); glVertex2i(-390, 35); glVertex2i(-390, 60); glVertex2i(-410, 60);
    glVertex2i(-370, 35); glVertex2i(-350, 35); glVertex2i(-350, 60); glVertex2i(-370, 60);
    glVertex2i(-330, 35); glVertex2i(-310, 35); glVertex2i(-310, 60); glVertex2i(-330, 60);
    glEnd();

    glColor3f(0.75f, 0.05f, 0.02f);
    glBegin(GL_QUADS);
    glVertex2i(-385, 95); glVertex2i(-350, 95); glVertex2i(-350, 145); glVertex2i(-385, 145);
    glEnd();

    drawCircle(-365, 180, 15, 0.65f, 0.65f, 0.65f);
    drawCircle(-345, 205, 20, 0.7f,  0.7f,  0.7f);
    drawCircle(-320, 230, 25, 0.75f, 0.75f, 0.75f);

    drawCircle(-470, -55, 10, 0.0f, 0.55f, 0.9f);
    drawCircle(-420, -55, 10, 0.0f, 0.55f, 0.9f);
    drawCircle(-370, -55, 10, 0.0f, 0.55f, 0.9f);
    drawCircle(-320, -55, 10, 0.0f, 0.55f, 0.9f);

    glPopMatrix();
}

void drawRealBeachChair_R(int x, int y)
{
    // wood frame
    glColor3f(0.45f, 0.22f, 0.08f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(x,      y);       glVertex2i(x + 45,  y + 110);
    glVertex2i(x + 90, y);       glVertex2i(x + 45,  y + 110);
    glVertex2i(x,      y);       glVertex2i(x + 90,  y);
    glVertex2i(x + 10, y);       glVertex2i(x - 20,  y - 60);
    glVertex2i(x + 80, y);       glVertex2i(x + 115, y - 60);
    glEnd();

    // cloth back
    glColor3f(0.0f, 0.48f, 0.55f);
    glBegin(GL_QUADS);
    glVertex2i(x + 25, y + 10);  glVertex2i(x + 80, y + 10);
    glVertex2i(x + 65, y + 90);  glVertex2i(x + 10, y + 90);
    glEnd();

    // cloth seat
    glColor3f(0.0f, 0.42f, 0.48f);
    glBegin(GL_QUADS);
    glVertex2i(x + 10,  y);      glVertex2i(x + 90,  y);
    glVertex2i(x + 115, y - 35); glVertex2i(x + 25,  y - 35);
    glEnd();

    glLineWidth(1);
}

void drawBeachUmbrella_R()
{
    // pole
    glColor3f(0.25f, 0.12f, 0.05f);
    glLineWidth(6);
    glBegin(GL_LINES);
    glVertex2i(0, -400); glVertex2i(20, -120);
    glEnd();
    glLineWidth(1);

    // umbrella top
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.35f, 0.55f);
    glVertex2i(20, -80);
    glColor3f(0.0f, 0.55f, 0.75f);
    glVertex2i(-180, -120); glVertex2i(-120, -40); glVertex2i(-40, -10);
    glVertex2i(  40, -10);  glVertex2i( 120, -40); glVertex2i(190, -120);
    glEnd();

    // stripes
    glColor3f(0.85f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLES);
    glVertex2i(20,  -80); glVertex2i(-120, -40);  glVertex2i(-80, -120);
    glVertex2i(20,  -80); glVertex2i( -20, -10);  glVertex2i( 20, -120);
    glVertex2i(20,  -80); glVertex2i(  80, -20);  glVertex2i(120, -120);
    glEnd();

    // lower wavy edge
    glColor3f(0.0f, 0.25f, 0.38f);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2i(-180, -120); glVertex2i(-120, -135); glVertex2i(-60, -120);
    glVertex2i(   0, -135); glVertex2i(  60, -120); glVertex2i(120, -135); glVertex2i(190, -120);
    glEnd();
    glLineWidth(1);
}

void drawUmbrellaWithChairs_R()
{
    glPushMatrix();
    glTranslatef(150, 0, 0);
    drawBeachUmbrella_R();
    drawRealBeachChair_R(-80, -420);
    drawRealBeachChair_R( 60, -420);
    glPopMatrix();
}

void update_R(int value)
{
    if (R.position > 1500.0f) R.position = -800.0f;
    R.position = R.position + R.speed;
    glutPostRedisplay();
    glutTimerFunc(25, update_R, 0);
}

void display_R()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (!R.isNight) {
        // Sunset sky
        glBegin(GL_QUADS);
        glColor3f(0.8671f, 0.789f,   0.746f);  glVertex2i(-800, 600);
        glColor3f(0.7265f, 0.285f,   0.027f);  glVertex2i( 800, 600);
        glVertex2i( 800,  80);
        glColor3f(0.996f,  0.492f,  0.1992f);  glVertex2i(-800,  80);
        glEnd();
    } else {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.1f);
        glVertex2i(-800, 600); glVertex2i(800, 600);
        glColor3f(0.0f, 0.0f, 0.3f);
        glVertex2i( 800,  80); glVertex2i(-800, 80);
        glEnd();

        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(-600, 500); glVertex2i(-300, 550); glVertex2i(  0, 520);
        glVertex2i( 300, 570); glVertex2i( 600, 500); glVertex2i(200, 480); glVertex2i(-200, 470);
        glEnd();

    }


    drawSun_R();

    if (!R.isNight)
        drawClouds_R();

    // Sea
    glBegin(GL_QUADS);
    glColor3f(0.443f, 0.7070f, 0.8555f);
    glVertex2i(-800, -240); glVertex2i(800, -240);
    glColor3f(0.1f, 0.4f, 0.8f);
    glVertex2i( 800,  140); glVertex2i(-800, 140);
    glEnd();

    // Waves
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2i(-700, 40);  glVertex2i(-550, 40);
    glVertex2i(-300, 20);  glVertex2i(-150, 20);
    glVertex2i( 100, 60);  glVertex2i( 250, 60);
    glVertex2i( 400, -20); glVertex2i( 600, -20);
    glEnd();

    drawMiniShip_R();

    // Sand
    glBegin(GL_QUADS);
    glColor3f(0.808f, 0.679f, 0.5f);
    glVertex2i(-800, -600); glVertex2i(800, -600);
    glColor3f(0.757f, 0.589f, 0.531f);
    glVertex2i( 800, -240); glVertex2i(-800, -240);
    glEnd();

    // Sand dots
    glColor3f(0.55f, 0.45f, 0.35f);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2i(-700, -500); glVertex2i(-620, -420); glVertex2i(-500, -550);
    glVertex2i(-300, -480); glVertex2i(-100, -530); glVertex2i(  80, -470);
    glVertex2i( 260, -540); glVertex2i( 430, -450); glVertex2i( 650, -520);
    glVertex2i( 500, -350); glVertex2i(-450, -330); glVertex2i(   0, -380);
    glEnd();

    drawUmbrellaWithChairs_R();

    glFlush(); // Render now
}


void display()
{
    switch (currentDisplay) {
        case 0: coverPage();       break;
        case 1: instructionPage(); break;
        case 2: display_E();       break;
        case 3: display_F();       break;
        case 4: display_R();       break;
    }
}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        E.speed += 1.0f;
        F.speed += 1.0f;
        R.speed += 1.0f;
        break;
    case 's':
        E.speed -= 1.0f;
        if (E.speed < 0) E.speed = 0;
        F.speed -= 1.0f;
        if (F.speed < 0) F.speed = 0;
        R.speed -= 1.0f;
        if (R.speed < 0) R.speed = 0;
        break;
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        currentDisplay = (currentDisplay + 1) % 5;
        glutPostRedisplay();
    }
}



void init()
{
    // Set up 2D orthographic viewing region
    glMatrixMode(GL_PROJECTION);      // Switch to the projection matrix
    glLoadIdentity();                 // Reset projection matrix
    gluOrtho2D(-800.0, 800.0, -600.0, 600.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(880, 640);          // Set the window's initial width & height
    glutInitWindowPosition(80, 50);        // Set the window's initial position
    glutCreateWindow("Waves of Cox's Bazar: A Coastal Visualization"); // Create a window with the given title

    init();                                // Call your initialization function

    glutDisplayFunc(display);              // Register display callback handler
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);


    glutTimerFunc(25, update_E,       0);
    glutTimerFunc(25, updateCloud1_E, 0);
    glutTimerFunc(25, updateCloud2_E, 0);
    glutTimerFunc(25, updateSun_E,    0);
    glutTimerFunc(25, updateCar_E,    0);


    glutTimerFunc(25, update_F,       0);
    glutTimerFunc(25, updateCloud1_F, 0);
    glutTimerFunc(25, updateCloud2_F, 0);
    glutTimerFunc(25, updateSun_F,    0);


    glutTimerFunc(25, update_R,       0);
    glutTimerFunc(25, updateCloud1_R, 0);
    glutTimerFunc(25, updateCloud2_R, 0);
    glutTimerFunc(25, updateCloud3_R, 0);
    glutTimerFunc(25, updateCloud4_R, 0);
    glutTimerFunc(25, updateSun_R,    0);

    glutMainLoop();                        // Enter the event-processing loop
    return 0;
}
