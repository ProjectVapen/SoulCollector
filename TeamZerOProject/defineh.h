#define MFAIL(code,string) if(FAILED( code ) ) { MessageBox(0,string,"error",MB_OK); return E_FAIL; }
#define MFALSE(code,string) if(!( code ) ) { MessageBox(0,string,"error",MB_OK); return E_FAIL; }