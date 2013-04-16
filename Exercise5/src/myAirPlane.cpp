#include "myAirPlane.h"


void myAirplane::draw()
{
    //Asa Esquerda//


     glBegin(GL_TRIANGLES);    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(-1.0f, 0.0f, 3.0f);  
    glVertex3f(-0.25f, 0.0f, 3.0f);     
    glEnd();   

    glBegin(GL_TRIANGLES);       
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 3.0f);  
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(-0.25f, 0.0f, 3.0f);     
    glEnd();   

    //-----------------//

    //Asa Direita//

    glBegin(GL_TRIANGLES);   
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(0.25f, 0.0f, 3.0f);  
    glVertex3f(1.0f, 0.0f, 3.0f);     
    glEnd();   

    glBegin(GL_TRIANGLES);      
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.25f, 0.0f, 3.0f);  
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(1.0f, 0.0f, 3.0f);     
    glEnd();  

    //------------------//

    //Base//
    glBegin(GL_TRIANGLES);     
    glNormal3f(1.5f, 0.75f, 0.125f);
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(-0.25f, 0.0f, 3.0f);  
    glVertex3f(0.0f, -0.5f, 3.0f);     
    glEnd();   

    glBegin(GL_TRIANGLES);          
    glNormal3f(-1.5f, -0.75f, -0.125f);
    glVertex3f(-0.25f, 0.0f, 3.0f);  
    glVertex3f(0.0f, 0.0f, 0.0f);  
    glVertex3f(0.0f, -0.5f, 3.0f);     
    glEnd();  

    glBegin(GL_TRIANGLES);  
    glNormal3f(1.5f, -0.75f, -0.125f);
    glVertex3f(0.0f, 0.0f, 0.0f); 
    glVertex3f(0.25f, 0.0f, 3.0f);  
    glVertex3f(0.0f, -0.5f, 3.0f);     
    glEnd(); 

    glBegin(GL_TRIANGLES);  
    glNormal3f(-1.5f, 0.75f, 0.125f);
    glVertex3f(0.25f, 0.0f, 3.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); 
    glVertex3f(0.0f, -0.5f, 3.0f);     
    glEnd();
    //--------//
}
