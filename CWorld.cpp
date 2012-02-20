#include "Cworld.h"
#include "defFonctions.h"



CWorld::CWorld( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nShowCmd)
{

	//grab instance handle
	hInst = hInstance ;

	//fill in window class
	WNDCLASSEX wc ;
	wc.cbClsExtra = 0 ;	//no extra class information
	wc.cbSize = sizeof ( WNDCLASSEX ) ; //size of structure
	wc.cbWndExtra = 0 ;	//no extra window information
	wc.hbrBackground = ( HBRUSH ) GetStockObject ( BLACK_BRUSH ) ;	//black brush
	wc.hCursor = NULL ;	//no cursor
	wc.hIcon = NULL ;	//no icon
	wc.hIconSm = NULL ;	//no small icon
	wc.hInstance = hInstance ;	//instance handle
	wc.lpfnWndProc = DefWindowProc ;	//window procedure
	wc.lpszClassName = WINDOWCLASS ;	//name of class
	wc.lpszMenuName = NULL ;	//no menu
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC ;	//class styles

	//register window class
	RegisterClassEx ( &wc ) ;

	//create window
	mainHwnd = CreateWindowEx ( 0 , WINDOWCLASS , WINDOWTITLE , WS_OVERLAPPEDWINDOW , 0 , 0 , 640 , 480 , NULL , NULL , hInstance , NULL ) ;

	//show the window
	ShowWindow ( mainHwnd , nShowCmd ) ;

	//initialization
	
	if (!initD3D())
		PostQuitMessage(0);
	
	if (FAILED(input.initDInput()))
		PostQuitMessage(0);
	input.setFunc(DIK_ESCAPE, quit);
	loadMap("map/map1.txt");
	CGod *player;
	POINT ms;
	ms.x = 1;
	ms.y = 1;
	
	player = new CGod(ms);
	player->setAnimeSet(_units);
	_dobjects = new CGoList();
	_dobjects->_current = player;

	
	MSG msg ;
	//message pump
	for ( ; ; ) 
	{
		//check for a message
		if ( PeekMessage( &msg , NULL , 0 , 0 , PM_REMOVE ) )
		{
			//message exists

			//check for quit message
			if ( msg.message == WM_QUIT ) break ;

			//translate the message
			TranslateMessage ( &msg ) ;

			//dispatch the message
			DispatchMessage ( &msg ) ;
		}
		else 
			gameLoop();
	}
	
}

void CWorld::gameLoop() {
	input.getInput();
	renderFrame(NULL, NULL);
}
CWorld::~CWorld(void)
{
	clearD3D();
	input.clearDInput();
}
