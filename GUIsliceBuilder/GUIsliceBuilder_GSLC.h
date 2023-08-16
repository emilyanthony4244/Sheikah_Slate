//<File !Start!>
// FILE: [GUIsliceBuilder_GSLC.h]
// Created by GUIslice Builder version: [0.17.b12]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>

// Ensure optional features are enabled in the configuration
#if !(GSLC_SD_EN)
  #error "Config: GSLC_SD_EN required for this program but not enabled. Please see: https://github.com/ImpulseAdventure/GUIslice/wiki/Configuring-GUIslice"
#endif
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be TFT_eSPI
#endif
#include <Adafruit_GFX.h>
#include "dosis_bold8pt7b.h"
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
#define IMG_BKGND                 "/4k_botw_sheikah_slate_by_si7vervvolf_dbxczga-fullview.bmp"
#define IMG_CAMBUTTON             "/cambutton.bmp"
#define IMG_CAMBUTTON_SEL         "/cambutton.bmp"
#define IMG_LOCKBUTTON            "/lockbutton.bmp"
#define IMG_LOCKBUTTON_SEL        "/lockbutton.bmp"
#define IMG_MAGBUTTON             "/magbutton.bmp"
#define IMG_MAGBUTTON_SEL         "/magbutton.bmp"
#define IMG_MAPBUTTON             "/mapbutton.bmp"
#define IMG_MAPBUTTON_SEL         "/mapbutton.bmp"
#define IMG_SENSORBUTTON          "/sensorbutton.bmp"
#define IMG_SENSORBUTTON_SEL      "/sensorbutton.bmp"
#define IMG_TUNESBUTTON           "/tunesbutton.bmp"
#define IMG_TUNESBUTTON_SEL       "/tunesbutton.bmp"
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_BASE,E_MAIN,E_CAM_CONTROL};
enum {E_ELEM_IMAGEBTN2,E_ELEM_IMAGEBTN3,E_ELEM_IMAGEBTN4
      ,E_ELEM_IMAGEBTN5,E_ELEM_IMAGEBTN6,E_ELEM_IMAGEBTN7
      ,E_ELEM_IMAGEBTN8,E_ELEM_TEXT1};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN5X8,E_DOSIS_BOLD8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                3

#define MAX_ELEM_PG_BASE 1 // # Elems total on page
#define MAX_ELEM_PG_BASE_RAM MAX_ELEM_PG_BASE // # Elems in RAM

#define MAX_ELEM_MAIN 6 // # Elems total on page
#define MAX_ELEM_MAIN_RAM MAX_ELEM_MAIN // # Elems in RAM

#define MAX_ELEM_CAM_CONTROL 1 // # Elems total on page
#define MAX_ELEM_CAM_CONTROL_RAM MAX_ELEM_CAM_CONTROL // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asBasePage1Elem[MAX_ELEM_PG_BASE_RAM];
gslc_tsElemRef                  m_asBasePage1ElemRef[MAX_ELEM_PG_BASE];
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_MAIN];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_CAM_CONTROL_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_CAM_CONTROL];

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_DOSIS_BOLD8,GSLC_FONTREF_PTR,&dosis_bold8pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_BASE,m_asBasePage1Elem,MAX_ELEM_PG_BASE_RAM,m_asBasePage1ElemRef,MAX_ELEM_PG_BASE);
  gslc_PageAdd(&m_gui,E_MAIN,m_asPage1Elem,MAX_ELEM_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_MAIN);
  gslc_PageAdd(&m_gui,E_CAM_CONTROL,m_asPage2Elem,MAX_ELEM_CAM_CONTROL_RAM,m_asPage2ElemRef,MAX_ELEM_CAM_CONTROL);

  // Now mark E_PG_BASE as a "base" page which means that it's elements
  // are always visible. This is useful for common page elements.
  gslc_SetPageBase(&m_gui, E_PG_BASE);


  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_MAIN);
  
  // Set Background to an image
  gslc_SetBkgndImage(&m_gui,gslc_GetImageFromSD((const char*)IMG_BKGND,GSLC_IMGREF_FMT_BMP24));

  // -----------------------------------
  // PAGE: E_PG_BASE
  
  
  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT1,E_PG_BASE,(gslc_tsRect){10,450,139,10},
    (char*)"SHEIKAH SLATE BUILD 0.0",0,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);

  // -----------------------------------
  // PAGE: E_MAIN
  
  
  // Create E_ELEM_IMAGEBTN2 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN2,E_MAIN,(gslc_tsRect){62,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_CAMBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_CAMBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  
  // Create E_ELEM_IMAGEBTN3 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN3,E_MAIN,(gslc_tsRect){178,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_LOCKBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_LOCKBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  
  // Create E_ELEM_IMAGEBTN4 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN4,E_MAIN,(gslc_tsRect){294,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_MAGBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_MAGBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  
  // Create E_ELEM_IMAGEBTN5 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN5,E_MAIN,(gslc_tsRect){410,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_MAPBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_MAPBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  
  // Create E_ELEM_IMAGEBTN6 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN6,E_MAIN,(gslc_tsRect){526,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_SENSORBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_SENSORBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
  
  // Create E_ELEM_IMAGEBTN7 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN7,E_MAIN,(gslc_tsRect){642,186,96,96},
          gslc_GetImageFromSD((const char*)IMG_TUNESBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_TUNESBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);

  // -----------------------------------
  // PAGE: E_CAM_CONTROL
  
  
  // Create E_ELEM_IMAGEBTN8 button with image label
  pElemRef = gslc_ElemCreateBtnImg(&m_gui,E_ELEM_IMAGEBTN8,E_CAM_CONTROL,(gslc_tsRect){240,190,96,96},
          gslc_GetImageFromSD((const char*)IMG_CAMBUTTON,GSLC_IMGREF_FMT_BMP24),
          gslc_GetImageFromSD((const char*)IMG_CAMBUTTON_SEL,GSLC_IMGREF_FMT_BMP24),
          &CbBtnCommon);
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
