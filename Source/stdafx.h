// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "include/AAGuiCapi.h"
#include "include/dataConnectorApi.h"
#include "GuiString.h"
#include <WinGDI.h>

#define GUI_DECL_HANDLER(name) \
	void name(const AAObject* sender, const AAGuiArgs& e)
// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#ifndef AAGUIEXEC
#define AAGUIEXEC(frame, element, func, arg)	\
	if(widget_window_)\
	widget_window_->ExcuteCommand(frame, element, func, arg);
#endif

#ifndef __FRAME_BEGIN__ 
#define __FRAME_BEGIN__(name, call_func) \
	if(frame_id){ \
	std::wstring frame_id_ = frame_id;\
	if(frame_id_ == name) \
{\
	call_func;\
}
#endif
#ifndef __FRAME_FUNC__ 
#define __FRAME_FUNC__(name, call_func)\
	else if(frame_id_ == name)\
{\
	call_func();\
}
#endif
#ifndef __FRAME_END__ 
#define __FRAME_END__  };
#endif
#define GUI_BIND_WIDGET_EVENT(frame_, where_, event_name, handler) \
	if(widget_window_){ \
	widget_window_->BindEventHandler(frame_, where_, event_name, AAGuiBind(&handler, this)); }

static void AAGuiSetW(LPCTSTR  frame_id, LPCTSTR  control_id, std::wstring value, AAWidgetWindow* widget_window_)
{
	if(widget_window_ == NULL) return;

	AAGuiArgs Arg;
	Arg.WriteStringW("Value", value); //ֵ
	widget_window_->ExcuteCommand(frame_id, control_id, L"Set", Arg);

}
static std::wstring AAGuiGetW(LPCTSTR  frame_id, LPCTSTR  control_id, AAWidgetWindow* widget_window_)
{
	if(widget_window_ == NULL) return L"";

	AAGuiArgs Arg;

	widget_window_->ExcuteCommand(frame_id, control_id, L"Get", Arg);

	return Arg.GetStringW("ValueW");

}
#define GUI_SETW(frame,element, value) \
	AAGuiSetW(frame, element, value, widget_window_);
#define GUI_GETW(frame,element, value) \
	AAGuiGetW(frame, element, widget_window_);
#define GUI_TASK(name) \
	void name(AAGuiArgs& e)
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"");