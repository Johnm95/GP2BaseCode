#include "Common.h"
#include "Graphics.h"
#include "Vertex.h"
/*
//This creates a multicoloured TRIANGLE
Vertex verts[] ={ {0.0f,1.0f,0.0f, //x,y,z
    1.0f,0.0f,0.0f,1.0f}, //r,g,b,a
    
    {-1.0f,-1.0f,0.0f, //x,y,z
        0.0f,1.0f,0.0f,1.0f}, //r,g,b,a
    
    {1.0f,-1.0f,0.0f, //x,y,z
        0.0f,0.0f,1.0f,1.0f}};//r,g,b,a
 */


 //This creates a multicoloured SQUARE
Vertex verts[] = {
    //Front
    {-0.5f,0.5f,0.5f,
        1.0f,0.0f,1.0f,1.0f},//Top Left
    {-0.5f,-0.5f,0.5f,
        1.0f,1.0f,0.0f,1.0f},//Bottom Left
    {0.5f,-0.5f,0.5f,
        0.0f,1.0f,1.0f,1.0f},//Bottom Right
    {0.5f,0.5f,0.5f,
        1.0f,0.0f,1.0f,1.0f},//Top Right
    
    //Back
    {-0.5f,0.5f,-0.5f,
        1.0f,0.0f,1.0f,1.0f},//Top Left
    {-0.5f,-0.5f,-0.5f,
        1.0f,1.0f,0.0f,1.0f},//Bottom Left
    {0.5f,-0.5f,-0.5f,
        0.0f,1.0f,1.0f,1.0f},//Bottom Right
    {0.5f,0.5f,-0.5f,
        1.0f,0.0f,1.0f,1.0f},//Top Right
    
    //Right Face
    
    //Left Face
};

GLuint indices[]={
    //Front
    0,1,2,
    0,3,2,
    
    //Left
    4,5,1,
    4,1,0,
    
    //Right
    3,7,2,
    7,6,2,
    
    //Bottom
    1,5,2,
    6,2,5,
    
    //Top
    4,0,7,
    0,7,3,
    
    //Back
    4,5,6,
    4,7,6
};




GLuint VBO;
GLuint EBO;

void update()
{
}


void initScene()
{
    //Create buffer
    glGenBuffers(1,&VBO);
    //Make the new VBO active
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    //Copy Vertex Data to VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts),verts,GL_STATIC_DRAW);
    
    //Create buffer
    glGenBuffers(1,&EBO);
    //Make the new EBO active
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    //Copy index data to EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
}



void render()
{
    //old imediate mode!
    //Set the clear colour(background)
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    //clear the colour and depth buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    //Make the new VBO active. Repeat here as a sanity check(may have changed since initialisation)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    //The 3 pointer is now filled out, the pipeline needs to know the size of each vertex
    glVertexPointer(3,GL_FLOAT,sizeof(Vertex),NULL);
    //The last parameter basically says that the colours start 3 floats into each element of the array
    glColorPointer(4,GL_FLOAT,sizeof(Vertex),(void**)(3*sizeof(float)));
    
    //Establish array contains vertices and colours
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    
    
    //Switch to ModelView
    glMatrixMode(GL_MODELVIEW);
    //Reset using the Identity Matrix
    glLoadIdentity();
    
    gluLookAt(0.0,0.0,6.0,0.0,0.0,-1.0f,0.0,1.0,0.0);
    
    //Transla
    glTranslatef(1.0f,0.0f,-6.0f);
    //Actually draw the triangle, giving the number of vertices provided
     
    glDrawArrays(GL_TRIANGLES,0,sizeof(verts)/sizeof(Vertex));
    glDrawElements(GL_TRIANGLES,sizeof(indices)/sizeof(GLuint),GL_UNSIGNED_INT,0);
    
    /*
    //Swith to ModelView
    glMatrixMode( GL_MODELVIEW );
    //Reset using the Indentity Matrix
    glLoadIdentity( );
    //Do translation, push the next bit of drawing 'back' 5 units
    //on z-zaxis
    //Everyting after this will be drawn at -5.0f on z-axis
    //until reset by glLoadIdentity!
    glTranslatef( 0.0f, 0.0f, -5.0f );
     */
/*
    //Begin drawing triangles
    glBegin( GL_TRIANGLES );
      glColor3f(1.0f, 0.0f, 0.0f); //Colour of the vertices
      glVertex3f(  0.0f,  1.0f, 0.0f ); // Top
      glVertex3f( -1.0f, -1.0f, 0.0f ); // Bottom Left
      glVertex3f(  1.0f, -1.0f, 0.0f ); // Bottom Right
    glEnd( );
*/
}

void cleanUp()
{
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
}

int main(int argc, char * arg[])
{
    //Controls the game loop
    bool run=true;
    bool pause=false;
    // init everyting - SDL, if it is nonzero we have a problem
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "ERROR SDL_Init " <<SDL_GetError()<< std::endl;

        return -1;
    }

    //Create a window
    SDL_Window * window = SDL_CreateWindow(
                                           "SDL",             // window title
                                           SDL_WINDOWPOS_CENTERED,     // x position, centered
                                           SDL_WINDOWPOS_CENTERED,     // y position, centered
                                           640,                        // width, in pixels
                                           480,                        // height, in pixels
                                           SDL_WINDOW_OPENGL           // flags
                                           );
    // Create an OpenGL context associated with the window.
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);

    //Initialisation
    //Call our InitOpenGL Function
    initOpenGL();
    
    //Call our initScene Function
    initScene();
    
    //Set our viewport
    setViewport(640,480);

    //Value to hold the event generated by SDL
    SDL_Event event;
    //Game Loop
    while(run)
    {
        //While we still have events in the queue
        while (SDL_PollEvent(&event)) {
            //Get event type
            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
                //set our boolean which controls the loop to false
                run = false;
            }
            if (event.type==SDL_WINDOWEVENT)
            {
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_MINIMIZED:
                            pause=true;
                        break;
                    default:
                        break;
                }

            }
        }

        //update
        update();
        //Then Draw
        render();

        //Call swap so that our GL back buffer is displayed
        SDL_GL_SwapWindow(window);

    }

    // clean up, reverse order!!!
    cleanUp();
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
