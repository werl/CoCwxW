//
// Created by peter on 2021-11-13.
//

#ifndef COCWXW_ABSTRACT_PANEL_HPP
#define COCWXW_ABSTRACT_PANEL_HPP


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class AbstractPanel: public wxPanel{
public:
    AbstractPanel (wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                   long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr));

    /**
     * To prompt if the app should close.
     *
     * @return true to prompt for save, false to not
     */
    virtual bool shouldPromptForSave () = 0;

    /**
     * Called to save a file. Does nothing by default
     *
     * @param filePath current path to file, empty string if not set
     *
     * @return if save was successful (used for closing the app)
     */
    virtual bool doSave (const wxString &filePath);

    /**
     * Called to open a file. Does nothing by default
     *
     * @param filePath the path of the file to open
     */
    virtual void doOpen (const wxString &filePath);
};


#endif //COCWXW_ABSTRACT_PANEL_HPP
