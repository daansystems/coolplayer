/*
 * CoolPlayer - Blazing fast audio player.
 * Copyright (C) 2000-2001 Niek Albers
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#include "stdafx.h"
#include "globals.h"
#include "CPI_Player.h"
#include "CPI_Playlist.h"
#include "CPI_PlaylistItem.h"
#include "CPI_ID3.h"


////////////////////////////////////////////////////////////////////////
//
//
//
void    playlist_move_control(int ControlID, LPRECT NewPlaylistrect,
                              int type)
{
    /*
       RECT    winrect;

       int     xsize, ysize;

       HWND    hwndDlg = windows.dlg_playlist;
       HWND    hwndControl = GetDlgItem(hwndDlg, ControlID);

       GetWindowRect(hwndControl,	// handle to window
    	  &winrect);	// address of structure for window coordinates

       xsize = winrect.right - winrect.left;
       ysize = winrect.bottom - winrect.top;
       ScreenToClient(hwndDlg,	// window handle for source coordinates
    	   (LPPOINT) & winrect);	// address of structure containing coordinates);

       switch (type) {
       case TOPRIGHT:
    MoveWindow(hwndControl,	// handle to window
    	   winrect.left +
    	   ((NewPlaylistrect->right - globals.playlist_rect.right)
    	    + (globals.playlist_rect.left - NewPlaylistrect->left)),	// horizontal position
    	   winrect.top,	//+NewPlaylistrect->top,          // vertical position
    	   xsize,	// width
    	   ysize,	// height
    	   TRUE);	// repaint flag
    break;
       case RESIZE:
    MoveWindow(hwndControl,	// handle to window
    	   winrect.left,	// horizontal position
    	   winrect.top,	//+NewPlaylistrect->top,          // vertical position
    	   xsize +
    	   ((NewPlaylistrect->right - globals.playlist_rect.right)
    	    + (globals.playlist_rect.left - NewPlaylistrect->left)),	// width
    	   ysize +
    	   ((NewPlaylistrect->bottom
    	     - globals.playlist_rect.bottom) +
    	    (globals.playlist_rect.top - NewPlaylistrect->top)),	// height
    	   TRUE);	// repaint flag
    break;
       case BOTTOMLEFT:
    MoveWindow(hwndControl,	// handle to window
    	   winrect.left,	// horizontal position
    // horizontal position
    	   winrect.top +
    	   ((NewPlaylistrect->bottom
    	     - globals.playlist_rect.bottom) +
    	    (globals.playlist_rect.top - NewPlaylistrect->top)),	//+NewPlaylistrect->top,          // vertical position
    	   xsize,	// width
    	   ysize,	// height
    	   TRUE);	// repaint flag
    break;
       case BOTTOMRIGHT:
    MoveWindow(hwndControl,	// handle to window
    	   winrect.left +
    	   ((NewPlaylistrect->right - globals.playlist_rect.right)
    	    + (globals.playlist_rect.left - NewPlaylistrect->left)),	// horizontal position
    	   winrect.top +
    	   ((NewPlaylistrect->bottom
    	     - globals.playlist_rect.bottom) +
    	    (globals.playlist_rect.top - NewPlaylistrect->top)),	//+NewPlaylistrect->top,          // vertical position
    	   xsize,	// width
    	   ysize,	// height
    	   TRUE);	// repaint flag
    break;
       }
    */
}

