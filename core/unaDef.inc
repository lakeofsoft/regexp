
(*
	----------------------------------------------

	  unaDef.inc
	  compiler options and conditional defines

	----------------------------------------------
	  Copyright (c) 2001-2011 Lake of Soft
		     All rights reserved

	  http://lakeofsoft.com/
	----------------------------------------------

	  created by:
		Lake, Apr 2001

	  modified by:
		Lake, Jan-Oct 2002
		Lake, Jan-Jul 2003
		Lake, Sep-Dec 2005
		Lake, Dec 2007
		Lake, Jan-Dec 2010
		Lake, May 2011

	----------------------------------------------
*)

{xx $DEFINE DEBUG       }      	// debug version
{xx $DEFINE UNA_SERVICE }	// service module
{xx $DEFINE FMX         }       // FireMonkey


{$IFDEF UNA_NEED_ANSI }
{$ELSE }
  {$DEFINE NO_ANSI_SUPPORT }	// undefine this symbol if you do need support for ANSI version of Windows API (Win9x)
{$ENDIF UNA_NEED_ANSI }

// -- VC 2.5 license type --
{$I unaVC25_license.inc }


{$IFDEF VC25_ENTERPRISE }
  //
  {$IFDEF NO_ANSI_SUPPORT }
    //
    {$DEFINE VC25_OVERLAPPED }      // enable overlapped calls
    {$DEFINE VC25_WINSOCK20 }       // enable WinSock 2.0 extensions
    //
    {$IFDEF FPC }
    {$ELSE }
      {$IFDEF VC25_OVERLAPPED }
	{$DEFINE VC25_IOCP }            // enable IOCP calls
      {$ENDIF VC25_OVERLAPPED }
    {$ENDIF FPC }
    //
  {$ENDIF NO_ANSI_SUPPORT }
  //
{$ELSE }
  //
{$ENDIF VC25_ENTERPRISE }


// -- ============= --

{$IFDEF FPC }
  {$MODE DELPHI }
  {$ASMMODE Intel }
  {$DEFINE VER170 }
  {$DEFINE __STRANSI__ }
  //
  {$IFDEF CPU64 }
    {$DEFINE FPC64 }
  {$ENDIF CPU64 }
{$ENDIF FPC }

