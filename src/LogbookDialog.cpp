﻿///////////////////////////////////////////////////////////////////////////

// C++ code generated with wxFormBuilder (version Sep  8 2010)

// http://www.wxformbuilder.org/

//

///////////////////////////////////////////////////////////////////////////
#include "LogbookDialog.h"
#include "Logbook.h"
#include "logbook_pi.h"
#include "Options.h"
#include "EzGrid.h"
#include "tinyxml/tinyxml.h"
//#ifdef __WXOSX__
	#include "MessageBoxOSX.h"
//#endif

#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include "wx/generic/gridctrl.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/html/htmlwin.h>
#include <wx/dialog.h>
#include <wx/dirdlg.h> 
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include "wx/stdpaths.h"
#include "wx/fileconf.h"
#include <wx/image.h>
#include <wx/fs_inet.h>
#include "wx/grid.h"
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/dir.h> 
#include <wx/filefn.h>
#include <wx/msgdlg.h> 
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include <wx/mimetype.h>
#include <wx/platinfo.h>
#include <wx/timer.h> 
#include <wx/arrimpl.cpp>

//#define PBVE_DEBUG 1
//////////////////////////////////////////////////////////////////////////

LogbookDialog::LogbookDialog(logbookkonni_pi * d, wxTimer* t, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style )
:wxDialog( parent, id, title, pos, size, style )

