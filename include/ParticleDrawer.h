#ifndef PARTICLEDRAWER_H
#define PARTICLEDRAWER_H

//----------------------------------------------------------------------------------------------------------------------
/// @file ParticleDrawer.h
/// @brief Class in which you can load positional data of particles and draw them in arguably the most efficient way
/// @brief in rasterisation by drawing point sprites as spheres.
/// @author Declan Russell
/// @version 1.0
/// @date 17/11/2015
/// @class ParticleDrawer
//----------------------------------------------------------------------------------------------------------------------

#ifdef DARWIN
    #include <GLFW/glfw3.h>
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
    #ifndef WIN32
        #include <GL/gl.h>
    #endif
#endif

#include <vector>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include "ShaderProgram.h"

class ParticleDrawer
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our default constructor
    //----------------------------------------------------------------------------------------------------------------------
    ParticleDrawer();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our destructor
    //----------------------------------------------------------------------------------------------------------------------
    ~ParticleDrawer();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief resize our particle buffer
    /// @param _n - number of particles we want to have
    //----------------------------------------------------------------------------------------------------------------------
    void resizeParticleBuffer(int _n);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief sets particle position data
    /// @param - _posData - vector of position position data
    //----------------------------------------------------------------------------------------------------------------------
    void setPositions(std::vector<glm::vec3> &_posData);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets our screen width needed by our shader
    /// @param _width - width of screen
    //----------------------------------------------------------------------------------------------------------------------
    void setScreenWidth(int _width);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the size that we wish to draw our particles
    /// @param _size - desired size of particles
    //----------------------------------------------------------------------------------------------------------------------
    void setParticleSize(float _size);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Set the colour of our particles
    //----------------------------------------------------------------------------------------------------------------------
    void setColour(float _r, float _g, float _b);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw function
    /// @param _M - model matrix of scene
    /// @param _V - view matrix of scene
    /// @param _P - projection matrix of scene
    //----------------------------------------------------------------------------------------------------------------------
    void draw(glm::mat4 _M, glm::mat4 _V, glm::mat4 _P);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw function that will draw a VAO from an external source
    /// @param _VAO - VAO to draw
    /// @param _n - number of points to draw
    /// @param _M - model matrix of scene
    /// @param _V - view matrix of scene
    /// @param _P - projection matrix of scene
    //----------------------------------------------------------------------------------------------------------------------
    void drawFromVAO(GLuint _VAO, int _n, glm::mat4 _M, glm::mat4 _V, glm::mat4 _P);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw function that will draw a VAO from an external source
    /// @param _VAO - VAO to draw
    /// @param _n - number of points to draw
    /// @param _M - model matrix of scene
    /// @param _V - view matrix of scene
    /// @param _P - projection matrix of scene
    //----------------------------------------------------------------------------------------------------------------------
    void drawCMYKFromVAO(GLuint _VAO, int _n, glm::mat4 _M, glm::mat4 _V, glm::mat4 _P);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief accessor to our VAO
    /// @return handle to our VAO
    //----------------------------------------------------------------------------------------------------------------------
    inline GLuint getVAO(){return m_VAO;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief accessor to our particle position VBO
    /// @return handlt to our particle position VBO
    //----------------------------------------------------------------------------------------------------------------------
    inline GLuint getPosVBO(){return m_posVBO;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief binds and returns a pointer to our particle position buffer
    /// @brief this can be used to set postion data
    /// @return ptr to the particle postion buffer
    //----------------------------------------------------------------------------------------------------------------------
    void* bindPosBufferPtr();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief unbinds the ptr to our particle position buffer
    //----------------------------------------------------------------------------------------------------------------------
    void unBindPosBufferPtr();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief accesor to particle size
    /// @return particle size (float)
    //----------------------------------------------------------------------------------------------------------------------
    inline float getParticleSize(){return m_particleSize;}
    //----------------------------------------------------------------------------------------------------------------------
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief particle size
    //----------------------------------------------------------------------------------------------------------------------
    float m_particleSize;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief VAO to hold our particle in information
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_VAO;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief VBO of our particle positions
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_posVBO;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the number of particles we have to draw
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_numParticles;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our particle shader program
    //----------------------------------------------------------------------------------------------------------------------
    ShaderProgram *m_particleShader;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our CMYK particle shader progam
    //----------------------------------------------------------------------------------------------------------------------
    ShaderProgram *m_CMYKParticleShader;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our particle size uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_pointSizeHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our colour uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_colourHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our P matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_PMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our MV Matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_MVMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our MVP Matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_MVPMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our screen width uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_screenWidthHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our particle size uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_CMYKpointSizeHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our P matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_CMYKPMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our MV Matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_CMYKMVMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our MVP Matrix uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_CMYKMVPMatHndl;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief handle to our screen width uniform
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_CMYKscreenWidthHndl;
    //----------------------------------------------------------------------------------------------------------------------

};

#endif // PARTICLEDRAWER_H
