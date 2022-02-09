
#include "Application.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

Application::Application()
{
	_hInst = nullptr;
	_hWnd = nullptr;
	_driverType = D3D_DRIVER_TYPE_NULL;
	_featureLevel = D3D_FEATURE_LEVEL_11_0;
	_pd3dDevice = nullptr;
	_pImmediateContext = nullptr;
	_pSwapChain = nullptr;
	_pRenderTargetView = nullptr;
	_pVertexShader = nullptr;
	_pPixelShader = nullptr;
	_pVertexLayout = nullptr;
	_pVertexBuffer = nullptr;
	_pIndexBuffer = nullptr;
	_pConstantBuffer = nullptr;
}

Application::~Application()
{
	Cleanup();
}

HRESULT Application::Initialise(HINSTANCE hInstance, int nCmdShow)
{
    if (FAILED(InitWindow(hInstance, nCmdShow)))
	{
        return E_FAIL;
	}

    RECT rc;
    GetClientRect(_hWnd, &rc);
    _WindowWidth = rc.right - rc.left;
    _WindowHeight = rc.bottom - rc.top;

    if (FAILED(InitDevice()))
    {
        Cleanup();

        return E_FAIL;
    }

	// Initialize the world matrix
	XMStoreFloat4x4(&_world, XMMatrixIdentity());

    // Initialize the view matrix
	XMVECTOR Eye = XMVectorSet(0.0f, 0.0f, -3.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	XMStoreFloat4x4(&_view, XMMatrixLookAtLH(Eye, At, Up));

    // Initialize the projection matrix
	XMStoreFloat4x4(&_projection, XMMatrixPerspectiveFovLH(XM_PIDIV2, _WindowWidth / (FLOAT) _WindowHeight, 0.01f, 100.0f));

	return S_OK;
}

HRESULT Application::InitShadersAndInputLayout()
{
	HRESULT hr;

    // Compile the vertex shader
    ID3DBlob* pVSBlob = nullptr;
    hr = CompileShaderFromFile(L"DX11 Framework.fx", "VS", "vs_4_0", &pVSBlob);

    if (FAILED(hr))
    {
        MessageBox(nullptr,
                   L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
        return hr;
    }

	// Create the vertex shader
	hr = _pd3dDevice->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), nullptr, &_pVertexShader);

	if (FAILED(hr))
	{	
		pVSBlob->Release();
        return hr;
	}

	// Compile the pixel shader
	ID3DBlob* pPSBlob = nullptr;
    hr = CompileShaderFromFile(L"DX11 Framework.fx", "PS", "ps_4_0", &pPSBlob);

    if (FAILED(hr))
    {
        MessageBox(nullptr,
                   L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
        return hr;
    }

	// Create the pixel shader
	hr = _pd3dDevice->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), nullptr, &_pPixelShader);
	pPSBlob->Release();

    if (FAILED(hr))
        return hr;

    // Define the input layout
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	UINT numElements = ARRAYSIZE(layout);

    // Create the input layout
	hr = _pd3dDevice->CreateInputLayout(layout, numElements, pVSBlob->GetBufferPointer(),
                                        pVSBlob->GetBufferSize(), &_pVertexLayout);
	pVSBlob->Release();

	if (FAILED(hr))
        return hr;

    // Set the input layout
    _pImmediateContext->IASetInputLayout(_pVertexLayout);

	return hr;
}

