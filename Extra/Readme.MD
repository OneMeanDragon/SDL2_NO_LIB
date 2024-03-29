# Temporary Classes
That may or may not have anything to do with SDL.

### Direct3D + SDL
```cpp
#define INCLUDE_DIRECTX12D3D
#define INCLUDE_SDL2

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cassert>

#include "SDL2/SDL2Inc.h"
#include "DirectX/DXInc.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nShowCmd) {
    if (CSDL::Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        //printf("Error: %s\n", CSDL::GetError());
        return -1;
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    CSDL::SetHint(SDL_HINT_IME_SHOW_UI, "1"); // = CSDL::SetHint("SDL_IME_SHOW_UI", "1");
#endif

    int32_t width = 1280;
    int32_t height = 720;

    // Setup window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = CSDL::CreateHWindow("SDL2+Direct3D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    CSDL::GetWindowWMInfo(window, &wmInfo);
    HWND hwnd = (HWND)wmInfo.info.win.window;

    // Initialize Direct3D
    DirectX::DX12Globals* dx = DirectX::DX12Globals::Instance();
    if (!dx->CreateDeviceD3D(hwnd))
    {
        dx->CleanupDeviceD3D();
        return 1;
    }


    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (CSDL::PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == CSDL::GetWindowID(window))
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED && event.window.windowID == CSDL::GetWindowID(window))
            {
                // Release all outstanding references to the swap chain's buffers before resizing.
                dx->CleanupRenderTarget();
                HRESULT result = dx->SwapChain()->ResizeBuffers(0, event.window.data1, event.window.data2, DXGI_FORMAT_UNKNOWN, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT);
                assert(SUCCEEDED(result) && "Failed to resize swapchain.");
                dx->CreateRenderTarget();
            }
        }

        DirectX::FrameContext* frameCtx = dx->WaitForNextFrameResources();
        UINT backBufferIdx = dx->SwapChain()->GetCurrentBackBufferIndex();
        frameCtx->CommandAllocator->Reset();

        D3D12_RESOURCE_BARRIER barrier = {};
        barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        barrier.Transition.pResource = dx->MainRenderTargetResource(backBufferIdx);
        barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        dx->CommandList()->Reset(frameCtx->CommandAllocator, nullptr);
        dx->CommandList()->ResourceBarrier(1, &barrier);


        const float clear_color_with_alpha[4] = { 0.0f, 0.5f, 0.7f, 1.0f };
        dx->CommandList()->ClearRenderTargetView(dx->MainRenderTargetDescriptor(backBufferIdx), clear_color_with_alpha, 0, nullptr);
        dx->CommandList()->OMSetRenderTargets(1, &dx->g_mainRenderTargetDescriptor[backBufferIdx], FALSE, nullptr);
        dx->CommandList()->SetDescriptorHeaps(1, &dx->g_pd3dSrvDescHeap);
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        dx->CommandList()->ResourceBarrier(1, &barrier);
        dx->CommandList()->Close();


        dx->CommandQueue()->ExecuteCommandLists(1, (ID3D12CommandList* const*)&dx->g_pd3dCommandList);

        dx->SwapChain()->Present(1, 0); // Present with vsync
        UINT64 fenceValue = dx->g_fenceLastSignaledValue + 1;
        dx->CommandQueue()->Signal(dx->g_fence, fenceValue);
        dx->g_fenceLastSignaledValue = fenceValue;
        frameCtx->FenceValue = fenceValue;
    }

    dx->CleanupDeviceD3D();
    DirectX::DX12Globals::Release();
    dx = nullptr;

    CSDL::DestroyWindow(window);
    CSDL::Quit();
    return 0;
}
```
### Direct2D + SDL
```cpp
#define INCLUDE_DIRECT2D
#define INCLUDE_SDL2

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cassert>

#include "Graphics/SDL2/SDL2Inc.h"
#include "Graphics/DirectX/DXInc.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nShowCmd) {
    if (CSDL::Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        //printf("Error: %s\n", CSDL::GetError());
        return -1;
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    CSDL::SetHint(SDL_HINT_IME_SHOW_UI, "1"); // = CSDL::SetHint("SDL_IME_SHOW_UI", "1");
#endif

    int32_t width = 1280;
    int32_t height = 720;

    // Setup window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = CSDL::CreateHWindow("SDL2+Direct2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    CSDL::GetWindowWMInfo(window, &wmInfo);
    HWND hwnd = (HWND)wmInfo.info.win.window;

#if defined(INCLUDE_DIRECT2D)
    if (DirectX::DX2DGlobals::SetWindow(hwnd)) {
        DirectX::DX2DGlobals* dx = DirectX::DX2DGlobals::Instance();
        bool done = false;
        while (!done)
        {
#pragma region "EarlyUpdate()"
            // update the current delta time, and input
            // 
            // Gather the Input data
            SDL_Event event;
            while (CSDL::PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    done = true;
                if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == CSDL::GetWindowID(window))
                    done = true;
            }
#pragma endregion

#pragma region "Update(Delta)"
            // Update via the DeltaTime
#pragma endregion

#pragma region "Begin Draw"
            dx->BeginDraw();
            dx->ClearScreen(0.0f, 0.0f, 0.0f);
#pragma endregion

#pragma region "Render()"
            for (int i = 0; i < 1000; i++) {
                dx->DrawCircle(
                    (float)(rand() % width),
                    (float)(rand() % height),
                    (float)(rand() % 100),
                    (rand() % 100) / 100.0f,
                    (rand() % 100) / 100.0f,
                    (rand() % 100) / 100.0f,
                    (rand() % 100) / 100.0f
                );
            }
#pragma endregion

#pragma region "End Draw"
            dx->EndDraw();
#pragma endregion
            int x = 1; /* just here for a break point for reasons read next lines */
#pragma region "Frame Lock"
            // should be implemented unless you want your device to melt
#pragma endregion
        }
        DirectX::DX2DGlobals::Release();
    }
#endif

    CSDL::DestroyWindow(window);
    CSDL::Quit();
    return 0;
}
```
