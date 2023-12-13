
package aot;

import java.util.*;
import com.google.gson.annotations.*; 

public class FormsGroup
{
    @SerializedName("forms")
    public List<Form> forms = null;

    @SerializedName("grm")
    public String grm = null;
}
