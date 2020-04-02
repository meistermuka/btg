BEGIN {
   count = 0;
   obj = "";
   if (pass == "c2")
   {
      print "\nOBJECT objs[] = {";
   }
}

/^- / {
   outputRecord(",");
   obj = $2;
   prop["description"] = "NULL";
   prop["tags"]        = "";
   prop["location"]    = "NULL";
   prop["destination"] = "NULL";
   prop["prospect"]    = "";
   prop["details"]     = "\"You see nothing special.\\n\"";
   prop["contents"]    = "\"You see\"";
   prop["textGo"]      = "\"You can't get any closer than this.\\n\"";
   prop["weight"]      = "99";
   prop["capacity"]    = "9999";
   prop["health"]      = "0";
}

obj && /^[ \t]+[a-z]/ {
   name = $1;
   $1 = "";
   if (name in prop)
   {
      prop[name] = $0;
   }
   else if (pass == "c2")
   {
      print "#error \"" FILENAME " line " NR ": unknown attribute '" name "'\"";
   }
}

!obj && pass == (/^#include/ ? "c1" : "h") {
   print;
}

END {
   outputRecord("\n};");
   if (pass == "h")
   {
      print "\n#define endOfObjs\t(objs + " count ")";
   }
}

function outputRecord(separator)
{
   if (obj)
   {
      if (pass == "h")
      {
         print "#define " obj "\t(objs + " count ")";
      }
      else if (pass == "c1")
      {
         print "static const char *tags" count "[] = {" prop["tags"] ", NULL};";
      }
      else if (pass == "c2")
      {
         print "\t{\t/* " count " = " obj " */";
         print "\t\t" prop["description"] ",";
         print "\t\ttags" count ",";
         print "\t\t" prop["location"] ",";
         print "\t\t" prop["destination"] ",";
         print "\t\t" prop[prop["prospect"] ? "prospect" : "destination"] ",";
         print "\t\t" prop["details"] ",";
         print "\t\t" prop["contents"] ",";
         print "\t\t" prop["textGo"] ",";
         print "\t\t" prop["weight"] ",";
         print "\t\t" prop["capacity"] ",";
         print "\t\t" prop["health"];
         print "\t}" separator;
         delete prop;
      }
      count++;
   }
}