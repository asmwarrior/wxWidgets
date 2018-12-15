/////////////////////////////////////////////////////////////////////////////
// Name:        dcgraph.h
// Purpose:     interface of wxGCDC
// Author:      wxWidgets team
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

/**
    @class wxGCDC

    wxGCDC is a device context that draws on a wxGraphicsContext.

    @remarks
    If Direct2D is a renderer of underlying graphics context, only wxFont objects
    representing TrueType fonts can be used in the font-related functions.

    @library{wxcore}
    @category{dc}

    @see wxDC, wxGraphicsContext
*/

class wxGCDC: public wxDC
{
public:
    /**
       Constructs a wxGCDC from a wxWindowDC.
    */
    wxGCDC( const wxWindowDC& windowDC );

    /**
       Constructs a wxGCDC from a wxMemoryDC.
    */
    wxGCDC( const wxMemoryDC& memoryDC );

    /**
       Constructs a wxGCDC from a wxPrinterDC.
    */
    wxGCDC( const wxPrinterDC& printerDC );

    /**
       Construct a wxGCDC from an existing graphics context.

       Note that this object takes ownership of @a context and will delete it
       when it is destroyed or when SetGraphicsContext() is called with a
       different context object.

       Also notice that @a context will continue using the same font, pen and
       brush as before until SetFont(), SetPen() or SetBrush() is explicitly
       called to change them. This means that the code can use this
       wxDC-derived object to work using pens and brushes with alpha component,
       for example (which normally isn't supported by wxDC API), but it also
       means that the return values of GetFont(), GetPen() and GetBrush() won't
       really correspond to the actually used objects because they simply can't
       represent them anyhow. If you wish to avoid such discrepancy, you need
       to call the setter methods to bring wxDC and wxGraphicsContext font, pen
       and brush in sync with each other.
    */
    wxGCDC(wxGraphicsContext* context);

    /**
       Constructs a wxGCDC from a wxEnhMetaFileDC.

       This constructor is only available in wxMSW port and when @c
       wxUSE_ENH_METAFILE build option is enabled, i.e. when wxEnhMetaFileDC
       class itself is available.

       @since 2.9.3
    */
    wxGCDC( const wxEnhMetaFileDC& emfDC );

    wxGCDC();
    virtual ~wxGCDC();
    
    /**
       Retrieves associated wxGraphicsContext
    */
    wxGraphicsContext* GetGraphicsContext() const;

    /**
       Set the graphics context to be used for this wxGCDC.

       Note that this object takes ownership of @a context and will delete it when
       it is destroyed or when SetGraphicsContext() is called again.
    */
    void SetGraphicsContext(wxGraphicsContext* context);

};

