
package aot;

import java.util.*;
import com.google.gson.annotations.*; 

public class Paradigm
{
    @SerializedName("formsGroups")
    public List<FormsGroup> formsGroups = null;

    @SerializedName("pos")
    public String pos = null;

    public String getPosNotNull()
    {
	return pos != null?pos.toUpperCase():"";
    }
}