BOOL    playlist_skin_set_control_bitmap(char *position)
{
    /*
       HWND    hDlg = windows.dlg_playlist;
       HWND    button;
       unsigned int teller = 0;
       char    name[MAX_PATH];
       int     controlid = 0;
       short   i = 0;
       LONG    style;
       UINT    x = 0, y = 0, w = 0, h = 0;

       char   *items[] =
    { "Add", "Save", "AddDir", "Clear", "ClearSel", "MoveUp",
    "MoveDown",
    "Shuffle", "Close", "Close2",
    "Minimize", "Maximize", "Find", NULL
       };
       UINT    controlids[] =
    { IDC_OPENLIST, IDC_SAVELIST, IDC_ADDDIR, IDC_CLEAR, IDC_CLEARSEL,
    IDC_MOVEUP, IDC_MOVEDOWN, IDC_SHUFFLE, IDOK, IDC_CLOSE, IDC_MINIMIZE, 
    IDC_MAXIMIZE, IDC_FIND,
    0
       };
       RECT    winrect;
       WINDOWPLACEMENT wndpl;
       if (IsIconic(hDlg)) {
    wndpl.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(hDlg, &wndpl);
    CopyRect(&winrect, &wndpl.rcNormalPosition);
       } else
    GetWindowRect(hDlg, &winrect);
       winrect.right -= winrect.left;
       winrect.bottom -= winrect.top;
       winrect.left = 0;
       winrect.top = 0;

       while (teller < strlen(position)) {
    if (position[teller] == '=' || position[teller] == ',')
        position[teller] = ' ';
    teller++;
       }
       sscanf(position, "%s %d %d %d %d", name, &x, &y, &w, &h);

       while (items[i] != NULL) {
    if (!stricmp(name, items[i])) {
        controlid = controlids[i];
        break;
    };
    i++;
       }

       if (!stricmp(name, "List")) {
    button = GetDlgItem(hDlg, IDC_PLAYLIST);
    SetWindowPos(button, NULL, x, y, winrect.right - w - x,
    	     winrect.bottom - h - y,
    	     SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_NOREDRAW);
    return TRUE;
       }

       if (controlid) {
    BITMAP  bm;
    char    playlistbitmapfile[MAX_PATH];
    char    pathname[MAX_PATH];
    button = GetDlgItem(hDlg, controlid);
    style = GetWindowLong(button, GWL_STYLE);
    style |= BS_OWNERDRAW;
    SetWindowLong(button, GWL_STYLE, style);
    SetWindowLong(button, GWL_USERDATA, w);
    strcpy(playlistbitmapfile, options.playlist_skin_file);
    path_remove_filespec(playlistbitmapfile);

    sprintf(pathname, "%s%s.bmp", playlistbitmapfile, name);
    DeleteObject(PlayListBitmap.bm[i]);
    PlayListBitmap.bm[i] =
        LoadImage(0, pathname, IMAGE_BITMAP, 0, 0,
    	      LR_LOADFROMFILE);

    if (!PlayListBitmap.bm[i])
        ShowWindow(GetDlgItem(hDlg, controlid), SW_HIDE);
    GetObject(PlayListBitmap.bm[i], sizeof(bm), &bm);
    SetWindowPos(GetDlgItem(hDlg, controlid), NULL, 0, 0,
    	     bm.bmWidth, bm.bmHeight / 2,
    	     SWP_NOREDRAW | SWP_NOMOVE | SWP_NOOWNERZORDER |
    	     SWP_NOZORDER);
    switch (w) {
    case BOTTOMRIGHT:
        SetWindowPos(button, NULL, winrect.right - x,
    		 winrect.bottom - y, 0, 0,
    		 SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER
    		 | SWP_NOREDRAW);
        break;
    case TOPRIGHT:
        SetWindowPos(button, NULL, winrect.right - x, y, 0, 0,
    		 SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER
    		 | SWP_NOREDRAW);
        break;
    case BOTTOMLEFT:
        SetWindowPos(button, NULL, x, winrect.bottom - y, 0, 0,
    		 SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER
    		 | SWP_NOREDRAW);
        break;
    case TOPLEFT:
        SetWindowPos(button, NULL, x, y, 0, 0,
    		 SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER
    		 | SWP_NOREDRAW);
        break;
    }
    return TRUE;
       }
    	*/
    return FALSE;
}

BOOL    playlist_skin_get_ini_value(char *key, char *position, SIZE * rect)
{
    /*
       SIZE    readrect;
       while (*position != 0) {
    unsigned int teller = 0;
    char    name[MAX_PATH];
    while (teller < strlen(position)) {
        if (position[teller] == '=' || position[teller] == ',')
    	position[teller] = ' ';
        teller++;
    }
    sscanf(position, "%s %i %i", name, &readrect.cx, &readrect.cy);

    if (!stricmp(name, key)) {
        rect->cx = readrect.cx;
        rect->cy = readrect.cy;
        return TRUE;
    }

    position = position + strlen(position) + 1;
       }
    */

    return FALSE;
}

