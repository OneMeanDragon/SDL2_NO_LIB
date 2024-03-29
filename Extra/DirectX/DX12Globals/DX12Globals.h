#if !defined(_DX12_GLOBALS_HEADER)
#define _DX12_GLOBALS_HEADER
#pragma once

#pragma comment(lib, "D3D12.lib") /* DirectX12                                */
#pragma comment(lib, "DXGI.lib")  /* DirectX DXGI Creating a DXGI 1.1 Factory */
#include <d3d12.h>
#include <dxgi1_4.h>

#ifdef _DEBUG
	#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
	#include <dxgidebug.h>
	#pragma comment(lib, "dxguid.lib")
#endif

namespace DirectX {

	struct FrameContext
	{
		ID3D12CommandAllocator* CommandAllocator;
		UINT64                  FenceValue;
	};

	class DX12Globals {
	private:
		static DX12Globals* sInstance;
	private:
		DX12Globals();
		~DX12Globals();
	public:
		DX12Globals(const DX12Globals& obj) = delete; /* Remove the copy constructor */
		void operator=(const DX12Globals&) = delete;  /* Remove the assignment operator */
	public:
		static DX12Globals* Instance();
		static void Release();
	public:
		static int const             NUM_FRAMES_IN_FLIGHT = 3;
		FrameContext                 g_frameContext[NUM_FRAMES_IN_FLIGHT] = {};
		UINT                         g_frameIndex = 0;

		static int const             NUM_BACK_BUFFERS{ 3 };
		ID3D12Device*                g_pd3dDevice = nullptr;
		ID3D12DescriptorHeap*        g_pd3dRtvDescHeap = nullptr;
		ID3D12DescriptorHeap*        g_pd3dSrvDescHeap = nullptr;
		ID3D12CommandQueue*          g_pd3dCommandQueue = nullptr;
		ID3D12GraphicsCommandList*   g_pd3dCommandList = nullptr;
		ID3D12Fence*                 g_fence = nullptr;
		HANDLE                       g_fenceEvent = nullptr;
		UINT64                       g_fenceLastSignaledValue = 0;
		IDXGISwapChain3*             g_pSwapChain = nullptr;
		HANDLE                       g_hSwapChainWaitableObject = nullptr;
		ID3D12Resource*              g_mainRenderTargetResource[NUM_BACK_BUFFERS] = {};
		D3D12_CPU_DESCRIPTOR_HANDLE  g_mainRenderTargetDescriptor[NUM_BACK_BUFFERS] = {};

	public:
		IDXGISwapChain3* SwapChain() { return g_pSwapChain; }
		ID3D12Resource* MainRenderTargetResource(UINT Idx) { return g_mainRenderTargetResource[Idx]; }
		ID3D12GraphicsCommandList* CommandList() { return g_pd3dCommandList; }
		D3D12_CPU_DESCRIPTOR_HANDLE MainRenderTargetDescriptor(UINT Idx) { return g_mainRenderTargetDescriptor[Idx]; }
		ID3D12CommandQueue* CommandQueue() { return g_pd3dCommandQueue; }

	public:
		bool CreateDeviceD3D(HWND hWnd);
		void CleanupDeviceD3D();
		void CreateRenderTarget();
		void CleanupRenderTarget();
		void WaitForLastSubmittedFrame();
		FrameContext* WaitForNextFrameResources();

	};

}

#endif