{
	logbookPlugIn = d;
	timer = t;
	GPSTimer = NULL;

	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_logbook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	m_panel2 = new wxPanel( m_logbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer6->AddGrowableRow( 2 );
	fgSizer6->AddGrowableCol(0);

	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button4 = new wxButton( m_panel2, wxID_ANY, _("Add Line"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button4->SetToolTip( _("Add a line to the end of your logbook") );
	bSizer6->Add( m_button4, 0, wxALL, 5 );
	
	logSave = new wxButton( m_panel2, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	logSave->SetToolTip( _("export your logbook-data as:\nHTML, ODT,  ODS, XML, CSV") );
	bSizer6->Add( logSave, 0, wxALL, 5 );
	
	m_staticline8 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer6->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText32 = new wxStaticText( m_panel2, wxID_ANY, _("Select Layout: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer6->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString logbookChoiceChoices;
	logbookChoice = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), logbookChoiceChoices, 0 );
	logbookChoice->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	logbookChoice->SetSelection( 0 );
	bSizer6->Add( logbookChoice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayout = new wxButton( m_panel2, wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayout->SetToolTip( _("Reload Layouts") );
	
	bSizer6->Add( m_buttonReloadLayout, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayout = new wxButton( m_panel2, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayout->SetToolTip( _("Edit Layout") );
	
	bSizer6->Add( m_buttonEditLayout, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTML = new wxRadioButton( m_panel2, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_radioBtnHTML->SetValue( true ); 
	bSizer6->Add( m_radioBtnHTML, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODT = new wxRadioButton( m_panel2, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_radioBtnODT, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	logView = new wxButton( m_panel2, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	logView->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );
	bSizer6->Add( logView, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticline7 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer6->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );
	
	newLogbook = new wxButton( m_panel2, wxID_ANY, _("New Logbook"), wxDefaultPosition, wxDefaultSize, 0 );
	newLogbook->SetToolTip( _("Create a new logbook\nthe active logbook is saved with today's date\nand can be viewed with Button \"Select Logbook\"") );

	bSizer6->Add( newLogbook, 0, wxALL, 5 );
	
	selLogbook = new wxButton( m_panel2, wxID_ANY, _("Select Logbook"), wxDefaultPosition, wxDefaultSize, 0 );
	selLogbook->SetToolTip( _("Select a old logbook\nEverytime a new logbook is created, you'll \nfind the active logbook as old logbook here") );

	bSizer6->Add( selLogbook, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );
	
	fgSizer6->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer6->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_notebook8 = new wxNotebook( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel6 = new wxPanel( m_notebook8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer9->AddGrowableCol( 0 );
	fgSizer9->AddGrowableRow( 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer9->SetMinSize( wxSize( -1,400 ) ); 
	m_gridGlobal = new wxGrid( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB );
	
	// Grid
	m_gridGlobal->CreateGrid( 0, 14 );
	m_gridGlobal->EnableEditing( true );
	m_gridGlobal->EnableGridLines( true );
	m_gridGlobal->EnableDragGridSize( false );
	m_gridGlobal->SetMargins( 0, 0 );
	
	// Columns
	m_gridGlobal->SetColSize( 0, 144 );
	m_gridGlobal->SetColSize( 1, 68 );
	m_gridGlobal->SetColSize( 2, 63 );
	m_gridGlobal->SetColSize( 3, 34 );
	m_gridGlobal->SetColSize( 4, 157 );
	m_gridGlobal->SetColSize( 5, 58 );
	m_gridGlobal->SetColSize( 6, 86 );
	m_gridGlobal->SetColSize( 7, 143 );
	m_gridGlobal->SetColSize( 8, 54 );
	m_gridGlobal->SetColSize( 9, 50 );
	m_gridGlobal->SetColSize( 10, 55 );
	m_gridGlobal->SetColSize( 11, 57 );
	m_gridGlobal->SetColSize( 12, 62 );
	m_gridGlobal->SetColSize( 13, 248 );
	m_gridGlobal->EnableDragColMove( false );
	m_gridGlobal->EnableDragColSize( true );
	m_gridGlobal->SetColLabelSize( 30 );
	m_gridGlobal->SetColLabelValue( 0, _("Route") );
	m_gridGlobal->SetColLabelValue( 1, _("Date") );
	m_gridGlobal->SetColLabelValue( 2, _("Time") );
	m_gridGlobal->SetColLabelValue( 3, _("Sign") );
	m_gridGlobal->SetColLabelValue( 4, _("Watch") );
	m_gridGlobal->SetColLabelValue( 5, _("Distance") );
	m_gridGlobal->SetColLabelValue( 6, _("DistanceTotal") );
	m_gridGlobal->SetColLabelValue( 7, _("Position") );
	m_gridGlobal->SetColLabelValue( 8, _("COG (T)") );
	m_gridGlobal->SetColLabelValue( 9, _("Heading") );
	m_gridGlobal->SetColLabelValue( 10, _("SOG") );
	m_gridGlobal->SetColLabelValue( 11, _("STW") );
	m_gridGlobal->SetColLabelValue( 12, _("Depth") );
	m_gridGlobal->SetColLabelValue( 13, _("Remarks") );
	m_gridGlobal->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridGlobal->AutoSizeRows();
	m_gridGlobal->EnableDragRowSize( true );
	m_gridGlobal->SetRowLabelSize( 30 );
	m_gridGlobal->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridGlobal->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem41;
	m_menuItem41 = new wxMenuItem( m_menu1, 505, wxString( _("Timer ") ) , wxEmptyString, wxITEM_CHECK );
	m_menu1->Append( m_menuItem41 );
	m_menuItem41->Check( true );
	
	wxMenuItem* m_menuItemTimerInterval;
	m_menuItemTimerInterval = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Set Timer Interval") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemTimerInterval );

	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, 500, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem1 );

//	wxMenuItem* m_separator3;
//	m_separator3 = m_menu1->AppendSeparator();
	
	wxMenuItem* m_menuItem132;
	m_menuItem132 = new wxMenuItem( m_menu1, 503, wxString( _("Show hidden columns") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem132 );

	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Hide column") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem15 );

	wxMenuItem* m_menuItemSearch;
	m_menuItemSearch = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Search in Logbook") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemSearch );
	
	m_gridGlobal->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( LogbookDialog::m_gridGlobalOnContextMenu ), NULL, this ); 
	
	fgSizer9->Add( m_gridGlobal, 1, wxALL|wxEXPAND, 5 );
	
	m_panel6->SetSizer( fgSizer9 );
	m_panel6->Layout();
	fgSizer9->Fit( m_panel6 );
	m_notebook8->AddPage( m_panel6, _("Navigation"), true );
	m_panel7 = new wxPanel( m_notebook8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_gridWeather = new wxGrid( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB );
	
	// Grid
	m_gridWeather->CreateGrid( 0, 13 );
	m_gridWeather->EnableEditing( true );
	m_gridWeather->EnableGridLines( true );
	m_gridWeather->EnableDragGridSize( false );
	m_gridWeather->SetMargins( 0, 0 );
	
	// Columns
	m_gridWeather->SetColSize( 0, 69 );
	m_gridWeather->SetColSize( 1, 68 );
	m_gridWeather->SetColSize( 2, 74 );
	m_gridWeather->SetColSize( 3, 66 );
	m_gridWeather->SetColSize( 4, 81 );
	m_gridWeather->SetColSize( 5, 76 );
	m_gridWeather->SetColSize( 6, 63 );
	m_gridWeather->SetColSize( 7, 76 );
	m_gridWeather->SetColSize( 8, 175 );
	m_gridWeather->SetColSize( 9, 153 );
	m_gridWeather->EnableDragColMove( false );
	m_gridWeather->EnableDragColSize( true );
	m_gridWeather->SetColLabelSize( 30 );
	m_gridWeather->SetColLabelValue( 0, _("Barometer") );
	m_gridWeather->SetColLabelValue( 1, _("Hygrometer") );
	m_gridWeather->SetColLabelValue( 2, _("Air") );
	m_gridWeather->SetColLabelValue( 3, _("Water") );
	m_gridWeather->SetColLabelValue( 4, _("Wind") );
	m_gridWeather->SetColLabelValue( 5, _("W/Strength") );
	m_gridWeather->SetColLabelValue( 6, _("Current") );
	m_gridWeather->SetColLabelValue( 7, _("C/Strength") );
	m_gridWeather->SetColLabelValue( 8, _("Wave") );
	m_gridWeather->SetColLabelValue( 9, _("Swell") );
	m_gridWeather->SetColLabelValue( 10, _("Weather") );
	m_gridWeather->SetColLabelValue( 11, _("Clouds") );
	m_gridWeather->SetColLabelValue( 12, _("Visibility") );
	m_gridWeather->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridWeather->EnableDragRowSize( true );
	m_gridWeather->SetRowLabelSize( 30 );
	m_gridWeather->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridWeather->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	bSizer11->Add( m_gridWeather, 1, wxEXPAND|wxALL, 5 );
	
	m_panel7->SetSizer( bSizer11 );
	m_panel7->Layout();
	bSizer11->Fit( m_panel7 );
	m_notebook8->AddPage( m_panel7, _("Weather"), false );
	m_panel71 = new wxPanel( m_notebook8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );
	
	m_gridMotorSails = new wxGrid( m_panel71, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB );
	
	// Grid
	m_gridMotorSails->CreateGrid( 0, 20 );
	m_gridMotorSails->EnableEditing( true );
	m_gridMotorSails->EnableGridLines( true );
	m_gridMotorSails->EnableDragGridSize( false );
	m_gridMotorSails->SetMargins( 0, 0 );
	
	// Columns
	m_gridMotorSails->SetColSize( 0, 62 );
	m_gridMotorSails->SetColSize( 1, 76 );
	m_gridMotorSails->SetColSize( 2, 63 );
	m_gridMotorSails->SetColSize( 3, 76 );
	m_gridMotorSails->SetColSize( 4, 63 );
	m_gridMotorSails->SetColSize( 5, 70 );
	m_gridMotorSails->SetColSize( 6, 113 );
	m_gridMotorSails->SetColSize( 7, 67 );
	m_gridMotorSails->SetColSize( 8, 63 );
	m_gridMotorSails->SetColSize( 9, 66 );
	m_gridMotorSails->SetColSize( 10, 52 );
	m_gridMotorSails->SetColSize( 11, 75 );
	m_gridMotorSails->SetColSize( 12, 116 );
	m_gridMotorSails->SetColSize( 13, 62 );
	m_gridMotorSails->SetColSize( 14, 97 );
	m_gridMotorSails->SetColSize( 15, 75 );
	m_gridMotorSails->SetColSize( 16, 61 );
	m_gridMotorSails->SetColSize( 17, 56 );
	m_gridMotorSails->SetColSize( 18, 80 );
	m_gridMotorSails->SetColSize( 19, 298 );
	m_gridMotorSails->EnableDragColMove( false );
	m_gridMotorSails->EnableDragColSize( true );
	m_gridMotorSails->SetColLabelSize( 30 );
	m_gridMotorSails->SetColLabelValue( 0, _("Engine #1") );
	m_gridMotorSails->SetColLabelValue( 1, _("#1 Total") );
	m_gridMotorSails->SetColLabelValue( 2, _("Engine #2") );
	m_gridMotorSails->SetColLabelValue( 3, _("#2 Total") );
	m_gridMotorSails->SetColLabelValue( 4, _("Fuel") );
	m_gridMotorSails->SetColLabelValue( 5, _("FuelTotal") );
	m_gridMotorSails->SetColLabelValue( 6, _("Sails") );
	m_gridMotorSails->SetColLabelValue( 7, _("Reef") );
	m_gridMotorSails->SetColLabelValue( 8, _("Generator") );
	m_gridMotorSails->SetColLabelValue( 9, _("Gen. total") );
	m_gridMotorSails->SetColLabelValue( 10, _("Bank #1") );
	m_gridMotorSails->SetColLabelValue( 11, _("AH #1 Total") );
	m_gridMotorSails->SetColLabelValue( 12, _("Bank #2") );
	m_gridMotorSails->SetColLabelValue( 13, _("AH #2 Total") );
	m_gridMotorSails->SetColLabelValue( 14, _("Watermaker") );
	m_gridMotorSails->SetColLabelValue( 15, _("W-Total") );
	m_gridMotorSails->SetColLabelValue( 16, _("W-Output") );
	m_gridMotorSails->SetColLabelValue( 17, _("Water") );
	m_gridMotorSails->SetColLabelValue( 18, _("WaterTotal") );
	m_gridMotorSails->SetColLabelValue( 19, _("Remarks") );
	m_gridMotorSails->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridMotorSails->EnableDragRowSize( true );
	m_gridMotorSails->SetRowLabelSize( 30 );
	m_gridMotorSails->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridMotorSails->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	bSizer111->Add( m_gridMotorSails, 1, wxEXPAND|wxALL, 5 );
	
	m_panel71->SetSizer( bSizer111 );
	m_panel71->Layout();
	bSizer111->Fit( m_panel71 );
	m_notebook8->AddPage( m_panel71, _("Motor/Sails"), false );
	
	fgSizer6->Add( m_notebook8, 1, wxEXPAND | wxALL, 5 );
	
	m_panel2->SetSizer( fgSizer6 );
	m_panel2->Layout();
	fgSizer6->Fit( m_panel2 );
	m_logbook->AddPage( m_panel2, _("Logbook"), false );
	m_panel142 = new wxPanel( m_logbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer251;
	fgSizer251 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer251->AddGrowableCol( 0 );
	fgSizer251->AddGrowableRow( 2 );
	fgSizer251->SetFlexibleDirection( wxBOTH );
	fgSizer251->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer251->SetMinSize( wxSize( -1,400 ) ); 
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	logSaveOverview = new wxButton( m_panel142, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	logSaveOverview->SetToolTip( _("export your Overview-data as HTML or ODT") );
	bSizer61->Add( logSaveOverview, 0, wxALL, 5 );
	
	m_staticline81 = new wxStaticLine( m_panel142, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer61->Add( m_staticline81, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText323 = new wxStaticText( m_panel142, wxID_ANY, _("Select Layout: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	bSizer61->Add( m_staticText323, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString overviewChoiceChoices;
	overviewChoice = new wxChoice( m_panel142, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), overviewChoiceChoices, 0 );
	overviewChoice->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	overviewChoice->SetSelection( 0 );
	
	bSizer61->Add( overviewChoice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayoutOview = new wxButton( m_panel142, wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayoutOview->SetToolTip( _("Reload Layouts") );
	
	bSizer61->Add( m_buttonReloadLayoutOview, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutOview = new wxButton( m_panel142, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayoutOview->SetToolTip( _("Edit Layout") );
	
	bSizer61->Add( m_buttonEditLayoutOview, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLOverview = new wxRadioButton( m_panel142, wxID_ANY, _T("HTML"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_radioBtnHTMLOverview->SetValue( true ); 
	bSizer61->Add( m_radioBtnHTMLOverview, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTOverview = new wxRadioButton( m_panel142, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_radioBtnODTOverview, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	logViewOverview = new wxButton( m_panel142, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	logViewOverview->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );

	bSizer61->Add( logViewOverview, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticline71 = new wxStaticLine( m_panel142, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer61->Add( m_staticline71, 0, wxEXPAND | wxALL, 5 );

	m_radioBtnActuellLogbook = new wxRadioButton( m_panel142, wxID_ANY, _("Actuell Logbook"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_radioBtnActuellLogbook->SetValue( true ); 
	bSizer61->Add( m_radioBtnActuellLogbook, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnAllLogbooks = new wxRadioButton( m_panel142, wxID_ANY, _("All Logbooks"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_radioBtnAllLogbooks, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnSelectLogbook = new wxRadioButton( m_panel142, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_radioBtnSelectLogbook, 0, wxALL|wxEXPAND, 5 );

	m_buttonSelectLogbook = new wxButton( m_panel142, wxID_ANY, _("Select Logbook"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSelectLogbook->SetToolTip( _("Select one of the old logbooks") );
	bSizer61->Add( m_buttonSelectLogbook, 0, wxALL, 5 );
	
	bSizer51->Add( bSizer61, 1, wxEXPAND, 5 );
	
	fgSizer251->Add( bSizer51, 1, wxEXPAND, 5 );
	
	m_staticline11 = new wxStaticLine( m_panel142, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer251->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );
	
	m_gridOverview = new wxGrid( m_panel142, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridOverview->CreateGrid( 1, 33 );
	m_gridOverview->EnableEditing( false );
	m_gridOverview->EnableGridLines( true );
	m_gridOverview->EnableDragGridSize( false );
	m_gridOverview->SetMargins( 0, 0 );
	
	// Columns
	m_gridOverview->SetColSize( 0, 153 );
	m_gridOverview->SetColSize( 1, 144 );
	m_gridOverview->SetColSize( 2, 60 );
	m_gridOverview->SetColSize( 3, 60 );
	m_gridOverview->SetColSize( 4, 100 );
	m_gridOverview->SetColSize( 5, 73 );
	m_gridOverview->SetColSize( 6, 93 );
	m_gridOverview->SetColSize( 7, 96 );
	m_gridOverview->SetColSize( 8, 70 );
	m_gridOverview->SetColSize( 9, 80 );
	m_gridOverview->SetColSize( 10, 80 );
	m_gridOverview->SetColSize( 11, 80 );
	m_gridOverview->SetColSize( 12, 80 );
	m_gridOverview->SetColSize( 13, 114 );
	m_gridOverview->SetColSize( 14, 108 );
	m_gridOverview->SetColSize( 15, 93 );
	m_gridOverview->SetColSize( 16, 129 );
	m_gridOverview->SetColSize( 17, 80 );
	m_gridOverview->SetColSize( 18, 80 );
	m_gridOverview->SetColSize( 19, 100 );
	m_gridOverview->SetColSize( 20, 80 );
	m_gridOverview->SetColSize( 21, 108 );
	m_gridOverview->SetColSize( 22, 80 );
	m_gridOverview->SetColSize( 23, 80 );
	m_gridOverview->SetColSize( 24, 123 );
	m_gridOverview->SetColSize( 25, 80 );
	m_gridOverview->SetColSize( 26, 80 );
	m_gridOverview->SetColSize( 27, 80 );
	m_gridOverview->SetColSize( 28, 80 );
	m_gridOverview->SetColSize( 29, 80 );
	m_gridOverview->SetColSize( 30, 80 );
	m_gridOverview->SetColSize( 31, 110 );
	m_gridOverview->SetColSize( 32, 80 );
	m_gridOverview->EnableDragColMove( false );
	m_gridOverview->EnableDragColSize( true );
	m_gridOverview->SetColLabelSize( 30 );
	m_gridOverview->SetColLabelValue( 0, _("Logbook") );
	m_gridOverview->SetColLabelValue( 1, _("Route") );
	m_gridOverview->SetColLabelValue( 2, _("Start") );
	m_gridOverview->SetColLabelValue( 3, _("End") );
	m_gridOverview->SetColLabelValue( 4, _("Total Time") );
	m_gridOverview->SetColLabelValue( 5, _("Distance") );
	m_gridOverview->SetColLabelValue( 6, _("Distance p. Day") );
	m_gridOverview->SetColLabelValue( 7, _("Best Dist. p. Day") );
	m_gridOverview->SetColLabelValue( 8, _("Speed Avg.") );
	m_gridOverview->SetColLabelValue( 9, _("Speed Max.") );
	m_gridOverview->SetColLabelValue( 10, _("Engine #1") );
	m_gridOverview->SetColLabelValue( 11, _("Engine #2") );
	m_gridOverview->SetColLabelValue( 12, _("Fuel") );
	m_gridOverview->SetColLabelValue( 13, _("Generator") );
	m_gridOverview->SetColLabelValue( 14, _("Bank #1 gen.") );
	m_gridOverview->SetColLabelValue( 15, _("Bank #1 used") );
	m_gridOverview->SetColLabelValue( 16, _("Bank #2 gen.") );
	m_gridOverview->SetColLabelValue( 17, _("Bank #2 used") );
	m_gridOverview->SetColLabelValue( 18, _("Watermaker") );
	m_gridOverview->SetColLabelValue( 19, _("Waterm. Outp") );
	m_gridOverview->SetColLabelValue( 20, _("Water used") );
	m_gridOverview->SetColLabelValue( 21, _("Winddirection Avg.") );
	m_gridOverview->SetColLabelValue( 22, _("Wind Avg.") );
	m_gridOverview->SetColLabelValue( 23, _("Wind Max.") );
	m_gridOverview->SetColLabelValue( 24, _("Currentdirection Avg.") );
	m_gridOverview->SetColLabelValue( 25, _("Current Avg.") );
	m_gridOverview->SetColLabelValue( 26, _("Current Max.") );
	m_gridOverview->SetColLabelValue( 27, _("Wave Avg.") );
	m_gridOverview->SetColLabelValue( 28, _("Wave Max.") );
	m_gridOverview->SetColLabelValue( 29, _("Swell Avg.") );
	m_gridOverview->SetColLabelValue( 30, _("Swell Max.") );
	m_gridOverview->SetColLabelValue( 31, _("Sails used mostly") );
	m_gridOverview->SetColLabelValue( 32, _("Path") );
	m_gridOverview->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridOverview->EnableDragRowSize( true );
	m_gridOverview->SetRowLabelSize( 30 );
	m_gridOverview->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridOverview->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	m_gridOverview->SetMinSize( wxSize( -1,400 ) );
	
	m_menuOverView = new wxMenu();
	wxMenuItem* m_menuItemOverviewRoute;
	m_menuItemOverviewRoute = new wxMenuItem( m_menuOverView, wxID_ANY, wxString( _("Goto Route") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuOverView->Append( m_menuItemOverviewRoute );

//	wxMenuItem* m_separator4;
//	m_separator4 = m_menuOverView->AppendSeparator();
	
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( m_menuOverView, wxID_ANY, wxString( _("Show hidden columns") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuOverView->Append( m_menuItem14 );

	wxMenuItem* m_menuItem16;
	m_menuItem16 = new wxMenuItem( m_menuOverView, wxID_ANY, wxString( _("Hide column") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuOverView->Append( m_menuItem16 );
	
	fgSizer251->Add( m_gridOverview, 1, wxALL|wxEXPAND, 5 );
	
	m_panel142->SetSizer( fgSizer251 );
	m_panel142->Layout();
	fgSizer251->Fit( m_panel142 );
	m_logbook->AddPage( m_panel142, _("Overview"), true );
	m_panel21 = new wxPanel( m_logbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer7->AddGrowableCol( 0 );
	fgSizer7->AddGrowableRow( 1 );
	fgSizer7->AddGrowableRow( 2 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	crewAdd = new wxButton( m_panel21, wxID_ANY, _("Add Crew"), wxDefaultPosition, wxDefaultSize, 0 );
	crewAdd->SetToolTip( _("Add a new Crewmember") );
	bSizer3->Add( crewAdd, 0, wxALL, 5 );
	
	crewSave = new wxButton( m_panel21, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	crewSave->SetToolTip( _("export your crew-data as:\nHTML, ODT,  ODS, XML, CSV") );
	bSizer3->Add( crewSave, 0, wxALL, 5 );
	
	m_staticline5 = new wxStaticLine( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer3->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText321 = new wxStaticText( m_panel21, wxID_ANY, _("Select Layout: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer3->Add( m_staticText321, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString crewChoiceChoices;
	crewChoice = new wxChoice( m_panel21, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), crewChoiceChoices, 0 );
	crewChoice->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	crewChoice->SetSelection( 0 );
	bSizer3->Add( crewChoice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonReloadCrew = new wxButton( m_panel21, wxID_ANY, _("R"),wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadCrew->SetToolTip( _("Reload Layouts") );
	
	bSizer3->Add( m_buttonReloadCrew, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutCrew = new wxButton( m_panel21, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayoutCrew->SetToolTip( _("Edit Layout") );
	
	bSizer3->Add( m_buttonEditLayoutCrew, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLCrew = new wxRadioButton( m_panel21, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnHTMLCrew->SetValue( true ); 
	bSizer3->Add( m_radioBtnHTMLCrew, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTCrew = new wxRadioButton( m_panel21, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_radioBtnODTCrew, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	crewView = new wxButton( m_panel21, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	crewView->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );

	bSizer3->Add( crewView, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer7->Add( bSizer3, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer7->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	fgSizer7->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel21, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	sbSizer1->SetMinSize( wxSize( -1,450 ) ); 
	m_gridCrew = new wxGrid( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridCrew->CreateGrid( 0, 15 );
	m_gridCrew->EnableEditing( true );
	m_gridCrew->EnableGridLines( true );
	m_gridCrew->EnableDragGridSize( false );
	m_gridCrew->SetMargins( 0, 0 );
	
	// Columns
	m_gridCrew->SetColSize( 0, 60 );
	m_gridCrew->SetColSize( 1, 154 );
	m_gridCrew->SetColSize( 2, 139 );
	m_gridCrew->SetColSize( 3, 140 );
	m_gridCrew->SetColSize( 4, 50 );
	m_gridCrew->SetColSize( 5, 78 );
	m_gridCrew->SetColSize( 6, 127 );
	m_gridCrew->SetColSize( 7, 116 );
	m_gridCrew->SetColSize( 8, 118 );
	m_gridCrew->SetColSize( 9, 147 );
	m_gridCrew->SetColSize( 10, 110 );
	m_gridCrew->SetColSize( 11, 82 );
	m_gridCrew->SetColSize( 12, 155 );
	m_gridCrew->SetColSize( 13, 261 );
	m_gridCrew->SetColSize( 14, 243 );
	m_gridCrew->EnableDragColMove( false );
	m_gridCrew->EnableDragColSize( true );
	m_gridCrew->SetColLabelSize( 30 );
	m_gridCrew->SetColLabelValue( 0, _("Onboard") );
	m_gridCrew->SetColLabelValue( 1, _("Name") );
	m_gridCrew->SetColLabelValue( 2, _("Birthname") );
	m_gridCrew->SetColLabelValue( 3, _("Firstname") );
	m_gridCrew->SetColLabelValue( 4, _("Title") );
	m_gridCrew->SetColLabelValue( 5, _("Date of Birth") );
	m_gridCrew->SetColLabelValue( 6, _("Place of Birth") );
	m_gridCrew->SetColLabelValue( 7, _("Nationality") );
	m_gridCrew->SetColLabelValue( 8, _("Passport-Nr") );
	m_gridCrew->SetColLabelValue( 9, _("Issued in") );
	m_gridCrew->SetColLabelValue( 10, _("Date of Issue") );
	m_gridCrew->SetColLabelValue( 11, _("Zip") );
	m_gridCrew->SetColLabelValue( 12, _("Country") );
	m_gridCrew->SetColLabelValue( 13, _("Town") );
	m_gridCrew->SetColLabelValue( 14, _("Street") );
	m_gridCrew->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridCrew->EnableDragRowSize( true );
	m_gridCrew->SetRowLabelSize( 30 );
	m_gridCrew->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridCrew->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_menu2 = new wxMenu();

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem2 );
	
	wxMenuItem* m_menuItemAddWake;
	m_menuItemAddWake = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Add to Watchlist") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemAddWake );	
	sbSizer1->Add( m_gridCrew, 1, wxALL|wxEXPAND, 5 );

	wxMenuItem* m_menuItemSameWatch;
	m_menuItemSameWatch = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Add to Watchlist same as") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemSameWatch );
	
	wxMenuItem* m_menuItem22;
	m_menuItem22 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Show hidden columns") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem22 );

	m_menu2->AppendSeparator();
	
	wxMenuItem* m_menuItem30;
	m_menuItem30 = new wxMenuItem( m_menu2, MENUCREWONBOARD, wxString( _("Show onboard only") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem30 );
	m_menuItem30->Check( true );
	
	wxMenuItem* m_menuItem31;
	m_menuItem31 = new wxMenuItem( m_menu2, MENUCREWALL, wxString( _("Show all crew-entries") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem31 );

	m_menu2->AppendSeparator();

	wxMenuItem* m_menuItem32;
	m_menuItem32 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Sort ascending") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem32 );
	
	wxMenuItem* m_menuItem33;
	m_menuItem33 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Sort descending") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem33 );

	m_gridCrewWake = new wxGrid( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridCrewWake->CreateGrid( 0, 14 );
	m_gridCrewWake->EnableEditing( true );
	m_gridCrewWake->EnableGridLines( true );
	m_gridCrewWake->EnableDragGridSize( false );
	m_gridCrewWake->SetMargins( 0, 0 );
	
	// Columns
	m_gridCrewWake->SetColSize( 0, 158 );
	m_gridCrewWake->SetColSize( 1, 157 );
	m_gridCrewWake->SetColSize( 2, 80 );
	m_gridCrewWake->SetColSize( 3, 80 );
	m_gridCrewWake->SetColSize( 4, 80 );
	m_gridCrewWake->SetColSize( 5, 80 );
	m_gridCrewWake->SetColSize( 6, 80 );
	m_gridCrewWake->SetColSize( 7, 80 );
	m_gridCrewWake->EnableDragColMove( false );
	m_gridCrewWake->EnableDragColSize( true );
	m_gridCrewWake->SetColLabelSize( 30 );
	m_gridCrewWake->SetColLabelValue( 0, _("Name") );
	m_gridCrewWake->SetColLabelValue( 1, _("Firstname") );
	m_gridCrewWake->SetColLabelValue( 2, _("Start 1.Watch") );
	m_gridCrewWake->SetColLabelValue( 3, _("End 1.Watch") );
	m_gridCrewWake->SetColLabelValue( 4, _("Start 2.Watch") );
	m_gridCrewWake->SetColLabelValue( 5, _("End 2.Watch") );
	m_gridCrewWake->SetColLabelValue( 6, _("Start 3.Watch") );
	m_gridCrewWake->SetColLabelValue( 7, _("End 3.Watch") );
	m_gridCrewWake->SetColLabelValue( 8, _("Start 4.Watch") );
	m_gridCrewWake->SetColLabelValue( 9, _("End 4.Watch") );
	m_gridCrewWake->SetColLabelValue( 10, _("Start 5.Watch") );
	m_gridCrewWake->SetColLabelValue( 11, _("End 5.Watch") );
	m_gridCrewWake->SetColLabelValue( 12, _("Start 6.Watch") );
	m_gridCrewWake->SetColLabelValue( 13, _("End 6.Watch") );
	m_gridCrewWake->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridCrewWake->EnableDragRowSize( true );
	m_gridCrewWake->SetRowLabelSize( 30 );
	m_gridCrewWake->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridCrewWake->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	
	m_menu21 = new wxMenu();
	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( m_menu21, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem21 );
	
	wxMenuItem* m_menuItem19;
	m_menuItem19 = new wxMenuItem( m_menu21, wxID_ANY, wxString( _("Set Watches") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem19 );	
	sbSizer1->Add( m_gridCrewWake, 1, wxALL|wxEXPAND, 5 );
	
	wxMenuItem* m_menuItem23;
	m_menuItem23 = new wxMenuItem( m_menu21, wxID_ANY, wxString( _("Show hidden columns") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem23 );

	fgSizer7->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	m_panel21->SetSizer( fgSizer7 );
	m_panel21->Layout();
	fgSizer7->Fit( m_panel21 );
	m_logbook->AddPage( m_panel21, _("Crewlist"), false );
	m_panel3 = new wxPanel( m_logbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer1->AddGrowableCol( 0 );
	fgSizer1->AddGrowableRow( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	addEquipmentButton = new wxButton( m_panel3, wxID_ANY, _("Add Equipment"), wxDefaultPosition, wxDefaultSize, 0 );
	addEquipmentButton->SetToolTip( _("add the equipment of your boat") );
	bSizer10->Add( addEquipmentButton, 0, wxALL, 5 );

	m_toggleBtnShowEquipment = new wxToggleButton( m_panel3, wxID_ANY, _("Show Equipment"), wxDefaultPosition, wxSize( 120,-1 ), 0 );
	m_toggleBtnShowEquipment->SetToolTip( _("Show/Hide Equipmentgrid") );
	bSizer10->Add( m_toggleBtnShowEquipment, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticline27 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer10->Add( m_staticline27, 0, wxEXPAND | wxALL, 5 );
	
	boatSave = new wxButton( m_panel3, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	boatSave->SetToolTip( _("export your boat/equipment-data as:\n      HTML, ODT,  ODS, XML, CSV") );

	bSizer10->Add( boatSave, 0, wxALL, 5 );
	
	m_staticline4 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer10->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText322 = new wxStaticText( m_panel3, wxID_ANY, _("Select Layout: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	bSizer10->Add( m_staticText322, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString boatChoiceChoices;
	boatChoice = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), boatChoiceChoices, 0 );
	boatChoice->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	boatChoice->SetSelection( 0 );
	bSizer10->Add( boatChoice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayoutsBoat = new wxButton( m_panel3, wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayoutsBoat->SetToolTip( _("Reload Layouts") );
	
	bSizer10->Add( m_buttonReloadLayoutsBoat, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutBoat = new wxButton( m_panel3, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize,wxBU_EXACTFIT );
	m_buttonEditLayoutBoat->SetToolTip( _("Edit Layouts") );
	
	bSizer10->Add( m_buttonEditLayoutBoat, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLBoat = new wxRadioButton( m_panel3, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnHTMLBoat->SetValue( true ); 
	bSizer10->Add( m_radioBtnHTMLBoat, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTBoat = new wxRadioButton( m_panel3, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_radioBtnODTBoat, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	boatView = new wxButton( m_panel3, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	boatView->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );

	bSizer10->Add( boatView, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	fgSizer1->Add( bSizer9, 1, wxEXPAND, 5 );
	
	m_splitter1 = new wxSplitterWindow( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( LogbookDialog::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 15 );
	
	m_panel72 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer34;
	fgSizer34 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer34->SetFlexibleDirection( wxBOTH );
	fgSizer34->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel72, wxID_ANY, _("Boat") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer38;
	fgSizer38 = new wxFlexGridSizer( 1, 12, 0, 0 );
	fgSizer38->SetFlexibleDirection( wxBOTH );
	fgSizer38->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bname = new wxStaticText( m_panel72, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	bname->Wrap( -1 );
	fgSizer38->Add( bname, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	boatName = new wxTextCtrl( m_panel72, 1, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer38->Add( boatName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText114 = new wxStaticText( m_panel72, wxID_ANY, _("Homeport"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	fgSizer38->Add( m_staticText114, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	homeport = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer38->Add( homeport, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText115 = new wxStaticText( m_panel72, wxID_ANY, _("Callsign"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	fgSizer38->Add( m_staticText115, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	callsign = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( callsign, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText116 = new wxStaticText( m_panel72, wxID_ANY, _("HIN-Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText116->Wrap( -1 );
	fgSizer38->Add( m_staticText116, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	hin = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	hin->SetToolTip( _("Hull Identification No.") );
	fgSizer38->Add( hin, 0, wxALL, 5 );
	
	m_staticText117 = new wxStaticText( m_panel72, wxID_ANY, _("Sail-Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText117->Wrap( -1 );
	fgSizer38->Add( m_staticText117, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sailno = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( sailno, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText119 = new wxStaticText( m_panel72, wxID_ANY, _("Insurance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText119->Wrap( -1 );
	fgSizer38->Add( m_staticText119, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	insurance = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer38->Add( insurance, 0, wxALL, 5 );
	
	m_staticText118 = new wxStaticText( m_panel72, wxID_ANY, _("Registration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText118->Wrap( -1 );
	fgSizer38->Add( m_staticText118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	registration = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer38->Add( registration, 0, wxALL, 5 );
	
	m_staticText120 = new wxStaticText( m_panel72, wxID_ANY, _("Policy"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText120->Wrap( -1 );
	fgSizer38->Add( m_staticText120, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	policy = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( policy, 0, wxALL, 5 );
	
	m_staticText53 = new wxStaticText( m_panel72, wxID_ANY, _("MMSI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	fgSizer38->Add( m_staticText53, 0, wxALL, 5 );
	
	mmsi = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( mmsi, 0, wxALL, 5 );
	
	sbSizer11->Add( fgSizer38, 1, wxEXPAND, 5 );
	
	fgSizer34->Add( sbSizer11, 1, wxEXPAND, 5 );
	
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel72, wxID_ANY, _("Owner") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer39;
	fgSizer39 = new wxFlexGridSizer( 2, 10, 0, 0 );
	fgSizer39->SetFlexibleDirection( wxBOTH );
	fgSizer39->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText90 = new wxStaticText( m_panel72, wxID_ANY, _("Name      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	fgSizer39->Add( m_staticText90, 0, wxALL, 5 );
	
	ownerName = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer39->Add( ownerName, 0, wxALL, 5 );
	
	m_staticText91 = new wxStaticText( m_panel72, wxID_ANY, _("Firstname"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer39->Add( m_staticText91, 0, wxALL, 5 );
	
	ownerFirstname = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer39->Add( ownerFirstname, 0, wxALL, 5 );
	
	m_staticText95 = new wxStaticText( m_panel72, wxID_ANY, _("Telephone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	fgSizer39->Add( m_staticText95, 0, wxALL, 5 );
	
	ownerPhone = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer39->Add( ownerPhone, 0, wxALL, 5 );
	
	
	fgSizer39->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer39->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer39->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer39->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText92 = new wxStaticText( m_panel72, wxID_ANY, _("Street"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	fgSizer39->Add( m_staticText92, 0, wxALL, 5 );
	
	ownerStreet = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer39->Add( ownerStreet, 0, wxALL, 5 );
	
	m_staticText93 = new wxStaticText( m_panel72, wxID_ANY, _("Zip"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	fgSizer39->Add( m_staticText93, 0, wxALL, 5 );
	
	owenerZip = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer39->Add( owenerZip, 0, wxALL, 5 );
	
	m_staticText94 = new wxStaticText( m_panel72, wxID_ANY, _("Town"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	fgSizer39->Add( m_staticText94, 0, wxALL, 5 );
	
	ownerTown = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer39->Add( ownerTown, 0, wxALL, 5 );
	
	sbSizer6->Add( fgSizer39, 1, wxEXPAND, 5 );
	
	fgSizer34->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel72, wxID_ANY, _("Details") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer33;
	fgSizer33 = new wxFlexGridSizer( 1, 10, 0, 0 );
	fgSizer33->SetFlexibleDirection( wxBOTH );
	fgSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText128 = new wxStaticText( m_panel72, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText128->Wrap( -1 );
	fgSizer33->Add( m_staticText128, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	boatType = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer33->Add( boatType, 0, wxALL, 5 );
	
	m_staticText125 = new wxStaticText( m_panel72, wxID_ANY, _("Builder"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText125->Wrap( -1 );
	fgSizer33->Add( m_staticText125, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	builder = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer33->Add( builder, 0, wxALL, 5 );
	
	m_staticText124 = new wxStaticText( m_panel72, wxID_ANY, _("Hull"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText124->Wrap( -1 );
	fgSizer33->Add( m_staticText124, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	hull = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( hull, 0, wxALL, 5 );
	
	m_staticText126 = new wxStaticText( m_panel72, wxID_ANY, _("Date Launched"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText126->Wrap( -1 );
	fgSizer33->Add( m_staticText126, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	dateLaunched = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( dateLaunched, 0, wxALL, 5 );
	
	m_staticText127 = new wxStaticText( m_panel72, wxID_ANY, _("Yard-Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText127->Wrap( -1 );
	fgSizer33->Add( m_staticText127, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	yardNr = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( yardNr, 0, wxALL, 5 );
	
	m_staticText123 = new wxStaticText( m_panel72, wxID_ANY, _("Designer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText123->Wrap( -1 );
	fgSizer33->Add( m_staticText123, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	designer = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer33->Add( designer, 0, wxALL, 5 );
	
	m_staticText129 = new wxStaticText( m_panel72, wxID_ANY, _("Construction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText129->Wrap( -1 );
	fgSizer33->Add( m_staticText129, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	construction = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer33->Add( construction, 0, wxALL, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText106 = new wxStaticText( m_panel72, wxID_ANY, _("LOA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	fgSizer33->Add( m_staticText106, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	LOA = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	LOA->SetToolTip( _("Length over all") );
	
	fgSizer33->Add( LOA, 0, wxALL, 5 );
	
	m_staticText107 = new wxStaticText( m_panel72, wxID_ANY, _("LOD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText107->Wrap( -1 );
	fgSizer33->Add( m_staticText107, 0, wxALL, 5 );
	
	LOD = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	LOD->SetToolTip( _("Length over Deck") );
	
	fgSizer33->Add( LOD, 0, wxALL, 5 );
	
	m_staticText108 = new wxStaticText( m_panel72, wxID_ANY, _("LWL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	fgSizer33->Add( m_staticText108, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	LWL = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	LWL->SetToolTip( _("Length in Waterline") );
	
	fgSizer33->Add( LWL, 0, wxALL, 5 );
	
	m_staticText109 = new wxStaticText( m_panel72, wxID_ANY, _("Beam"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	fgSizer33->Add( m_staticText109, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	beam = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	beam->SetToolTip( _("Greatest Width of Hull") );
	
	fgSizer33->Add( beam, 0, wxALL, 5 );
	
	m_staticText110 = new wxStaticText( m_panel72, wxID_ANY, _("Draft"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	fgSizer33->Add( m_staticText110, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	draft = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	fgSizer33->Add( draft, 0, wxALL, 5 );
	
	UserLabel1 = new wxTextCtrl( m_panel72, wxID_ANY, _("UserLabel"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	UserLabel1->SetToolTip( _("write your own label") );
	
	fgSizer33->Add( UserLabel1, 0, wxALL, 5 );
	
	Userfield1 = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( Userfield1, 0, wxALL, 5 );
	
	UserLabel2 = new wxTextCtrl( m_panel72, wxID_ANY, _("UserLabel"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	UserLabel2->SetToolTip( _("write your own label") );
	
	fgSizer33->Add( UserLabel2, 0, wxALL, 5 );
	
	Userfield2 = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( Userfield2, 0, wxALL, 5 );
	
	UserLabel3 = new wxTextCtrl( m_panel72, wxID_ANY, _("UserLabel"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	UserLabel3->SetToolTip( _("write your own label") );
	UserLabel3->SetMaxSize( wxSize( 30,-1 ) );
	
	fgSizer33->Add( UserLabel3, 0, wxALL, 5 );
	
	Userfield3 = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	fgSizer33->Add( Userfield3, 0, wxALL, 5 );
	
	m_staticText122 = new wxStaticText( m_panel72, wxID_ANY, _("Displacement"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText122->Wrap( -1 );
	fgSizer33->Add( m_staticText122, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	displacement = new wxTextCtrl( m_panel72, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	fgSizer33->Add( displacement, 0, wxALL, 5 );
	
	sbSizer8->Add( fgSizer33, 1, wxEXPAND, 5 );
	
	fgSizer34->Add( sbSizer8, 1, wxEXPAND, 5 );
	
	m_panel72->SetSizer( fgSizer34 );
	m_panel72->Layout();
	fgSizer34->Fit( m_panel72 );
	m_panel8 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );

	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, _("Equipment") ), wxVERTICAL );

	sbSizer12->SetMinSize( wxSize( -1,-1 ) ); 

	m_gridEquipment = new wxGrid( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridEquipment->CreateGrid( 0, 4 );
	m_gridEquipment->EnableEditing( true );
	m_gridEquipment->EnableGridLines( true );
	m_gridEquipment->EnableDragGridSize( false );
	m_gridEquipment->SetMargins( 0, 0 );
	
	// Columns
	m_gridEquipment->SetColSize( 0, 120 );
	m_gridEquipment->SetColSize( 1, 296 );
	m_gridEquipment->SetColSize( 2, 151 );
	m_gridEquipment->SetColSize( 3, 297 );
	m_gridEquipment->EnableDragColMove( false );
	m_gridEquipment->EnableDragColSize( true );
	m_gridEquipment->SetColLabelSize( 30 );
	m_gridEquipment->SetColLabelValue( 0, _("Type") );
	m_gridEquipment->SetColLabelValue( 1, _("Description") );
	m_gridEquipment->SetColLabelValue( 2, _("Serial-Nr.") );
	m_gridEquipment->SetColLabelValue( 3, _("Remarks") );
	m_gridEquipment->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridEquipment->EnableDragRowSize( true );
	m_gridEquipment->SetRowLabelSize( 30 );
	m_gridEquipment->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridEquipment->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem3 );
	
	
	sbSizer12->Add( m_gridEquipment, 1, wxALL|wxEXPAND, 5 );
	
	m_panel8->SetSizer( sbSizer12 );
	m_panel8->Layout();
	sbSizer12->Fit( m_panel8 );
	
	m_splitter1->SplitHorizontally( m_panel72, m_panel8, 315 );

	fgSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	m_panel3->SetSizer( fgSizer1 );
	m_panel3->Layout();
	fgSizer1->Fit( m_panel3 );
	m_logbook->AddPage( m_panel3, _("Boat"), false );
	m_panel13 = new wxPanel( m_logbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook6 = new wxNotebook( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel14 = new wxPanel( m_notebook6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer151;
	fgSizer151 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer151->AddGrowableCol( 0 );
	fgSizer151->AddGrowableRow( 2 );
	fgSizer151->SetFlexibleDirection( wxBOTH );
	fgSizer151->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer1011;
	bSizer1011 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAddLineService = new wxButton( m_panel14, wxID_ANY, _("Add Line"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddLineService->SetToolTip( _("Add a new line") );
	bSizer1011->Add( m_buttonAddLineService, 0, wxALL, 5 );
	
	m_buttonSaveService = new wxButton( m_panel14, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSaveService->SetToolTip( _("export your Service-data as HTML or ODT") );	
	bSizer1011->Add( m_buttonSaveService, 0, wxALL, 5 );
	
	m_staticline151 = new wxStaticLine( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer1011->Add( m_staticline151, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText621 = new wxStaticText( m_panel14, wxID_ANY, _("Select Layout:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText621->Wrap( -1 );
	bSizer1011->Add( m_staticText621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceSelectLayoutServiceChoices;
	m_choiceSelectLayoutService = new wxChoice( m_panel14, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), m_choiceSelectLayoutServiceChoices, 0 );
	m_choiceSelectLayoutService->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	m_choiceSelectLayoutService->SetSelection( 0 );
	bSizer1011->Add( m_choiceSelectLayoutService, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayoutsServiceHTML = new wxButton( m_panel14, wxID_ANY, _("R"),wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayoutsServiceHTML->SetToolTip( _("Reload Layouts") );
	
	bSizer1011->Add( m_buttonReloadLayoutsServiceHTML, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutODTService = new wxButton( m_panel14, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayoutODTService->SetToolTip( _("Edit Layout") );
	
	bSizer1011->Add( m_buttonEditLayoutODTService, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLService = new wxRadioButton( m_panel14, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnHTMLService->SetValue( true ); 
	bSizer1011->Add( m_radioBtnHTMLService, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTService = new wxRadioButton( m_panel14, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1011->Add( m_radioBtnODTService, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonViewService = new wxButton( m_panel14, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonViewService->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );
	bSizer1011->Add( m_buttonViewService, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1011->Add( 300, 0, 1, wxEXPAND, 5 );
	
	fgSizer151->Add( bSizer1011, 1, wxEXPAND, 5 );
	
	m_staticline141 = new wxStaticLine( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer151->Add( m_staticline141, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	bSizer12->SetMinSize( wxSize( -1,400 ) ); 
	m_gridMaintanence = new EzGrid( m_panel14, wxID_ANY, wxDefaultPosition, wxSize(1000,400), 0 );
	
	// Grid
	m_gridMaintanence->CreateGrid( 0, 7 );
	m_gridMaintanence->EnableEditing( true );
	m_gridMaintanence->EnableGridLines( true );
	m_gridMaintanence->EnableDragGridSize( false );
	m_gridMaintanence->SetMargins( 0, 0 );
	
	// Columns
	m_gridMaintanence->SetColSize( 0, 50 );
	m_gridMaintanence->SetColSize( 1, 400 );
	m_gridMaintanence->SetColSize( 2, 100 );
	m_gridMaintanence->SetColSize( 3, 100 );
	m_gridMaintanence->SetColSize( 4, 80 );
	m_gridMaintanence->SetColSize( 5, 80 );
	m_gridMaintanence->EnableDragColMove( false );
	m_gridMaintanence->EnableDragColSize( true );
	m_gridMaintanence->SetColLabelSize( 30 );
	m_gridMaintanence->SetColLabelValue( 0, _("Priority") );
	m_gridMaintanence->SetColLabelValue( 1, _("Service TODO") );
	m_gridMaintanence->SetColLabelValue( 2, _("If") );
	m_gridMaintanence->SetColLabelValue( 3, _("Warnvalue") );
	m_gridMaintanence->SetColLabelValue( 4, _("Urgentvalue") );
	m_gridMaintanence->SetColLabelValue( 5, _("Startvalue") );
	m_gridMaintanence->SetColLabelValue( 6, _("Active") );
	m_gridMaintanence->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridMaintanence->AutoSizeRows();
	m_gridMaintanence->EnableDragRowSize( true );
	m_gridMaintanence->SetRowLabelSize( 30 );
	m_gridMaintanence->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	m_gridMaintanence->SetLabelTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	// Cell Defaults
	m_gridMaintanence->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	m_menu7 = new wxMenu();
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Service done") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem9 );
	
	wxMenuItem* m_menuItem92;
	m_menuItem92 = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Buy parts for this service") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem92 );
	
//	wxMenuItem* m_separator1;
//	m_separator1 = m_menu7->AppendSeparator();
	
	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem13 );
	
	
	bSizer12->Add( m_gridMaintanence, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	fgSizer151->Add( bSizer12, 1, wxEXPAND, 5 );
	
	m_panel14->SetSizer( fgSizer151 );
	m_panel14->Layout();
	fgSizer151->Fit( m_panel14 );
	m_notebook6->AddPage( m_panel14, _("Service"), true );
	m_panel141 = new wxPanel( m_notebook6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1513;
	fgSizer1513 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer1513->AddGrowableCol( 0 );
	fgSizer1513->AddGrowableRow( 2 );
	fgSizer1513->SetFlexibleDirection( wxBOTH );
	fgSizer1513->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer10113;
	bSizer10113 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAddLineRepairs = new wxButton( m_panel141, wxID_ANY, _("Add Line"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddLineRepairs->SetToolTip( _("Add a new line") );
	bSizer10113->Add( m_buttonAddLineRepairs, 0, wxALL, 5 );
	
	m_buttonSaveRepairs = new wxButton( m_panel141, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSaveRepairs->SetToolTip( _("export your Repairs-data as HTML or ODT") );	
	bSizer10113->Add( m_buttonSaveRepairs, 0, wxALL, 5 );
	
	m_staticline1513 = new wxStaticLine( m_panel141, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer10113->Add( m_staticline1513, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText6213 = new wxStaticText( m_panel141, wxID_ANY, _("Select Layout:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6213->Wrap( -1 );
	bSizer10113->Add( m_staticText6213, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceSelectLayoutRepairsChoices;
	m_choiceSelectLayoutRepairs = new wxChoice( m_panel141, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), m_choiceSelectLayoutRepairsChoices, 0 );
	m_choiceSelectLayoutRepairs->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	m_choiceSelectLayoutRepairs->SetSelection( 0 );
	bSizer10113->Add( m_choiceSelectLayoutRepairs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayoutsRepairsHTML = new wxButton( m_panel141, wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayoutsRepairsHTML->SetToolTip( _("Reload Layouts") );
	
	bSizer10113->Add( m_buttonReloadLayoutsRepairsHTML, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutODTRepairs = new wxButton( m_panel141, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayoutODTRepairs->SetToolTip( _("Edit Layout") );
	
	bSizer10113->Add( m_buttonEditLayoutODTRepairs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLRepairs = new wxRadioButton( m_panel141, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnHTMLRepairs->SetValue( true ); 
	bSizer10113->Add( m_radioBtnHTMLRepairs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTRepairs = new wxRadioButton( m_panel141, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10113->Add( m_radioBtnODTRepairs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonViewRepairs = new wxButton( m_panel141, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonViewRepairs->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );
	bSizer10113->Add( m_buttonViewRepairs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10113->Add( 300, 0, 1, wxEXPAND, 5 );
	
	fgSizer1513->Add( bSizer10113, 1, wxEXPAND, 5 );
	
	m_staticline1413 = new wxStaticLine( m_panel141, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1513->Add( m_staticline1413, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxVERTICAL );
	
	bSizer122->SetMinSize( wxSize( -1,400 ) ); 
	m_gridMaintanenceRepairs = new EzGrid( m_panel141, wxID_ANY, wxDefaultPosition, wxSize( 1000,400 ), 0 );
	
	// Grid
	m_gridMaintanenceRepairs->CreateGrid( 0, 2 );
	m_gridMaintanenceRepairs->EnableEditing( true );
	m_gridMaintanenceRepairs->EnableGridLines( true );
	m_gridMaintanenceRepairs->EnableDragGridSize( false );
	m_gridMaintanenceRepairs->SetMargins( 0, 0 );
	
	// Columns
	m_gridMaintanenceRepairs->SetColSize( 0, 50 );
	m_gridMaintanenceRepairs->SetColSize( 1, 400 );
	m_gridMaintanenceRepairs->EnableDragColMove( false );
	m_gridMaintanenceRepairs->EnableDragColSize( true );
	m_gridMaintanenceRepairs->SetColLabelSize( 30 );
	m_gridMaintanenceRepairs->SetColLabelValue( 0, _("Priority") );
	m_gridMaintanenceRepairs->SetColLabelValue( 1, _("RepairsTODO") );
	m_gridMaintanenceRepairs->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridMaintanenceRepairs->AutoSizeRows();
	m_gridMaintanenceRepairs->EnableDragRowSize( true );
	m_gridMaintanenceRepairs->SetRowLabelSize( 30 );
	m_gridMaintanenceRepairs->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	m_gridMaintanenceRepairs->SetLabelTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	// Cell Defaults
	m_gridMaintanenceRepairs->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );
	m_menu71 = new wxMenu();
	wxMenuItem* m_menuItem91;
	m_menuItem91 = new wxMenuItem( m_menu71, wxID_ANY, wxString( _("Repair done") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( m_menuItem91 );
	
	wxMenuItem* m_menuItem921;
	m_menuItem921 = new wxMenuItem( m_menu71, wxID_ANY, wxString( _("Buy parts for this repair") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( m_menuItem921 );
	
//	wxMenuItem* m_separator11;
//	m_separator11 = m_menu71->AppendSeparator();
	
	wxMenuItem* m_menuItem131;
	m_menuItem131 = new wxMenuItem( m_menu71, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( m_menuItem131 );
	
	
	bSizer122->Add( m_gridMaintanenceRepairs, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	fgSizer1513->Add( bSizer122, 1, wxEXPAND, 5 );
	
	m_panel141->SetSizer( fgSizer1513 );
	m_panel141->Layout();
	fgSizer1513->Fit( m_panel141 );
	m_notebook6->AddPage( m_panel141, _("Repairs"), false );
	m_panel16 = new wxPanel( m_notebook6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1511;
	fgSizer1511 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer1511->AddGrowableCol( 0 );
	fgSizer1511->AddGrowableRow( 2 );
	fgSizer1511->SetFlexibleDirection( wxBOTH );
	fgSizer1511->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer10111;
	bSizer10111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAddLineBuyParts = new wxButton( m_panel16, wxID_ANY, _("Add Line"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddLineBuyParts->SetToolTip( _("Add a new line") );
	bSizer10111->Add( m_buttonAddLineBuyParts, 0, wxALL, 5 );
	
	m_buttonSaveBuyParts = new wxButton( m_panel16, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSaveBuyParts->SetToolTip( _("export your BuyParts-data as HTML or ODT") );	
	bSizer10111->Add( m_buttonSaveBuyParts, 0, wxALL, 5 );
	
	m_staticline1511 = new wxStaticLine( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer10111->Add( m_staticline1511, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText6211 = new wxStaticText( m_panel16, wxID_ANY, _("Select Layout:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6211->Wrap( -1 );
	bSizer10111->Add( m_staticText6211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceSelectLayoutBuyPartsChoices;
	m_choiceSelectLayoutBuyParts = new wxChoice( m_panel16, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), m_choiceSelectLayoutBuyPartsChoices, 0 );
	m_choiceSelectLayoutBuyParts->SetToolTip( _("Select a layout which is displayed\nwith button \"View\"") );
	m_choiceSelectLayoutBuyParts->SetSelection( 0 );
	bSizer10111->Add( m_choiceSelectLayoutBuyParts, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonReloadLayoutsBuyPartsHTML = new wxButton( m_panel16, wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonReloadLayoutsBuyPartsHTML->SetToolTip( _("Reload Layouts") );
	
	bSizer10111->Add( m_buttonReloadLayoutsBuyPartsHTML, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEditLayoutODTBuyParts = new wxButton( m_panel16, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_buttonEditLayoutODTBuyParts->SetToolTip( _("Edit Layout") );
	
	bSizer10111->Add( m_buttonEditLayoutODTBuyParts, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnHTMLBuyParts = new wxRadioButton( m_panel16, wxID_ANY, wxT("HTML"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnHTMLBuyParts->SetValue( true ); 
	bSizer10111->Add( m_radioBtnHTMLBuyParts, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnODTBuyParts = new wxRadioButton( m_panel16, wxID_ANY, wxT("ODT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10111->Add( m_radioBtnODTBuyParts, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonViewBuyParts = new wxButton( m_panel16, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonViewBuyParts->SetToolTip( _("View data in browser (HTML) or Openoffice/LibreOffice (ODT)") );
	bSizer10111->Add( m_buttonViewBuyParts, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10111->Add( 300, 0, 1, wxEXPAND, 5 );
	
	fgSizer1511->Add( bSizer10111, 1, wxEXPAND, 5 );
	
	m_staticline1411 = new wxStaticLine( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1511->Add( m_staticline1411, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );
	
	bSizer121->SetMinSize( wxSize( -1,400 ) ); 
	m_gridMaintenanceBuyParts = new EzGrid( m_panel16, wxID_ANY, wxDefaultPosition, wxSize(1000,400), 0 );
	
	// Grid
	m_gridMaintenanceBuyParts->CreateGrid( 0, 6 );
	m_gridMaintenanceBuyParts->EnableEditing( true );
	m_gridMaintenanceBuyParts->EnableGridLines( true );
	m_gridMaintenanceBuyParts->EnableDragGridSize( false );
	m_gridMaintenanceBuyParts->SetMargins( 0, 0 );
	
	// Columns
	m_gridMaintenanceBuyParts->SetColSize( 0, 50 );
	m_gridMaintenanceBuyParts->SetColSize( 1, 101 );
	m_gridMaintenanceBuyParts->SetColSize( 2, 400 );
	m_gridMaintenanceBuyParts->SetColSize( 3, 325 );
	m_gridMaintenanceBuyParts->SetColSize( 4, 74 );
	m_gridMaintenanceBuyParts->SetColSize( 5, 255 );
	m_gridMaintenanceBuyParts->EnableDragColMove( false );
	m_gridMaintenanceBuyParts->EnableDragColSize( true );
	m_gridMaintenanceBuyParts->SetColLabelSize( 30 );
	m_gridMaintenanceBuyParts->SetColLabelValue( 0, _("Priority") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 1, _("Category") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 2, _("Title") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 3, _("Buy Parts") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 4, _("Date") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 5, _("At") );
	m_gridMaintenanceBuyParts->SetColLabelValue( 6, _("Active") );
	m_gridMaintenanceBuyParts->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridMaintenanceBuyParts->AutoSizeRows();
	m_gridMaintenanceBuyParts->EnableDragRowSize( true );
	m_gridMaintenanceBuyParts->SetRowLabelSize( 40 );
	m_gridMaintenanceBuyParts->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridMaintenanceBuyParts->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_menu711 = new wxMenu();
	wxMenuItem* m_menuItem1311;
	m_menuItem1311 = new wxMenuItem( m_menu711, wxID_ANY, wxString( _("Delete Row") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu711->Append( m_menuItem1311 );
	
	
	bSizer121->Add( m_gridMaintenanceBuyParts, 1, wxALL|wxEXPAND, 5 );
	
	fgSizer1511->Add( bSizer121, 1, wxEXPAND, 5 );
	
	m_panel16->SetSizer( fgSizer1511 );
	m_panel16->Layout();
	fgSizer1511->Fit( m_panel16 );
	m_notebook6->AddPage( m_panel16, _("Buy Parts"), false );
	
	bSizer13->Add( m_notebook6, 1, wxEXPAND | wxALL, 5 );
	
	m_panel13->SetSizer( bSizer13 );
	m_panel13->Layout();
	bSizer13->Fit( m_panel13 );
	m_logbook->AddPage( m_panel13, _("Maintenance"), false );
	
	bSizer2->Add( m_logbook, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxHORIZONTAL );

	// Connect Events
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_EDITOR_HIDDEN, wxGridEventHandler( LogbookDialog::onGridEditorHidden ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( LogbookDialog::onGridEditorShow ), NULL, this );
	m_logbook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( LogbookDialog::OnNoteBookPageChangedLogbook ), NULL, this );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( LogbookDialog::LogbookDialogOnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( LogbookDialog::LogbookDialogOnInitDialog ) );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::m_button4OnButtonClick ), NULL, this );
	m_gridGlobal->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickGlobal ), NULL, this );
	m_gridWeather->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickWeather ), NULL, this );
	m_gridMotorSails->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickMotorSails ), NULL, this );
	m_gridOverview->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickOverview ), NULL, this );
	m_gridCrew->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickCrew ), NULL, this );
	this->Connect( m_menuItem30->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionOnboardCrew ) );
	this->Connect( m_menuItem31->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAllEntriesCrew ) );
	m_gridCrewWake->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickCrewWake ), NULL, this );
	logSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::logSaveOnButtonClick ), NULL, this );
	logView->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::logViewOnButtonClick ), NULL, this );
	newLogbook->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::newLogbookOnButtonClick ), NULL, this );
	selLogbook->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::selLogbookOnButtonClick ), NULL, this );
	m_gridGlobal->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridCellRightClick ), NULL, this );
	m_gridGlobal->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridCmdCellChange ), NULL, this );
	m_gridGlobal->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridSelectCell ), NULL, this );
	m_gridGlobal->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridGlobalOnKeyDown ), NULL, this );
	this->Connect( m_menuItem41->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_TimerOnMenuSelection ) );
	this->Connect( m_menuItemTimerInterval->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionTimerInterval ) );
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
	this->Connect( m_menuItem15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHideColumn ) );
	this->Connect( m_menuItem16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHideColumnOverView ) );
	this->Connect( m_menuItemSearch->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionSearch ) );
	m_gridWeather->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridCellRightClick ), NULL, this );
	m_gridWeather->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridCmdCellChange ), NULL, this );
	m_gridWeather->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridSelectCell ), NULL, this );
	m_gridWeather->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridWeatherOnKeyDown ), NULL, this );
	m_gridMotorSails->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridCellRightClick ), NULL, this );
	m_gridMotorSails->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridCmdCellChange ), NULL, this );
	m_gridMotorSails->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridSelectCell ), NULL, this );
	m_gridMotorSails->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridMotorSailsOnKeyDown ), NULL, this );
	crewAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewAddOnButtonClick ), NULL, this );
	crewSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewSaveOnButtonClick ), NULL, this );
	crewView->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewViewOnButtonClick ), NULL, this );
	m_gridCrew->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridCrewOnGridCellChange ), NULL, this );
	m_gridCrew->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridCrewOnGridCellRightClick ), NULL, this );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem2OnMenuSelection ) );
	m_gridCrewWake->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridCrewWakeOnGridCellChange ), NULL, this );
	addEquipmentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boataddEquipmentButtonOnButtonClick ), NULL, this );
	boatSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boatSaveOnButtonClick ), NULL, this );
	boatView->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boatViewOnButtonClick ), NULL, this );
//	boatName->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LogbookDialog::boatNameOnTextEnter ), NULL, this );
	m_gridEquipment->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridEquipmentOnGridCellChange ), NULL, this );
	m_gridEquipment->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridEquipmentOnGridCellRightClick ), NULL, this );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem3OnMenuSelection ) );
	m_radioBtnHTML->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTML ), NULL, this );
	m_radioBtnODT->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODT ), NULL, this );
	m_buttonReloadLayout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonReloadLayoutLogbook ), NULL, this );
	m_buttonEditLayout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutLogbook ), NULL, this );
	m_buttonAddLineService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineService ), NULL, this );
	m_buttonSaveService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveService), NULL, this );
	m_buttonReloadLayoutsServiceHTML->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsServiceHTML ), NULL, this );
	m_buttonEditLayoutODTService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTService ), NULL, this );
	m_radioBtnHTMLService->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLService ), NULL, this );
	m_radioBtnODTService->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTService ), NULL, this );
	m_buttonViewService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewService ), NULL, this );
	m_buttonReloadLayoutsBoat->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsBoat ), NULL, this );
	m_buttonEditLayoutBoat->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutBoat ), NULL, this );
	m_radioBtnHTMLBoat->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLBoat ), NULL, this );
	m_radioBtnODTBoat->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTBoat ), NULL, this );
	m_buttonReloadCrew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsCrew ), NULL, this );
	m_buttonEditLayoutCrew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutCrew ), NULL, this );
	m_radioBtnHTMLCrew->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLCrew ), NULL, this );
	m_radioBtnODTCrew->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTCrew ), NULL, this );
	m_buttonSelectLogbook->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickSelectLogbook ), NULL, this );
	m_gridOverview->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellRightClickOverview ), NULL, this );
	m_gridOverview->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickOverview ), NULL, this );
	this->Connect( m_menuItemOverviewRoute->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionGotoRoute ) );
	logSaveOverview->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnButtonClickOverviewSave ), NULL, this );
	m_buttonReloadLayoutOview->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonReloadLayoutOverView ), NULL, this );
	m_buttonEditLayoutOview->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutOverview ), NULL, this );
	m_radioBtnHTMLOverview->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLOverview ), NULL, this );
	m_gridOverview->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownOverview ), NULL, this );
	m_radioBtnODTOverview->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTOverView ), NULL, this );
	logViewOverview->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnButtonClickOverView ), NULL, this );
	m_radioBtnHTMLOverview->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLOverview ), NULL, this );
	m_radioBtnAllLogbooks->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::OnRadioButtonAllLogbooks ), NULL, this );
	m_radioBtnActuellLogbook->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::OnRadioButtonActuellLogbook ), NULL, this );
	m_toggleBtnShowEquipment->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnToggleButtonShowEquip ), NULL, this );
	this->Connect( m_menuItem19->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem19MenuSelection ) );
	this->Connect( m_menuItem21->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem21MenuSelection ) );
	this->Connect( m_menuItemSameWatch->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionSameWatch ) );
	this->Connect( m_menuItemAddWake->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAddWatch ) );
	this->Connect( m_menuItem32->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAsc ) );
	this->Connect( m_menuItem33->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionDesc ) );

	m_gridCrew->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( LogbookDialog::OnGridEditorShownCrew ), NULL, this );

	this->Connect( m_menuItem22->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHiddenCrew ) );
	this->Connect( m_menuItem23->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHiddenWake ) );
	m_gridGlobal->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellLeftClickGlobal ), NULL, this );

	m_gridMaintanence->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::onGridCellServiceChange ), NULL, this );
	m_gridMaintanence->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellServiceSelected ), NULL, this );
	m_gridCrewWake->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellRightClickWake ), NULL, this );
	m_gridCrew->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownCrew ), NULL, this );
	m_gridCrewWake->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownWatch ), NULL, this );
	m_gridMaintanence->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickService ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickBuyParts ), NULL, this );
	m_gridMaintanenceRepairs->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickRepairs ), NULL, this );
	
	this->Connect( m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceOK ) );
	this->Connect( m_menuItem92->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceBuyParts ) );

	m_gridMaintanence->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellLeftClickService ), NULL, this );
	m_gridMaintanence->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellLeftClickService ), NULL, this );
	m_gridMaintanence->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellRightClickService ), NULL, this );
	m_buttonAddLineBuyParts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineBuyParts ), NULL, this );
	m_buttonAddLineRepairs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineRepairs ), NULL, this );
	m_buttonReloadLayoutsBuyPartsHTML->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsBuyPartsHTML ), NULL, this );
	m_buttonEditLayoutODTBuyParts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTBuyParts ), NULL, this );
	m_radioBtnHTMLBuyParts->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLBuyParts ), NULL, this );
	m_radioBtnODTBuyParts->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTBuyParts ), NULL, this );
	m_buttonViewBuyParts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::onGridCellChangeBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellRightClickBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellSelectedBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellSelectedBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellLeftClickBuyParts ), NULL, this );
	m_buttonSaveBuyParts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveBuyParts ), NULL, this );

	this->Connect( m_menuItem91->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsOK ) );
	this->Connect( m_menuItem921->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsBuyParts ) );
	this->Connect( m_menuItem131->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsDelete ) );
	this->Connect( m_menuItem1311->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionBuyPartsDelete ) );
	this->Connect( m_menuItem13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceDelete ) );
	this->Connect( m_menuItem132->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionShowHiddenCols ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionSearch ) );
	this->Connect( m_menuItem14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionShowHiddenColsOverview ) );
	m_gridMaintanenceRepairs->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::onGridCellRepairsChange ), NULL, this );
	m_gridMaintanenceRepairs->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellRightClickRepairs ), NULL, this );
	m_gridMaintanenceRepairs->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellRepairsSelected ), NULL, this );
	m_gridMaintanenceRepairs->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownRepairs ), NULL, this );
	m_buttonSaveRepairs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveRepairs ), NULL, this );
	m_buttonReloadLayoutsRepairsHTML->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsRepairsHTML ), NULL, this );
	m_buttonEditLayoutODTRepairs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTRepairs ), NULL, this );
	m_radioBtnHTMLRepairs->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLRepairs ), NULL, this );
	m_radioBtnODTRepairs->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTRepairs ), NULL, this );
	m_buttonViewRepairs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewRepairs ), NULL, this );

	m_buttonSaveService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveService ), NULL, this );
	m_buttonReloadLayoutsServiceHTML->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsServiceHTML ), NULL, this );
	m_buttonEditLayoutODTService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTService ), NULL, this );
	m_radioBtnHTMLService->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLService ), NULL, this );
	m_radioBtnODTService->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTService ), NULL, this );
	m_buttonViewService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewService ), NULL, this );

	m_gridGlobal->Connect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Connect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Connect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Connect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Connect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Connect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Connect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Connect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Connect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Connect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Connect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Connect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Connect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Connect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Connect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	this->menuItemTimer = 	m_menuItem41;
}



