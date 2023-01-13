/*MIT License

C++ OpenGL 3D Game Tutorial Series (https://github.com/PardCode/OpenGL-3D-Game-Tutorial-Series)

Copyright (c) 2021-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <OGL3D/Graphics/OVertexArrayObject.h>
#include <OGL3D/Graphics/OUniformBuffer.h>
#include <OGL3D/Graphics/OShaderProgram.h>
#include <glad/glad.h>

OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferDesc& vbDesc)
{
    return std::make_shared<OVertexArrayObject>(vbDesc);
}

OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferDesc& vbDesc, const OIndexBufferDesc& ibDesc)
{
    return std::make_shared<OVertexArrayObject>(vbDesc, ibDesc);
}

OUniformBufferPtr OGraphicsEngine::createUniformBuffer(const OUniformBufferDesc& desc)
{
    return std::make_shared<OUniformBuffer>(desc);
}

OShaderProgramPtr OGraphicsEngine::createShaderProgram(const OShaderProgramDesc& desc)
{
    return std::make_shared<OShaderProgram>(desc);
}

void OGraphicsEngine::clear(const OVec4& color)
{
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OGraphicsEngine::setFaceCulling(const OCullType& type)
{
    auto cullType = GL_BACK;

    if (type == OCullType::FrontFace) cullType = GL_FRONT;
    else if (type == OCullType::BackFace) cullType = GL_BACK;
    else if (type == OCullType::Both) cullType = GL_FRONT_AND_BACK;

    glEnable(GL_CULL_FACE);
    glCullFace(cullType);
}

void OGraphicsEngine::setWindingOrder(const OWindingOrder& order)
{
    auto orderType = GL_CW;

    if (order == OWindingOrder::ClockWise) orderType = GL_CW;
    else if (order == OWindingOrder::CounterClockWise) orderType = GL_CCW;

    glFrontFace(orderType);
}

void OGraphicsEngine::setViewport(const ORect& size)
{
    glViewport(size.left,size.top,size.width,size.height);
}

void OGraphicsEngine::setVertexArrayObject(const OVertexArrayObjectPtr& vao)
{
    glBindVertexArray(vao->getId());
}

void OGraphicsEngine::setUniformBuffer(const OUniformBufferPtr& buffer, ui32 slot)
{
    glBindBufferBase(GL_UNIFORM_BUFFER, slot, buffer->getId());
}

void OGraphicsEngine::setShaderProgram(const OShaderProgramPtr& program)
{
    glUseProgram(program->getId());
}

void OGraphicsEngine::drawTriangles(const OTriangleType& triangleType, ui32 vertexCount, ui32 offset)
{
    auto glTriType = GL_TRIANGLES;

    switch (triangleType)
    {
    case OTriangleType::TriangleList: { glTriType = GL_TRIANGLES; break; }
    case OTriangleType::TriangleStrip: { glTriType = GL_TRIANGLE_STRIP; break; }
    }

    glDrawArrays(glTriType, offset, vertexCount);
}

void OGraphicsEngine::drawIndexedTriangles(const OTriangleType& triangleType, ui32 indicesCount)
{
    auto glTriType = GL_TRIANGLES;

    switch (triangleType)
    {
    case OTriangleType::TriangleList: { glTriType = GL_TRIANGLES; break; }
    case OTriangleType::TriangleStrip: { glTriType = GL_TRIANGLE_STRIP; break; }
    }

    glDrawElements(glTriType, indicesCount, GL_UNSIGNED_INT, nullptr);
}
