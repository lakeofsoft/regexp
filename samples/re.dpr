
(*
	----------------------------------------------

	  re.dpr
	  RegExp sample

	----------------------------------------------
	  Copyright (c) 2011-2012 Lake of Soft
		     All rights reserved

	  http://lakeofsoft.com/
	----------------------------------------------

	  created by:
		Lake, 08 Jan 2012

	  modified by:
		Lake, Jan 2012

	----------------------------------------------
*)

{$APPTYPE CONSOLE }
{$DEFINE CONSOLE }

{$I unaDef.inc}

program
  regexpTC;

uses
  unaTypes, unaUtils, unaRE;


// -- main --

var
  pos, len, index: int;
  subj, regexp: wString;
begin
  if (paramCount < 2) then begin
    //
    writeLn('regexp, version 1.0               (c) 2012 Lake of Soft');
    writeLn('usage: [-m|-r] "subject" "regexp" ["substitution"]');
    writeLn('	-m	match (default)');
    writeLn('	-r	replace');
    writeLn('');
  end
  else begin
    //
    if (not hasSwitch('r')) then begin
      //
      index := 1;
      if (hasSwitch('m')) then
	index := 2;
      //
      subj := paramStr(index);
      regexp := paramStr(index + 1);
      //
      writeln('Subj: ', string(subj));
      writeln('Regexp: ', string(regexp));
      //
      index := 1;
      repeat
	//
	pos := rematch(subj, regexp, len, index);
	if (0 < pos) then begin
	  //
	  writeln(' ** Match at position ', pos, ', length=', len, ' : "' + string(copy(subj, pos, len)) + '"');
	  index := pos + 1;
	end
	else
	  break;
	//
      until (false);
      //
      writeln('No more matches.');
    end
    else begin
      //
      if (3 < paramCount) then
	writeln(string(replace(paramStr(2), paramStr(3), paramStr(4), 1, false)))
      else
	writeln('-r needs 3 parameters: "subject" "regexp" "substitution"');
    end;
  end;
end.

