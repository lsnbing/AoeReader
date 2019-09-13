#include "Reader.h"
#include "AppConfig.h"
#include <ShellAPI.h>
#include <Shlwapi.h>
#include "AA_String.h"
ReaderClient::ReaderClient()
{

}
ReaderClient::~ReaderClient()
{

}
void ReaderClient::Run()
{


	//res_file_name = L"def.skin";
	//AAGuiOption gui_option;
	//gui_option.use_zip = true;
	//gui_option.resource_filename = res_file_name.c_str();
		//AAGuiInit(gui_option);


		const WORD LangID_ja_JP = MAKELANGID(LANG_JAPANESE, SUBLANG_JAPANESE_JAPAN);
		const WORD LangID_en_US = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);

		printf("LangID_ja_JP = 0x%04hx\n", LangID_ja_JP); // 0x0411
		printf("LangID_en_US = 0x%04hx\n", LangID_en_US); // 0x0409

		_ASSERTE(PRIMARYLANGID(LangID_ja_JP) == LANG_JAPANESE);
		_ASSERTE(PRIMARYLANGID(LangID_en_US) == LANG_ENGLISH);

		// �ʤ����ձ��Z OS ��٩`���Ȥ������Z�ѥå����m�ä��������Ǥϡ�
		// ���`����ձ��Z�Τޤޣ�ANSI ���`�ɥک`���� CP932, Shift_JIS �Τޤޣ��ʤΤǡ�
		// ���ޥ�ɥץ��ץȤǤϥǥե�����O�����ձ��Z�����Ф��ʾ�Ǥ��롣

		const WORD sysDefLangId = ::GetSystemDefaultLangID();
		const WORD usrDefLangId = ::GetUserDefaultLangID();
		const WORD sysDefUILang = ::GetSystemDefaultUILanguage();
		const WORD usrDefUILang = ::GetUserDefaultUILanguage();
		const DWORD sysDefLcid = ::GetSystemDefaultLCID();
		const DWORD usrDefLcid = ::GetUserDefaultLCID();


		//Identifier 
		//	Language

		//	0x0000 
		//	Language  Neutral   

		//	0x0400
		//	Process Default Language   

		//	0x0401
		//	Arabic   (Saudi   Arabia)
		//	�������ɳ�ذ�������
		//	0x0801
		//	Arabic   (Iraq)
		//	������
		//	0x0c01
		//	Arabic   (Egypt)
		//	����
		//	0x1001
		//	Arabic   (Libya)   
		//	������
		//	0x1401
		//	Arabic   (Algeria) 
		//	����������
		//	0x1801
		//	Arabic   (Morocco)
		//	Ħ���
		//	0x1c01
		//	Arabic   (Tunisia)   
		//	ͻ��˹
		//	0x2001
		//	Arabic   (Oman) 
		//	����
		//	0x2401
		//	Arabic   (Yemen) 
		//	Ҳ��
		//	0x2801
		//	Arabic   (Syria) 
		//	������
		//	0x2c01
		//	Arabic   (Jordan) 
		//	Լ��
		//	0x3001
		//	Arabic   (Lebanon)  
		//	�����
		//	0x3401
		//	Arabic   (Kuwait)  
		//	������
		//	0x3801
		//	Arabic   (U.A.E.)
		//	����������������
		//	0x3c01
		//	Arabic   (Bahrain) 
		//	����
		//	0x4001
		//	Arabic   (Qatar)
		//	������
		//	0x0402
		//	Bulgarian   
		//	����������
		//	0x0403
		//	Catalan
		//	��̩������
		//	0x0404
		//	Chinese   (Taiwan   Region) 
		//	̨��
		//	0x0804
		//	Chinese   (PRC) 
		//	�л����񹲺͹�
		//	0x0c04
		//	Chinese   (Hong   Kong   SAR,   PRC) 
		//	���
		//	0x1004
		//	Chinese   (Singapore) 
		//	�¼���
		//	0x0405
		//	Czech 
		//	�ݿ�
		//	0x0406
		//	Danish
		//	����
		//	0x0407
		//	German   (Standard)
		//	�����׼��
		//	0x0807
		//	German   (Swiss) 
		//	��ʿ
		//	0x0c07
		//	German   (Austrian)
		//	�µ���
		//	0x1007
		//	German   (Luxembourg)
		//	¬ɭ��
		//	0x1407
		//	German   (Liechtenstein)
		//	��֧��ʿ��
		//	0x0408
		//	Greek 
		//	ϣ��
		//	0x0409
		//	English   (United   States)   
		//	����
		//	0x0809
		//	English   (United   Kingdom)   
		//	Ӣ��
		//	0x0c09
		//	English   (Australian)  
		//	�Ĵ�����
		//	0x1009
		//	English   (Canadian) 
		//	���ô�
		//	0x1409
		//	English   (New   Zealand) 
		//	������
		//	0x1809
		//	English   (Ireland) 
		//	������
		//	0x1c09
		//	English   (South   Africa)  
		//	�Ϸ�
		//	0x2009
		//	English   (Jamaica)
		//	�����
		//	0x2409
		//	English   (Caribbean)
		//	���ձ�
		//	0x2809
		//	English   (Belize) 
		//	������
		//	0x2c09
		//	English   (Trinidad) 
		//	�������
		//	0x040a
		//	Spanish   (Traditional   Sort) 
		//	���������ͳ���
		//	0x080a
		//	Spanish   (Mexican)   
		//	ī����
		//	0x0c0a
		//	Spanish   (Modern   Sort) 
		//	��������ִ�����
		//	0x100a
		//	Spanish   (Guatemala)  
		//	Σ������
		//	0x140a
		//	Spanish   (Costa   Rica) 
		//	��˹�����
		//	0x180a
		//	Spanish   (Panama) 
		//	������
		//	0x1c0a
		//	Spanish   (Dominican   Republic)   
		//	������ӹ��͹�
		//	0x200a
		//	Spanish   (Venezuela)
		//	ί������
		//	0x240a
		//	Spanish   (Colombia)  
		//	���ױ���
		//	0x280a
		//	Spanish   (Peru)  
		//	��³
		//	0x2c0a
		//	Spanish   (Argentina)   
		//	����͢
		//	0x300a
		//	Spanish   (Ecuador) 
		//	��϶��
		//	0x340a
		//	Spanish   (Chile) 
		//	����
		//	0x380a
		//	Spanish   (Uruguay)
		//	������
		//	0x3c0a
		//	Spanish   (Paraguay) 
		//	������
		//	0x400a
		//	Spanish   (Bolivia)  
		//	����ά��
		//	0x440a
		//	Spanish   (El   Salvador)
		//	�����߶�
		//	0x480a
		//	Spanish   (Honduras)
		//	�鶼��˹
		//	0x4c0a
		//	Spanish   (Nicaragua) 
		//	�������
		//	0x500a
		//	Spanish   (Puerto   Rico)   
		//	�������
		//	0x040b
		//	Finnish  
		//	����
		//	0x040c
		//	French   (Standard)
		//	����
		//	0x080c
		//	French   (Belgian) 
		//	����ʱ
		//	0x0c0c
		//	French   (Canadian) 
		//	���ô�
		//	0x100c
		//	French   (Swiss)  
		//	��ʿ
		//	0x140c
		//	French   (Luxembourg)
		//	¬ɭ��
		//	0x040d
		//	Hebrew
		//	ϣ������
		//	0x040e
		//	Hungarian
		//	������
		//	0x040f
		//	Icelandic
		//	����
		//	0x0410
		//	Italian   (Standard) 
		//	��������׼��
		//	0x0810
		//	Italian   (Swiss)
		//	��ʿ
		//	0x0411
		//	Japanese  
		//	���յ�
		//	0x0412
		//	Korean
		//	����
		//	0x0812
		//	Korean   (Johab)  
		//	���ģ��ù���
		//	0x0413
		//	Dutch   (Standard)
		//	������
		//	0x0813
		//	Dutch   (Belgian)
		//	����ʱ
		//	0x0414
		//	Norwegian   (Bokmal)
		//	Ų���ģ��Ϳ�Ħ��
		//	0x0814
		//	Norwegian   (Nynorsk) 
		//	��ŵ˹��
		//	0x0415
		//	Polish
		//	����
		//	0x0416
		//	Portuguese   (Brazilian)
		//	�������������
		//	0x0816
		//	Portuguese   (Standard)

		//	0x0418
		//	Romanian 
		//	����
		//	0x0419
		//	Russian
		//	����˹
		//	0x041a
		//	Croatian 
		//	���޵���
		//	0x081a
		//	Serbian   (Latin) 
		//	����ά���������
		//	0x0c1a
		//	Serbian   (Cyrillic) 
		//	�������
		//	0x041b
		//	Slovak 
		//	˹�工��
		//	0x041c
		//	Albanian
		//	������������
		//	0x041d
		//	Swedish
		//	���
		//	0x081d
		//	Swedish   (Finland)  
		//	����������
		//	0x041e
		//	Thai 
		//	̩��
		//	0x041f
		//	Turkish 
		//	������
		//	0x0421
		//	Indonesian
		//	ӡ��������
		//	0x0422
		//	Ukrainian  
		//	�ڿ���
		//	0x0423
		//	Belarusian
		//	�׶���˹
		//	0x0424
		//	Slovenian 
		//	˹��������
		//	0x0425
		//	Estonian
		//	��ɳ������
		//	0x0426
		//	Latvian  
		//	����ά��
		//	0x0427
		//	Lithuanian
		//	������
		//	0x0429
		//	Farsi
		//	��˹��
		//	0x042a
		//	Vietnamese 
		//	Խ��
		//	0x042d
		//	Basque 
		//	��˹��
		//	0x0436
		//	Afrikaans
		//	�Ϸ���
		//	0x0438
		//	Faeroese 

		switch (sysDefLangId)
		{
		case 0X0804:
			{
				//MessageBox(0, L"����", 0, 0);
				int ddd = 5;
			}
			break;
		case 0x0409:
			//MessageBox(_T("English"));
			{
				//MessageBox(0, L"Ӣ��", 0, 0);
				int kkk = 3;
			}
		case  0x0411:
			{
			//	MessageBox(0, L"����", 0, 0);
			}
			break;
		}

		LPCTSTR pszCmdLineW = GetCommandLineW();  

		std::wstring file_name = L"";


		if(pszCmdLineW != NULL)
		{
			int num_args = 0;
			wchar_t** args = NULL;
			args = ::CommandLineToArgvW(pszCmdLineW, &num_args);

			std::vector<std::wstring> new_argv;

			if(args && num_args > 1)
			{
				
				for(int i=0; i<num_args; ++i)
				{
					new_argv.push_back(args[i]);
				}

				if(new_argv.size() > 1)
				{
					file_name = new_argv[1];
				}
			}
		}

		if(!file_name.empty())
		{
			int dot_pos = file_name.rfind(L".");
			if(dot_pos != std::wstring::npos)
			{
				wstring extension = file_name.substr(dot_pos + 1, file_name.length() - dot_pos - 1);

				if(extension != L"txt")
				{
					return;
				}
			}
		}

		wchar_t wszAppPath[MAX_PATH] = {0};
		::GetModuleFileName(NULL, wszAppPath, MAX_PATH);
		std::wstring wstrAppPath = wszAppPath;
		std::wstring strTemp = wstrAppPath.substr(0, wstrAppPath.find_last_of(L'\\') + 1);

		strTemp += L"\\reader.res";


		if(!PathFileExistsW(strTemp.c_str()))
		{
			return;
		}

		//SYSTEMTIME time;
		//WIN32_FILE_ATTRIBUTE_DATA lpinf;
		//GetFileAttributesEx(strTemp.c_str(),GetFileExInfoStandard,&lpinf);//��ȡ�ļ���Ϣ��pathΪ�ļ�·��
		//FileTimeToSystemTime(&lpinf.ftLastWriteTime,&time);//ת��ʱ���ʽ��FILETIME��SYSTEMTIME

		//AGuiString fileInfo;
		//fileInfo.Format(_T("%d-%d-%d"),time.wYear,time.wMonth,time.wDay);
		AppConfigure::Instance()->LoadConfig();

		AAGuiOption option;
		/*option.resource_filename = L"reader.res";
		option.use_zip = true;*/
		option.use_zip = false;
		option.disable_dpi = true;
		AAGuiInit(option);

		DataConnectorInit();


		ReaderWindow* readerWidget_ = new ReaderWindow;
		
		if(!file_name.empty())
		{
			readerWidget_->InitOpenFile(file_name);
		}
		if(readerWidget_){

			readerWidget_->Create();

			AAGuiRun();

		}

}