LogbookDialog::~LogbookDialog()
{
	setIniValues();

	if(GPSTimer->IsRunning())
		GPSTimer->Stop();

	this->Disconnect( wxEVT_TIMER, wxObjectEventFunction( &LogbookDialog::OnTimerGPS ));
    delete GPSTimer;
	GPSTimer = NULL;

	if(logbookTimer->IsRunning())
		logbookTimer->Stop();

	this->Disconnect( wxEVT_TIMER, wxObjectEventFunction( &LogbookDialog::OnLogTimer ));
    delete logbookTimer;
	logbookTimer = NULL;

	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( LogbookDialog::LogbookDialogOnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( LogbookDialog::LogbookDialogOnInitDialog ) );
	m_logbook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( LogbookDialog::OnNoteBookPageChangedLogbook ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::m_button4OnButtonClick ), NULL, this );
	logView->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::logViewOnButtonClick ), NULL, this );
	logSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::logSaveOnButtonClick ), NULL, this );
	newLogbook->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::newLogbookOnButtonClick ), NULL, this );
	selLogbook->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::selLogbookOnButtonClick ), NULL, this );
	m_gridGlobal->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridCellRightClick ), NULL, this );
	m_gridGlobal->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridCmdCellChange ), NULL, this );
	m_gridGlobal->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridGlobalOnGridSelectCell ), NULL, this );
	m_gridGlobal->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridGlobalOnKeyDown ), NULL, this );
	m_gridGlobal->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickGlobal ), NULL, this );
	m_gridWeather->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickWeather ), NULL, this );
	m_gridMotorSails->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickMotorSails ), NULL, this );
	m_gridOverview->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickOverview ), NULL, this );
	m_gridCrew->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickCrew ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionOnboardCrew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAllEntriesCrew ) );
	m_gridCrewWake->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftDClickCrewWake ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_TimerOnMenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHideColumn ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionTimerInterval ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHideColumnOverView ) );
	m_gridWeather->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridCellRightClick ), NULL, this );
	m_gridWeather->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridCmdCellChange ), NULL, this );
	m_gridWeather->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridWeatherOnGridSelectCell ), NULL, this );
	m_gridWeather->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridWeatherOnKeyDown ), NULL, this );
	m_gridMotorSails->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridCellRightClick ), NULL, this );
	m_gridMotorSails->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridCmdCellChange ), NULL, this );
	m_gridMotorSails->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::m_gridMotorSailsOnGridSelectCell ), NULL, this );
	m_gridMotorSails->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::m_gridMotorSailsOnKeyDown ), NULL, this );
	crewAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewAddOnButtonClick ), NULL, this );
	crewSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewSaveOnButtonClick ), NULL, this );
	crewView->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::crewViewOnButtonClick ), NULL, this );
	m_gridCrew->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridCrewOnGridCellChange ), NULL, this );
	m_gridCrew->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridCrewOnGridCellRightClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_TimerOnMenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem2OnMenuSelection ) );
	m_gridCrewWake->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridCrewWakeOnGridCellChange ), NULL, this );
	addEquipmentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boataddEquipmentButtonOnButtonClick ), NULL, this );
	boatSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boatSaveOnButtonClick ), NULL, this );
	boatView->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::boatViewOnButtonClick ), NULL, this );
//	boatName->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( LogbookDialog::boatNameOnTextEnter ), NULL, this );
	m_gridEquipment->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::m_gridEquipmentOnGridCellChange ), NULL, this );
	m_gridEquipment->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::m_gridEquipmentOnGridCellRightClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem3OnMenuSelection ) );
	m_radioBtnHTML->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTML ), NULL, this );
	m_radioBtnODT->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODT ), NULL, this );
	m_buttonReloadLayout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonReloadLayoutLogbook ), NULL, this );
	m_buttonEditLayout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutLogbook ), NULL, this );
	m_buttonAddLineService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineService ), NULL, this );
	m_buttonSaveService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveService ), NULL, this );
	m_buttonReloadLayoutsServiceHTML->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsServiceHTML ), NULL, this );
	m_buttonEditLayoutODTService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTService ), NULL, this );
	m_radioBtnHTMLService->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLService ), NULL, this );
	m_radioBtnODTService->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTService ), NULL, this );
	m_buttonViewService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewService ), NULL, this );
	m_buttonReloadLayoutsBoat->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsBoat ), NULL, this );
	m_buttonEditLayoutBoat->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutBoat ), NULL, this );
	m_radioBtnHTMLBoat->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLBoat ), NULL, this );
	m_radioBtnODTBoat->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTBoat ), NULL, this );
	m_buttonReloadCrew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsCrew ), NULL, this );
	m_buttonEditLayoutCrew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutCrew ), NULL, this );
	m_radioBtnHTMLCrew->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLCrew ), NULL, this );
	m_radioBtnODTCrew->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTCrew ), NULL, this );
	m_buttonSelectLogbook->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickSelectLogbook ), NULL, this );	
	m_gridOverview->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellRightClickOverview ), NULL, this );
	m_gridOverview->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickOverview ), NULL, this );
	m_gridOverview->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownOverview ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionGotoRoute ) );
	logSaveOverview->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnButtonClickOverviewSave ), NULL, this );
	m_buttonReloadLayoutOview->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonReloadLayoutOverView ), NULL, this );
	m_buttonEditLayoutOview->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutOverview ), NULL, this );
	m_radioBtnHTMLOverview->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLOverview ), NULL, this );
	m_radioBtnODTOverview->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTOverView ), NULL, this );
	logViewOverview->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnButtonClickOverView ), NULL, this );
	m_radioBtnHTMLOverview->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLOverview ), NULL, this );
	m_radioBtnAllLogbooks->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::OnRadioButtonAllLogbooks ), NULL, this );
	m_gridMaintanence->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::onGridCellServiceChange ), NULL, this );
	m_gridMaintanence->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellServiceSelected ), NULL, this );
	m_gridMaintenanceBuyParts->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellLeftClickBuyParts ), NULL, this );
	m_buttonSaveBuyParts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveBuyParts ), NULL, this );
	m_toggleBtnShowEquipment->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::OnToggleButtonShowEquip ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem19MenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::m_menuItem21MenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAddWatch ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionAsc ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionDesc ) );

	m_gridCrewWake->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellRightClickWake ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionSameWatch ) );
	m_gridCrew->Disconnect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( LogbookDialog::OnGridEditorShownCrew ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHiddenCrew ) );
	m_gridCrew->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownCrew ), NULL, this );
	m_gridCrewWake->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownWatch ), NULL, this );

	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionHiddenWake ) );
	m_gridGlobal->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridCellLeftClickGlobal ), NULL, this );

	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceOK ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceBuyParts ) );
	this->Disconnect( 503, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionShowHiddenCols ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::OnMenuSelectionShowHiddenColsOverview ) );
	m_gridMaintanence->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellRightClickService ), NULL, this );
	m_gridMaintanence->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickService ), NULL, this );
	m_gridMaintenanceBuyParts->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickBuyParts ), NULL, this );
	m_gridMaintanenceRepairs->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( LogbookDialog::OnGridLabelLeftClickRepairs ), NULL, this );

	m_gridMaintenanceBuyParts->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LogbookDialog::onGridCellChangeBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LogbookDialog::onGridCellRightClickBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( LogbookDialog::onGridCellSelectedBuyParts ), NULL, this );
	m_buttonAddLineBuyParts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineBuyParts ), NULL, this );
	m_gridMaintenanceBuyParts->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( LogbookDialog::OnKeyDownBuyParts ), NULL, this );

	m_buttonAddLineRepairs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineRepairs ), NULL, this );
	m_buttonSaveRepairs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveRepairs ), NULL, this );
	m_buttonReloadLayoutsRepairsHTML->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsRepairsHTML ), NULL, this );
	m_buttonEditLayoutODTRepairs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTRepairs ), NULL, this );
	m_radioBtnHTMLRepairs->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLRepairs ), NULL, this );
	m_radioBtnODTRepairs->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTRepairs ), NULL, this );
	m_buttonViewRepairs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewRepairs ), NULL, this );

	m_buttonAddLineService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineService ), NULL, this );
	m_buttonSaveService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickSaveService ), NULL, this );
	m_buttonReloadLayoutsServiceHTML->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickReloadLayoutsServiceHTML ), NULL, this );
	m_buttonEditLayoutODTService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickEditLayoutODTService ), NULL, this );
	m_radioBtnHTMLService->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonHTMLService ), NULL, this );
	m_radioBtnODTService->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( LogbookDialog::onRadioButtonODTService ), NULL, this );
	m_buttonViewService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtonClickViewService ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsOK ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsBuyParts ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionRepairsDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionBuyPartsDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogbookDialog::onMenuSelectionServiceDelete ) );
	m_buttonAddLineRepairs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogbookDialog::onButtobClickAddLineRepairs ), NULL, this );
	m_gridGlobal->Disconnect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Disconnect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Disconnect(wxEVT_SCROLLWIN_THUMBTRACK,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Disconnect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Disconnect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Disconnect(wxEVT_SCROLLWIN_PAGEUP,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Disconnect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Disconnect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Disconnect(wxEVT_SCROLLWIN_PAGEDOWN,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Disconnect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Disconnect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Disconnect(wxEVT_SCROLLWIN_LINEUP,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	m_gridGlobal->Disconnect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridGlobalScrolled), NULL, this);
	m_gridWeather->Disconnect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridWeatherScrolled), NULL, this);
	m_gridMotorSails->Disconnect(wxEVT_SCROLLWIN_LINEDOWN,wxScrollWinEventHandler(LogbookDialog::gridMotorSailsScrolled), NULL, this);

	delete m_menu1; 
	delete m_menu2; 
	delete m_menu7; 
	delete m_menu71; 
	delete m_menu711;

	delete maintenance;  //still a warning with Mac OS C Xcode here: "Delete called on 'Maintenance' that has virtual functions but non-virtual destructor"
	delete crewList;
	delete boat;
	delete logbook;
	delete coldfinger;

	clearDataDir();
}

void LogbookDialog::clearDataDir()
{
	wxString data = *pHome_Locn;
	data.Append(_T("data"));
	data.Append(wxFileName::GetPathSeparator());

	wxString f = wxFindFirstFile(data+_T("*.tmp"));
	while ( !f.empty() )
	{
		wxRemoveFile(f);
		f = wxFindNextFile();
	}

	f = wxFindFirstFile(data+_T("*.html"));
	while ( !f.empty() )
	{
		wxRemoveFile(f);
		f = wxFindNextFile();
	}

	f = wxFindFirstFile(data+_T("*.odt"));
	while ( !f.empty() )
	{
		wxRemoveFile(f);
		f = wxFindNextFile();
	}
}


void LogbookDialog::OnGridLabelLeftDClickGlobal( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	selGridCol = ev.GetCol();
	navigationHideColumn(ev);
}

void LogbookDialog::OnGridLabelLeftDClickWeather( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	selGridCol = ev.GetCol();
	navigationHideColumn(ev);
}

void LogbookDialog::OnGridLabelLeftDClickMotorSails( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	selGridCol = ev.GetCol();
	navigationHideColumn(ev);
}

void LogbookDialog::m_menu1Highlighted(wxMenuEvent& ev)
{
#ifdef __WXOSX__
    MessageBoxOSX(NULL,m_menu1->GetLabel(ev.GetMenuId()));
#else
	wxMessageBox(m_menu1->GetLabel(ev.GetMenuId()));
#endif
}

void LogbookDialog::OnMenuSelectionSearch( wxCommandEvent& event )
{
	logbook->showSearchDlg(selGridRow,selGridCol);
}

void LogbookDialog::OnMenuSelectionHideColumn(wxCommandEvent& ev)
{
	navigationHideColumn(ev);	
}

void LogbookDialog::navigationHideColumn(wxCommandEvent& ev)
{
	int selGrid = this->m_notebook8->GetSelection();
	int count = 0;

	for(int i = 0; i < logGrids[selGrid]->GetNumberCols() && count < 2; i++)
		if(logGrids[selGrid]->GetColumnWidth(i) > 0)
			count++;

	if(count < 2) return;

	logGrids[selGrid]->SetColumnWidth(selGridCol,0);
	if(previousColumn != selGridCol)
		logGrids[selGrid]->SetGridCursor(selGridRow,previousColumn);
	selGridCol = previousColumn;
	logGrids[selGrid]->Refresh();
}

void LogbookDialog::m_gridGlobalOnKeyDown( wxKeyEvent& ev )
{
	noOpenPositionDlg = true;
	wxTextCtrl *ctrl = (wxTextCtrl*)ev.GetEventObject();

	selGridCol  = logGrids[m_notebook8->GetSelection()]->GetGridCursorCol();

	if (ev.ShiftDown() && ev.GetKeyCode() == WXK_RETURN)
	{	
		if(ev.GetEventObject()->IsKindOf(CLASSINFO(wxTextCtrl)))	
			ctrl->WriteText( wxT("\n") );
		return;
	}

	if (ev.GetKeyCode() == WXK_RETURN)
	{	
//		if(selGridCol == Logbook::POSITION)
//				noOpenPositionDlg = false;

		ev.Skip();
		setEqualRowHeight(selGridRow);
		for(int i = 0; i < LOGGRIDS; i++)
			logGrids[i]->Refresh();
		return;
	}

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || (ev.GetKeyCode() == WXK_LEFT))
	{	
		if(selGridCol == 0)
		{
			if(m_notebook8->GetSelection() == 0)
				m_notebook8->SetSelection(2);
			else
				m_notebook8->SetSelection(m_notebook8->GetSelection()-1);
			selGridCol = logGrids[m_notebook8->GetSelection()]->GetNumberCols()-1;
			logGrids[m_notebook8->GetSelection()]->SetFocus();
			logGrids[m_notebook8->GetSelection()]->SetGridCursor(selGridRow,selGridCol);
			logGrids[m_notebook8->GetSelection()]->MakeCellVisible(selGridRow,selGridCol);

			checkHiddenColumns(logGrids[m_notebook8->GetSelection()],-1,true);
		}
		else
		{
			if(checkHiddenColumns(logGrids[m_notebook8->GetSelection()],-1,true))
				ev.Skip();
		}
		return;
	}

	if (ev.GetKeyCode() == WXK_TAB || ev.GetKeyCode() == WXK_RIGHT)
	{	
		if(selGridCol == logGrids[m_notebook8->GetSelection()]->GetNumberCols()-1)
		{
			if(m_notebook8->GetSelection() == LOGGRIDS - 1)
				m_notebook8->SetSelection(0);
			else
				m_notebook8->SetSelection(m_notebook8->GetSelection()+1);
			selGridCol = 0;
			logGrids[m_notebook8->GetSelection()]->SetFocus();
			logGrids[m_notebook8->GetSelection()]->SetGridCursor(selGridRow,selGridCol);
			logGrids[m_notebook8->GetSelection()]->MakeCellVisible(selGridRow,selGridCol);

			checkHiddenColumns(logGrids[m_notebook8->GetSelection()],1,true);
		}
		else
		{
			if(checkHiddenColumns(logGrids[m_notebook8->GetSelection()],1,true))
				ev.Skip();
		}
		return;
	}
    else 
	{
        ev.Skip () ;
	}
}

bool LogbookDialog::checkHiddenColumns(wxGrid* grid,int i, bool use)
{
	bool skip = true;

	while((selGridCol+i <= grid->GetNumberCols()) && (selGridCol+i >= 0))
	{
		if(grid->GetColSize(selGridCol+i) == 0)
			selGridCol += i;
		else
			break;
		
		if((selGridCol == 0  && i == -1) && use)
		{
			  if(m_notebook8->GetSelection() == 0)
				m_notebook8->SetSelection(2);
			  else if(m_notebook8->GetSelection() == 1)
				m_notebook8->SetSelection(0);
			  else
				m_notebook8->SetSelection(1);

			  grid = logGrids[m_notebook8->GetSelection()];
			  selGridCol = grid->GetNumberCols()-1;
			  grid->SetFocus();
			  grid->SetGridCursor(selGridRow,selGridCol);
			  grid->MakeCellVisible(selGridRow,selGridCol);
			  checkHiddenColumns(grid, i, false);
			  return true;
		}

			if((selGridCol == grid->GetNumberCols()-1 && i == 1) && use)
			{
			  if(m_notebook8->GetSelection() == 0)
				m_notebook8->SetSelection(1);
			  else if(m_notebook8->GetSelection() == 1)
				m_notebook8->SetSelection(2);
			  else
				m_notebook8->SetSelection(0);

			  selGridCol = 0;
			  grid = logGrids[m_notebook8->GetSelection()];
			  grid->SetFocus();
			  grid->SetGridCursor(selGridRow,selGridCol);
			  grid->MakeCellVisible(selGridRow,selGridCol);
			  if(m_notebook8->GetSelection() == 0)
				 selGridCol--;
			  checkHiddenColumns(grid, i, false);
			  return true;
			}

			grid = logGrids[m_notebook8->GetSelection()];
		

	}
	grid->SetGridCursor(selGridRow,selGridCol);
	return skip;
}

void LogbookDialog::OnGridCellLeftClickGlobal( wxGridEvent& event )
{
	noOpenPositionDlg = false;
	event.Skip();
}

void LogbookDialog::gridGlobalScrolled( wxScrollWinEvent& ev )
{
	ev.Skip();
	m_gridWeather->HandleOnScroll(ev);
	m_gridMotorSails->HandleOnScroll(ev);
}

void LogbookDialog::gridWeatherScrolled( wxScrollWinEvent& ev )
{
	ev.Skip();
	m_gridGlobal->HandleOnScroll(ev);
	m_gridMotorSails->HandleOnScroll(ev);
}

void LogbookDialog::gridMotorSailsScrolled( wxScrollWinEvent& ev )
{
	ev.Skip();
	m_gridWeather->HandleOnScroll(ev);
	m_gridGlobal->HandleOnScroll(ev);
}

void LogbookDialog::m_gridMotorSailsOnKeyDown( wxKeyEvent& ev )
{
	m_gridGlobalOnKeyDown( ev );
}

void LogbookDialog::m_gridWeatherOnKeyDown( wxKeyEvent& ev )
{
	m_gridGlobalOnKeyDown( ev );
}

void LogbookDialog::newLogbookOnButtonClick( wxCommandEvent& ev )
{
	logbook->newLogbook();
}

void LogbookDialog::selLogbookOnButtonClick( wxCommandEvent& ev )
{
	logbook->selectLogbook();
}

void LogbookDialog::onButtonReloadLayoutLogbook(wxCommandEvent & ev)
{
	loadLayoutChoice(logbook->layout_locn,logbookChoice);
}

