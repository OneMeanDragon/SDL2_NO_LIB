#include "DX2DGlobals.h"
#include <cassert>

namespace DirectX {

	namespace {
		template<class Interface>
		inline void SafeRelease(Interface** ppInterfaceToRelease)
		{
			if (*ppInterfaceToRelease != nullptr)
			{
				(*ppInterfaceToRelease)->Release();
				(*ppInterfaceToRelease) = nullptr;
			}
		}
	}

	// Statics
	DX2DGlobals* DX2DGlobals::sInstance = nullptr;
	DX2DGlobals* DX2DGlobals::Instance() {
		if (sInstance == nullptr) { sInstance = new DX2DGlobals(); }
		return sInstance;
	}
	void DX2DGlobals::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	D2D1_SIZE_U DX2DGlobals::mWindowSize = {0};
	HWND DX2DGlobals::mWindow = nullptr;
	bool DX2DGlobals::SetWindow(HWND windowhandle) {
		DX2DGlobals::mWindow = { windowhandle };
		RECT client_rect{ 0 };
		GetClientRect(DX2DGlobals::mWindow, &client_rect);
		DX2DGlobals::mWindowSize = D2D1::SizeU(client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);
		return (DX2DGlobals::mWindow != nullptr);
	}
	// /End statics

	DX2DGlobals::DX2DGlobals()
		:
		mFactory(nullptr),
		mRenderTarget(nullptr),
		mBrush(nullptr)
	{
		/* 
			Initalize
				1: could init the factory
				2: can init the hwnd staticly (and then instance the class and init everything)
				3: brush needs (2:) for a render target
		*/
		if (DX2DGlobals::mWindow != nullptr) { /* window handle must be set */
			HRESULT res{ S_OK };
			res = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &mFactory);
			assert(res == S_OK);
			res = mFactory->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(DX2DGlobals::mWindow, DX2DGlobals::mWindowSize),
				&mRenderTarget);
			assert(res == S_OK);
			res = mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &mBrush);
			assert(res == S_OK);
		}
	}
	DX2DGlobals::~DX2DGlobals() {
		SafeRelease(&mFactory);
		SafeRelease(&mRenderTarget);
		SafeRelease(&mBrush);
	}

	void DX2DGlobals::BeginDraw() {
		mRenderTarget->BeginDraw();
	}

	void DX2DGlobals::EndDraw() {
		mRenderTarget->EndDraw();
	}

	void DX2DGlobals::ClearScreen(float r, float g, float b, float a) {
		mRenderTarget->Clear(D2D1::ColorF(r, g, b, a));
	}

	void DX2DGlobals::DrawCircle(float x, float y, float rad, float r, float g, float b, float a) {
		mBrush->SetColor(D2D1::ColorF(r, g, b, a));
		mRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), rad, rad), mBrush, 3.0f);
	}

}
