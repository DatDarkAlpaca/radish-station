#include "pch.h"
#include "Graphics/GraphicsSystem.h"

int main()
{
    rds::GraphicsSystem graphicsSystem;
    graphicsSystem.Initialize({ 
        { 800, 600 }, "RadishStation v1.0" }, 
        { 4, 5 }
    );

    auto& window = graphicsSystem.GetWindow();
    while (window->IsOpen())
    {
        window->PollEvent();

        window->Swapbuffer();
    }

    return 0;
}