{$IFDEF VER90 }
  // Delphi 2.0
  {$DEFINE __BEFORE_D3__ }	// Not Delphi 3.0 yet
  {$DEFINE __BEFORE_D4__ }	// Not Delphi 4.0 yet
  {$DEFINE __BEFORE_D5__ }	// Not Delphi 5.0 yet
  {$DEFINE __BEFORE_D6__ }	// Not Delphi 6.0 yet
  {$DEFINE __BEFORE_D7__ }	// Not Delphi 7.0 yet
  {$DEFINE __BEFORE_D8__ }	// Not Delphi 8.0 yet
  {$DEFINE __BEFORE_D9__ }	// Not Delphi 2005 yet
  {$DEFINE __BEFORE_DA__ }	// Not Delphi 2006 yet
  {$DEFINE __BEFORE_DB__ }	// Not Delphi 2007 yet
  {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
  {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
  {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
  {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
  {$DEFINE __STRANSI__ }
  //
  {$DEFINE __AFTER_D1__ }	// Delphi 2.0 or later
{$ELSE }
  {$IFDEF VER100 }
    // Delphi 3.0
    {$DEFINE __BEFORE_D4__ }	// Not Delphi 4.0 yet
    {$DEFINE __BEFORE_D5__ }	// Not Delphi 5.0 yet
    {$DEFINE __BEFORE_D6__ }	// Not Delphi 6.0 yet
    {$DEFINE __BEFORE_D7__ }	// Not Delphi 7.0 yet
    {$DEFINE __BEFORE_D8__ }	// Not Delphi 8.0 yet
    {$DEFINE __BEFORE_D9__ }	// Not Delphi 2005 yet
    {$DEFINE __BEFORE_DA__ }	// Not Delphi 2006 yet
    {$DEFINE __BEFORE_DB__ }	// Not Delphi 2007 yet
    {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
    {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
    {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
    {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
    {$DEFINE __STRANSI__ }
    //
    {$DEFINE __AFTER_D1__ }	// Delphi 2.0 or later
    {$DEFINE __AFTER_D2__ }	// Delphi 3.0 or later
  {$ELSE }
    {$IFDEF VER110 }
      // CBuilder 3.0
      {$DEFINE __BEFORE_D4__ }
      {$DEFINE __BEFORE_D5__ }
      {$DEFINE __BEFORE_D6__ }
      {$DEFINE __BEFORE_D7__ }
      {$DEFINE __BEFORE_D8__ }
      {$DEFINE __BEFORE_D9__ }
      {$DEFINE __BEFORE_DA__ }
      {$DEFINE __BEFORE_DB__ }
      {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
      {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
      {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
      {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
      {$DEFINE __STRANSI__ }
      //
      {$DEFINE __AFTER_D1__ }
      {$DEFINE __AFTER_D2__ }
    {$ELSE }
      {$IFDEF VER120 }
	// Delphi 4.0
	{$DEFINE __BEFORE_D5__ }
	{$DEFINE __BEFORE_D6__ }
	{$DEFINE __BEFORE_D7__ }
	{$DEFINE __BEFORE_D8__ }
	{$DEFINE __BEFORE_D9__ }
	{$DEFINE __BEFORE_DA__ }
	{$DEFINE __BEFORE_DB__ }
	{$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
	{$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
	{$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
        {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
	{$DEFINE __STRANSI__ }
	//
	{$DEFINE __AFTER_D1__ }
	{$DEFINE __AFTER_D2__ }
	{$DEFINE __AFTER_D3__ }
      {$ELSE }
	{$IFDEF VER130 }
	  // Delphi 5.0 / C++ Builder 5.0
	  {$DEFINE __BEFORE_D6__ }
	  {$DEFINE __BEFORE_D7__ }
	  {$DEFINE __BEFORE_D8__ }
	  {$DEFINE __BEFORE_D9__ }
	  {$DEFINE __BEFORE_DA__ }
	  {$DEFINE __BEFORE_DB__ }
	  {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
	  {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
	  {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
          {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
	  {$DEFINE __STRANSI__ }
	  //
	  {$DEFINE __AFTER_D1__ }
	  {$DEFINE __AFTER_D2__ }
	  {$DEFINE __AFTER_D3__ }
	  {$DEFINE __AFTER_D4__ }
	{$ELSE }
	  {$IFDEF VER140 }
	    // Delphi 6.0 / C++ Builder 6.0
	    {$DEFINE __BEFORE_D7__ }
	    {$DEFINE __BEFORE_D8__ }
	    {$DEFINE __BEFORE_D9__ }
	    {$DEFINE __BEFORE_DA__ }
	    {$DEFINE __BEFORE_DB__ }
	    {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
	    {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
	    {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
            {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
	    {$DEFINE __STRANSI__ }
	    //
	    {$DEFINE __AFTER_D1__ }
	    {$DEFINE __AFTER_D2__ }
	    {$DEFINE __AFTER_D3__ }
	    {$DEFINE __AFTER_D4__ }
	    {$DEFINE __AFTER_D5__ }
	  {$ELSE }
	    {$IFDEF VER150 }
	      // Delphi 7.0
	      {$DEFINE __BEFORE_D8__ }
	      {$DEFINE __BEFORE_D9__ }
	      {$DEFINE __BEFORE_DA__ }
	      {$DEFINE __BEFORE_DB__ }
	      {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
	      {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
	      {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
              {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
    	      {$DEFINE __STRANSI__ }
	      //
	      {$DEFINE __AFTER_D1__ }
	      {$DEFINE __AFTER_D2__ }
	      {$DEFINE __AFTER_D3__ }
	      {$DEFINE __AFTER_D4__ }
	      {$DEFINE __AFTER_D5__ }
	      {$DEFINE __AFTER_D6__ }
	    {$ELSE }
	      {$IFDEF VER160 }
		// Delphi 8.0
		{$DEFINE __BEFORE_D9__ }
		{$DEFINE __BEFORE_DA__ }
		{$DEFINE __BEFORE_DB__ }
		{$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
		{$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
		{$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
                {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
		{$DEFINE __STRANSI__ }
		//
		{$DEFINE __AFTER_D1__ }
		{$DEFINE __AFTER_D2__ }
		{$DEFINE __AFTER_D3__ }
		{$DEFINE __AFTER_D4__ }
		{$DEFINE __AFTER_D5__ }
		{$DEFINE __AFTER_D6__ }
		{$DEFINE __AFTER_D7__ }
	      {$ELSE }
		{$IFDEF VER170 }
		  //
		  // Delphi 2005 (D9)
		  {$DEFINE __BEFORE_DA__ }
		  {$DEFINE __BEFORE_DB__ }
		  {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
		  {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
		  {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
                  {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
		  {$DEFINE __STRANSI__ }
		  //
		  {$DEFINE __AFTER_D1__ }
		  {$DEFINE __AFTER_D2__ }
		  {$DEFINE __AFTER_D3__ }
		  {$DEFINE __AFTER_D4__ }
		  {$DEFINE __AFTER_D5__ }
		  {$DEFINE __AFTER_D6__ }
		  {$DEFINE __AFTER_D7__ }
		  {$DEFINE __AFTER_D8__ }
		{$ELSE }
		  {$IFDEF VER180 }
		    //
		    {$DEFINE __BEFORE_DC__ }	// Not Delphi 2009 yet
		    {$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
		    {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
                    {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
		    {$DEFINE __STRANSI__ }
		    //
		    // Delphi 2006 (DA) or Delphi 2007 (DB),
		    // fortunately we can use VER185 (see below)
		    //
		    {$DEFINE __AFTER_D1__ }  	// Delphi 2.0 or later
		    {$DEFINE __AFTER_D2__ }  	// Delphi 3.0 or later
		    {$DEFINE __AFTER_D3__ }  	// Delphi 4.0 or later
		    {$DEFINE __AFTER_D4__ }  	// Delphi 5.0 or later
		    {$DEFINE __AFTER_D5__ }  	// Delphi 6.0 or later
		    {$DEFINE __AFTER_D6__ }  	// Delphi 7.0 or later
		    {$DEFINE __AFTER_D7__ }  	// Delphi 8.0 or later
		    {$DEFINE __AFTER_D8__ }  	// Delphi 2005 or later
		    {$DEFINE __AFTER_D9__ }	// Delphi 2006 or later
		    //
		    {$IFDEF VER185 }
		      // Delphi 2007 (11.0) defines both VER180 and VER185 while Delphi 2006 defines VER180 only
		      {$DEFINE __AFTER_DA__ }	// Delphi 2007 or later
		    {$ELSE }
		      {$DEFINE __BEFORE_DB__ }	// Not Delphi 2007 yet
		      //
		      {$DEFINE __STRANSI__ }
		    {$ENDIF VER185 }
		  {$ELSE }
		    //
		    {$IFDEF VER190 }
		      // Delphi 2008? (never released)
		    {$ELSE }
		      {$IFDEF VER200 }
			//
			// Delphi 2009 (DC)
			//
			{$DEFINE __BEFORE_DD__ }	// Not Delphi 2010 yet
			{$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
                        {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
			//
			{$DEFINE __AFTER_D1__ }  	// Delphi 2.0 or later
			{$DEFINE __AFTER_D2__ }  	// Delphi 3.0 or later
			{$DEFINE __AFTER_D3__ }  	// Delphi 4.0 or later
			{$DEFINE __AFTER_D4__ }  	// Delphi 5.0 or later
			{$DEFINE __AFTER_D5__ }  	// Delphi 6.0 or later
			{$DEFINE __AFTER_D6__ }  	// Delphi 7.0 or later
			{$DEFINE __AFTER_D7__ }  	// Delphi 8.0 or later
			{$DEFINE __AFTER_D8__ }  	// Delphi 2005 or later
			{$DEFINE __AFTER_D9__ }	        // Delphi 2006 or later
			{$DEFINE __AFTER_DA__ }	        // Delphi 2007 or later
			{$DEFINE __AFTER_DB__ }	        // Delphi 2009 or later
			//
		      {$ELSE }
			{$IFDEF VER210 }
			  //
			  // Delphi 2010 (DD)
			  //
			  {$DEFINE __BEFORE_DE__ }	// Not Delphi XE yet
                          {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
			  //
			  {$DEFINE __AFTER_D1__ }  	// Delphi 2.0 or later
			  {$DEFINE __AFTER_D2__ }  	// Delphi 3.0 or later
			  {$DEFINE __AFTER_D3__ }  	// Delphi 4.0 or later
			  {$DEFINE __AFTER_D4__ }  	// Delphi 5.0 or later
			  {$DEFINE __AFTER_D5__ }  	// Delphi 6.0 or later
			  {$DEFINE __AFTER_D6__ }  	// Delphi 7.0 or later
			  {$DEFINE __AFTER_D7__ }  	// Delphi 8.0 or later
			  {$DEFINE __AFTER_D8__ }  	// Delphi 2005 or later
			  {$DEFINE __AFTER_D9__ }	// Delphi 2006 or later
			  {$DEFINE __AFTER_DA__ }	// Delphi 2007 or later
			  {$DEFINE __AFTER_DB__ }	// Delphi 2009 or later
			  {$DEFINE __AFTER_DC__ }	// Delphi 2010 or later

			{$ELSE }
			  {$IFDEF VER220 }
			    //
			    // Delphi XE (DE)
                            {$DEFINE __BEFORE_DF__ }	// Not Delphi XE2 yet
			    //
			    {$DEFINE __AFTER_D1__ }  	// Delphi 2.0 or later
			    {$DEFINE __AFTER_D2__ }  	// Delphi 3.0 or later
			    {$DEFINE __AFTER_D3__ }  	// Delphi 4.0 or later
			    {$DEFINE __AFTER_D4__ }  	// Delphi 5.0 or later
			    {$DEFINE __AFTER_D5__ }  	// Delphi 6.0 or later
			    {$DEFINE __AFTER_D6__ }  	// Delphi 7.0 or later
			    {$DEFINE __AFTER_D7__ }  	// Delphi 8.0 or later
			    {$DEFINE __AFTER_D8__ }  	// Delphi 2005 or later
			    {$DEFINE __AFTER_D9__ }	// Delphi 2006 or later
			    {$DEFINE __AFTER_DA__ }	// Delphi 2007 or later
			    {$DEFINE __AFTER_DB__ }	// Delphi 2009 or later
			    {$DEFINE __AFTER_DC__ }	// Delphi 2010 or later
			    {$DEFINE __AFTER_DD__ }	// Delphi XE or later

			  {$ELSE }
			     //
                            {$IFDEF VER230 }
                              //
                              // Delphi XE2 (DF)
                              {$DEFINE __BEFORE_E0__ }	// Not Delphi XE3 yet
                              //
                              {$DEFINE __AFTER_D1__ }  	// Delphi 2.0 or later
                              {$DEFINE __AFTER_D2__ }  	// Delphi 3.0 or later
                              {$DEFINE __AFTER_D3__ }  	// Delphi 4.0 or later
                              {$DEFINE __AFTER_D4__ }  	// Delphi 5.0 or later
                              {$DEFINE __AFTER_D5__ }  	// Delphi 6.0 or later
                              {$DEFINE __AFTER_D6__ }  	// Delphi 7.0 or later
                              {$DEFINE __AFTER_D7__ }  	// Delphi 8.0 or later
                              {$DEFINE __AFTER_D8__ }  	// Delphi 2005 or later
                              {$DEFINE __AFTER_D9__ }	// Delphi 2006 or later
                              {$DEFINE __AFTER_DA__ }	// Delphi 2007 or later
                              {$DEFINE __AFTER_DB__ }	// Delphi 2009 or later
                              {$DEFINE __AFTER_DC__ }	// Delphi 2010 or later
                              {$DEFINE __AFTER_DD__ }	// Delphi XE or later
                              {$DEFINE __AFTER_DE__ }	// Delphi XE2 or later

                            {$ELSE }
                               // ... after XE2
                            {$ENDIF VER230 }
                          {$ENDIF VER210 }
			{$ENDIF VER210 }
		      {$ENDIF VER200 }
		    {$ENDIF VER190 }
		  {$ENDIF VER180 }
		{$ENDIF VER170 }
	      {$ENDIF VER160 }
	    {$ENDIF VER150 }
	  {$ENDIF VER140 }
	{$ENDIF VER130 }
      {$ENDIF VER120 }
    {$ENDIF VER110 }
  {$ENDIF VER100 }
{$ENDIF VER90 }

// --  --

{$IFDEF DEBUG }

  //=================
  // DEBUG OPTIONS
  //=================

  {$IFDEF VER90 }          // Delphi 2.0
  {$ELSE }

    {$IFDEF FORCE_OPTIMIZATION }
      // override optimization options
      {$ASSERTIONS OFF }
      //
    {$ELSE}
      //
      {$ASSERTIONS ON }		// $C+
      //			// generation of assersion code (affects binary code)
    {$ENDIF FORCE_OPTIMIZATION }

    {$IFDEF VER100 }         // Delphi 3.0
    {$ELSE }
      //
      {$IFDEF VER110 }         // CBuilder 3.0
      {$ELSE }
	{$IFDEF FPC }
	{$ELSE }
	  {$DEFINITIONINFO ON }	// $YD
				// generation of symbol reference information
	{$ENDIF FPC }
      {$ENDIF VER110 }
      //
    {$ENDIF VER100 }
    //
  {$ENDIF VER90 }

  {$DEBUGINFO ON }      // $D+ generation of debug info

  {$IFNDEF FPC }
    {$LOCALSYMBOLS ON }	// $L+ generation of local symbol information
    {$REFERENCEINFO ON }	// $Y+ generation of symbol reference information
  {$ENDIF FPC }

  {$IFDEF FORCE_OPTIMIZATION }
    //
    // override optimization options
    {$IOCHECKS OFF }
    {$OPTIMIZATION ON }
    {$OVERFLOWCHECKS OFF }
    {$RANGECHECKS OFF }
    {$STACKFRAMES OFF }
  {$ELSE}
    {$IOCHECKS ON }		// $I+ generation of checking I/O results code (affects binary code)
    {$OPTIMIZATION OFF }	// $O- turn off optimization (affects binary code)
    {$OVERFLOWCHECKS ON }	// $Q+ generation of overflow checking code (affects binary code)
    {$RANGECHECKS ON }		// $R+ generation of range-checking code (affects binary code)
    {$STACKFRAMES ON }		// $W+ generation of stack frames for procedures and functions (affects binary code)
  {$ENDIF FORCE_OPTIMIZATION }

{$ELSE }

  //=================
  // RELEASE OPTIONS
  //=================

  {$DEFINE RELEASE }

  {$IFDEF VER90 }    // Delphi 2.0
  {$ELSE }
    {$ASSERTIONS OFF }	// $C-
			// generation of assersion code (affects binary code)
    {$IFDEF VER100 }         // Delphi 3.0
    {$ELSE }
      {$IFDEF VER110 }         // CBuilder 3.0
      {$ELSE }
	//
	{$IFDEF FPC }
	{$ELSE }
	  {$DEFINITIONINFO OFF }  // $Y-
				  // disallow generation of symbol reference information
	{$ENDIF FPC }
      {$ENDIF }
    {$ENDIF }
  {$ENDIF }

  {$IFNDEF FPC }
    {$LOCALSYMBOLS OFF }	// $L- generation of local symbol information
    {$REFERENCEINFO OFF }	// $Y- generation of symbol reference information
  {$ELSE }
    {$DEFINE NO_UNA_DESCR }
  {$ENDIF FPC }

  {$DEBUGINFO OFF }     // $D- no debug info
  {$OPTIMIZATION ON }	// $O+ turn on optimization (affects binary code)
  {$IOCHECKS OFF }	// $I- generation of checking I/O results code (affects binary code)
  {$OVERFLOWCHECKS OFF }// $Q- generation of overflow checking code (affects binary code)
  {$RANGECHECKS OFF }	// $R- generation of range-checking code (affects binary code)
  {$STACKFRAMES OFF }	// $W- generation of stack frames for procedures and functions (affects binary code)
{$ENDIF }


// COMMON (RELEASE and DEBUG) options

{$IFDEF FPC }
{$ELSE }
  {$E-}	// ?
  {$F-}	// ?
  {$K-}	// ?
  {$N-} // ?
{$ENDIF FPC }

{$S-} // ?

// -- common --

{$IFDEF VER90 }          // Delphi 2.0
{$ELSE}

  {$IFDEF FPC }
  {$ELSE }
    {$IMPORTEDDATA ON }	// $G+ turn on creation of imported data references
			// NOTE: C++ Builder ?.0 crashes when installing packages compiled with $G-
  {$ENDIF FPC }

  {$IFDEF VER100 }         // Delphi 3.0
  {$ELSE }
    {$IFDEF VER110 }         // CBuilder 3.0
    {$ELSE }

      {$IFDEF FPC }
      {$ELSE }
        {$REALCOMPATIBILITY OFF }	// Real type is equivalent to Double
      {$ENDIF FPC }

    {$ENDIF VER110 }
  {$ENDIF VER100 }
{$ENDIF VER90 }

{$A+ }		        // $A+ align records to 8/16 boundaries (unless packed modifier is specified)
{$BOOLEVAL OFF }        // $B- turn off full boolean evaluation
			// WARNING! turning is option on will introduce certain access violations
{$IFDEF FPC }
  {$LONGSTRINGS ON }	// $H+ turn on long string support
{$ELSE }
  {$SAFEDIVIDE OFF }	// $U- turn off guards against the flawed FDIV instruction exhibited by certain early Pentium processors
{$ENDIF FPC }

{$WRITEABLECONST OFF }	// $J- turn off writeable const
{$TYPEINFO OFF }	// $M- turn off RTTI (when possible)
{$TYPEDADDRESS ON }	// $T+ turn on typed pointers
{$EXTENDEDSYNTAX ON }   // $X+ turn on extended syntax
{$MINENUMSIZE 4 }	// $Z+ or $Z4 set enum element size to 4 bytes

{$IFDEF __AFTER_DC__ }
  {xx $RTTI EXPLICIT METHODS([]) PROPERTIES([]) FIELDS([])} // ends up in internal error :)
  {$WEAKLINKRTTI ON}
{$ENDIF __AFTER_DC__ }

{$P+}	// short string? who still needs them..
{$V+}	// short string? who still needs them..


{$IFDEF NO_UNA_DESCR }
{$ELSE }
  //
  {$IFDEF VCX_DEMO }
    {$DESCRIPTION 'VC25EDEC11' }        // Evaluation version
  {$ELSE }
    //
    {$IFDEF VC25_ENTERPRISE }
      {$DESCRIPTION 'VC25XDEC11' }	// Enterprise
    {$ELSE }
      {$DESCRIPTION 'VC25PDEC11' }      // Pro version
    {$ENDIF}
    //
  {$ENDIF VCX_DEMO }
{$ENDIF }


{$IFDEF __AFTER_D7__ }
  {$IFDEF DEBUG }
  {$ELSE }
    {$DEFINE UNA_OK_INLINE }	// inline is OK after Delphi 7, but it is bad for debugging
  {$ENDIF DEBUG }
{$ENDIF __AFTER_D7__ }


{$IFDEF CPUX64 }	// defined by dcc64 only
  {$DEFINE CPU64 }
{$ENDIF CPUX64 }

{$IFDEF WIN64 }		// defined by dcc64 only
  {$DEFINE CPU64 }
{$ENDIF CPUX64 }


