//
// GUIslice Library Examples
// - Calvin Hass
// - https://www.impulseadventure.com/elec/guislice-gui.html
// - https://github.com/ImpulseAdventure/GUIslice
// - Example 10 (Arduino): [minimum RAM version]
//     Demonstrate textbox controls
//   - Demonstrates the use of ElemCreate*_P() functions
//     These RAM-reduced examples take advantage of the internal
//     Flash storage (via PROGMEM).
//   - NOTE: This sketch requires moderate program storage in Flash.
//     As a result, it may not run on basic Arduino devices (eg. ATmega328)
//
// ARDUINO NOTES:
// - GUIslice_config.h must be edited to match the pinout connections
//   between the Arduino CPU and the display controller (see ADAGFX_PIN_*).
//

#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
#include "elem/XSlider.h"
#include "elem/XTextbox.h"


// Defines for resources

// Enumerations for pages, elements, fonts, images
enum {E_PG_MAIN};
enum {E_ELEM_BOX,E_ELEM_BTN_QUIT,E_ELEM_COLOR,
      E_SLIDER,E_ELEM_TXT_COUNT,
      E_ELEM_TEXTBOX,E_SCROLLBAR};
enum {E_FONT_TXT,E_FONT_TITLE,MAX_FONT}; // Use separate enum for fonts, MAX_FONT at end

bool      m_bQuit = false;

// Free-running counter for display
unsigned  m_nCount = 0;

// Instantiate the GUI
#define MAX_PAGE                1

// Define the maximum number of elements per page
// - To enable the same code to run on devices that support storing
//   data into Flash (PROGMEM) and those that don't, we can make the
//   number of elements in Flash dependent upon GSLC_USE_PROGMEM
// - This should allow both Arduino and ARM Cortex to use the same code
#define MAX_ELEM_PG_MAIN          7                                        // # Elems total
#if (GSLC_USE_PROGMEM)
  #define MAX_ELEM_PG_MAIN_PROG   6                                        // # Elems in Flash
#else
  #define MAX_ELEM_PG_MAIN_PROG   0                                         // # Elems in Flash
#endif
#define MAX_ELEM_PG_MAIN_RAM      MAX_ELEM_PG_MAIN - MAX_ELEM_PG_MAIN_PROG  // # Elems in RAM

gslc_tsGui                  m_gui;
gslc_tsDriver               m_drv;
gslc_tsFont                 m_asFont[MAX_FONT];
gslc_tsPage                 m_asPage[MAX_PAGE];
gslc_tsElem                 m_asPageElem[MAX_ELEM_PG_MAIN_RAM];   // Storage for all elements in RAM
gslc_tsElemRef              m_asPageElemRef[MAX_ELEM_PG_MAIN];    // References for all elements in GUI

// Define max number of rows and columns
// - Warning: sizing must be considered carefully on limited
//   RAM devices (such as Arduino)
// - For the number of columns, some margin should
//   be provided for special characters:
//   - Each row allocates one byte for the line terminator (NULL)
//   - Each embedded color change consumes 4 bytes
#define TBOX_ROWS           12  // Define max # rows
#define TBOX_COLS           16  // Define max # columns

gslc_tsXTextbox             m_sTextbox;
char                        m_acTextboxBuf[TBOX_ROWS*TBOX_COLS];

#define MAX_STR             15

  // Save some element references for quick access
  gslc_tsElemRef*  m_pElemTextbox        = NULL;

// Define debug message function
static int16_t DebugOut(char ch) { Serial.write(ch); return 0; }

// Quit button callback
bool CbBtnQuit(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  if (eTouch == GSLC_TOUCH_UP_IN) {
    m_bQuit = true;
  }
  return true;
}

bool CbControls(void* pvGui,void* pvElemRef,int16_t nPos)
{
  gslc_tsGui*     pGui      = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef  = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem     = gslc_GetElemFromRef(pGui,pElemRef);

  char            acTxt[20];
  int16_t         nVal;
  gslc_tsElemRef* pElemRefTmp = NULL;

  // Handle various controls
  switch (pElem->nId) {
    case E_SCROLLBAR:
      // Fetch the scrollbar value
      nVal = gslc_ElemXSliderGetPos(pGui,pElemRef);
      // Update the textbox scroll position
      pElemRefTmp = gslc_PageFindElemById(pGui,E_PG_MAIN,E_ELEM_TEXTBOX);
      gslc_ElemXTextboxScrollSet(pGui,pElemRefTmp,nVal,100);
      break;

    case E_SLIDER:
      // Fetch the slider position
      nVal = gslc_ElemXSliderGetPos(pGui,pElemRef);

      // Link slider to the numerical display
      snprintf(acTxt,20,(char*)"%u",nVal);
      pElemRefTmp = gslc_PageFindElemById(pGui,E_PG_MAIN,E_ELEM_TXT_COUNT);
      gslc_ElemSetTxtStr(pGui,pElemRefTmp,acTxt);

      // Link slider to insertion of text into textbox
      pElemRefTmp = gslc_PageFindElemById(pGui,E_PG_MAIN,E_ELEM_TEXTBOX);
      snprintf(acTxt,20,(char*)"Slider=%3u\n",nVal);
      gslc_ElemXTextboxAdd(pGui,pElemRefTmp,acTxt);

      break;

    default:
      break;
  }
  return true;
}

// Create page elements
bool InitOverlays()
{
  gslc_tsElemRef*  pElemRef = NULL;

  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPageElem,MAX_ELEM_PG_MAIN_RAM,m_asPageElemRef,MAX_ELEM_PG_MAIN);

  // Background flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_GRAY_DK2);

  // Create Title with offset shadow