void LogbookDialog::onButtonClickEditLayoutLogbook(wxCommandEvent & ev)
{
	int format;
	
	if(m_radioBtnODT->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(logbookChoice,logbook->layout_locn, format);
}

int LogbookDialog::showLayoutDialog(wxChoice *choice, wxString location, int format)
{
	wxString layout = choice->GetString(choice->GetSelection());
	int sel = choice->GetSelection();
	wxString fmt;

	if(format)
		fmt = _T(".odt");
	else
		fmt = _T(".html");

	LayoutDialog* dlg = new LayoutDialog(this,location,choice);

	dlg->SetTitle(layout);
	layout = location + layout + fmt;

	wxArrayString ar;
	ar.Add(_("none"));
	for(unsigned int r = 0; r < choice->GetCount(); r++)
	{
		wxString g = choice->GetString(r);
		if(!g.Contains(_T("_"))) continue; 
		g = g.substr(0,g.find_first_of('_')+1);

		if(!isInArrayString(ar,g))
			ar.Add(g);
	}
	dlg->m_choice15->Clear();
	dlg->m_choice15->Append(ar);
	dlg->m_choice15->SetSelection(0);
	loadLayoutChoice(location,choice);
	choice->SetSelection(sel);

	if (dlg->ShowModal() == wxID_CANCEL)
            return -1;
	
	if(dlg->m_radioBtnEdit->GetValue())
	{
		if(m_radioBtnODT->GetValue())
			startApplication(layout,fmt);
		else
			startApplication(layout, fmt);
	}
	else if(dlg->m_radioBtnFilter->GetValue())
	{
		logbookPlugIn->opt->layoutPrefix = 
			dlg->m_choice15->GetString(dlg->m_choice15->GetSelection());
		if(!(logbookPlugIn->opt->layoutPrefix == _("none")))
			logbookPlugIn->opt->filterLayout = true;
		else
			logbookPlugIn->opt->filterLayout = false;
		loadLayoutChoice(location,choice);
		return 1;
	}
	else if(dlg->m_radioBtnRename->GetValue())
	{
		::wxRenameFile(layout,
					   location+dlg->m_textCtrlRename->GetValue()+fmt);
		loadLayoutChoice(location,choice);
		return 2;
	}
	else if(dlg->m_radioBtnDelete->GetValue())
	{
		::wxRemoveFile(layout);
		loadLayoutChoice(location,choice);
		return 3;
	}
	else if(dlg->m_radioBtnEmail->GetValue())
	{
//		wxMimeTypesManager manager;
//		wxFileType *filetype1=manager.GetFileTypeFromExtension(_T("RSS"));
//		wxString command=filetype1->GetOpenCommand(_T(" "));

//		command = command.substr(0,command.find_first_of(_T('/'))-1);
		wxString command = logbookPlugIn->opt->mailClient;
#ifdef __WXMSW__		
		wxExecute(command + _T(" /mailurl:mailto:myfriend@xy.xy?subject=LogbookKonni-Layout&body=Drag and Drop file here"));			
		wxExecute(_T("explorer.exe /select,")+layout);
#endif
#ifdef __WXGTK__
		wxExecute(_T("/bin/bash -c \"") + logbookPlugIn->opt->mailClient +  _T(" -s Logbook-Layout --attach ") +
			  layout + _T("\"\""));		
		wxExecute(logbookPlugIn->opt->dataManager+_T(" ")+layout);		
#endif
#ifdef __WXOSX__
// worked in Mac-OS X
        wxExecute(command + _T(" mailto:carcode@me.com?subject=LogbookKonni-Layout&body=Drag-And-Drop-File-Here"));
#endif
		return 4;
	}
	else if(dlg->m_radioBtnInstall->GetValue())
	{
		if(!dlg->layoutFileName.IsEmpty())
		{
			::wxCopyFile(dlg->layoutPath,location+dlg->layoutFileName);
		}
		loadLayoutChoice(location,choice);
		return 5;
	}

	delete dlg;
	return -1;	
}

bool LogbookDialog::isInArrayString(wxArrayString ar, wxString s)
{
	for(unsigned int z = 0; z < ar.GetCount(); z ++)
		if(s.Trim() == ar[z].Trim())
			return true;

	return false;
}

void LogbookDialog::m_gridGlobalOnGridSelectCell( wxGridEvent& ev )
{

	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	if(selGridRow != ev.GetRow())
		setEqualRowHeight(selGridRow);

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();
	previousColumn = ev.GetCol();

	int rowHeight = m_gridGlobal->GetRowHeight(selGridRow);

	if(selGridCol == Logbook::REMARKS && rowHeight < 120)
		m_gridGlobal->SetRowHeight(selGridRow,120);
	else if(rowHeight == 120 && selGridCol != Logbook::REMARKS)
		setEqualRowHeight(selGridRow);

	for(int i = 0; i < LOGGRIDS; i++)
	{
		logGrids[i]->Refresh();
		logGrids[i]->MakeCellVisible(selGridRow,selGridCol);
	}

	if(selGridCol == Logbook::POSITION && !noOpenPositionDlg)
	{
		PositionDlg* dlg = new PositionDlg(this);
		int i = dlg->ShowModal();
		if( i == wxID_OK)
		{
			m_gridGlobal->SetCellValue(dlg->retstr,selGridRow,Logbook::POSITION);
			logbook->getModifiedCellValue(0,selGridRow,0,Logbook::POSITION);
			setEqualRowHeight(selGridRow);
		}
		delete dlg;
	}

	ev.Skip();
}

void LogbookDialog::m_gridMotorSailsOnGridSelectCell( wxGridEvent& ev )
{
	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	if(selGridRow != ev.GetRow())
		setEqualRowHeight(selGridRow);

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();
	previousColumn = ev.GetCol();

	if(selGridCol == Logbook::MREMARKS-logbook->sailsCol && m_gridMotorSails->GetRowHeight(selGridRow) < 120)
		m_gridMotorSails->SetRowHeight(selGridRow,120);
	else if(m_gridMotorSails->GetRowHeight(selGridRow) == 120 && selGridCol != Logbook::MREMARKS-logbook->sailsCol)
		setEqualRowHeight(selGridRow);

	for(int i = 0; i < LOGGRIDS; i++)
	{
		logGrids[i]->Refresh();
		logGrids[i]->MakeCellVisible(selGridRow,selGridCol);
	}
	ev.Skip();
}

void LogbookDialog::m_gridWeatherOnGridSelectCell( wxGridEvent& ev )
{
	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();
	previousColumn = ev.GetCol();

	for(int i = 0; i < LOGGRIDS; i++)
	{
		logGrids[i]->Refresh();
		logGrids[i]->MakeCellVisible(selGridRow,selGridCol);
	}

	ev.Skip();
}

void LogbookDialog::LogbookDialogOnInitDialog( wxInitDialogEvent& ev )
{

}

void LogbookDialog::setTitleExt()
{
	titleExt = _(" - Timer on - Interval: ")+wxString::Format(_T("%s h %s m %s s"),
		logbookPlugIn->opt->thour.c_str(),logbookPlugIn->opt->tmin.c_str(),logbookPlugIn->opt->tsec.c_str());
}

void LogbookDialog::init()
{	
	sashPos = -1;
	noOpenPositionDlg = false;
	decimalPoint = wxLocale::GetInfo(wxLOCALE_DECIMAL_POINT, wxLOCALE_CAT_NUMBER);
	setDatePattern();

	wxInitAllImageHandlers();
	clouds[0] = wxT("Cirrus");
	clouds[1] = wxT("Cirrocumulus");
	clouds[2] = wxT("Cirrostratus");
	clouds[3] = wxT("Altocumulus");
	clouds[4] = wxT("Altostratus");
	clouds[5] = wxT("Stratocumulus");
	clouds[6] = wxT("Stratus");
	clouds[7] = wxT("Cumulus");
	clouds[8] = wxT("Nimbostratus");
	clouds[9] = wxT("Cumulonimbus");

//	imageList = new wxImageList(160,120);

	saveDialogFilter = _("Opendocument SpreadSheet(*.ods)|*.ods|\
Excel 2003 Format(*.xml)|*.xml|\
CSV Format OpenOffice(*.csv)|*.csv|\
Backup Logbook(*.txt)|*.txt");

	setTitleExt();
	if(logbookPlugIn->opt->timer)
		SetTitle(GetTitle()+titleExt);

	declareExportHeader();

	defaultBackground = GetBackgroundColour();

	numPages = 0;
	totalColumns = 0;
	selGridRow = 0;
	selGridCol = 0;
	logbook = NULL;

	logGrids[0] = m_gridGlobal;
	logGrids[1] = m_gridWeather;
	logGrids[2] = m_gridMotorSails;

	if(logbookPlugIn->opt->navHTML)
	{
	  logbookChoice->SetSelection(logbookPlugIn->opt->navGridLayoutChoice);
	  m_radioBtnHTML->SetValue(true);
	}
	else
	{
	  logbookChoice->SetSelection(logbookPlugIn->opt->navGridLayoutChoiceODT);
	  this->m_radioBtnODT->SetValue(true);
	}

	if(logbookPlugIn->opt->crewHTML)
	{
	  crewChoice->SetSelection(logbookPlugIn->opt->crewGridLayoutChoice);
	  this->m_radioBtnHTMLCrew->SetValue(true);
	}
	else
	{
	  crewChoice->SetSelection(logbookPlugIn->opt->crewGridLayoutChoiceODT);
	  this->m_radioBtnODTCrew->SetValue(true);
	}

	if(logbookPlugIn->opt->boatHTML)
	{
	  boatChoice->SetSelection(logbookPlugIn->opt->boatGridLayoutChoice);	
	  this->m_radioBtnHTMLBoat->SetValue(true);
	}
	else
	{
	  boatChoice->SetSelection(logbookPlugIn->opt->boatGridLayoutChoice);
	  this->m_radioBtnODTBoat->SetValue(true);
	}

	if(logbookPlugIn->opt->overviewHTML)
	{
	  overviewChoice->SetSelection(logbookPlugIn->opt->overviewGridLayoutChoice);
	  this->m_radioBtnHTMLOverview->SetValue(true);
	}
	else
	{
	  overviewChoice->SetSelection(logbookPlugIn->opt->overviewGridLayoutChoiceODT);	
	  this->m_radioBtnODTOverview->SetValue(true);
	}
	
	if(logbookPlugIn->opt->serviceHTML)
	{
	  m_choiceSelectLayoutService->SetSelection(logbookPlugIn->opt->serviceGridLayoutChoice);
	  this->m_radioBtnHTMLService->SetValue(true);
	}
	else
	{
	  m_choiceSelectLayoutService->SetSelection(logbookPlugIn->opt->serviceGridLayoutChoiceODT);
	  this->m_radioBtnODTService->SetValue(true);
	}

	if(logbookPlugIn->opt->repairsHTML)
	{
	  m_choiceSelectLayoutRepairs->SetSelection(logbookPlugIn->opt->repairsGridLayoutChoice);
	  this->m_radioBtnHTMLRepairs->SetValue(true);
	}
	else
	{
	  m_choiceSelectLayoutRepairs->SetSelection(logbookPlugIn->opt->repairsGridLayoutChoiceODT);
	  this->m_radioBtnODTRepairs->SetValue(true);
	}
	
	if(logbookPlugIn->opt->buypartsHTML)
	{
	  m_choiceSelectLayoutBuyParts->SetSelection(logbookPlugIn->opt->buypartsGridLayoutChoice);
	  this->m_radioBtnHTMLBuyParts->SetValue(true);
	}
	else
	{
	  m_choiceSelectLayoutBuyParts->SetSelection(logbookPlugIn->opt->buypartsGridLayoutChoiceODT);	
	  this->m_radioBtnODTBuyParts->SetValue(true);
	}

	if(!logbookPlugIn->opt->overviewAll)
		this->m_radioBtnActuellLogbook->SetValue(true);
	else
		this->m_radioBtnAllLogbooks->SetValue(true);

	numPages = m_notebook8->GetPageCount();

	for(int i = 0; i < LOGGRIDS; i ++)
	{
		logGrids[i]->SetDefaultEditor(new wxGridCellAutoWrapStringEditor);
		totalColumns += logGrids[i]->GetNumberCols();
	}

	wxStandardPathsBase& std_path = wxStandardPathsBase::Get();
#ifdef __WXMSW__
	wxString stdPath  = std_path.GetConfigDir();
#endif
#ifdef __WXGTK__
	wxString stdPath  = std_path.GetUserDataDir();
#endif
#ifdef __WXOSX__
	wxString stdPath  = std_path.GetUserConfigDir();   // should be ~/Library/Preferences	
#endif


	pHome_Locn = new wxString();
	pHome_Locn->Append(stdPath);
	appendOSDirSlash(pHome_Locn) ;

	pHome_Locn->append(_T("plugins"));
	appendOSDirSlash(pHome_Locn);

	pHome_Locn->Append(_T("logbook"));
	appendOSDirSlash(pHome_Locn);
	if(!wxDir::Exists(*pHome_Locn))
		wxMkdir(*pHome_Locn);

	wxString data = *pHome_Locn;
	data.Append(_T("data"));
	appendOSDirSlash(&data) ;
	if(!wxDir::Exists(data))
		wxMkdir(data);

	image_locn = data;
	image_locn.append(_T("Images"));
	appendOSDirSlash(&image_locn);
	if(!wxDir::Exists(image_locn))
		wxMkdir(image_locn);

	layoutHTML = data;
	layoutHTML.append(_T("HTMLLayouts"));
	appendOSDirSlash(&layoutHTML);

	layoutODT = data;
	layoutODT.append(_T("ODTLayouts"));
	appendOSDirSlash(&layoutODT);

	lastRowSelectedRepairs = 0;
	lastRowSelectedBuyParts = 0;

	logbook     = new Logbook    (this,data,layoutHTML,layoutODT);
	logbook->loadData();

	overview    = new OverView   (this,data,layoutHTML,layoutODT);
	crewList    = new CrewList   (this,data,layoutHTML,layoutODT);
	boat        = new Boat       (this,data,layoutHTML,layoutODT);

	maintenance = new Maintenance(this,data,layoutHTML,layoutODT);
	maintenance->loadData();

	m_gridGlobal->SetColMinimalAcceptableWidth(0);
	m_gridWeather->SetColMinimalAcceptableWidth(0);
	m_gridMotorSails->SetColMinimalAcceptableWidth(0);

	m_gridOverview->SetColMinimalAcceptableWidth(0);

	m_gridCrew->SetColMinimalAcceptableWidth(0);
	m_gridCrewWake->SetColMinimalAcceptableWidth(0);

	m_gridCrew->SetRowMinimalAcceptableHeight(0);

	m_gridOverview->SetColMinimalWidth(OverView::FPATH,0);
	m_gridOverview->SetColSize(OverView::FPATH,0);

	m_logbook->SetSelection(0);
	m_notebook8->SetSelection(0);

	m_gridGlobal->SetGridCursor(0,0);
	m_gridWeather->SetGridCursor(0,0);
	m_gridMotorSails->SetGridCursor(0,0);

	getIniValues();

	GPSTimer = new wxTimer(this,ID_GPSTIMER);
	this->Connect( wxEVT_TIMER, wxObjectEventFunction( &LogbookDialog::OnTimerGPS ));
	GPSTimer->Start(GPSTIMEOUT);

	logbookTimer = new wxTimer(this,ID_LOGTIMER);
	this->Connect( wxEVT_TIMER, wxObjectEventFunction( &LogbookDialog::OnLogTimer ));
	logbookTimer->Start(LOGSAVETIME);

	logbookPlugIn->GetOriginalColors();

	coldfinger = new ColdFinger(this);
	coldfinger->Show(false);

	crewList->filterCrewMembers();

#ifdef PBVE_DEBUG
	if(PBVE_DEBUG)
	{
		logbook->pvbe = new PBVEDialog(this);
		logbook->pvbe->Show();
	}
#endif



#ifndef __WXMSW__  // wxWidgets won't set buttonwidth in Linux like in windows
	m_buttonEditLayout->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayout->SetMinSize( wxSize( 25,-1 ) );
	m_buttonEditLayoutOview->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayoutOview->SetMinSize( wxSize( 25,-1 ) );
	m_buttonEditLayoutCrew->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadCrew->SetMinSize( wxSize( 25,-1 ) );	
	
	m_buttonEditLayoutBoat->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayoutsBoat->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayoutsServiceHTML->SetMinSize( wxSize( 25,-1 ) );
	m_buttonEditLayoutODTService->SetMinSize( wxSize( 25,-1 ) );
	m_buttonEditLayoutODTRepairs->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayoutsRepairsHTML->SetMinSize( wxSize( 25,-1 ) );
	m_buttonEditLayoutODTBuyParts->SetMinSize( wxSize( 25,-1 ) );
	m_buttonReloadLayoutsBuyPartsHTML->SetMinSize( wxSize( 25,-1 ) );
	
#endif
}

void LogbookDialog::OnLogTimer(wxTimerEvent& ev)
{
	static int maintenance_timer = 0;

	int id = ev.GetId();
	if(id == ID_GPSTIMER)
		OnTimerGPS(ev);
	else
	{
		maintenance_timer++;
		logbook->update();			// save Data every 10 Minutes, if modified
		if(maintenance_timer == 6) // = once per hour
		{
			maintenance->checkService(m_gridGlobal->GetNumberRows()-1);
			maintenance_timer = 0;
		}
	}
}

void LogbookDialog::m_menuItem1OnMenuSelection( wxCommandEvent& ev )
{
	logbook->modified = true;

	if(ev.GetId() == DELETE_ROW)
	{
		logbook->deleteRow(selGridRow);
		logbook->modified = true;
		selGridRow--;
		if(selGridRow < 0) selGridRow = 0;
	}
	else if(ev.GetId() == COLDFINGER)
	{
		coldfinger->ShowModal();
		if(!coldfinger->IsModal() && coldfinger->retItem != NULL)
		{
			myTreeItem* item = coldfinger->retItem;
			m_notebook8->SetSelection(item->grid);
			//wxMessageBox(item->text);
			wxString insert = logGrids[item->grid]->GetCellValue(selGridRow,item->gridcol);

			logGrids[item->grid]->SetCellValue(insert+((insert.Length() == 0)?_T(""):_T("\n"))+item->text,selGridRow,item->gridcol);

			logGrids[item->grid]->SetFocus();
			logGrids[item->grid]->SetGridCursor(selGridRow,item->gridcol);
			setEqualRowHeight(selGridRow);
		}
		
	}
	else if(ev.GetId() == SELECT_ROUTE)
	{
		RouteDialog *dlg = new RouteDialog(this);
		wxListItem itemCol;
		itemCol.SetText(_("Route"));
		itemCol.SetImage(-1);
		itemCol.SetWidth(225);
		dlg->m_listCtrlRoute->InsertColumn(0, itemCol);

		wxStandardPathsBase& std_path = wxStandardPathsBase::Get();
#ifdef __WXMSW__
	wxString stdPath  = std_path.GetConfigDir();
#elif defined __WXGTK__
	wxString stdPath  = std_path.GetUserDataDir();	
#elif defined __WXOSX__
	wxString stdPath  = std_path.GetUserConfigDir();
#endif
		wxString path = stdPath + wxFileName::GetPathSeparator() + _T("navobj.xml");

		wxString g,temp;
		int n = 0;

		for(int i = 0; i < 2; i++)
		{
			if(i == 1)
			{
				path = stdPath + wxFileName::GetPathSeparator() + _T("navobj.xml.changes");
				if(!wxFile::Exists(path)) break;
			}
			wxFileInputStream in(path);
			wxTextInputStream xml(in);
			while(!in.Eof())
			{
				temp = xml.ReadLine();
				if(temp.Contains(_T("<rte>")))
				{
					temp = xml.ReadLine();
					if(temp.Contains(_T("<name>")))
					{
						temp = temp.AfterFirst('>');
						g = temp.BeforeFirst('<');
						if(i == 1)
						{
							for(int z = 0; z < 6; z++)
								temp = xml.ReadLine();
							if(temp.Contains(_T("<opencpn:action>delete")))
								dlg->m_listCtrlRoute->DeleteItem(dlg->m_listCtrlRoute->FindItem(0,g));
							else
								dlg->m_listCtrlRoute->InsertItem(n++,g);

						}
						else
							dlg->m_listCtrlRoute->InsertItem(n++,g);
					}
					//else if(temp.Contains(_T("<extensions>")))
						//dlg->m_listCtrlRoute->InsertItem(n++,_("Unnamed Route"));
				}
			}
		}

		if(dlg->ShowModal() == wxID_OK)
		{
			int selIndex = -1;
			for(;;)
			{
				selIndex = dlg->m_listCtrlRoute->GetNextItem(selIndex,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
				if(selIndex != -1) break;
				else
				{
					delete dlg;
					return;
				}
			}
			m_gridGlobal->SetCellValue(selGridRow,0,dlg->m_listCtrlRoute->GetItemText(selIndex));
			logbook->modified = true;
		}
		delete dlg;
	}
	else if(selGridCol == Logbook::WAKE && this->m_notebook8->GetSelection() == 0)
	{
		wxString s = logGrids[m_notebook8->GetSelection()]->GetCellValue(selGridRow,selGridCol);
		logGrids[m_notebook8->GetSelection()]->SetCellValue(
		selGridRow,selGridCol,
		(s.IsEmpty()) 
		? m_menu1->GetLabelText(ev.GetId())
		: s + _T("\n") + m_menu1->GetLabelText(ev.GetId())
		);
		setEqualRowHeight(selGridRow);
		logGrids[m_notebook8->GetSelection()]->Refresh();
	}
	else if((selGridCol == Logbook::REMARKS                        && m_notebook8->GetSelection() == 0) ||
			(selGridCol == Logbook::WEATHER-   logbook->weatherCol && m_notebook8->GetSelection() == 1) ||
			(selGridCol == Logbook::VISIBILITY-logbook->weatherCol && m_notebook8->GetSelection() == 1) ||
			(selGridCol == Logbook::SAILS-     logbook->sailsCol   && m_notebook8->GetSelection() == 2) ||
			(selGridCol == Logbook::REEF-      logbook->sailsCol   && m_notebook8->GetSelection() == 2) ||
			(selGridCol == Logbook::MREMARKS-  logbook->sailsCol   && m_notebook8->GetSelection() == 2) )
	{
		wxString s = logGrids[m_notebook8->GetSelection()]->GetCellValue(selGridRow,selGridCol);
		wxTreeItemId id = FindMenuItem(m_notebook8->GetSelection(), selGridCol, m_menu1->GetLabelText(ev.GetId()));
		wxString text = ((myTreeItem*)coldfinger->m_treeCtrl3->GetItemData(id))->text;
		int grid = ((myTreeItem*)coldfinger->m_treeCtrl3->GetItemData(id))->grid;

		logGrids[grid]->SetCellValue(selGridRow,selGridCol,s+((s.Length() == 0)?_T(""):_T("\n"))+text);
		logGrids[grid]->SetGridCursor(selGridRow,selGridCol);
	}
	else if(selGridCol == Logbook::CLOUDS-logbook->weatherCol && m_notebook8->GetSelection() == 1)
	{
		logGrids[1]->SetCellValue(selGridRow,Logbook::CLOUDS-logbook->weatherCol,m_menu1->GetLabelText(ev.GetId()));
	}
}

void LogbookDialog::OnMenuSelectionShowHiddenCols(wxCommandEvent &ev)
{
	int selGrid = this->m_notebook8->GetSelection();

	for(int i = 0; i < logGrids[selGrid]->GetNumberCols(); i++)
		if(logGrids[selGrid]->GetColumnWidth(i) == 0)
			logGrids[selGrid]->AutoSizeColumn(i,false);

	logGrids[selGrid]->Refresh();
}

void LogbookDialog::OnMenuSelectionShowHiddenColsOverview(wxCommandEvent &ev)
{
	for(int i = 0; i < m_gridOverview->GetNumberCols()-1; i++)
		if(m_gridOverview->GetColumnWidth(i) == 0)
			m_gridOverview->AutoSizeColumn(i,false);

	m_gridOverview->Refresh();
}

void LogbookDialog::OnNoteBookPageChangedLogbook(wxNotebookEvent & ev)
{
	if(ev.GetEventObject() == this->m_logbook && ev.GetSelection() == 1)
	{      // OverView
		logbook->modified = true;
		logbook->update();
		overview->refresh();
	}
	
	if(ev.GetSelection() == 3)
	{
		if(sashPos == -1)
		{
			this->m_panel72->Fit();
			m_splitter1->SetSashPosition(m_panel72->GetSize().GetY());
		}
	}
	ev.Skip();
}

void LogbookDialog::m_gridGlobalOnGridCellRightClick( wxGridEvent& ev )
{
	wxString sails = _T("");

	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();

	menuItemTimer->Check(logbookPlugIn->opt->timer);

	if(ev.GetCol() == 4 && (m_notebook8->GetSelection() == 0))
	{
		m_menu1->PrependSeparator();
		for(int i = 0; i < m_gridCrewWake->GetNumberRows(); i++)
		{
			wxMenuItem *item = new wxMenuItem( m_menu1, wxID_ANY, 
				m_gridCrewWake->GetCellValue(i,CrewList::LWFIRSTNAME)+_T(" ")+
				m_gridCrewWake->GetCellValue(i,CrewList::LWNAME) , wxEmptyString, wxITEM_NORMAL );
			m_menu1->Prepend( item );
			this->Connect( item->GetId(), wxEVT_COMMAND_MENU_SELECTED, 
				wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );

		}
	}

	if(ev.GetCol() == 0 && (m_notebook8->GetSelection() == 0))
	{
		m_menu1->PrependSeparator();

		wxMenuItem *item = new wxMenuItem( m_menu1, SELECT_ROUTE, 
				_("Select Route"), wxEmptyString, wxITEM_NORMAL );
		m_menu1->Prepend( item );
		this->Connect( item->GetId(), wxEVT_COMMAND_MENU_SELECTED, 
				wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
	}

	if((selGridCol == Logbook::REMARKS                         && m_notebook8->GetSelection() == 0) ||
		(selGridCol == Logbook::WEATHER-   logbook->weatherCol && m_notebook8->GetSelection() == 1) ||
		(selGridCol == Logbook::VISIBILITY-logbook->weatherCol && m_notebook8->GetSelection() == 1) ||
		(selGridCol == Logbook::SAILS-     logbook->sailsCol   && m_notebook8->GetSelection() == 2) ||
		(selGridCol == Logbook::REEF-      logbook->sailsCol   && m_notebook8->GetSelection() == 2) ||
		(selGridCol == Logbook::MREMARKS-  logbook->sailsCol   && m_notebook8->GetSelection() == 2)
	   )
	{
		addColdFingerDialog(m_menu1);
		addColdFingerTextBlocks(m_menu1);
	}

	if(ev.GetCol() == 11 && (m_notebook8->GetSelection() == 1))
	{
		m_menu1->PrependSeparator();
		wxString path = *pHome_Locn;
		path += _T("data") + wxString(wxFileName::GetPathSeparator());
		path +=_T("Clouds") + wxString(wxFileName::GetPathSeparator());

		for(int i = 0; i < 10; i++)
		{
			wxMenu *temp = new wxMenu();
			wxMenuItem *item = new wxMenuItem( temp, wxID_ANY, clouds[i], wxEmptyString,wxITEM_NORMAL);

			const wxBitmap bmp ((path+clouds[i].Lower()+_T(".jpg")), wxBITMAP_TYPE_ANY);
			//bmp.SetWidth(200), bmp.SetHeight(135);
			item->SetBitmap(bmp);
			temp->Append(item);
			m_menu1->Prepend( -1, clouds[i], temp );

			this->Connect( item->GetId(), wxEVT_COMMAND_MENU_SELECTED, 
				wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
		}
	}

	m_gridGlobal->PopupMenu( m_menu1, ev.GetPosition() );

	wxMenuItemList  list = m_menu1->GetMenuItems();

	for(wxMenuItemList::iterator it = list.begin(); it != list.end(); it++)
		{
			wxMenuItem* item = *it;
			int id = (*it)->GetId();

			if(id == MENUTIMER) break;

			m_menu1->Remove( item->GetId() );

			this->Disconnect( id, wxEVT_COMMAND_MENU_SELECTED, 
			wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
		}
}

void LogbookDialog::addColdFingerDialog(wxMenu* m_menu)
{
	m_menu->PrependSeparator();

		wxMenuItem *item = new wxMenuItem( m_menu, COLDFINGER, 
				_("use Textblocks..."), wxEmptyString, wxITEM_NORMAL );
		m_menu1->Prepend( item );
		this->Connect( item->GetId(), wxEVT_COMMAND_MENU_SELECTED, 
				wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
}

void LogbookDialog::addColdFingerTextBlocks(wxMenu* menu)
{
	FindMenuItem(-1,0,wxEmptyString);
	FindMenuItem(m_notebook8->GetSelection(),selGridCol,wxEmptyString);
}

#include <stack>
using namespace std;
wxTreeItemId LogbookDialog::FindMenuItem(int grid, int col, wxString name)
{
	wxTreeCtrl* tree = coldfinger->m_treeCtrl3;
	std::stack<wxTreeItemId> items;
	if (tree->GetRootItem().IsOk())
		items.push(tree->GetRootItem());

	while (!items.empty())
	{
		wxTreeItemId next = items.top();
		items.pop();

		if(grid == -1)
		{
			if (next != tree->GetRootItem() && ((myTreeItem*)tree->GetItemData(next))->grid == -1)
				return next;
		}
		else if(name == wxEmptyString)
		{			
			if (((next != tree->GetRootItem() && ((myTreeItem*)tree->GetItemData(next))->grid == grid)) && ((myTreeItem*)tree->GetItemData(next))->gridcol == col && 
				((myTreeItem*)tree->GetItemData(next))->menu == true)
			{	
				wxTreeItemIdValue cookie;
				next = tree->GetFirstChild(next, cookie);

				while(next.IsOk())
				{
				wxMenuItem *item = new wxMenuItem( m_menu1, wxID_ANY, 
					tree->GetItemText(next), wxEmptyString, wxITEM_NORMAL );
				m_menu1->Prepend( item );
				this->Connect( item->GetId(), wxEVT_COMMAND_MENU_SELECTED, 
					wxCommandEventHandler( LogbookDialog::m_menuItem1OnMenuSelection ) );
			//	wxMessageBox(wxString::Format(_("%i %i %i %i %i"),grid,col,((myTreeItem*)tree->GetItemData(next))->grid,((myTreeItem*)tree->GetItemData(next))->gridcol,((myTreeItem*)tree->GetItemData(next))->menu));
				 next = tree->GetNextSibling(next);
				}

				return  wxTreeItemId();
			}
		}
		else
		{
			if (next != tree->GetRootItem() && tree->GetItemText(next) == name)
				return next;
		}
 
		wxTreeItemIdValue cookie;
		wxTreeItemId nextChild = tree->GetFirstChild(next, cookie);
		while (nextChild.IsOk())
		{
			items.push(nextChild);
			nextChild = tree->GetNextSibling(nextChild);
		}
	}
 
	return wxTreeItemId();
}

void LogbookDialog::m_gridWeatherOnGridCellRightClick( wxGridEvent& ev )
{
	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();
	m_gridGlobalOnGridCellRightClick( ev );
}

void LogbookDialog::m_gridMotorSailsOnGridCellRightClick( wxGridEvent& ev )
{
	for(int i = 0; i < LOGGRIDS; i++)
		logGrids[i]->ClearSelection();

	selGridCol = ev.GetCol();
	selGridRow = ev.GetRow();
	m_gridGlobalOnGridCellRightClick( ev );
}

void LogbookDialog::m_gridGlobalOnGridCmdCellChange( wxGridEvent& ev )
{
	logbook->changeCellValue(ev.GetRow(),ev.GetCol(),0);
}

void LogbookDialog::m_gridWeatherOnGridCmdCellChange( wxGridEvent& ev )
{
	logbook->changeCellValue(ev.GetRow(),ev.GetCol(),0);
}

void LogbookDialog::m_gridMotorSailsOnGridCmdCellChange( wxGridEvent& ev )
{
	logbook->changeCellValue(ev.GetRow(),ev.GetCol(),0);
}

void LogbookDialog::logSaveOnButtonClick( wxCommandEvent& ev )
{
	wxString filter = saveDialogFilter;
	if(m_radioBtnHTML->GetValue())
		filter.Prepend(_T("HTML Format(*.html)|*.html|"));
	else
		filter.Prepend(_T("Opendocument Text(*.odt)|*.odt|"));

	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save Logbook File"), _T(""), _T("Logbook"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTML->GetValue())
				logbook->toHTML(path, 
				logbookChoice->GetString(logbookChoice->GetSelection()),true);
			else
				logbook->toODT(path,
				logbookChoice->GetString(logbookChoice->GetSelection()),true); 
			break;
	case 1:	logbook->toODS(path); break;
	case 2: logbook->toXML(path); break;
	case 3: logbook->toCSV(path); break;
	case 4: logbook->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
}

void LogbookDialog::logViewOnButtonClick( wxCommandEvent& ev )
{
	if(this->m_radioBtnHTML->GetValue())
		logbook->viewHTML(_T(""),logbookChoice->GetString(logbookChoice->GetSelection()),false);
	else
		logbook->viewODT(_T(""),logbookChoice->GetString(logbookChoice->GetSelection()),false);
}

void LogbookDialog::m_button4OnButtonClick( wxCommandEvent& ev )
{
	logbook->appendRow(true);
}

void LogbookDialog::m_TimerOnMenuSelection( wxCommandEvent& ev )
{
	long sec = logbookPlugIn->opt->timerSec;

	while(logbookPlugIn->opt->timerSec <= 0)
	{
		TimerInterval* ti = new TimerInterval(this,this->logbookPlugIn->opt);
#ifdef __WXOSX__
        ::MessageBoxOSX(NULL,_("Timer has 0 h 0 Min 0 sec.\n\nPlease change settings in Options"),_T("Information"),wxID_OK);
#else
		::wxMessageBox(_("Timer has 0 h 0 Min 0 sec.\n\nPlease change settings in Options"),_T(""));
#endif
		ti->ShowModal();
		sec = logbookPlugIn->opt->timerSec;
		delete ti;
	}

	if(ev.IsChecked() && sec > 0 )
	{
		timer->Start(sec);
		logbookPlugIn->opt->timer = true;
		setTitleExt();
		this->SetTitle(this->GetTitle()+ titleExt);
	}
	else 
	{
		timer->Stop();
		logbookPlugIn->opt->timer = false;
		this->SetTitle(logbook->title);
	}
}

void LogbookDialog::OnTimerGPS(wxTimerEvent& ev)
{
	logbook->SetGPSStatus(false);
	logbook->checkGPS(true);
}

void LogbookDialog::onRadioButtonHTML(wxCommandEvent& ev)
{
	logbook->setLayoutLocation(layoutHTML);
	logbookPlugIn->opt->navHTML = true;
}

void LogbookDialog::onRadioButtonODT(wxCommandEvent &ev)
{
	logbook->setLayoutLocation(layoutODT);
	logbookPlugIn->opt->navHTML = false;	
}

void LogbookDialog::LogbookDialogOnClose( wxCloseEvent& ev )
{
	this->Hide();
}

void LogbookDialog::OnMenuSelectionTimerInterval( wxCommandEvent& event )
{
	TimerInterval* ti = new TimerInterval(this,logbookPlugIn->opt);
	ti->ShowModal();
	delete ti;
}

void LogbookDialog::loadLayoutChoice(wxString path, wxChoice* choice)
{
	wxArrayString files;
	int i = wxDir::GetAllFiles(path,&files);
	choice->Clear();

	for(int n = 0; n < i; n++)
	{
		if(wxFileName(files[n]).GetExt().Upper() != _T("ODT") && wxFileName(files[n]).GetExt().Upper() != _T("HTML")) continue;

		if(this->logbookPlugIn->opt->filterLayout)
		{
			if(wxFileName(files[n]).GetName().Contains(logbookPlugIn->opt->layoutPrefix))
				choice->Append(wxFileName(files[n]).GetName());
		}
		else
			choice->Append(wxFileName(files[n]).GetName());
	}
	choice->SetSelection(0);
}


void LogbookDialog::setEqualRowHeight(int row)
{
	  int max = 0, height;

      for(int i = 0; i < LOGGRIDS; i++)
      {
		int count = logGrids[i]->GetNumberRows();
		if(count <= 0) return;

		logGrids[i]->AutoSizeRow(row,false);	
		height = logGrids[i]->GetRowHeight(row);

		if( height > max)
			  max = height;
      }

      for(int i = 0; i < LOGGRIDS; i++)
      {
		 logGrids[i]->SetRowHeight(row,max);
      }
}

void LogbookDialog::appendOSDirSlash(wxString* pString)
{
	wxChar sep = wxFileName::GetPathSeparator();

	if (pString->Last() != sep)
		pString->Append(sep);
}

wxString LogbookDialog::replaceDangerChar(wxString s)
{
	s.Replace(wxT("\n"),wxT("\\n"));
	return s;
}

wxString LogbookDialog::restoreDangerChar(wxString s)
{
	s.Replace(wxT("\\n"),wxT("\n"));
	return s;
}

void LogbookDialog::startBrowser(wxString filename)
{
  if(wxGetOsVersion() & wxOS_WINDOWS)
  {
	filename.Replace(wxT("/"),wxT("\\"));

	wxFileType *filetype = wxTheMimeTypesManager->GetFileTypeFromExtension(_T("html"));
	wxString cmd = filetype->GetOpenCommand(wxT("file:///")+filename);

	if(cmd.Contains(wxT("IEXPLORE")))
		wxExecute(wxString::Format(wxT("explorer.exe ")+filename));
	else
		wxExecute(cmd);
  }
  else
    wxLaunchDefaultBrowser(wxString(_T("file:///"))+filename);
}

void LogbookDialog::startApplication(wxString filename, wxString ext)
{

	if(ext == _T(".odt"))
	{
		 wxString command = logbookPlugIn->opt->odtEditor +  _T(" \"") +filename + _T("\"");

#ifdef __WXOSX__
		command = _T("/bin/bash -c \"open ")+filename+_T("\"");
//		MessageBoxOSX(this,command,_T("Information"),wxID_OK|wxID_NO|wxID_CANCEL);
#endif
		wxExecute(command);		
	}
	else
	{
		if(!logbookPlugIn->opt->htmlEditor.IsEmpty())
			wxExecute(wxString::Format(wxT("%s \"%s\" "),logbookPlugIn->opt->htmlEditor.c_str(),filename.c_str()));
		else
#ifdef __WXOSX__
            MessageBoxOSX(NULL,_("No Path set to HTML-Editor\nin Toolbox/Plugins/LogbookKonni/Preferences"),_T("Information"),wxID_OK);
#else
			wxMessageBox(_("No Path set to HTML-Editor\nin ToolBox/Plugins/LogbookKonni/Preferences"));
#endif
	}
}

void LogbookDialog::setIniValues()
{
	Options * opt = logbookPlugIn->opt;

	opt->NavColWidth.Clear();
	opt->WeatherColWidth.Clear();
	opt->MotorColWidth.Clear();
	opt->CrewColWidth.Clear();
	opt->WakeColWidth.Clear();
	opt->EquipColWidth.Clear();
	opt->ServiceColWidth.Clear();
	opt->RepairsColWidth.Clear();
	opt->BuyPartsColWidth.Clear();
	opt->OverviewColWidth.Clear();

	opt->navGridLayoutChoice = logbookChoice->GetSelection();
	opt->crewGridLayoutChoice = crewChoice->GetSelection();
	opt->boatGridLayoutChoice = boatChoice->GetSelection();

	for(int i = 0; i < LOGGRIDS; i++)
	{
		for(int n = 0; n < logGrids[i]->GetNumberCols(); n++)
		{
			switch(i)
			{
			case 0:	opt->NavColWidth.Add(logGrids[i]->GetColumnWidth(n)); break;
			case 1: opt->WeatherColWidth.Add(logGrids[i]->GetColumnWidth(n)); break;
			case 2: opt->MotorColWidth.Add(logGrids[i]->GetColumnWidth(n)); break;
			}
		}
	}

	for(int n = 0; n < m_gridCrew->GetNumberCols(); n++)
		opt->CrewColWidth.Add(m_gridCrew->GetColumnWidth(n));
	for(int n = 0; n < m_gridCrewWake->GetNumberCols(); n++)
		opt->WakeColWidth.Add(m_gridCrewWake->GetColumnWidth(n));
	for(int n = 0; n < m_gridEquipment->GetNumberCols(); n++)
		opt->EquipColWidth.Add(m_gridEquipment->GetColumnWidth(n));

	for(int n = 0; n < m_gridMaintanence->GetNumberCols(); n++)
		opt->ServiceColWidth.Add(m_gridMaintanence->GetColumnWidth(n));
	for(int n = 0; n < m_gridMaintanenceRepairs->GetNumberCols(); n++)
		opt->RepairsColWidth.Add(m_gridMaintanenceRepairs->GetColumnWidth(n));
	for(int n = 0; n < m_gridMaintenanceBuyParts->GetNumberCols(); n++)
		opt->BuyPartsColWidth.Add(m_gridMaintenanceBuyParts->GetColumnWidth(n));

	for(int n = 0; n < m_gridOverview->GetNumberCols(); n++)
		opt->OverviewColWidth.Add(m_gridOverview->GetColumnWidth(n));
}

void LogbookDialog::getIniValues()
{
	Options * opt = logbookPlugIn->opt;
	unsigned int colCount[3];
	colCount[0] = opt->NavColWidth.Count();
	colCount[1] = opt->WeatherColWidth.Count();
	colCount[2] = opt->MotorColWidth.Count();

	if((opt->navGridLayoutChoice == -1) || (opt->NavColWidth.GetCount() == 0)) return;

	for(int i = 0; i < LOGGRIDS; i++)
	{
		for(unsigned int n = 0; n < (unsigned int) logGrids[i]->GetNumberCols(); n++)
		{
			if(n >= colCount[i]) break;

			switch(i)
			{
			case 0:	logGrids[i]->SetColumnWidth(n,opt->NavColWidth[n]); 
				break;
			case 1: logGrids[i]->SetColumnWidth(n,opt->WeatherColWidth[n]); 
				break;
			case 2: 
				logGrids[i]->SetColumnWidth(n,opt->MotorColWidth[n]); 
				break;
			}
		}
	}

	for(int n = 0; n < m_gridCrew->GetNumberCols(); n++)
		m_gridCrew->SetColumnWidth(n,opt->CrewColWidth[n]);
	for(int n = 0; n < m_gridCrewWake->GetNumberCols(); n++)
		m_gridCrewWake->SetColumnWidth(n,opt->WakeColWidth[n]);
	for(int n = 0; n < m_gridEquipment->GetNumberCols(); n++)
		m_gridEquipment->SetColumnWidth(n,opt->EquipColWidth[n]);

	if(opt->OverviewColWidth[0] != -1 )
	{
		for(int n = 0; n < m_gridOverview->GetNumberCols(); n++)
			m_gridOverview->SetColumnWidth(n,opt->OverviewColWidth[n]);
	}

	if(opt->ServiceColWidth[0] != -1 )
	{
		for(int n = 0; n < m_gridMaintanence->GetNumberCols(); n++)
			m_gridMaintanence->SetColumnWidth(n,opt->ServiceColWidth[n]);
	}

	if(opt->RepairsColWidth[0] != -1 )
	{
		for(int n = 0; n < m_gridMaintanenceRepairs->GetNumberCols(); n++)
			m_gridMaintanenceRepairs->SetColumnWidth(n,opt->RepairsColWidth[n]);
	}

	if(opt->BuyPartsColWidth[0] != -1 )
	{
		for(int n = 0; n < m_gridMaintenanceBuyParts->GetNumberCols(); n++)
			m_gridMaintenanceBuyParts->SetColumnWidth(n,opt->BuyPartsColWidth[n]);
	}
}

void LogbookDialog::sortGrid(wxGrid* grid, int col, bool ascending)
{
	bool sort = false;
	crewList->showAllCrewMembers();

	myGridStringTable* data = (myGridStringTable*)grid->GetTable();

	wxGridStringArray arr = data->m_data;
	if(arr.Count() < 2) return;

	wxGridStringArray temp;

	temp .Add(arr[0]);
	int i;
	do{
		sort = false;
		i = 0;
		do
		{
			if(ascending) 
			{
				if((arr[i][col] > arr[i+1][col]))
				{
					temp[0] = arr[i];
					arr[i]  = arr[i+1];
					arr[i+1]  = temp[0];
					sort = true;
				}
			}
			else
			{
				if((arr[i+1][col] > arr[i][col]))
				{
					temp[0] = arr[i];
					arr[i]  = arr[i+1];
					arr[i+1]  = temp[0];
					sort = true;
				}
			}
			i++;
		}while(i < grid->GetNumberRows()-1);
	}while(sort);

	data->m_data = arr;

	if(m_menu2->IsChecked(MENUCREWONBOARD))
		crewList->filterCrewMembers();
	else
		grid->ForceRefresh();
}

//////////////////////////////////////////////////////////
//				CrewList Events
//////////////////////////////////////////////////////////

void LogbookDialog::crewAddOnButtonClick( wxCommandEvent& ev )
{
	crewList->addCrew(m_gridCrew,m_gridCrewWake);
}

void LogbookDialog::OnGridCellRightClickWake( wxGridEvent& event )
{
    m_gridCrewWake->SetGridCursor(event.GetRow(),event.GetCol());
    m_gridCrewWake->PopupMenu(m_menu21);
}

void LogbookDialog::OnMenuSelectionAsc( wxCommandEvent& event )
{
	int col;

	//row = m_gridCrew->GetGridCursorRow();
	col = m_gridCrew->GetGridCursorCol();

	sortGrid(m_gridCrew,col,true);
}

void LogbookDialog::OnMenuSelectionDesc( wxCommandEvent& event )
{
	int col;

//	row = m_gridCrew->GetGridCursorRow();
	col = m_gridCrew->GetGridCursorCol();

	sortGrid(m_gridCrew,col,false);
}

void LogbookDialog::OnGridLabelLeftDClickCrew( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	int count = 0;

	for(int i = 0; i < m_gridCrew->GetNumberCols() && count < 2; i++)
		if(m_gridCrew->GetColumnWidth(i) > 0)
			count++;

	if(count < 2) return;

	m_gridCrew->SetColumnWidth(ev.GetCol(),0);
	m_gridCrew->Refresh();
}

void LogbookDialog::OnGridLabelLeftDClickCrewWake( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	int count = 0;

	for(int i = 0; i < m_gridCrewWake->GetNumberCols() && count < 2; i++)
		if(m_gridCrewWake->GetColumnWidth(i) > 0)
			count++;

	if(count < 2) return;
	m_gridCrewWake->SetColumnWidth(ev.GetCol(),0);
	m_gridCrewWake->Refresh();
}

void LogbookDialog::OnMenuSelectionHiddenCrew( wxCommandEvent& event )
{
	for(int i = 0; i < m_gridCrew->GetNumberCols(); i++)
		if(m_gridCrew->GetColumnWidth(i) == 0)
			m_gridCrew->AutoSizeColumn(i,false);

	m_gridCrew->Refresh();
}

void LogbookDialog::OnMenuSelectionHiddenWake( wxCommandEvent& event )
{
	for(int i = 0; i < m_gridCrewWake->GetNumberCols(); i++)
		if(m_gridCrewWake->GetColumnWidth(i) == 0)
			m_gridCrewWake->AutoSizeColumn(i,false);

	m_gridCrewWake->Refresh();
}

void LogbookDialog::OnGridEditorShownCrew( wxGridEvent& ev )
{
	if(!this->IsShown()) return;

	selGridRow = ev.GetRow();
	selGridCol = ev.GetCol();

	crewList->lastSelectedName      = m_gridCrew->GetCellValue(ev.GetRow(),CrewList::NAME); 
	crewList->lastSelectedFirstName = m_gridCrew->GetCellValue(ev.GetRow(),CrewList::FIRSTNAME); 

	ev.Skip();
}

void LogbookDialog::m_menuItem19MenuSelection( wxCommandEvent& event )
{
    crewList->showAutomaticWatchDlg();
}

void LogbookDialog::m_menuItem21MenuSelection( wxCommandEvent& event )
{
	int row = m_gridCrewWake->GetGridCursorRow();
	m_gridCrewWake->DeleteRows(row);
	crewList->modified = true;    
}

void LogbookDialog::OnMenuSelectionSameWatch( wxCommandEvent& event )
{
	crewList->SameWatchAsDlg(m_gridCrew->GetGridCursorRow());	
}

void LogbookDialog::OnMenuSelectionAddWatch( wxCommandEvent& event )
{
	crewList->addToWatchList();
}

void LogbookDialog::crewSaveOnButtonClick( wxCommandEvent& ev )
{
	wxString filter = saveDialogFilter;
	if(m_radioBtnHTMLCrew->GetValue())
		filter.Prepend(_T("HTML Format(*.html)|*.html|"));
	else
		filter.Prepend(_T("Opendocument Text(*.odt)|*.odt|"));

	filter.Replace(_T("Logbook"),_T("CrewList"));
	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save CrewList File"), _T(""), _T("CrewList"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLCrew->GetValue())
				crewList->saveHTML(path,
				crewChoice->GetString(crewChoice->GetSelection()),false); 
			else
				crewList->saveODT(path,
				crewChoice->GetString(crewChoice->GetSelection()),true); 
			break;
	case 1: crewList->saveODS(path); break;
	case 2:	crewList->saveXML(path); break;
	case 3: crewList->saveCSV(path); break;
	case 4: crewList->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
}

void LogbookDialog::crewViewOnButtonClick( wxCommandEvent& ev )
{
	if(this->m_radioBtnHTMLCrew->GetValue())
		crewList->viewHTML(_T(""),crewChoice->GetString(crewChoice->GetSelection()));
	else
		crewList->viewODT(_T(""),crewChoice->GetString(crewChoice->GetSelection()));
}

void LogbookDialog::onButtonClickReloadLayoutsCrew(wxCommandEvent &ev)
{
	loadLayoutChoice(crewList->layout_locn,crewChoice);
}

void LogbookDialog::onButtonClickEditLayoutCrew(wxCommandEvent &ev)
{
	int format;

	if(m_radioBtnODTCrew->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(crewChoice,crewList->layout_locn, format);
}

void LogbookDialog::onRadioButtonHTMLCrew(wxCommandEvent &ev)
{
	crewList->setLayoutLocation(layoutHTML);
	logbookPlugIn->opt->crewHTML = true;
}

void LogbookDialog::onRadioButtonODTCrew(wxCommandEvent &ev)
{
	crewList->setLayoutLocation(layoutODT);
	logbookPlugIn->opt->crewHTML = false;
}

void LogbookDialog::m_gridCrewOnGridCellChange( wxGridEvent& ev )
{
	crewList->changeCrew(m_gridCrew,ev.GetRow(),ev.GetCol(),0);
}

void LogbookDialog::m_gridCrewWakeOnGridCellChange( wxGridEvent& ev )
{
	crewList->changeCrewWake(m_gridCrewWake,ev.GetRow(),ev.GetCol(),2);
}

void LogbookDialog::m_gridCrewOnGridCellRightClick( wxGridEvent& ev )
{
	selGridRow = ev.GetRow();
	selGridCol = ev.GetCol();

	crewList->lastSelectedName      = m_gridCrew->GetCellValue(selGridRow,CrewList::NAME); 
	crewList->lastSelectedFirstName = m_gridCrew->GetCellValue(selGridRow,CrewList::FIRSTNAME); 

	m_gridCrew->SetGridCursor(selGridRow,selGridCol);
	m_gridCrew->PopupMenu( m_menu2, ev.GetPosition() );
}

void LogbookDialog::m_menuItem2OnMenuSelection( wxCommandEvent& ev )
{
	crewList->deleteRow(selGridRow);
	crewList->modified = true;

	if(m_menu2->IsChecked(MENUCREWONBOARD))
		crewList->filterCrewMembers();
}

void LogbookDialog::OnKeyDownCrew( wxKeyEvent& ev )
{
	int offset;
	int col = m_gridCrew->GetGridCursorCol();
	int row = m_gridCrew->GetGridCursorRow();

	if((ev.GetKeyCode() != WXK_TAB) || (ev.ShiftDown() && ev.GetKeyCode() != WXK_TAB)) 
		{ ev.Skip(); return; }

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_LEFT))
			offset = -1; 

	if ((!ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_RIGHT))
			offset = 1; 

	while((col+offset < m_gridCrew->GetNumberCols()-1) && (col+offset > 0))
	{
		if(m_gridCrew->GetColSize(col+offset) == 0)
			col += offset;
		else
			break;
	}

	if(col+offset == 0 && m_gridCrew->GetColSize(0) == 0)
		col = m_gridCrew->GetNumberCols()-1;
	if((col+offset == m_gridCrew->GetNumberCols()-1) && (m_gridCrew->GetColSize(col+offset) == 0))
		col = 0;
	m_gridCrew->SetGridCursor(row,col);
	ev.Skip();
}

void LogbookDialog::OnKeyDownWatch( wxKeyEvent& ev )
{
	int offset;
	int col = m_gridCrewWake->GetGridCursorCol();
	int row = m_gridCrewWake->GetGridCursorRow();

	if((ev.GetKeyCode() != WXK_TAB) || (ev.ShiftDown() && ev.GetKeyCode() != WXK_TAB)) 
		{ ev.Skip(); return; }

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_LEFT))
			offset = -1; 

	if ((!ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_RIGHT))
			offset = 1; 

	while((col+offset < m_gridCrewWake->GetNumberCols()-1) && (col+offset > 0))
	{
		if(m_gridCrewWake->GetColSize(col+offset) == 0)
			col += offset;
		else
			break;
	}

	if(col+offset == 0 && m_gridCrewWake->GetColSize(0) == 0)
		col = m_gridCrewWake->GetNumberCols()-1;
	if((col+offset == m_gridCrewWake->GetNumberCols()-1) && (m_gridCrewWake->GetColSize(col+offset) == 0))
		col = 0;
	m_gridCrewWake->SetGridCursor(row,col);
	ev.Skip();
}

/////////////////////////////////////////////////////////////
//				Boat Events
/////////////////////////////////////////////////////////////

void LogbookDialog::boataddEquipmentButtonOnButtonClick( wxCommandEvent& ev )
{
	this->m_toggleBtnShowEquipment->SetValue(true);
    OnToggleButtonShowEquip(ev);
	boat->addEquip();
}

void LogbookDialog::OnToggleButtonShowEquip(wxCommandEvent& ev)
{
	if(m_toggleBtnShowEquipment->GetValue())
	{
		m_toggleBtnShowEquipment->SetLabel(_("Hide Equipment"));
		m_toggleBtnShowEquipment->Refresh();
		if(m_splitter1->GetSashPosition() != 100)
			sashPos = m_panel72->GetSize().GetY();
		m_splitter1->SetSashPosition(100);
	}
	else
	{
		m_toggleBtnShowEquipment->SetLabel(_("Show Equipment"));
		m_toggleBtnShowEquipment->Refresh();
	    m_splitter1->SetSashPosition(sashPos);
	}
}

void LogbookDialog::boatSaveOnButtonClick( wxCommandEvent& ev )
{
	wxString filter = saveDialogFilter;
	if(m_radioBtnHTMLBoat->GetValue())
		filter.Prepend(_T("HTML Format(*.html)|*.html|"));
	else
		filter.Prepend(_T("Opendocument Text(*.odt)|*.odt|"));
	filter.Replace(_T("Logbook"),_T("Boat"));
	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save Boat File"), _T(""), _T("Boat"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLBoat->GetValue())
				boat->toHTML(path,
				boatChoice->GetString(boatChoice->GetSelection()), true); 
			else
				boat->toODT(path,
				boatChoice->GetString(boatChoice->GetSelection()), true); 
		break;
	case 1: boat->toODS(path); break;
	case 2:	boat->toXML(path); break;
	case 3: boat->toCSV(path); break;
	case 4: boat->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
}

void LogbookDialog::boatViewOnButtonClick( wxCommandEvent& ev )
{
	if(this->m_radioBtnHTMLBoat->GetValue())
		boat->viewHTML(_T(""),boatChoice->GetString(boatChoice->GetSelection()),false);
	else
		boat->viewODT(_T(""),boatChoice->GetString(boatChoice->GetSelection()),false);
}

void LogbookDialog::onButtonClickReloadLayoutsBoat(wxCommandEvent & ev)
{
	loadLayoutChoice(boat->layout_locn,boatChoice);
}

void LogbookDialog::onButtonClickEditLayoutBoat(wxCommandEvent &ev)
{
	int format;

	if(m_radioBtnODTBoat->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(boatChoice,boat->layout_locn, format);
}

void LogbookDialog::onRadioButtonHTMLBoat(wxCommandEvent &ev)
{
	boat->setLayoutLocation(layoutHTML);
	logbookPlugIn->opt->boatHTML = true;
}

void LogbookDialog::onRadioButtonODTBoat(wxCommandEvent &ev)
{
	boat->setLayoutLocation(layoutODT);
	logbookPlugIn->opt->boatHTML = false;
}

void LogbookDialog::m_gridEquipmentOnGridCellChange( wxGridEvent& ev )
{
	boat->cellChanged(ev.GetRow(),ev.GetCol());
}

void LogbookDialog::m_gridEquipmentOnGridCellRightClick( wxGridEvent& ev )
{
	selGridRow = ev.GetRow();
	selGridCol = ev.GetCol();

	m_gridEquipment->PopupMenu( m_menu3, ev.GetPosition() ); 
}

void LogbookDialog::boatNameOnTextEnter( wxCommandEvent& ev )
{
	//((wxTextCtrl*)ev.GetEventObject())->Navigate();
	boat->modified = true;
	ev.Skip();
}

void LogbookDialog::m_menuItem3OnMenuSelection( wxCommandEvent& ev )
{
	boat->deleteRow(selGridRow);
	boat->modified = true;
}

void LogbookDialog::OnMenuSelectionOnboardCrew( wxCommandEvent& event )
{
	m_menu2->Check(MENUCREWONBOARD,true);
	m_menu2->Check(MENUCREWALL,false);
	crewList->filterCrewMembers();
}

void LogbookDialog::OnMenuSelectionAllEntriesCrew( wxCommandEvent& event )
{
	m_menu2->Check(MENUCREWALL,true);
	m_menu2->Check(MENUCREWONBOARD,false);
	crewList->showAllCrewMembers();
}

wxDateTime LogbookDialog::getDateTo(wxString filename)
{
	wxDateTime dt;
	dt = dt.Now();
	wxString from, to, token, year, month, day;
	long tday;
	long tmonth;
	long tyear;

	to = filename.substr(filename.find_first_of('_')+1);
	to = to.substr(0,to.find_first_of('_')+1);
	to = to.RemoveLast();
	wxStringTokenizer tkz(to,_T("-"));
	year = tkz.GetNextToken();
	month = tkz.GetNextToken();
	day = tkz.GetNextToken();
	day.ToLong(&tday);
	month.ToLong(&tmonth);
	year.ToLong(&tyear);
	dt.SetYear((int)tyear);
	dt.SetMonth((wxDateTime::Month)(tmonth-1));
	dt.SetDay((int)tday);

	return dt;
}

////////////////////////////////////////////////////////////
//	 Maintenance
////////////////////////////////////////////////////////////
void LogbookDialog::onButtobClickAddLineService(wxCommandEvent &ev)
{
	maintenance->addLine();
}

void LogbookDialog::OnGridLabelLeftClickService( wxGridEvent& event )
{
	int row, col;
	row = event.GetRow();
	col = event.GetCol();

	this->m_gridMaintanence->SetFocus();

	if(row != -1 || (row == -1 && col == -1)) { event.Skip(); return; }

	this->m_gridMaintanence->SetGridCursor(0,col);
	static bool ascending = true;
	this->sortGrid(this->m_gridMaintanence,event.GetCol(),ascending);
	ascending = !ascending;

	maintenance->checkService(m_gridGlobal->GetNumberRows()-1);
}

void LogbookDialog::onButtobClickSaveService(wxCommandEvent & ev)
{
	wxString filter = _T("");
	if(m_radioBtnHTMLService->GetValue())
		filter = _T("HTML Format(*.html)|*.html");
	else
		filter = _T("Opendocument Text(*.odt)|*.odt");

	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save Service File"), _T(""), _T("Service"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLService->GetValue())
				maintenance->toHTML(0,path, 
				m_choiceSelectLayoutService->GetString(m_choiceSelectLayoutService->GetSelection()),2);
			else
				maintenance->toODT(0,path,
				m_choiceSelectLayoutService->GetString(m_choiceSelectLayoutService->GetSelection()),2); 
			break;
//	case 1:	overview->toODS(path); break;
//	case 2: overview->toXML(path); break;
//	case 3: overview->toCSV(path); break;
//	case 4: overview->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
	delete saveFileDialog;
}

void LogbookDialog::onButtonClickReloadLayoutsServiceHTML(wxCommandEvent &ev)
{
	maintenance->setLayoutLocation();
}

void LogbookDialog::onGridCellLeftClickService(wxGridEvent &ev)
{
	if((ev.GetCol() == maintenance->WARN || ev.GetCol() == maintenance->URGENT) && 
		m_gridMaintanence->GetCellValue(ev.GetRow(), maintenance->IF) == maintenance->m_choices[8])
	{
		 maintenance->showDateDialog(ev.GetRow(),ev.GetCol(),m_gridMaintanence);
		 maintenance->cellCollChanged(ev.GetCol(),ev.GetRow());
		 maintenance->checkService(m_gridGlobal->GetNumberRows()-1);
	}
	ev.Skip();
}

void LogbookDialog::onButtonClickEditLayoutODTService(wxCommandEvent &ev)
{
	int format;

	if(m_radioBtnODTService->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(m_choiceSelectLayoutService,maintenance->layout_locnService, format);
}

void LogbookDialog::onGridCellServiceChange( wxGridEvent& ev )
{
	maintenance->cellCollChanged(ev.GetCol(), ev.GetRow());
	if(ev.GetCol() == maintenance->IF|| ev.GetCol() == maintenance->WARN || 
		ev.GetCol() == maintenance->URGENT || ev.GetCol() == maintenance->ACTIVE)
			maintenance->checkService(m_gridGlobal->GetNumberRows()-1);


}

void LogbookDialog::onGridCellServiceSelected(wxGridEvent &ev)
{
	maintenance->cellSelected(ev.GetCol(), ev.GetRow());
	lastRowSelectedService = ev.GetRow();

	ev.Skip();
}

void LogbookDialog::onMenuSelectionServiceOK(wxCommandEvent &ev)
{
	maintenance->setRowDone(maintenance->selectedRow);
	maintenance->checkService(m_gridGlobal->GetNumberRows()-1);
	maintenance->grid->Refresh();
}

void LogbookDialog::onMenuSelectionServiceDelete( wxCommandEvent& ev )
{
	m_gridMaintanence->SetCellValue(maintenance->m_YesNo[1],maintenance->selectedRow,Maintenance::ACTIVE);
	maintenance->checkService(m_gridGlobal->GetNumberRows()-1);

	m_gridMaintanence->DeleteRows(maintenance->selectedRow);
	maintenance->checkService(m_gridGlobal->GetNumberRows()-1);
}

void LogbookDialog::onGridCellRightClickService(wxGridEvent &ev)
{
	maintenance->selectedRow = ev.GetRow();
	maintenance->selectedCol = ev.GetCol();
	m_gridMaintanence->PopupMenu( m_menu7, ev.GetPosition() );
}

void LogbookDialog::onRadioButtonHTMLService(wxCommandEvent &ev)
{
	maintenance->setLayoutLocation();
	logbookPlugIn->opt->serviceHTML = true;
}

void LogbookDialog::onRadioButtonODTService(wxCommandEvent &ev)
{
	maintenance->setLayoutLocation();	
	logbookPlugIn->opt->serviceHTML = false;
}

void LogbookDialog::onButtonClickViewService(wxCommandEvent &ev)
{
	if(this->m_radioBtnHTMLService->GetValue())
		maintenance->viewHTML(SERVICE,_T(""),
		m_choiceSelectLayoutService->GetString(m_choiceSelectLayoutService->GetSelection()),false);
	else
		maintenance->viewODT(SERVICE,_T(""),
		m_choiceSelectLayoutService->GetString(m_choiceSelectLayoutService->GetSelection()),true);
}

void LogbookDialog::OnKeyDownService( wxKeyEvent& ev )
{
}

void LogbookDialog::onMenuSelectionServiceBuyParts(wxCommandEvent &ev)
{
	maintenance->buyParts(0);
}

///////////////////// Repairs ////////////////////////

void LogbookDialog::onButtobClickAddLineRepairs(wxCommandEvent &ev)
{
	maintenance->addLineRepairs();
}

void LogbookDialog::OnGridLabelLeftClickRepairs( wxGridEvent& event )
{
	int row, col;
	row = event.GetRow();
	col = event.GetCol();

	this->m_gridMaintanenceRepairs->SetFocus();

	if(row != -1 || (row == -1 && col == -1)) { event.Skip(); return; }

	this->m_gridMaintanenceRepairs->SetGridCursor(0,col);
	static bool ascending = true;
	this->sortGrid(this->m_gridMaintanenceRepairs,event.GetCol(),ascending);
	ascending = !ascending;

	maintenance->checkRepairs();
}

void LogbookDialog::onGridCellRepairsSelected( wxGridEvent& ev )
{
	maintenance->selectedRowRepairs = ev.GetRow();
	maintenance->selectedColRepairs = ev.GetCol();
	m_gridMaintanenceRepairs->AutoSizeRow(lastRowSelectedRepairs,false);

	if(ev.GetCol() == maintenance->RTEXT)
		m_gridMaintanenceRepairs->SetRowHeight(ev.GetRow(),170);

	m_gridMaintanenceRepairs->Refresh();
	lastRowSelectedRepairs = ev.GetRow();

	ev.Skip();
}

void LogbookDialog::onGridCellRepairsChange( wxGridEvent& ev )
{
	maintenance->checkRepairs();
	ev.Skip();
}

void LogbookDialog::onMenuSelectionRepairsOK(wxCommandEvent &ev)
{
	maintenance->setRepairDone(maintenance->selectedRowRepairs);
}

void LogbookDialog::onMenuSelectionRepairsDelete(wxCommandEvent &ev)
{
	m_gridMaintanenceRepairs->DeleteRows(maintenance->selectedRowRepairs);
}

void LogbookDialog::onMenuSelectionRepairsBuyParts(wxCommandEvent &ev)
{
	maintenance->buyParts(1);
}

void LogbookDialog::onButtobClickSaveRepairs( wxCommandEvent& event )
{
	wxString filter = _T("");
	if(m_radioBtnHTMLRepairs->GetValue())
		filter = _T("HTML Format(*.html)|*.html");
	else
		filter = _T("Opendocument Text(*.odt)|*.odt");

	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save Repairs File"), _T(""), _T("Repairs"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLRepairs->GetValue())
				maintenance->toHTML(1,path, 
				m_choiceSelectLayoutRepairs->GetString(m_choiceSelectLayoutRepairs->GetSelection()),2);
			else
				maintenance->toODT(1,path,
				m_choiceSelectLayoutRepairs->GetString(m_choiceSelectLayoutRepairs->GetSelection()),2); 
			break;
//	case 1:	maintenance->toODS(path); break;
//	case 2: maintenance->toXML(path); break;
//	case 3: maintenance->toCSV(path); break;
//	case 4: maintenance->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
	delete saveFileDialog;
}

void LogbookDialog::onButtonClickReloadLayoutsRepairsHTML( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
}
void LogbookDialog::onButtonClickEditLayoutODTRepairs( wxCommandEvent& event )
{
	int format;

	if(m_radioBtnODTRepairs->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(m_choiceSelectLayoutRepairs,maintenance->layout_locnRepairs, format);
}

void LogbookDialog::onRadioButtonHTMLRepairs( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
	logbookPlugIn->opt->repairsHTML = true;
}
void LogbookDialog::onRadioButtonODTRepairs( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
	logbookPlugIn->opt->repairsHTML = false;
}
void LogbookDialog::onButtonClickViewRepairs( wxCommandEvent& event )
{
	if(this->m_radioBtnHTMLRepairs->GetValue())
		maintenance->viewHTML(REPAIRS,_T(""),
		m_choiceSelectLayoutRepairs->GetString(m_choiceSelectLayoutRepairs->GetSelection()),false);
	else
		maintenance->viewODT(REPAIRS,_T(""),
		m_choiceSelectLayoutRepairs->GetString(m_choiceSelectLayoutRepairs->GetSelection()),true);
}

void LogbookDialog::onGridCellRightClickRepairs( wxGridEvent& ev )
{
	maintenance->selectedRowRepairs = ev.GetRow();
	maintenance->selectedColRepairs = ev.GetCol();
	m_gridMaintanenceRepairs->PopupMenu( m_menu71, ev.GetPosition() );
}

void LogbookDialog::OnKeyDownRepairs( wxKeyEvent& ev )
{

	wxTextCtrl *ctrl = (wxTextCtrl*)ev.GetEventObject();

	if (ev.ShiftDown() && ev.GetKeyCode() == WXK_RETURN)
	{	
		if(maintenance->selectedColRepairs != maintenance->RTEXT) return;
		if(ev.GetEventObject()->IsKindOf(CLASSINFO(wxTextCtrl)))	
			ctrl->WriteText( wxT("\n") );
		return;
	}

	if (ev.GetKeyCode() == WXK_RETURN)
	{	
		ev.Skip();
		m_gridMaintanenceRepairs->AutoSizeRow(maintenance->selectedRowRepairs,false);
		lastRowSelectedRepairs= maintenance->selectedRowRepairs;
		m_gridMaintanenceRepairs->Refresh();
		return;
	}

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || (ev.GetKeyCode() == WXK_LEFT))
	{	
		if(maintenance->selectedColRepairs == 0)
		{
			maintenance->selectedColRepairs = m_gridMaintanenceRepairs->GetNumberCols()-1;
			m_gridMaintanenceRepairs->SetGridCursor(maintenance->selectedRowRepairs,maintenance->selectedColRepairs);
			m_gridMaintanenceRepairs->MakeCellVisible(maintenance->selectedRowRepairs,maintenance->selectedColRepairs);
		}
		else
			ev.Skip();
		return;
	}
	
	if (ev.GetKeyCode() == WXK_TAB || ev.GetKeyCode() == WXK_RIGHT)
	{	
		if(maintenance->selectedColRepairs == m_gridMaintanenceRepairs->GetNumberCols()-1)
		{
			maintenance->selectedColRepairs = 0;
			m_gridMaintanenceRepairs->SetGridCursor(maintenance->selectedRowRepairs,maintenance->selectedColRepairs);
			m_gridMaintanenceRepairs->MakeCellVisible(maintenance->selectedRowRepairs,maintenance->selectedColRepairs);
		}
		else
			ev.Skip();
		return;
	}
    else 
	{
        ev.Skip () ;
	}
}

///////////////////// BuyParts ////////////////////////

void LogbookDialog::onGridCellRightClickBuyParts( wxGridEvent& ev )
{
	maintenance->selectedRowBuyParts = ev.GetRow();
	maintenance->selectedColBuyParts = ev.GetCol();
	m_gridMaintanence->PopupMenu( m_menu711, ev.GetPosition() );
}

void LogbookDialog::OnGridLabelLeftClickBuyParts( wxGridEvent& event )
{
	int row, col;
	row = event.GetRow();
	col = event.GetCol();

	this->m_gridMaintenanceBuyParts->SetFocus();

	if(row != -1 || (row == -1 && col == -1)) { event.Skip(); return; }

	this->m_gridMaintenanceBuyParts->SetGridCursor(0,col);
	static bool ascending = true;
	this->sortGrid(this->m_gridMaintenanceBuyParts,event.GetCol(),ascending);
	ascending = !ascending;

	maintenance->checkBuyParts();
}

void LogbookDialog::onGridCellLeftClickBuyParts(wxGridEvent& ev)
{
	if(ev.GetCol() == maintenance->DATE)
		 maintenance->showDateDialog(ev.GetRow(),ev.GetCol(),m_gridMaintenanceBuyParts);
	ev.Skip();
}

void LogbookDialog::onMenuSelectionBuyPartsDelete(wxCommandEvent &ev)
{
	m_gridMaintenanceBuyParts->DeleteRows(maintenance->selectedRowBuyParts);	
}

void LogbookDialog::onButtobClickAddLineBuyParts(wxCommandEvent &ev)
{
	maintenance->addLineBuyParts();
}

void LogbookDialog::onGridCellChangeBuyParts(wxGridEvent &ev)
{
	maintenance->checkBuyParts();
	ev.Skip();
}
void LogbookDialog::onButtobClickSaveBuyParts( wxCommandEvent& event )
{
	wxString filter = _T("");
	if(m_radioBtnHTMLBuyParts->GetValue())
		filter = _T("HTML Format(*.html)|*.html");
	else
		filter = _T("Opendocument Text(*.odt)|*.odt");

	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save BuyParts File"), _T(""), _T("BuyParts"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLBuyParts->GetValue())
				maintenance->toHTML(2,path, 
				m_choiceSelectLayoutBuyParts->GetString(m_choiceSelectLayoutBuyParts->GetSelection()),2);
			else
				maintenance->toODT(2,path,
				m_choiceSelectLayoutBuyParts->GetString(m_choiceSelectLayoutBuyParts->GetSelection()),2); 
			break;
//	case 1:	maintenance->toODS(path); break;
//	case 2: maintenance->toXML(path); break;
//	case 3: maintenance->toCSV(path); break;
//	case 4: maintenance->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
	delete saveFileDialog;
}

void LogbookDialog::onButtonClickReloadLayoutsBuyPartsHTML( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
}

void LogbookDialog::onButtonClickEditLayoutODTBuyParts( wxCommandEvent& event )
{
	int format;

	if(m_radioBtnODTBuyParts->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(m_choiceSelectLayoutBuyParts,maintenance->layout_locnBuyParts, format);
}

void LogbookDialog::onRadioButtonHTMLBuyParts( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
	logbookPlugIn->opt->buypartsHTML = true;
}

void LogbookDialog::onRadioButtonODTBuyParts( wxCommandEvent& event )
{
	maintenance->setLayoutLocation();
	logbookPlugIn->opt->buypartsHTML = false;
}

void LogbookDialog::onButtonClickViewBuyParts( wxCommandEvent& event )
{
	if(this->m_radioBtnHTMLBuyParts->GetValue())
		maintenance->viewHTML(BUYPARTS,_T(""),
		m_choiceSelectLayoutBuyParts->GetString(m_choiceSelectLayoutBuyParts->GetSelection()),false);
	else
		maintenance->viewODT(BUYPARTS,_T(""),
		m_choiceSelectLayoutBuyParts->GetString(m_choiceSelectLayoutBuyParts->GetSelection()),true);
}

void LogbookDialog::onGridCellSelectedBuyParts(wxGridEvent &ev)
{
	maintenance->selectedRowBuyParts = ev.GetRow();
	maintenance->selectedColBuyParts = ev.GetCol();

	m_gridMaintenanceBuyParts->AutoSizeRow(lastRowSelectedBuyParts,false);
	if(ev.GetCol() == maintenance->PARTS)
		m_gridMaintenanceBuyParts->SetRowHeight(ev.GetRow(),170);

	maintenance->checkBuyParts();
	m_gridMaintenanceBuyParts->Refresh();
	lastRowSelectedBuyParts = ev.GetRow();
	ev.Skip();
}

void LogbookDialog::OnKeyDownBuyParts( wxKeyEvent& ev )
{

	wxTextCtrl *ctrl = (wxTextCtrl*)ev.GetEventObject();

	if (ev.ShiftDown() && ev.GetKeyCode() == WXK_RETURN)
	{	
		if(maintenance->selectedColBuyParts != maintenance->PARTS) return;
		if(ev.GetEventObject()->IsKindOf(CLASSINFO(wxTextCtrl)))	
			ctrl->WriteText( wxT("\n") );
		return;
	}

	if (ev.GetKeyCode() == WXK_RETURN)
	{	
		ev.Skip();
		m_gridMaintenanceBuyParts->AutoSizeRow(maintenance->selectedRow,false);
		lastRowSelectedBuyParts = maintenance->selectedRow;
		m_gridMaintanence->Refresh();
		return;
	}

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || (ev.GetKeyCode() == WXK_LEFT))
	{	
		if(maintenance->selectedColBuyParts == 0)
		{
			maintenance->selectedColBuyParts = m_gridMaintenanceBuyParts->GetNumberCols()-1;
			m_gridMaintenanceBuyParts->SetGridCursor(maintenance->selectedRowBuyParts,maintenance->selectedColBuyParts);
			m_gridMaintenanceBuyParts->MakeCellVisible(maintenance->selectedRowBuyParts,maintenance->selectedColBuyParts);
		}
		else
			ev.Skip();
		return;
	}
	
	if (ev.GetKeyCode() == WXK_TAB || ev.GetKeyCode() == WXK_RIGHT)
	{	
		if(maintenance->selectedColBuyParts == m_gridMaintenanceBuyParts->GetNumberCols()-1)
		{
			maintenance->selectedColBuyParts = 0;
			m_gridMaintenanceBuyParts->SetGridCursor(maintenance->selectedRowBuyParts,maintenance->selectedColBuyParts);
			m_gridMaintenanceBuyParts->MakeCellVisible(maintenance->selectedRowBuyParts,maintenance->selectedColBuyParts);
		}
		else
			ev.Skip();
		return;
	}
    else 
	{
        ev.Skip () ;
	}
}

void LogbookDialog::onGridEditorHidden( wxGridEvent& ev )
{
	ev.Skip();
}
void LogbookDialog::onGridEditorShow( wxGridEvent& ev )
{
	ev.Skip();
}

////////////////////////////////////////////////////////////
//    OverView
////////////////////////////////////////////////////////////
void LogbookDialog::onButtonClickSelectLogbook(wxCommandEvent & ec)
{
	overview->selectLogbook();		
}

void LogbookDialog::OnGridLabelLeftDClickOverview( wxGridEvent& ev )
{
	if(ev.GetCol() == -1) return;
	int count = 0;

	for(int i = 0; i < m_gridOverview->GetNumberCols() && count < 2; i++)
		if(m_gridOverview->GetColumnWidth(i) > 0)
			count++;

	if(count < 2) return;
	m_gridOverview->SetColumnWidth(ev.GetCol(),0);
	m_gridOverview->Refresh();	
}

void LogbookDialog::OnKeyDownOverview( wxKeyEvent& ev )
{
	int offset;
	int col = m_gridOverview->GetGridCursorCol();
	int row = m_gridOverview->GetGridCursorRow();

	if((ev.GetKeyCode() != WXK_TAB) || (ev.ShiftDown() && ev.GetKeyCode() != WXK_TAB)) 
		{ ev.Skip(); return; }

	if ((ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_LEFT))
			offset = -1; 

	if ((!ev.ShiftDown() && ev.GetKeyCode() == WXK_TAB) || 
		(ev.GetKeyCode() == WXK_RIGHT))
			offset = 1; 

	while((col+offset < m_gridOverview->GetNumberCols()-1) && (col+offset > 0))
	{
		if(m_gridOverview->GetColSize(col+offset) == 0)
			col += offset;
		else
			break;
	}

	if(col+offset == 0 && m_gridOverview->GetColSize(0) == 0)
		col = m_gridOverview->GetNumberCols()-1;
	if((col+offset == m_gridOverview->GetNumberCols()-1) && (m_gridOverview->GetColSize(col+offset) == 0))
		col = 0;
	m_gridOverview->SetGridCursor(row,col);
	ev.Skip();
}

void LogbookDialog::OnMenuSelectionHideColumnOverView(wxCommandEvent& ev)
{
	m_gridOverview->SetColumnWidth(m_gridOverview->GetCursorColumn(),0);
	m_gridOverview->Refresh();	
}

void LogbookDialog::OnButtonClickOverviewSave( wxCommandEvent& ev )
{
	wxString filter = _T("");
	if(m_radioBtnHTMLOverview->GetValue())
		filter = _T("HTML Format(*.html)|*.html");
	else
		filter = _T("Opendocument Text(*.odt)|*.odt");

	wxFileDialog *saveFileDialog = 
			new wxFileDialog(this, _("Save Overview File"), _T(""), _T("Overview"),
										   filter, 
										   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog->ShowModal() == wxID_CANCEL)
            return;

	wxString path = saveFileDialog->GetPath();
	int sel = saveFileDialog->GetFilterIndex();

	switch(sel)
	{
	case 0: if(m_radioBtnHTMLOverview->GetValue())
				overview->toHTML(path, 
				overviewChoice->GetString(overviewChoice->GetSelection()),2);
			else
				overview->toODT(path,
				overviewChoice->GetString(overviewChoice->GetSelection()),2); 
			break;
//	case 1:	overview->toODS(path); break;
//	case 2: overview->toXML(path); break;
//	case 3: overview->toCSV(path); break;
//	case 4: overview->backup(path); break;
#ifdef __WXOSX__
    default: ::MessageBoxOSX(NULL,_T("Not implemented yet"),_T("Information"),wxID_OK); break;        
#else
	default: ::wxMessageBox(_T("Not implemented yet"),_T("Information")); break;
#endif
	}
	delete saveFileDialog;
}

void LogbookDialog::onButtonReloadLayoutOverView( wxCommandEvent& ev )
{
	overview->setLayoutLocation();
}

void LogbookDialog::onButtonClickEditLayoutOverview( wxCommandEvent& ev )
{
	int format;

	if(this->m_radioBtnODTOverview->GetValue())
		format = ODT;
	else
		format = HTML;

	showLayoutDialog(overviewChoice,overview->layout_locn, format);
}

void LogbookDialog::onRadioButtonHTMLOverview( wxCommandEvent& ev )
{
	overview->setLayoutLocation();
	logbookPlugIn->opt->overviewHTML = true;
}

void LogbookDialog::onRadioButtonODTOverView( wxCommandEvent& ev )
{
	overview->setLayoutLocation();
    logbookPlugIn->opt->overviewHTML = false;
}

void LogbookDialog::OnButtonClickOverView( wxCommandEvent& ev )
{
	if(m_radioBtnHTMLOverview->GetValue())
		overview->viewHTML(_T(""),
		overviewChoice->GetString(overviewChoice->GetSelection()),false);
	else
		overview->viewODT(_T(""),
		overviewChoice->GetString(overviewChoice->GetSelection()),true);
}

void LogbookDialog::OnGridCellRightClickOverview( wxGridEvent& ev )
{
	m_gridOverview->SetGridCursor(ev.GetRow(),ev.GetCol());
	overview->setSelectedRow(ev.GetRow());
	m_gridOverview->PopupMenu( m_menuOverView, ev.GetPosition() );
}

void LogbookDialog::OnGridLabelLeftClickOverview( wxGridEvent& ev )
{
}

void LogbookDialog::OnRadioButtonActuellLogbook(wxCommandEvent & ev)
{
	overview->refresh();
}

void LogbookDialog::OnRadioButtonAllLogbooks(wxCommandEvent &ev)
{
	overview->refresh();
}

void LogbookDialog::OnMenuSelectionGotoRoute( wxCommandEvent& ev )
{
	overview->gotoRoute();
}

bool LogbookDialog::myParseDate(wxString s, wxDateTime &dt)
{
	long day;
	long month;
	long year;

	for(unsigned int i = 0; i < s.Length(); i++)
		if(s.at(i) < '0' || s.at(i) > '9')
			dateSeparator = s.at(i);

	int i = 0;
	wxString temp = s.substr(0,s.find_first_of(dateSeparator));
	switch(datePattern.GetChar(i))
		{
		case 'd': temp.ToLong(&day); i += 3;
			break;
		case 'm': temp.ToLong(&month); i += 3;
			break;
		case 'y': temp.ToLong(&year); i += 5;
			break;
		}
	temp = s.substr(s.find_first_of(dateSeparator)+1,s.find_last_of(dateSeparator)-2);
	switch(datePattern.GetChar(i))
		{
		case 'd': temp.ToLong(&day); i += 3;
			break;
		case 'm': temp.ToLong(&month); i += 3;
			break;
		case 'y': temp.ToLong(&year); i += 5;
			break;
		}
	temp = s.substr(s.find_last_of(dateSeparator)+1);
	switch(datePattern.GetChar(i))
		{
		case 'd': temp.ToLong(&day); i += 3;
			break;
		case 'm': temp.ToLong(&month); i += 3;
			break;
		case 'y': temp.ToLong(&year); i += 5;
			break;
		}

	s = wxString::Format(_T("%i.%i.%i"),month,day,year);
	if(dt.ParseDate(s))
		return true;
	else
		return false;
}

const wxChar* LogbookDialog::myParseTime(wxString s, wxDateTime& dt)
{
	const wxChar* c;
	bool correction = false;

	if((int) s.GetChar(0) == 19979 || (int) s.GetChar(0) == 19978 )  // chinese time starts with this two chars
	{																 // ParseTime will not handle this correct
		if((int) s.GetChar(0) == 19979)  // is it like 'F with a broken arm' ?
			correction = true;           // It's a PM-Time, needs correction
		unsigned int i;
		for( i = 0; i < s.Len(); i++) // eleminate leading chars
			if(s.at(i) >= '0' && s.at(i) <= '9')
				break;
		if(i > 0)
			s = s.Remove(0,i);
	}

	s = s.Upper();
	c = dt.ParseTime(s);
	if(correction) // make correction for PM (chinese only)
	{
		wxTimeSpan diff(12); 
		dt.Add(diff);
	}

    return c;
}

void LogbookDialog::setDatePattern()
{
	wxDateTime dt;
	dt.Set((wxDateTime::wxDateTime_t) 14, (wxDateTime::Month) 11, 2011);
	wxString s = dt.FormatDate();

	for(unsigned int i = 0; i < s.Length(); i++)
		if(s.at(i) < '0' || s.at(i) > '9')
			dateSeparator = s.at(i);

	int i = 0;
	if(s.SubString(i,1) == _T("14"))
		{ datePattern = _T("dd") + wxString(dateSeparator); i += 3; }
	if(s.SubString(i,1) == _T("12"))
		{ datePattern = _T("mm") + wxString(dateSeparator); i += 3; }
	if(s.SubString(i,3) == _T("2011"))
		{ datePattern = _T("yyyy") + wxString(dateSeparator); i += 5; }

	if(s.SubString(i,i+1) == _T("14"))
		{ datePattern += _T("dd") + wxString(dateSeparator);  i += 3; }
	if(s.SubString(i,i+1) == _T("12"))
		{ datePattern += _T("mm") + wxString(dateSeparator);  i += 3; }
    if(s.SubString(i,i+3) == _T("2011"))
		{ datePattern += _T("yyyy") + wxString(dateSeparator);  i += 5; }

	if(s.SubString(i,i+1) == _T("14"))
		{ datePattern += _T("dd");  i += 3; }
	if(s.SubString(i,i+1) == _T("12"))
		{ datePattern += _T("mm");  i += 3; }
    if(s.SubString(i,i+3) == _T("2011"))
		{ datePattern += _T("yyyy");  i += 5; }
}

////////////////////////////////////////////////////////////
//   Headers for Export
///////////////////////////////////////////////////////////
void LogbookDialog::declareExportHeader()
{
	content=
_T("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\
<office:document-content xmlns:office=\"urn:oasis:names:tc:opendocument:xmlns:office:1.0\" xmlns:style=\"urn:oasis:names:tc:opendocument:xmlns:style:1.0\" xmlns:text=\"urn:oasis:names:tc:opendocument:xmlns:text:1.0\" xmlns:table=\"urn:oasis:names:tc:opendocument:xmlns:table:1.0\" xmlns:draw=\"urn:oasis:names:tc:opendocument:xmlns:drawing:1.0\" xmlns:fo=\"urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:meta=\"urn:oasis:names:tc:opendocument:xmlns:meta:1.0\" xmlns:number=\"urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0\" xmlns:presentation=\"urn:oasis:names:tc:opendocument:xmlns:presentation:1.0\" xmlns:svg=\"urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0\" xmlns:chart=\"urn:oasis:names:tc:opendocument:xmlns:chart:1.0\" xmlns:dr3d=\"urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0\" xmlns:math=\"http://www.w3.org/1998/Math/MathML\" xmlns:form=\"urn:oasis:names:tc:opendocument:xmlns:form:1.0\" xmlns:script=\"urn:oasis:names:tc:opendocument:xmlns:script:1.0\" xmlns:ooo=\"http://openoffice.org/2004/office\" xmlns:ooow=\"http://openoffice.org/2004/writer\" xmlns:oooc=\"http://openoffice.org/2004/calc\" xmlns:dom=\"http://www.w3.org/2001/xml-events\" xmlns:xforms=\"http://www.w3.org/2002/xforms\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:rpt=\"http://openoffice.org/2005/report\" xmlns:of=\"urn:oasis:names:tc:opendocument:xmlns:of:1.2\" xmlns:xhtml=\"http://www.w3.org/1999/xhtml\" xmlns:grddl=\"http://www.w3.org/2003/g/data-view#\" xmlns:field=\"urn:openoffice:names:experimental:ooo-ms-interop:xmlns:field:1.0\" office:version=\"1.2\" grddl:transformation=\"http://docs.oasis-open.org/office/1.2/xslt/odf2rdf.xsl\">\
<office:scripts />\
<office:font-face-decls>\
<style:font-face style:name=\"Arial\" svg:font-family=\"Arial\" style:font-family-generic=\"swiss\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Arial Unicode MS\" svg:font-family=\"'Arial Unicode MS'\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Mangal\" svg:font-family=\"Mangal\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Tahoma\" svg:font-family=\"Tahoma\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
</office:font-face-decls>\
<office:automatic-styles>\
<style:style style:name=\"co1\" style:family=\"table-column\">\
<style:table-column-properties fo:break-before=\"auto\" style:column-width=\"2.267cm\" />\
</style:style>\
<style:style style:name=\"ro2\" style:family=\"table-row\">\
<style:table-row-properties style:row-height=\"0.453cm\" fo:break-before=\"auto\" style:use-optimal-row-height=\"true\" />\
</style:style>\
<style:style style:name=\"ro3\" style:family=\"table-row\">\
<style:table-row-properties style:row-height=\"0.894cm\" fo:break-before=\"auto\" style:use-optimal-row-height=\"true\" />\
</style:style>\
<style:style style:name=\"ta1\" style:family=\"table\" style:master-page-name=\"Default\">\
<style:table-properties table:display=\"true\" style:writing-mode=\"lr-tb\" />\
</style:style>\
<style:style style:name=\"ta_extref\" style:family=\"table\">\
<style:table-properties table:display=\"false\" />\
</style:style>\
</office:automatic-styles>\
<office:body>\
<office:spreadsheet>\
<table:table table:name=\"Logbook\" table:style-name=\"ta1\" table:print=\"false\">\
<table:table-column table:style-name=\"co1\" table:number-columns-repeated=\"33\" table:default-cell-style-name=\"Default\" />\
");
	contentEnd=_T("</table:table></office:spreadsheet></office:body></office:document-content>\
 ");

	manifest=
_T("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\
<manifest:manifest xmlns:manifest=\"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0\">\
<manifest:file-entry manifest:media-type=\"application/vnd.oasis.opendocument.spreadsheet\" manifest:version=\"1.2\" manifest:full-path=\"/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/statusbar/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/accelerator/current.xml\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/accelerator/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/floater/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/popupmenu/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/progressbar/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/menubar/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/toolbar/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/images/Bitmaps/\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Configurations2/images/\" />\
<manifest:file-entry manifest:media-type=\"application/vnd.sun.xml.ui.configuration\" manifest:full-path=\"Configurations2/\" />\
<manifest:file-entry manifest:media-type=\"text/xml\" manifest:full-path=\"content.xml\" />\
<manifest:file-entry manifest:media-type=\"text/xml\" manifest:full-path=\"styles.xml\" />\
<manifest:file-entry manifest:media-type=\"text/xml\" manifest:full-path=\"meta.xml\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Thumbnails/thumbnail.png\" />\
<manifest:file-entry manifest:media-type=\"\" manifest:full-path=\"Thumbnails/\" />\
<manifest:file-entry manifest:media-type=\"text/xml\" manifest:full-path=\"settings.xml\" />\
</manifest:manifest>");

	styles =_T(
"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\
<office:document-styles xmlns:office=\"urn:oasis:names:tc:opendocument:xmlns:office:1.0\" xmlns:style=\"urn:oasis:names:tc:opendocument:xmlns:style:1.0\" xmlns:text=\"urn:oasis:names:tc:opendocument:xmlns:text:1.0\" xmlns:table=\"urn:oasis:names:tc:opendocument:xmlns:table:1.0\" xmlns:draw=\"urn:oasis:names:tc:opendocument:xmlns:drawing:1.0\" xmlns:fo=\"urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:meta=\"urn:oasis:names:tc:opendocument:xmlns:meta:1.0\" xmlns:number=\"urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0\" xmlns:presentation=\"urn:oasis:names:tc:opendocument:xmlns:presentation:1.0\" xmlns:svg=\"urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0\" xmlns:chart=\"urn:oasis:names:tc:opendocument:xmlns:chart:1.0\" xmlns:dr3d=\"urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0\" xmlns:math=\"http://www.w3.org/1998/Math/MathML\" xmlns:form=\"urn:oasis:names:tc:opendocument:xmlns:form:1.0\" xmlns:script=\"urn:oasis:names:tc:opendocument:xmlns:script:1.0\" xmlns:ooo=\"http://openoffice.org/2004/office\" xmlns:ooow=\"http://openoffice.org/2004/writer\" xmlns:oooc=\"http://openoffice.org/2004/calc\" xmlns:dom=\"http://www.w3.org/2001/xml-events\" xmlns:rpt=\"http://openoffice.org/2005/report\" xmlns:of=\"urn:oasis:names:tc:opendocument:xmlns:of:1.2\" xmlns:xhtml=\"http://www.w3.org/1999/xhtml\" xmlns:grddl=\"http://www.w3.org/2003/g/data-view#\" office:version=\"1.2\" grddl:transformation=\"http://docs.oasis-open.org/office/1.2/xslt/odf2rdf.xsl\">\
<office:font-face-decls>\
<style:font-face style:name=\"Arial\" svg:font-family=\"Arial\" style:font-family-generic=\"swiss\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Arial Unicode MS\" svg:font-family=\"'Arial Unicode MS'\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Mangal\" svg:font-family=\"Mangal\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
<style:font-face style:name=\"Tahoma\" svg:font-family=\"Tahoma\" style:font-family-generic=\"system\" style:font-pitch=\"variable\" />\
</office:font-face-decls>\
<office:styles>\
<style:default-style style:family=\"table-cell\">\
<style:table-cell-properties style:decimal-places=\"2\" />\
<style:paragraph-properties style:tab-stop-distance=\"1.25cm\" />\
<style:text-properties style:font-name=\"Arial\" fo:language=\"de\" fo:country=\"DE\" style:font-name-asian=\"Arial Unicode MS\" style:language-asian=\"zh\" style:country-asian=\"CN\" style:font-name-complex=\"Tahoma\" style:language-complex=\"hi\" style:country-complex=\"IN\" />\
</style:default-style>\
<number:number-style style:name=\"N0\">\
<number:number number:min-integer-digits=\"1\" /> \
</number:number-style>\
<number:currency-style style:name=\"N106P0\" style:volatile=\"true\">\
<number:number number:decimal-places=\"2\" number:min-integer-digits=\"1\" number:grouping=\"true\" /> \
<number:text />\
<number:currency-symbol number:language=\"de\" number:country=\"DE\">€</number:currency-symbol>\
</number:currency-style>\
<number:currency-style style:name=\"N106\">\
<style:text-properties fo:color=\"#ff0000\" />\
<number:text>-</number:text>\
<number:number number:decimal-places=\"2\" number:min-integer-digits=\"1\" number:grouping=\"true\" />\
<number:text />\
<number:currency-symbol number:language=\"de\" number:country=\"DE\">€</number:currency-symbol>\
<style:map style:condition=\"value()>=0\" style:apply-style-name=\"N106P0\" />\
</number:currency-style>\
<style:style style:name=\"Default\" style:family=\"table-cell\">\
<style:text-properties style:font-name-complex=\"Mangal\" />\
</style:style>\
<style:style style:name=\"Result\" style:family=\"table-cell\" style:parent-style-name=\"Default\">\
<style:text-properties fo:font-style=\"italic\" style:text-underline-style=\"solid\" style:text-underline-width=\"auto\" style:text-underline-color=\"font-color\" fo:font-weight=\"bold\" />\
</style:style>\
<style:style style:name=\"Result2\" style:family=\"table-cell\" style:parent-style-name=\"Result\" style:data-style-name=\"N106\" />\
<style:style style:name=\"Heading\" style:family=\"table-cell\" style:parent-style-name=\"Default\">\
<style:table-cell-properties style:text-align-source=\"fix\" style:repeat-content=\"false\" />\
<style:paragraph-properties fo:text-align=\"center\" />\
<style:text-properties fo:font-size=\"16pt\" fo:font-style=\"italic\" fo:font-weight=\"bold\" />\
</style:style>\
<style:style style:name=\"Heading1\" style:family=\"table-cell\" style:parent-style-name=\"Heading\">\
<style:table-cell-properties style:rotation-angle=\"90\" />\
</style:style>\
</office:styles>\
<office:automatic-styles>\
<style:page-layout style:name=\"Mpm1\">\
<style:page-layout-properties style:writing-mode=\"lr-tb\" />\
<style:header-style>\
<style:header-footer-properties fo:min-height=\"0.751cm\" fo:margin-left=\"0cm\" fo:margin-right=\"0cm\" fo:margin-bottom=\"0.25cm\" />\
</style:header-style>\
<style:footer-style>\
<style:header-footer-properties fo:min-height=\"0.751cm\" fo:margin-left=\"0cm\" fo:margin-right=\"0cm\" fo:margin-top=\"0.25cm\" />\
</style:footer-style>\
</style:page-layout>\
<style:page-layout style:name=\"Mpm2\">\
<style:page-layout-properties style:writing-mode=\"lr-tb\" />\
<style:header-style>\
<style:header-footer-properties fo:min-height=\"0.751cm\" fo:margin-left=\"0cm\" fo:margin-right=\"0cm\" fo:margin-bottom=\"0.25cm\" fo:border=\"0.088cm solid #000000\" fo:padding=\"0.018cm\"  fo:background-color=\"#c0c0c0\">\
<style:background-image />\
</style:header-footer-properties>\
</style:header-style>\
<style:footer-style>\
<style:header-footer-properties fo:min-height=\"0.751cm\" fo:margin-left=\"0cm\" fo:margin-right=\"0cm\" fo:margin-top=\"0.25cm\" fo:border=\"0.088cm solid #000000\" fo:padding=\"0.018cm\" fo:background-color=\"#c0c0c0\">\
<style:background-image />\
</style:header-footer-properties>\
</style:footer-style>\
</style:page-layout>\
</office:automatic-styles>\
<office:master-styles>\
<style:master-page style:name=\"Default\" style:page-layout-name=\"Mpm1\">\
<style:header>\
<text:p>\
<text:sheet-name>p</text:sheet-name>\
</text:p>\
</style:header>\
<style:header-left style:display=\"false\" />\
<style:footer>\
<text:p>\
Seite\
<text:page-number>1</text:page-number>\
</text:p>\
</style:footer>\
<style:footer-left style:display=\"false\" />\
</style:master-page>\
<style:master-page style:name=\"Report\" style:page-layout-name=\"Mpm2\">\
<style:header>\
<style:region-left>\
<text:p>\
<text:sheet-name>p</text:sheet-name>(<text:title>p</text:title>)\
</text:p>\
</style:region-left>\
<style:region-right>\
<text:p>\
<text:date style:data-style-name=\"N2\" text:date-value=\"2010-11-20\">20.11.2010</text:date>,<text:time>12:55:07</text:time>\
</text:p>\
</style:region-right>\
</style:header>\
<style:header-left style:display=\"false\" />\
<style:footer>\
<text:p>Seite <text:page-number>1</text:page-number>/<text:page-count>99</text:page-count>\
</text:p>\
</style:footer>\
<style:footer-left style:display=\"false\" /> \
</style:master-page>\
</office:master-styles>\
</office:document-styles>\
");

	meta = _T(
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\
<office:document-meta xmlns:office=\"urn:oasis:names:tc:opendocument:xmlns:office:1.0\" xmlns:meta=\"urn:oasis:names:tc:opendocument:xmlns:meta:1.0\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" office:version=\"1.1\">\
<office:meta>\
<meta:generator>OpenCPN-Logbook</meta:generator>\
<dc:creator>OpenCPN</dc:creator>\
<dc:date>2010-11-19T20:43:36Z</dc:date>\
<meta:editing-duration>PT0S</meta:editing-duration>\
</office:meta>\
</office:document-meta>");

	xmlHead =_T(
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
<?mso-application progid=\"Excel.Sheet\"?>\
<Workbook xmlns:c=\"urn:schemas-microsoft-com:office:component:spreadsheet\" xmlns:html=\"http://www.w3.org/TR/REC-html40\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:x2=\"http://schemas.microsoft.com/office/excel/2003/xml\" xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:x=\"urn:schemas-microsoft-com:office:excel\">\
<OfficeDocumentSettings xmlns=\"urn:schemas-microsoft-com:office:office\">\
<Colors>\
<Color>\
<Index>3</Index>\
<RGB>#c0c0c0</RGB>\
</Color>\
<Color>\
<Index>4</Index>\
<RGB>#ff0000</RGB>\
</Color>\
</Colors>\
</OfficeDocumentSettings>\
<ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\">\
<WindowHeight>9000</WindowHeight>\
<WindowWidth>13860</WindowWidth>\
<WindowTopX>240</WindowTopX>\
<WindowTopY>75</WindowTopY>\
<ProtectStructure>False</ProtectStructure>\
<ProtectWindows>False</ProtectWindows>\
</ExcelWorkbook>\
<Styles>\
<Style ss:ID=\"Default\" ss:Name=\"Default\"/>\
<Style ss:ID=\"Result\" ss:Name=\"Result\">\
<Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Underline=\"Single\"/>\
</Style>\
<Style ss:ID=\"Result2\" ss:Name=\"Result2\">\
<Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Underline=\"Single\"/>\
<NumberFormat ss:Format=\"Euro Currency\"/>\
</Style><Style ss:ID=\"Heading\" ss:Name=\"Heading\">\
<Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"16\"/>\
</Style>\
<Style ss:ID=\"Heading1\" ss:Name=\"Heading1\">\
<Font ss:Bold=\"1\" ss:Italic=\"1\" ss:Size=\"16\"/>\
</Style>\
<Style ss:ID=\"co1\"/><Style ss:ID=\"ta1\"/><Style ss:ID=\"ta_extref\"/>\
</Styles>\
<ss:Worksheet ss:Name=\"Tabelle1\">\
<Table ss:StyleID=\"ta1\">\
<Column ss:Span=\"1\" ss:Width=\"64.2614\"/>");
	xmlEnd =_T(
"</Table>\
<x:WorksheetOptions/>\
</ss:Worksheet>\
</Workbook>");
}

/////////////////////////////////////////////////////////
// Route Dialog
/////////////////////////////////////////////////////////
RouteDialog::RouteDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_listCtrlRoute = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 250,250 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING|wxHSCROLL );
	fgSizer17->Add( m_listCtrlRoute, 0, wxALL, 5 );
	
	m_sdbSizer6 = new wxStdDialogButtonSizer();
	m_sdbSizer6OK = new wxButton( this, wxID_OK );
	m_sdbSizer6->AddButton( m_sdbSizer6OK );
	m_sdbSizer6Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer6->AddButton( m_sdbSizer6Cancel );
	m_sdbSizer6->Realize();
	fgSizer17->Add( m_sdbSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( fgSizer17 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

RouteDialog::~RouteDialog()
{
}
///////////////////////////////////////////////////////////////////////////
//  Layout Dialog
///////////////////////////////////////////////////////////////////////////
#include "folder.xpm"
LayoutDialog::LayoutDialog( wxWindow* parent, wxString location, wxChoice* choice, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxFlexGridSizer* fgSizer25;
	fgSizer25 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer25->SetFlexibleDirection( wxBOTH );
	fgSizer25->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 6, 3, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer23->Add( 10, 0, 1, wxEXPAND, 5 );
	
	m_radioBtnEdit = new wxRadioButton( this, wxID_ANY, _("Edit Layout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnEdit->SetValue( true ); 
	fgSizer23->Add( m_radioBtnEdit, 0, wxALL, 5 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_radioBtnFilter = new wxRadioButton( this, wxID_ANY, _("Filter Layout by"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( m_radioBtnFilter, 0, wxALL, 5 );
	
	wxArrayString m_choice15Choices;
	m_choice15 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 60,-1 ), m_choice15Choices, 0 );
	m_choice15->SetSelection( 0 );
	fgSizer23->Add( m_choice15, 0, wxALL, 0 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_radioBtnRename = new wxRadioButton( this, wxID_ANY, _("Rename Layout"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( m_radioBtnRename, 0, wxALL, 5 );
	
	m_textCtrlRename = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( -1,-1 ), wxSize( 150,-1 ), 0 );
	fgSizer23->Add( m_textCtrlRename, 0, wxALL, 0 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_radioBtnDelete = new wxRadioButton( this, wxID_ANY, _("Delete Layout"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( m_radioBtnDelete, 0, wxALL, 5 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_radioBtnEmail = new wxRadioButton( this, wxID_ANY, _("Send Layout by email"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( m_radioBtnEmail, 0, wxALL, 5 );
	
	
	fgSizer23->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer23->Add( 0, 30, 1, wxEXPAND, 5 );
	
	m_radioBtnInstall = new wxRadioButton( this, wxID_ANY, _("Install single Layout"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( m_radioBtnInstall, 0, wxALL, 5 );
	
	m_bpButtonLoadLayout = new wxBitmapButton( this, wxID_ANY, wxBitmap( folder ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer23->Add( m_bpButtonLoadLayout, 0, wxALL, 0 );
	
	fgSizer25->Add( fgSizer23, 1, wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	fgSizer25->Add( m_sdbSizer3, 0, wxALIGN_CENTER, 5 );
	
	this->SetSizer( fgSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButtonLoadLayout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayoutDialog::OnButtonClickLoadLayout ), NULL, this );

	layoutFileName= _T("");
	dialog = (LogbookDialog* )parent;
	if(dialog->logbookPlugIn->opt->filterLayout)
		{
			dialog->logbookPlugIn->opt->filterLayout = false;
			dialog->logbookPlugIn->opt->showAllLayouts = true;
			dialog->loadLayoutChoice(location,choice);
			dialog->logbookPlugIn->opt->showAllLayouts = false;
			dialog->logbookPlugIn->opt->filterLayout = true;
		}
}

LayoutDialog::~LayoutDialog()
{
	// Disconnect Events
	m_bpButtonLoadLayout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayoutDialog::OnButtonClickLoadLayout ), NULL, this );
	
}

void LayoutDialog::OnButtonClickLoadLayout( wxCommandEvent& event )
{
	wxFileDialog dlg(this);
	if(	dlg.ShowModal() == wxID_OK)
	{
		layoutPath = dlg.GetPath();
		layoutFileName = dlg.GetFilename();
	}
}

////////////////////////////////////////////////////
// Select Logbook Dialog
////////////////////////////////////////////////////
SelectLogbook::SelectLogbook( wxWindow* parent, wxString path, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->path = path;
	this->parent = (LogbookDialog*)parent;

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrlSelectLogbook = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING|wxALWAYS_SHOW_SB );
		bSizer23->Add( m_listCtrlSelectLogbook, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer4 = new wxStdDialogButtonSizer();
	m_sdbSizer4OK = new wxButton( this, wxID_OK );
	m_sdbSizer4->AddButton( m_sdbSizer4OK );
	m_sdbSizer4Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer4->AddButton( m_sdbSizer4Cancel );
	m_sdbSizer4->Realize();
	bSizer23->Add( m_sdbSizer4, 0, wxALIGN_CENTER, 5 );
	
	this->SetSizer( bSizer23 );
	this->Layout();
	
	this->Centre( wxBOTH );

	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( SelectLogbook::OnInit ) );
}

SelectLogbook::~SelectLogbook()
{
}

void SelectLogbook::OnInit(wxInitDialogEvent& ev)
{
	wxString filename;
	wxDateTime dtfrom, dtto;
	wxListItem itemCol;
	itemCol.SetText(_("Logbook"));
	itemCol.SetImage(-1);
	itemCol.SetWidth(255);
	m_listCtrlSelectLogbook->InsertColumn(0, itemCol);

	wxDir::GetAllFiles(path,&files,_T("*logbook.txt"));

	for(unsigned int i = 0; i < files.Count(); i++)
	{
		wxFileName fn(files[i]);
		filename = fn.GetName();
		if(filename == _T("logbook"))
			filename = _("Actuell Logbook");
		else
		{
			dtto = parent->getDateTo(filename);
			wxFileInputStream input( files[i]);
			wxTextInputStream text( input );
			wxString t = text.ReadLine();
			wxStringTokenizer tk(t,_T("	"));
			tk.GetNextToken();
			wxString date = tk.GetNextToken();
			date = dtfrom.ParseDate(date);
			filename = wxString::Format(_("Logbook from %s to %s"),dtfrom.FormatDate().c_str(), dtto.FormatDate().c_str()); 
		}
		m_listCtrlSelectLogbook->InsertItem(i,filename);
	}
}

//////////////////////////// myGridStringTable /////////


WX_DEFINE_OBJARRAY(myGridStringArray)

//IMPLEMENT_DYNAMIC_CLASS( myGridStringTable, wxGridTableBase )

myGridStringTable::myGridStringTable()
        : wxGridTableBase()
{
}

myGridStringTable::myGridStringTable( int numRows, int numCols )
        : wxGridTableBase()
{
    m_data.Alloc( numRows );

    wxArrayString sa;
    sa.Alloc( numCols );
    sa.Add( wxEmptyString, numCols );

    m_data.Add( sa, numRows );
}

myGridStringTable::~myGridStringTable()
{
}

int myGridStringTable::GetNumberRows()
{
    return m_data.GetCount();
}

int myGridStringTable::GetNumberCols()
{
    if ( m_data.GetCount() > 0 )
        return m_data[0].GetCount();
    else
        return 0;
}

wxString myGridStringTable::GetValue( int row, int col )
{
    wxCHECK_MSG( (row < GetNumberRows()) && (col < GetNumberCols()),
                 wxEmptyString,
                 _T("invalid row or column index in myGridStringTable") );

    return m_data[row][col];
}

void myGridStringTable::SetValue( int row, int col, const wxString& value )
{
    wxCHECK_RET( (row < GetNumberRows()) && (col < GetNumberCols()),
                 _T("invalid row or column index in myGridStringTable") );

    m_data[row][col] = value;
}

bool myGridStringTable::IsEmptyCell( int row, int col )
{
    wxCHECK_MSG( (row < GetNumberRows()) && (col < GetNumberCols()),
                 true,
                  _T("invalid row or column index in myGridStringTable") );

    return (m_data[row][col] == wxEmptyString);
}

void myGridStringTable::Clear()
{
    int row, col;
    int numRows, numCols;

    numRows = m_data.GetCount();
    if ( numRows > 0 )
    {
        numCols = m_data[0].GetCount();

        for ( row = 0; row < numRows; row++ )
        {
            for ( col = 0; col < numCols; col++ )
            {
                m_data[row][col] = wxEmptyString;
            }
        }
    }
}

bool myGridStringTable::InsertRows( size_t pos, size_t numRows )
{
    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0 ? m_data[0].GetCount() :
                          ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    if ( pos >= curNumRows )
    {
        return AppendRows( numRows );
    }

    wxArrayString sa;
    sa.Alloc( curNumCols );
    sa.Add( wxEmptyString, curNumCols );
    m_data.Insert( sa, pos, numRows );

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_INSERTED,
                                pos,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

bool myGridStringTable::AppendRows( size_t numRows )
{
    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0
                         ? m_data[0].GetCount()
                         : ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    wxArrayString sa;
    if ( curNumCols > 0 )
    {
        sa.Alloc( curNumCols );
        sa.Add( wxEmptyString, curNumCols );
    }

    m_data.Add( sa, numRows );

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_APPENDED,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

bool myGridStringTable::DeleteRows( size_t pos, size_t numRows )
{
    size_t curNumRows = m_data.GetCount();

    if ( pos >= curNumRows )
    {
        wxFAIL_MSG( wxString::Format
                    (
                        wxT("Called myGridStringTable::DeleteRows(pos=%lu, N=%lu)\nPos value is invalid for present table with %lu rows"),
                        (unsigned long)pos,
                        (unsigned long)numRows,
                        (unsigned long)curNumRows
                    ) );

        return false;
    }

    if ( numRows > curNumRows - pos )
    {
        numRows = curNumRows - pos;
    }

    if ( numRows >= curNumRows )
    {
        m_data.Clear();
    }
    else
    {
        m_data.RemoveAt( pos, numRows );
    }

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_DELETED,
                                pos,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

bool myGridStringTable::InsertCols( size_t pos, size_t numCols )
{
    size_t row, col;

    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0
                         ? m_data[0].GetCount()
                         : ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    if ( pos >= curNumCols )
    {
        return AppendCols( numCols );
    }

    if ( !m_colLabels.IsEmpty() )
    {
        m_colLabels.Insert( wxEmptyString, pos, numCols );

        size_t i;
        for ( i = pos; i < pos + numCols; i++ )
            m_colLabels[i] = wxGridTableBase::GetColLabelValue( i );
    }

    for ( row = 0; row < curNumRows; row++ )
    {
        for ( col = pos; col < pos + numCols; col++ )
        {
            m_data[row].Insert( wxEmptyString, col );
        }
    }

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_COLS_INSERTED,
                                pos,
                                numCols );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

bool myGridStringTable::AppendCols( size_t numCols )
{
    size_t row;

    size_t curNumRows = m_data.GetCount();

#if 0
    if ( !curNumRows )
    {
        // TODO: something better than this ?
        //
        wxFAIL_MSG( wxT("Unable to append cols to a grid table with no rows.\nCall AppendRows() first") );
        return false;
    }
#endif

    for ( row = 0; row < curNumRows; row++ )
    {
        m_data[row].Add( wxEmptyString, numCols );
    }

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_COLS_APPENDED,
                                numCols );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

bool myGridStringTable::DeleteCols( size_t pos, size_t numCols )
{
    size_t row;

    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0 ? m_data[0].GetCount() :
                          ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    if ( pos >= curNumCols )
    {
        wxFAIL_MSG( wxString::Format
                    (
                        wxT("Called myGridStringTable::DeleteCols(pos=%lu, N=%lu)\nPos value is invalid for present table with %lu cols"),
                        (unsigned long)pos,
                        (unsigned long)numCols,
                        (unsigned long)curNumCols
                    ) );
        return false;
    }

    int colID;
    if ( GetView() )
        colID = GetView()->GetColAt( pos );
    else
        colID = pos;

    if ( numCols > curNumCols - colID )
    {
        numCols = curNumCols - colID;
    }

    if ( !m_colLabels.IsEmpty() )
    {
        // m_colLabels stores just as many elements as it needs, e.g. if only
        // the label of the first column had been set it would have only one
        // element and not numCols, so account for it
        int nToRm = m_colLabels.size() - colID;
        if ( nToRm > 0 )
            m_colLabels.RemoveAt( colID, nToRm );
    }

    for ( row = 0; row < curNumRows; row++ )
    {
        if ( numCols >= curNumCols )
        {
            m_data[row].Clear();
        }
        else
        {
            m_data[row].RemoveAt( colID, numCols );
        }
    }

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_COLS_DELETED,
                                pos,
                                numCols );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}

wxString myGridStringTable::GetRowLabelValue( int row )
{
    if ( row > (int)(m_rowLabels.GetCount()) - 1 )
    {
        // using default label
        //
        return wxGridTableBase::GetRowLabelValue( row );
    }
    else
    {
        return m_rowLabels[row];
    }
}

wxString myGridStringTable::GetColLabelValue( int col )
{
    if ( col > (int)(m_colLabels.GetCount()) - 1 )
    {
        // using default label
        //
        return wxGridTableBase::GetColLabelValue( col );
    }
    else
    {
        return m_colLabels[col];
    }
}

void myGridStringTable::SetRowLabelValue( int row, const wxString& value )
{
    if ( row > (int)(m_rowLabels.GetCount()) - 1 )
    {
        int n = m_rowLabels.GetCount();
        int i;

        for ( i = n; i <= row; i++ )
        {
            m_rowLabels.Add( wxGridTableBase::GetRowLabelValue(i) );
        }
    }

    m_rowLabels[row] = value;
}

void myGridStringTable::SetColLabelValue( int col, const wxString& value )
{
    if ( col > (int)(m_colLabels.GetCount()) - 1 )
    {
        int n = m_colLabels.GetCount();
        int i;

        for ( i = n; i <= col; i++ )
        {
            m_colLabels.Add( wxGridTableBase::GetColLabelValue(i) );
        }
    }

    m_colLabels[col] = value;
}


/////////////////////// Cold Finger Conviniece /////////////////////
////////////////////////////////////////////////////////////////////
//#include <wx/dnd.h>

ColdFinger::ColdFinger( LogbookDialog* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	dialog =  parent;

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( ColdFinger::m_splitter2OnIdle ), NULL, this );
	
	m_panel18 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	m_treeCtrl3 = new wxTreeCtrl( m_panel18, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_EDIT_LABELS );
	m_menu9 = new wxMenu();
	wxMenuItem* m_menuItem24;
	m_menuItem24 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Add Item") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItem24 );
	
	wxMenuItem* m_menuItem25;
	m_menuItem25 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Delete Item") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItem25 );
	
	wxMenuItem* m_menuItem26;
	m_menuItem26 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Rename Item") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItem26 );
	
	m_menu9->AppendSeparator();
	
	wxMenuItem* m_menuItem27;
	m_menuItem27 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Add Treenode") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItem27 );
	
	wxMenuItem* m_menuItem28;
	m_menuItem28 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Delete Treenode") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItem28 );
	
	
	bSizer30->Add( m_treeCtrl3, 1, wxALL|wxEXPAND, 5 );
	
	m_panel18->SetSizer( bSizer30 );
	m_panel18->Layout();
	bSizer30->Fit( m_panel18 );
	m_panel19 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText97 = new wxStaticText( m_panel19, wxID_ANY, _("Text"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText97->Wrap( -1 );
	m_staticText97->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer31->Add( m_staticText97, 0, wxALL|wxEXPAND, 5 );
	
	m_textCtrl73 = new wxTextCtrl( m_panel19, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer31->Add( m_textCtrl73, 1, wxALL|wxEXPAND, 5 );
	
	m_panel19->SetSizer( bSizer31 );
	m_panel19->Layout();
	bSizer31->Fit( m_panel19 );
	m_splitter2->SplitVertically( m_panel18, m_panel19, 0 );
	bSizer27->Add( m_splitter2, 1, wxEXPAND, 5 );
	
	m_sdbSizer8 = new wxStdDialogButtonSizer();
	m_sdbSizer8OK = new wxButton( this, wxID_OK );
	m_sdbSizer8->AddButton( m_sdbSizer8OK );
	m_sdbSizer8Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer8->AddButton( m_sdbSizer8Cancel );
	m_sdbSizer8->Realize();
	bSizer27->Add( m_sdbSizer8, 0, wxALIGN_CENTER, 5 );
	
	this->SetSizer( bSizer27 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ColdFinger::OnCloseCold ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ColdFinger::OnInitDialog ) );
	m_treeCtrl3->Connect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( ColdFinger::OnTreeBeginDragCold ), NULL, this );
	m_treeCtrl3->Connect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( ColdFinger::OnTreeBeginDragCold ), NULL, this );
	m_treeCtrl3->Connect( wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, wxTreeEventHandler( ColdFinger::OnTreeItemRightClickCold ), NULL, this );
	m_treeCtrl3->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( ColdFinger::OnTreeSelChanged ), NULL, this );
	this->Connect( m_menuItem24->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionAddCold ) );
	this->Connect( m_menuItem25->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionDeleteCold ) );
	this->Connect( m_menuItem26->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionRenameCold ) );
	this->Connect( m_menuItem27->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionaddNodeCold ) );
	this->Connect( m_menuItem28->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuTreeSelectionDeleteNodeCold ) );
	m_textCtrl73->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ColdFinger::OnTextCold ), NULL, this );
	m_sdbSizer8OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ColdFinger::OnOKButtonClickCold ), NULL, this );
	m_sdbSizer8Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ColdFinger::OnCancelButtonClickCold ), NULL, this );

	init();
}

ColdFinger::~ColdFinger()
{
	writeTextblocks();

	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ColdFinger::OnCloseCold ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ColdFinger::OnInitDialog ) );
	m_treeCtrl3->Disconnect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( ColdFinger::OnTreeBeginDragCold ), NULL, this );
	m_treeCtrl3->Disconnect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( ColdFinger::OnTreeBeginDragCold ), NULL, this );
	m_treeCtrl3->Disconnect( wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, wxTreeEventHandler( ColdFinger::OnTreeItemRightClickCold ), NULL, this );
	m_treeCtrl3->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( ColdFinger::OnTreeSelChanged ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionAddCold ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionDeleteCold ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionRenameCold ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuSelectionaddNodeCold ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ColdFinger::OnMenuTreeSelectionDeleteNodeCold ) );
	m_textCtrl73->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ColdFinger::OnTextCold ), NULL, this );
	m_sdbSizer8OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ColdFinger::OnOKButtonClickCold ), NULL, this );
	m_sdbSizer8Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ColdFinger::OnCancelButtonClickCold ), NULL, this );

	delete m_menu9;
}

