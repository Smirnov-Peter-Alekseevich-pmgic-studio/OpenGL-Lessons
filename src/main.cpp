//
// Created by smirnov on 16.05.2021.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//callbacks
void framebuffer_size_callback(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}
void process_input(GLFWwindow *window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}
//end callbacks

int main(){
    glfwInit(); // initialize the openGL

    //set openGLs settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //initialize a GLFWs window
    GLFWwindow* window = glfwCreateWindow(800,600,"OpenGL Sample",nullptr,nullptr);
    if(window == nullptr){
        std::cerr << "Window is not creating. Please check your drivers" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // set window is current context

    //is initialize a GLAD ?
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "GLAD is not initializing. Please check your drivers" << std::endl;
        glfwTerminate();
        return -2;
    }

    //set view port
    glViewport(0,0,800,600);

    //set resize callback
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        process_input(window);

        glClearColor(0.2f,0.3f,0.3f,0.3f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}