/*
You should add your initialization code here. This function will be called
when the dialog box receives the WM_INITDIALOG message.
*/
int     playlist_skin_read()
{
    /*

       char    values[32768];
       char    playlistfile[MAX_PATH];
       char    playlistbitmapfile[MAX_PATH];
       char   *position;
       char    buffer[4096];
       HWND    hDlg = windows.dlg_playlist;
       int     i = 0;
       UINT    controlids[] =
    { IDC_OPENLIST, IDC_SAVELIST, IDC_ADDDIR, IDC_CLEAR, IDC_CLEARSEL,
    IDC_MOVEUP, IDC_MOVEDOWN, IDC_SHUFFLE, IDOK, IDC_CLOSE, 
    IDC_MINIMIZE, IDC_MAXIMIZE, IDC_FIND,
    0
       };
       while (controlids[i] != 0)
    SetWindowLong(GetDlgItem(hDlg, controlids[i++]), GWL_USERDATA, 0);

       if (!*options.playlist_skin_file || !options.use_playlist_skin)
    return FALSE;
       GetPrivateProfileString(NULL, NULL, NULL,
    		    buffer, sizeof(buffer),
    		    options.playlist_skin_file);

       if (GetPrivateProfileSection
    ("Playlist", values, 32767, options.playlist_skin_file) == 0) {
    MessageBox(hDlg, "Can\'t open ini file!",
    	   options.playlist_skin_file,
    	   MB_ICONERROR | MB_SETFOREGROUND | MB_TOPMOST);
       }				// points to initialization filename
       strcpy(playlistfile, options.playlist_skin_file);
       path_remove_filespec(playlistfile);
       position = values;
       while (*position != 0) {

    playlist_skin_set_control_bitmap(position);
    position = position + strlen(position) + 1;
       }

       sprintf(playlistbitmapfile, "%sPlaylist.bmp", playlistfile);
       DeleteObject(graphics.bmp_playlist_bg);
       graphics.bmp_playlist_bg =
    LoadImage(0, playlistbitmapfile, IMAGE_BITMAP, 0, 0,
    	  LR_LOADFROMFILE);
       if (!graphics.bmp_playlist_bg)
    MessageBox(hDlg, "Can\'t load bitmap", playlistbitmapfile,
    	   MB_ICONERROR | MB_SETFOREGROUND | MB_TOPMOST);

       position = values;
       playlist_skin_get_ini_value("UpLeft", position,
    			&PlayListBitmap.UpLeft);
       position = values;
       playlist_skin_get_ini_value("UpRight", position,
    			&PlayListBitmap.UpRight);
       position = values;
       playlist_skin_get_ini_value("DownLeft", position,
    			&PlayListBitmap.DownLeft);
       position = values;
       playlist_skin_get_ini_value("DownRight", position,
    			&PlayListBitmap.DownRight);
       position = values;
       playlist_skin_get_ini_value("UpMid", position, &PlayListBitmap.UpMid);
       position = values;
       playlist_skin_get_ini_value("DownMid", position,
    			&PlayListBitmap.DownMid);
       position = values;
       playlist_skin_get_ini_value("LeftMid", position,
    			&PlayListBitmap.LeftMid);
       position = values;
       playlist_skin_get_ini_value("RightMid", position,
    			&PlayListBitmap.RightMid);
       position = values;
       playlist_skin_get_ini_value("MinSize", position,
    			&PlayListBitmap.MinSize);
       position = values;
       playlist_skin_get_ini_value("Colors", position,
    			&PlayListBitmap.Colors);

       if (PlayListBitmap.UpLeft.cx) {
    LONG    style;
    HWND    button;
    LONG    data;
    style = GetWindowLong(hDlg, GWL_STYLE);
    style &= ~WS_CAPTION;
    style &= ~WS_THICKFRAME;
    style &= ~WS_BORDER;
    SetWindowLong(hDlg, GWL_STYLE, style);

    ShowWindow(GetDlgItem(hDlg, IDC_MINIMIZE), SW_SHOW);
    ShowWindow(GetDlgItem(hDlg, IDC_MAXIMIZE), SW_SHOW);
    ShowWindow(GetDlgItem(hDlg, IDC_CLOSE), SW_SHOW);
    ShowWindow(GetDlgItem(hDlg, IDC_SORTTEXT), SW_HIDE);
    ShowWindow(GetDlgItem(hDlg, IDC_MOVETEXT), SW_HIDE);

    // Check for the find button.
    button = GetDlgItem(hDlg, IDC_FIND);
    data = GetWindowLong(button, GWL_USERDATA);
    if (!data) {
        ShowWindow(button, SW_HIDE);
    } else
        ShowWindow(button, SW_SHOW);

       } else
    return FALSE;
    */
    return 1;
}