void ColdFinger::OnCloseCold( wxCloseEvent& event )
{
	if(modified)
	{
		((myTreeItem*)m_treeCtrl3->GetItemData(m_treeCtrl3->GetSelection()))->text = m_textCtrl73->GetValue();
		writeTextblocks();
	}

	retItem = NULL;
	Hide();
}

void ColdFinger::OnOKButtonClickCold( wxCommandEvent& event )
{
	if(modified)
	{
		((myTreeItem*)m_treeCtrl3->GetItemData(m_treeCtrl3->GetSelection()))->text = m_textCtrl73->GetValue();
		writeTextblocks();
	}

	retItem = (myTreeItem*)m_treeCtrl3->GetItemData(m_treeCtrl3->GetSelection());
	if(retItem->type == NODE)
		retItem = NULL;

	Hide();
}

void ColdFinger::OnCancelButtonClickCold( wxCommandEvent& ev )
{
	OnCloseCold( (wxCloseEvent&)ev );
}

#include "xmblue.xpm"
#include <wx/imaglist.h>
void ColdFinger::init()
{
	imageList = new wxImageList();
	imageList->Create(16,16);
	fo = imageList->Add(wxBitmap (folder));
	it = imageList->Add(wxBitmap (xmblue));
	m_treeCtrl3->SetImageList(imageList);

	dataPath = *(dialog->pHome_Locn);
	dataPath += _T("data");
	dataPath += wxFileName::GetPathSeparator();
	dataPath += _T("Textblocks.xml");

	loadTextBlocks();

	if(!m_treeCtrl3->GetRootItem().IsOk())
	{
		myTreeItem *item = new myTreeItem(NODE,_("Textblocks"),
			_("Help\n-----\n\nOpen treenode\n  \'Texts when using this Dialog only\'\n  and select e.g. \'Remarks\'\n\nRightclick in TreeView for menu\n\nAdd a item and rename it\n   USE UNIQUE NAMES FOR ITEMS !\n\nInsert text\n\nIn \'Texts when using this Dialog only\' you can insert/delete treenodes only\n\nUse Drag \'n Drop to move item from/to menu\n\nsee next treenodes for more help"),_T(""),_T(""),_T(""),_T(""),0,0,false,true,false);
		selectedItem = m_treeCtrl3->AddRoot(item->name,fo,-1,item);
		m_textCtrl73->SetValue(item->text);

		item = new myTreeItem(NODE,_T(""),_("The itemname is shown in the rightcklick-menu of the following Columns\nBy clicking on it the text is inserted\n\n")+
			dialog->m_gridGlobal->GetColLabelValue(Logbook::REMARKS)+_T("\n")+
			dialog->m_gridWeather->GetColLabelValue(Logbook::WEATHER-11)+_T("\n")+
			dialog->m_gridWeather->GetColLabelValue(Logbook::VISIBILITY-11)+_T("\n")+
			dialog->m_gridMotorSails->GetColLabelValue(Logbook::SAILS-24)+_T("\n")+
			dialog->m_gridMotorSails->GetColLabelValue(Logbook::REEF-24)+_T("\n")+
			dialog->m_gridMotorSails->GetColLabelValue(Logbook::MREMARKS-24)
			,_T(""),_T(""),_T(""),_T(""),-1,0,false,false,true);
		wxTreeItemId menu = this->m_treeCtrl3->AppendItem(selectedItem,_("Texts for Rightclick-Menu"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),0,Logbook::REMARKS,false,false,true);
		wxTreeItemId test = this->m_treeCtrl3->AppendItem(menu,dialog->m_gridGlobal->GetColLabelValue(Logbook::REMARKS)+_T(" (")+
			dialog->m_notebook8->GetPageText(0)+_T(")"),-fo,-1,item);

		item = new myTreeItem(ITEM,_T(""),_("Sails up\nEngine stopped\n\nDemo - Rightclick-Menu \'use Testextblocks\' for help"),_T(""),_T(""),_T(""),_T(""),0,Logbook::REMARKS,true,false,true);
		this->m_treeCtrl3->AppendItem(test,_("Demo Sails up"),it,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),1,Logbook::WEATHER-dialog->logbook->weatherCol,false,false,true);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridWeather->GetColLabelValue(Logbook::WEATHER-dialog->logbook->weatherCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(1)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),1,Logbook::VISIBILITY-dialog->logbook->weatherCol,false,false,true);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridWeather->GetColLabelValue(Logbook::VISIBILITY-dialog->logbook->weatherCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(1)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::SAILS-dialog->logbook->sailsCol,false,false,true);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::SAILS-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::REEF-dialog->logbook->sailsCol,false,false,true);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::REEF-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::MREMARKS-dialog->logbook->sailsCol,false,false,true);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::MREMARKS-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);

