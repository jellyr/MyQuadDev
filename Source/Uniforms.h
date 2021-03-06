/*
  ==============================================================================

    Uniforms.h
    Created: 5 Nov 2017 4:31:07pm
    Author:  srejv

  ==============================================================================
*/

#pragma once
//==============================================================================
    // This class just manages the uniform values that the demo shaders use.
    struct Uniforms
    {
        Uniforms (const OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram)
        {
            projectionMatrix = createUniform (openGLContext, shaderProgram, "projectionMatrix");
            viewMatrix       = createUniform (openGLContext, shaderProgram, "viewMatrix");

			// 
			resolution	= createUniform(openGLContext, shaderProgram, "iResolution");
			time		= createUniform(openGLContext, shaderProgram, "iTime");
			timeDelta	= createUniform(openGLContext, shaderProgram, "iTimeDelta");
			frame		= createUniform(openGLContext, shaderProgram, "iFrame");
			mouse		= createUniform(openGLContext, shaderProgram, "iMouse");
			date		= createUniform(openGLContext, shaderProgram, "iDate");
			sampleRate	= createUniform(openGLContext, shaderProgram, "iSampleRate");
			channel0	= createUniform(openGLContext, shaderProgram, "iChannel0");
			feedback = createUniform(openGLContext, shaderProgram, "iFeedback");
			
        }

		ScopedPointer<OpenGLShaderProgram::Uniform>
			projectionMatrix,
			viewMatrix,
			resolution,
			time,
			timeDelta,
			frame,
			mouse,
			date,
			sampleRate,
			channel0,
			feedback;

    private:
        static OpenGLShaderProgram::Uniform* createUniform (const OpenGLContext& openGLContext,
                                                            OpenGLShaderProgram& shaderProgram,
                                                            const char* uniformName)
        {
            if (openGLContext.extensions.glGetUniformLocation (shaderProgram.getProgramID(), uniformName) < 0)
                return nullptr;

            return new OpenGLShaderProgram::Uniform (shaderProgram, uniformName);
        }
    };