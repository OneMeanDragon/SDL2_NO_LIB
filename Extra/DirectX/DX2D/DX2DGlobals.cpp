#include "DX2DGlobals.h"

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

	DX2DGlobals::DX2DGlobals()
		:
		mFactory(nullptr),
		mRenderTarget(nullptr),
		mBrush(nullptr)
	{
		/* Initalize */
	}
	DX2DGlobals::~DX2DGlobals() {
		SafeRelease(&mFactory);
		SafeRelease(&mRenderTarget);
		SafeRelease(&mBrush);
	}

	bool DX2DGlobals::Init(HWND hWnd) {
		if (D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &mFactory) != S_OK) return false;
		
		RECT client_rect{ 0 };
		GetClientRect(hWnd, &client_rect);

		if (mFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(client_rect.right, client_rect.bottom)),
			&mRenderTarget
		) != S_OK) return false;

		if (mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &mBrush) != S_OK) return false;

		return true;
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