/////////////////// in dialog only ////////////
		item = new myTreeItem(NODE,_T(""),_("These texts are inserted into the grid-colmn\nby calling this dialog\n\nSelect Item\nClick OK-Button\n\nUse Drag \'n Drop to place a item in menu"),_T(""),_T(""),_T(""),_T(""),-2,0,false,false,false);
		menu = this->m_treeCtrl3->AppendItem(selectedItem,_("Texts when using this Dialog only"),fo,0,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),0,Logbook::REMARKS,false,true,false);
		test = this->m_treeCtrl3->AppendItem(menu,dialog->m_gridGlobal->GetColLabelValue(Logbook::REMARKS)+_T(" (")+
			dialog->m_notebook8->GetPageText(0)+_T(")"),-fo,-1,item);

		item = new myTreeItem(ITEM,_T(""),_("Engine stopped\n\nDemo - Rightclick-Menu \'use Testextblocks\' for help"),_T(""),_T(""),_T(""),_T(""),0,Logbook::REMARKS,true,true,false);
		this->m_treeCtrl3->AppendItem(test,_("Demo Engine stopped"),it,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),1,Logbook::WEATHER-dialog->logbook->weatherCol,false,true,false);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridWeather->GetColLabelValue(Logbook::WEATHER-dialog->logbook->weatherCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(1)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),1,Logbook::VISIBILITY-dialog->logbook->weatherCol,false,true,false);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridWeather->GetColLabelValue(Logbook::VISIBILITY-dialog->logbook->weatherCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(1)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::SAILS-dialog->logbook->sailsCol,false,true,false);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::SAILS-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::REEF-dialog->logbook->sailsCol,false,true,false);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::REEF-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);

		item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),2,Logbook::MREMARKS-dialog->logbook->sailsCol,false,true,false);
		this->m_treeCtrl3->AppendItem(menu,dialog->m_gridMotorSails->GetColLabelValue(Logbook::MREMARKS-dialog->logbook->sailsCol)+_T(" (")+
			dialog->m_notebook8->GetPageText(2)+_T(")"),fo,-1,item);
		
		modified = true;
		this->writeTextblocks();
	}
	else
	{
		modified = false;
	}

	selectedItem = m_treeCtrl3->GetRootItem();
	m_treeCtrl3->SetFocus();
	m_treeCtrl3->SelectItem(selectedItem);
	m_treeCtrl3->Expand(selectedItem);
	retItem = NULL;

	SetDropTarget(new DnD(this,m_treeCtrl3,m_treeCtrl3));
}