HRESULT Application::InitVertexBuffer()
{
	HRESULT hr;

    // Create vertex buffer
    SimpleVertex vertices[] =
    {
		//Cube1
       { XMFLOAT3( -1.0f, 1.0f, -1.0f ), XMFLOAT3( -0.58f, 0.58f, -0.58f) },
        { XMFLOAT3( 1.0f, 1.0f, -1.0f ), XMFLOAT3( 0.58f, 0.58f, 0.58f) },
        { XMFLOAT3( -1.0f, -1.0f, -1.0f ), XMFLOAT3(-0.58f, -0.58f, -0.58f) },
        { XMFLOAT3( 1.0f, -1.0f, -1.0f ), XMFLOAT3( 0.58f, -0.58f, -0.58f) },
		{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT3(-0.58f, 0.58f, 0.58f) },
		{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(0.58f, 0.58f, 0.58f) },
		{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT3(-0.58f, -0.58f, 0.58f) },
		{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT3(0.58f, -0.58f, 0.58f) },

		///Cube2
		/*{ XMFLOAT3(2.0f, 0.5f, -0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(3.0f, 0.5f, -0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(2.0f, -0.5f, -0.5f), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(3.0f, -0.5f, -0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(3.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(2.0f, -0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(3.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },/**/

    };

    D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(SimpleVertex) * 8;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = vertices;

    hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pVertexBuffer);

    if (FAILED(hr))
        return hr;

	return S_OK;
}

HRESULT Application::InitIndexBuffer()
{
	HRESULT hr;

    // Create index buffer
    WORD indices[] =
    {

		//Cube 1

		//Front
        0,1,2,
        2,1,3,
		

		//Right
		5,3,1,
		3,5,7,
		

		//Top
		0,4,1,
		4,5,1,
		

		//Left
		4,0,2,
		2,6,4,

		//Bottom
		3,6,2,
		3,7,6,

		//Back
		6,5,4,
		6,7,5,

		
    };

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(WORD) * 36;     
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = indices;
    hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pIndexBuffer);

    if (FAILED(hr))
        return hr;

	return S_OK;
}



HRESULT Application::InitVertexBufferPyr()
{
	HRESULT hr;

	// Create vertex buffer
	SimpleVertex vertices[] =
	{
		//pyr------------------------------------------------------------------
			/*{ XMFLOAT3(-1.0f, 0.0f, 1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
			{ XMFLOAT3(-1.0f, 0.0f, -1.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
			{ XMFLOAT3(1.0f, 0.0f, 1.0f), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f) },
			{ XMFLOAT3(1.0f, 0.0f, -1.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
			{ XMFLOAT3(0.0f, 2.0f, 0.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
			//----------------------------------------------------------------------*/

			{ XMFLOAT3(-1.0f, 0.0f, 1.0f), XMFLOAT3(-0.71f, 0.0f, 0.71f) },
			{ XMFLOAT3(-1.0f, 0.0f, -1.0f), XMFLOAT3(-0.71f, 0.0f,-0.71f) },
			{ XMFLOAT3(1.0f, 0.0f, 1.0f), XMFLOAT3(0.71f, 0.0f, 0.71f ) },
			{ XMFLOAT3(1.0f, 0.0f, -1.0f), XMFLOAT3(0.71f, 0.0f, -0.71f) },
			{ XMFLOAT3(0.0f, 2.0f, 0.0f), XMFLOAT3(0.71f, 0.0f, 0.71f) },
	};

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * 5;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;

	hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pVertexBuffer);

	if (FAILED(hr))
		return hr;

	return S_OK;
}