void    playlist_draw_control(UINT controlid, LPDRAWITEMSTRUCT ds)
{
    /*
       HDC     winmemdc = CreateCompatibleDC(ds->hDC);
       HBITMAP h;
       HBITMAP image;
       HPALETTE oldpal;
       int     height = 0, i = 0;
       UINT    controlids[] =
    { IDC_OPENLIST, IDC_SAVELIST, IDC_ADDDIR, IDC_CLEAR, IDC_CLEARSEL,
    IDC_MOVEUP, IDC_MOVEDOWN, IDC_SHUFFLE, IDOK, IDC_CLOSE, IDC_MINIMIZE, 
    IDC_MAXIMIZE, IDC_FIND,	0
       };
       while (controlids[i] != 0) {
    if (controlids[i] == ds->CtlID) {
        image = PlayListBitmap.bm[i];
        break;
    }
    i++;
       }

       if (ds->itemState & ODS_SELECTED) {
    height = ds->rcItem.bottom;
       }

       h = (HBITMAP) SelectObject(winmemdc, image);
       oldpal = SelectPalette(ds->hDC, graphics.pal_main, FALSE);
       RealizePalette(ds->hDC);
       BitBlt(ds->hDC, 0, 0, ds->rcItem.right, ds->rcItem.bottom, winmemdc,
       0, height, SRCCOPY);
       SelectPalette(ds->hDC, oldpal, FALSE);
       SelectObject(winmemdc, h);
       DeleteDC(winmemdc);
    */
}

#define	 MIDUP	1
#define  MIDDOWN	2
#define  MIDLEFT	3
#define  MIDRIGHT	4
#define	 CENTER		5