/*
  #define TMP_COL1 (gslc_tsColor){ 32, 32, 60}
  #define TMP_COL2 (gslc_tsColor){128,128,240}
  // Note: must use title Font ID
  gslc_ElemCreateTxt_P(&m_gui,98,E_PG_MAIN,2,2,320,50,"Textbox",&m_asFont[E_FONT_TITLE],
          TMP_COL1,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_ALIGN_MID_MID,false,false);
  gslc_ElemCreateTxt_P(&m_gui,99,E_PG_MAIN,0,0,320,50,"Textbox",&m_asFont[E_FONT_TITLE],
          TMP_COL2,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_ALIGN_MID_MID,false,false);
*/

  // Create background box
  gslc_ElemCreateBox_P(&m_gui,200,E_PG_MAIN,10,50,300,180,GSLC_COL_WHITE,GSLC_COL_BLACK,true,true,NULL,NULL);

  // Example horizontal slider
  gslc_ElemXSliderCreate_P(&m_gui,E_SLIDER,E_PG_MAIN,20,60,140,20,
    0,100,50,5,false,GSLC_COL_GREEN,GSLC_COL_BLACK);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG_MAIN,E_SLIDER);
  gslc_ElemXSliderSetStyle(&m_gui,pElemRef,true,GSLC_COL_GREEN_DK4,10,5,GSLC_COL_GRAY_DK2);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbControls);

  // Text to show slider value
  static char mstr_cnt[8] = ""; // Provide space for large counter value
  gslc_ElemCreateTxt_P_R(&m_gui,E_ELEM_TXT_COUNT,E_PG_MAIN,180,60,40,20,mstr_cnt,8,&m_asFont[E_FONT_TXT],
          GSLC_COL_GRAY_LT2,GSLC_COL_BLACK,GSLC_COL_BLACK,GSLC_ALIGN_MID_LEFT,false,true);


  // Create wrapping box for textbox and scrollbar
  gslc_ElemCreateBox_P(&m_gui,GSLC_ID_AUTO,E_PG_MAIN,18,83,203,64,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK,true,true,NULL,NULL);

  // Create textbox
  // - NOTE: XTextbox does not have a FLASH-based version yet (ElemXTextboxCreate_P)
  pElemRef = gslc_ElemXTextboxCreate(&m_gui,E_ELEM_TEXTBOX,E_PG_MAIN,
    &m_sTextbox,(gslc_tsRect){20,85,180,60},E_FONT_TXT,(char*)&m_acTextboxBuf,
        TBOX_ROWS,TBOX_COLS);
  gslc_ElemXTextboxWrapSet(&m_gui,pElemRef,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_LT2,GSLC_COL_BLACK,GSLC_COL_GRAY_DK3);
  m_pElemTextbox = pElemRef;

  // Create vertical scrollbar for textbox
  gslc_ElemXSliderCreate_P(&m_gui,E_SCROLLBAR,E_PG_MAIN,200,85,20,60,
    0,100,0,5,true,GSLC_COL_BLUE_DK4,GSLC_COL_BLACK);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG_MAIN,E_SCROLLBAR);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbControls);

  // Quit button
  gslc_ElemCreateBtnTxt_P(&m_gui,E_ELEM_BTN_QUIT,E_PG_MAIN,250,60,50,30,"Quit",&m_asFont[E_FONT_TXT],
    GSLC_COL_WHITE,GSLC_COL_BLUE_DK2,GSLC_COL_BLUE_DK4,GSLC_COL_BLUE_DK2,GSLC_COL_BLUE_DK1,GSLC_ALIGN_MID_MID,true,true,&CbBtnQuit,NULL);

  return true;
}


void setup()
{
  // Initialize debug output
  Serial.begin(9600);
  gslc_InitDebug(&DebugOut);
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  // Initialize
  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // Load Fonts
  if (!gslc_FontSet(&m_gui,E_FONT_TXT,GSLC_FONTREF_PTR,NULL,1)) { return; }
  if (!gslc_FontSet(&m_gui,E_FONT_TITLE,GSLC_FONTREF_PTR,NULL,3)) { return; }

  // Create pages display
  InitOverlays();

  // Start up display on main page
  gslc_SetPageCur(&m_gui,E_PG_MAIN);

  // Insert some text
  gslc_tsElemRef* pElemTextbox = gslc_PageFindElemById(&m_gui,E_PG_MAIN,E_ELEM_TEXTBOX);

  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"Welcome\n");
  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"Hi ");
#if (GSLC_FEATURE_XTEXTBOX_EMBED)
  // Can change text color dynamically only if feature enabled
  gslc_ElemXTextboxColSet(&m_gui,pElemTextbox,GSLC_COL_RED);
  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"RED\n");
  gslc_ElemXTextboxColReset(&m_gui,pElemTextbox);
#else
  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"RED\n");
#endif
  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"Long line here that may wrap\n");
  gslc_ElemXTextboxAdd(&m_gui,pElemTextbox,(char*)"End...\n");

  m_bQuit = false;
  return;
}

void loop()
{
    char                acTxt[MAX_STR];

  // General counter
  m_nCount++;

    if ((m_nCount % 5000) == 0) {
      snprintf(acTxt,MAX_STR,"Step %u\n",m_nCount);
      gslc_ElemXTextboxAdd(&m_gui,m_pElemTextbox,acTxt);
    }

  // Periodically call GUIslice update function
  gslc_Update(&m_gui);

  // In a real program, we would detect the button press and take an action.
  // For this Arduino demo, we will pretend to exit by emulating it with an
  // infinite loop. Note that interrupts are not disabled so that any debug
  // messages via Serial have an opportunity to be transmitted.
  if (m_bQuit) {
    gslc_Quit(&m_gui);
    while (1) { }
  }
}