void ColdFinger::OnInitDialog(wxInitDialogEvent& event)
{

}

void ColdFinger::OnTreeSelChanged( wxTreeEvent& event )
{   
	if(modified && selectedItem.IsOk())
		((myTreeItem*)m_treeCtrl3->GetItemData(selectedItem))->text = m_textCtrl73->GetValue();

	wxString t = ((myTreeItem*)m_treeCtrl3->GetItemData(event.GetItem()))->text;
	selectedItem = event.GetItem();

	m_textCtrl73->SetValue(t);
	modified = false;
}

void ColdFinger::OnMenuSelectionaddNodeCold( wxCommandEvent& event )
{
	static int i = 1;
	wxTreeItemId parent;

	myTreeItem *item = new myTreeItem(NODE,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),fo,0,true,true,false);

	if(((myTreeItem*)this->m_treeCtrl3->GetItemData(selectedItem))->type ==  ITEM)
		parent = this->m_treeCtrl3->GetItemParent(selectedItem);
	else
		parent = selectedItem;

	myTreeItem* parentdata = ((myTreeItem*)this->m_treeCtrl3->GetItemData(parent));
	item->grid		 = parentdata->grid;
	item->gridcol	 = parentdata->gridcol;
	item->add		 = true;
	item->deleteable = true;
	item->menu       = parentdata->menu;

	selectedItem = m_treeCtrl3->AppendItem(parent,wxString::Format(_("New Node%i"),i++),fo,-1,item);
	m_treeCtrl3->SelectItem(selectedItem);
	m_treeCtrl3->EditLabel(selectedItem);
	modified = true;
}