HRESULT Application::InitVertexBufferPlane()
{
	HRESULT hr;

	// Create vertex buffer
	SimpleVertex vertices[] =
	{
		

			{ XMFLOAT3(-2.0f, -4.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-1.0f, -4.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(0.0f, -4.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(1.0f, -4.0f, -1.0f),XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(2.0f, -4.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-2.0f, -4.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-1.0f, -4.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(0.0f, -4.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(1.0f, -4.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(2.0f, -4.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-2.0f, -4.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-1.0f, -4.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(0.0f, -4.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(1.0f, -4.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(2.0f, -4.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-2.0f, -4.0f, 2.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-1.0f, -4.0f, 2.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(0.0f, -4.0f, 2.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(1.0f, -4.0f, 2.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(2.0f, -4.0f, 2.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-2.0f, -4.0f, 3.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(-1.0f, -4.0f, 3.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(0.0f, -4.0f, 3.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(1.0f, -4.0f, 3.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{ XMFLOAT3(2.0f, -4.0f, 3.0f), XMFLOAT3(0.0f, 1.0f, 0.0f)}
			


	};

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * 25;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;

	hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pVertexBuffer);

	if (FAILED(hr))
		return hr;

	return S_OK;
}

HRESULT Application::InitIndexBufferPlane()
{
	HRESULT hr;

	// Create index buffer
	WORD indices[] =
	{

		0,6,1,
		1,7,2,
		2,8,3,
		3,9,4,
		5,6,0,
		1,6,7,
		2,7,8,
		3,8,9,
		5,11,6,
		6,12,7,
		7,13,8,
		8,14,9,
		5,10,11,
		6,11,12,
		7,12,13,
		8,13,14,
		10,16,11,
		11,17,12,
		12,18,13,
		13,19,14,
		10,15,16,
		11,16,17,
		12,17,18,
		13,18,19,
		15,21,16,
		16,22,17,
		17,23,18,
		18,24,19,
		15,20,21,
		16,21,22,
		17,22,23,
		18,23,24
	

	};

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(WORD) * 96;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = indices;
	hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pIndexBuffer);

	if (FAILED(hr))
		return hr;

	return S_OK;
}

HRESULT Application::InitIndexBufferPyr()
{
	HRESULT hr;

	// Create index buffer
	WORD indices[] =
	{
		0,1,2,
		2,1,3,
		3,1,4,
		4,1,0,
		0,2,4,
		4,2,3

	};

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(WORD) * 18;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = indices;
	hr = _pd3dDevice->CreateBuffer(&bd, &InitData, &_pIndexBuffer);

	if (FAILED(hr))
		return hr;

	return S_OK;
}
HRESULT Application::InitWindow(HINSTANCE hInstance, int nCmdShow)
{
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW );
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Create window
   _hInst = hInstance;
    RECT rc = {0, 0, 640, 480};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    _hWnd = CreateWindow(L"TutorialWindowClass", L"DX11 Framework", WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
                         nullptr);
    if (!_hWnd)
		return E_FAIL;

    ShowWindow(_hWnd, nCmdShow);

    return S_OK;
}

HRESULT Application::CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(DEBUG) || defined(_DEBUG)
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;
    hr = D3DCompileFromFile(szFileName, nullptr, nullptr, szEntryPoint, szShaderModel, 
        dwShaderFlags, 0, ppBlobOut, &pErrorBlob);

    if (FAILED(hr))
    {
        if (pErrorBlob != nullptr)
            OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());

        if (pErrorBlob) pErrorBlob->Release();

        return hr;
    }

    if (pErrorBlob) pErrorBlob->Release();

    return S_OK;
}

HRESULT Application::InitDevice()
{
    HRESULT hr = S_OK;

    UINT createDeviceFlags = 0;

#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };

    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };


	D3D11_TEXTURE2D_DESC depthStencilDesc;
	depthStencilDesc.Width = _WindowWidth;
	depthStencilDesc.Height = _WindowHeight;
	depthStencilDesc.MipLevels = 1;
	depthStencilDesc.ArraySize = 1;
	depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilDesc.SampleDesc.Count = 1;
	depthStencilDesc.SampleDesc.Quality = 0;
	depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
	depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilDesc.CPUAccessFlags = 0;
	depthStencilDesc.MiscFlags = 0;
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	
	
	


    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = _WindowWidth;
    sd.BufferDesc.Height = _WindowHeight;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = _hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
        _driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain(nullptr, _driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
                                           D3D11_SDK_VERSION, &sd, &_pSwapChain, &_pd3dDevice, &_featureLevel, &_pImmediateContext);
        if (SUCCEEDED(hr))
            break;
    }

    if (FAILED(hr))
        return hr;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = nullptr;
    hr = _pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

    if (FAILED(hr))
        return hr;

    hr = _pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &_pRenderTargetView);
    pBackBuffer->Release();

    if (FAILED(hr))
        return hr;

    _pImmediateContext->OMSetRenderTargets(1, &_pRenderTargetView, nullptr);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)_WindowWidth;
    vp.Height = (FLOAT)_WindowHeight;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    _pImmediateContext->RSSetViewports(1, &vp);

	InitShadersAndInputLayout();

	InitVertexBuffer();
	//InitVertexBufferPyr();

	_pd3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, &_depthStencilBuffer);
	_pd3dDevice->CreateDepthStencilView(_depthStencilBuffer, nullptr, &_depthStencilView);

    // Set vertex buffer
    UINT stride = sizeof(SimpleVertex);
    UINT offset = 0;
    _pImmediateContext->IASetVertexBuffers(0, 1, &_pVertexBuffer, &stride, &offset);

	InitIndexBuffer();
	//InitIndexBufferPyr();
    // Set index buffer
    _pImmediateContext->IASetIndexBuffer(_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);

    // Set primitive topology
    _pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Create the constant buffer
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(ConstantBuffer);
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;
    hr = _pd3dDevice->CreateBuffer(&bd, nullptr, &_pConstantBuffer);

    if (FAILED(hr))
        return hr;

    return S_OK;
}

void Application::Cleanup()
{
    if (_pImmediateContext) _pImmediateContext->ClearState();

    if (_pConstantBuffer) _pConstantBuffer->Release();
    if (_pVertexBuffer) _pVertexBuffer->Release();
    if (_pIndexBuffer) _pIndexBuffer->Release();
    if (_pVertexLayout) _pVertexLayout->Release();
    if (_pVertexShader) _pVertexShader->Release();
    if (_pPixelShader) _pPixelShader->Release();
    if (_pRenderTargetView) _pRenderTargetView->Release();
    if (_pSwapChain) _pSwapChain->Release();
    if (_pImmediateContext) _pImmediateContext->Release();
    if (_pd3dDevice) _pd3dDevice->Release();
	if (_depthStencilView) _depthStencilView->Release();
	if (_depthStencilBuffer) _depthStencilBuffer->Release();

}

void Application::Update()
{
    // Update our time
    static float t = 0.0f;

    if (_driverType == D3D_DRIVER_TYPE_REFERENCE)
    {
        t += (float) XM_PI * 0.0125f;
    }
    else
    {
        static DWORD dwTimeStart = 0;
        DWORD dwTimeCur = GetTickCount();

        if (dwTimeStart == 0)
            dwTimeStart = dwTimeCur;

        t = (dwTimeCur - dwTimeStart) / 1000.0f;
    }

    //
    // Animate the cube
    //
	XMStoreFloat4x4(&_world, XMMatrixTranslation(6.0f, 6.0f, 0.0f) * XMMatrixScaling(0.2f, 0.2f, 0.2f) * XMMatrixRotationZ(-t) * XMMatrixRotationZ(-t));
	//XMStoreFloat4x4(&_world2, XMMatrixRotationX(t) * XMMatrixTranslation(2.0f, 0.0f, 0.0f));
	XMStoreFloat4x4(&_world2, XMMatrixTranslation(18.0f, 23.0f, 0.0f)* XMMatrixScaling(0.1f, 0.1f, 0.1f)* XMMatrixRotationZ(t));
	XMStoreFloat4x4(&_world3, XMMatrixTranslation(-18.0f,-23.0f, 0.0f) * XMMatrixScaling(0.1f, 0.1f, 0.1f) * XMMatrixRotationZ(-t));
	XMStoreFloat4x4(&_worldPlane, XMMatrixTranslation(0.0f, 0.0f, 0.0f) * XMMatrixScaling(0.5f, 0.5f, 0.5f));
	XMStoreFloat4x4(&_world4, XMMatrixTranslation(0.0f, 0.0f, 0.0f) * XMMatrixScaling(0.5f, 0.5f, 0.5f) * XMMatrixRotationY(-t));
	
	/*XMStoreFloat4x4(&_world, XMMatrixTranslation(-5.0f, 0.0f, 0.0f) * XMMatrixScaling(0.5f, 0.5f, 0.5f));
	XMStoreFloat4x4(&_world2,XMMatrixTranslation(0.0f, 0.0f, 0.0f) * XMMatrixScaling(0.5f, 0.5f, 0.5f));
	XMStoreFloat4x4(&_world3,XMMatrixTranslation(5.0f, 0.0f, 0.0f) * XMMatrixScaling(0.5f, 0.5f, 1.0f));*/
	

	



}

void Application::Draw()
{
    //
    // Clear the back buffer
    //
    float ClearColor[4] = {0.0f, 0.125f, 0.3f, 1.0f}; // red,green,blue,alpha
    _pImmediateContext->ClearRenderTargetView(_pRenderTargetView, ClearColor);




	XMMATRIX world = XMLoadFloat4x4(&_world);
	XMMATRIX view = XMLoadFloat4x4(&_view);
	XMMATRIX projection = XMLoadFloat4x4(&_projection);

	
    //
    // Update variables
    //
    ConstantBuffer cb;
	cb.mWorld = XMMatrixTranspose(world);
	cb.mView = XMMatrixTranspose(view);
	cb.mProjection = XMMatrixTranspose(projection);
	

	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);

	InitVertexBuffer();
	//InitVertexBufferPyr();

	// Set vertex buffer
	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	_pImmediateContext->IASetVertexBuffers(0, 1, &_pVertexBuffer, &stride, &offset);

	InitIndexBuffer();
	//InitIndexBufferPyr();
	// Set index buffer
	_pImmediateContext->IASetIndexBuffer(_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
	
	/*world = XMLoadFloat4x4(&_world2);
	cb.mWorld = XMMatrixTranspose(world);
	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);
	
	_pImmediateContext->DrawIndexed(36, 0, 0);*/

    //
    // Renders a triangle
    //
	_pImmediateContext->VSSetShader(_pVertexShader, nullptr, 0);
	_pImmediateContext->VSSetConstantBuffers(0, 1, &_pConstantBuffer);
    _pImmediateContext->PSSetConstantBuffers(0, 1, &_pConstantBuffer);
	_pImmediateContext->PSSetShader(_pPixelShader, nullptr, 0);
	_pImmediateContext->DrawIndexed(36, 0, 0);  


	

	world = XMLoadFloat4x4(&_world2);
	cb.mWorld = XMMatrixTranspose(world);
	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);
	_pImmediateContext->DrawIndexed(36, 0, 0);

	world = XMLoadFloat4x4(&_world3);
	cb.mWorld = XMMatrixTranspose(world);
	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);
	_pImmediateContext->DrawIndexed(36, 0, 0);


	InitVertexBufferPlane();
	// Set vertex buffer
	stride = sizeof(SimpleVertex);
	offset = 0;
	_pImmediateContext->IASetVertexBuffers(0, 1, &_pVertexBuffer, &stride, &offset);

	InitIndexBufferPlane();
	
	// Set index buffer
	_pImmediateContext->IASetIndexBuffer(_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);

	world = XMLoadFloat4x4(&_worldPlane);
	cb.mWorld = XMMatrixTranspose(world);
	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);
	_pImmediateContext->DrawIndexed(96, 0, 0);



	InitVertexBufferPyr();
	//InitVertexBufferPyr();

	// Set vertex buffer
	stride = sizeof(SimpleVertex);
	offset = 0;
	_pImmediateContext->IASetVertexBuffers(0, 1, &_pVertexBuffer, &stride, &offset);

	InitIndexBufferPyr();
	//InitIndexBufferPyr();
	// Set index buffer
	_pImmediateContext->IASetIndexBuffer(_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);


	world = XMLoadFloat4x4(&_world4);
	cb.mWorld = XMMatrixTranspose(world);
	_pImmediateContext->UpdateSubresource(_pConstantBuffer, 0, nullptr, &cb, 0, 0);
	_pImmediateContext->DrawIndexed(36, 0, 0);


	_pImmediateContext->ClearDepthStencilView(_depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    //
    // Present our back buffer to our front buffer
    //
    _pSwapChain->Present(0, 0);
}