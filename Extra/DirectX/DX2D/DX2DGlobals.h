#if !defined(_DX2D_GLOBALS_HEADER)
#define _DX2D_GLOBALS_HEADER
#pragma once

#pragma comment(lib, "D2D1.lib") /* DirectX Direct2D */
#include <d2d1_3.h>

namespace DirectX {

	class DX2DGlobals {
	private:
		static DX2DGlobals* sInstance;
	private:
		DX2DGlobals();
		~DX2DGlobals();
	public:
		DX2DGlobals(const DX2DGlobals& obj) = delete; /* Remove the copy constructor */
		void operator=(const DX2DGlobals&) = delete;  /* Remove the assignment operator */
	public:
		static DX2DGlobals* Instance();
		static void Release();
	private:
		ID2D1Factory* mFactory;
		ID2D1HwndRenderTarget* mRenderTarget;
		ID2D1SolidColorBrush* mBrush;
	public:
		bool Init(HWND hWnd);

		void BeginDraw();
		void EndDraw();
		void ClearScreen(float r, float g, float b, float a = (1.0f));
		void DrawCircle(float x, float y, float rad, float r, float g, float b, float a = (1.0f));
	};

}

#endif
