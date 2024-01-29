#include <RadishEngine.h>

int main()
{
    // Graphics Systems:
    rds::GraphicsSystem graphicsSystem;
    graphicsSystem.Initialize({
        { 800, 600 }, "RadishStation v1.0" },
        { 4, 5 }
    );

    // Pipeline:
    rds::PipelineHandle pipeline;
    {
        auto basicVertexHandle = graphicsSystem.CreateShader({ "res/basic.vert", rds::ShaderType::VERTEX });
        auto basicFragHandle = graphicsSystem.CreateShader({ "res/basic.frag", rds::ShaderType::FRAGMENT });

        rds::PipelineInput pipelineDescriptor;
        {
            pipelineDescriptor.shaderHandles.push_back(basicVertexHandle);
            pipelineDescriptor.shaderHandles.push_back(basicFragHandle);
        }

        pipeline = graphicsSystem.CreatePipeline(pipelineDescriptor);
    }

    // Renderer:
    rds::BaseRenderer renderer(&graphicsSystem);
    renderer.SetClearMasks(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer.BindPipeline(pipeline);

    // Main:
    auto& window = graphicsSystem.GetWindow();
    while (window->IsOpen())
    {
        window->PollEvent();

        // Rendering:
        {
            renderer.Begin();
            renderer.Clear({ 0.1f, 0.2f, 0.5f, 1.0f });

            renderer.SubmitQuad({}, {});

            renderer.End();
        }
        
        window->Swapbuffer();
    }

    return 0;
}