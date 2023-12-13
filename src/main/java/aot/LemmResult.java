
package aot;

import java.util.*;
import java.lang.reflect.*;

import com.google.gson.*;
import com.google.gson.reflect.*;
import com.google.gson.annotations.*; 

public class LemmResult
{
    static public final Type LIST_TYPE = new TypeToken<List<LemmResult>>(){}.getType();

    @SerializedName("commonGrammems")
    public String commonGrammems = null;

    @SerializedName("found")
    public boolean found = false;

    @SerializedName("morphInfo")
    public String morphInfo = null;

    @SerializedName("paradigm")
    public List<Paradigm> paradigm = null;

    @SerializedName("srcNorm")
    public String srcNorm = null;

    @SerializedName("wordForm")
    public String wordForm = null;

    public String[] getMorphInfoAsArray()
    {
	return splitArray(morphInfo);
    }

    public String[] getCommonGrammemsAsArray()
    {
	return splitArray(commonGrammems);
    }

    static public LemmResult[] fromJsonAsArray(String str)
    {
	final List<LemmResult> res = new Gson().fromJson(str, LIST_TYPE);
	if (res == null)
	    return null;
	return res.toArray(new LemmResult[res.size()]);
    }

    static public String[] splitArray(String value)
    {
	if (value == null)
	    return new String[0];
	final List<String> res = new ArrayList();
	for(String s: value.split(",", -1))
	{
	    final String ss = s.trim();
	    if (!s.isEmpty())
		res.add(s.toUpperCase());
	}
	return res.toArray(new String[res.size()]);
	 }
}