void ColdFinger::OnMenuTreeSelectionDeleteNodeCold( wxCommandEvent& event )
{
	if(m_treeCtrl3->GetSelection() == m_treeCtrl3->GetRootItem()) return;
	if(((myTreeItem*)m_treeCtrl3->GetItemData(selectedItem))->deleteable == false ||
	  ((myTreeItem*)m_treeCtrl3->GetItemData(selectedItem))->type == ITEM)
	  return;

	m_treeCtrl3->Delete(selectedItem);
	selectedItem = m_treeCtrl3->GetItemParent(selectedItem);
	modified = true;
}

void ColdFinger::OnMenuSelectionAddCold( wxCommandEvent& event )
{
	static int i = 1;
	wxTreeItemId parent;

	myTreeItem *item = new myTreeItem(ITEM,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),it,0,true,true,false);

	if(((myTreeItem*)this->m_treeCtrl3->GetItemData(m_treeCtrl3->GetSelection()))->type ==  ITEM)
		parent = this->m_treeCtrl3->GetItemParent(selectedItem);
	else
		parent = selectedItem;

	myTreeItem* parentdata = ((myTreeItem*)this->m_treeCtrl3->GetItemData(parent));
	item->grid		 = parentdata->grid;
	item->gridcol	 = parentdata->gridcol;
	item->add		 = true;
	item->deleteable = true;
	item->menu       = parentdata->menu;

	selectedItem = m_treeCtrl3->AppendItem(parent,wxString::Format(_("New Item%i"),i++),it,-1,item);
	m_treeCtrl3->SelectItem(selectedItem);
	m_treeCtrl3->EditLabel(selectedItem);
	modified = true;
}

void ColdFinger::OnTreeItemRightClickCold( wxTreeEvent& event )
{
	if(event.GetItem() == this->m_treeCtrl3->GetRootItem()) return;


	selectedItem = event.GetItem();
	m_treeCtrl3->SelectItem(selectedItem);

	myTreeItem* item = ((myTreeItem*)this->m_treeCtrl3->GetItemData(selectedItem));

	if(item->grid == -1 || item->grid == -2) return;

	if(item->deleteable == false)
		m_menu9->Enable(m_menu9->FindItem(_("Delete Treenode")),false);
	else
		m_menu9->Enable(m_menu9->FindItem(_("Delete Treenode")),true);

	if(item->add == false)
		m_menu9->Enable(m_menu9->FindItem(_("Add Treenode")),false);
	else
		m_menu9->Enable(m_menu9->FindItem(_("Add Treenode")),true);

	m_treeCtrl3->PopupMenu( m_menu9 );
}

void ColdFinger::OnMenuSelectionDeleteCold( wxCommandEvent& event )
{
	if(((myTreeItem*)this->m_treeCtrl3->GetItemData(selectedItem))->deleteable == false ||
		((myTreeItem*)this->m_treeCtrl3->GetItemData(selectedItem))->type == NODE) return;

	if(selectedItem != m_treeCtrl3->GetRootItem())
	{
		m_treeCtrl3->Delete(selectedItem);
		selectedItem = m_treeCtrl3->GetItemParent(selectedItem);
		modified = true;
	}
}

void ColdFinger::OnMenuSelectionRenameCold( wxCommandEvent& event )
{
	modified = true;
	m_treeCtrl3->EditLabel(m_treeCtrl3->GetSelection());
}

void ColdFinger::OnTextCold( wxCommandEvent& event )
{
	modified = true;
}

void ColdFinger::writeTextblocks()
{
	if(!modified) 
		return;

	TiXmlDocument doc(dataPath.mb_str(wxConvUTF8));  
	
 	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "UTF-8", "" );  
	doc.LinkEndChild( decl ); 

	myTreeItem* item;
	item = (myTreeItem*) m_treeCtrl3->GetItemData(m_treeCtrl3->GetRootItem());

	TiXmlElement *root = new TiXmlElement("TextblocksXML");
	doc.LinkEndChild( root ); 	

	root->SetAttribute( "Name",item->name.mb_str(wxConvUTF8) );
	root->SetAttribute( "Helptext",item->text.mb_str(wxConvUTF8) );
	recursiveWrite(m_treeCtrl3->GetRootItem(), root);
	doc.SaveFile();
}

void ColdFinger::addElement(TiXmlElement* root, const char* key, const char* label)
{
	TiXmlElement* celem = new TiXmlElement(key);
	celem->LinkEndChild(new TiXmlText(label));
	root->LinkEndChild(celem);		
}

wxTreeItemId ColdFinger::recursiveWrite(wxTreeItemId id, TiXmlElement *elem)
{
	wxTreeItemIdValue cookie;
	wxTreeItemId child;
    wxTreeItemId item = m_treeCtrl3->GetFirstChild(id, cookie );
	TiXmlElement *newElement;

	while( item.IsOk() )
	{
		wxString sData = m_treeCtrl3->GetItemText(item);
		myTreeItem* data = (myTreeItem*) m_treeCtrl3->GetItemData(item);
//wxMessageBox(sData);						
		newElement = new TiXmlElement((data->type)?"ITEM":"NODE");					

			
		addElement(newElement,"Type",wxString::Format(_T("%i"),data->type).mb_str());
		addElement(newElement,"Name",sData.mb_str(wxConvUTF8));
		addElement(newElement,"Text",data->text.mb_str(wxConvUTF8));
		addElement(newElement,"GUID",data->guid.mb_str(wxConvUTF8));
		addElement(newElement,"Route",data->route.mb_str(wxConvUTF8));							
		addElement(newElement,"GUIDWP",data->guidWP.mb_str(wxConvUTF8));
		addElement(newElement,"WP",data->WP.mb_str(wxConvUTF8));
		addElement(newElement,"Grid",wxString::Format(_T("%i"),data->grid).mb_str());
		addElement(newElement,"Column",wxString::Format(_T("%i"),data->gridcol).mb_str());
		addElement(newElement,"Deleteable",wxString::Format(_T("%s"),(data->deleteable)?_T("true"):_T("false")).mb_str());
		addElement(newElement,"Add",wxString::Format(_T("%s"),(data->add)?_T("true"):_T("false")).mb_str());
		addElement(newElement,"Menu",wxString::Format(_T("%s"),(data->menu)?_T("true"):_T("false")).mb_str());

		if( m_treeCtrl3->ItemHasChildren( item ) )
			recursiveWrite( item, newElement );

		elem->LinkEndChild(newElement);
		item = m_treeCtrl3->GetNextSibling(item);
	}
     
	/* Not found */
	wxTreeItemId dummy;
	return dummy;	
}

void ColdFinger::loadTextBlocks()
{
	TiXmlDocument doc(dataPath.mb_str(wxConvUTF8));
	bool ok = doc.LoadFile();

	if(ok)
		fillTree(m_treeCtrl3->GetRootItem(), &doc);

	modified = false;
}

void ColdFinger::fillTree(wxTreeItemId id, TiXmlNode* node)
{
	TiXmlNode* pChild;
	static myTreeItem* elem	;
	int t = node->Type();

	switch ( t )
	{
	case TiXmlNode::TINYXML_ELEMENT:
		if(wxString(node->Value(),wxConvUTF8) == _T("TextblocksXML"))
		{
			wxString name,text;
			TiXmlAttribute* pAttrib=node->ToElement()->FirstAttribute();
			if(wxString(pAttrib->Name(),wxConvUTF8) == _T("Name"))
				name = wxString(pAttrib->Value(),wxConvUTF8);
			pAttrib=pAttrib->Next();
			if(wxString(pAttrib->Name(),wxConvUTF8) == _T("Helptext"))
				text = wxString(pAttrib->Value(),wxConvUTF8);

			elem = new myTreeItem(NODE,name,text,_T(""),_T(""),_T(""),_T(""),0,0,false,false,false);
			id = m_treeCtrl3->AddRoot(name,fo,-1,elem);
		}
		if(wxString(node->Value(),wxConvUTF8) == _T("NODE"))
		{
			elem = new myTreeItem(0,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),0,0,false,false,false);
			id = m_treeCtrl3->AppendItem(id,_T(""),fo,-1,elem);
		}
		if(wxString(node->Value(),wxConvUTF8) == _T("ITEM"))
		{
			elem = new myTreeItem(1,_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),0,0,false,false,false);
			id = m_treeCtrl3->AppendItem(id,_T(""),it,-1,elem);
		}

		if(wxString(node->Value(),wxConvUTF8) == _T("Type"))
		{
			elem->type = atoi(node->ToElement()->GetText());
			m_treeCtrl3->SetItemText(id,elem->name);
		}
		if(wxString(node->Value(),wxConvUTF8) == _T("Name"))
		{
			elem->name = wxString(node->ToElement()->GetText(),wxConvUTF8);
			m_treeCtrl3->SetItemText(id,elem->name);
		}
		if(wxString(node->Value(),wxConvUTF8) == _T("Text"))
			elem->text = wxString(node->ToElement()->GetText(),wxConvUTF8);

		if(wxString(node->Value(),wxConvUTF8) == _T("Grid"))
		{
			elem->grid = atoi(node->ToElement()->GetText());
			m_treeCtrl3->SetItemText(id,elem->name);
		}

		if(wxString(node->Value(),wxConvUTF8) == _T("Column"))
			elem->gridcol = atoi(node->ToElement()->GetText());

		if(wxString(node->Value(),wxConvUTF8) == _T("Deleteable"))
			elem->deleteable = (wxString(node->ToElement()->GetText(),wxConvUTF8) == _T("true"))?true:false;

		if(wxString(node->Value(),wxConvUTF8) == _T("Add"))
			elem->add = (wxString(node->ToElement()->GetText(),wxConvUTF8) == _T("true"))?true:false;

		if(wxString(node->Value(),wxConvUTF8) == _T("Menu"))
			elem->menu = (wxString(node->ToElement()->GetText(),wxConvUTF8) == _T("true"))?true:false;
		break;
	}

	for ( pChild = node->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
	{
		fillTree( id, pChild );
	}
}

void ColdFinger::OnTreeBeginDragCold( wxTreeEvent& event )
{
	selectedItem = event.GetItem();
	this->m_textCtrl73->SetValue(((myTreeItem*)m_treeCtrl3->GetItemData(selectedItem))->text);
	m_treeCtrl3->SelectItem(selectedItem);

	if(((myTreeItem*)this->m_treeCtrl3->GetItemData(selectedItem))->type == NODE)
		return;

	wxTextDataObject o(m_treeCtrl3->GetItemText(selectedItem));
	wxDropSource dragSource( m_treeCtrl3 );
	dragSource.SetData( o );
	wxDragResult result = dragSource.DoDragDrop( TRUE );

	switch (result)
	{
	    case wxDragCopy: /* copy the data */
			modified = true;
			break;
	    case wxDragMove: /* move the data */
			modified = true;
			break;
	    default:         /* do nothing */ break;
	}

}

/////////////////// used in ColdFinger /////////////////
myTreeItem::myTreeItem( int type, wxString name, wxString text, wxString guid, wxString route, wxString guidWP, wxString WP, int grid, int gridcol, bool deleteable, bool add, bool menu )
{
	this->type       = type;
	this->name       = name;
	this->text       = text;
	this->guidWP     = guidWP;
	this->route      = route;
	this->guidWP     = guidWP;
	this->WP         = WP;
	this->grid       = grid;
	this->gridcol    = gridcol;
	this->deleteable = deleteable;
	this->add        = add;
	this->menu   	 = menu;
}

myTreeItem::myTreeItem(const myTreeItem* item)
{
	this->type       = item->type;
	this->name       = item->name;
	this->text       = item->text;
	this->guidWP     = item->guidWP;
	this->route      = item->route;
	this->guidWP     = item->guidWP;
	this->WP         = item->WP;
	this->grid       = item->grid;
	this->gridcol    = item->gridcol;
	this->deleteable = item->deleteable;
	this->add        = item->add;
	this->menu   	 = item->menu;
}


bool DnD::OnDropText(wxCoord x, wxCoord y, const wxString& str)
{
	wxTreeItemId id,parent;

	id = m_pOwner->HitTest(wxPoint(x,y));
	if( id == m_pOwner->GetRootItem()) return false;
	myTreeItem* my = (myTreeItem*)m_pOwner->GetItemData(id);

	if(my->grid == -1 || my->grid == -2) return false;

	if(my->type == ColdFinger::NODE)
		parent = id;
	else
		parent = m_pOwner->GetItemParent(id);

	myTreeItem* parentmy = (myTreeItem*)m_pOwner->GetItemData(dialog->selectedItem);
	wxString s = m_pOwner->GetItemText(dialog->selectedItem);

	parentmy->type       = ColdFinger::ITEM;
	parentmy->grid       = my->grid;
	parentmy->gridcol    = my->gridcol;
	parentmy->deleteable = true;
	parentmy->add        = false;
	parentmy->menu       = my->menu;

	myTreeItem* newmy = new myTreeItem(parentmy);
	wxTreeItemId newId = m_pOwner->InsertItem(parent,(newmy->type == ColdFinger::NODE)?wxTreeItemId():id,s,(newmy->type == ColdFinger::NODE)?dialog->fo:dialog->it,-1,newmy);

	m_pOwner->Delete(dialog->selectedItem);
	dialog->selectedItem = newId;
	dialog->m_textCtrl73->SetValue(newmy->text);
	m_pOwner->SelectItem(newId);
	m_pOwner->Expand(id);
	//m_pOwner->ExpandAll();
//	m_pOwner->Refresh();

    return true;
}

////////////// Timer-Interval Dialog ///////
TimerInterval::TimerInterval( wxWindow* parent, Options* opt, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_spinCtrlH = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 24, 24 );
	bSizer33->Add( m_spinCtrlH, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextH = new wxStaticText( this, wxID_ANY, opt->motorh.c_str(), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextH->Wrap( -1 );
	bSizer33->Add( m_staticTextH, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_spinCtrlM = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	bSizer33->Add( m_spinCtrlM, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextM = new wxStaticText( this, wxID_ANY, _T("m"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextM->Wrap( -1 );
	bSizer33->Add( m_staticTextM, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	m_spinCtrlS = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	bSizer33->Add( m_spinCtrlS, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextS = new wxStaticText( this, wxID_ANY, _T("s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextS->Wrap( -1 );
	bSizer33->Add( m_staticTextS, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0 );
	
	bSizer32->Add( bSizer33, 1, wxEXPAND, 5 );
	
	m_sdbSizer9 = new wxStdDialogButtonSizer();
	m_sdbSizer9OK = new wxButton( this, wxID_OK );
	m_sdbSizer9->AddButton( m_sdbSizer9OK );
	m_sdbSizer9Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer9->AddButton( m_sdbSizer9Cancel );
	m_sdbSizer9->Realize();
	bSizer32->Add( m_sdbSizer9, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer32 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sdbSizer9OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TimerInterval::OnButtonOKClick ), NULL, this );
	init(opt, (LogbookDialog*)parent);
}

TimerInterval::~TimerInterval()
{
	// Disconnect Events
	m_sdbSizer9OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TimerInterval::OnButtonOKClick ), NULL, this );
	
}

void TimerInterval::OnButtonOKClick( wxCommandEvent& event )
{
	opt->thour = wxString::Format(_T("%i"),this->m_spinCtrlH->GetValue());
	opt->tmin  = wxString::Format(_T("%i"),this->m_spinCtrlM->GetValue());
	opt->tsec  = wxString::Format(_T("%i"),this->m_spinCtrlS->GetValue());

	opt->timerSec = (m_spinCtrlH->GetValue()  * 3600000 +
					 m_spinCtrlM->GetValue() * 60000   +
					 m_spinCtrlS->GetValue() * 1000);

	dialog->setTitleExt();

	if(timerruns && opt->timerSec > 0)
	{
		dialog->logbookPlugIn->m_timer->Start(opt->timerSec);
		dialog->SetTitle(dialog->GetTitle()+ dialog->titleExt);
	}
	else
	{
		dialog->logbookPlugIn->m_timer->Stop();
		opt->timer = false;
	}

	Close();
}

void TimerInterval::init(Options* opt, LogbookDialog* dialog)
{
	this->opt = opt;
	this->dialog = dialog;
	timerruns = false;

	if(dialog->logbookPlugIn->m_timer->IsRunning())
	{
		dialog->logbookPlugIn->m_timer->Stop();
		timerruns = true;
		dialog->SetTitle(dialog->GetTitle().BeforeFirst('-'));
	}
	
	m_spinCtrlH->SetValue(opt->thour);
	m_spinCtrlM->SetValue(opt->tmin);
	m_spinCtrlS->SetValue(opt->tsec);

}

//////////////// Dialog PositionDlg ////////////////
PositionDlg::PositionDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer44;
	fgSizer44 = new wxFlexGridSizer( 0, 9, 0, 0 );
	fgSizer44->SetFlexibleDirection( wxBOTH );
	fgSizer44->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_textCtrlDeg1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer44->Add( m_textCtrlDeg1, 0, wxALL, 5 );
	
	m_staticTextDeg1 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDeg1->Wrap( -1 );
	fgSizer44->Add( m_staticTextDeg1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlmin1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer44->Add( m_textCtrlmin1, 0, wxALL, 5 );
	
	m_staticTextmin1 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextmin1->Wrap( -1 );
	fgSizer44->Add( m_staticTextmin1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlsec1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer44->Add( m_textCtrlsec1, 0, wxALL, 5 );
	
	m_staticTextsec1 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextsec1->Wrap( -1 );
	fgSizer44->Add( m_staticTextsec1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNS = new wxTextCtrl( this, wxID_ANY, wxT("N"), wxDefaultPosition, wxSize( 25,-1 ), 0 );
	fgSizer44->Add( m_textCtrlNS, 0, wxALL, 5 );
	
	bSizer34->Add( fgSizer44, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	fgSizer441 = new wxFlexGridSizer( 0, 9, 0, 0 );
	fgSizer441->SetFlexibleDirection( wxBOTH );
	fgSizer441->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_textCtrlDeg2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer441->Add( m_textCtrlDeg2, 0, wxALL, 5 );
	
	m_staticTextDeg2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDeg2->Wrap( -1 );
	fgSizer441->Add( m_staticTextDeg2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlmin2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer441->Add( m_textCtrlmin2, 0, wxALL, 5 );
	
	m_staticTextmin2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextmin2->Wrap( -1 );
	fgSizer441->Add( m_staticTextmin2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlsec2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer441->Add( m_textCtrlsec2, 0, wxALL, 5 );
	
	m_staticTextsec2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextsec2->Wrap( -1 );
	fgSizer441->Add( m_staticTextsec2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlWE = new wxTextCtrl( this, wxID_ANY, wxT("W"), wxDefaultPosition, wxSize( 25,-1 ), 0 );
	fgSizer441->Add( m_textCtrlWE, 0, wxALL, 5 );
	
	bSizer34->Add( fgSizer441, 0, wxALIGN_RIGHT, 5 );
	
	bSizer35->Add( bSizer34, 1, wxEXPAND, 5 );
	
	wxArrayString m_choiceFormatChoices;
	m_choiceFormat = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFormatChoices, 0 );
	m_choiceFormat->SetSelection( 0 );
	bSizer35->Add( m_choiceFormat, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sdbSizer10 = new wxStdDialogButtonSizer();
	m_sdbSizer10OK = new wxButton( this, wxID_OK );
	m_sdbSizer10->AddButton( m_sdbSizer10OK );
	m_sdbSizer10Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer10->AddButton( m_sdbSizer10Cancel );
	m_sdbSizer10->Realize();
	bSizer35->Add( m_sdbSizer10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer35 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sdbSizer10Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PositionDlg::OnCancelButtonClick ), NULL, this );
	m_sdbSizer10OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PositionDlg::OnOKButtonClick ), NULL, this );
	m_choiceFormat->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PositionDlg::OnChoice ), NULL, this );


	init((LogbookDialog*)parent);
}

PositionDlg::~PositionDlg()
{
	m_choiceFormat->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PositionDlg::OnChoice ), NULL, this );
	m_sdbSizer10Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PositionDlg::OnCancelButtonClick ), NULL, this );
	m_sdbSizer10OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PositionDlg::OnOKButtonClick ), NULL, this );
}

void PositionDlg::init(LogbookDialog* dlg)
{
	this->dlg = dlg;
	Options* opt = dlg->logbookPlugIn->opt;

	m_staticTextDeg1->SetLabel(opt->Deg);
	m_staticTextDeg2->SetLabel(opt->Deg);
	m_staticTextmin1->SetLabel(opt->Min);
	m_staticTextmin2->SetLabel(opt->Min);
	m_staticTextsec1->SetLabel(opt->Sec);
	m_staticTextsec2->SetLabel(opt->Sec);

	m_choiceFormat->Append(wxT("054\xB0 12.1234'"));
	m_choiceFormat->Append(wxT("054\xB0 12' 12.34\""));
	m_choiceFormat->Select(opt->traditional);
	oldSel = m_choiceFormat->GetSelection();

	wxString tmp = dlg->m_gridGlobal->GetCellValue(dlg->selGridRow,Logbook::POSITION);
	if(tmp.IsEmpty() && dlg->selGridRow != 0)
		tmp = dlg->m_gridGlobal->GetCellValue(dlg->selGridRow-1,Logbook::POSITION);

	if(tmp.Contains(_T("\"")))
	{
		m_textCtrlDeg1->SetValue(tmp.substr(0,3));
		m_textCtrlmin1->SetValue(tmp.substr(5,2));
		m_textCtrlsec1->SetValue(tmp.substr(9,5));
		m_textCtrlNS->  SetValue(tmp.substr(16,1));
		m_textCtrlDeg2->SetValue(tmp.substr(18,3));
		m_textCtrlmin2->SetValue(tmp.substr(23,2));
		m_textCtrlsec2->SetValue(tmp.substr(27,5));
		m_textCtrlWE->SetLabel(tmp.substr(34,1));

		if(!opt->traditional)
			   setFormat(1);
	}
	else if(!tmp.IsEmpty())
	{
		m_textCtrlDeg1->SetValue(tmp.substr(0,3));
		m_textCtrlmin1->SetValue(tmp.substr(5,7));
		m_textCtrlNS->  SetValue(tmp.substr(14,1));
		m_textCtrlDeg2->SetValue(tmp.substr(16,3));
		m_textCtrlmin2->SetValue(tmp.substr(21,7));
		m_textCtrlWE->SetLabel(tmp.substr(30,1));

		if(opt->traditional)
			   setFormat(0);
	}

	if(!opt->traditional)
	{
		m_textCtrlsec1->Enable(false);
		m_textCtrlsec2->Enable(false);
	}

	this->Fit();
}

void PositionDlg::OnChoice( wxCommandEvent& event )
{
	if(event.GetSelection() == oldSel)
		return;

	if(event.GetSelection() == 1)
	{
			m_textCtrlsec1->Enable(true);
			m_textCtrlsec2->Enable(true);
			setFormat(0);
	}
	else
	{
			setFormat(1);
			m_textCtrlsec1->Enable(false);
			m_textCtrlsec2->Enable(false);
	}
	oldSel = event.GetSelection();
}

void PositionDlg::setFormat(int fmt)
{
	//Options* opt = dlg->logbookPlugIn->opt;

	if(fmt)
	{
		double min1,sec1,min2,sec2;
		min1 = wxAtof(replaceComma(m_textCtrlmin1->GetValue()));
		min2 = wxAtof(replaceComma(m_textCtrlmin2->GetValue()));

		sec1 = wxAtof(replaceComma(m_textCtrlsec1->GetValue()))/60;
		sec2 = wxAtof(replaceComma(m_textCtrlsec2->GetValue()))/60;

		min1 += sec1;
		min2 += sec2;

		m_textCtrlmin1->SetValue(wxString::Format(_T("%07.4f"),min1));
		m_textCtrlmin2->SetValue(wxString::Format(_T("%07.4f"),min2));
		m_textCtrlsec1->Clear();
		m_textCtrlsec2->Clear();
	}
	else
	{
		double min1,sec1,min2,sec2;
		min1 = wxAtoi(m_textCtrlmin1->GetValue());
		min2 = wxAtoi(m_textCtrlmin2->GetValue());

		if(m_choiceFormat->GetSelection() == 1)
		{
			sec1 = (wxAtof(replaceComma(m_textCtrlmin1->GetValue()))-(int)min1)*60;
			sec2 = (wxAtof(replaceComma(m_textCtrlmin2->GetValue()))-(int)min2)*60;
		}
		else
		{
			sec1 = wxAtof(replaceComma(m_textCtrlsec1->GetValue()));
			sec2 = wxAtof(replaceComma(m_textCtrlsec2->GetValue()));
		}

		m_textCtrlmin1->SetValue(wxString::Format(_T("%02.0f"),min1));
		m_textCtrlmin2->SetValue(wxString::Format(_T("%02.0f"),min2));
		m_textCtrlsec1->SetValue(wxString::Format(_T("%06.3f"),sec1));
		m_textCtrlsec2->SetValue(wxString::Format(_T("%06.3f"),sec2));
	}
}

wxString PositionDlg::replaceComma(wxString s)
{
	wxString tmp = s;
	tmp.Replace(_T(","),_T("."));
	return tmp;
}

void PositionDlg::OnOKButtonClick( wxCommandEvent& event )
{
	Options* opt = dlg->logbookPlugIn->opt;
	double degf1, degf2,min1,sec1,min2,sec2;

	wxString min1str;
	wxString min2str;
	wxString sec1str;
	wxString sec2str;

	this->m_textCtrlsec1->Enable(true);
	this->m_textCtrlsec2->Enable(true);

	degf1 = wxAtof(m_textCtrlDeg1->GetValue());
	degf2 = wxAtof(m_textCtrlDeg2->GetValue());
	wxString deg1    = wxString::Format(_T("%03.0f"),wxAtof(m_textCtrlDeg1->GetValue()));
	wxString deg2    = wxString::Format(_T("%03.0f"),wxAtof(m_textCtrlDeg2->GetValue()));
	min1 = wxAtof(replaceComma(m_textCtrlmin1->GetValue()));
	min2 = wxAtof(replaceComma(m_textCtrlmin2->GetValue()));

	if(opt->traditional)
	{
		if(this->m_choiceFormat->GetSelection() == 0)
		{
			min1 = (int) min1;
			min2 = (int) min2;
			sec1 = (wxAtof(replaceComma(m_textCtrlmin1->GetValue()))-min1)*60;
			sec2 = (wxAtof(replaceComma(m_textCtrlmin2->GetValue()))-min2)*60;
		}
		else
		{
			sec1 = wxAtof(replaceComma(m_textCtrlsec1->GetValue()));
			sec2 = wxAtof(replaceComma(m_textCtrlsec2->GetValue()));
		}

		min1str = wxString::Format(_T("%02.0f"),min1);
		min2str = wxString::Format(_T("%02.0f"),min2);
		sec1str = wxString::Format(_T("%05.2f"),sec1);
		sec2str = wxString::Format(_T("%05.2f"),sec2);

		retstr = deg1+min1str+sec1str+m_textCtrlNS->GetValue().Lower()+deg2+min2str+sec2str+m_textCtrlWE->GetValue().Lower();
	}
	else
	{
		sec1 = wxAtof(replaceComma(m_textCtrlsec1->GetValue()))/60;
		sec2 = wxAtof(replaceComma(m_textCtrlsec2->GetValue()))/60;

		min1 += sec1;
		min2 += sec2;

		min1str = wxString::Format(_T("%07.4f"),min1);
		min2str = wxString::Format(_T("%07.4f"),min2);

		retstr = deg1+min1str+m_textCtrlNS->GetValue().Lower()+deg2+min2str+m_textCtrlWE->GetValue().Lower();
	}

	wxString NS = m_textCtrlNS->GetValue().Upper();
	wxString WE = m_textCtrlWE->GetValue().Upper();

	if(degf1 < 0.0  || degf1 > 359.0)
	{
		m_textCtrlDeg1->SetFocus();
		m_textCtrlDeg1->SetSelection(-1,-1);
	}
	else if(degf2 < 0.0 || degf2 > 359.0)
	{
		m_textCtrlDeg2->SetFocus();
		m_textCtrlDeg2->SetSelection(-1,-1);
	}
	else if(min1 < 0.0 || min1 > 59.9999)
	{
		m_textCtrlmin1->SetFocus();
		m_textCtrlmin1->SetSelection(-1,-1);
	}
	else if(min2 < 0.0 || min2 > 59.9999)
	{
		m_textCtrlmin2->SetFocus();
		m_textCtrlmin2->SetSelection(-1,-1);
	}
	else if(sec1< 0.0 || sec1 > 59.9999)
	{
		m_textCtrlsec1->SetFocus();
		m_textCtrlsec1->SetSelection(-1,-1);
	}
	else if(sec2 < 0.0 || sec2 > 59.9999)
	{
		m_textCtrlsec2->SetFocus();
		m_textCtrlsec2->SetSelection(-1,-1);
	}
	else if(NS != _T("N") && NS != _T("S"))
	{
		m_textCtrlNS->SetFocus();
		m_textCtrlNS->SetSelection(-1,-1);
	}
	else if(WE != _T("W") && WE != _T("E"))
	{
		m_textCtrlWE->SetFocus();
		m_textCtrlWE->SetSelection(-1,-1);
	}
	else
	{
		retstr.Replace(_T("."),dlg->decimalPoint);
		EndModal(wxID_OK);
	}
}