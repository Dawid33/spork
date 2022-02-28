#include "GameCanvas.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include "Game.hpp"
#include <iostream>

float vertices[] = {
//  Position      Color             Texcoords
        -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
        0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Top-right_dock
        0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right_dock
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
};

GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
};

const char* vertexSource = R"glsl(
    #version 150 core

    in vec2 texcoord;
    in vec2 position;
    in vec3 color;

    out vec3 Color;
    out vec2 Texcoord;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 proj;

    void main()
    {
        Texcoord = texcoord;
        Color = color;
        gl_Position =  proj * view * model * vec4(position, 0.0, 1.0);
    }
)glsl";
const char* fragmentSource = R"glsl(
    #version 150 core

    in vec3 Color;
    in vec2 Texcoord;

    out vec4 outColor;

    uniform sampler2D tex;

    void main()
    {
        outColor = texture(tex, Texcoord) * vec4(Color, 1.0);
    }
)glsl";

GameCanvas::GameCanvas(QWidget *parent, Game *game) : QOpenGLWidget(parent) {
    time_start = std::chrono::high_resolution_clock::now();
    this->game = game;
}

void GameCanvas::initializeGL() {
    QOpenGLFunctions f(QOpenGLContext::currentContext());

    yellow = new QOpenGLTexture(QImage("resources/yellow.png"));
    if (!yellow->isCreated()) {
        std::cout << "Failed to create texture." << std::endl;
    }
    yellow->setMagnificationFilter(QOpenGLTexture::Filter::Nearest);

    GLuint vbo;
    f.glGenBuffers(1, &vbo); // Generate 1 buffer
    f.glBindBuffer(GL_ARRAY_BUFFER, vbo);
    f.glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    GLuint vertexShader = f.glCreateShader(GL_VERTEX_SHADER);

    f.glShaderSource(vertexShader, 1, &vertexSource, NULL);
    f.glCompileShader(vertexShader);

    GLuint fragmentShader = f.glCreateShader(GL_FRAGMENT_SHADER);
    f.glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    f.glCompileShader(fragmentShader);

    GLuint shaderProgram = f.glCreateProgram();
    f.glAttachShader(shaderProgram, vertexShader);
    f.glAttachShader(shaderProgram, fragmentShader);
    f.glLinkProgram(shaderProgram);
    f.glUseProgram(shaderProgram);

    GLint posAttrib = f.glGetAttribLocation(shaderProgram, "position");
    f.glEnableVertexAttribArray(posAttrib);
    f.glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
                          7*sizeof(float), 0);

    GLint colAttrib = f.glGetAttribLocation(shaderProgram, "color");
    f.glEnableVertexAttribArray(colAttrib);
    f.glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
                          7*sizeof(float), (void*)(2*sizeof(float)));

    GLint texAttrib = f.glGetAttribLocation(shaderProgram, "texcoord");
    f.glEnableVertexAttribArray(texAttrib);
    f.glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,
                          7*sizeof(float), (void*)(5*sizeof(float)));

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    uniModel = f.glGetUniformLocation(shaderProgram, "model");
    f.glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(trans));

    glm::mat4 view = glm::lookAt(
            glm::vec3(1.2f, 1.2f, 1.2f),
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f)
    );
    GLint uniView = f.glGetUniformLocation(shaderProgram, "view");
    f.glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
    GLint uniProj = f.glGetUniformLocation(shaderProgram, "proj");
    f.glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));


    GLuint ebo;
    f.glGenBuffers(1, &ebo);
    f.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    f.glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

//    GLuint vao;
//    f.glGenVertexArrays(1, &vao);
//    f.glBindVertexArray(vao);



}

void GameCanvas::paintGL() {
    QOpenGLFunctions f(QOpenGLContext::currentContext());
    f.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    f.glClear(GL_COLOR_BUFFER_BIT);

    // Calculate transformation
    auto t_now = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - time_start).count();

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(
            trans,
            time * glm::radians(180.0f),
            glm::vec3(0.0f, 0.0f, 1.0f)
    );
    f.glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(trans));

    yellow->bind();
    f.glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    yellow->release();
}

void GameCanvas::resizeGL(int width, int height) {
}