BOOL    playlist_skin_draw_side(HDC hdc, HDC winmemdc, BITMAP * bm,
                                RECT * winrect, int type)
{
    /*
       RECT    Siderect;
       RECT    Destrect;
       int     mode;
       switch (type) {

       case MIDUP:
    Siderect.left = PlayListBitmap.UpLeft.cx;
    Siderect.top = 0;
    Siderect.right = bm->bmWidth - PlayListBitmap.UpRight.cx;
    Siderect.bottom = PlayListBitmap.UpMid.cx;

    Destrect.left = PlayListBitmap.UpLeft.cx;
    Destrect.top = 0;
    Destrect.right = winrect->right - (PlayListBitmap.UpRight.cx);
    Destrect.bottom = PlayListBitmap.UpMid.cx;
    mode = PlayListBitmap.UpMid.cy;
    break;
       case MIDDOWN:
    Siderect.left = PlayListBitmap.DownLeft.cx;
    Siderect.top = bm->bmHeight - PlayListBitmap.DownMid.cx;
    Siderect.right = bm->bmWidth - PlayListBitmap.DownRight.cx;
    Siderect.bottom = bm->bmHeight;

    Destrect.left = PlayListBitmap.DownLeft.cx;
    Destrect.top = winrect->bottom - (PlayListBitmap.DownMid.cx);
    Destrect.right = winrect->right - (PlayListBitmap.DownRight.cx);
    Destrect.bottom = winrect->bottom;
    mode = PlayListBitmap.DownMid.cy;

    break;

       case MIDLEFT:
    Siderect.left = 0;
    Siderect.top = PlayListBitmap.UpLeft.cy;
    Siderect.right = PlayListBitmap.LeftMid.cx;
    Siderect.bottom = bm->bmHeight - PlayListBitmap.DownLeft.cy;

    Destrect.left = 0;
    Destrect.top = PlayListBitmap.UpLeft.cy;
    Destrect.right = PlayListBitmap.LeftMid.cx;
    Destrect.bottom = winrect->bottom - PlayListBitmap.DownLeft.cy;
    mode = PlayListBitmap.LeftMid.cy;

    break;

       case MIDRIGHT:
    Siderect.left = bm->bmWidth - (PlayListBitmap.RightMid.cx);
    Siderect.top = PlayListBitmap.UpRight.cy;
    Siderect.right = bm->bmWidth;
    Siderect.bottom = bm->bmHeight - PlayListBitmap.DownRight.cy;

    Destrect.left = winrect->right - PlayListBitmap.RightMid.cx;
    Destrect.top = PlayListBitmap.UpRight.cy;
    Destrect.right = winrect->right;
    Destrect.bottom = winrect->bottom - PlayListBitmap.DownRight.cy;
    mode = PlayListBitmap.RightMid.cy;
    break;

       case CENTER:
    Siderect.left = PlayListBitmap.LeftMid.cx;
    Siderect.top = PlayListBitmap.UpMid.cx;
    Siderect.right = bm->bmWidth - PlayListBitmap.RightMid.cx;
    Siderect.bottom = bm->bmHeight - PlayListBitmap.DownMid.cx;

    Destrect.left = PlayListBitmap.LeftMid.cx;
    Destrect.top = PlayListBitmap.UpMid.cx;
    Destrect.right = winrect->right - PlayListBitmap.RightMid.cx;;
    Destrect.bottom = winrect->bottom - PlayListBitmap.DownMid.cx;

    mode = 1;

    break;
       }

       if (mode == 1) {
    StretchBlt(hdc,		// handle to destination DC
    	   Destrect.left,	// x-coord of destination upper-left corner
    	   Destrect.top,	// y-coord of destination upper-left corner
    	   Destrect.right - Destrect.left,	// width of destination rectangle
    	   Destrect.bottom - Destrect.top,	// height of destination rectangle
    	   winmemdc,	// handle to source DC
    	   Siderect.left,	// x-coord of source upper-left corner
    	   Siderect.top,	// y-coord of source upper-left corner
    	   Siderect.right - Siderect.left,	// width of source rectangle
    	   Siderect.bottom - Siderect.top,	// height of source rectangle
    	   SRCCOPY	// raster operation code
        );

       } else {
    //      Figure out when our last images will be drawn.
    int     nEndCol =
        (Destrect.right - Destrect.left) / (Siderect.right -
    					Siderect.left) + 1;
    int     nEndRow =
        (Destrect.bottom - Destrect.top) / (Siderect.bottom -
    					Siderect.top) + 1;
    int     nCol, nRow;

    //
    //      We would use clipping when the tiling is used as a background bitmap.
    //      This would substantially reduce the number of BitBlt's we do.

    for (nCol = 0; nCol < nEndCol; nCol++) {
        int     xcount, xrest = 0;
        xcount =
    	(Destrect.right - Destrect.left) -
    	((Siderect.right - Siderect.left) * (nCol + 1));
        if (xcount < 0)
    	xrest = xcount;
        for (nRow = 0; nRow < nEndRow; nRow++) {
    	int     ycount, yrest = 0;
    	ycount =
    	    (Destrect.bottom - Destrect.top) -
    	    ((nRow + 1) * (Siderect.bottom - Siderect.top));
    	if (ycount < 0)
    	    yrest = ycount;
    	BitBlt(hdc,
    	       Destrect.left +
    	       ((Siderect.right - Siderect.left) *
    		nCol),
    	       Destrect.top +
    	       ((Siderect.bottom - Siderect.top) *
    		nRow),
    	       Siderect.right - Siderect.left + xrest,
    	       Siderect.bottom - Siderect.top + yrest,
    	       winmemdc, Siderect.left, Siderect.top, SRCCOPY);
        }
    }

       }
    */
    return TRUE;
}
//
//
//
LRESULT CALLBACK playlist_windowproc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    /*
       switch (msg) 
    {
       case WM_ERASEBKGND:
    	if(!PlayListBitmap.UpLeft.cx)
    		return FALSE;
    	else
    		return TRUE;
       case WM_PAINT:
    	{
    		HDC     winhdc, winmemdc;
    		HBITMAP h;
    		BITMAP  bm;
    		HPALETTE oldpal;
    		PAINTSTRUCT Paint;
    		RECT    winrect;
    		RECT    Listviewrect;
    		if (!PlayListBitmap.UpLeft.cx)
    		break;
    		winhdc = BeginPaint(hwndDlg, &Paint);

    		GetClientRect(hwndDlg, &winrect);
    		GetWindowRect(windows.m_hWndPlaylist_ListView, &Listviewrect);

    		Listviewrect.right -= Listviewrect.left;
    		Listviewrect.bottom -= Listviewrect.top;

    		ScreenToClient(hwndDlg, (LPPOINT) & Listviewrect);

    		Listviewrect.right += Listviewrect.left;
    		Listviewrect.bottom += Listviewrect.top;

    		ExcludeClipRect(winhdc, Listviewrect.left, Listviewrect.top,
    				Listviewrect.right, Listviewrect.bottom);

    		winmemdc = CreateCompatibleDC(winhdc);
    		GetObject(graphics.bmp_playlist_bg, sizeof(bm), &bm);
    		h = (HBITMAP) SelectObject(winmemdc, graphics.bmp_playlist_bg);
    		oldpal = SelectPalette(winhdc, graphics.pal_main, FALSE);
    		RealizePalette(winhdc);
    		BitBlt(winhdc, 0, 0, PlayListBitmap.UpLeft.cx,
    		   PlayListBitmap.UpLeft.cy, winmemdc, 0, 0, SRCCOPY);
    		playlist_skin_draw_side(winhdc, winmemdc, &bm, &winrect,
    					MIDUP);
    		BitBlt(winhdc, winrect.right - (PlayListBitmap.UpRight.cx), 0,
    		   PlayListBitmap.UpRight.cx, PlayListBitmap.UpRight.cy,
    		   winmemdc, bm.bmWidth - PlayListBitmap.UpRight.cx, 0,
    		   SRCCOPY);
    		playlist_skin_draw_side(winhdc, winmemdc, &bm, &winrect,
    					MIDLEFT);
    		playlist_skin_draw_side(winhdc, winmemdc, &bm, &winrect,
    					MIDRIGHT);
    		BitBlt(winhdc, 0, winrect.bottom - PlayListBitmap.DownLeft.cy,
    		   PlayListBitmap.DownLeft.cx, PlayListBitmap.DownLeft.cy,
    		   winmemdc, 0, bm.bmHeight - PlayListBitmap.DownLeft.cy,
    		   SRCCOPY);
    		playlist_skin_draw_side(winhdc, winmemdc, &bm, &winrect,
    					MIDDOWN);
    		BitBlt(winhdc, winrect.right - (PlayListBitmap.DownRight.cx),
    		   winrect.bottom - PlayListBitmap.DownRight.cy,
    		   PlayListBitmap.DownRight.cx,
    		   PlayListBitmap.DownRight.cy, winmemdc,
    		   bm.bmWidth - PlayListBitmap.DownRight.cx,
    		   bm.bmHeight - PlayListBitmap.DownRight.cy, SRCCOPY);
    		SelectPalette(winmemdc, oldpal, FALSE);
    		SelectObject(winmemdc, h);
    		DeleteDC(winmemdc);
    		EndPaint(hwndDlg, &Paint);
    	}
    	return 0;

       case WM_DRAWITEM:
    	playlist_draw_control(wParam, (LPDRAWITEMSTRUCT) lParam);
    	return TRUE;

       case WM_INITDIALOG:
    	windows.wnd_playlist_IPEdit = NULL;
    	playlist_skin_read();
    	return TRUE;

       case WM_SIZE:
    {
        RECT    NewPlaylistrect;
        int     moveflag;

    	InvalidateRect(windows.dlg_playlist, NULL, TRUE);
        if (wParam != SIZE_MINIMIZED) {

    	GetWindowRect(hwndDlg, &NewPlaylistrect);
    	windows.dlg_playlist = hwndDlg;
    	playlist_move_control(IDC_PLAYLIST, &NewPlaylistrect,
    			      RESIZE);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_SORTTEXT),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_SORTTEXT, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_OPENLIST),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_OPENLIST, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_SAVELIST),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_SAVELIST, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem(hwndDlg, IDC_CLEAR),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_CLEAR, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_CLEARSEL),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_CLEARSEL, &NewPlaylistrect,
    			      moveflag);

    	if (!(moveflag = GetWindowLong(GetDlgItem(hwndDlg, IDC_MOVETEXT), GWL_USERDATA)))
    		moveflag = TOPRIGHT;
    	playlist_move_control(IDC_MOVETEXT, &NewPlaylistrect, moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_MOVEUP),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_MOVEUP, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_MOVEDOWN),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_MOVEDOWN, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem(hwndDlg, IDOK),
    			   GWL_USERDATA))) moveflag = BOTTOMRIGHT;
    	playlist_move_control(IDOK, &NewPlaylistrect, moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_SHUFFLE),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_SHUFFLE, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_ADDDIR),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_ADDDIR, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_MINIMIZE),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_MINIMIZE, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem
    			   (hwndDlg, IDC_MAXIMIZE),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_MAXIMIZE, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem(hwndDlg, IDC_CLOSE),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_CLOSE, &NewPlaylistrect,
    			      moveflag);

    	if (!
    	    (moveflag =
    	     GetWindowLong(GetDlgItem(hwndDlg, IDC_FIND),
    			   GWL_USERDATA))) moveflag = TOPRIGHT;
    	playlist_move_control(IDC_FIND, &NewPlaylistrect,
    			      moveflag);

    	GetWindowRect(hwndDlg, &globals.playlist_rect);
    	CopyRect(&options.playlist_window_pos,
    		 &globals.playlist_rect);
        }
        break;
    }

    return 0;

       }
    */
    return FALSE;
}
